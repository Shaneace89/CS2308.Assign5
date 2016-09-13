#include <iomanip>
#include <sstream>
using namespace std;

#include "Time.h"


// class function implementations

Time::Time() {
    hour = 12;
    minute = 0;
}

Time::Time(int hr) {
    hour = hr;
    minute = 0;
}

Time::Time(int hr, int min) {
    hour = hr;
    minute = min;
}

void Time::setHour(int hr) {
    hour = hr;           // hour is a member var
}
void Time::setMinute(int min) {
    minute = min;        // minute is a member var
}
int Time::getHour() const {
    return hour;
}
int Time::getMinute() const {
    return minute;
}

void Time::addHour() {  // a private member func
    if (hour == 12)
        hour = 1;
    else
        hour++;
}

void Time::addMinute()
{
    if (minute == 59) {
        minute = 0;
        addHour();   // call to private member func
    } else
        minute++;
}

string Time::display() const {
    // returns time in string formatted to hh:mm
    ostringstream sout;
    sout.fill('0');
    sout << hour << ":" << setw(2) << minute;
    return sout.str();
}

bool Time::isEqual (Time other) {
    return (hour==other.hour && minute==other.minute);
}

bool Time::lessThan (Time other) {
    if (hour == other.hour)
        return (minute < other.minute);
    return ( hour < other.hour);
}
