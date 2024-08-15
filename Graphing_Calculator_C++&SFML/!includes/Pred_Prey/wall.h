#ifndef WALL_H
#define WALL_H

#include "../../!includes/Pred_Prey/creature.h"

class Wall : public Creature
{
public:
    Wall(Location loc);
    void move(Creature* grid[][MAX]);
    void breed(Creature* grid[][MAX]);
    void print();
    int get_type();
    void draw(sf::RenderWindow& window, Location loc);
    void force_breed(Creature* grid[][MAX]);

private:
    //NOTHING
};

#endif // WALL_H
