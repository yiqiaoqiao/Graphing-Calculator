#include "tokenizer.h"

Tokenizer::Tokenizer()
{
    //DO NOTHING
}

Tokenizer::Tokenizer(string eqn)
{
    _equation = strtok(&eqn.front(), " ");
    _infix = find_infix();
}

Tokenizer::Tokenizer(char* eqn): _equation(eqn)
{
    _infix = find_infix();
}

void Tokenizer::set_eqn(string eqn)
{
    _equation = strtok(&eqn.front(), " ");
    _infix = find_infix();
}

Queue<Token*> Tokenizer::find_infix()
{
    //Website: https://en.cppreference.com/w/cpp/string/byte/strtok
    char* eqn_walker = _equation;
    while(eqn_walker != NULL) {
        if(*eqn_walker == '(')
            _infix.push(new L_paren());
        else if(*eqn_walker == ')')
            _infix.push(new R_paren());
        else if(isdigit(*eqn_walker))
            _infix.push(new Number(atof(eqn_walker)));
        else if(*eqn_walker == ')')
            _infix.push(new R_paren());
        else if(*eqn_walker == '+' || *eqn_walker == '-' || *eqn_walker == '*' ||
                *eqn_walker == '/' || *eqn_walker == '^')
            _infix.push(new Operator(eqn_walker));
        else if(*eqn_walker == 'x')
            _infix.push(new Variable("x"));
        else
            _infix.push(new Function(eqn_walker));
        eqn_walker = strtok(NULL, " ");
    }
    return _infix;
}

Queue<Token*> Tokenizer::get_infix()
{
    return _infix;
}

ostream& operator << (ostream& outs, Queue<Token*> infix)
{
    for(Queue<Token*>::Iterator it = infix.Begin(); it != infix.End(); it++)
    {
        (*it)->print();
        cout << " ";
    }
    outs << endl;
    return outs;
}
