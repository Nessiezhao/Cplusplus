#include <iostream>
#include<string.h>
#include<assert.h>
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
//
//class String
//{
//public:
//    String(char* str="")
//        :_str(new char(strlen(str)+1))
//    {
//        strcpy(_str,str);
//    }
//    String(const String& s)
//        :_str(new char(strlen(s._str)+1))
//    {
//        strcpy(_str,s._str);
//    }
//    //s1 = s3
//    String& operator=(const String& s)
//    {
//        if(this != &s)
//        {
//            char* tmp = new char(strlen(s._str) + 1);
//            strcpy(tmp,s._str);
//            delete[] _str;
//            _str = tmp;
//        }
//        return *this;
//    }
//    ~String()
//    {
//        delete[] _str;
//        _str = NULL;
//    }
//    const char* c_str()
//    {
//        return _str;
//    }
//    const char& operator[](size_t pos)const
//    {
//        return _str[pos];
//    }
//    char& operator[](size_t pos)
//    {
//        if(GetCount() > 1 )
//        {
//            char* tmp = new char(strlen(_str)+1+4);
//            strcpy(_str,tmp+4);
//            --GetCount();
//            _str = tmp+4;
//            GetCount() = 1;
//        }
//        return _str[pos];
//    }
//    int& GetCount()
//    {
//        return *((int*)_str - 1);
//    }
//private:
//    char* _str;
//};
//
//void Test()
//{
//    String s1("abcd");
//    char* str1 = "abcd";
//    cout<<sizeof(s1)<<endl;
//    cout<<sizeof(str1)<<endl;
//    String s2(s1);
//    cout<<s1.c_str()<<endl;
//    cout<<s2.c_str()<<endl;
//    String s3("1234");
//    s1 = s3;
//    cout<<s1.c_str()<<endl;
//    cout<<s3.c_str()<<endl;
//}
class String
{
public:
    String(const char* str="")
        :_size(strlen(str))
        ,_capacity(_size)
    {
        _str = new char(_size+1);
        strcpy(_str,str);
    }
    //s1.Swap(s2)
    void Swap(String& s)
    {
        swap(_str,s._str);
        swap(_size,s._size);
        swap(_capacity,s._capacity);
    }
    //String s2(s1)
    String(const String& s)
        :_str(NULL)
    {
        String tmp(s._str);//为什么传的不是s
        this->Swap(tmp);
    }
    //s1 = s2
    String& operator=(String s)
    {
        this->Swap(s);
        return *this;
    }
    ~String()
    {
        if(_str)
        {
            delete[] _str;
            _str = NULL;
        }
    }
    const char* c_str()
    {
        return _str;
    }
    //Capacity
    void Reserve(size_t n)
    {
        Expand(n);
    }
    //Size + CapacityA
    //如果n < size就保留前n个
    //如果n > size就把size~n之间的数都用ch替换
    void Resize(size_t n, char ch = '\0')
    {
        if(n < _size)
        {
            _size = n;
            _str[_size] = '\0';
        }
        else
        {
            if(n > _capacity)
            {
                Expand(n);
            }
            size_t i = 0;
            for(i = _size;i < n;++i)
            {
                _str[i] = ch;
            }
            _str[n] = '\0';
            _size = n;
        }
    }
    void Expand(size_t n)
    {
        if(n > _capacity)
        {
            char *tmp = new char[n+1];
            strcpy(tmp,_str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }
    }
    void PushBack(char ch)
    {
        Insert(_size,ch);
    }
    void PopBack()
    {

    }
    void Insert(size_t pos,char ch)
    {
        assert(pos <= _size);
        if(_capacity == _size)
        {
            Expand(_capacity * 2);
        }
        int end = _size;
        while(end >= (int)pos)
        {
            _str[end+1] = _str[end];
            --end;
        }
        _str[pos] = ch;
        ++_size;
    }
    void Insert(size_t pos,const char* str)
    {
        assert(pos <= _size);
        size_t len = strlen(str);
        if(len + _size > _capacity)
        {
            Expand(_size+len);
        }
        int end = _size;
        while(end >= (int)pos)
        {
            _str[end+len] = _str[end];
            --end;
        }
        strncpy(_str+pos,str,len);
        _size += len;
    }
    void Erase(size_t pos,size_t n = 1)
    {
        
    }
    size_t Find(char ch)
    {

    }
    size_t Find(const char* str)
    {

    }
    String operator+(char ch)
    {

    }
    String& operator+=(char ch)
    {

    }
    String operator+(const char* str)
    {

    }
    String& operator+=(const char* str)
    {
        
    }
    bool operator>(const String& s)
    {

    }
    bool operator>=(const String& s)
    {

    }
    bool operator<(const String& s)
    {

    }
    bool operator<=(const String& s)
    {

    }
    bool operator==(const String& s)
    {

    }
    bool operator!=(const String& s)
    {

    }
private:
    char* _str;
    size_t _size;
    size_t _capacity;
};
int main()
{
    Test();
    return 0;
}
