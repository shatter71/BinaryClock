#include <ESP8266WiFi.h>
#include <time.h>
#include "FastLED.h"

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER RGB
#define NUM_LEDS    36
#define BRIGHTNESS  255
#define NIGHT_MODE        1     //Set night mode where 0 is off and 1 is on (Night mode turns the clock off at night)
#define WEEKEND_MODE      0     //Set weekend mode where 0 is off and 1 is on (Weekend mode turns the clock off on the weekends)
#define NIGHT_OFF_TIME    22    //Time that clock turns off when night mode is active
#define NIGHT_ON_TIME     7     //Time that clock turns on when night mode is active
#define MILITARY_MODE         0     //Set 24HR mode where hour is shown as 1-23 rather than 1-12 where 0 = 1-12 mode and 1 = 1-23 mode
int NIGHT_CHK = 0;              //Night model toggle
int WEEKEND_CHK = 0;            //Weekend mode toggle

CRGB leds[NUM_LEDS];

//Digits color values in RGB
int hrr=255;
int hrg=0;
int hrb=0;
int mnr=0;
int mng=255;
int mnb=0;
int scr=0;
int scg=0;
int scb=255;
int r=255;
int g=255;
int b=255;

const char* ESP_HOST_NAME = "esp-" + ESP.getFlashChipId();
//Your Wifi info
const char* ssid    = "SSID";
const char* password = "password";

//Your time zone
int timezone = 7 * 3600; //UTC offset * 3600
int dst = 0;
   
WiFiClient wifiClient;

void connectWifi() 
{
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  delay(500);
  connectWifi();
  Serial.println();
  Serial.println("\n\nNext Loop-Step: " + String(millis()) + ":");
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);
  FastLED.setBrightness(BRIGHTNESS);
}


