//
// Created by sergey on 12.03.2022.
//

#ifndef STACKLIB_STACK_H
#define STACKLIB_STACK_H

#include <iostream>
#include"EStackEmpty.h"
using namespace std;


template <typename T>
struct Node
{
    T item;
    Node<T>* next;
};

template <typename T>
class Stack
{
private:
    Node<T>* pTop;
    int size = 0;
public:
    Stack()
    {
        pTop = nullptr;
    }
    void Push(T item)
    {
        Node<T>* p;
        p = new Node<T>;
        p->item = item;
        p->next = pTop;
        pTop = p;
        size++;
    }

    int Size()
    {
        return size;
    }
    void Print()
    {
        if (pTop == nullptr)
            throw EStackEmpty();

        else
        {
            Node<T>* p;
            p = pTop;
            while (p != nullptr)
            {
                cout << p->item << "\n";
                p = p->next;
            }
            cout << endl;
        }
    }

    ~Stack()
    {
        Node<T>* p;
        Node<T>* p2;
        p = pTop;
        while (p != nullptr)
        {
            p2 = p;
            p = p->next;
            delete p2;
        }
        pTop = nullptr;
    }

    T Pop()
    {
        if (pTop == nullptr)
            throw EStackEmpty();
        Node<T>* p2;
        T item;
        item = pTop->item;
        p2 = pTop;
        pTop = pTop->next;
        delete p2;
        size--;
        return item;
    }
};



#endif //STACKLIB_STACK_H
