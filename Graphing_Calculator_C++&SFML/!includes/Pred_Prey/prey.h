#ifndef PREY_H
#define PREY_H

#include "../../!includes/Pred_Prey/creature.h"

class Prey : public Creature
{
public:
    Prey(Location loc);
    void move(Creature* grid[][MAX]);
    void breed(Creature* grid[][MAX]);
    void print();
    int get_type();
    void draw(sf::RenderWindow& window, Location loc);
    void force_breed(Creature* grid[][MAX]);

private:
    int _move;
};

#endif // PREY_H