void loop()
{
    time_t now = time(nullptr);
    struct tm* p_tm = localtime(&now);
    Serial.print("-------------------------------------------------\n");
    Serial.print("Date & Time : ");
    Serial.print(p_tm->tm_mday);
    Serial.print("/");
    Serial.print(p_tm->tm_mon + 1);
    Serial.print("/");
    Serial.print(p_tm->tm_year + 1900);
    Serial.print(" ");
    int hour=p_tm->tm_hour;
    int minute=p_tm->tm_min;
    int second=p_tm->tm_sec;
    int weekday=p_tm->tm_wday; //day of the week, range 0 to 6

    if (NIGHT_MODE==1)
    {
      if (hour==NIGHT_OFF_TIME && NIGHT_CHK==0)
      {
        NIGHT_CHK = 1;
      }
      if (hour==NIGHT_ON_TIME && NIGHT_CHK==1)
      {
        NIGHT_CHK = 0;
      }
    }

    if (WEEKEND_MODE == 1)
    {
      if (weekday == 0 || weekday == 6)
      {
        WEEKEND_CHK = 1;
      }
      if (weekday != 0 && weekday != 6)
      {
        WEEKEND_CHK = 0;
      }
    }

    if (NIGHT_CHK == 1 || WEEKEND_CHK == 1)
    {
      FastLED.clear();  // clear all pixel data
      FastLED.show();
    }

    if (NIGHT_CHK == 0 && WEEKEND_CHK == 0)
    {
    if (MILITARY_MODE == 0)
    {
      if(hour>12)
      {
        hour=hour-12;
      }
    }
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
//    Serial.println(p_tm->tm_sec);
//    pride();
    if(hour==1)
    {
      hour1();
    }
    if(hour==2)
    {
      hour2();
    }
    if(hour==3)
    {
      hour3();
    }
    if(hour==4)
    {
      hour4();
    }
    if(hour==5)
    {
      hour5();
    }
    if(hour==6)
    {
      hour6();
    }
    if(hour==7)
    {
      hour7();
    }
    if(hour==8)
    {
      hour8();
    }
    if(hour==9)
    {
      hour9();
    }
    if(hour==10)
    {
      hour10();
    }
    if(hour==11)
    {
      hour11();
    }
    if(hour==12)
    {
      hour12();
    }
    if (MILITARY_MODE == 1)
    {
        if(hour==12)
      {
        hour12();
      }
        if(hour==13)
      {
        hour13();
      }
        if(hour==14)
      {
        hour14();
      }
        if(hour==15)
      {
        hour15();
      }
        if(hour==16)
      {
        hour16();
      }
        if(hour==17)
      {
        hour17();
      }
        if(hour==18)
      {
        hour18();
      }
        if(hour==19)
      {
        hour19();
      }
        if(hour==20)
      {
        hour20();
      }
        if(hour==21)
      {
        hour21();
      }
        if(hour==22)
      {
        hour22();
      }
        if(hour==23)
      {
        hour23();
      }
        if(hour==0 || hour==24)
      {
        hour0();
      }
    }

    if(minute==0)
    {
      min0();
    }
    if(minute==1)
    {
      min1();
    }
    if(minute==2)
    {
      min2();
    }
    if(minute==3)
    {
      min3();
    }
    if(minute==4)
    {
      min4();
    }
    if(minute==5)
    {
      min5();
    }
    if(minute==6)
    {
      min6();
    }
    if(minute==7)
    {
      min7();
    }
    if(minute==8)
    {
      min8();
    }
    if(minute==9)
    {
      min9();
    }
    if(minute==10)
    {
      min10();
    }
    if(minute==11)
    {
      min11();
    }
    if(minute==12)
    {
      min12();
    }
    if(minute==13)
    {
      min13();
    }
    if(minute==14)
    {
      min14();
    }
    if(minute==15)
    {
      min15();
    }
    if(minute==16)
    {
      min16();
    }
    if(minute==17)
    {
      min17();
    }
    if(minute==18)
    {
      min18();
    }
    if(minute==19)
    {
      min19();
    }
    if(minute==20)
    {
      min20();
    }
    if(minute==21)
    {
      min21();
    }
    if(minute==22)
    {
      min22();
    }
    if(minute==23)
    {
      min23();
    }
    if(minute==24)
    {
      min24();
    }
    if(minute==25)
    {
      min25();
    }
    if(minute==26)
    {
      min26();
    }
    if(minute==27)
    {
      min27();
    }
    if(minute==28)
    {
      min28();
    }
    if(minute==29)
    {
      min29();
    }
    if(minute==30)
    {
      min30();
    }
    if(minute==31)
    {
      min31();
    }
    if(minute==32)
    {
      min32();
    }
    if(minute==33)
    {
      min33();
    }
    if(minute==34)
    {
      min34();
    }
    if(minute==35)
    {
      min35();
    }
    if(minute==36)
    {
      min36();
    }
    if(minute==37)
    {
      min37();
    }
    if(minute==38)
    {
      min38();
    }
    if(minute==39)
    {
      min39();
    }
    if(minute==40)
    {
      min40();
    }
    if(minute==41)
    {
      min41();
    }
    if(minute==42)
    {
      min42();
    }
    if(minute==43)
    {
      min43();
    }
    if(minute==44)
    {
      min44();
    }
    if(minute==45)
    {
      min45();
    }
    if(minute==46)
    {
      min46();
    }
    if(minute==47)
    {
      min47();
    }
    if(minute==48)
    {
      min48();
    }
    if(minute==49)
    {
      min49();
    }
    if(minute==50)
    {
      min50();
    }
    if(minute==51)
    {
      min51();
    }
    if(minute==52)
    {
      min52();
    }
    if(minute==53)
    {
      min53();
    }
    if(minute==54)
    {
      min54();
    }
    if(minute==55)
    {
      min55();
    }
    if(minute==56)
    {
      min56();
    }
    if(minute==57)
    {
      min57();
    }
    if(minute==58)
    {
      min58();
    }
    if(minute==59)
    {
      min59();
    }
    if(minute==60)
    {
      min0();
    }

    if(second==0)
    {
      sec0();
    }
    if(second==1)
    {
      sec1();
    }
    if(second==2)
    {
      sec2();
    }
    if(second==3)
    {
      sec3();
    }
    if(second==4)
    {
      sec4();
    }
    if(second==5)
    {
      sec5();
    }
    if(second==6)
    {
      sec6();
    }
    if(second==7)
    {
      sec7();
    }
    if(second==8)
    {
      sec8();
    }
    if(second==9)
    {
      sec9();
    }
    if(second==10)
    {
      sec10();
    }
    if(second==11)
    {
      sec11();
    }
    if(second==12)
    {
      sec12();
    }
    if(second==13)
    {
      sec13();
    }
    if(second==14)
    {
      sec14();
    }
    if(second==15)
    {
      sec15();
    }
    if(second==16)
    {
      sec16();
    }
    if(second==17)
    {
      sec17();
    }
    if(second==18)
    {
      sec18();
    }
    if(second==19)
    {
      sec19();
    }
    if(second==20)
    {
      sec20();
    }
    if(second==21)
    {
      sec21();
    }
    if(second==22)
    {
      sec22();
    }
    if(second==23)
    {
      sec23();
    }
    if(second==24)
    {
      sec24();
    }
    if(second==25)
    {
      sec25();
    }
    if(second==26)
    {
      sec26();
    }
    if(second==27)
    {
      sec27();
    }
    if(second==28)
    {
      sec28();
    }
    if(second==29)
    {
      sec29();
    }
    if(second==30)
    {
      sec30();
    }
    if(second==31)
    {
      sec31();
    }
    if(second==32)
    {
      sec32();
    }
    if(second==33)
    {
      sec33();
    }
    if(second==34)
    {
      sec34();
    }
    if(second==35)
    {
      sec35();
    }
    if(second==36)
    {
      sec36();
    }
    if(second==37)
    {
      sec37();
    }
    if(second==38)
    {
      sec38();
    }
    if(second==39)
    {
      sec39();
    }
    if(second==40)
    {
      sec40();
    }
    if(second==41)
    {
      sec41();
    }
    if(second==42)
    {
      sec42();
    }
    if(second==43)
    {
      sec43();
    }
    if(second==44)
    {
      sec44();
    }
    if(second==45)
    {
      sec45();
    }
    if(second==46)
    {
      sec46();
    }
    if(second==47)
    {
      sec47();
    }
    if(second==48)
    {
      sec48();
    }
    if(second==49)
    {
      sec49();
    }
    if(second==50)
    {
      sec50();
    }
    if(second==51)
    {
      sec51();
    }
    if(second==52)
    {
      sec52();
    }
    if(second==53)
    {
      sec53();
    }
    if(second==54)
    {
      sec54();
    }
    if(second==55)
    {
      sec55();
    }
    if(second==56)
    {
      sec56();
    }
    if(second==57)
    {
      sec57();
    }
    if(second==58)
    {
      sec58();
    }
    if(second==59)
    {
      sec59();
    }
    if(second==60)
    {
      sec0();
    }
    
    FastLED.show();
    FastLED.clear();
    FastLED.show();  
    }
}

