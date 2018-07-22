#include <iostream>
class Person
{
public:
    void Display()
    {
        std::cout<<_name<<"-"<<_sex<<"-"<<_age<<std::endl;
    }
public:
    char* _name;
    char* _sex;
    int _age;
};
