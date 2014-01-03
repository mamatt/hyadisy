/*  Example of a sound being triggered by MIDI input.
 *
 *  Demonstrates playing notes with Mozzi in response to MIDI input,
 *  using the version of the Arduino MIDI library which
 *  works with Teensy boards (http://www.pjrc.com/teensy/td_midi.html).  
 *  Tested on a Teensy2++, which can be used as a MIDI device 
 *  without any extra parts.  
 *  The sketch would be almost the same with the mainstream
 *  MIDI library (using MIDI as a prefix to calls instead of usbMIDI).
 *  This sketch won't compile on the Teensy2++ if you also 
 *  have the mainstream MIDI library installed.
 *
 *  Circuit: On the Teensy2++, audio output is on pin B5.  Midi input on usb.
 *
 *  Mozzi help/discussion/announcements:
 *  https://groups.google.com/forum/#!forum/mozzi-users
 *
 *  Tim Barrass 2013.
 *  This example code is in the public domain.
 */
#define AUDIO_MODE HIFI


#include <MIDI.h>
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <Line.h> // for envelope
#include <tables/saw2048_int8.h> // sine table for oscillator
#include <tables/sin2048_int8.h>
#include <mozzi_midi.h>
#include <ADSR.h>
#include <mozzi_fixmath.h>
#include <mozzi_analog.h>
#include <SPI.h>
#include <McpDigitalPot.h>

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 128 // powers of 2 please

// audio sinewave oscillator
Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aTri0 (SAW2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin0(SIN2048_DATA);

// envelope generator
ADSR <CONTROL_RATE> envelope;

//#define AUDIO_MODE HIFI

#define LED 13

#define CUTOFF_CV 3

byte gainS ;
byte gainT ;

byte cutOFF ;

byte Reso ;

// Wire up the SPI Interface common lines:
// #define SPI_CLOCK            13 //arduino   <->   SPI Slave Clock Input     -> SCK (Pin 02 on McpDigitalPot DIP)
// #define SPI_MOSI             11 //arduino   <->   SPI Master Out Slave In   -> SDI (Pin 03 on McpDigitalPot DIP)
// #define SPI_MISO             12 //arduino   <->   SPI Master In Slave Out   -> SDO (Pin 13 on McpDigitalPot DIP)

// Then choose any other free pin as the Slave Select (pin 10 if the default but doesnt have to be)
#define MCP_DIGITAL_POT_SLAVE_SELECT_PIN 8 //arduino   <->   Chip Select               -> CS  (Pin 01 on McpDigitalPot DIP)

// Its recommended to measure the rated end-end resistance (terminal A to terminal B)
// Because this can vary by a large margin, up to -+ 20%. And temperature variations.
float rAB_ohms = 10000.00; // 10k Ohm

// Instantiate McpDigitalPot object, with default rW (=117.5 ohm, its typical resistance)
McpDigitalPot digitalPot = McpDigitalPot( MCP_DIGITAL_POT_SLAVE_SELECT_PIN, rAB_ohms );

void HandleNoteOn(byte channel, byte note, byte velocity) { 
  if(velocity == 0){
    // some midi controllers send velocity 0 instead of note-off
    envelope.noteOff();
    //digitalWrite(LED,LOW);
  }  
  else{
    //aSig.setFreq(mtof(note)); // simple but less accurate frequency
    aTri0.setFreq_Q16n16(Q16n16_mtof(Q8n0_to_Q16n16(note))); // accurate frequency
    aSin0.setFreq_Q16n16(Q16n16_mtof(Q8n0_to_Q16n16(note-8))); // accurate frequency
    envelope.noteOn();
    //digitalWrite(LED,HIGH);
  }
}


void HandleNoteOff(byte channel, byte note, byte velocity) { 
  envelope.noteOff();
  //digitalWrite(LED,LOW);
}


void setup() {
  //pinMode(LED, OUTPUT);
//Serial.begin(115200);  
  pinMode(CUTOFF_CV,OUTPUT);
  
  //SPI Setup
  SPI.begin(); 
  
  // First measure the the wiper resistance, called rW
  digitalPot.setPosition(0, 0); // rAW = rW_ohms
  //digitalPot.setPosition(1, 0); // rAW = rW_ohms
  
  digitalPot.scale = 255;
  
  MIDI.begin(MIDI_CHANNEL_OMNI);    
  Serial.begin(115200);  

  // Connect the HandleNoteOn function to the library, so it is called upon reception of a NoteOn.
  MIDI.setHandleNoteOn(HandleNoteOn);    // Put only the name of the function
  MIDI.setHandleNoteOff(HandleNoteOff);  // Put only the name of the function

  envelope.setADLevels(255,64);
  envelope.setTimes(50,200,10000,200); // 10000 is so the note will sustain 10 seconds unless a noteOff comes

  aSin0.setFreq(440); // default frequency
  aTri0.setFreq(440);
  
  //adcEnableInterrupt(); // enables the ADC interrupt which gets triggered by adcReadAllChannels()
  
  startMozzi(CONTROL_RATE); 
}


void updateControl(){
  gainS = mozziAnalogRead(A0)>>2; // 0 to 255
  gainT = mozziAnalogRead(A1)>>2; // 0 to 255
  
  cutOFF = mozziAnalogRead(A2)>>2; // 0 to 255

  Reso = mozziAnalogRead(A3) >> 2 ; // O to 255

  MIDI.read();
  envelope.update();
  
  updateReso(Reso) ;
  
}

void updateReso(byte counter) {
	 digitalPot.setResistance(0, counter);
}



void updateCV_Cutoff(byte cutOFF_value) {
	static byte cv_count ;
// PORTD maps to Arduino digital pins 0 to 7
// http://playground.arduino.cc/Learning/PortManipulation
  (cv_count++ >= cutOFF_value) ? PORTD &= ~(1 << CUTOFF_CV) : PORTD |= (1 << CUTOFF_CV);
  //(green_count++ >= g) ? PORTD &= ~(1 << GREEN_PIN) : PORTD |= (1 << GREEN_PIN);
  //(blue_count++ >= b) ? PORTD &= ~(1 << BLUE_PIN) : PORTD |= (1 << BLUE_PIN);
} ;

int updateAudio(){
  
  updateCV_Cutoff(cutOFF) ;
  
  int tri = aTri0.next() * (gainT -1) >> 8 ;
  int sin = aSin0.next() * (gainS -1) >> 8 ;
  
  return (int) (sin + tri) << 5 ;
}


void loop() {
  audioHook(); // required here
} 