//void pride() 
//{
//  static uint16_t sPseudotime = 0;
//  static uint16_t sLastMillis = 0;
//  static uint16_t sHue16 = 0;
// 
//  uint8_t sat8 = beatsin88( 87, 220, 250);
//  uint8_t brightdepth = beatsin88( 341, 96, 224);
//  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
//  uint8_t msmultiplier = beatsin88(147, 23, 60);
//
//  uint16_t hue16 = sHue16;//gHue * 256;
//  uint16_t hueinc16 = beatsin88(113, 1, 3000);
//  
//  uint16_t ms = millis();
//  uint16_t deltams = ms - sLastMillis ;
//  sLastMillis  = ms;
//  sPseudotime += deltams * msmultiplier;
//  sHue16 += deltams * beatsin88( 400, 5,9);
//  uint16_t brightnesstheta16 = sPseudotime;
//  
//  for( uint16_t i = 0 ; i < NUM_LEDS; i++) {
//    hue16 += hueinc16;
//    uint8_t hue8 = hue16 / 256;
//
//    brightnesstheta16  += brightnessthetainc16;
//    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;
//
//    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
//    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
//    bri8 += (255 - brightdepth);
//    
//    CRGB newcolor = CHSV( hue8, sat8, bri8);
//    
//    uint16_t pixelnumber = i;
//    pixelnumber = (NUM_LEDS-1) - pixelnumber;
//    
//    nblend( leds[pixelnumber], newcolor, 64);
//  }
//}

/*------------------------------------Hour LEDs------------------------------------*/
void hour0()
{
    //leds[5] = CRGB(hrr,hrg,hrb);
}
void hour1()
{
    leds[5] = CRGB(hrr,hrg,hrb);
}
void hour2()
{
    leds[8] = CRGB(hrr,hrg,hrb);
}
void hour3()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[8] = CRGB(hrr,hrg,hrb);
}
void hour4()
{
    leds[17] = CRGB(hrr,hrg,hrb);
}
void hour5()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[17] = CRGB(hrr,hrg,hrb);
}
void hour6()
{
    leds[8] = CRGB(hrr,hrg,hrb);
    leds[17] = CRGB(hrr,hrg,hrb);
}
void hour7()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[8] = CRGB(hrr,hrg,hrb);
    leds[17] = CRGB(hrr,hrg,hrb);
}
void hour8()
{
    leds[20] = CRGB(hrr,hrg,hrb);
}
void hour9()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[20] = CRGB(hrr,hrg,hrb);
}
void hour10()
{
    leds[6] = CRGB(hrr,hrg,hrb);
}
void hour11()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[6] = CRGB(hrr,hrg,hrb);
}
void hour12()
{
    leds[6] = CRGB(hrr,hrg,hrb);
    leds[8] = CRGB(hrr,hrg,hrb);
}
void hour13()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[6] = CRGB(hrr,hrg,hrb);
    leds[8] = CRGB(hrr,hrg,hrb);
}
void hour14()
{
    leds[6] = CRGB(hrr,hrg,hrb);
    leds[17] = CRGB(hrr,hrg,hrb);
}
void hour15()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[6] = CRGB(hrr,hrg,hrb);
    leds[17] = CRGB(hrr,hrg,hrb);
}
void hour16()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[8] = CRGB(hrr,hrg,hrb);
    leds[17] = CRGB(hrr,hrg,hrb);
}
void hour17()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[6] = CRGB(hrr,hrg,hrb);
    leds[8] = CRGB(hrr,hrg,hrb);
    leds[17] = CRGB(hrr,hrg,hrb);
}
void hour18()
{
    leds[6] = CRGB(hrr,hrg,hrb);
    leds[20] = CRGB(hrr,hrg,hrb);
}
void hour19()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[6] = CRGB(hrr,hrg,hrb);
    leds[20] = CRGB(hrr,hrg,hrb);
}
void hour20()
{
    leds[7] = CRGB(hrr,hrg,hrb);
}
void hour21()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[7] = CRGB(hrr,hrg,hrb);
}
void hour22()
{
    leds[7] = CRGB(hrr,hrg,hrb);
    leds[8] = CRGB(hrr,hrg,hrb);
}
void hour23()
{
    leds[5] = CRGB(hrr,hrg,hrb);
    leds[7] = CRGB(hrr,hrg,hrb);
    leds[8] = CRGB(hrr,hrg,hrb);
}

