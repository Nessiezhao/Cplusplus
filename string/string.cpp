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
    void Append(const char* str)
    {
        Insert(_size,str);
    }
    void PopBack()
    {
        assert(_size > 0);
        --_size;
        _str[_size] = '\0';
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
    void Erase(size_t pos,size_t len)
    {
        assert(pos < _size);
        if(pos + len > _size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            strcpy(_str+pos,_str+pos+len);
            _size -= len;
        }
    }
    size_t Find(char ch)const
    {
        size_t i = 0;
        for(i = 0;i < _size;++i)
        {
            if(_str[i] == ch)
            {
                return i;
            }
        }
        return -1;
    }
    size_t Find(const char* str)const
    {
        char* src = _str;
        while(*src)
        {
            const char* lstr = src;
            const char* sstr = str;
            while(*sstr && *lstr == *sstr)
            {
                ++lstr;
                ++sstr;
            }
            if(*sstr == '\0')
            {
                return src-_str;
            }
            else
            {
                ++src;
            }
        }
        return -1;
    }
    String operator+(char ch)
    {
        String ret(*this);
        ret.PushBack(ch);
        return ret;
    }
    String& operator+=(char ch)
    {
        this->PushBack(ch);
        return *this;
    }
    String operator+(const char* str)
    {
        String ret(*this);
        ret.Append(str);
        return ret;
    }
    String& operator+=(const char* str)
    {
       this->Append(str) ;
       return *this;
    }
    bool operator>(const String& s)
    {
        return !(*this <= s);
    }
    bool operator>=(const String& s)
    {
        return !(*this < s);
    }
    bool operator<(const String& s)
    {
        const char* str1 = _str;
        const char* str2 = s._str;
        while(*str1 && *str2)
        {
            if(*str1 > *str2)
            {
                return false;
            }
            else if(*str1 < *str2)
            {
                return true;
            }
            else
            {
                ++str1;
                ++str2;
            }
        }
        if(*str1 == '\0' && *str2 != '\0')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<=(const String& s)
    {
        return *this < s || *this == s;
    }
    bool operator==(const String& s)const
    {
        const char* str1 = _str;
        const char* str2 = s._str;
        while(*str1 && *str2)
        {
            if(*str1 != *str2)
            {
                return false;
            }
            else
            {
                ++str1;
                ++str2;
            }
        }
        if(*str1 == '\0' && *str2 == '\0')
        {
            return true;
        }
        else{
            return false;
        }
    }
    bool operator!=(const String& s)const
    {
        return !(*this == s);
    }
private:
    char* _str;
    size_t _size;
    size_t _capacity;
};

void Test()
{
    String s1 = "hello ";
    String s2(s1);
    cout<<"hello:"<<s1.c_str()<<endl;
    cout<<"hello:"<<s2.c_str()<<endl;

    String s3;
    s3 = s1;
    s3.PushBack('a');
    s3.PushBack('b');
    s3.PushBack('c');
    s3.PushBack('d');
    cout<<"hello abcd:"<<s3.c_str()<<endl;
    s3.PopBack();
    s3.PopBack();
    cout<<"hello ab:"<<s3.c_str()<<endl;
    s3.Swap(s1);
    cout<<"hello :"<<s3.c_str()<<endl;
    size_t x = s3.Find('e');
    cout<<"1 :"<<x<<endl;
    s3.Erase(2,2);
    cout<<"heo :"<<s3.c_str()<<endl;
    bool a = s3.operator<=(s1);
    cout<<"0 : "<<a<<endl;
    s1.Append("world");
    cout<<"hello abworld : "<<s1.c_str()<<endl;
}
int main()
{
    Test();
    return 0;
}
