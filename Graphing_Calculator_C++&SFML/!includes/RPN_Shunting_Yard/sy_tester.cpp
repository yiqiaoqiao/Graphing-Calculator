#include "sy_tester.h"

void _test_one()
{
    Queue<Token*> infix;
    infix.push(new Number(3));
    infix.push(new Operator("*"));
    infix.push(new Number(5));
    infix.push(new Operator("+"));
    infix.push(new Number(8));

    //Infix: 3 * 5 + 8
    //Postfix: 3 5 * 8 +
    cout << "---------------------- TEST ONE -----------------------" << endl;
    Shunting_yard sy(infix);
    cout << sy;
    cout << "---------------------- END OF TEST ONE ---------------------------" << endl;
}

void _test_two()
{
    Queue<Token*> infix;
    infix.push(new Number(2));
    infix.push(new Operator("+"));
    infix.push(new Number(3));
    infix.push(new Operator("*"));
    infix.push(new Number(5));
    infix.push(new Operator("/"));
    infix.push(new Number(8));

    //Infix: 2 + 3 * 5 / 8
    //Postfix: 2 3 5 * 8 / +
    cout << "---------------------- TEST TWO -----------------------" << endl;
    Shunting_yard sy(infix);
    cout << sy;
    cout << "---------------------- END OF TEST TWO ---------------------------" << endl;
}

void _test_three()
{
    Queue<Token*> infix;
    infix.push(new Number(3));
    infix.push(new Operator("*"));
    infix.push(new L_paren());
    infix.push(new Number(5));
    infix.push(new Operator("+"));
    infix.push(new Number(8));
    infix.push(new R_paren);
    infix.push(new Operator("/"));
    infix.push(new Number(2));

    //Infix: 3 * ( 5 + 8 ) / 2
    //Postfix: 3 5 8 + * 2 /
    cout << "---------------------- TEST THREE -----------------------" << endl;
    Shunting_yard sy(infix);
    cout << sy;
    cout << "---------------------- END OF TEST THREE ---------------------------" << endl;
}

void _test_four()
{
    Queue<Token*> infix;
    infix.push(new Variable("x"));
    infix.push(new Operator("*"));
    infix.push(new Function("cos"));
    infix.push(new L_paren);
    infix.push(new Number(1));
    infix.push(new Operator("/"));
    infix.push(new Variable("x"));
    infix.push(new R_paren);

    //Infix: x * cos ( 1 / x )
    //Postfix: x 1 x / cos *
    cout << "---------------------- TEST FOUR -----------------------" << endl;
    Shunting_yard sy(infix);
    cout << sy;
    cout << "---------------------- END OF TEST FOUR ---------------------------" << endl;
}

void _test_five()
{
    Queue<Token*> infix;
    infix.push(new Number(3));
    infix.push(new Operator("*"));
    infix.push(new Function("sin"));
    infix.push(new L_paren);
    infix.push(new Variable("x"));
    infix.push(new Operator("^"));
    infix.push(new Number(2));
    infix.push(new R_paren);

    //Infix: 3 * sin ( x ^ 2 )
    //Postfix: 3 x 2 ^ sin *
    cout << "---------------------- TEST FIVE -----------------------" << endl;
    Shunting_yard sy(infix);
    cout << sy;
    cout << "---------------------- END OF TEST FIVE ---------------------------" << endl;
}

void _test_all()
{
    _test_one();
    cout << endl << endl;
    _test_two();
    cout << endl << endl;
    _test_three();
    cout << endl << endl;
    _test_four();
    cout << endl << endl;
    _test_five();
    cout << endl << endl;
}
