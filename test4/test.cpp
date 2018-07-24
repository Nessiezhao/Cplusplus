#include <iostream>
class Time
{
public:
    Time()
    {
        std::cout<<"Time()"<<std::endl;
        _hour = 0;
        _minute = 0;
        _second = 0;
    }
    Time(const Time& t)
    {
        std::cout<<"Time(const Time& t)"<<std::endl;
        _hour = t._hour;
        _minute = t._minute;
        _second = t._second;
    }
private:
    int _hour;
    int _minute;
    int _second;
};

class Date
{
public:
    Date(int year,int month,int day,const Time& t)
    {
        std::cout<<"Date()--非初始化列表"<<std::endl;
        _year = year;
        _month = month;
        _day = day;
        _t = t;
    }
//    Date(int year,int month,int day,const Time& t)
//        :_year(year)
//         ,_month(month)
//         ,_day(day)
//         ,_t(t)
//    {
//        std::cout<<"Date()--初始化列表"<<std::endl;
//    }
//
private:
    int _year;
    int _month;
    int _day;
    const int _testConst;
    Time _t;
};
void Test()
{
    Time t1;
    Date d1(2015,4,29,t1);
}

int main()
{
    Test();
    return 0;
}
