#ifndef VARIABLE_H
#define VARIABLE_H
#include "../../!includes/RPN_Shunting_Yard/token.h"
#include <string>
#include <iostream>

using namespace std;

class Variable : public Token
{
public:
    Variable(string variable);
    int type();
    void print();

private:
    string _variable;
};

#endif // VARIABLE_H
