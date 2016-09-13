#include "Time.h"

class TimeList        //new data type
{
private:
   Time list[100];
   int size;
 
public:
   TimeList();
   void addTime(Time);
   void showTimes();
};

