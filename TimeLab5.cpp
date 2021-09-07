#include <iostream>
using namespace std;
 
class Time{
private:
    int hours;
    int minutes;
 
public:
    void setTime(int h,int m);
    void showTime();
    friend Time addTime(Time &obj1,Time &obj2);
};
 
void Time::setTime(int h,int m)
{
    hours = h;
    minutes = m;
}
 
void Time::showTime()
{
    cout << "It is " << hours << ":" << minutes << endl;
}
 
Time addTime(Time& obj1,Time& obj2){
    int min,hr;
	min = obj1.minutes + obj2.minutes;
	hr = obj1.hours + obj2.hours + (min / 60);
	hr = hr % 24;
	min = min % 60;
    
    Time res;
    res.setTime(hr,min);
    
    return res;
}
 
 
int main()
{
    Time t1,t2,t3;
    
	t1.setTime(5,45);
    t2.setTime(5,35);
    
    cout << "Time 1 : ";
    t1.showTime();
    
    cout << "Time 2 : ";
    t2.showTime();
    
    t3 = addTime(t1,t2);
    
    cout << "Sum of Time 1 and Time 2 : ";
	t3.showTime();
     
    return 0;
}