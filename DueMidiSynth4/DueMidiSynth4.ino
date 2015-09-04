#include "DueTimer.h"
#include <SPI.h>

#include "MidiNoteFrequencies.h"
#include "MidiCC.h"
#include "DueMcpDac.h"
#include "IntOnePoleFilter.h"
#include "IntPhaseGenerator.h"
#include "IntNoise.h"
#include "IntOperators.h"

// oscillator globals:
const int SamplingFrequency = 40000;

const int LPFNumPoles = 8;

//integer stuff
static const int IntegerResolution = 12;

const int NumWaveForms = 4;
IntOperator g_Operators[NumWaveForms] = { IntSawUp<IntegerResolution>,
                                        IntPulse<IntegerResolution>,
                                        IntFullPseudoSin<IntegerResolution>,
                                        IntSemiPseudoSin<IntegerResolution> };

const int NumOperators = 4;

IntOperator g_CurrentOperator[NumOperators];

CIntegerNoise<IntegerResolution> g_NoiseInt;
CIntegerMultiStageFilter<int, CIntegerOnePoleLowPassFilter<int, 8>, LPFNumPoles> g_LPFIntMulti;
CIntegerPhaseGenerator<IntegerResolution> g_PhaseInt(0);
CIntegerPhaseGenerator<IntegerResolution> g_PhaseIntSub(0);



// debugging
unsigned long g_InteruptCounter;

// midi globals
const int LpfMidiCC = 1;//mod wheel!
const int WaveFormMidiCC[NumOperators] = { 79, 84, 91, 93 };
const int SubWaveFormMidiCC = 84;

int g_CurrMidiNote;
int g_CurrAmplitude;
CMidiCC MidiCC;


// helper functions:
void myHandler()
{
  unsigned int DacValue = CalcDacValue();//CalcLPFNoiseInt();

  // TODO limit on signed value! now <0 is not possible, but will be a very hight uint value!!!
  //DacValue = 0 < DacValue ? DacValue : 0;
  DacValue = DacValue < 4096 ? DacValue : 4095;

  mcp48_setOutput(0, GAIN_1, 0x01, DacValue);
  ++g_InteruptCounter;
}

int CalcDacValue()
{
  int Phase = g_PhaseInt();
  int SubPhase = g_PhaseIntSub();
  int OscillatorValue = g_LPFIntMulti( ( g_CurrentOperator[0](Phase) + g_CurrentOperator[1](Phase) 
                                          + g_CurrentOperator[2](SubPhase) + g_CurrentOperator[3](SubPhase)
                                          )>>2 );
  
  // 'envelope'
  OscillatorValue = 0<g_CurrAmplitude ? OscillatorValue : 0;

  return IntBipolarToUnsigned<IntegerResolution>(OscillatorValue);
}

int CalcLPFNoiseInt()
{
  int Noise = g_NoiseInt();
  int Saw = g_PhaseInt();
  int SubPhase = g_PhaseIntSub();
  int Pulse = IntPulse<IntegerResolution>(SubPhase);
  int Sin = IntFullPseudoSin<IntegerResolution>(Saw);

  int OscillatorValue = g_LPFIntMulti((Noise+Saw+Pulse+Sin)>>2);
  // 'envelope'
  OscillatorValue = 0<g_CurrAmplitude ? OscillatorValue : 0;

  return 2048+OscillatorValue;//TODO function?
}

void TestLPFNoiseInt()
{
  while(true)
  {
    int DacValue = CalcDacValue();//CalcLPFNoiseInt();
    Serial.println(DacValue);
    if(DacValue<0 || 4096<=DacValue)
    {
      Serial.println("!!!!!!!!!!");
      delay(500);
    }
    delay(100);
  }
}


void LogSpeedTest(int Repeats, unsigned long Before, unsigned long After)
{
  Serial.print("Repeat x ");
  Serial.print(Repeats);
  Serial.print("  = ");
  unsigned long Duration = After-Before;
  Serial.print(Duration);
  Serial.println(" mSec");
}

void TestCalcSpeed()
{
  Serial.println("Testing speed...");

  {
    g_LPFIntMulti.SetParameter(168);
    g_LPFIntMulti.SetStages(LPFNumPoles);

    unsigned long Before = millis();
    unsigned int DacValue;
    for(int Repeat = 0; Repeat<SamplingFrequency; ++Repeat)
    {
        DacValue += CalcDacValue();//CalcLPFNoiseInt();
    }

    unsigned long After = millis();
    LogSpeedTest(SamplingFrequency, Before, After);
  }

  {
    unsigned long Before = millis();
    unsigned int DacValue = 1<<(IntegerResolution-1);
    for(int Repeat = 0; Repeat<SamplingFrequency; ++Repeat)
    {
      mcp48_setOutput(2048, GAIN_1, 0x01, DacValue);
    }

    unsigned long After = millis();
    LogSpeedTest(SamplingFrequency, Before, After);
  }

}

