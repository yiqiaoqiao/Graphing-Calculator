#include "counter.h"
#include <iostream>
using namespace std;

Counter::Counter()
{
    reset();

}

Counter::Counter(int number)
{
    _count = number;
}

void Counter::show()
{
    cout << "[" << _count << "]" << endl;
}

void Counter::incr(){
    _count ++;
}

void Counter::decr(){
    _count --;
}

void Counter::reset()
{
    _count = 0;
}

//============Friend Operators====================

Counter operator +(const Counter& left, const Counter& right)
{
    //Take counts from left and right
    //Add them together
    //Build a counter object from it, and return it

    int sum = left._count + right._count;
    Counter c(sum);
    return c;

    //Or return Counter(sum)
}

ostream& operator << (ostream& outs, const Counter& print_me)
{
    outs << "[" << print_me._count << "]" << endl;
    return outs;
}
