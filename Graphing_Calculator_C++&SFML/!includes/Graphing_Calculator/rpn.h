#ifndef RPN_H
#define RPN_H
#include "../../!includes/List_Functions/queue.h"
#include "../../!includes/List_Functions/stack.h"
#include "../../!includes/RPN_Shunting_Yard/token.h"
#include "../../!includes/RPN_Shunting_Yard/function.h"
#include "../../!includes/RPN_Shunting_Yard/number.h"
#include "../../!includes/RPN_Shunting_Yard/operator.h"
#include "../../!includes/RPN_Shunting_Yard/variable.h"
#include <cmath>
#include <cassert>

//y = x

class RPN
{
public:
    RPN(Queue<Token*> post_fix);
    double get_y(double x);
    double calculation(double left, double right, string op);
private:
    Queue<Token*> _post_fix;
};

#endif // RPN_H
