# BinaryClock
 Binary clock using LEDs

Parts used:
1. ESP8266 ESP-12E board
2. WS2812B Black 60LED + IP30 not waterproof + 1m (12mm LED spacing and 10mm strip width) [24 LEDs needed in 4 strips of 6 LEDs]
3. Four tact switches (push buttons)
4. Resistor
5. Capacitor
6. Barrel power adapter
7. 5x7 glass plate

Wiring on ESP-12E:
PIN_BUTTON_HOUR 14      //Set to GPIO PIN 14 
PIN_BUTTON_MIN 12       //Set to GPIO PIN 12 
PIN_BUTTON_SEC 13       //Set to GPIO PIN 13
PIN_BUTTON_DST 5        //Set to GPIO PIN 5

Settings:
#define NIGHT_MODE        1     //Set night mode where 0 is off and 1 is on (Night mode turns the clock off at night)
#define WEEKEND_MODE      0     //Set weekend mode where 0 is off and 1 is on (Weekend mode turns the clock off on the weekends)
#define NIGHT_OFF_TIME    22    //Time that clock turns off when night mode is active
#define NIGHT_ON_TIME     7     //Time that clock turns on when night mode is active
#define MILITARY_MODE     0     //Set 24HR mode where hour is shown as 1-23 rather than 1-12 where 0 = 1-12 mode and 1 = 1-23 mode

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
