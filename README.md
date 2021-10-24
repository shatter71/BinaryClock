# BinaryClock
 Binary clock using LEDs

VERSION 2 IN PRODUCTION - AUTOMATING DAYLIGHT SAVINGS TIME AND CHANGING DST BUTTON TO ONLY HAVE DIMMING FUNCTION

Parts used:
1. ESP8266 ESP-12E board
2. WS2812B Black 60LED + IP30 not waterproof + 1m (12mm LED spacing and 10mm strip width) [24 LEDs needed in 4 strips of 6 LEDs]
3. Four tact switches (push buttons)
4. Through-Hole Resistor - 470 ohm 5% 1/4W
5. 4700uF 10v Electrolytic Capacitor
6. 3-pin JST SM Plug (plug into LEDs that came with one end of plug)
7. Power adapter barrel jack to screw terminal 
8. 5x7 glass plate (took mine from $1 picture frame on clearance)

Wiring on ESP-12E:
1. Wire one side of hour push button to GPIO PIN 14 (D5) and the other side to GND
2. Wire one side of minute push button to GPIO PIN 12 (D6) and the other side to GND
3. Wire one side of second push botton to GPIO PIN 13 (D7) and the other side to GND
4. Wire one side of DST push button to GPIO PIN 5 (D1) and the other side to GND 
5. Wire the LED data connection to the 470 ohm resistor and then to GPIO PIN 4 (D2)
6. Wire power and ground lines from the barrel jack screw terminal to Vin and GND on the ESP-12E and wire the capacitor across the 5V and GND lines
7. Wire power and ground lines from the barrel jack screw terminal to 5V and GND on the LED strip (LEDs are powered directly from the power supply and not by the ESP-12E)
8. Cut the LED strips into four sections of 6 LEDs.  Wire the 5V, GND and Data lines from section to section while paying attention to the data flow arrows on the strips.  I placed the LED strips in the face plate and used that as the guide for how long to make each wire connecting one strip to the next.

NOTE: I used a three wire plug between the ESP-12E data and POWER lines to the LED such that I can disconnec the LEDs when connecting the ESP-12E to the computer USB port for programming.

Settings:
1. #define NIGHT_MODE        1     //Set night mode where 0 is off and 1 is on (Night mode turns the clock off at night)
2. #define WEEKEND_MODE      0     //Set weekend mode where 0 is off and 1 is on (Weekend mode turns the clock off on the weekends)
3. #define NIGHT_OFF_TIME    22    //Time that clock turns off when night mode is active
4. #define NIGHT_ON_TIME     7     //Time that clock turns on when night mode is active
5. #define MILITARY_MODE     0     //Set 24HR mode where hour is shown as 1-23 rather than 1-12 where 0 = 1-12 mode and 1 = 1-23 mode
6. #define DST             1       //DST adjustment toggle (set 0 if you don't want auto adjust, 1 if you do)

Wifi Settings:
1. Set SSID to your wifi network name
2. Set PASSWORD to your wifi network password

What the four buttons do:
1. DST Button (DUAL MODE) = (1) press to adjust brightness and (2) hold for 5 seconds to adjust hour forward and back by one hour for daylight savings time.  Brightness can only be adjusted every 7 seconds to make the dual mode work.  When holding down for 5 seconds to adjust DST, the brightness will be adjusted once but will adjust back to the prior setting when the DST is changed so don't worry if LEDs go off, they'll come back on when DST adjustment triggers.
2. HOUR Button = cycle through six colors of the hour LEDs
3. MIN Button = cycle through six colors of the minute LEDs
4. SEC Button = cycle through six colors of the second LEDs

Set timezone:
//Your time zone
int timezone = -8 * 3600; //UTC offset * 3600
