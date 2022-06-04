
#include "PicoEspTime.h"
#include <time.h>                       // time() ctime()
#include <sys/time.h>                   // struct timeval


time_t now;

void PicoEspTime::read() {
  struct timeval tv;
  gettimeofday(&tv, nullptr);
  now = time(nullptr);
  struct tm* p_tm = localtime(&now);
    second     = p_tm->tm_sec;
    minute     = p_tm->tm_min;
    hour       = p_tm->tm_hour;
    dayOfWeek  = p_tm->tm_wday;
    dayOfMonth = p_tm->tm_mday;
    month      = p_tm->tm_mon;
    year       = p_tm->tm_year+1900;
}

/*!
    get the time as an Arduino String object with the specified format
	https://www.cplusplus.com/reference/ctime/tm/
	https://www.cplusplus.com/reference/ctime/strftime/
*/

String PicoEspTime::getTime(String format){
  char s[128];
  char c[128];
  format.toCharArray(c, 127);
  struct tm* timeinfo = localtime(&now);
  strftime(s, 127, c, timeinfo);
  return String(s);
}
long PicoEspTime::getEpoch() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec;
}

void PicoEspTime::adjust(uint8_t _hour, uint8_t _minute, uint8_t _second, uint16_t _year, uint8_t _month, uint8_t _day) {
  struct tm t = {0};        // Initalize to all 0's
  t.tm_year = _year - 1900;    // This is year-1900, so 122 = 2022
  t.tm_mon = _month - 1;
  t.tm_mday = _day;
  t.tm_hour = _hour;
  t.tm_min = _minute;
  t.tm_sec = _second;
  time_t timeSinceEpoch = mktime(&t);
  adjust(timeSinceEpoch);
}

void PicoEspTime::adjust(long epoch) {
  struct timeval tv;
  tv.tv_sec = epoch;  // epoch time (seconds)
  tv.tv_usec = 0;    // microseconds
  settimeofday(&tv, NULL);
}