#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H

#include"../../!includes/List_Functions/node.h"
#include<iostream>
#include<cassert>

using namespace std;

template <class T>
class List
{
public:

    List();                                 // CTORS

    //Big Three
    List(const List<T> &copyThis);       // Copy contructor
    List& operator =(const List& RHS);   // Assignment operator
    ~List();                              // Destructor

    node<T>* InsertHead(const T& i);      //inset i at the head of list

    node<T>* InsertAfter(const T& i,node<T>* iMarker);   //insert i after iMarker

    node<T>* InsertBefore(const T& i,node<T>* iMarker);   //insert i before iMarker

    T Delete(node<T>* iMarker);         //delete node pointed to by iMarker

    void Print() const;                 //print the list

    node<T>* Search(const T& key);      //return pointer to node containing
                                         //  key. NULL if not there

    node<T>* Prev(node<T>* iMarker);    //get the previous node to iMarker

    node<T>* Next(node<T>* iMarker);    //get the next node to iMarker

    T& operator[](int index);           //return the item at index

    node<T>* Begin() const;             //return the head of the list

    node<T>* End() const;               //return the tail of the list
                                        //  if you ever have to use this
                                        //  function, you need to redesign
                                        //  your program.

    void clear();                       // clear the list

    template <class U>
    friend ostream& operator << (ostream& outs, const List<U>& object);

private:
    node<T>* _head;

};

//============================ FXN DEFINITION ==========================
template <class T>
List<T>::List(): _head(nullptr){
    //Nothing to code
}

template <class T>
List<T>::List(const List<T> &copyThis){
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
node<T>* List<T>::InsertHead(const T& i) {
    //Insert head function
    return _insert_head(_head,i);
}

template <class T>
node<T>* List<T>::InsertAfter(const T& i,node<T>* iMarker) {
    //Insert after function
    return _insert_after(_head,iMarker,i);
}

template <class T>
node<T>* List<T>::InsertBefore(const T& i,node<T>* iMarker) {
    //Insert before function
    return _insert_before(_head,iMarker,i);
}

template <class T>
T List<T>:: Delete(node<T>* iMarker){
    //Delete node function
    return _delete_node(_head,iMarker);
}

template <class T>
void List<T>::Print() const{
    //Print list function
    _print_list(_head);
}

template <class T>
node<T>* List<T>::Search(const T& key) {
    //Search function
    return _search(_head,key);
}


template <class T>
node<T>* List<T>::Prev(node<T>* iMarker){
    //Previous function
    return _previous(_head,iMarker);
}

template <class T>
node<T>* List<T>::Next(node<T>* iMarker){
    //Next function
    return _next(iMarker);
}

template <class T>
T& List<T>::operator[](int index){
    //At function
    return _at(_head,index);
}

template <class T>
node<T>* List<T>::Begin() const {
    //head pointer is the beginning of the list
    return _head;
}

template <class T>
node<T>* List<T>::End() const {
    //Last node function
    return _last_node(_head);
}

template <class U>
ostream& operator << (ostream& outs, const List<U>& object) {
    //Print list function
    return _print_list(object._head, outs);
}
#endif // LIST_FUNCTIONS_H
