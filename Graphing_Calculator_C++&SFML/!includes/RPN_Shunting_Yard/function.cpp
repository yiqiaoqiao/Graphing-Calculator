#include "function.h"

Function::Function(string func):Operator(func)
{
    //DO NOTHING
}

int Function::type()
{
    return 6;
}

double Function::calculation(double number)
{
    string op = Operator::op();
    if(op == "sin")
    {
        return sin(number);
    }
    else if(op == "cos")
        return cos(number);
    else if(op == "log")
    {
        //Can't be 0
        assert(number != 0);
        return log(number);
    }
    else if(op == "tan")
        return tan(number);
    return -1;
}

