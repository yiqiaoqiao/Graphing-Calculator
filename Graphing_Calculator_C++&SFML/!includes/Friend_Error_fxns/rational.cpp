#include "rational.h"
#include <string>
using namespace std;

Rational::Rational():_n(0), _d(1), _error(0)
{
    //No need of anything
}

Rational :: Rational(int num, int denom):_n(num), _d(denom), _error(0)
{
    //Check for errors
    _error = is_error();
}

Rational :: Rational(int w): _n(w), _d(1), _error(0)
{
    //No need of anything because programmer initialize the denom
}

void Rational :: set(int num, int denom)
{
    _n = num;
    _d = denom;
    //Need to check for the denominator
    _error = is_error();
}

void Rational :: set_num(int n)
{
    //You don't need to check for the numerator because it will not give you error
    _n = n;
}

void Rational :: set_denom(int d)
{
    _d = d;
    //Need to check for the denominator
    _error = is_error();
}

int Rational :: get_num() const //This is constant because you do not change any private variable
{
    return _n;
}

int Rational :: get_denom() const //This is constant because you do not change any private variable
{
    return _d;
}

int Rational :: error() const //This is constant because you do not change any private variable
{
    return _error;
}

int Rational :: is_error() //Change error
{
    if(_d == 0)
    {
        _error = 1;
        return _error;
    }
    _error = 0;
    return _error;
}

string Rational :: error_description() const //This is constant because you do not change any private variable
{
    return error_description(_error);
}

string Rational :: error_description(int e) const //This is constant because you do not change any private variable
{
    switch (e)
    {
    case 0: return "NO ERROR";
    case 1:
        return "UNDEFINED";
        //break;
    default:
        return "UNKNOWN ERROR"; //There might be unknown error
        //break;
    }
}

void Rational :: clear()
{
    _error = 0;
    _n = 0; //Set the member variables to the initial value, which is 0/1
    _d = 1;
}

Rational operator +(const Rational &num1, const Rational &num2)
{
    //Check for errors
    if(num1.error() || num2.error())
    {
        //return error object
        return Rational(1,0); //Setting denominator to 0 so when outputting it will output undefined.
    }

    int n_sum = num1.get_num() * num2.get_denom() + num2.get_num() * num1.get_denom();
    int d_sum = num1.get_denom() * num2.get_denom();
    Rational sum(n_sum, d_sum);
    return sum;
}

Rational operator -(const Rational &num1, const Rational &num2)
{
    //Check for errors
    if(num1.error() || num2.error())
    {
        //return error object
        return Rational(1,0); //Setting denominator to 0 so when outputting it will output undefined.
    }

    int n_sub = num1.get_num() * num2.get_denom() - num2.get_num() * num1.get_denom();
    int d_sub = num1.get_denom() * num2.get_denom();
    Rational sub(n_sub, d_sub);
    return sub;
}

Rational operator *(const Rational &num1, const Rational &num2)
{
    //Check for errors
    if(num1.error() || num2.error())
    {
        //return error object
        return Rational(1,0); //Setting denominator to 0 so when outputting it will output undefined.
    }

    int n_product = num1.get_num() * num2.get_num();
    int d_product = num1.get_denom() * num2.get_denom();
    Rational product(n_product, d_product);
    return product;
}

Rational operator /(const Rational &num1, const Rational &num2)
{
    //Check for errors
    if(num1.error() || num2.error())
    {
        //return error object
        return Rational(1,0); //Setting denominator to 0 so when outputting it will output undefined.
    }

    int n_quotient = num1.get_num() * num2.get_denom();
    int d_quotient = num1.get_denom() * num2.get_num();
    Rational quotient(n_quotient, d_quotient);
    return quotient;
}

ostream& operator <<(ostream &outs, const Rational &num)
{
    int new_n = 0, new_d = 0;
    //If it has error, then it will output the error message
    if(num.error())
    {
        outs << num.error_description(num.error());
    }
    //Else it will output the fraction
    else
    {
        //Checks if both numerator and denominator is negative
        //If they are both neg, set them both as positive when outputting it
        if(num.get_num() < 0 && num.get_denom() < 0)
        {
            new_n = 0 - num.get_num();
            new_d = 0 - num.get_denom();
            outs << new_n << "/" << new_d;
        }
        //Else output in the normal way
        else
            outs << num.get_num() << "/" << num.get_denom();
    }
    return outs;
}

istream& operator >>(istream &ins, Rational &num)
{
    int n = 0, d = 0;
    char slash = ' ';
    //Slash for place holder for the user to input /
    ins >> n >> slash >> d;
    num = Rational(n,d);
    return ins;
}
