#pragma once
#include<iostream>

typedef int DateType;

struct ListNode
{
    ListNode* _next;
    ListNode* _prev;
    DateType _data;
    ListNode(DateType x)
        :_data(x)
         ,_next(NULL)
         ,_prev(NULL)
    {}
};

class List
{
    typedef ListNode Node;
public:
    List()
        :_head(new Node(DateType()))
    {
        _head->_next = _head;
        _head->_prev = _head;
    }
    List(const List& l)
    {

    }
    List& operator=(const List& l)
    {

    }
    ~List()
    {

    }

    void PushBack(DateType x)
    {

    }
    void PushFront(DateType x)
    {

    }
    void PopBack(DateType x)
    {

    }
    void PopFront(DateType x)
    {

    }
    Node* Find(DateType x)
    {

    }
    void Insert(Node* pos,DateType x)
    {

    }
    void Erase(Node* pos)
    {

    }
private:
    Node* _head;
};
