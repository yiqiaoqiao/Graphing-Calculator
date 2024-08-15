#include "shunting_yard.h"

Shunting_yard::Shunting_yard(Queue<Token*> infix)
{
    _infix = infix;
    _postfix = post_fix();
}

Shunting_yard::Shunting_yard()
{
    _infix.push(new Variable("x"));
    _postfix = post_fix();
}

Queue<Token*> Shunting_yard::get_postfix()
{
    return _postfix;
}

Queue<Token*> Shunting_yard::post_fix()
{
    Queue<Token*> infix_copy = _infix;
    Stack<Token*> op;
    //Stack iterator
    Stack<Token*>::Iterator stack_it;
    //Queue iterator
    Queue<Token*>::Iterator queue_it;

    //While infix is not empty
    while (!infix_copy.empty()) {
        queue_it = infix_copy.Begin();
        stack_it = op.Begin();

        if((*queue_it)->type() == 1)
        {
            //cout << "1" << endl;
            //Number, add to post fix
            _postfix.push(*queue_it);
        }
        else if((*queue_it)->type() == 2 || (*queue_it)->type() == 6)
        {
            //cout << "2" << endl;
            //Operator
            //If stack is empty, just push
            if(op.empty())
            {
                //(*queue_it)->print();
                //cout << "pushed" << endl;
                op.push(*queue_it);
            }

            //Else check for the prec
            //If stack prec is bigger than queue prec
            //Pop it and put into post fix
            //Else push it into stack
            else
            {
                int stack_prec = static_cast<Operator*>(*stack_it)->get_prec();
                //cout << "Stack_prec: " << stack_prec << endl;
                int queue_prec = static_cast<Operator*>(*queue_it)->get_prec();
                //cout << "Queue_prec: " << queue_prec << endl;
                //Make sure if there's (), end this loop
                while (queue_prec <= stack_prec && (*stack_it)->type() != 3 && !op.empty()) {
                    Token* temp = op.pop();
                    //cout << "pop" << endl;
                    //temp->print();
                    //cout << endl;
                    _postfix.push(temp);
                    if(!op.empty())
                        stack_it = op.Begin();
                    stack_prec = static_cast<Operator*>(*stack_it)->get_prec();
                    queue_prec = static_cast<Operator*>(*queue_it)->get_prec();
                    //cout << "Stack_prec: " << stack_prec << endl;
                    //cout << "Queue_prec: " << queue_prec << endl;
                }

                //Push operator into op
                op.push(*queue_it);
            }
        }
        else if((*queue_it)->type() == 3)
        {
            //cout << "3" << endl;
            //(
            //(*queue_it)->print();
            //cout << " Added " << endl;
            op.push(*queue_it);
        }
        else if((*queue_it)->type() == 4)
        {
            //cout << "4" << endl;
            //)
            Token* temp = op.pop();
            //While it is not (, push all the operators into queue
            while (temp->type() != 3) {
                //cout << "temp: ";
                //temp->print();
                //cout << endl;
                /*
                if(op.empty())
                {
                    cout << "empty" << endl;
                    break;
                }
                */
                _postfix.push(temp);
                temp = op.pop();
            }
        }
        else if((*queue_it)->type() == 5)
        {
            //cout << "5" << endl;
            //Variable, add to post fix
            _postfix.push(*queue_it);
        }
        infix_copy.pop();
    }

    //Push rest into postfix
    while (!op.empty()) {
        //cout << "push " << endl;
        _postfix.push(op.pop());
    }
    return _postfix;
}

ostream& operator << (ostream& outs, const Shunting_yard& sy)
{
    Queue<Token*> infix = sy._infix;
    outs << "Infix: ";
    for(Queue<Token*>::Iterator it = infix.Begin(); it != infix.End(); it++)
    {
        (*it)->print();
        cout << " ";
    }
    outs << endl;

    Queue<Token*> postfix = sy._postfix;
    outs << "Postfix: ";
    for(Queue<Token*>::Iterator it = postfix.Begin(); it != postfix.End(); it++)
    {
        (*it)->print();
        cout << " ";
    }
    outs << endl;
    return outs;
}
