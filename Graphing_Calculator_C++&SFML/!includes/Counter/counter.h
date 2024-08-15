#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
using namespace std;

class Counter
{
public:
    Counter();
    Counter(int number);
    void incr();
    void decr();
    void reset();
    void show();

    //Operators:
    friend Counter operator +(const Counter& left, const Counter& right);
    friend ostream& operator << (ostream& outs, const Counter& print_me);

private:
    int _count;
};

#endif // COUNTER_H
