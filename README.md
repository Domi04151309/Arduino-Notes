# Arduino-Notes

## How to Install

1. Download the repository from GitHub
2. Unzip it
3. Copy the "Arduino-Notes-master" folder into your library folder
4. Open the Arduino IDE
5. Click on Sketch > Include Library > Notes
Done!

## Reference

| Type | Name | Description |
|----------|-------------|-------------|
| `class` | `Notes` | The main class of this library. |
| `void` | `advancedSettings(unsigned int beatBlinkDuration, unsigned int toneGap)` | Sets the duration the beat LED blinks and the gap between the tones. |
| `void` | `speakerSetup(uint8_t pin, unsigned int speed = 120)` | Sets the speed in beats per minute and the pin of the speaker. |
| `void` | `toneLEDSetup(uint8_t beat, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t a, uint8_t b)` | Sets the pins for the LEDs. |
| `void` | `note(float frequency, uint8_t duration, bool dotted = false, bool offbeat = false)` | Plays a sound with the applied settings. The duration has to be 1, 2, 4 or 8 for 1/1, 1/2, 1/4 and 1/8. |

_For the frequency you can also use keywords which you can find in Pitches.h_.
