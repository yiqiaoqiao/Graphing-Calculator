#ifndef TERM_H
#define TERM_H

#include<iostream>
using namespace std;

struct Term{
    double _coef;
    int _exp;

    //CTOR
    Term();
    Term(double coef, int exp);

    //Comparing operators
    friend bool operator ==(const Term& lhs, const Term& rhs);
    friend bool operator !=(const Term& lhs, const Term& rhs);
    friend bool operator >(const Term& lhs, const Term& rhs);
    friend bool operator <(const Term& lhs, const Term& rhs);

    //Calculation operators
    friend Term operator + (const Term& lhs, const Term& rhs);
    friend Term operator - (const Term& lhs, const Term& rhs);
    friend Term operator * (const Term& lhs, const Term& rhs);
    //used in Poly division operator
    friend Term operator / (const Term& lhs, const Term& rhs);

    //Input & Output
    friend ostream& operator <<(ostream& outs, const Term& t);
    friend istream& operator >> (istream& ins, Term& t);
};

#endif // TERM_H
