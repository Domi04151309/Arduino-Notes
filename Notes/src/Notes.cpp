/*
 *Notes - Library for a better tone command
 *
 *Copyright 2018 Dominik Reichl
 *
 *Developed by Dominik Reichl
 *
 *This library is free software; you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation; either version 2 of the License, or
 *(at your option) any later version.
 *
 *This library is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this library; if not, write to the Free Software
 *Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *As a special exception, you may use this file as part of a free software
 *library without restriction.  Specifically, if other files instantiate
 *templates or use macros or inline functions from this file, or you compile
 *this file and link it with other files to produce an executable, this
 *file does not by itself cause the resulting executable to be covered by
 *the GNU General Public License.  This exception does not however
 *invalidate any other reasons why the executable file might be covered by
 *the GNU General Public License.
 */

#include <Arduino.h>
#include <Notes.h>
#include <Board.h>

//Setup process
Notes::Notes(unsigned int x, unsigned int y){ 
  beatLEDTime=x;
  toneDelay=y;
}

//Sets the speakerPort and the speed
void Notes::speakerSetup(uint8_t speaker, unsigned int speed){
  //For Debugging
  Serial.print("speakerSetup ");Serial.print(speaker);Serial.print(", ");Serial.println(speed);
  
  #ifdef ARDUINO_BOARD_UNO
  if(speaker != 3 && speaker != 5 && speaker != 6 && speaker != 9 && speaker != 10 && speaker != 11){
		Serial.println("###");
		Serial.println("### ERROR: Pin has to be 3, 5, 6, 9, 10 or 11");
		Serial.println("###");
  }
  #elif defined ARDUINO_BOARD_ZERO
  if(speaker != 3 && speaker != 4 && speaker != 5 && speaker != 6 && speaker != 8 && speaker != 9 && speaker != 10 && speaker != 11 && speaker != 12 && speaker != 13){
		Serial.println("###");
		Serial.println("### ERROR: Pin has to be 3, 4, 5, 6, 8, 9, 10, 11, 12 or 13");
		Serial.println("###");
  }
  #elif defined ARDUINO_BOARD_YUN_400MHZ
  if(speaker != 3 && speaker != 5 && speaker != 6 && speaker != 10 && speaker != 11){
		Serial.println("###");
		Serial.println("### ERROR: Pin has to be 3, 5, 6, 10 or 11");
		Serial.println("###");
  }
  #endif
  
  speakerPort=speaker;
  bpm=speed;
  beatDuration=60000/bpm;
}

