#include <SPI.h>
#include "UnoMcpDac.h"
#include "IntMultiStageEnvelope2.h"
#include "TimerOne.h"


static const unsigned long SamplingFrequency = 12000;

static const int DacScale = 12;//[0,4096[
static const int NumStages = 4;
typedef isl::CMultiStageEnvelope2<long, NumStages, DacScale> EnvelopeType;
EnvelopeType g_Envelope;

void WriteDac()
{
  unsigned int DacValue = g_Envelope();
  mcp48_setOutput(0, GAIN_1, 1, DacValue);
}

void TestAccuracy()
{
  //high-res saw wave
  for (unsigned int DacValue = 0; DacValue < 4096; DacValue += 32)
  {
    mcp48_setOutput(0, GAIN_1, 1, DacValue);
    //mcp48_setOutput(DacValue);

    int ValueA = analogRead(A0);
    int ValueB = analogRead(A1);
    Serial.print("DAC out=");
    Serial.print(DacValue);
    Serial.print(" ADC in=");
    Serial.print(ValueA);
    Serial.print(" ");
    Serial.print(ValueB);
    Serial.println();

    delay(250);
  }
}

void TestDacSpeed()
{
  unsigned long Number = SamplingFrequency;
  unsigned long Before = millis();

  //high-res saw wave
  for (unsigned long Repeat = 0; Repeat < SamplingFrequency; ++Repeat)
  {
    unsigned int DacValue = Repeat%(1<<DacScale);
    mcp48_setOutput(0, GAIN_1, 1, DacValue);
    //mcp48_setOutput(DacValue);
  }

  unsigned long After = millis();
  unsigned long Duration = After - Before;

  Serial.print("DAC out x ");
  Serial.print(Number);
  Serial.print(" = ");
  Serial.print(Duration);
  Serial.print(" mSec");
  Serial.println();
}

void TestEnvelopeSpeed()
{
  unsigned long Number = SamplingFrequency;
  unsigned long Before = millis();

  long Tmp = 0;
  for (unsigned long Repeat = 0; Repeat < SamplingFrequency; ++Repeat)
  {
      Tmp += g_Envelope();
  }

  unsigned long After = millis();
  unsigned long Duration = After - Before;

  Serial.print("DAC out x ");
  Serial.print(Number);
  Serial.print(" = ");
  Serial.print(Duration);
  Serial.print(" mSec (");
  Serial.print(Tmp);
  Serial.println();
}

void setup()
{
  Serial.begin(115200);
  Serial.println("UnoMultiStageEnvelope...");

  for(int Stage = 0; Stage<NumStages; ++Stage)
  {
    g_Envelope.SetDuration(Stage, SamplingFrequency/2);
    g_Envelope.SetTarget(Stage, Stage%2 ? 0 : 4095);
    g_Envelope.SetAction(Stage, true, EnvelopeType::AdvanceAction);
    g_Envelope.SetAction(Stage, false, EnvelopeType::HoldAction);
  }

  mcp48_begin();

  Serial.println("Testing...");
  TestDacSpeed();
  TestEnvelopeSpeed();
 
  
  Serial.println("Starting...");
  const unsigned long PeriodMicroSeconds = 1000000ul / SamplingFrequency;
  Timer1.initialize(PeriodMicroSeconds);
  Timer1.attachInterrupt(WriteDac);
}

void loop()
{
    //TestDacSpeed();
    //TestEnvelopeSpeed();
    //TestAccuracy();

    g_Envelope.NoteOn();
    Serial.println("Gate On...");
    delay(1600);
    
    g_Envelope.NoteOff();
    Serial.println("Gate Off...");
    delay(1600);
    
    //Serial.println("Running...");
    
  //TestSaw();
 // TestSquare();
}

