#include "rpn.h"

RPN::RPN(Queue<Token*> post_fix):_post_fix(post_fix)
{
    //DO NOTHING
}

double RPN::get_y(double x)
{
    Queue<Token*> postfix_copy = _post_fix;
    Stack<Token*> number_stack;
    Token* left_num;
    Token* right_num;
    Token* temp;
    double num;

        //cout << "While loop " << endl;
    while(!postfix_copy.empty())
    {
        temp = postfix_copy.pop();
        //temp = postfix_copy.pop();
        switch(temp->type())
        {
        case 1:
            //Number
            number_stack.push(temp);
                //cout << "push " << temp << endl;
            break;
        case 5:
            //Variable
            number_stack.push(new Number(x));
                //cout << "Variable Push " << x << endl;
            /*
            if(number_stack.empty())
                cout << "NUMBER STACK EMPTY" << endl;
                */
            break;
        case 2:
            //Operator
            right_num = number_stack.pop();
            left_num = number_stack.pop();
            num = static_cast<Operator*>(temp)->calculation(static_cast<Number*>(left_num)->number(),
                                                                   static_cast<Number*>(right_num)->number());
            number_stack.push(new Number(num));
                //cout << "Operator: " << num << endl;
            break;
        case 6:
            //Function
            right_num = number_stack.pop();
            num = static_cast<Function*>(temp)->calculation(static_cast<Number*>(right_num)->number());
                //cout << "Function: " << num << endl;
            number_stack.push(new Number(num));
            break;
        }
    }

        //cout << "END OF WHILE LOOP " << endl;
    assert(!number_stack.empty());

    double result = static_cast<Number*>(number_stack.pop())->number();
    return result;
}


