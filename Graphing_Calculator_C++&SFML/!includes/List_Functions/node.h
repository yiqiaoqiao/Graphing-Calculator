#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
struct node{
    T _item;
    node<T>* _next;
    node(const T& item = T(), node<T>* next = nullptr): _item(item), _next(next){/*Do nothing*/}
    friend ostream& operator << (ostream& outs, const node<T> n)
    {
        outs << "[" << n._item << "]->";
        return outs;
    }
};

template<typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item);    //insert at the head of list

template<typename T>
node<T>* _insert_after(node<T>*& head_ptr, node<T>* afterThis, const T& insertThis);    //insert after ptr

template<typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs = cout);

template<typename T>
node<T>* _search(node<T>* head_ptr, const T& key);     //return ptr to key or NULL

template<typename T>
node<T>* _next(node<T>* next_to_this);    //ptr to next node

template<typename T>
node<T>* _previous(node<T>* head_ptr, node<T>* previous_to_this);   //ptr to previous node

template <typename T>
void _printList_backwards(node<T> *head);            //recursive fun! :)

template <typename T>
node<T>* _insert_before(node<T>*& head, node<T>* beforeThis, T insertThis);    //insert before ptr

template <typename T>
T _delete_node(node<T>*& head, node<T>* deleteThis);    //delete, return item

template <typename T>
node<T>* _copy_list(node<T>* head);           //duplicate the list...

template <typename T>
void _clear_list(node<T>*& head);                     //delete all the nodes

template <typename T>
T& _at(node<T>* head, int pos);              //_item at this position

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
node<T>* _insert_sorted(node<T>* &head,       //insert
                                  T item,
                                  bool ascending=true);

template <typename T>
node<T>* _insert_sorted_add(node<T>* &head, T item, bool ascending = true);

template <typename T>
node<T>* _where_this_goes(node<T>* head,         //node after which this
                               T item,                //    item goes
                               bool ascending=true);          //order: 0 ascending

template <typename T>
node<T>* _last_node(node<T>* head);            //Last Node in the list

//=====================================================================================

template<typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item){
    //insert the item at the head of the list: make it the first j
    //      link in the chain.

    //1: create a new node:
    node<T>* temp = new node<T>(item);

    //2. point (the next field of) this new node to where head is pointing to
    temp->_next = head_ptr;

    //3. point head to this new node:
    head_ptr = temp;

    return head_ptr;
}

template<typename T>
node<T>* _insert_after(node<T>*& head_ptr, node<T>* afterThis, const T& insertThis)
{
    //Check for head_ptr
    if(head_ptr == nullptr)
    {
        return _insert_head(head_ptr, insertThis);
    }

    //1. create a new node:
    node<T>* temp = new node<T>(insertThis);

    //2. this temp's next node should be mark's next position
    temp-> _next = afterThis->_next;

    //3. then mark's next should point at the temp's address
    afterThis->_next = temp;

    return temp;
}

template <typename T>
node<T>* _insert_before(node<T>*& head, node<T>* beforeThis, T insertThis)
{
    //Check for head ptr
    if(head == nullptr)
    {
        return _insert_head(head, insertThis);
    }

    //1. Check for head_ptr condition
    if(beforeThis == head)
    {
        node<T>* temp = new node<T>(insertThis);

        //Set the temp next to head ptr to create link list before head
        temp ->_next = head;

        //Set the head to the temp ---- new head
        head = temp;
        return temp;
    }

    //2. Find where this new node be next to
    node<T>* afterThis = _previous(head, beforeThis);

    //3. Set the temp after the afterThis node
    _insert_after(head, afterThis, insertThis);

    return afterThis->_next;
}

template<typename T>
node<T>* _search(node<T>* head_ptr, const T& key)
{
    node<T>* w = head_ptr;
    //Check if head ptr is null ptr
    if(head_ptr == nullptr)
        return nullptr;
    //Search until finds it
    while(w != nullptr)
    {
        if(w -> _item == key)
        {
            return w;
        }
        w = w ->_next;
    }
    w = nullptr;
    return w;    
}

template<typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs){
    outs<<"H->";
    for (node<T>* w = head_ptr; w!=nullptr; w =w->_next){
        outs<<*w;
    }
    outs<<"|||";
    return outs;
}

template <typename T>
void _printList_backwards(node<T>* head)
{
    node<T>* temp = head;
    //The bottom condition
    if(temp == nullptr)
    {
        cout << "H->";
        return;
    }
    else{
        _printList_backwards(temp -> _next);
    }
    cout << *temp;
}

template<typename T>
node<T>* _next(node<T>* next_to_this)
{
    node<T>* next = next_to_this ->_next;
    return next;
}

