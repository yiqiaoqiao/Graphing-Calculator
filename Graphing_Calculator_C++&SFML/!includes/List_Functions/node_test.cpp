#include "node_test.h"

node<int>* _get_list1()
{
    node<int>* head_ptr=nullptr;
    for (int i=0; i<10; i++){
        //List: 9, 8, .....0
        _insert_head(head_ptr, i);
    }
    return head_ptr;
}

node<int>* _get_list2(){
    node<int>* head_ptr=nullptr;
    for (int i=9; i>=0; i--){
        //List: 0, 10, 20....90
        _insert_head(head_ptr, i*10);
    }
    return head_ptr;
}

void _test_insert_head(){
    cout << "----------- Test Insert Head -------------\n";
    node<int>* head_ptr = _get_list1();
    _print_list(head_ptr);
    _clear_list(head_ptr);
    cout<<endl<<endl;
}

void _test_insert_after()
{
    cout << "----------- Test Insert After -------------\n";

    node<int>* head_ptr = nullptr;
    for(int i = 90; i < 100; i++)
    {
        _insert_after(head_ptr, head_ptr, i);
    }
    _print_list(head_ptr);
    _clear_list(head_ptr);
    cout<<endl<<endl;
}

void _test_search()
{
    cout << "----------- Test Search -------------\n";

    node<int>* head_ptr = _get_list1();
    _print_list(head_ptr);
    cout << endl;
    cout << "Search 9..." << endl;
    if(_search(head_ptr, 9) != nullptr)
    {
        cout << "9 is in the link list " << endl;
    }
    _clear_list(head_ptr);
    cout<<endl<<endl;
}

void _test_next()
{
    cout << "----------- Test Next -------------\n";
    node<int>* head_ptr = _get_list1();
    _print_list(head_ptr);
    cout << endl;

    cout << "The number next to 7 is ";
    cout << _next(_search(head_ptr, 7)) ->_item;
    _clear_list(head_ptr);
    cout << endl << endl;
}

void _test_previous()
{
    cout << "----------- Test Previous -------------\n";
    node<int>* head_ptr = _get_list1();
    _print_list(head_ptr);
    cout << endl;

    cout << "The number previous to 7 is ";
    cout << _previous(head_ptr, _search(head_ptr, 7)) ->_item;
    cout << endl;

    //Check the head consition:
    cout << "The number previous to 9 is ";
    cout << _previous(head_ptr, _search(head_ptr, 9)) ->_item;
    _clear_list(head_ptr);
    cout << endl << endl;
}

void _test_printList_backwards()
{
    cout << "----------- Test Print List Backwards -------------\n";
    node<int>* head_ptr = _get_list1();
    _printList_backwards(head_ptr);
    cout << "|||";
    _clear_list(head_ptr);
    cout << endl << endl;
}

void _test_insert_before()
{
    cout << "----------- Test Insert Before -------------\n";
    node<int>* head_ptr = _get_list1();
    _print_list(head_ptr);

    cout << endl<< "Insert 11 before number 7\n";
    _insert_before(head_ptr, _search(head_ptr, 7), 11);
    _print_list(head_ptr);
    cout << endl << endl;

    //Check the head condition:
    cout << "Insert 70 before number 9\n";
    _insert_before(head_ptr, _search(head_ptr, 9), 70);
    _print_list(head_ptr);
    _clear_list(head_ptr);
    cout << endl << endl;
}

void _test_delete_node()
{
    cout << "----------- Test delete node -------------\n";
    node<int>* head_ptr = _get_list1();
    _print_list(head_ptr);

    cout << endl << "Delete number 7\n";
    _delete_node(head_ptr, _search(head_ptr, 7));
    _print_list(head_ptr);

    //Check the head condition:
    cout << endl << "Delete number 9\n";
    _delete_node(head_ptr, _search(head_ptr, 9));
    _print_list(head_ptr);
    _clear_list(head_ptr);
    cout << endl << endl;
}

void _test_copy_list()
{
    cout << "----------- Test Copy List -------------\n";
    node<int>* head_ptr = _get_list1();
    _print_list(head_ptr);

    cout << endl << "Copy Link List\n";
    node<int>* head_copy = _copy_list(head_ptr);
    _print_list(head_copy);
    _clear_list(head_ptr);
    cout << endl << endl;
}

void _test_at()
{
    cout << "----------- Test At -------------\n";
    node<int>* head_ptr = _get_list1();
    _print_list(head_ptr);

    int item = _at<int>(head_ptr, 3);
        //cout << endl << item << endl;
    cout << endl << "Item at position 3 is " << item;
    _clear_list(head_ptr);
    cout << endl << endl;
}

void _test_last_node()
{
    cout << "-------------- Test Last Node -----------\n";
    node<int>* head_ptr = _get_list2();
    _print_list(head_ptr);

    cout << endl << "Item at last: " << _last_node(head_ptr)->_item << endl;
    _clear_list(head_ptr);
    cout << endl << endl;
}

void _test_insert_sorted()
{
    cout << "-------------- Test Sorted -----------\n";
    node<int>* head_ptr = _get_list2();
    _print_list(head_ptr);

    cout << endl << "Insert 65\n";
    //List 2 is 90...0 so it's descending
    _insert_sorted(head_ptr, 65, true);
    _print_list(head_ptr);
    _clear_list(head_ptr);
    cout << endl << endl;
}

void _test_node()
{
    _test_insert_head();
    _test_insert_after();
    _test_search();
    _test_next();
    _test_previous();
    _test_printList_backwards();
    _test_insert_before();
    _test_delete_node();
    _test_copy_list();
    _test_at();
    _test_last_node();
    _test_insert_sorted();
}
