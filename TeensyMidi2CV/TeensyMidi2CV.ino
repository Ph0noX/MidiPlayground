
#include "MIDI.h"//serial midi on Serial1 
//#include "usb_api.h"

// use USB for midi in (and midi out) and use Serial1 as serial out
// comment out for using Serial1 as midi in and use usb as serial out
#define USE_USB 

// use this to switch between serial1 and usb midi
#ifdef USE_USB
#define MIDI_USED usbMIDI
#define SERIAL_USED Serial1
#endif

#ifndef USE_USB
#define MIDI_USED MIDI
#define SERIAL_USED Serial
#endif

void OnNoteOn(byte Channel, byte Note, byte Velocity)
{
  SERIAL_USED.print("NoteOn : ch ");
  SERIAL_USED.print(Channel, DEC);
  SERIAL_USED.print(" note ");
  SERIAL_USED.print(Note, DEC);
  SERIAL_USED.print(" vel ");
  SERIAL_USED.println(Velocity);
}

void OnNoteOff(byte Channel, byte Note, byte Velocity)
{
  SERIAL_USED.print("NoteOff : ch ");
  SERIAL_USED.print(Channel, DEC);
  SERIAL_USED.print(" note ");
  SERIAL_USED.print(Note, DEC);
  SERIAL_USED.print(" vel ");
  SERIAL_USED.println(Velocity);
}

void OnControlChange(byte Channel, byte Number, byte Value)
{
  SERIAL_USED.print("CC : ch ");
  SERIAL_USED.print(Channel, DEC);
  SERIAL_USED.print(" nr ");
  SERIAL_USED.print(Number, DEC);
  SERIAL_USED.print(" val ");
  SERIAL_USED.println(Value);
}

void OnPitchBend(byte Channel, int Bend)
{
  SERIAL_USED.print("PitchBend : ch ");
  SERIAL_USED.print(Channel, DEC);
  SERIAL_USED.print(" val ");
  SERIAL_USED.println(Bend);
}

void TestSerial1In()
{
  #ifndef USE_USB

  Serial.println("Testing serial 1 in...");
  while(true)
  {
    if(0<Serial1.available())
    {
      int Byte = Serial1.read();
      Serial.print(' 0x');
      Serial.println(Byte, HEX);
    }
  }
  
  #endif
}

void setup() {
  // put your setup code here, to run once:
  SERIAL_USED.begin(115200);
  delay(1000);//?
  
  SERIAL_USED.println("Teensy Midi In test...");

  #ifndef USE_USB
  MIDI_USED.begin(MIDI_CHANNEL_OMNI, 115200);//for now, use midi-ox or similar
  #endif

  //TestSerial1In();
  
  MIDI_USED.setHandleNoteOn(OnNoteOn);
  MIDI_USED.setHandleNoteOff(OnNoteOff);
  MIDI_USED.setHandleControlChange(OnControlChange);
  #ifndef USE_USB
  MIDI_USED.setHandlePitchBend(OnPitchBend);
  #endif
  #ifdef USE_USB
  MIDI_USED.setHandlePitchChange(OnPitchBend);
  #endif
  
  pinMode(13, OUTPUT);
  SERIAL_USED.println("Starting..");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int Repeat = 0; Repeat<100000; ++Repeat)
  {
    MIDI_USED.read();
  }
  //SERIAL_USED.println("Midi read 100000x");
}

