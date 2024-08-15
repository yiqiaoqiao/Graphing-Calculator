#ifndef STACK_H
#define STACK_H

#include<iostream>
#include "../../!includes/List_Functions/node.h"

using namespace std;

template <class T>
class Stack{
public:
    //The nexted class is declared and defined inside the enclosing class declaration.
    class Iterator{
    public:
        friend class Stack;             //allow List to access private member of Iterator class

        Iterator()                      //default ctor
        {
            _ptr = nullptr;
        }

        Iterator(node<T>* p)            //ctor
        {
            _ptr = p;
        }

        bool is_null()                  //true if _ptr is NULL
        {
            return (_ptr == nullptr);
        }

        friend bool operator ==(const Iterator& left, const Iterator& right)    //true if left == right
        {
            return (left._ptr == right._ptr);
        }

        friend bool operator !=(const Iterator& left, const Iterator& right)    //true if left != right
        {
            return (!(left == right));
        }

        T& operator *()                 //dereference operator
        {
            assert(_ptr != nullptr);

            //returns the item in the list
            return _ptr->_item;
        }

        const T& operator *() const     //dereference operator
        {
            assert(_ptr != nullptr);

            //returns the item itself
            return *_ptr;
        }

        T* operator ->()                //member access operator
        {
            assert(_ptr != nullptr);

            //return the address of the item
            return _ptr;
        }

        const T* operator ->() const    //member access operator
        {
            assert(_ptr != nullptr);

            //return the address of the item
            return _ptr;
        }

        T& operator[] (int index)       //Return the item at the index
        {
            assert(index >= 0);

            //Same as at function in node
            return _at(_ptr, index);
        }

        friend Iterator operator ++(Iterator& it, int unused)   //it++
        {
            //First create temp that will save the address of it
            Iterator temp = it;

            //Then add the it ptr (++it)
            ++it;

            //Return the temp because it++ returns the ptr before adds
            return temp;
        }

        Iterator& operator++()          //++it
        {
            //Return the ptr after adds
            assert(_ptr != nullptr);
            _ptr = _ptr ->_next;
            return *this;
        }

    private:
        node<T>* _ptr;
    };

    //Functions:
    Stack();                                //ctor

    //Big three
    Stack(const Stack<T>& copy_this);       //Copy ctor
    Stack& operator =(const Stack& RHS);    //Assignment operator
    ~Stack();                               //Destructor

    void push(const T& item);               //Push at the front
    T pop();                                //Pop at the front
    bool empty() const;                     //True if the list is empty
    T top() const;                          //Return the top item

    Iterator Begin();
    Iterator End();
    void print();

private:
    node<T>* _top;
};

//============================ FXN DEFINITION ==========================
template <class T>
Stack<T>::Stack(): _top(nullptr)
{
    //Do nothing
}

template <class T>
Stack<T>::Stack(const Stack<T>& copy_this)
{
    _top = _copy_list(copy_this._top);
}

template <class T>
Stack<T>& Stack<T>::operator =(const Stack& RHS)
{
    // 1. check for self-reference
    if(this == &RHS){
        return *this;
    }

    //2. deallocate existing space
    _clear_list(_top);

    //3. allocate space for new array
    //No need in this class

    //4. copy everything over
    _top = _copy_list(RHS._head);

    //5. return this object
    return *this;
}

template <class T>
Stack<T>::~Stack()
{
    /*
    const bool debug = true;
    if(debug)
    {
        cout << "~Vector: ";
        _print_list(_head, cout);
        cout << endl;
    }
    */
    _clear_list(_top);
}

template <class T>
void Stack<T>::push(const T& item)
{
    _top = _insert_head(_top, item);
}

template <class T>
T Stack<T>::pop()
{
    return (_delete_node(_top, _top));
}

template <class T>
bool Stack<T>::empty() const
{
    return (_top == nullptr);
}

template <class T>
T Stack<T>::top() const
{
    return _top->_item;
}

template <class T>
typename Stack<T>::Iterator Stack<T>::Begin()
{
    return Iterator(_top);
}

template <class T>
typename Stack<T>::Iterator Stack<T>::End()
{
    return Iterator(nullptr);
}

template <class T>
void Stack<T>::print()
{
    _print_list(_top, cout);
}

#endif // STACK_H
