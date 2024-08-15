#ifndef NUMBER_H
#define NUMBER_H

#include "../RPN_Shunting_Yard/token.h"

class Number : public Token
{
public:
    Number(double num);
    int type();
    void print();
    double number();
private:
    double _number;
};

#endif // NUMBER_H
