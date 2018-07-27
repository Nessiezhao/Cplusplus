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
    size_t Size()
    {

    }
    size_t Capacity()
    {

    }
    void Expand(size_t n)
    {

    }
    void PushBack(DateType x)
    {

    }
    void Reserve(size_t n)
    {

    }
    void PopBack()
    {

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
