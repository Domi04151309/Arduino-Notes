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
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program; if not, write to the Free Software
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

//Setup process
Notes::Notes(unsigned int x, unsigned int y){ 
  beatLEDTime=x;
  toneDelay=y;
}

//Sets the speakerPort and the speed
void Notes::speakerSetup(unsigned int speaker, unsigned int speaker2){
  //For Debugging
  Serial.print("speakerSetup ");Serial.print(speaker);Serial.print(", ");Serial.println(speaker2);
  
  if(speaker != 3 && speaker != 5 && speaker != 6 && speaker != 9 && speaker != 10 && speaker != 11){
	Serial.println("###");
	Serial.println("### ERROR: Port has to be 3, 5, 6, 9, 10 or 11");
	Serial.println("###");
  }
  
  speakerPort=speaker;
  bpm=speaker2;
  beatDuration=60000/bpm;
}

//Sets the ports of the LED pins
void Notes::toneLEDSetup(unsigned int pin0, unsigned int pin1, unsigned int pin2, unsigned int pin3, unsigned int pin4, unsigned int pin5, unsigned int pin6, unsigned int pin7){
  //For Debugging
  Serial.print("toneLEDSetup ");Serial.print(pin0);Serial.print(", ");Serial.print(pin1);Serial.print(", ");Serial.print(pin2);Serial.print(", ");Serial.print(pin3);Serial.print(", ");Serial.print(pin4);Serial.print(", ");Serial.print(pin5);Serial.print(", ");Serial.print(pin6);Serial.print(", ");Serial.println(pin7);
  
  if(pin0 > 14 || pin1 > 14 || pin2 > 14 || pin3 > 14 || pin4 > 14 || pin5 > 14 || pin6 > 14 || pin7 > 14 || pin0 < 2 || pin1 < 2 || pin2 < 2 || pin3 < 2 || pin4 < 2 || pin5 < 2 || pin6 < 2 || pin7 < 2){
	Serial.println("###");
	Serial.println("### ERROR: Port numbers have to be between 2 and 13");
	Serial.println("###");
  }
  
  beatLEDPort=pin0;
  cLED=pin1;
  dLED=pin2;
  eLED=pin3;
  fLED=pin4;
  gLED=pin5;
  aLED=pin6;
  hLED=pin7;
  pinMode(beatLEDPort, OUTPUT);
  pinMode(cLED, OUTPUT);
  pinMode(dLED, OUTPUT);
  pinMode(eLED, OUTPUT);
  pinMode(fLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(aLED, OUTPUT);
  pinMode(hLED, OUTPUT);
}

//A LED blinks
void Notes::blinkLED(unsigned int param1LED){
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
void Notes::beatLEDFunctionFour(unsigned int z){
  for(unsigned int repeats=z; repeats>0; repeats=repeats-1){
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
void Notes::note(float param1, unsigned int param2, bool param3, bool param4){
    
  //For Debugging
  Serial.print("note ");Serial.print(param1);Serial.print(", ");Serial.print(param2);Serial.print(", ");Serial.print(param3);Serial.print(", ");Serial.println(param4);
  
  if(param2 != 1 && param2 != 2 && param2 != 4 && param2 != 8){
	Serial.println("###");
	Serial.println("### ERROR: Parameter 2 has to be 1, 2, 4 or 8");
	Serial.println("###");
  }
  
  //Plays the sound
  tone(speakerPort,param1);
  
  //LEDs for the notes
  if (param1 <= 132){toneLED=cLED;}			//low
  else if (param1 <= 148.5){toneLED=dLED;}
  else if (param1 <= 165){toneLED=eLED;}
  else if (param1 <= 176){toneLED=fLED;}
  else if (param1 <= 198){toneLED=gLED;}
  else if (param1 <= 220){toneLED=aLED;}
  else if (param1 <= 247.5){toneLED=hLED;}
  
  else if (param1 <= 264){toneLED=cLED;}	//normal
  else if (param1 <= 297){toneLED=dLED;}
  else if (param1 <= 330){toneLED=eLED;}
  else if (param1 <= 352){toneLED=fLED;}
  else if (param1 <= 396){toneLED=gLED;}
  else if (param1 <= 440){toneLED=aLED;}
  else if (param1 <= 495){toneLED=hLED;}
  
  else if (param1 <= 528){toneLED=cLED;}	//high
  else if (param1 <= 594){toneLED=dLED;}
  else if (param1 <= 660){toneLED=eLED;}
  else if (param1 <= 704){toneLED=fLED;}
  else if (param1 <= 792){toneLED=gLED;}
  else if (param1 <= 880){toneLED=aLED;}
  else if (param1 <= 990){toneLED=hLED;}
  
  else if (param1 <= 1056){toneLED=cLED;}	//very high
  else if (param1 <= 1188){toneLED=dLED;}
  else if (param1 <= 1320){toneLED=eLED;}
  else if (param1 <= 1408){toneLED=fLED;}
  else if (param1 <= 1584){toneLED=gLED;}
  else if (param1 <= 1760){toneLED=aLED;}
  else if (param1 <= 1980){toneLED=hLED;}
  //Turns on the toneLED
  digitalWrite(toneLED,HIGH);
  
  if(param4 == false){
    if(param2 == 1){
      //1/1 note
      beatLEDFunctionFour(3);
      beatLEDFunction();
      delay(beatDuration-beatLEDTime-toneDelay);
      noToneDelay();
    }else if(param2 == 2){
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
    }else if(param2 == 4){ 
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
    }else if(param2 == 8){
      //1/8 note
      beatLEDFunction();
      delay(beatDuration/2-beatLEDTime-toneDelay);
      noToneDelay();
    }
  }else if(param4 == true){
    if(param2 == 1){
      //1/1 note with asynchronous beatLED
      delay(beatDuration/2);
      beatLEDFunctionFour(3);
      beatLEDFunction();
      delay(beatDuration/2-beatLEDTime-toneDelay);
      noToneDelay();
    }else if(param2 == 2){
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
    }else if(param2 == 4){ 
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
    }else if(param2 == 8){
      //1/8 note with asynchronous beatLED
      delay(beatDuration/2-toneDelay);
      noToneDelay();
    }
  }
  //Turns off the toneLED
  digitalWrite(toneLED,LOW);
}