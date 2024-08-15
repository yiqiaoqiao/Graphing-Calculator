#include "link_list_poly.h"
#include <iostream>
#include "../../!includes/Polynomials/link_list_term.h"
#include "../../!includes/List_Functions/sorted_list.h"

using namespace std;

Poly::Poly()
{
    _poly = List<Term>(false, true);
}

Poly::Poly(List<Term> poly): _poly(poly)
{
    //DO NOTHING
}

Poly::Poly(double term_array[], int order)
{
    _poly = List<Term>(false, true);
    Poly answer;
    for(int i = 0; i <= order; i++)
    {
        Term t(term_array[i], i);
        answer += t;
    }
    _poly = answer._poly;
}

//------------------------------------ Comparing Operator -------------------------------------

bool operator == (const Poly& left, const Poly& right)
{
    //cout << "Checking == " << endl;
    //Save in iterator
    List<Term>::Iterator left_it = left._poly.Begin();
    List<Term>::Iterator right_it = right._poly.Begin();

    //Check for empty
    if(left_it.is_null() && right_it.is_null())
        return true;
    //If one is empty, then it's false -> Make sure both are not empty before checking others
    if(left_it.is_null() || right_it.is_null())
        return false;

    //Check for all the items in the poly
    while (left_it != left._poly.End() && right_it != right._poly.End()) {
        if(*left_it != *right_it)
            return false;
        left_it ++;
        right_it ++;
    }

    //Check if one iterator ends first, which means that one Poly is shorter than the other poly
    if(left_it != left._poly.End() || right_it != right._poly.End())
        return false;

    //Else it's true
    return true;
}

bool operator != (const Poly& left, const Poly& right)
{
    return (!(left == right));
}

//-------------------------------- Poly Term Calculation -----------------------------------------------

Poly& Poly::operator +=(const Term& t)
{
    _poly.Insert(t);
    delim_zeros();
    return *this;
}

Poly& Poly::operator *=(const Term& t)
{
    for(List<Term>::Iterator it = _poly.Begin(); it != _poly.End(); it++)
    {
        //Dereference iterator, gives you Term, so multiply this term to t
        *it *= t;
    }
    delim_zeros();
    return *this;
}

Poly operator + (const Poly& left, const Term& t)
{
    //operator +=
    Poly result = left;
    result += t;
    return result;
}

Poly operator * (const Poly& left, const Term& t)
{
    //operator *=
    Poly result = left;
    result *= t;
    return result;
}

//--------------------------------- Poly Poly calculation --------------------------------------

Poly& Poly::operator +=(const Poly& RHS)
{
    //Add every term of RHS to the poly
    for(List<Term>::Iterator it = RHS._poly.Begin(); it != RHS._poly.End(); it++)
    {
        //_poly += *it? why doesn't work?
        *this += *it;
    }
    return *this;
}

Poly& Poly::operator -=(const Poly& RHS)
{
    Poly temp = -RHS;
    *this += temp;
    return *this;
}

Poly& Poly::operator *=(const Poly& RHS)
{
    //For every term of the ths, multiply _poly and then add to the _poly
    //poly += poly * term
    Poly result;
    Poly mult = *this;
    for(List<Term>::Iterator it = RHS._poly.Begin(); it != RHS._poly.End(); it++)
    {
        //*it is dereferencing the iterator to the term
        result += mult*(*it);
    }
    *this = result;
    return *this;
}

Poly& Poly::operator /=(const Poly& RHS)
{
    /*
     * Process:
     * 1. Save the first term of the demo(rhs) ------> divident_term
     * 2. Make copy of the Poly -----> lets call it divisor
     * 3. divisor first term / divident_term
     * 4. Add to the answer -----> lets call it result
     * 5. then mult that answer term to the rhs ----> lets call it mult ------> could combine with 4
     * 6. divident - mult -----> sub
     * 7. Keep going until can't divide
     */

    //rhs can't be 0
    assert(RHS._poly.Begin()->_coef != 0.0);
    Term divident_term = *RHS._poly.Begin();
    Poly divisor = *this;
    Poly answer;
    Poly mult;
    Term answer_term(0,0);

    //Find the answer_term ----> it can't be 0 x0
    answer_term = *divisor._poly.Begin() / divident_term;

    //divisor will be subtracted, so the loop should end when divisor's order is less than the divident order
    //Infinite loop?  ------> answer term can't be (0,0), it means that you have nothing to divide, it should end
    while(divisor._poly.Begin()->_exp >= RHS._poly.Begin()->_exp && answer_term._coef != 0.0) {
        //Add to the result
        answer += answer_term;

        //Multiply
        mult = RHS * answer_term;

        //Subtract the mult
        divisor -= mult;

        //Find the new answer_term
        answer_term = *divisor._poly.Begin() / divident_term;
    }
    *this = answer;
    return *this;
}

Poly operator + (const Poly& left, const Poly& right)
{
    //Use operator +=
    Poly answer = left;
    answer += right;
    return answer;
}

Poly operator -(const Poly& left, const Poly& right)
{
    //Use operator -=
    Poly answer = left;
    answer -= right;
    return answer;
}

Poly operator * (const Poly& left, const Poly& right)
{
    //Use operator *=
    Poly answer = left;
    answer *= right;
    return answer;
}

Poly operator / (const Poly& left, const Poly& right)
{
    //Use operator /=
    Poly answer = left;
    answer /= right;
    return answer;
}

Poly operator % (const Poly& left, const Poly& right)
{
    Poly temp = left / right;
    Poly result = left - (temp * right);
    return result;
}

//--------------------------------- Others ----------------------------

Poly Poly::operator -() const
{
    //Add every negative term in Poly
    Poly result;
    for(List<Term>::Iterator it = _poly.Begin(); it != _poly.End(); it++)
    {
        Term t = *it;
        t = -t;
        result += t;
    }
    return result;
}

Term& Poly::operator [](const int exp)
{
    return _poly[exp];
}

ostream& operator << (ostream& outs, const Poly& print_me)
{
    outs << "[";
    for(List<Term>::Iterator it = print_me._poly.Begin(); it != print_me._poly.End(); it++)
    {
        //*it is term
        outs << *it;
    }
    outs << "]";
    return outs;
}

istream& operator >> (istream& ins, Poly& print_me)
{
    //Enter like 2 x3..... 1 x0
        //Need a space holder

        Term t;
        Poly result;
        char space = ' ';
        //Ends when user enter terms with -exp
        ins >> t;
        while(t._exp > 0)
        {
            result = result + t;
            ins >> space >> t;
        }

        //The last t is not saved
        result = result + t;
        print_me = result;
        return ins;
}

void Poly::delim_zeros()
{
    //If there is a 0 coefficient term, then delete that
    for(List<Term>::Iterator it = _poly.Begin(); it != _poly.End(); it++)
    {
        //Get the term
        Term t = *it;
        if(t._coef == 0.0)
            _poly.Delete(it);
    }

    //Test if _poly is empty. If it is, then add 0x0
    if(_poly.Begin().is_null())
        _poly.Insert(Term());
}
