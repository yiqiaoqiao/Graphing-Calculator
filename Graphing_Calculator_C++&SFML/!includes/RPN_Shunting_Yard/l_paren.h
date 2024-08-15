#ifndef L_PAREN_H
#define L_PAREN_H
#include "../RPN_Shunting_Yard/token.h"

class L_paren : public Token
{
public:
    L_paren();
    int type();
    void print();
};

#endif // L_PAREN_H
