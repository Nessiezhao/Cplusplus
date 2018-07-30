#include <iostream>
#include<string.h>
using namespace std;

//class String
//{
//public:
//    String(char* str="")
//    {
//        _str = new char(strlen(str) + 1);
//        strcpy(_str,str);
//        _pCount = new size_t(1);
//    }
//    String(const String& s)
//    {
//        _str = s._str;
//        _pCount = s._pCount;
//        ++(*_pCount);
//    }
//    String& operator=(const String& s)
//    {
//        //if(this!= &s)
//        if(_str != s._str)
//        {
//            if(--(*_pCount) == 0)
//            {
//                delete[] _str;
//                delete _pCount;
//            }
//            _str = s._str;
//            _pCount = s._pCount;
//            ++(*_pCount);
//        }
//    }
//    ~String()
//    {
//        if(--(*_pCount) == 0)
//        {
//            delete[] _str;
//            delete _pCount;
//        }
//    }
//    const char* c_str()
//    {
//        return _str;
//    }
//    void CopyOnWrite()
//    {
//        if(*_pCount > 1)
//        {
//            char* tmp = new char(strlen(_str)+1);
//            strcpy(tmp,_str);
//            --(*_pCount);
//
//            _str = tmp;
//            _pCount = new size_t(1);
//        }
//    }
//    char& operator[](size_t pos)
//    {
//        CopyOnWrite();
//        return _str[pos];
//    }
//    const char& operator[](size_t pos)const
//    {
//        return _str[pos];
//    }
//private:
//    char* _str;
//    size_t* _pCount;
//};

class String
{
public:
    String(char* str="")
        :_str(new char(strlen(str)+1))
    {
        strcpy(_str,str);
    }
    String(const String& s)
        :_str(new char(strlen(s._str)+1))
    {
        strcpy(_str,s._str);
    }
    //s1 = s3
    String& operator=(const String& s)
    {
        if(this != &s)
        {
            char* tmp = new char(strlen(s._str) + 1);
            strcpy(tmp,s._str);
            delete[] _str;
            _str = tmp;
        }
        return *this;
    }
    ~String()
    {
        delete[] _str;
        _str = NULL;
    }
    const char* c_str()
    {
        return _str;
    }
    const char& operator[](size_t pos)const
    {
        return _str[pos];
    }
    char& operator[](size_t pos)
    {
        if(GetCount() > 1 )
        {
            char* tmp = new char(strlen(_str)+1+4);
            strcpy(_str,tmp+4);
            --GetCount();
            _str = tmp+4;
            GetCount() = 1;
        }
        return _str[pos];
    }
    int& GetCount()
    {
        return *((int*)_str - 1);
    }
private:
    char* _str;
};

void Test()
{
    String s1("abcd");
    char* str1 = "abcd";
    cout<<sizeof(s1)<<endl;
    cout<<sizeof(str1)<<endl;
    String s2(s1);
    cout<<s1.c_str()<<endl;
    cout<<s2.c_str()<<endl;
    String s3("1234");
    s1 = s3;
    cout<<s1.c_str()<<endl;
    cout<<s3.c_str()<<endl;
}
int main()
{
    Test();
    return 0;
}
