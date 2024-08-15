#ifndef ONE_D_FUNCTIONS_H
#define ONE_D_FUNCTIONS_H
#include <iostream>
using namespace std;

template <typename T>
void copy(T* dest, T* src, int size);

template <typename T>
void shiftLeft(T* array, T* position_ptr, int& size);

template <typename T>
void shiftRight(T* array, T* position_ptr, int& size);

template <typename T>
T* find(T* start_ptr, int size, T target);

template <typename T>
void print(T* list, int size); //Print the list

template <typename T>
T* allocate(int capacity); //Return a new array with the current capacity

template <typename T>
void init_one_d(T* array_ptr, int size, T value); //Initializing one D array, the array that saves values

template <typename T>
void init_one_d(T* array_ptr, int size, T value)
{
    for(T* end = array_ptr + size; array_ptr < end; array_ptr ++)
    {
        *array_ptr = value; // Save every value to the same value
    }
}

/*
 * Precondition: len(dest) >= size
                len(src) >= size
 Postcondition: copy size element from source to the destination
*/
template<typename T>
void copy(T* dest, T* src, int size)
{
    //For the size of elements, every elements will copy from source to the destination
    for(int i = 0; i < size; i++)
    {
        *dest = *src; //The value of destination pointer points to will be the same as the value of source pointer points to
        dest++;    //Moves the dest pointer to the right
        src++;     //Moves the src pointer to the right
    }
}

/*
 * Precondition: size initialized
 * Postcondition: everything from the right of the position pointer is
 */
template <typename T>
void shiftLeft(T* array, T* position_ptr, int& size)
{
    int position_size = array + size - position_ptr;
    T* next_ptr = position_ptr; //Initialize the next pointer
    for(T* end = position_ptr + position_size; next_ptr < end; position_ptr ++) //NOTE: next pointer cannot be more than the
        //end of the pointer
    {
        next_ptr = position_ptr + 1; // set the next pointer one more than the address of the position pointer
        *position_ptr = *next_ptr; //Move all the next value to current array
    }
    size --;
}

template <typename T>
void shiftRight(T* array, T* position_ptr, int& size)
{
    //Find the size that needs to be shifted right
    int ptr_size = array + size - position_ptr;

    //pointer that will help do the shift
    T* pointer_shift = array + size - 1;

    //Pointer that will be the destintion that the pointer shift will shift
    T* shift_here = nullptr;
    for(int i = 0; i < ptr_size; i++)
    {
        //Set shift here one to the right of the pointer
         shift_here = pointer_shift + 1;
         //Shift here
         *shift_here = *pointer_shift;
         pointer_shift --;
    }
    size++;
}

/*
 * Postcondition: return a address that has the value of target, else return null
 */
template <typename T>
T* find(T* start_ptr, int size, T target)
{
    for(T* end = start_ptr + size; start_ptr < end; start_ptr++)
    {
        if(*start_ptr == target)
        {
            return start_ptr; //If there is a value that is the same, return the ADDRESS of this value that is stored in
        }
    }
    return nullptr; //Else return the null pointer
}

template <typename T>
void print(T* list, int size)
{
    for(T* end = list + size; list < end; list ++)
    {
        cout << *list << " ";
    }
    cout << endl;
}

template <typename T>
T* allocate(int capacity){
    /*
    const bool debug = false;
    if (debug) {
        cout << "allocate: capacity: " << capacity << endl;
    }
     */ //What does this do? Why do we need this?
    return new T[capacity];
}
#endif // ONE_D_FUNCTIONS_H
