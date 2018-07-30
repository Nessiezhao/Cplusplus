#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;
typedef int DateType;
class Vector
{
public:
    Vector()
        :_first(NULL)
         ,_finish(NULL)
         ,_endofstorage(NULL)
    {}
    Vector(const Vector& v)
    {
        _first = new DateType[v.Size()];
        size_t i = 0;
        for(i = 0;i < v.Size();i++)
        {
            _first[i] = v._first[i];
        }
        _finish = _first + v.Size();
        _endofstorage = _first + v.Size();
    }
    const DateType& operator[](size_t pos)
    {
        return _first[pos];
    }
    Vector& operator=(Vector v)
    {
        swap(_first,v._first);
        swap(_finish,v._finish);
        swap(_endofstorage,v._endofstorage);
        return *this;
    }
    DateType& Back()
    {
        return *(_finish-1);
    }
    DateType& Front()
    {
        return *(_first);
    }
    ~Vector()
    {
        if(_first)
        {
            delete[] _first;
        }
        _first = _finish = _endofstorage = NULL;
    }
    size_t Size()const
    {
        return (_finish - _first);
    }
    size_t Capacity()const
    {
        return (_endofstorage - _first);
    }
    void PushBack(DateType x)
    {
        if(_finish == _endofstorage)
        {
            size_t newcapacity = Capacity() == 0 ? 3 : (Capacity()* 2);
            Expand(newcapacity);
        }
        *_finish = x;
        ++_finish;
    }
    void Expand(size_t newcapacity)
    {
        if(newcapacity > Capacity())
        {
            size_t size = Size();
            DateType* tmp = new DateType[newcapacity];
            if(_first)
            {
                size_t i = 0;
                for(i = 0;i < size ;i++)
                {
                    tmp[i] = _first[i];
                }
            }
            _first = tmp;
            _finish = _first + size;
            _endofstorage = _first + newcapacity;
        }
    }
    void Resize(size_t size,const DateType& value)
    {
        Expand(size);
        memset(_first,value,sizeof(DateType)*size);
    }
    void PopBack()
    {
        Erase(Size() - 1);
    }
    void Reserve(size_t n)
    {
        if(n > Capacity())
        {
            DateType* new_first = new DateType[n];
            DateType* new_finish = new_first;
            DateType* tmp = this->_first;
            for(tmp = this->_first;tmp != this->_finish;tmp++)
            {
                *new_first = *tmp;
                new_finish++;
            }
            delete[] _first;
            _first = new_first;
            _finish = new_finish;
            _endofstorage = new_first + n;
        }
    }
    void Insert(size_t pos,DateType x)
    {
        assert(pos <= Size());
        if(_finish == _endofstorage)
        {
            size_t newcapacity = Capacity() == 0 ? 3 : Capacity()*2;
            Expand(newcapacity);
        }
        DateType* end = _finish -1;
        while(end >= _first + pos)
        {
            *(end+1) = *end;
            --end;
        }
        _first[pos] = x;
        ++_finish;
    }
    void Erase(size_t pos)
    {
        assert(pos < Size());
        DateType* start = _first + pos;
        while(start < _finish-1)
        {
            *start = *(start+1);
            ++start;
        }
        --_finish;
    }
    size_t Find(DateType x)
    {
        size_t i = 0;
        for(i = 0;i < Size();i++)
        {
            if(_first[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
private:
    DateType* _first;
    DateType* _finish;
    DateType* _endofstorage;
};

void Test1()
{
    Vector v1;
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    v1.PushBack(4);
    v1.PushBack(5);
    int i = 0;
    for(i = 0;i < (int)v1.Size();++i)
    {
        std::cout<<v1[i]<<" ";
    }
    std::cout<<std::endl;
    v1.Erase(2);
    for(i = 0;i < (int)v1.Size();++i)
    {
        std::cout<<v1[i]<<" ";
    }
    std::cout<<std::endl;
    v1.PopBack();
    for(i = 0;i < (int)v1.Size();++i)
    {
        std::cout<<v1[i]<<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    Test1();
    return 0;
}
