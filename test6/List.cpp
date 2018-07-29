#include<iostream>
#include<assert.h>
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
    typedef ListNode Node;
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
        :_head(new Node(DateType()))
    {
        _head->_next = _head;
        _head->_prev = _head;
        Node* cur = l._head->_next;
        while(cur !=l._head){
            PushBack(cur->_data);
            cur = cur->_next;
        }
    }
    List& operator=(List l)
    {
        std::swap(_head,l._head);
        return *this;
    }
    bool Empty()
    {
        return _head->_next == _head;
    }
    ~List()
    {
        Node* cur1 = _head->_next;
        Node* cur2 = cur1->_next;
        while(cur1 != _head)
        {
            delete cur1;
            cur1 = cur2;
            cur2 = cur2->_next;
        }
        std::cout<<"~List()"<<std::endl;
    }

    void PushBack(DateType x)
    {
        Insert(_head,x);
    }
    void PushFront(DateType x)
    {
        Insert(_head->_next,x);
    }
    void PopBack()
    {
        Erase(_head->_prev);
    }
    void PopFront()
    {
        Erase(_head->_next);
    }
    Node* Find(DateType x)
    {
        if(_head->_next == _head)
        {
            return NULL;
        }
        Node* cur = _head->_next;
        while(cur != _head)
        {
            if(cur->_data == x)
            {
                return cur;
            }
            cur = cur->_next;
        }
        return NULL;
    }
    void Insert(Node* pos,DateType x)
    {
        //node_prev new_node pos
        assert(pos);
        Node* new_node = new Node(x);
        Node* node_prev = pos->_prev;
        new_node->_next = pos;
        pos->_prev = new_node;
        new_node->_prev = node_prev;
        node_prev->_next = new_node;
    }
    void Erase(Node* pos)
    {
        assert(pos && pos != _head);
        Node* prev1 = pos->_prev;
        Node* next1 = pos->_next;
        prev1->_next = next1;
        next1->_prev = prev1;
        delete pos;
    }
    void Show()
    {
        Node* cur = _head->_next;
        while(cur != _head)
        {
            std::cout<<cur->_data<<" ";
            cur = cur->_next;
        }
        std::cout<<std::endl;
    }
private:
    Node* _head;
};

void Test()
{
    List l1;
    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);
    l1.PushBack(4);
    l1.PushBack(5);
    l1.Show();
    std::cout<<std::endl;

    List l2 = l1;
    l2.Show();
    std::cout<<std::endl;

    std::cout<<l1.Find(3)->_data<<std::endl;
    Node* pos = l1.Find(3);
    l1.Insert(pos,7);
    l1.Show();
    std::cout<<std::endl;

    List l3;
    l3 = l1;
    l3.Show();
    std::cout<<std::endl;
}
int main()
{
    Test();
    return 0;
}
