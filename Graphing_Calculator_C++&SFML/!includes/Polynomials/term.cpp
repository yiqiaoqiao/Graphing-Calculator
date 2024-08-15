#include "term.h"
#include<cmath>
#include<cassert>
#include<iomanip>
using namespace std;
const double EPSILON = 0.001;

Term::Term(): _coef(0), _exp(0)
{
    //Do nothing
}

Term::Term(double coef, int exp): _coef(coef), _exp(exp)
{
    //Do nothing
}

//Comparing operators
bool operator ==(const Term& lhs, const Term& rhs)
{
    assert(lhs._exp == rhs._exp);
    return (fabs(lhs._coef - rhs._coef) < EPSILON);
}

bool operator !=(const Term& lhs, const Term& rhs)
{
    return (!(lhs == rhs));
}

bool operator >(const Term& lhs, const Term& rhs)
{
    if(lhs._exp > rhs._exp)
        return true;
    else if ((lhs._exp == rhs._exp) && (lhs._coef > rhs._coef))
        return true;
    else
        return false;
}

bool operator <(const Term& lhs, const Term& rhs)
{
    if(lhs._exp < rhs._exp)
        return true;
    else if ((lhs._exp == rhs._exp) && (lhs._coef < rhs._coef))
        return true;
    else
        return false;
}


//Calculation operators
Term operator + (const Term& lhs, const Term& rhs)
{
    assert(lhs._exp == rhs._exp);
    double coef = lhs._coef + rhs._coef;
    Term result(coef, lhs._exp);
    return result;
}

Term operator - (const Term& lhs, const Term& rhs)
{
    assert(lhs._exp == rhs._exp);
    double coef = lhs._coef - rhs._coef;
    Term result(coef, lhs._exp);
    return result;
}

Term operator * (const Term& lhs, const Term& rhs)
{
    if(lhs._coef == 0 || rhs._coef == 0)
    {
        Term result(0,0);
    }
    double coef = lhs._coef * rhs._coef;
    int exp = lhs._exp + rhs._exp;
    Term result(coef, exp);
    return result;
}

Term operator / (const Term& lhs, const Term& rhs)
{
    double coef = lhs._coef / rhs._coef;
    int exp = lhs._exp - rhs._exp;
    Term result(coef, exp);
    return result;
}

//Input & Output
ostream& operator <<(ostream& outs, const Term& t)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(1);
    if(t._coef != 0.0)
    {
        if(t._coef > 0)
            outs << "+";
        outs << t._coef;
        if(t._exp > 1)
            outs << "X^" << t._exp << " ";
        else if(t._exp == 1)
            outs << "X ";
    }
    return outs;
}

istream& operator >> (istream& ins, Term& t)
{
    //2 x2 +3 x4
    double coef = 0.0;
    char x = ' ';
    //char space = ' ';
    int exp = 0;
    ins >> coef >> x >> exp;
    Term new_t(coef, exp);
    t = new_t;
    return ins;
}
