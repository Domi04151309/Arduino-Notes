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
 
#include <Pitches.h>
#ifndef Notes_h
#define Notes_h

#define ON true
#define OFF false

class Notes
{
 public:
   Notes(unsigned int x, unsigned int y);
   void speakerSetup(uint8_t speaker, unsigned int speaker2 = 120);
   void toneLEDSetup(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5, uint8_t pin6, uint8_t pin7);
	 void toneLEDState(bool state = true);
   void blinkLED(uint8_t param1LED);
   void note(float param1, uint8_t param2, bool param3 = false, bool param4 = false);
 private:
	 bool toneLEDStateBool = false;
   uint8_t speakerPort;
   uint8_t beatLEDPort;
   uint8_t cLED;
   uint8_t dLED;
   uint8_t eLED;
   uint8_t fLED;
   uint8_t gLED;
   uint8_t aLED;
   uint8_t bLED;
   uint8_t toneLED;
   unsigned int bpm;
   float beatDuration;
   unsigned int beatLEDTime;
   unsigned int toneDelay;
   void beatLEDFunction();
   void beatLEDFunctionFour(uint8_t z = 1);
   void noToneDelay();
};

#endif