//Sets the ports of the LED pins
void Notes::toneLEDSetup(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5, uint8_t pin6, uint8_t pin7){
  //For Debugging
  Serial.print("toneLEDSetup ");Serial.print(pin0);Serial.print(", ");Serial.print(pin1);Serial.print(", ");Serial.print(pin2);Serial.print(", ");Serial.print(pin3);Serial.print(", ");Serial.print(pin4);Serial.print(", ");Serial.print(pin5);Serial.print(", ");Serial.print(pin6);Serial.print(", ");Serial.println(pin7);
  
  #if defined(ARDUINO_BOARD_UNO) || defined(ARDUINO_BOARD_ZERO) || defined(ARDUINO_BOARD_YUN_400MHZ)
  if(pin0 > 14 || pin1 > 14 || pin2 > 14 || pin3 > 14 || pin4 > 14 || pin5 > 14 || pin6 > 14 || pin7 > 14 || pin0 < 2 || pin1 < 2 || pin2 < 2 || pin3 < 2 || pin4 < 2 || pin5 < 2 || pin6 < 2 || pin7 < 2){
		Serial.println("###");
		Serial.println("### ERROR: Pin numbers have to be between 2 and 13");
		Serial.println("###");
  }
  #endif
  
  beatLEDPort=pin0;
  cLED=pin1;
  dLED=pin2;
  eLED=pin3;
  fLED=pin4;
  gLED=pin5;
  aLED=pin6;
  bLED=pin7;
  pinMode(beatLEDPort, OUTPUT);
  pinMode(cLED, OUTPUT);
  pinMode(dLED, OUTPUT);
  pinMode(eLED, OUTPUT);
  pinMode(fLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(aLED, OUTPUT);
  pinMode(bLED, OUTPUT);
}

void Notes::toneLEDState(bool state){
	toneLEDStateBool = state;
}

//A LED blinks
void Notes::blinkLED(uint8_t param1LED){
  //For Debugging
  Serial.print("blinkLED ");Serial.println(param1LED);
  digitalWrite(param1LED,HIGH);
  delay(beatDuration/4);
  digitalWrite(param1LED,LOW);
}

//BeatLED blinks
void Notes::beatLEDFunction(){
  digitalWrite(beatLEDPort,HIGH);
  delay(beatLEDTime);
  digitalWrite(beatLEDPort,LOW);
}

//BeatLED blink + 1/4 note
void Notes::beatLEDFunctionFour(uint8_t z){
  for(uint8_t repeats=z; repeats>0; repeats=repeats-1){
    beatLEDFunction();
    delay(beatDuration-beatLEDTime);
  }
}

//noTone with delay after every note in case of two equal notes after each other
void Notes::noToneDelay(){
  noTone(speakerPort);
  delay(toneDelay);
}

//Main function of this library
void Notes::note(float param1, uint8_t param2, bool param3, bool param4){
    
  //For Debugging
  Serial.print("note ");Serial.print(param1);Serial.print(", ");Serial.print(param2);Serial.print(", ");Serial.print(param3);Serial.print(", ");Serial.println(param4);
  
  //Plays the sound
  tone(speakerPort,param1);
  
	if(toneLEDStateBool == true){
		//LEDs for the notes
		int x;
		for(x=param1;x>NOTE_B1;x=x/2){
			Serial.println(x);
		}
		if(x<=NOTE_C1){
		  toneLED=cLED;
		}else if(x<=NOTE_D1){
		  toneLED=dLED;
		}else if(x<=NOTE_E1){
		  toneLED=eLED;
		}else if(x<=NOTE_F1){
		  toneLED=fLED;
		}else if(x<=NOTE_G1){
		  toneLED=gLED;
		}else if(x<=NOTE_A1){
		  toneLED=aLED;
		}else if(x<=NOTE_B1){
		  toneLED=bLED;
		}
		
		//Turns on the toneLED
		digitalWrite(toneLED,HIGH);
	}
  
  if(param4 == false){
		switch(param2){
			case 1:
				//1/1 note
				beatLEDFunctionFour(3);
				beatLEDFunction();
				delay(beatDuration-beatLEDTime-toneDelay);
				noToneDelay();
				break;
				
			case 2:
				if(param3 == true){
					//1/2 note with point
					beatLEDFunctionFour(2);
					beatLEDFunction();
					delay(beatDuration-beatLEDTime-toneDelay);
					noToneDelay();
				}else if(param3 == false){
					//1/2 note
					beatLEDFunctionFour();
					beatLEDFunction();
					delay(beatDuration-beatLEDTime-toneDelay);
					noToneDelay();
				}
				break;
				
			case 4:
				if(param3 == true){
					//1/4 note with point
					beatLEDFunctionFour();
					beatLEDFunction();
					delay(beatDuration/2-beatLEDTime-toneDelay);
					noToneDelay();
				}else if(param3 == false){
					//1/4 note
					beatLEDFunction();
					delay(beatDuration-beatLEDTime-toneDelay);
					noToneDelay();
				}
				break;
				
			case 8:
				//1/8 note
				beatLEDFunction();
				delay(beatDuration/2-beatLEDTime-toneDelay);
				noToneDelay();
				break;
				
			default:
				Serial.println("###");
				Serial.println("### ERROR: Parameter 2 has to be 1, 2, 4 or 8");
				Serial.println("###");
				break;
    }
	
  }else if(param4 == true){
		switch(param2){
			case 1:
				//1/1 note with asynchronous beatLED
				delay(beatDuration/2);
				beatLEDFunctionFour(3);
				beatLEDFunction();
				delay(beatDuration/2-beatLEDTime-toneDelay);
				noToneDelay();
				break;
				
			case 2:
				if(param3 == true){
				//1/2 note with asynchronous beatLED and point
					delay(beatDuration/2);
					beatLEDFunctionFour(2);
					beatLEDFunction();
					delay(beatDuration/2-beatLEDTime-toneDelay);
					noToneDelay();
				}else if(param3 == false){
				//1/2 note with asynchronous beatLED
					delay(beatDuration/2);
					beatLEDFunctionFour();
					beatLEDFunction();
					delay(beatDuration/2-beatLEDTime-toneDelay);
					noToneDelay();
				}
				break;
				
			case 4:
				if(param3 == true){
				//1/4 note with asynchronous beatLED and point
					delay(beatDuration/2);
					beatLEDFunction();
					delay(beatDuration-beatLEDTime-toneDelay);
					noToneDelay();
				}else if(param3 == false){
				//1/4 note with asynchronous beatLED
					delay(beatDuration/2);
					beatLEDFunction();
					delay(beatDuration/2-beatLEDTime-toneDelay);
					noToneDelay();
				}
				break;
				
			case 8:
				//1/8 note with asynchronous beatLED
				delay(beatDuration/2-toneDelay);
				noToneDelay();
				break;
				
			default:
				Serial.println("###");
				Serial.println("### ERROR: Parameter 2 has to be 1, 2, 4 or 8");
				Serial.println("###");
				break;
    }
  }	
	if(toneLEDStateBool == true){
		//Turns off the toneLED
		digitalWrite(toneLED,LOW);
	}
}