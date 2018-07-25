#include <iostream>
#include<assert.h>
class Date
{
public:
    Date(int year = 1900,int month = 1,int day = 1)
        :_year(year)
         ,_month(month)
         ,_day(day)
    {
        if(!IsInvalid(year,month,day))
        {
            assert(year<0);
            assert(month < 0 || month >12);
            assert(day <0 || day > GetMonthDay(year,month));
        }
    }
    Date(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    Date& operator=(const Date& d)
    {
        if(this != &d)
        {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        return *this;
    }
    ~Date()
    {

    }
    bool IsInvalid(int year,int month,int day)
    {
        if((year < 0) || (month < 0) || (month > 12) || (day < 0) || (day > GetMonthDay(year,month)))
           return false;
        return true;
    }
    bool isLeapYear(int year)
    {
        if((year%400 == 0) || ((year%4==0)&&(year%100 != 0)))
            return true;
        return false;
    }
    int GetMonthDay(int year,int month)
    {
        int day = 0;
        int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        day = days[month];
        if(month == 2) 
            day += isLeapYear(year);
        return day;
    }
    void Show()
    {
        std::cout<<_year<<"-"<<_month<<"-"<<_day<<std::endl;
    }
    bool operator==(const Date& d)
    {
        return ((_year == d._year)&&(_month == d._month)&&(_day == d._day));
    }
    bool operator!=(const Date& d)
    {
        return !(*this == d);
    }
    bool operator>=(const Date& d)
    {
        return !(*this < d);
    }
    bool operator<=(const Date& d)
    {
        return !(*this > d);
    }
    bool operator>(const Date& d)
    {
        if(_year >= d._year)
        {
            if(_month >= d._month)
            {
                if(_day > d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator<(const Date& d)
    {
        if(_year <= d._year)
        {
            if(_month <= d._month)
            {
                if(_day < d._day)
                {
                    return true;
                }
            }
        }
        return false;

    }
    Date operator+(int day)
    {
        if(day < 0)
        {
            return (*this - (0 - day));
        }
        Date tmp(*this) ;
        tmp._day += day;
        while(tmp._day < 1)
        {
            tmp._month--;
            if(tmp._month < 1)
            {
                tmp._year--;
                tmp._month = 12;
            }
            tmp._day += GetMonthDay(tmp._year,tmp._month-1);
         }
        return tmp;

    }
    Date& operator+=(int day)
    {
        *this = *this + day;
        return *this;
    }
    Date operator-(int day)
    {
        if(day < 0)
        {
            return (*this + (0 - day));
        }
        Date tmp(*this) ;
        tmp._day -= day;
        while(tmp._day > GetMonthDay(tmp._year,tmp._month))
        {
            tmp._month++;
            if(tmp._month > 12)
            {
                tmp._year++;
                tmp._month = 1;
            }
            tmp._day -= GetMonthDay(tmp._year,tmp._month);
         }
        return tmp;
    }
    Date& operator-=(int day)
    {
        *this = *this - day;
        return *this;
    }
    int operator-(const Date& d)
    {
        int flag = 1;
        Date max = *this;
        Date min = d;
        if(*this < d)
        {
            max = d;
            min = *this;
            flag = -1;
        }
        int count = 0;
        while(min != max)
        {
            ++min;
            count++;
        }
        return (count*flag);
    }
    Date& operator++()//前置++
    {
        _day++;
        if(_day > GetMonthDay(_year,_month))
        {
            _month++;
            if(_month > 13)
            {
                _year++;
                _month  = 1;
            }
            _day = 1;
        }
        return *this;
    }
    Date operator++(int)//后置++
    {
        Date tmp(*this);
        _day++;
        if(_day > GetMonthDay(_year,_month))
        {
            _month++;
            if(_month > 13)
            {
                _year++;
                _month = 1;
            }
            _day = 1;
        }
        return tmp;
    }
    Date& operator--()//前置--
    {
        _day--;
        if(_day < 1)
        {
            _month--;
            if(_month <  1)
            {
                _year--;
                _month  = 12;
            }
            _day = GetMonthDay(_year,_month);
        }
        return *this;
    }
    Date operator--(int)//后置--
    {
        Date tmp(*this);
        _day--;
        if(_day < 1)
        {
            _month--;
            if(_month <  1)
            {
                _year--;
                _month  = 12;
            }
            _day = GetMonthDay(_year,_month);
        }
        return tmp;
    }
private:
    int _year;
    int _month;
    int _day;
};

void Test1()
{
    Date d1;
    std::cout<<"d1"<<std::endl;
    d1.Show();
}
void Test2()
{
    Date d2(2018,7,25);
    std::cout<<"d2"<<std::endl;
    d2.Show();
    std::cout<<"给d2减10天"<<std::endl;
    d2.operator-=(10);
    d2.Show();
    std::cout<<"给d2减15天"<<std::endl;
    d2.operator-=(16);
    d2.Show();
}
int main()
{
    Test1();
    Test2();
    return 0;
}
