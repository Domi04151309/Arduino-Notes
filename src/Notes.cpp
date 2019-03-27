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

//Class constructor
Notes::Notes(){}

//Advanced settings
void Notes::advancedSettings(unsigned int beatBlinkDuration, unsigned int toneGap){ 
  _beatBlinkDuration = beatBlinkDuration;
  _toneGap = toneGap;
}

//Warning message on serial monitor
void Notes::warning(String msg){
  Serial.println("###\n### WARNING: " + msg + "\n###");
}

//speakerPin and speed
void Notes::speakerSetup(uint8_t pin, unsigned int speed){
  //For Debugging
  Serial.println("speakerSetup " + String(pin) + ", " + String(speed));
  
  #ifdef ARDUINO_BOARD_UNO
  if(pin != 3 && pin != 5 && pin != 6 && pin != 9 && pin != 10 && pin != 11){
    warning("Pin has to be 3, 5, 6, 9, 10 or 11");
  }
  #elif defined ARDUINO_BOARD_ZERO
  if(pin != 3 && pin != 4 && pin != 5 && pin != 6 && pin != 8 && pin != 9 && pin != 10 && pin != 11 && pin != 12 && pin != 13){
    warning("Pin has to be 3, 4, 5, 6, 8, 9, 10, 11, 12 or 13");
  }
  #elif defined ARDUINO_BOARD_YUN_400MHZ
  if(pin != 3 && pin != 5 && pin != 6 && pin != 10 && pin != 11){
    warning("Pin has to be 3, 5, 6, 10 or 11");
  }
  #endif
  
  speakerPin = pin;
  bpm = speed;
  beatDuration = 60000 / bpm;
}

