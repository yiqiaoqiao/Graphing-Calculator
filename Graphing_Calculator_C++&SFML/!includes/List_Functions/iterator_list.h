#ifndef ITERATOR_LIST_H
#define ITERATOR_LIST_H

#include <iostream>
#include <cassert>
#include "../List_Functions/node.h"

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
    List();                                 // CTORS

    //Big Three
    List(const List<T> &copyThis);       // Copy contructor
    List& operator =(const List& RHS);   // Assignment operator
    ~List();                              // Destructor

    Iterator InsertHead(const T& i);      //inset i at the head of list

    Iterator InsertAfter(const T& i,Iterator iMarker);   //insert i after iMarker

    Iterator InsertBefore(const T& i,Iterator iMarker);   //insert i before iMarker

    T Delete(List<T>::Iterator iMarker);         //delete node pointed to by iMarker

    void Print() const;                 //print the list

    Iterator Search(const T& key);      //return pointer to node containing
                                         //  key. NULL if not there

    Iterator Prev(Iterator iMarker);    //get the previous node to iMarker

    Iterator Next(Iterator iMarker);    //get the next node to iMarker

    T& operator[](int index);           //return the item at index

    Iterator Begin() const;             //return the head of the list

    Iterator End() const;               //return the tail of the list
                                        //  if you ever have to use this
                                        //  function, you need to redesign
                                        //  your program.

    Iterator LastNode();

    void clear();                       // clear the list

    template <class U>
    friend ostream& operator << (ostream& outs, const List<U>& object);

private:
    node<T>* _head;
};

//============================ FXN DEFINITION ==========================
template <class T>
List<T>::List():_head(nullptr)
{
    //Do nothing
}

//Big Three
template <class T>
List<T>::List(const List<T> &copyThis)
{
    //copy list
     _head = _copy_list(copyThis._head);
}

template <class T>
List<T>& List<T>::operator =(const List& RHS){
    // 1. check for self-reference
    if(this == &RHS){
        return *this;
    }

    //2. deallocate existing space
    _clear_list(_head);

    //3. allocate space for new array
    //No need in this class

    //4. copy everything over
    _head = _copy_list(RHS._head);

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
    _clear_list(_head);
}

template <class T>
typename List<T>::Iterator List<T>::InsertHead(const T& i)
{
    //Insert head function
    return Iterator(_insert_head(_head,i));
}

template <class T>
typename List<T>::Iterator List<T>::InsertAfter(const T& i, typename List<T>::Iterator iMarker) {
    //Insert after function
    return Iterator(_insert_after(_head,iMarker._ptr,i));
}

template <class T>
typename List<T>::Iterator List<T>::InsertBefore(const T& i, typename List<T>::Iterator iMarker) {
    //Insert before function
    return Iterator(_insert_before(_head,iMarker._ptr,i));
}

template <class T>
T List<T>::Delete(typename List<T>::Iterator iMarker)
{
    //Delete node function
    return _delete_node(_head,iMarker._ptr);
}

template <class T>
void List<T>::Print() const{
    //Print list function
    _print_list(_head);
}

template <class T>
typename List<T>::Iterator List<T>::Search(const T& key) {
    //Search function
    return _search(_head,key);
}

template <class T>
typename List<T>::Iterator List<T>::Prev(typename List<T>::Iterator iMarker){
    //Previous function
    return Iterator(_previous(_head,iMarker._ptr));
}

template <class T>
typename List<T>::Iterator List<T>::Next(typename List<T>::Iterator iMarker){
    //Next function
    return Iterator(_next(iMarker._ptr));
}

template <class T>
T& List<T>::operator[](int index){
    //At function
    return _at(_head,index);
}

template <class T>
typename List<T>::Iterator List<T>::Begin() const {
    //head pointer is the beginning of the list
    return _head;
}

template <class T>
typename List<T>::Iterator List<T>::End() const {
    //Last node function
    return nullptr;
}

template <class T>
void List<T>::clear()
{
    _clear_list(_head);
}

template <class T>
typename List<T>::Iterator List<T>::LastNode()
{
    //Check for head ptr
        if(_head == nullptr)
            return nullptr;

        //Keep going through the walker and find the last position
        node<T>* temp = _head;
        node<T>* last_node;
        while (temp != nullptr) {
            last_node = temp;
            temp = temp ->_next;
        }
        return last_node;
}

template <class U>
ostream& operator << (ostream& outs, const List<U>& object) {
    //Print list function
    return _print_list(object._head, outs);
}


#endif // ITERATOR_LIST_H
