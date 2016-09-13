#include <iostream>
using namespace std;

#include "TimeList.h"


// class function implementations

TimeList::TimeList() {
    size = 0;
}

void TimeList::addTime(Time t) {
    if (size <100) {
        list[size] = t;  // assign/copy one object to another
        size++;
    }
}

void TimeList::showTimes() {
    for (int i=0; i<size; i++) {
        cout << list[i].display() << endl;
    }
}