/*----------------------------Minutes LEDs----------------------------*/
void min0()
{
    //leds[62] = CRGB(mnr,mng,mnb);
}
void min1()
{
    leds[3] = CRGB(mnr,mng,mnb);
}
void min2()
{
    leds[10] = CRGB(mnr,mng,mnb);
}
void min3()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
}
void min4()
{
    leds[15] = CRGB(mnr,mng,mnb);
}
void min5()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min6()
{
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min7()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min8()
{
    leds[22] = CRGB(mnr,mng,mnb);
}
void min9()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min10()
{
    leds[4] = CRGB(mnr,mng,mnb);
}
void min11()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
}
void min12()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
}
void min13()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
}
void min14()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min15()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min16()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min17()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min18()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min19()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min20()
{
    leds[9] = CRGB(mnr,mng,mnb);
}
void min21()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
}
void min22()
{
    leds[9] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
}
void min23()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min24()
{
    leds[9] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min25()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min26()
{
    leds[9] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min27()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min28()
{
    leds[9] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min29()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min30()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
}
void min31()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
}
void min32()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
}
void min33()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
}
void min34()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min35()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min36()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min37()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
}
void min38()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min39()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[9] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min40()
{
    leds[16] = CRGB(mnr,mng,mnb);
}
void min41()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min42()
{
    leds[10] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min43()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min44()
{
    leds[15] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min45()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min46()
{
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min47()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min48()
{
    leds[16] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min49()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min50()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min51()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min52()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min53()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min54()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min55()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min56()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min57()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[10] = CRGB(mnr,mng,mnb);
    leds[15] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
}
void min58()
{
    leds[4] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}
void min59()
{
    leds[3] = CRGB(mnr,mng,mnb);
    leds[4] = CRGB(mnr,mng,mnb);
    leds[16] = CRGB(mnr,mng,mnb);
    leds[22] = CRGB(mnr,mng,mnb);
}

/*----------------------------Seconds LEDs----------------------------*/
void sec0()
{
//    leds[62] = CRGB(scr,scg,scb);
}
void sec1()
{
    leds[1] = CRGB(scr,scg,scb);
}
void sec2()
{
    leds[12] = CRGB(scr,scg,scb);
}
void sec3()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
}
void sec4()
{
    leds[13] = CRGB(scr,scg,scb);
}
void sec5()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec6()
{
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec7()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec8()
{
    leds[24] = CRGB(scr,scg,scb);
}
void sec9()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec10()
{
    leds[2] = CRGB(scr,scg,scb);
}
void sec11()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
}
void sec12()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
}
void sec13()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
}
void sec14()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec15()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec16()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec17()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec18()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec19()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec20()
{
    leds[11] = CRGB(scr,scg,scb);
}
void sec21()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
}
void sec22()
{
    leds[11] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
}
void sec23()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
}
void sec24()
{
    leds[11] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec25()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec26()
{
    leds[11] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec27()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec28()
{
    leds[11] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec29()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec30()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
}
void sec31()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
}
void sec32()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
}
void sec33()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
}
void sec34()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec35()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec36()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec37()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
}
void sec38()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec39()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[11] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec40()
{
    leds[14] = CRGB(scr,scg,scb);
}
void sec41()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec42()
{
    leds[12] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec43()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec44()
{
    leds[13] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec45()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec46()
{
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec47()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec48()
{
    leds[14] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec49()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec50()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec51()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec52()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec53()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec54()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec55()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec56()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec57()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[12] = CRGB(scr,scg,scb);
    leds[13] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
}
void sec58()
{
    leds[2] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
void sec59()
{
    leds[1] = CRGB(scr,scg,scb);
    leds[2] = CRGB(scr,scg,scb);
    leds[14] = CRGB(scr,scg,scb);
    leds[24] = CRGB(scr,scg,scb);
}
