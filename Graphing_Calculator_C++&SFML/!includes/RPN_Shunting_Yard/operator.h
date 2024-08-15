#ifndef OPERATOR_H
#define OPERATOR_H

#include "../RPN_Shunting_Yard/token.h"
#include <string>
#include <cmath>

using namespace std;

class Operator : public Token
{
public:
    Operator(string op);
    int type();
    void print();
    int prec();
    int get_prec();
    string op();
    double calculation(double left, double right);

private:
    int _prec;
    string _operator;
};

#endif // OPERATOR_H
