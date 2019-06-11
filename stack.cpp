#include "stack.h"
#include<limits.h>

template class Stack<int>;

template <class T>
bool Stack<T>::push(T e)
{
    if(isFull())
    {
        return false;
    }
    else
    {
        stack[++top] = e;
        return true;
    }
}

template <class T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        return INT_MIN;
    }
    else
    {
        return stack[top--];
    }
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (top < 0);
}

template <class T>
bool Stack<T>::isFull()
{
    return (top == size);
}

template <class T>
int Stack<T>::spaceLeft()
{
    return (size - top - 1);
}


