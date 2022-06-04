

#ifndef PICOESPTIME_H
#define PICOESPTIME_H

#include <Arduino.h>

class PicoEspTime {
public:
    void read();
    String getTime(String format);
    void adjust(long epoch);
    void adjust(uint8_t _hour, uint8_t _minute, uint8_t _second, uint16_t _year, uint8_t _month, uint8_t _day);

    uint8_t second;
    uint8_t minute;
    uint8_t hour;
    uint8_t dayOfWeek;
    uint8_t dayOfMonth;
    uint8_t month;
    uint16_t year;
    long getEpoch();
};

#endif
