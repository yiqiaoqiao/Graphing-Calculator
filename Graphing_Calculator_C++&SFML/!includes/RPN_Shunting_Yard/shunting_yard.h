#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "../../!includes/List_Functions/queue.h"
#include "../../!includes/List_Functions/stack.h"
#include "../../!includes/RPN_Shunting_Yard/token.h"
#include "../../!includes/RPN_Shunting_Yard/variable.h"
#include "../../!includes/RPN_Shunting_Yard/operator.h"

class Shunting_yard
{
public:
    Shunting_yard();
    Shunting_yard(Queue<Token*> infix);
    Queue<Token*> get_postfix();
    friend ostream& operator << (ostream& outs, const Shunting_yard& sy);

private:
    Queue<Token*> _infix;
    Queue<Token*> _postfix;
    Queue<Token*> post_fix();
};

#endif // SHUNTING_YARD_H
