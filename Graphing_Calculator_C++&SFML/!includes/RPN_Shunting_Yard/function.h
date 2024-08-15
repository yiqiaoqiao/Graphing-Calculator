#ifndef FUNCTION_H
#define FUNCTION_H
#include "../../!includes/RPN_Shunting_Yard/operator.h"
#include <cmath>
#include <cassert>

class Function : public Operator
{
public:
    Function(string func);
    int type();
    double calculation(double number);
};

#endif // FUNCTION_H
