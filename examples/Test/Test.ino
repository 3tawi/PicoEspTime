// - Lien vidéo: https://youtu.be/g5hJh01psXk
// - Time Library: https://github.com/3tawi/PicoEspTime
// - Getting Started Raspberry Pi Pico : https://youtu.be/KiM6-Hmxf3s
// - Find All "Great Projects" Videos : https://www.youtube.com/c/GreatProjects

#include <PicoEspTime.h>

PicoEspTime rtc;

uint32_t lastTime; 

void setup() {
  Serial.begin(115200);
// rtc.adjust(1, 28, 21, 2022, 6, 3); // 01:26:21 03 Jun 2022
// rtc.adjust(1654219721); // Friday, June 03 2022 01:28:41
}
void loop() {
   if(millis() - lastTime >= 1000) {
    rtc.read(); 
    PrintTime();
    lastTime = millis();
    }
}
void PrintTime()
{ 
  Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));   // (String) returns time with specified format   
// formating options  https://www.cplusplus.com/reference/ctime/strftime/

      Serial.println(""); 
      Serial.println(rtc.getEpoch());         //  (long)    1647216003
      Serial.println(rtc.second);             //  (int)     30    (0-59)
      Serial.println(rtc.minute);             //  (int)     58    (0-59)
      Serial.println(rtc.hour);               //  (int)     0     (0-23)
      Serial.println(rtc.dayOfMonth);         //  (int)     14    (1-31)
      Serial.println(rtc.month);              //  (int)     3     (1-12)
      Serial.println(rtc.year);               //  (int)     2022
      Serial.println(rtc.dayOfWeek);          //  (int)     1     (0-6)
      Serial.println(""); 
} 
