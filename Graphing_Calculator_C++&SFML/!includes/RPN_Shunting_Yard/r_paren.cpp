#include "r_paren.h"

#include <iostream>

using namespace std;

R_paren::R_paren()
{
    //DO NOTHING
}

int R_paren::type()
{
    return 4;
}

void R_paren::print()
{
    cout << ")";
}
