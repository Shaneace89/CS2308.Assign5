#include<iostream>
using namespace std;

#include "ProductInventory.h"


//Driver demo using Time and TimeList classes

int main() {
    
    //testing the Time class
    Time t1(1,30);
    Time t2(11,30);
    Time t3(11,35);
    

    if (t1.lessThan(t2))
        cout << "less than"<< endl;
    else
        cout << "NOT less than"<< endl;
    if (t1.isEqual(t2))
        cout << "equals"<< endl;
    else
        cout << "NOT equals"<< endl;
    
    cout << endl;

    //testing the TimeList class:
    TimeList tl;
    tl.addTime(t1);
    tl.addTime(t2);
    tl.addTime(t3);
    cout << "The list of times: " << endl;
    tl.showTimes();
    
    return 0;
}
