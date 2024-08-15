#ifndef ADD_REMOVE_ENTRY_H
#define ADD_REMOVE_ENTRY_H

#include <iostream>
#include "/../../../C++/!includes/pointerFunctions/one_d_functions.h"
using namespace std;

template <typename T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity); //Add the new entry to the last of the array

template <typename T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity); //Find the entry and remove from the array

template <typename T>
T* reallocate(int size, int capacity, T* arr); //Copy the array from the original array to the new array and return the
//new array

template <typename T>
T* insert_at_index(T* array, const int& insert_here, const T& insert_this, int& size, int& capacity);
//Insert a element at the middle of the array

template <typename T>
T* remove_at_index(T* array, const int& erase_index, int& size, int& capacity);
//Remove a element at the middle of the array

template <typename T>
T* resize(T* array, int capacity, int new_capacity, const T& value = T());

//=================================================================================================================

template <typename T>
T* resize(T* array, int capacity, int new_capacity, const T& value)
{
    T* new_array = allocate<T>(new_capacity);
    copy(new_array, array, capacity);
    delete[] array;

    //Initialize the rest of the elements that is not copied
    T* init_position = new_array + capacity;
    int size = new_capacity - capacity;
    init_one_d(init_position, size, value);

    return new_array;
}

template <typename T>
T* remove_at_index(T* array, const int& erase_index, int& size, int& capacity)
{
    T* position = array + erase_index;
    shiftLeft(array, position, size);
    //Check whether or not need to be reallocated
    if(size < capacity / 4) // Check if size is 1/4 of the capacity and reallocate if it is
    {
        array = reallocate(size, capacity / 2, array);
        capacity /= 2;
    }
    //cout  << "Array: " << *array << endl;
    //cout << array << endl;
    size --;
    return array;
}

template <typename T>
T* insert_at_index(T* array, const int& insert_here, const T& insert_this, int& size, int& capacity)
{
    //Check whether or not need to be reallocated
    if (size + 1 == capacity) {
        array = reallocate(size, capacity * 2, array); //If the size is the same as capacity, reallocate
        capacity *= 2;
    }
    //Find the position
    T* position = array + insert_here;
    shiftRight(array, position, size);
    *position = insert_this;
    size ++;
    return array;
}

template <typename T>
T* reallocate(int size, int capacity, T* arr)
{
    T* newList;
    newList = allocate<T>(capacity);

    copy(newList, arr, size); //Function from the other file that is include in this program
    delete[] arr; // Need to delete the original array so do not take space in heap
    return newList;
}

template <typename T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity) {
    if (size + 1 == capacity) {
        list = reallocate(size, capacity * 2, list); //If the size is the same as capacity, reallocate
        capacity *= 2;
    }
    //Walker position is to find the address of one after the interesting element so you can add entry to the next position
    T* position = list + size;
    *position = new_entry;
    size ++;
    return list;
}

template <typename T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity)
{
    T* startPtr = list;
    T* findPtr = find(startPtr, size, delete_me);

    if(findPtr != nullptr) //If pointer does not return null pointer, delete the value in that address that find
        //pointer finds.
        //Only need to remove one entry
    {
        shiftLeft(list, findPtr, size);
    }

    if(size < capacity / 4) // Check if size is 1/4 of the capacity and reallocate if it is
    {
        list = reallocate(size, capacity / 2, list);
        capacity /= 2;
    }
    return list;
}

#endif //ADD_REMOVE_ENTRY_H
