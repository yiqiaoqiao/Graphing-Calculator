#ifndef MCOUNTER_H
#define MCOUNTER_H


class MCounter
{
public:
    MCounter();
    int add_1();
    int add_10();
    int add_100();
    int add_1000();
    int reset();
    int count() const;
    bool is_error() const;
private:
    int _count;
};


#endif // MCOUNTER_H
