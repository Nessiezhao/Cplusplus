#pragma once
#include<iostream>
#include<assert.h>
typedef int DateType;
template<class T>
class Vector
{
public:
    Vector()
        :_first(NULL)
         ,_finish(NULL)
         ,_endofstorage(NULL)
    {}
    Vector(const Vector<T>& v)
    {
        _first = new T[v.Size()];
        int i = 0;
        for(i = 0;i < v.Size();i++)
        {
            _first[i] = v._first[i];
        }
        _finish = _first + v.Size();
        _endofstorage = _first + v.Size();
    }
    Vector<T>& operator=(const Vector<T>& v)
    {
        swap(_first,v._first);
        swap(_finish,v._finish);
        swap(_endofstorage,v._endofstorage);
        return *this;
    }
    T& Back()
    {
        return *(_finish-1);
    }
    T& Front()
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
    void PushBack(const T& x)
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
            T* tmp = new T[newcapacity];
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
    void Resize(size_t size,const T& value)
    {
        Expand(size);
        memset(_first,value,sizeof(T)*size);
    }
    void PopBack()
    {
        Erase(Size() - 1);
    }
    void Reserve(size_t n)
    {

    }
    void Insert(size_t pos,const T& x)
    {
        assert(pos <= Size());
        if(_finish == _endofstorage)
        {
            size_t newcapacity = Capacity() == 0 ? 3 : Capacity()*2;
            Expand(newcapacity);
        }
        T* end = _finish -1;
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
        T* start = _first + pos;
        while(start < _finish-1)
        {
            *start = *(start+1);
            ++start;
        }
        --_finish;
    }
    size_t Find(T x)
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
