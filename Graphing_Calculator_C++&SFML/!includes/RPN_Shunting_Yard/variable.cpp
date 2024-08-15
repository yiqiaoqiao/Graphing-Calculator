#include "variable.h"

Variable::Variable(string variable): _variable(variable)
{
    //DO NOTHING
}

int Variable::type()
{
    return 5;
}

void Variable::print()
{
    cout << _variable;
}
