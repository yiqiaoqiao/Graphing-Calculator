#include "number.h"

#include <iostream>

using namespace std;

Number::Number(double num):_number(num)
{
    //DO NOTHING
}

int Number::type()
{
    return 1;
}

void Number::print()
{
    cout << _number;
}

double Number::number()
{
    return _number;
}
