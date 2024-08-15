#include "predator.h"

Predator::Predator(Location loc): Creature(loc._r, loc._c)
{
    _move = 0;
    _starve = 0;
}

void Predator::move(Creature* grid[][MAX])
{
    if(!get_moved())
    {
        //Check to see if it will starve to death
        if(_starve == STARVE)
            starve(grid);
        //Check to see if finds preys to eat
        Location food = find_this_creature(grid, 2);
        if(food._r != -1)
        {
            eat(grid, food);
            _starve = 0;
            _move ++;
        }
        else {
            //If not finding food to eat, it will randomly move
            Creature::move(grid);
            _starve ++;
            _move ++;
        }
    }
}

void Predator::breed(Creature* grid[][MAX])
{
    //If move is 8, then it will breed
    if(_move == BREED)
    {
        Location position = find_blank(grid);
        //Check if can find a position to breed
        if(position._r != -1)
            grid[position._r][position._c] = new Predator(position);
        //Reset move
        _move = 0;
    }
}

void Predator::print()
{
    cout << "X";
}

int Predator::get_type()
{
    return 3;
}

void Predator::starve(Creature* grid[][MAX])
{
    Creature::kill(grid);
}

void Predator::eat(Creature* grid[][MAX], Location loc)
{
    //Predator eats the prey and move to the prey's location
    grid[loc._r][loc._c]->kill(grid);
    move_to(grid, loc);
}

void Predator::draw(sf::RenderWindow& window, Location loc)
{
    //cout << "Drawing Predator" << endl;
    sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rectangle.move(sf::Vector2f(loc._r * CELL_SIZE, loc._c * CELL_SIZE));
    rectangle.setFillColor(sf::Color::Red);
    window.draw(rectangle);
}

void Predator::force_breed(Creature* grid[][MAX])
{
    Location position = find_blank(grid);
    //Check if can find a position to breed
    if(position._r != -1)
        grid[position._r][position._c] = new Predator(position);
    //Reset move
    _move = 0;
}
