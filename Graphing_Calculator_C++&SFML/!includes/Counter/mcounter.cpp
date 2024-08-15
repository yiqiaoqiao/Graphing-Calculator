#include "mcounter.h"

MCounter::MCounter()
{
    _count = reset();
}

int MCounter::add_1()
{
    _count ++;
    return _count;
}

int MCounter::add_10()
{
    _count += 10;
    return _count;
}

int MCounter::add_100()
{
    _count += 100;
    return _count;
}

int MCounter::add_1000()
{
    _count += 1000;
    return _count;
}

int MCounter::reset()
{
    _count = 0;
    return _count;
}

bool MCounter::is_error() const
{
    if(_count > 9999)
        return true;
    return false;
}

int MCounter::count() const
{
    return _count;
}
