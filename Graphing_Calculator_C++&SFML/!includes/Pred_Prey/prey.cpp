#include "prey.h"

Prey::Prey(Location loc): Creature(loc._r, loc._c)
{
    _move = 0;
}

void Prey::move(Creature* grid[][MAX])
{
    if(!get_moved())
        _move ++;
    Creature::move(grid);
}

void Prey::breed(Creature* grid[][MAX])
{
    //If move is 3, then it will breed
    if(_move == 3)
    {
        Location position = find_blank(grid);
        //Check if can find a position to breed
        if(position._r != -1)
            grid[position._r][position._c] = new Prey(position);
        //Reset move
        _move = 0;
    }
}

void Prey::print()
{
    cout << "O";
}

int Prey::get_type()
{
    return 2;
}

void Prey::draw(sf::RenderWindow& window, Location loc)
{
    //cout << "Drawing prey" << endl;
    sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rectangle.move(sf::Vector2f(loc._r * CELL_SIZE, loc._c * CELL_SIZE));
    rectangle.setFillColor(sf::Color::Green);
    window.draw(rectangle);
}

void Prey::force_breed(Creature* grid[][MAX])
{
    Location position = find_blank(grid);
    //Check if can find a position to breed
    if(position._r != -1)
        grid[position._r][position._c] = new Prey(position);
    //Reset move
    _move = 0;
}

