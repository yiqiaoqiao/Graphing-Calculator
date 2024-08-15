#include "token.h"
#include <iostream>

using namespace std;

Token::Token()
{
    //DO NOTHING
}

int Token::type()
{
    //1 is number
    //2 is operator
    //3 is left parenthesis
    //4 is right parenthesis
    //5 is variable
    //6 is function
    return 0;
}

void Token::print()
{
    cout << "T";
}
