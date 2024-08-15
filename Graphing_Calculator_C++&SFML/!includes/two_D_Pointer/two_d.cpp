#include "two_d.h"
int getSize (int* size)
{
    int two_d_size = 0;
    while (*size != -1) //While the size of 1D array is not -1
    {
        two_d_size ++;
        size++;
    }
    return two_d_size;
}

void init_debug(int** two_d_array, int* size)
{
    int value = 0;
    while (*size != -1)
    {
        init_debug_one_d(*two_d_array, *size, value);
        value += 10; //After initialize the first row, the first value for the next row start with +10
        size ++;
        two_d_array ++;
    }
}

void init_debug_one_d(int* array_ptr, int size, int value)
{
    for(int* end = array_ptr + size; array_ptr < end; array_ptr ++)
    {
        *array_ptr = value;
        value ++; //To make sure the next value is one greater
    }
}

bool isValid(int row, int column, int* size)
{
    if (row > getSize(size) || row < 0) //Row can't be greater than the number of size, and row can't be negative
        return false;
    int* sizeWalker = size;
    sizeWalker += row;
    return (column < *sizeWalker && column >= 0); //Column can't be greater than the size of the 1D array, and it can't
    //be negative

}

void testing_two_d_pointer()
{
    int size[] = {5, 4, 3, 6, -1};
    int** two_d_ptr = allocate_two_d <int> (size);

    //Initializing the array to the same value
    cout << "Initializing the array to all 0s" << endl;
    init_two_d(two_d_ptr, size, 0);
    print_two_d(two_d_ptr, size);

    //Initializing the array to a pattern with increment of 1 per row and increment of 10 per column
    cout << endl << "Initializing the array to 0, 1, 2, 3....." << endl;
    init_debug(two_d_ptr, size);
    print_two_d(two_d_ptr, size);

    //Tesing the read functions to read a number in the array (Valid)
    int value;
    cout << endl << "Reading value of third row and second element --> 21" << endl;
    value = read<int>(two_d_ptr, 2, 1, size);
    cout << "value = " << value << endl;

    /*
    //Tesing the read functions to read a number in the array (Not valid)
    cout << endl << "Reading value of fifth row and third element --> row not valid" << endl;
    value = read<int>(two_d_ptr, 4, 2, size);
    cout << "value = " << value << endl;

     //Tesing the read functions to read a number in the array (Not valid)
    cout << endl << "Reading value of fourth row and ninth element --> Column not valid" << endl;
    value = read<int>(two_d_ptr, 4, 8, size);
    cout << "value = " << value << endl;
     */

    //Write 60 to the second row and third element
    cout << endl << "Write 60 to the second row and third element" << endl;
    write(two_d_ptr, 1, 2, 60, size);
    print_two_d(two_d_ptr, size);


    /*
    //Write 100 to the sixth row and third element (Not Valid)
    cout << endl << "Write 100 to the sixth row and third element --> Row not valid" << endl;
    write(two_d_ptr, 5, 2, 100, size);
    print_two_d(two_d_ptr, size);

    //Write 100 to the first row and tenth element (Not Valid)
    cout << endl << "Write 100 to the first row and tenth element --> Column not valid" << endl;
    write(two_d_ptr, 0, 9, 100, size);
    print_two_d(two_d_ptr, size);
     */

    //Search a number in the array
    cout << endl << "Search the value 13 in the array using call by value search function" << endl;
    if(search_two_d(two_d_ptr, 13, size) != nullptr)
    {
        cout << "Search complete" << endl;
    }

    //Search a number in the array
    cout << endl << "Search the value 13 in the array using boolean search function" << endl;
    int row = 0;
    int column = 0;
    if(search_two_d(two_d_ptr, 13, size, row, column))
    {
        cout << "Search complete, writing 50 to the position found" << endl;
        write(two_d_ptr, row, column, 50, size);
        print_two_d(two_d_ptr, size);
    }

    //Deallocate the 2D array
    cout << endl << "Deleting the 2D array" << endl;
    deallocate(two_d_ptr, size);
    cout <<"2D array deleted" << endl;
}
