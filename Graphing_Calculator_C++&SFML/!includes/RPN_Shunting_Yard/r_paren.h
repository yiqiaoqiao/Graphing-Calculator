#ifndef R_PAREN_H
#define R_PAREN_H
#include "../RPN_Shunting_Yard/token.h"

class R_paren : public Token
{
public:
    R_paren();
    int type();
    void print();
};

#endif // R_PAREN_H
