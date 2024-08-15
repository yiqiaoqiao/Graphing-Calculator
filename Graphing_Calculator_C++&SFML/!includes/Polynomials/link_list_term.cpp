#include "link_list_term.h"
#include<cmath>
#include<cassert>
#include<iomanip>
using namespace std;

Term::Term(): _coef(0), _exp(0)
{
    //Do nothing
}

Term::Term(double coef, int exp): _coef(coef), _exp(exp)
{
    //Do nothing
}

//Compund Assignment
Term& Term::operator +=(const Term& rhs)
{
    assert(_exp == rhs._exp);
    _coef = _coef + rhs._coef;
    return *this;
}

Term& Term::operator -=(const Term& rhs)
{
    assert(_exp == rhs._exp);
    _coef = _coef - rhs._coef;
    return *this;
}

Term& Term::operator *=(const Term& rhs)
{
    _exp = _exp + rhs._exp;
    _coef = _coef * rhs._coef;
    return *this;
}

Term& Term::operator /=(const Term& rhs)
{
    _exp = _exp - rhs._exp;
    _coef = _coef / rhs._coef;
    return *this;
}

//Comparing operators
bool operator ==(const Term& lhs, const Term& rhs)
{
    //ONLY LOOK FOR EXP!!!
    if(lhs._exp != rhs._exp)
        return false;
    return true;
}

bool operator !=(const Term& lhs, const Term& rhs)
{
    return (!(lhs == rhs));
}

bool operator >(const Term& lhs, const Term& rhs)
{
    if(lhs._exp > rhs._exp)
        return true;
    return false;
}

bool operator <(const Term& lhs, const Term& rhs)
{
    if(lhs._exp < rhs._exp)
        return true;
    return false;
}

//Unary operator
Term Term::operator -() const
{
    //Negative coef
    double neg_coef = -1*(_coef);
    return Term(neg_coef, _exp);
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
    Term result = lhs;
    result *= rhs;
    return result;
    /*
    if(lhs._coef == 0 || rhs._coef == 0)
    {
        Term result(0,0);
    }
    double coef = lhs._coef * rhs._coef;
    int exp = lhs._exp + rhs._exp;
    Term result(coef, exp);
    return result;
    */
}

Term operator / (const Term& lhs, const Term& rhs)
{
    Term result = lhs;
    result /= rhs;
    return result;
    /*
    double coef = lhs._coef / rhs._coef;
    int exp = lhs._exp - rhs._exp;
    Term result(coef, exp);
    return result;
    */
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

