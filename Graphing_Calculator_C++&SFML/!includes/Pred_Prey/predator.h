#ifndef PREDATOR_H
#define PREDATOR_H

#include "../../!includes/Pred_Prey/creature.h"

const int BREED = 8;
const int STARVE = 3;

class Predator : public Creature
{
public:
    Predator(Location loc);
    void move(Creature* grid[][MAX]);
    void breed(Creature* grid[][MAX]);
    void print();
    int get_type();
    void starve(Creature* grid[][MAX]);
    void eat(Creature* grid[][MAX], Location loc);
    void draw(sf::RenderWindow& window, Location loc);
    void force_breed(Creature* grid[][MAX]);

private:
    int _move;
    int _starve;
};

#endif // PREDATOR_H
