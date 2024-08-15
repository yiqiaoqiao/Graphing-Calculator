#include "creature.h"
#include "../../!includes/AddEntry/Add_Remove_Entry.h"
#include <iostream>
#include <ctime>

using namespace std;

Creature::Creature(int row, int column): _moved(false)
{
    _l._r = row;
    _l._c = column;
}

void Creature::move(Creature* grid[][MAX])
{
    //There are 8 cases of moving the creature
    srand(time(0));
    int choice = (rand() % 8);
    Location loc;
    switch (choice) {
    case 0:
        //up
        if(grid[_l._r - 1][_l._c] == nullptr)
        {
            loc._r = _l._r - 1;
            loc._c = _l._c;
            move_to(grid, loc);
        }
        break;
    case 1:
        //down
        if(grid[_l._r + 1][_l._c] == nullptr)
        {
            loc._r = _l._r + 1;
            loc._c = _l._c;
            move_to(grid, loc);
        }
        break;
    case 2:
        //left
        if(grid[_l._r][_l._c - 1] == nullptr)
        {
            loc._r = _l._r;
            loc._c = _l._c - 1;
            move_to(grid, loc);
        }
        break;
    case 3:
        //right
        if(grid[_l._r][_l._c + 1] == nullptr)
        {
            loc._r = _l._r;
            loc._c = _l._c + 1;
            move_to(grid, loc);
        }
        break;
    case 4:
        //left up
        if(grid[_l._r - 1][_l._c - 1] == nullptr)
        {
            loc._r = _l._r - 1;
            loc._c = _l._c - 1;
            move_to(grid, loc);
        }
        break;
    case 5:
        //right up
        if(grid[_l._r - 1][_l._c + 1] == nullptr)
        {
            loc._r = _l._r - 1;
            loc._c = _l._c + 1;
            move_to(grid, loc);
        }
        break;
    case 6:
        //left down
        if(grid[_l._r + 1][_l._c - 1] == nullptr)
        {
            loc._r = _l._r + 1;
            loc._c = _l._c - 1;
            move_to(grid, loc);
        }
        break;
    case 7:
        //right down
        if(grid[_l._r + 1][_l._c + 1] == nullptr)
        {
            loc._r = _l._r + 1;
            loc._c = _l._c + 1;
            move_to(grid, loc);
        }
        break;
    }
}

void Creature::breed(Creature* grid[][MAX])
{
    //DO NOTHING BECAUSE ITS VIRTUAL
}

void Creature::print()
{
    cout << "C";
}

int Creature::get_type()
{
    return 0;
}

void Creature::move_to(Creature* grid[][MAX], Location l)
{
    Creature* temp = grid[_l._r][_l._c];
    grid[l._r][l._c] = temp;
    _moved = true;

    //Set original location as null
    grid[_l._r][_l._c] = nullptr;
    _l._r = l._r;
    _l._c = l._c;
}

Location Creature::find_blank(Creature* grid[][MAX])
{
    int capacity = 3;
    int size = 0;
    Location* blanks = allocate<Location>(capacity);
    Location loc;

    //Find all the blank space and save in an array
    for(int i = _l._r - 1; i <= _l._r + 1; i++)
    {
        for(int j = _l._c - 1; j <= _l._c + 1; j++)
        {
            if(grid[i][j] == nullptr)
            {
                loc._r = i;
                loc._c = j;
                blanks = add_entry<Location>(blanks, loc, size, capacity);
            }
        }
    }

    //Checks for if size = 0
    if(size == 0)
    {
        //Return a location with negative, to show that cannot find any blank space
        loc._r = -1;
        loc._c = -1;
        return loc;
    }

    //If finds a location, then randomly choose an element in the array and return it
    srand(time(0));
    int random = (rand() % size);
    loc._r = blanks[random]._r;
    loc._c = blanks[random]._c;

    //Delete the dynamic array
    delete[] blanks;

    return loc;
}

Location Creature::find_this_creature(Creature* grid[][MAX], int type)
{
    //FIND THE CREATURE AROUND THE LOCATION!!!!
    int capacity = 3;
    int size = 0;
    Location* list = allocate<Location>(capacity);
    Location loc;

    //Find all the blank space and save in an array
    for(int i = _l._r - 1; i <= _l._r + 1; i++)
    {
        for(int j = _l._c - 1; j <= _l._c + 1; j++)
        {
            if(grid[i][j] != nullptr && grid[i][j]->get_type() == type)
            {
                loc._r = i;
                loc._c = j;
                list = add_entry(list, loc, size, capacity);
            }
        }
    }

    //Checks for if size = 0
    if(size == 0)
    {
        //Return a location with negative, to show that cannot find any blank space
        loc._r = -1;
        loc._c = -1;
        return loc;
    }

    //If finds a location, then randomly choose an element in the array and return it
    srand(time(0));
    int random = (rand() % size);
    loc._r = list[random]._r;
    loc._c = list[random]._c;

    //Delete the dynamic array
    delete[] list;

    return loc;
}

Location Creature::find_not_this_creature(Creature* grid[][MAX], int type)
{
    int capacity = 3;
    int size = 0;
    Location* list = allocate<Location>(capacity);
    Location loc;

    //Find all the blank space and save in an array
    for(int i = _l._r - 1; i <= _l._r + 1; i++)
    {
        for(int j = _l._c - 1; j <= _l._c + 1; j++)
        {
            if(grid[i][j]->get_type() != type)
            {
                loc._r = i;
                loc._c = j;
                list = add_entry<Location>(list, loc, size, capacity);
            }
        }
    }

    //Checks for if size = 0
    if(size == 0)
    {
        //Return a location with negative, to show that cannot find any blank space
        loc._r = -1;
        loc._c = -1;
        return loc;
    }

    //If finds a location, then randomly choose an element in the array and return it
    srand(time(0));
    int random = (rand() % size);
    loc._r = list[random]._r;
    loc._c = list[random]._c;

    //Delete the dynamic array
    delete[] list;

    return loc;
}

void Creature::set_moved(bool moved)
{
    _moved = moved;
}

bool Creature::get_moved() const
{
    return _moved;
}

void Creature::kill(Creature* grid[][MAX])
{
    grid[_l._r][_l._c] = nullptr;
}

ostream& operator << (ostream outs, const Creature& print_me)
{
    outs << "C";
    return outs;
}

void Creature::draw(sf::RenderWindow& window, Location loc)
{
    //DO NOTHING
    //Will specify in each child class
}

void Creature::force_breed(Creature* grid[][MAX])
{
    //DO NOTHING
    //Will specify in each child class
}


