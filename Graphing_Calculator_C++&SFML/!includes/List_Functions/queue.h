#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include "../../!includes/List_Functions/iterator_list.h"

using namespace std;

template <class T>
class Queue{
public:
    //The nexted class is declared and defined inside the enclosing class declaration.
    class Iterator{
    public:
        friend class Queue;             //allow List to access private member of Iterator class

        Iterator()                      //default ctor
        {
            _ptr = nullptr;
        }

        Iterator(typename List<T>::Iterator p)            //ctor
        {
            _ptr = p;
        }

        bool is_null()                  //true if _ptr is NULL
        {
            return (_ptr == nullptr);
        }

        friend bool operator ==(const Iterator& left, const Iterator& right)    //true if left == right
        {
            return (left._ptr == right._ptr);
        }

        friend bool operator !=(const Iterator& left, const Iterator& right)    //true if left != right
        {
            return (!(left == right));
        }

        T& operator *()                 //dereference operator
        {
            assert(_ptr != nullptr);

            //returns the item in the list
            return *_ptr;
        }

        const T& operator *() const     //dereference operator
        {
            assert(_ptr != nullptr);

            //returns the item itself
            return *_ptr;
        }

        T* operator ->()                //member access operator
        {
            assert(_ptr != nullptr);

            //return the address of the item
            return _ptr;
        }

        const T* operator ->() const    //member access operator
        {
            assert(_ptr != nullptr);

            //return the address of the item
            return _ptr;
        }

        T& operator[] (int index)       //Return the item at the index
        {
            assert(index >= 0);

            //Same as at function in node
            return _at(_ptr, index);
        }

        friend Iterator operator ++(Iterator& it, int unused)   //it++
        {
            //First create temp that will save the address of it
            Iterator temp = it;

            //Then add the it ptr (++it)
            ++it;

            //Return the temp because it++ returns the ptr before adds
            return temp;
        }

        Iterator& operator++()          //++it
        {
            _ptr++;
            return *this;
        }

    private:
        typename List<T>::Iterator _ptr;
    };

    //Functions:
    Queue();                                //ctor

    //Big three
    Queue(const Queue<T>& copy_this);       //Copy ctor
    Queue& operator =(const Queue& RHS);    //Assignment operator
    ~Queue();                               //Destructor

    void push(const T& item);               //Push at the front
    T pop();                                //Pop at the front
    bool empty() const;                     //True if the list is empty
    T front() const;                   //Return the top iterator

    Iterator Begin();
    Iterator End();

    template<typename U>
    friend ostream& operator << (ostream& outs, const Queue<U>& queue);

private:
    List<T> _queue;
    typename List<T>::Iterator _rear;
};

//============================ FXN DEFINITION ==========================
template <class T>
Queue<T>::Queue():_rear(_queue.LastNode())
{
    _queue = List<T>();
}

template <class T>
Queue<T>::Queue(const Queue<T>& copy_this)
{
    _queue = List<T>(copy_this._queue);
    _rear = copy_this._rear;
}

template <class T>
Queue<T>& Queue<T>::operator =(const Queue& RHS)
{
    // 1. check for self-reference
    if(this == &RHS){
        return *this;
    }

    //2. deallocate existing space
    _queue.clear();

    //3. allocate space for new array
    //No need in this class

    //4. copy everything over
    _queue = RHS._queue;
    _rear = RHS._rear;

    //5. return this object
    return *this;
}

template <class T>
Queue<T>::~Queue()
{
    /*
    const bool debug = true;
    if(debug)
    {
        cout << "~Vector: ";
        _print_list(_head, cout);
        cout << endl;
    }
    */
    _queue.clear();
}

template <class T>
void Queue<T>::push(const T& item)
{
    //Set rear
    _queue.InsertAfter(item, _rear);
    _rear = _queue.LastNode();
}

template <class T>
T Queue<T>::pop()
{
    //No need to set rear because pop in the front
    return (_queue.Delete(_queue.Begin()));
}

template <class T>
bool Queue<T>::empty() const
{
    return (_queue.Begin().is_null());
}

template <class T>
T Queue<T>::front() const
{
    return *(_queue.Begin());
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Begin()
{
    return Iterator(_queue.Begin());
}

template <class T>
typename Queue<T>::Iterator Queue<T>::End()
{
    return Iterator(_queue.End());
}

template <class U>
ostream& operator << (ostream& outs, const Queue<U>& queue)
{
    queue._queue.Print();
    return outs;
}
#endif // QUEUE_H
