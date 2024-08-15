#include "operator.h"
#include <iostream>
using namespace std;

Operator::Operator(string op):_operator(op)
{
    _prec = prec();
}

int Operator::type()
{
    return 2;
}

void Operator::print()
{
    cout << _operator;
}

int Operator::prec()
{
    if(_operator == "+" || _operator == "-")
        _prec = 1;
    else if(_operator == "*" || _operator == "/")
        _prec = 2;
    else if (_operator == "^") {
        _prec = 3;
    }

    //For function class
    else if(_operator == "cos" || _operator == "sin" || _operator == "tan" || _operator == "log")
        _prec = 4;

    else
        //default prec
        _prec = 1;
    return _prec;
}

int Operator::get_prec()
{
    return _prec;
}

string Operator::op()
{
    return _operator;
}

double Operator::calculation(double left, double right)
{
    if(_operator == "+")
        return (left + right);
    else if(_operator == "-")
        return (left - right);
    else if(_operator == "*")
        return (left * right);
    else if(_operator == "/")
        return (left / right);
    else if(_operator == "^")
        return (pow(left, right));
    //Else return -1
    return (-1);
}
