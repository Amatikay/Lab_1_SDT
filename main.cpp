#include <iostream>
#include "Stack.h"
int main() {
    Stack<int> A;
    A.Push(23);
    std::cout<<A.Size()<<endl;
    std::cout<< A.Pop()<<endl;

    for (int i = 0; i < 10; ++i) {
        A.Push(10-i);
    }
    A.Print();
}