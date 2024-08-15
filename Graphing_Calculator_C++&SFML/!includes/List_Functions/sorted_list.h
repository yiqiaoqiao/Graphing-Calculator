#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>
#include "../../!includes/List_Functions/node.h"

using namespace std;
template <class T>
class List{
public:
    //The nexted class is declared and defined inside the enclosing class declaration.
    class Iterator{
    public:
        friend class List;             //allow List to access private member of Iterator class

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
            return &(_ptr->_item);
        }

        const T* operator ->() const    //member access operator
        {
            assert(_ptr != nullptr);

            //return the address of the item
            return &(_ptr->_item);
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

    List(bool order=false, bool unique=true);                   //CTOR with default args

    //BIG 3:
    ~List();
    List(const List<T> &copyThis);
    List& operator =(const List& RHS);

    Iterator Insert(const T& i);                        //Insert i in a sorted manner

    T Delete(List<T>::Iterator iMarker);        //delete node pointed to by marker
    void Print() const;
    Iterator Search(const T &key) const;                //return Iterator to node [key]
    Iterator Next(Iterator iMarker);                        //Next node to marker
    Iterator Prev(Iterator iMarker);                            //previous node to marker

    const T& operator[](int index) const;               //const version of the operator [ ]
    T& operator[](int index);                           //return item at position index
    Iterator Begin() const;                                     //Iterator to the head node
    Iterator End() const;                                       //Iterator to NULL
    template <class U>                                          //Note the template arg U
    friend ostream& operator <<(ostream& outs, const List<U>& l);

private:
    node<T>* _head_ptr;
    bool _order;
    bool _unique;
};

//============================ FXN DEFINITION ==========================
template <class T>
List<T>::List(bool order, bool unique): _order(order), _unique(unique), _head_ptr(nullptr)
{
    //Do Nothing
}

template <class T>
List<T>::List(const List<T> &copyThis)
{
    //copy list
     _head_ptr = _copy_list(copyThis._head_ptr);
     _order = copyThis._order;
     _unique = copyThis._unique;
}

template <class T>
List<T>& List<T>::operator =(const List& RHS)
{
    // 1. check for self-reference
    if(this == &RHS){
        return *this;
    }

    //2. deallocate existing space
    _clear_list(_head_ptr);

    //3. allocate space for new array
    //No need in this class

    //4. copy everything over
    _head_ptr = _copy_list(RHS._head_ptr);
    _order = RHS._order;
    _unique = RHS._unique;

    //5. return this object
    return *this;
}

template <class T>
List<T>::~List(){
    /*
    const bool debug = true;
    if(debug)
    {
        cout << "~Vector: ";
        _print_list(_head, cout);
        cout << endl;
    }
    */
    _clear_list(_head_ptr);
}

template <class T>
typename List<T>::Iterator List<T>::Insert(const T& i)
{
    //If it is the same thing and is unique, then i will not be inserted again
    if(_unique)
    {
        //Inser sorted add
        return Iterator(_insert_sorted_add(_head_ptr, i, _order));
    }
    else
    {
        return Iterator(_insert_sorted(_head_ptr, i, _order)); //Insert sorted only
    }
}

template <class T>
T List<T>::Delete(typename List<T>::Iterator iMarker)
{
    //Delete node function
    return _delete_node(_head_ptr, iMarker._ptr);
}

template <class T>
void List<T>::Print() const
{
    //Print list function
    _print_list(_head_ptr, cout);
}

template <class T>
typename List<T>::Iterator List<T>::Search(const T &key) const
{
    //Search function
    return Iterator(_search(_head_ptr, key));
}

template <class T>
typename List<T>::Iterator List<T>::Next(typename List<T>::Iterator iMarker)
{
    //Previous function
    return Iterator(_next(iMarker._ptr));
}

template <class T>
typename List<T>::Iterator List<T>::Prev(typename List<T>::Iterator iMarker)
{
    //Previous function
    return Iterator(_previous(_head_ptr, iMarker._ptr));
}

template <class T>
const T& List<T>::operator[](int index) const
{
    //At function
    return _at(_head_ptr, index);
}

template <class T>
T& List<T>::operator[](int index)
{
    //At function
    return _at(_head_ptr, index);
}

template <class T>
typename List<T>::Iterator List<T>::Begin() const
{
    //Return head ptr
    return Iterator(_head_ptr);
}

template <class T>
typename List<T>::Iterator List<T>::End() const
{
    //Nullptr
    return nullptr;
}

template <class U>
ostream& operator <<(ostream& outs, const List<U>& l)
{
    //Print list function
    _print_list(l._head_ptr, outs);
    return outs;
}

#endif // SORTED_LIST_H
