#ifndef LINK_LIST_TERM_H
#define LINK_LIST_TERM_H

#include<iostream>
using namespace std;

struct Term{
    double _coef;
    int _exp;

    //CTOR
    Term();
    Term(double coef, int exp);

    //Compund Assignment
    Term& operator +=(const Term& rhs);
    Term& operator -=(const Term& rhs);
    Term& operator *=(const Term& rhs);
    Term& operator /=(const Term& rhs);

    //Comparing operators
    friend bool operator ==(const Term& lhs, const Term& rhs);
    friend bool operator !=(const Term& lhs, const Term& rhs);
    friend bool operator >(const Term& lhs, const Term& rhs);
    friend bool operator <(const Term& lhs, const Term& rhs);

    //Unary operator
    Term operator -() const;

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

#endif // LINK_LIST_TERM_H
