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

class Notes
{
 public:
   Notes(unsigned int x, unsigned int y);
   void speakerSetup(unsigned int speaker, unsigned int speaker2 = 120);
   void toneLEDSetup(unsigned int pin0, unsigned int pin1, unsigned int pin2, unsigned int pin3, unsigned int pin4, unsigned int pin5, unsigned int pin6, unsigned int pin7);
   void blinkLED(unsigned int param1LED);
   void note(float param1, unsigned int param2, bool param3 = false, bool param4 = false);
  private:
   unsigned int speakerPort;
   unsigned int beatLEDPort;
   unsigned int cLED;
   unsigned int dLED;
   unsigned int eLED;
   unsigned int fLED;
   unsigned int gLED;
   unsigned int aLED;
   unsigned int hLED;
   unsigned int toneLED;
   unsigned int bpm;
   float beatDuration;
   unsigned int beatLEDTime;
   unsigned int toneDelay;
   void beatLEDFunction();
   void beatLEDFunctionFour(unsigned int z = 1);
   void noToneDelay();
};

#endif