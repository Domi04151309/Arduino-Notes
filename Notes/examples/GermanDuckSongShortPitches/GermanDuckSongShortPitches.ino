//Includes the library
#include <Notes.h>

//Sets the beatLEDtime to 64 and the noToneDelay to 16
Notes n(64,16);

void setup()
{
  //Starts the serial monitor for debugging
  Serial.begin(9600);
  //Sets the speakerPort to 3 and the beats per minute to 120
  n.speakerSetup(3);
  //Sets the beatLED to port 6 and the toneLEDs to the ports 7, 8, 9, 10, 11, 12 and 13
  n.toneLEDSetup(6,7,8,9,10,11,12,13);
}

void loop()
{
  //Plays the song
  n.note(NOTE_G4,4);
  n.note(NOTE_A4,4);
  n.note(NOTE_B4,4);
  n.note(NOTE_C5,4);
  
  n.note(NOTE_D5,2);
  n.note(NOTE_D5,2);

  n.note(NOTE_E5,4);
  n.note(NOTE_E5,4);
  n.note(NOTE_E5,4);
  n.note(NOTE_E5,4);

  n.note(NOTE_D5,1);

  n.note(NOTE_E5,4);
  n.note(NOTE_E5,4);
  n.note(NOTE_E5,4);
  n.note(NOTE_E5,4);

  n.note(NOTE_D5,1);

  n.note(NOTE_C5,4);
  n.note(NOTE_C5,4);
  n.note(NOTE_C5,4);
  n.note(NOTE_C5,4);

  n.note(NOTE_B4,2);
  n.note(NOTE_B4,2);

  n.note(NOTE_A4,4);
  n.note(NOTE_A4,4);
  n.note(NOTE_A4,4);
  n.note(NOTE_A4,4);

  n.note(NOTE_G4,1);
}

