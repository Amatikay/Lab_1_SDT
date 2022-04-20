//
// Created by sergey on 12.03.2022.
//

#ifndef STACKLIB_STACK_H
#define STACKLIB_STACK_H

#include <iostream>
#include"EStackException.h"
using namespace std;


template <typename T>
struct Node //структура однонаправленного связного списка
{
    T item; // "этот" элемент
    Node<T>* next; //указатель на следующий элемент
};
/*
 * Шаблонный класс стек на списке
 */
template <typename T>
class Stack
{
private:
    Node<T>* pTop; // указатель на верхушку стека
    int size = 0; //размер стека
public:

    Stack() // контруктор по умолчанию
    {
        pTop = nullptr; // в качетве верхушки получаем константу нулевого указателя
    }

    Stack(const Stack& SL) //конструктор копирования
    {
        Node<T>* p;
        Node<T>* p2;
        Node<T>* p3;


        pTop = nullptr;
        p3 = nullptr;

        p = SL.pTop;
        while (p != nullptr)
        {

            try {

                p2 = new Node<T>;
            }
            catch (bad_alloc e)
            {
                cout << e.what() << endl;
                return;
            }
            p2->item = p->item;
            p2->next = nullptr;

            if (pTop == nullptr)
            {
                pTop = p2;
                p3 = p2;
            }
            else
            {
                p3->next = p2;
                p3 = p3->next;
            }
            p = p->next;
        }
    }
    void Push(T item) //добавить в стек элемент
    {
        Node<T>* p;
        p = new Node<T>;
        p->item = item;
        p->next = pTop;
        pTop = p;
        size++;
    }

    void Clear() // очистить стек
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

    int Size() //размер стека
    {
        return size;
    }
    void Print() // вывести стек не изменяя его
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

    ~Stack() //деструктор
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

    T Pop() //вернуть последний элемент с удалением его
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

    Node<struct Person> *const get_topPtr() const{ //получить указатель на верхушку стека
        return pTop;
    }

};



#endif //STACKLIB_STACK_H
