#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<cassert>
#include "../../!includes/AddEntry/Add_Remove_Entry.h"
#include "../../!includes/pointerFunctions/one_d_functions.h"

using namespace std;

template <class T>
class Vector{
public:

    Vector(unsigned int capacity = 100);

    // big three:
    Vector(const Vector& other); //copy constructor
    Vector& operator= (const Vector& other);
    ~Vector(); //destructor

    //member access functions:
    const T operator [](unsigned int index) const;
    T& operator [](unsigned int index);
    T& at(int index);             //return reference to item at position index
    const T at(int index) const;  //return a const item at position index
    T& front() const;             //return item at position 0.
    T& back() const;              //return item at the last position


    //Push and Pop functions:
    Vector& operator +=(const T& item); //push_back
    void push_back(const T& item);      //append to the end
    T pop_back();                       //remove last item and return it


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos
    void erase(int erase_index);        //erase item at position
    int index_of(const T& item);        //search for item. retur index.

    //size and capacity:
    void set_size(int size, const T& init_value = T());            //enlarge the vector to this size
    void set_capacity(int capacity);    //allocate this space
    int size() const {return _size;} //return _size
    int capacity() const {return _capacity;} //return _capacity
    bool empty() const;                 //return true if vector is empty

    //OUTPUT:
    template <class U>
    friend ostream& operator <<(ostream& outs, const Vector<U>& v);

private:
    int _size;
    int _capacity;
    T* _a;
    int _error = 0;
};




//==========================FXN DEFINITION==========================
template <class T>
Vector<T>::Vector(unsigned int capacity):_capacity(capacity), _size(0), _error(0)
{
    //init debug
    const bool debug = true;
    /*
    if(debug)
        cout << "Vector CTOR(" << _capacity << ")" << endl;
    */
    _a = allocate<T>(capacity);
}

// big three:
template <class T>
Vector<T>::Vector(const Vector& other)
{
    const bool debug = true;
    /*
    if(debug)
        cout << "Vector CTOR (" << other << ")" << endl;
        */
    _a = allocate<T>(other.capacity());
    _size = other.size();
    _capacity = other.capacity();
    _error = 0;
    copy(_a, other._a, _size);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    const bool debug = true;
    /*
    if(debug)
        cout << "Vector CTOR (" << other << ")" << endl;
        */

    //1. Check for self-reference
    if(this == &other)
        return *this;

    //2. deallocate existing space
    delete[] _a;

    //3. allocate space for new array
    _size = other.size();
    _capacity = other.capacity();
    _error = 0;
    _a = allocate<T>(other.capacity());

    //4. copy everything over
    copy(_a, other._a, other.size());

    //5. return this object
    return *this;
}

template <class T>
Vector<T>::~Vector()
{
    /*
    const bool debug = true;
    if(debug)
    {
        cout << "~Vector: ";
        for(int i = 0; i < _size; i++)
        {
            cout << _a[i] << " ";
        }
        cout << endl;
    }
    */

    //Delete the array
    delete[] _a;
}

//member access functions:
template <class T>
const T Vector<T>::operator[](const unsigned int index) const
{
    //Index has to be less or equal to size
    assert(index <= _size);

    T* position = _a + index;
    return *(position);
}

template <class T>
T& Vector<T>::operator[](const unsigned int index)
{
    //Index has to be less or equal to size
    assert(index <= _size);

    T* position = _a + index;
    return *(position);
}

template <class T>
T& Vector<T>::at(int index)
{
    //same as operator[]
    assert(index <= _size);

    T* position = _a + index;
    return *(position);
}

template <class T>
const T Vector<T>::at(int index) const
{
    //same as operator[]
    assert(index <= _size);

    T* position = _a + index;
    return *(position);
}

template <class T>
T& Vector<T>::back() const
{
    //Size need to - 1 because starts with 0
    T* position = _a + _size - 1;
    return *position;
}
template <class T>
T& Vector<T>::front() const
{
    //Beginning of the array
    return *_a;
}

//Push and Pop functions:
template <class T>
Vector<T>& Vector<T>::operator+=(const T& item)
{
    //Add entry to the last of the array
    _a = add_entry(_a, item, _size, _capacity);

    //Return this object
    return *this;
}

template <class T>
void Vector<T>::push_back(const T& item)
{
    //Same as operator +=
    _a = add_entry(_a, item, _size, _capacity);
}

//Ask Professor for pop_back
template <class T>
T Vector<T>::pop_back()
{
    //Find the position of the last element
    T* end_position = _a + _size - 1;

    //Save the value
    T value = *end_position;

    //Find the index that needs to be removed
    T remove_index = _size - 1;
    _a = remove_at_index(_a, remove_index, _size, _capacity);
    //return what? : value
    return value;
}


//Insert and Erase:
template <class T>
void Vector<T>::insert(int insert_here, const T& insert_this)
{
    _a = insert_at_index(_a, insert_here, insert_this, _size, _capacity);
}

template <class T>
void Vector<T>::erase(int erase_index)
{
    _a = remove_at_index(_a, erase_index, _size, _capacity);
    //cout  << "Array: " << *_a << endl;
    //cout << _a << endl;
}

template <class T>
int Vector<T>::index_of(const T& item)
{
    T* position = find(_a, _size, item);

    //If not find the item, return error and exit the program
    if(position == nullptr)
    {
        cout << "Error: item not found" << endl;
        exit (-1);
    }
    else
        return (position - _a);
}

//size and capacity:
template <class T>
void Vector<T>::set_size(int size, const T& init_value)
{
    //Size has to be greater than 0
    assert(size >= 0);
    if(size <= _size)
    {
        //If the size is smaller, just set the private variable size to the smaller size
        //Other elemnts outside will be trash
        _size = size;
    }
    else
    {
        //Make sure the capacity is greater than the size
        while (size >= _capacity) {
            _a = reallocate(_size, _capacity * 2, _a);
            _capacity *= 2;
        }
        //then initialize the value
        int init_size = size - _size;
        T* start_init_position = _a + _size; //Find the position that should start initialize
        init_one_d(start_init_position, init_size, init_value);
        _size = size;
    }
}

template <class T>
void Vector<T>::set_capacity(int capacity)
{
    //Capacity needs to be greater than the size
    assert(capacity > _size);

    //Reallocate the capacity
    _capacity = capacity;
    _a = reallocate(_size, _capacity, _a);
}

template <class T>
bool Vector<T>::empty() const
{
    //Check if the size is 0
    if(_size == 0)
        return true;
    else {
        return false;
    }
}

/*
//Output
template <class U>
ostream& operator <<(ostream& outs, const Vector<U>& v)
{
    //print the value
    for(int i = 0; i < v.size(); i++)
    {
        outs << v._a[i] << " ";
    }
    return outs;
}
*/

#endif // VECTOR_H
