#include "poly.h"
#include<iostream>
#include<cassert>
#include<cmath>
#include "../../!includes/Polynomials/term.h"
#include "../../!includes/pointerFunctions/one_d_functions.h"
#include "../../!includes/AddEntry/Add_Remove_Entry.h"
using namespace std;

const double EPSILON = 0.001;

Poly::Poly(): _order(0)
{
    _coefs = allocate<double>(1);
    *_coefs = 0;
}

Poly::Poly(double* coefs, int order):_order(order)
{
    //size is order + 1
    _coefs = allocate<double>(order + 1);
    copy(_coefs, coefs, order + 1);
}

//The BIG 3
Poly::Poly(const Poly& other)
{
    /*
    const bool debug = true;
    if(debug)
        cout << "Poly CTOR (" << other << ")" << endl;
    */

    //1. Copy variables
    _order = other._order;

    //2. allocate space for new array
    _coefs = allocate<double>(_order + 1);

    //3. copy everything over
    copy(_coefs, other._coefs, _order + 1);
}

Poly& Poly::operator =(const Poly& rhs)
{
    /*
    const bool debug = true;
    if(debug)
        cout << "Poly CTOR (" << rhs << ")" << endl;
    */

    //1. Check for self-reference
    if(this == &rhs)
        return *this;

    //2. deallocate existing space
    delete[] _coefs;

    //3. allocate space for new array
    _coefs = allocate<double>(rhs._order + 1);

    //4. copy everything over
    copy(_coefs, rhs._coefs, rhs._order + 1);
    _order = rhs._order;

    //5. return this object
    return *this;
}

Poly::~Poly()
{
    /*
    const bool debug = true;
    if(debug)
    {
        cout << "~Poly: ";
        cout << *this << endl;
    }
    */

    //Delete the array
    delete[] _coefs;
}

//Comparing operators
bool operator ==(const Poly& lhs, const Poly& rhs)
{
    //Check for order
    if(lhs._order != rhs._order)
        return false;

    //Check for coefficient
    for(int i = 0; i <= lhs._order; i++)
    {
        //Check for every term's exp then coef
        if(lhs[i]._exp != rhs[i]._exp)
            return false;

        //safe to compare double in this way
        else if(fabs(lhs[i]._coef - rhs[i]._coef) > EPSILON)
            return false;
    }
    return true;
}

bool operator !=(const Poly& lhs, const Poly& rhs)
{
    //not ==
    return (!(lhs == rhs));
}

bool operator >(const Poly& lhs, const Poly& rhs)
{
    //Check for exp and coe of each term of the Poly
    int count = 0;
    //Find the place that they were not same
    for(int i = 0; i < lhs._order; i++)
    {
        if(lhs[i]._exp != rhs[i]._exp || fabs(lhs[i]._coef - rhs[i]._coef) > EPSILON)
        {
            count = i;
            break;
        }
    }

    //Compare that term
    if(lhs[count]._exp > rhs[count]._exp)
        return true;
    else if(lhs[count]._coef > rhs[count]._coef)
        return true;
    //Even if they are the same, count is 0, so when compare the two terms at poly[0], they are the same
    //Still return false.

    return false;
}

bool operator <(const Poly& lhs, const Poly& rhs)
{
    //Same as operator > but except the < and > are the opposite.

    //Check for exp and coe of each term of the Poly
    int count = 0;
    //Find the place that they were not same
    for(int i = 0; i < lhs._order; i++)
    {
        if(lhs[i]._exp != rhs[i]._exp || fabs(lhs[i]._coef - rhs[i]._coef) > EPSILON)
        {
            count = i;
            break;
        }
    }

    //Compare that term
    if(lhs[count]._exp < rhs[count]._exp)
        return true;
    else if(lhs[count]._coef < rhs[count]._coef)
        return true;
    //Even if they are the same, count is 0, so when compare the two terms at poly[0], they are the same
    //Still return false.

    return false;
}

//Bracket operator
Term Poly::operator[](int order) const
{
    //Find the place of the order in the coef array
    double* operatorWalker = _coefs + order;

    //Save the coef of the term
    double coef = *operatorWalker;
    int exp = order;
    return Term(coef, exp);
}

//Calculation operators
Poly operator +(const Poly& lhs, const Term& t)
{
    //Set the result to the lhs
    Poly result = lhs;

    //Check special condition: coef is 0
    if(t._coef == 0.0)
        return result;

    //cout << "exp: " << exp <<endl;
    //Resize? term has bigger exp?? ---> resize
    if(t._exp > result._order)
    {
        //Need to add 1 because the size is one greater than the order
        result._coefs = resize<double>(result._coefs, result._order + 1, t._exp + 1, 0);
        result._order = t._exp;
            //cout << "result._order: " << result._order << endl;
    }

    //Find the new coef
    double result_coef = result[t._exp]._coef + t._coef;

    //Find the position
    double* position = result._coefs + t._exp;

    //Set the new coef at the position
    *position = result_coef;

    //Return the result
    return result;

}
Poly operator +(const Poly& lhs, const Poly& rhs)
{
    Poly result;
    //set it as lhs then add rhs terms
    result = lhs;
    for(int i = 0; i <= rhs._order; i++)
    {
            //cout << "operator +: " << result << " + " << rhs[i] << endl;
        result = result + rhs[i];
    }

    //For high level operator: fix order
    result.fix_order();
    return result;
}

