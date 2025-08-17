Binary clock using LEDs

FINAL UPDATE - WEB SERVER TO DEFINE WIFI CREDENTIALS, AUTOMATING DAYLIGHT SAVINGS TIME, AND CHANGING DST BUTTON TO ONLY HAVE DIMMING FUNCTION

Parts used:

    ESP8266 ESP-12E board
    WS2812B Black 60LED + IP30 not waterproof + 1m (12mm LED spacing and 10mm strip width) [24 LEDs needed in 4 strips of 6 LEDs]
    Four tact switches (push buttons)
    Through-Hole Resistor - 470 ohm 5% 1/4W
    4700uF 10v Electrolytic Capacitor
    3-pin JST SM Plug (plug into LEDs that came with one end of plug)
    Power adapter barrel jack to screw terminal
    5x7 glass plate (took mine from $1 picture frame on clearance)

Wiring on ESP-12E:

    Wire one side of hour push button to GPIO PIN 14 (D5) and the other side to GND
    Wire one side of minute push button to GPIO PIN 12 (D6) and the other side to GND
    Wire one side of second push botton to GPIO PIN 13 (D7) and the other side to GND
    Wire one side of DST push button to GPIO PIN 5 (D1) and the other side to GND
    Wire the LED data connection to the 470 ohm resistor and then to GPIO PIN 4 (D2)
    Wire power and ground lines from the barrel jack screw terminal to Vin and GND on the ESP-12E and wire the capacitor across the 5V and GND lines
    Wire power and ground lines from the barrel jack screw terminal to 5V and GND on the LED strip (LEDs are powered directly from the power supply and not by the ESP-12E)
    Cut the LED strips into four sections of 6 LEDs. Wire the 5V, GND and Data lines from section to section while paying attention to the data flow arrows on the strips. I placed the LED strips in the face plate and used that as the guide for how long to make each wire connecting one strip to the next.

NOTE: I used a three wire plug between the ESP-12E data and POWER lines to the LED such that I can disconnec the LEDs when connecting the ESP-12E to the computer USB port for programming.

Settings:

    #define NIGHT_MODE 1 //Set night mode where 0 is off and 1 is on (Night mode turns the clock off at night)
    #define WEEKEND_MODE 0 //Set weekend mode where 0 is off and 1 is on (Weekend mode turns the clock off on the weekends)
    #define NIGHT_OFF_TIME 22 //Time that clock turns off when night mode is active
    #define NIGHT_ON_TIME 7 //Time that clock turns on when night mode is active
    #define MILITARY_MODE 0 //Set 24HR mode where hour is shown as 1-23 rather than 1-12 where 0 = 1-12 mode and 1 = 1-23 mode
    #define DST 1 //DST adjustment toggle (set 0 if you don't want auto adjust, 1 if you do)

Wifi Settings:

    Now uses a web server to allow you to define the SSID and password of the wifi network to connect to. Connect to AutoConnectAP and web browser will open to let you define the SSID and password and then device will reboot using those credentials.

What the four buttons do:

    Brightness Button = press to adjust brightness
    HOUR Button = cycle through six colors of the hour LEDs
    MIN Button = cycle through six colors of the minute LEDs
    SEC Button = cycle through six colors of the second LEDs

Set timezone: //Your time zone int timezone = -8 * 3600; //UTC offset * 3600
