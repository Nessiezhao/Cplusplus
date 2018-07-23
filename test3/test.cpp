#include <iostream>

class Date
{
public:
    Date()//无参构造函数
    {}
    
    Date(int year,int month,int day)//带参构造函数
    {
        _year = year;
        _month = month;
        _day = day;
    }

//    Date(int year = 2000,int month = 1,int day = 1)//缺省参数的构造函数
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }

    Date(int year,int month = 1)//半缺省参数的构造函数
    {
        _year = year;
        _month = month;
        _day = 1;
    }

    //拷贝构造函数
    Date(const Date& d)//在类的成员函数中可以直接访问同类对象的私有/保护成员
        //C++的访问限定符是以类为单位的，也就是说在这个单位内的成员可以互相访问
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    //析构函数
    ~Date()
    {}

    //赋值操作符的重载
    Date& operator=(const Date&d)
    {
        if(this != &d)
        {
            this->_year = d._year;
            this->_month = d._month;
            this->_day = d._day;
        }
        return *this;
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
