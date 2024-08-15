#ifndef SORTED_LIST_TEST_H
#define SORTED_LIST_TEST_H

#include "../../!includes/List_Functions/sorted_list.h"
#include<iostream>
using namespace std;

List<int> list1();
void menu();
void choice_random(List<int>::Iterator& cursor, List<int>& list);
void choice_insert(List<int>::Iterator& cursor, List<int>& list, int item);
void choice_delete(List<int>::Iterator& cursor, List<int>& list);
void choice_search(List<int>::Iterator& cursor, List<int>& list, int item);
void choice_previous(List<int>::Iterator& cursor, List<int>& list);
void choice_next(List<int>::Iterator& cursor, List<int>& list);
void choice_home(List<int>::Iterator& cursor, List<int>& list);
void choice_end(List<int>::Iterator& cursor, List<int>& list);
void test();
void display_list(List<int>::Iterator& cursor, List<int>& list);
void choice_switch(List<int>::Iterator& cursor, List<int>& list, const char& choice);
void test_rest();

#endif // SORTED_LIST_TEST_H
