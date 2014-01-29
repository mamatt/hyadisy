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
//#include <Oscil.h> // oscillator template
#include "OscilM.h" // version perso
//#include <Line.h> // for envelope
#include "triangle4096_int8M.h"
//#include <tables/triangle2048_int8.h>
//#include "tri.h"
#include "saw4096_int8M.h"
//#include <tables/saw4096_int8.h>
#include <mozzi_midi.h>
//#include <ADSR.h>
//#include <mozzi_fixmath.h>
//#include <mozzi_analog.h>
#include <SPI.h>
//#include <McpDigitalPot.h>

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 128 // powers of 2 please

// audio sinewave oscillator
Oscil <SAW4096_NUM_CELLS, AUDIO_RATE>      OSC1(SAW4096_DATA);
Oscil <TRIANGLE4096_NUM_CELLS, AUDIO_RATE> OSC2(TRIANGLE4096_DATA);

// envelope generator
//ADSR <CONTROL_RATE> envelope;


//#define CUTOFF_PIN 3
#define RESO_PIN 6
#define DAC_PIN 7

byte gainOSC1 =128 ;
byte gainOSC2 =128 ;

//int TestSample=0 ;
//int PhaseACC=0 ;

//byte cutOFF ;

byte Reso ;

// Wire up the SPI Interface common lines:
// #define SPI_CLOCK            13 //arduino   <->   SPI Slave Clock Input     -> SCK (Pin 02 on McpDigitalPot DIP)
// #define SPI_MOSI             11 //arduino   <->   SPI Master Out Slave In   -> SDI (Pin 03 on McpDigitalPot DIP)
// #define SPI_MISO             12 //arduino   <->   SPI Master In Slave Out   -> SDO (Pin 13 on McpDigitalPot DIP)


void HandleNoteOn(byte channel, byte note, byte velocity) { 
 /* if(velocity == 0){
    // some midi controllers send velocity 0 instead of note-off
    envelope.noteOff();
    //digitalWrite(LED,LOW);
  }  
  else {
   */ //aSig.setFreq(mtof(note)); // simple but less accurate frequency
    OSC1.setFreq_Q16n16(Q16n16_mtof(Q8n0_to_Q16n16(note))); // accurate frequency
    OSC2.setFreq_Q16n16(Q16n16_mtof(Q8n0_to_Q16n16(note))); // accurate frequency
   /* envelope.noteOn();
  }*/
}

void HandleNoteOff(byte channel, byte note, byte velocity) { 
  //envelope.noteOff();
}

void setup() {
	
  pinMode(RESO_PIN,OUTPUT);
  pinMode(DAC_PIN,OUTPUT) ;
  
  //SPI Setup
  SPI.begin(); 
  SPI.setBitOrder(MSBFIRST);
  
  
  //MIDI.begin(MIDI_CHANNEL_OMNI);    
  //Serial.begin(115200);  

  // Connect the HandleNoteOn function to the library, so it is called upon reception of a NoteOn.
  //MIDI.setHandleNoteOn(HandleNoteOn);    // Put only the name of the function
  //MIDI.setHandleNoteOff(HandleNoteOff);  // Put only the name of the function

  //MIDI.setHandleControleChange(HandleCC) ;

 // envelope.setADLevels(255,64);
 // envelope.setTimes(50,200,1000,200); // 10000 is so the note will sustain 1 seconds unless a noteOff comes

  OSC1.setFreq(440); // default frequency
  OSC2.setFreq(440);
    
  startMozzi(CONTROL_RATE); 
}

void updateControl(){
  //gainOSC1 = mozziAnalogRead(A0) >> 2; // 0 to 255
 
  //gainOSC2 = 255 - gainOSC1 ;
 
  //Reso = mozziAnalogRead(A2)>>2; // 0 to 255

  
  //MIDI.read();

  //envelope.update();
  
  //updateReso(Reso) ;
}

void updateReso(byte val) {
	
	byte cmd=0; // cmd est la commande que l'on va envoyer
	//cmd = pot<<12; // 000x 0000 0000 0000 cf figure 7-2
	//val = val&255; // ainsi val <= 255
	//cmd |= val; 
	
	PORTD &= ~(1<<RESO_PIN) ; // Set #CS for DAC low, selecting it
	
	SPDR = cmd;  //The SPI Data Register - Writing to the register initiates data transmission.
    while (!(SPSR & (1<<SPIF)));
    SPDR = val ;
    while (!(SPSR & (1<<SPIF)));
    
    PORTD |= (1<<RESO_PIN)  ; // Set #CS for DAC high, deselecting it
}

void updateCV_Cutoff(byte cutOFF_value) {
	static byte cv_count ;
// PORTD maps to Arduino digital pins 0 to 7
// http://playground.arduino.cc/Learning/PortManipulation
  //(cv_count++ >= cutOFF_value) ? PORTD &= ~(1 << CUTOFF_PIN) : PORTD |= (1 << CUTOFF_PIN);
  //(green_count++ >= g) ? PORTD &= ~(1 << GREEN_PIN) : PORTD |= (1 << GREEN_PIN);
  //(blue_count++ >= b) ? PORTD &= ~(1 << BLUE_PIN) : PORTD |= (1 << BLUE_PIN);
} ;

int updateAudio(){

  //long OSC1Value = (((( (long)OSC1.next() / 8 + 128 )  * gainOSC1 ) >> 4 ) - 2048 );
  int Value = ( ( (long)OSC1.next() * gainOSC1 ) + ( (long)OSC2.next() * gainOSC2 ) ) >> 9 ;
  //int OSC2Value =  >> 8;
  
  //Serial.print(OSC1Value) ;
  
  
   return Value ;
  
}

void loop() {
  audioHook(); // required here
}  





