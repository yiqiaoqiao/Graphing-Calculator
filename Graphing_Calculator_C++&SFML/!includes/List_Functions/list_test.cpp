#include "list_test.h"
#include "list_functions.h"
#include <iostream>
#include <ctime>
using namespace std;

List<int> list1()
{
    List<int> list;
    list.InsertHead(17);
    list.InsertHead(35);
    list.InsertHead(6);
    list.InsertHead(54);
    list.InsertHead(6);
    return list;
}

void menu()
{
    cout << "[R]andom [A]fter  [B]efore [D]elete [S]earch"
         << " [P]revious [N]ext  [H]ome  [E]nd "<<endl;
}

void choice_random(node<int>*& cursor, List<int>& list)
{
    srand(time(0));
    //random number from 0 - 100
    int number = (rand() % 100);
    cursor = list.InsertAfter(number, cursor);
}

void choice_after(node<int>*& cursor, List<int>& list, int item)
{
    cursor = list.InsertAfter(item, cursor);
}

void choice_before(node<int>*& cursor, List<int>& list, int item)
{
    cursor = list.InsertBefore(item, cursor);
}

void choice_delete(node<int>*& cursor, List<int>& list)
{
    //The head is null ptr, cursor is still null ptr
    if(list.Begin() != nullptr)
    {
        list.Delete(cursor);
        //Cursor goes to the beginning when delete
        cursor = list.Begin();
    }

}

void choice_search(node<int>*& cursor, List<int>& list, int item)
{
    //If search, set the cursor, otherwise cursor does not change
    node<int>* search_ptr = list.Search(item);
    if(search_ptr != nullptr)
    {
        cursor = search_ptr;
    }
}

void choice_previous(node<int>*& cursor, List<int>& list)
{
    //Check if the cursor is going to be before the head ptr
    if(cursor != list.Begin())
        cursor = list.Prev(cursor);
}

void choice_next(node<int>*& cursor, List<int>& list)
{
    //Check if the cursor is going to be after the end
    if(cursor != list.End())
        cursor = list.Next(cursor);
}

void choice_home(node<int>*& cursor, List<int>& list)
{
    //The head ptr
    cursor = list.Begin();
}

void choice_end(node<int>*& cursor, List<int>& list)
{
    //Last node
    cursor = list.End();
}

void choice_switch(node<int>*& cursor, List<int>& list, const char& choice)
{
    int item = 0;
    switch (choice) {
    case 'R':
        //Random
        choice_random(cursor, list);
        break;
    case 'A':
        //After
        cout << "?: ";
        cin >> item;
        choice_after(cursor, list, item);
        break;
    case 'B':
        //Before
        cout << "?: ";
        cin >> item;
        choice_before(cursor, list, item);
        break;
    case 'D':
        //Delete
        choice_delete(cursor, list);
        break;
    case 'S':
        //Search
        cout << "?: ";
        cin >> item;
        choice_search(cursor, list, item);
        break;
    case 'P':
        //Previous
        choice_previous(cursor, list);
        break;
    case 'N':
        //Next
        choice_next(cursor, list);
        break;
    case 'H':
        //Home
        choice_home(cursor, list);
        break;
    case 'E':
        //End
        choice_end(cursor, list);
        break;
    default:
        //Do nothing
        break;
    }
}

void test()
{
    cout << "=======================================" << endl;
    List<int> list = list1();
    char choice = ' ';

    //Set the cursor
    node<int>* cursor = list.Begin();

    //Start the test
    while (choice != 'x') {
        display_list(cursor, list);
        menu();
        cin >> choice;
        cout << endl;
        choice_switch(cursor, list, toupper(choice));
    }

    cout << "..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   .." << endl;
    cout << "---------- END ----------------" << endl;
}

void display_list(node<int>*& cursor, List<int>& list)
{
    node<int>* walker = list.Begin();
    cout << "..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   .." << endl;
    while (walker != nullptr) {
        if(cursor == walker)
            cout << "{" << walker->_item << "}";
        else
            cout << "[" << walker->_item << "]";
        cout << "->";
        walker = walker->_next;
    }
    cout << "|||" << endl;
}

void test_rest()
{
    cout<< "========================= Test Rest Functions =========================" << endl;
    List<int> list = list1();
    cout << "List: " << list << endl;

    cout << "------------- Copy CTOR -----------" << endl;
    List<int> list2(list);
    cout << "List 2: " << list2 << endl;

    cout << "------------- Assignment Operator -----------" << endl;
    List<int> list3 = list;
    cout << "List 3: " << list3 << endl;

    cout << "------------- [] Function -----------" << endl;
    cout << "Element at position 3: " << list[3] << endl << endl;
}
