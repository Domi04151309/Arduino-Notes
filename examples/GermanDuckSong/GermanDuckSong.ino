int g=396;
int a=440;
int b=495;
int hc=528;
int hd=594;
int he=660;

//Includes the library
#include <Notes.h>

//Initializes an object of the class
Notes n;

void setup()
{
  //Starts the serial monitor for debugging
  Serial.begin(9600);
  //Sets the speakerPin to 3 and the beats per minute to 120
  n.speakerSetup(3,120);
  //Sets the beatLED to port 6 and the toneLEDs to the pins 7, 8, 9, 10, 11, 12 and 13
  n.toneLEDSetup(6,7,8,9,10,11,12,13);
}

void loop()
{
  //Plays the song
  n.note(g,4,false,false);
  n.note(a,4,false,false);
  n.note(b,4,false,false);
  n.note(hc,4,false,false);
  
  n.note(hd,2,false,false);
  n.note(hd,2,false,false);

  n.note(he,4,false,false);
  n.note(he,4,false,false);
  n.note(he,4,false,false);
  n.note(he,4,false,false);

  n.note(hd,1,false,false);

  n.note(he,4,false,false);
  n.note(he,4,false,false);
  n.note(he,4,false,false);
  n.note(he,4,false,false);

  n.note(hd,1,false,false);

  n.note(hc,4,false,false);
  n.note(hc,4,false,false);
  n.note(hc,4,false,false);
  n.note(hc,4,false,false);

  n.note(b,2,false,false);
  n.note(b,2,false,false);

  n.note(a,4,false,false);
  n.note(a,4,false,false);
  n.note(a,4,false,false);
  n.note(a,4,false,false);

  n.note(g,1,false,false);
}

