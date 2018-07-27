#pragma once
#include<iostream>
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
    void Expand(size_t n)
    {

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
    void Reserve(size_t n)
    {

    }
    void PopBack()
    {
        Erase(Size() - 1);
    }
    void Insert(size_t pos,DateType x)
    {

    }
    void Erase(size_t pos)
    {

    }
    size_t Find(DateType x)
    {

    }
private:
    DateType* _first;
    DateType* _finish;
    DateType* _endofstorage;
};
