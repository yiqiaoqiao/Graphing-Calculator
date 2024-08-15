#include "wall.h"

Wall::Wall(Location loc): Creature(loc._r, loc._c)
{
    //DO NOTHING
}

void Wall::move(Creature* grid[][MAX])
{
    //DO NOTHING BECAUSE WALL DON'T MOVE
}

void Wall::breed(Creature* grid[][MAX])
{
    //DO NOTHING BECAUSE WALL DON'T BREED
}

void Wall::print()
{
    cout << "Z";
}

int Wall::get_type()
{
    return 1;
}

void Wall::draw(sf::RenderWindow& window, Location loc)
{
    //cout << "Drawing walls" << endl;
    sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rectangle.move(sf::Vector2f(loc._r * CELL_SIZE, loc._c * CELL_SIZE));
    rectangle.setFillColor(sf::Color::Blue);
    window.draw(rectangle);
}

void Wall::force_breed(Creature* grid[][MAX])
{
    //DO NOTHING
}