template<typename T>
node<T>* _previous(node<T>* head_ptr, node<T>* previous_to_this)
{
    //Check if previous_to_this is the head_ptr
    if(previous_to_this == head_ptr)
        return head_ptr;
    node<T>* temp = head_ptr;
    while (temp != nullptr) {
        if(temp ->_next == previous_to_this)
            break;
        temp = temp -> _next;
    }
    return temp;
}

template <typename T>
T _delete_node(node<T>*& head, node<T>* deleteThis)
{
    assert(head != nullptr);
    T item = T();
    node<T>* temp;
    //Check if deleteThis is the same as head
    if(deleteThis == head)
    {
        item = head->_item;
        temp = head;
        head = head ->_next;
        delete temp;
        return item;
    }

    temp = head;
    while (temp != nullptr)
    {
        //If temp's next is delete this, set delete this next to temp's next so you skip delete this.
        if(temp->_next == deleteThis)
        {
            //Get the item
            item = deleteThis->_item;
            temp->_next = deleteThis->_next;
            //Delete this dynamic pointer
            delete deleteThis;
            break;
        }
        temp = temp->_next;
    }
    return item;
}

template <typename T>
node<T>* _copy_list(node<T>* head)
{
    //Check for head ptr
    if(head == nullptr)
        return nullptr;

    //1. Create node temp
    node<T>* temp = head;
    temp = temp->_next;

    //2. Create head copy
    node<T>* head_copy = new node<T>(head->_item);

    //3. Create head_copy_temp
    node<T>* head_copy_Temp = head_copy;
    //head_copy_Temp = head_copy_Temp->_next;

    //4. For every temp next, save it into head_copy
    while(temp != nullptr)
    {
        //5. Insert the item after the head_copy_temp
        _insert_after(head_copy, head_copy_Temp, temp->_item);

        //6. Get the address of next link list
        head_copy_Temp = head_copy_Temp->_next;
        temp = temp->_next;
    }

    return head_copy;
}

template <typename T>
void _clear_list(node<T>*& head)
{
    while (head != nullptr) {
        _delete_node(head, head);
    }
}

template <typename T>
T& _at(node<T>* head, int pos)
{
    //assume position start with 0
    node<T>* temp = head;
    for(int i = 0; i < pos; i++)
    {
        temp = temp->_next;
    }
    return temp->_item;
}

template <typename T>
node<T>* _insert_sorted(node<T>* &head, T item, bool ascending)
{
    //Check if head is null
    if(head == nullptr)
    {
        return _insert_head(head, item);
    }

    //Check if should insert before head
    if(ascending)
    {
        if(item < head->_item)
        {
            node<T>* insert_node = _insert_before(head, head, item);
            //cout << "Smaller than head ptr" << endl;
            return insert_node;
        }
    }
    if(!ascending)
    {
        if(item > head->_item)
        {
            node<T>* insert_node = _insert_before(head, head, item);
            //cout << "Bigger than head ptr" << endl;
            return insert_node;
        }
    }
    //Give head, insert the item and return the insert position
    node<T>* insert_position = _where_this_goes(head, item, ascending);
    node<T>* insert_node = _insert_after(head, insert_position, item);
        //cout << "insertNode: " << insert_node->_item << endl;
    return insert_node;
}

template <typename T>
node<T>* _insert_sorted_add(node<T>*& head, T item, bool ascending)
{
    //See if you can find the item
    node<T>* position = _search(head, item);

    //If find the item, then add the item up
    if(position != nullptr)
    {
        position->_item = position->_item + item;
        return position;
    }
    return _insert_sorted(head, item, ascending);
}

template <typename T>
node<T>* _where_this_goes(node<T>* head, T item, bool ascending)
{
    //Will always return follower not the walker
    node<T>* follower = head;
    node<T>* walker = follower->_next;

    //Two condition: ascending and descending
    if(ascending)
    {
        //If it is acending, the walker item should be < than the item
        while (walker != nullptr && walker->_item < item)
        {
            //Keep updating both walker
            follower = follower->_next;
            walker = walker->_next;
        }
    }
    else
    {
        //Opposite of ascending
        while (walker != nullptr && walker->_item > item)
        {
            //Keep updating both walker
            follower = follower->_next;
            walker = walker->_next;
        }
    }

    //Return the first pointer
        //cout << "Goes after " << follower->_item << endl;
    return follower;
}

template <typename T>
node<T>* _last_node(node<T>* head)
{
    //Check for head ptr
    if(head == nullptr)
        return nullptr;

    //Keep going through the walker and find the last position
    node<T>* temp = head;
    node<T>* last_node;
    while (temp != nullptr) {
        last_node = temp;
        temp = temp ->_next;
    }
    return last_node;
}

//----------------------------- Sorted List ----------------------------------


#endif // NODE_H
