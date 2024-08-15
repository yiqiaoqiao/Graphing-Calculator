#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include "../../!includes/Pred_Prey/constant.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
using namespace std;


struct Location
{
    int _r;
    int _c;
};

class Creature
{    
public:
    Creature(int row, int column);
    virtual void move(Creature* grid[][MAX]);
    virtual void breed(Creature* grid[][MAX]);
    virtual void print();
    virtual int get_type(); //1 is wall, 2 is prey, 3 is pred
    void move_to(Creature* grid[][MAX], Location l);
    Location find_blank(Creature* grid[][MAX]); //Return a random blank space
    Location find_this_creature(Creature* grid[][MAX], int type);
    Location find_not_this_creature(Creature* grid[][MAX], int type);
    void set_moved(bool moved);
    bool get_moved() const;
    void kill(Creature* grid[][MAX]);
    friend ostream& operator << (ostream outs, const Creature& print_me);

    //SFML
    virtual void draw(sf::RenderWindow& window, Location loc);
    virtual void force_breed(Creature* grid[][MAX]);
private:
    Location _l;
    bool _moved;
};

#endif // CREATURE_H