void setup()
{
  // use Serial as debug output
  Serial.begin(115200);
  Serial.println("MidiSynth...");

  // use serial1 as midi input
  // for now, use serial usb cable => baudrate is not 31250
  Serial1.begin(115200);

  analogReadResolution(10);

  const int DefaultMidiNote = 45;// note A1 = 110 Hz

  g_CurrMidiNote = DefaultMidiNote;
  g_CurrAmplitude = 0;

  mcp48_begin();

  MidiCC.SetController(LpfMidiCC, 64);
  for(int idx = 0; idx<NumOperators; ++idx)
  {
    MidiCC.SetController(WaveFormMidiCC[idx], 0);
  }
  g_LPFIntMulti.SetParameter((1+MidiCC.GetController(LpfMidiCC))*2);
  g_LPFIntMulti.SetStages(LPFNumPoles);

  int FreqMilliHz = GetMidiNoteFrequencyMilliHz(g_CurrMidiNote);
  g_PhaseInt.SetFrequency(SamplingFrequency, FreqMilliHz);
  g_PhaseIntSub.SetFrequency(SamplingFrequency, FreqMilliHz/2);

  g_CurrentOperator[0] = g_Operators[0];
  g_CurrentOperator[1] = g_Operators[0];
  g_CurrentOperator[2] = g_Operators[0];
  g_CurrentOperator[3] = g_Operators[0];

  //Serial.print("Freq= ");
  //Serial.print(FreqMilliHz);
  //Serial.print(" Phase= ");
  //Serial.println(g_PhaseInt.GetPhaseStep());

  g_InteruptCounter = 0;

  // always show current processing speed
  TestCalcSpeed();

  Timer3.attachInterrupt(myHandler);
  int SamplingPeriodMicroSeconds = 1000 * 1000 / SamplingFrequency;
  Timer3.start(SamplingPeriodMicroSeconds);
}

void OnNoteOn()
{
  int OscillatorFrequencyMilliHz = GetMidiNoteFrequencyMilliHz(g_CurrMidiNote);
  g_PhaseInt.SetFrequency(SamplingFrequency, OscillatorFrequencyMilliHz);
  g_PhaseInt.Sync();
  g_PhaseIntSub.SetFrequency(SamplingFrequency, OscillatorFrequencyMilliHz/2);
  g_PhaseIntSub.Sync();
}

void OnNoteOff()
{
  if (0 < g_CurrAmplitude)
  {
    --g_CurrAmplitude;
  }
}

void OnController(int Controller, int Value)
{
  //TODO
  int LPFCutOff = (1 + MidiCC.GetController(LpfMidiCC))*2;
  g_LPFIntMulti.SetParameter(LPFCutOff);

  for(int idx = 0; idx<NumOperators; ++idx)
  {
    int WaveForm = MidiCC.GetController(WaveFormMidiCC[idx])*NumWaveForms/128;//4 types
    g_CurrentOperator[idx] = g_Operators[WaveForm];
  }
}

void loop()
{
  if(SamplingFrequency*2<=g_InteruptCounter)
  {
    Serial.print(g_InteruptCounter);
    Serial.print(" t=");
    Serial.println(millis());
    g_InteruptCounter = 0;
  }
  // read midi in -> read something or read nothing
  // if note on/off, change curr amplitide, note
  // apply curr only when changed

  // read midi in
  // => simplest approach:
  // note on => curr note, ampl = 1, vel ignored
  // note off => ampl = 0, note and vel ignored
  // cc => store value if CC[]
  // other => ignored
  const int RawMidiInSize = 3;
  if (RawMidiInSize <= Serial1.available())
  {
    byte RawMidiInBuffer[RawMidiInSize];
    Serial1.readBytes(RawMidiInBuffer, RawMidiInSize);

    Serial.print("Recieved 0x");
    Serial.print(RawMidiInBuffer[0], HEX);
    Serial.print(" 0x");
    Serial.print(RawMidiInBuffer[1], HEX);
    Serial.print(" 0x");
    Serial.print(RawMidiInBuffer[2], HEX);
    Serial.println();

    if (RawMidiInBuffer[0] == 0x80)
    { //note off
      OnNoteOff();
      // debug:
      Serial.print("Note Off ");
      Serial.print(RawMidiInBuffer[1]);//note
      Serial.print(" (");
      Serial.print(RawMidiInBuffer[2]);//vel
      Serial.println(")");
    }
    else if (RawMidiInBuffer[0] == 0x90)
    { // note on
      ++g_CurrAmplitude;
      g_CurrMidiNote = RawMidiInBuffer[1];
      // ignore velocity
      OnNoteOn();
      // debug:
      Serial.print("Note On ");
      Serial.print(RawMidiInBuffer[1]);//note
      Serial.print(" (");
      Serial.print(RawMidiInBuffer[2]);//vel
      Serial.println(")");

    }
    else if (RawMidiInBuffer[0] == 0xB0)
    {
      int CC = RawMidiInBuffer[1];
      int Value = RawMidiInBuffer[2];
      MidiCC.SetController(CC, Value);
      // debug:
      Serial.print("CC ");
      Serial.print(CC);//controller
      Serial.print(" (");
      Serial.print(Value);//value
      Serial.println(")");
      //
      OnController(CC, Value);
    }
  }
}
