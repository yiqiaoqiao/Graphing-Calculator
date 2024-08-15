#ifndef LINK_LIST_POLY_H
#define LINK_LIST_POLY_H

#include <iostream>
#include "../../!includes/Polynomials/link_list_term.h"
#include "../../!includes/List_Functions/sorted_list.h"

using namespace std;

class Poly
{
public:

    Poly();
    Poly(List<Term> poly);
    Poly(double term_array[], int order);


    Poly& operator +=(const Term& t);
    Poly& operator *=(const Term& t);

    Poly& operator +=(const Poly& RHS);
    Poly& operator *=(const Poly& RHS);
    Poly& operator -=(const Poly& RHS);
    Poly& operator /=(const Poly& RHS);


    //Comparing
    friend bool operator == (const Poly& left, const Poly& right);
    friend bool operator != (const Poly& left, const Poly& right);

    //Calculation
    friend Poly operator + (const Poly& left, const Poly& right);
    friend Poly operator -(const Poly& left, const Poly& right);
    friend Poly operator * (const Poly& left, const Poly& right);
    friend Poly operator / (const Poly& left, const Poly& right);
    friend Poly operator % (const Poly& left, const Poly& right);
    Poly operator -() const;


    friend Poly operator + (const Poly& left, const Term& t);
    friend Poly operator * (const Poly& left, const Term& t);

    friend ostream& operator << (ostream& outs, const Poly& print_me);
    friend istream& operator >> (istream& ins, Poly& print_me);

    //These operators not suitable for list poly:
    //const Term& operator [](const int exp) const;
    //Term& operator [](const int exp);
    Term& operator [](const int exp);

private:
    List<Term> _poly;
    //descending sorted list;
    void delim_zeros();
};

#endif // LINK_LIST_POLY_H
