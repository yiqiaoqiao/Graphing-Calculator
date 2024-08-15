#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "../../!includes/RPN_Shunting_Yard/token.h"
#include "../../!includes/RPN_Shunting_Yard/function.h"
#include "../../!includes/RPN_Shunting_Yard/l_paren.h"
#include "../../!includes/RPN_Shunting_Yard/number.h"
#include "../../!includes/RPN_Shunting_Yard/operator.h"
#include "../../!includes/RPN_Shunting_Yard/r_paren.h"
#include "../../!includes/RPN_Shunting_Yard/variable.h"
#include "../../!includes/List_Functions/queue.h"

using namespace std;

class Tokenizer
{
public:
    Tokenizer();
    Tokenizer(string eqn);
    Tokenizer(char* eqn);
    void set_eqn(string eqn);
    Queue<Token*> find_infix();
    Queue<Token*> get_infix();
    friend ostream& operator << (ostream& outs, Queue<Token*> infix);
private:
    char* _equation;
    Queue<Token*> _infix;
};

#endif // TOKENIZER_H
