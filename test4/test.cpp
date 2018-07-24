#include <iostream>
class Date
{
public:
    Date(int x)
        :_day(x)
         ,_month(_day)
         ,_year(x)
    {
        std::cout<<"Date()"<<std::endl;
    }
    void Display()
    {
        std::cout<<"year:"<<_year<<std::endl;
        std::cout<<"month:"<<_month<<std::endl;
        std::cout<<"day:"<<_day<<std::endl;
    }
private:
    int _year;
    int _month;
    int _day;
};
void Test()
{
    Date d1(1);
    d1.Display();
}
int main()
{
    Test();
    return 0;
}
//class Time
//{
//public:
////    Time()
////    {
////        std::cout<<"Time()"<<std::endl;
////        _hour = 0;
////        _minute = 0;
////        _second = 0;
////    }
//    Time(const Time& t)
//    {
//        std::cout<<"Time(const Time& t)"<<std::endl;
//        _hour = t._hour;
//        _minute = t._minute;
//        _second = t._second;
//    }
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//class Date
//{
//public:
//    Date(int year,int month,int day,const Time& t)
//    {
//        std::cout<<"Date()--非初始化列表"<<std::endl;
//        _year = year;
//        _month = month;
//        _day = day;
//        _t = t;
//    }
////    Date(int year,int month,int day,const Time& t)
////        :_year(year)
////         ,_month(month)
////         ,_day(day)
////         ,_t(t)
////    {
////        std::cout<<"Date()--初始化列表"<<std::endl;
////    }
////
//private:
//    int _year;
//    int _month;
//    int _day;
// 
////    const int _testConst;
////    int& _testReference;
//    Time _t;
//};
//void Test()
//{
////    Time t1;
////    Date d1(2015,4,29,t1);
//}
//
//int main()
//{
//    Test();
//    return 0;
//}
