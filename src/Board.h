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

#ifndef Board_h
#define Board_h
 
#if defined(__AVR_ATmega328P__)
	#define ARDUINO_BOARD_UNO
	#define ARDUINO_BOARD_FIO
	
#elif defined(__AVR_ATSAMD21G18A__)
	#define ARDUINO_BOARD_ZERO
	
#elif defined(__AVR_ATSAM3X8E__)
	#define ARDUINO_BOARD_DUE
	
#elif defined(__AVR_Atmega32U4__)
	#define ARDUINO_BOARD_YUN_16MHZ
	#define ARDUINO_BOARD_MICRO
	#define ARDUINO_BOARD_LEONARDO
	#define ARDUINO_BOARD_ESPLORA
	
#elif defined(_AVR_AR9331__)
	#define ARDUINO_BOARD_YUN_400MHZ
	
#elif defined(__AVR_ATmega16U4__)
	#define ARDUINO_BOARD_LEONARDO
	
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	#define ARDUINO_BOARD_MEGA_NORMAL
	#define ARDUINO_BOARD_MEGA_ADK
	
#elif defined(_AVR_ATmega328__)
	#define ARDUINO_BOARD_NANO
	#define ARDUINO_BOARD_PRO_NORMAL
	#define ARDUINO_BOARD_PRO_328
	#define ARDUINO_BOARD_ETHERNET
	
#elif defined(_AVR_ATmega168__)
	#define ARDUINO_BOARD_NANO
	#define ARDUINO_BOARD_UNO
	#define ARDUINO_BOARD_PRO_NORMAL
	
#elif defined(_AVR_ATmega168V__)
	#define ARDUINO_BOARD_LILYPAD_1
	
#elif defined(_AVR_ATmega328V__)
	#define ARDUINO_BOARD_LILYPAD_2
	
#elif defined(_AVR_ATTiny85__)
	#define ARDUINO_BOARD_TRINKET
	
#elif  defined(__AVR_ARCv2EM__) || (__CURIE_FACTORY_DATA_H_)
	#define ARDUINO_BOARD_INTEL_CURIE
	#define ARDUINO_BOARD_101
	
#else
	#define ARDUINO_BOARD_UNKNOWN

#endif

#endif