int g=396;
int a=440;
int b=495;
int hc=528;
int hd=594;
int he=660;

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
	//Turns on the tone LEDs
	n.toneLEDState();
}

void loop()
{
  //Plays the song
  n.note(g,4);
  n.note(a,4);
  n.note(b,4);
  n.note(hc,4);
  
  n.note(hd,2);
  n.note(hd,2);

  n.note(he,4);
  n.note(he,4);
  n.note(he,4);
  n.note(he,4);

  n.note(hd,1);

  n.note(he,4);
  n.note(he,4);
  n.note(he,4);
  n.note(he,4);

  n.note(hd,1);

  n.note(hc,4);
  n.note(hc,4);
  n.note(hc,4);
  n.note(hc,4);

  n.note(b,2);
  n.note(b,2);

  n.note(a,4);
  n.note(a,4);
  n.note(a,4);
  n.note(a,4);

  n.note(g,1);
}

