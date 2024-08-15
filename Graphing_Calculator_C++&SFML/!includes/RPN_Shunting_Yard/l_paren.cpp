#include "l_paren.h"
#include <iostream>

using namespace std;

L_paren::L_paren()
{
    //DO NOTHING
}

int L_paren::type()
{
    return 3;
}

void L_paren::print()
{
    cout << "(";
}
