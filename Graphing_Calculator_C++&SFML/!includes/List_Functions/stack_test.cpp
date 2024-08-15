#include "stack_test.h"
#include "../../!includes/List_Functions/stack.h"
#include <iostream>
#include <string>

using namespace std;

Stack<int> _stack_one()
{
    Stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(4);
    return stack;
}

Stack<char> _stack_two()
{
    Stack<char> stack;
    stack.push('a');
    stack.push('b');
    stack.push('c');
    return stack;
}

Stack<string> _stack_three()
{
    Stack<string> stack;
    stack.push("World");
    stack.push("Hello");
    return stack;
}

void _stack_test_push()
{
    cout << "-------------------- Testing Push ----------------" << endl;
    cout << "------------ Test 1 ------------" << endl;
    Stack<int> stack;
    stack.push(2);
    stack.print();
    cout << endl;
    stack.push(3);
    stack.print();
    cout << endl;
    stack.push(4);
    stack.print();
    cout << endl;

    cout << "------------ Test 2 ------------" << endl;
    Stack<char> stack_two;
    stack_two.push('a');
    stack_two.print();
    cout << endl;
    stack_two.push('b');
    stack_two.print();
    cout << endl;
    stack_two.push('c');
    stack_two.print();
    cout << endl;

    cout << "------------ Test 3 ------------" << endl;
    Stack<string> stack_three;
    stack_three.push("World");
    stack_three.print();
    cout << endl;
    stack_three.push("Hello");
    stack_three.print();
    cout << endl << endl << endl;
}

void _stack_test_pop()
{
    cout << "-------------------- Testing Pop ----------------" << endl;
    cout << "------------ Test 1 ------------" << endl;
    Stack<int> stack = _stack_one();
    stack.print();
    cout << endl;
    stack.pop();
    stack.print();
    cout << endl;
    stack.pop();
    stack.print();
    cout << endl;
    stack.pop();
    stack.print();
    cout << endl;

    cout << "------------ Test 2 ------------" << endl;
    Stack<char> stack_two = _stack_two();
    stack_two.print();
    cout << endl;
    stack_two.pop();
    stack_two.print();
    cout << endl;
    stack_two.pop();
    stack_two.print();
    cout << endl;
    stack_two.pop();
    stack_two.print();
    cout << endl;
    cout << endl;

    cout << "------------ Test 3 ------------" << endl;
    Stack<string> stack_three = _stack_three();
    stack_three.print();
    cout << endl;
    stack_three.pop();
    stack_three.print();
    cout << endl;
    stack_three.pop();
    stack_three.print();
    cout << endl << endl << endl;
}

void _stack_test_top()
{
    cout << "-------------------- Testing Top ----------------" << endl;
    cout << "------------ Test 1 ------------" << endl;
    Stack<int> stack = _stack_one();
    stack.print();
    cout << endl << "This stack top: " << stack.top();
    cout << endl;

    cout << "------------ Test 2 ------------" << endl;
    Stack<char> stack_two = _stack_two();
    stack_two.print();
    cout << endl << "This stack top: " << stack_two.top();
    cout << endl;

    cout << "------------ Test 3 ------------" << endl;
    Stack<string> stack_three = _stack_three();
    stack_three.print();
    cout << endl << "This stack top: " << stack_three.top();
    cout << endl << endl << endl;
}

void _test_stack_big_three()
{
    cout << "-------------------- Testing Big Three ----------------" << endl;
    Stack<int> stack = _stack_one();
    stack.print();
    cout << endl << "----------- Testing Copy CTOR ----------" << endl;
    Stack<int> stack_two(stack);
    stack_two.print();
    cout << endl << "----------- Testing Assignment Operator ----------" << endl;
    Stack<int> stack_three = stack;
    stack_three.print();
    cout << endl;
}

void _test_stack()
{
    _stack_test_push();
    _stack_test_pop();
    _stack_test_top();
    _test_stack_big_three();
}
