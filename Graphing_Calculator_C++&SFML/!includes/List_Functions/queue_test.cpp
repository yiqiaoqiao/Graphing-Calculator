#include "queue_test.h"
#include "../../!includes/List_Functions/queue.h"
#include <iostream>
#include <string>

using namespace std;

Queue<int> _queue_one()
{
    Queue<int> queue;
    queue.push(2);
    queue.push(3);
    queue.push(4);
    return queue;
}

Queue<char> _queue_two()
{
    Queue<char> queue;
    queue.push('a');
    queue.push('b');
    queue.push('c');
    return queue;
}

Queue<string> _queue_three()
{
    Queue<string> queue;
    queue.push("World");
    queue.push("Hello");
    return queue;
}

void _queue_test_push()
{
    cout << "-------------------- Testing Push ----------------" << endl;
    cout << "------------ Test 1 ------------" << endl;
    Queue<int> queue;
    queue.push(2);
    cout << queue << endl;
    queue.push(3);
    cout << queue << endl;
    queue.push(4);;
    cout << queue;
    cout << endl;

    cout << "------------ Test 2 ------------" << endl;
    Queue<char> queue_two;
    queue_two.push('a');
    cout << queue_two << endl;
    queue_two.push('b');
    cout << queue_two << endl;
    queue_two.push('c');
    cout << queue_two << endl;

    cout << "------------ Test 3 ------------" << endl;
    Queue<string> queue_three;
    queue_three.push("World");
    cout << queue_three << endl;
    queue_three.push("Hello");
    cout << queue_three << endl;
    cout << endl << endl << endl;
}

void _queue_test_pop()
{
    cout << "-------------------- Testing Pop ----------------" << endl;
    cout << "------------ Test 1 ------------" << endl;
    Queue<int> queue = _queue_one();
    cout << queue << endl;
    queue.pop();
    cout << queue << endl;
    queue.pop();
    cout << queue << endl;
    queue.pop();
    cout << queue << endl;

    cout << "------------ Test 2 ------------" << endl;
    Queue<char> queue_two = _queue_two();
    cout << queue_two << endl;
    queue_two.pop();
    cout << queue_two << endl;
    queue_two.pop();
    cout << queue_two << endl;
    queue_two.pop();
    cout << queue_two << endl;

    cout << "------------ Test 3 ------------" << endl;
    Queue<string> queue_three = _queue_three();
    cout << queue_three << endl;
    queue_three.pop();
    cout << queue_three << endl;
    queue_three.pop();
    cout << queue_three << endl << endl << endl;
}

void _queue_test_top()
{
    cout << "-------------------- Testing Front ----------------" << endl;
    cout << "------------ Test 1 ------------" << endl;
    Queue<int> queue = _queue_one();
    cout << queue;
    cout << endl << "This queue front: " << queue.front();
    cout << endl;

    cout << "------------ Test 2 ------------" << endl;
    Queue<char> queue_two = _queue_two();
    cout << queue_two;
    cout << endl << "This queue front: " << queue_two.front();
    cout << endl;

    cout << "------------ Test 3 ------------" << endl;
    Queue<string> queue_three = _queue_three();
    cout << queue_three;
    cout << endl << "This stack front: " << queue_three.front();
    cout << endl << endl << endl;
}

void _test_queue_big_three()
{
    cout << "-------------------- Testing Big Three ----------------" << endl;
    Queue<int> queue = _queue_one();
    cout << queue;
    cout << endl << "----------- Testing Copy CTOR ----------" << endl;
    Queue<int> queue_two(queue);
    cout << queue_two;
    cout << endl << "----------- Testing Assignment Operator ----------" << endl;
    Queue<int> queue_three = queue;
    cout << queue_three;
    cout << endl;
}

void _test_queue()
{
    _queue_test_push();
    _queue_test_pop();
    _queue_test_top();
    _test_queue_big_three();
}
