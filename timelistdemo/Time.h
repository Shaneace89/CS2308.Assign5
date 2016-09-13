#include <string>
using namespace std;

// models a 12 hour clock
class Time        //new data type
{
private:
    int hour;
    int minute;
    void addHour();
    
public:
    Time();
    Time(int);
    Time(int,int);
    void setHour(int);
    void setMinute(int);
    int getHour() const;
    int getMinute() const;

    bool isEqual (Time);
    bool lessThan (Time);
    
    string display() const;
    void addMinute();
};

