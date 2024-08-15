
#ifndef TWO_D_H
#define TWO_D_H

#include <iostream>
#include <cassert>
#include "/../../../C++/!includes/pointerFunctions/one_d_functions.h"

using namespace std;

template <typename T>
T** allocate_two_d(int* size); //Allocate a 2D array

template <typename T>
void init_two_d(T** two_d_array, int* size, T value); //Initializing 2D array to a same value

template <typename T>
T* search_two_d(T** two_d_array, T target, int* size); //Giving an value, return the address with the target value

template <typename T>
void print_two_d(T** two_d_array, int* size); //Print the 2D array

template <typename T>
T read(T** two_d_array, int row, int column, int* size); //Read a value given row, column, and size

template <typename T>
void write(T** two_d_array, int row, int column, T value, int* size); //Change a value in the 2D array given the row
//and column

template <typename T>
void deallocate(T** two_d_array, int* size); //Deallocate all the array that is created

template <typename T>
bool search_two_d(T** two_d_array, T target, int* size, int& row, int& column);


//========================== NON TEMPLATED PROTOTYPES ====================================
void init_debug(int** two_d_array, int* size); //Initializing the 2D array like:
// 0 1 2 3
// 10 11 12 13 14 15
// 20 21 22 23

void init_debug_one_d(int* array_ptr, int size, int value); //Initializing 1D array: next value is 1 greater than the
//value before

bool isValid(int row, int column, int* size); //Check if the row and column here is valid

int getSize (int* size); //Get the size of the 2D array

void testing_two_d_pointer(); //Testing all the functions above
//============================================================================================================

template <typename T>
T* search_two_d(T** two_d_array, T target, int* size)
{
    T* find_prt;
    while(*size != -1)
    {
        T* one_d_array = *two_d_array; //Get the 1D array address from the 2D array
        find_prt = find(one_d_array, *size, target); //Find if the value is in that address given
        size ++;
        two_d_array ++;
        if(find_prt != nullptr) //Means that the value is found
            return find_prt;
    }
    return nullptr; //Else not found and return null pointer
}

template <typename T>
T& get(T** two_d_array, int row, int column)
{
    T** two_d_walker = two_d_array; //Create a walker
    two_d_walker += row; //When pass into this function, row already start with 0, same as column
    T* one_d_walker = *two_d_walker;
    one_d_walker += column;
    return *one_d_walker;
}

template <typename T>
void write(T** two_d_array, int row, int column, T value, int* size)
{
    assert(isValid(row, column, size)); //Check if out of bound
    get(two_d_array, row, column) = value;
}

template <typename T>
T read(T** two_d_array, int row, int column, int* size)
{
    assert(isValid(row, column, size)); //Check if out of bound
    return get(two_d_array, row, column);
}

template <typename T>
void init_two_d(T** two_d_array, int* size, T value)
{
    while (*size != -1)
    {
        init_one_d(*two_d_array, *size, value); //Initialize 1D array to the same value
        size ++;
        two_d_array ++;
    }
}

template <typename T>
bool search_two_d(T** two_d_array, T target, int* size, int& row, int& column)
{
    T* find_prt = nullptr;
    T** two_d_walker = two_d_array;
    while(*size != -1)
    {
        T* one_d_array = *two_d_walker; //Get the 1D array address from the 2D array
        find_prt = find(one_d_array, *size, target); //Find if the value is in that address given
        if(find_prt != nullptr) //Means that the value is found
        {
            column = find_prt - *two_d_walker;
            break;
        }
        size ++;
        two_d_walker ++;
    }
    if(find_prt == nullptr)
    {
        row = -1;
        column = -1;
        return false;
    }
    else
    {
        row = two_d_walker - two_d_array;
        return true;
    }
}

template <typename T>
T** allocate_two_d(int* size)
{
    int capacity = getSize(size);
    T** two_d_array = new T*[capacity];
    T** walker = two_d_array; //Need a walker because need to save the start address
    while (*size != -1) //This while loop saves address of array into 2D array
    {
        *walker = allocate<T>(*size);
        size ++;
        walker ++;
    }
    *walker = nullptr;
    return two_d_array;
}

template <typename T>
void print_two_d(T** two_d_array, int* size)
{
    while (*size != -1)
    {
        print(*two_d_array, *size);
        two_d_array ++;
        size ++;
    }
}

template <typename T>
void deallocate(T** two_d_array, int* size)
{
    T** walker = two_d_array;
    while(*size != -1) //Delete all the 1D array
    {
        delete[] *walker;
        size ++;
        walker ++;
    }
    delete[] *walker; //Delete the last null pointer
    delete[] two_d_array; //Delete the 2D array
}

#endif //LAB_PLANE_TWO_D_H
