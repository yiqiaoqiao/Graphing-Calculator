#ifndef TOKEN_H
#define TOKEN_H


class Token
{
public:
    Token();
    virtual int type();
    virtual void print();
};

#endif // TOKEN_H
