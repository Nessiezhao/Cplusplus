#include <iostream>
class Date
{
public:
    Date()
    {}
    Date(int year,int month,int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
private:
    int _year;
    int _month;
    int _day;
};
void TestDate1()
{
    Date d1;
    Date d2(2015,1,1);
    Date d3;
}
int main()
{
    TestDate1();
    return 0;
}
//class Person
//{
//public:
//    void Display()
//    {
//        std::cout<<_name<<"-"<<_sex<<"-"<<_age<<std::endl;
//    }
//public:
//    const char* _name;
//    const char* _sex;
//    int _age;
//};
//
//void Test()
//{
//    Person p;
//    p._name = "Jack";
//    p._age = 10;
//    p._sex = "男";
//    p.Display();
//}
//
//int main()
//{
//    Test();
//    return 0;
//}
