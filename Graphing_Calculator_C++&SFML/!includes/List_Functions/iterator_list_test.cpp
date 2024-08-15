#include "iterator_list_test.h"
#include "../List_Functions/iterator_list.h"

List<int> _get_list1()
{
    List<int> list;
    for (int i=0; i<10; i++){
        //List: 9, 8, .....0
        list.InsertHead(i*10);
    }
    return list;
}

List<int> _get_list2(){
    List<int> list;
    for (int i=9; i>=0; i--){
        //List: 0, 10, 20....90
        list.InsertHead(i*10);
    }
    return list;
}

void _test_insert_head(){
    cout << "----------- Test Insert Head -------------\n";
    List<int> list = _get_list1();
    list.Print();
    list.clear();
    cout<<endl<<endl;
}

void _test_insert_after()
{
    cout << "----------- Test Insert After -------------\n";

    List<int> list;
    list.InsertHead(1);
    List<int>::Iterator insert_here = list.Begin();
    for(int i = 90; i < 100; i++)
    {
        list.InsertAfter(i, insert_here);
        insert_here = list.Search(i);
    }
    list.Print();
    list.clear();
    cout<<endl<<endl;
}

void _test_next()
{
    cout << "----------- Test Next -------------\n";
    List<int> list = _get_list1();
    list.Print();
    cout << endl;

    cout << "The number next to 70 is ";
    cout << *list.Next(list.Search(70));
    list.clear();
    cout << endl << endl;
}

void _test_previous()
{
    cout << "----------- Test Previous -------------\n";
    List<int> list = _get_list1();
    list.Print();
    cout << endl;

    cout << "The number previous to 7 is ";
    cout << *list.Prev(list.Search(7));
    cout << endl;

    //Check the head consition:
    cout << "The number previous to 9 is ";
    cout << *list.Prev(list.Search(9));
    list.clear();
    cout << endl << endl;
}

void _test_insert_before()
{
    cout << "----------- Test Insert Before -------------\n";
    List<int> list = _get_list1();
    list.Print();

    cout << endl<< "Insert 11 before number 7\n";
    list.InsertBefore(11, list.Search(7));
    list.Print();
    cout << endl << endl;

    //Check the head condition:
    cout << "Insert 70 before number 9\n";
    list.InsertBefore(70, list.Search(9));
    list.Print();
    list.clear();
    cout << endl << endl;
}

void _test_delete()
{
    cout << "----------- Test delete -------------\n";
    List<int> list = _get_list2();
    list.Print();

    cout << endl << "Delete number 20\n";
    list.Delete(list.Search(20));
    list.Print();

    //Check the head condition:
    cout << endl << "Delete number 90\n";
    list.Delete(list.Search(90));
    list.Print();
    list.clear();
    cout << endl << endl;
}

void _test_at()
{
    cout << "----------- Test [] -------------\n";
    List<int> list = _get_list1();
    list.Print();

    int item = list[3];
        //cout << endl << item << endl;
    cout << endl << "Item at position 3 is " << item;
    list.clear();
    cout << endl << endl;
}

void _test_begin_end()
{
    cout << "----------- Test Begin End -------------\n";
    List<int> list = _get_list1();
    list.Print();
    cout << endl << "First element is: " << *list.Begin();
    cout << endl << "Last element is: " << *list.End();
    cout << endl << endl;
}

void _test_big_three()
{
    cout<< "========================= Test Big 3 =========================" << endl;
        List<int> list = _get_list1();
        cout << "List: " << list << endl;

        cout << "------------- Copy CTOR -----------" << endl;
        List<int> list2(list);
        cout << "List 2: " << list2 << endl;

        cout << "------------- Assignment Operator -----------" << endl;
        List<int> list3 = list;
        cout << "List 3: " << list3 << endl;
        cout << endl << endl;
}

void _test_iterated_list()
{
    _test_insert_head();
    _test_insert_after();
    _test_delete();
    _test_next();
    _test_previous();
    _test_insert_before();
    _test_begin_end();
    _test_at();
    _test_big_three();
}