//LED pins
void Notes::toneLEDSetup(uint8_t beat, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t a, uint8_t b){
  //For Debugging
  Serial.println("toneLEDSetup " + String(beat) + ", " + String(c) + ", " + String(d) + ", " + String(e) + ", " + String(f) + ", " + String(g) + ", " + String(a) + ", " + String(b));
  
  #if defined(ARDUINO_BOARD_UNO) || defined(ARDUINO_BOARD_ZERO) || defined(ARDUINO_BOARD_YUN_400MHZ)
  if(beat > 14 || c > 14 || d > 14 || e > 14 || f > 14 || g > 14 || a > 14 || b > 14 || beat < 2 || c < 2 || d < 2 || e < 2 || f < 2 || g < 2 || a < 2 || b < 2){
    warning("Pin numbers have to be between 2 and 13");
  }
  #endif
  
  beatLEDPin = beat;
  cLED = c;
  dLED = d;
  eLED = e;
  fLED = f;
  gLED = g;
  aLED = a;
  bLED = b;
  pinMode(beatLEDPin, OUTPUT);
  pinMode(cLED, OUTPUT);
  pinMode(dLED, OUTPUT);
  pinMode(eLED, OUTPUT);
  pinMode(fLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(aLED, OUTPUT);
  pinMode(bLED, OUTPUT);
}

//beatLED blinks
void Notes::beatLEDFunction(){
  digitalWrite(beatLEDPin, HIGH);
  delay(_beatBlinkDuration);
  digitalWrite(beatLEDPin, LOW);
}

//beatLED blink + 1/4 note
void Notes::repeatBeatLEDFunction(uint8_t repeats){
  for(uint8_t i = repeats; i > 0; i--){
    beatLEDFunction();
    delay(beatDuration - _beatBlinkDuration);
  }
}

//noTone with delay after every note in case of two equal notes after each other
void Notes::noToneDelay(){
  noTone(speakerPin);
  delay(_toneGap);
}

//Main function of this library
void Notes::note(float frequency, uint8_t duration, bool dotted, bool offbeat){
    
  //For Debugging
  Serial.println("note " + String(frequency) + "," + String(duration) + "," + String(dotted) + "," + String(offbeat));
  
  //Plays the tone
  tone(speakerPin, frequency);
  
  //LEDs for the notes
  int x;
  for(x = frequency; x > NOTE_B1; x = x / 2){}
  if(x <= NOTE_C1){
    toneLED = cLED;
  }else if(x <= NOTE_D1){
    toneLED = dLED;
  }else if(x <= NOTE_E1){
    toneLED = eLED;
  }else if(x <= NOTE_F1){
    toneLED = fLED;
  }else if(x <= NOTE_G1){
    toneLED = gLED;
  }else if(x <= NOTE_A1){
    toneLED = aLED;
  }else if(x <= NOTE_B1){
    toneLED = bLED;
  }
  
  //Turns on the toneLED
  digitalWrite(toneLED, HIGH);
  
  if(offbeat == false){
    switch(duration){
      case 1:
        //1/1 note
        repeatBeatLEDFunction(3);
        beatLEDFunction();
        delay(beatDuration - _beatBlinkDuration - _toneGap);
        noToneDelay();
        break;
        
      case 2:
        if(dotted == true){
          //1/2 note with point
          repeatBeatLEDFunction(2);
          beatLEDFunction();
          delay(beatDuration - _beatBlinkDuration - _toneGap);
          noToneDelay();
        }else if(dotted == false){
          //1/2 note
          repeatBeatLEDFunction();
          beatLEDFunction();
          delay(beatDuration - _beatBlinkDuration - _toneGap);
          noToneDelay();
        }
        break;
        
      case 4:
        if(dotted == true){
          //1/4 note with point
          repeatBeatLEDFunction();
          beatLEDFunction();
          delay(beatDuration / 2 - _beatBlinkDuration - _toneGap);
          noToneDelay();
        }else if(dotted == false){
          //1/4 note
          beatLEDFunction();
          delay(beatDuration - _beatBlinkDuration - _toneGap);
          noToneDelay();
        }
        break;
        
      case 8:
        //1/8 note
        beatLEDFunction();
        delay(beatDuration / 2 - _beatBlinkDuration - _toneGap);
        noToneDelay();
        break;
        
      default:
        warning("Duration has to be 1, 2, 4 or 8");
        break;
    }
  
  }else if(offbeat == true){
    switch(duration){
      case 1:
        //1/1 note with asynchronous beatLED
        delay(beatDuration / 2);
        repeatBeatLEDFunction(3);
        beatLEDFunction();
        delay(beatDuration / 2 - _beatBlinkDuration - _toneGap);
        noToneDelay();
        break;
        
      case 2:
        if(dotted == true){
        //1/2 note with asynchronous beatLED and point
          delay(beatDuration / 2);
          repeatBeatLEDFunction(2);
          beatLEDFunction();
          delay(beatDuration / 2 - _beatBlinkDuration - _toneGap);
          noToneDelay();
        }else if(dotted == false){
        //1/2 note with asynchronous beatLED
          delay(beatDuration / 2);
          repeatBeatLEDFunction();
          beatLEDFunction();
          delay(beatDuration / 2 - _beatBlinkDuration - _toneGap);
          noToneDelay();
        }
        break;
        
      case 4:
        if(dotted == true){
        //1/4 note with asynchronous beatLED and point
          delay(beatDuration / 2);
          beatLEDFunction();
          delay(beatDuration - _beatBlinkDuration - _toneGap);
          noToneDelay();
        }else if(dotted == false){
        //1/4 note with asynchronous beatLED
          delay(beatDuration / 2);
          beatLEDFunction();
          delay(beatDuration / 2 - _beatBlinkDuration - _toneGap);
          noToneDelay();
        }
        break;
        
      case 8:
        //1/8 note with asynchronous beatLED
        delay(beatDuration / 2 - _toneGap);
        noToneDelay();
        break;
        
      default:
        warning("Duration has to be 1, 2, 4 or 8");
        break;
    }
  }  
  //Turns off the toneLED
  digitalWrite(toneLED, LOW);
}
