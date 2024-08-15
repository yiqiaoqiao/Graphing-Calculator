#ifndef LIST_TEST_H
#define LIST_TEST_H

#include "list_functions.h"
#include<iostream>
using namespace std;

List<int> list1();
void menu();
void choice_random(node<int>*& cursor, List<int>& list);
void choice_after(node<int>*& cursor, List<int>& list, int item);
void choice_before(node<int>*& cursor, List<int>& list, int item);
void choice_delete(node<int>*& cursor, List<int>& list);
void choice_search(node<int>*& cursor, List<int>& list, int item);
void choice_previous(node<int>*& cursor, List<int>& list);
void choice_next(node<int>*& cursor, List<int>& list);
void choice_home(node<int>*& cursor, List<int>& list);
void choice_end(node<int>*& cursor, List<int>& list);
void test();
void display_list(node<int>*& cursor, List<int>& list);
void choice_switch(node<int>*& cursor, List<int>& list, const char& choice);
void test_rest();
#endif // LIST_TEST_H