Poly operator -(const Poly& p)
{
    Poly result;
    //Make everything negative
    for(int i = 0; i <= p._order; i++)
    {
        Term neg_term(-1 * p[i]._coef, p[i]._exp);
        result = result + neg_term;
    }
    return result;
}
Poly operator - (const Poly& lhs, const Poly& rhs)
{
    //Find the poly with higher order
    Poly result = lhs + (-rhs);

    //For high level operator: fix order
    result.fix_order();
    return result;
}

Poly operator *(const Poly& lhs, const Term& t)
{
    Poly result;

    /*
    //Check for special condition: order = 0
    if(lhs._order == 0)
        return result;

    //What if coefficient = 0? ---->Need to check
    if(lhs[0]._coef == 0)
        return result;
    */
    //Only if both order and coef is 0 then return result
    if(lhs._order == 0 && lhs[0]._coef == 0)
        return result;

    //cout << "Finish Check" << endl;
    for(int i = 0; i <= lhs._order; i++)
    {
        //Term * term = term, then poly + term
        Term mul = lhs[i] * t;
        result = result + mul;
    }

    return result;
}

Poly operator *(const Poly& lhs, const Poly& rhs)
{
    Poly result;
    for(int i = 0; i <= rhs._order; i++)
    {
        //lhs * every term in rhs ---> Poly
        //Decimal points? When dividing not integer?
        //Add the the Poly to the result
        result = result + (lhs * rhs[i]);
        //cout << "result: " << result << endl;
    }

    //For high level operator: fix order
    result.fix_order();
    return result;
}

//How to do it? Process?
Poly operator /(const Poly& lhs, const Poly& rhs)
{
    /*
     * Process:
     * 1. Save the first term of the demo(rhs) ------> divident_term
     * 2. Make copy of the lhs Poly -----> lets call it divisor
     * 3. divisor first term / divident_term
     * 4. Add to the answer -----> lets call it result
     * 5. then mult that answer term to the rhs ----> lets call it mult ------> could combine with 4
     * 6. divident - mult
     * 7. Keep going until can't divide
     */

    //rhs can't be 0
    assert(rhs != Poly());

    Term divident_term = rhs[rhs._order];
        //cout << endl << "divident_term = " << divident_term << endl;
    Poly divisor = lhs;
    Poly result;
    Poly mult;
    Poly sub;
    Term answer_term(0,0);

        //cout << endl <<"Divisor: " << divisor << endl;
    //Find the answer_term ----> it can't be 0 x0
    answer_term = divisor[divisor._order] / divident_term;
        //cout << "answer term: " << answer_term << endl;

    //divisor will be subtracted, so the loop should end when divisor's order is less than the divident order
    //Infinite loop?  ------> answer term can't be (0,0), it means that you have nothing to divide, it should end

    //In the Output.h there is a sample run to show
    //when you set rhs as 12 x0
    //without --------> answer_term._coef != 0.0 -----> will not work
    while(divisor._order >= rhs._order && answer_term._coef != 0.0)
    {
        //Add to the result
        result = result + answer_term;
            //cout << "result: " << result << endl;

        //multiply
        mult = rhs * answer_term;
            //cout << "mult: " << mult << endl;

        //Subtract the mult
        sub = divisor - mult;
            //cout << "divisor: " << divisor << " - " << mult << endl << " = " << sub << endl << endl;
        divisor = sub;

        //Find the answer_term
        answer_term = divisor[divisor._order] / divident_term;
            //cout << "answer term: " << answer_term << endl;
    }
    result.fix_order();
    return result;
}

Poly operator %(const Poly& lhs, const Poly& rhs)
{
    //p-(p/q) * q

    //First p/q
    Poly result = lhs / rhs;

    //Then * q
    result = result * rhs;

    //Then p - ans
    result = lhs - result;

    return result;
}

//Output and input
ostream& operator <<(ostream& outs, const Poly& p)
{
    outs << "[";
    for(int i = p._order; i >= 0; i--)
    {
        outs << p[i];
    }
    outs << "]";
    return outs;
}

istream& operator >>(istream& ins, Poly& p)
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
    p = result;
    return ins;
}



//========================== Private FXNs ==============================================
void Poly::fix_order()
{
    //Whenever the highest term's coef is 0, delete that
    double* coefWalker = _coefs + _order;
    double coef = *coefWalker;
    //Start from the last position because you need to reallocate
    //While the coef is 0 and order > 0
    //Need _order > 0 because otherwise might goes into infinite loop
    while (coef == 0.0 && _order > 0) {
        _order --;
        _coefs = reallocate<double>(_order + 1, _order, _coefs);
        coefWalker = _coefs + _order;
        coef = *coefWalker;
    }
}





