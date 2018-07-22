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

void Test()
{
    Person p;
    p._name = "Jack";
    p._age = 10;
    p._sex = "男";
    p.Display();
}

int main()
{
    Test();
    return 0;
}
