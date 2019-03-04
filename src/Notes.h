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

class Notes {
 public:
    Notes();
    void advancedSettings(unsigned int beatBlinkDuration, unsigned int toneGap);
    void speakerSetup(uint8_t pin, unsigned int speed = 120);
    void toneLEDSetup(uint8_t beat, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t a, uint8_t b);
    void note(float frequency, uint8_t duration, bool dotted = false, bool offbeat = false);
 private:
    unsigned int _beatBlinkDuration = 64;
    unsigned int _toneGap = 16;
    uint8_t speakerPin;
    uint8_t beatLEDPin = 0;
    uint8_t cLED = 0;
    uint8_t dLED = 0;
    uint8_t eLED = 0;
    uint8_t fLED = 0;
    uint8_t gLED = 0;
    uint8_t aLED = 0;
    uint8_t bLED = 0;
    uint8_t toneLED;
    unsigned int bpm;
    float beatDuration;
    void warning(String msg);
    void beatLEDFunction();
    void repeatBeatLEDFunction(uint8_t repeats = 1);
    void noToneDelay();
};

#endif
