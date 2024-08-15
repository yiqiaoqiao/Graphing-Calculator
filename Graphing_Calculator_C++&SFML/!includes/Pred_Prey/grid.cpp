#include "grid.h"
#include "../../!includes/Pred_Prey/creature.h"
#include "../../!includes/Pred_Prey/wall.h"
#include "../../!includes/Pred_Prey/predator.h"
#include "../../!includes/Pred_Prey/prey.h"
#include <iostream>
#include <ctime>

using namespace std;

//MAX: 20
//i -> row, j -> column

Grid::Grid():pred_num(PREDATOR_COUNT), prey_num(PREY_COUNT), generation(1)
{
    //set everything to nullptr
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
            _grid[i][j] = nullptr;
    }
    fill_grid();
}

void Grid::fill_wall()
{
    //Set the walls
    //1. set top and bottom walls
    Location loc;
    for(int j = 0; j < MAX; j++)
    {
        loc._r = 0;
        loc._c = j;
        _grid[0][j] = new Wall(loc);
        loc._r = MAX - 1;
        loc._c = j;
        _grid[MAX - 1][j] = new Wall(loc);
    }

    //2. left and right
    for(int i = 0; i < MAX; i++)
    {
        loc._r = i;
        loc._c = 0;
        _grid[i][0] = new Wall(loc);
        loc._r = i;
        loc._c = MAX - 1;
        _grid[i][MAX - 1] = new Wall(loc);
    }
}

void Grid::fill_prey()
{
    srand((time(0)));
    int prey_count = 0;
    int row = 0;
    int column = 0;
    Location loc;
    while (prey_count < PREY_COUNT) {
        //row and column should not be 0 or 20 1-19
        row = (rand() % MAX);
        column = (rand() % MAX);
        if(_grid[row][column] == nullptr)
        {
            loc._r = row;
            loc._c = column;
            _grid[row][column] = new Prey(loc);
            prey_count ++;
        }
    }
}

void Grid::fill_predator()
{
    srand((time(0)));
    int predator_count = 0;
    int row = 0;
    int column = 0;
    Location loc;
    while (predator_count < PREDATOR_COUNT) {
        //row and column should not be 0 or 20 1-19
        row = (rand() % MAX);
        column = (rand() % MAX);
        if(_grid[row][column] == nullptr)
        {
            loc._r = row;
            loc._c = column;
            _grid[row][column] = new Predator(loc);
            predator_count ++;
        }
    }
}

void Grid::fill_grid()
{
    fill_wall();
    fill_prey();
    fill_predator();
}

void Grid::step()
{
    //Call functions move, breed, kill
    move();
    breed();
    reset_move();
    generation ++;
}

void Grid::move()
{
    //No need for wall
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(_grid[i][j] != nullptr)
            {
                //cout << "HELLO" << endl;
                _grid[i][j]->move(_grid);
            }
        }
    }
}

void Grid::breed()
{
    //No need for wall
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(_grid[i][j] != nullptr)
            {
                _grid[i][j]->breed(_grid);
            }
        }
    }
}

void Grid::reset_move()
{
    //Go through the grid and set every moved to false
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(_grid[i][j] != nullptr)
            {
                _grid[i][j]->set_moved(false);
            }
        }
    }
}

bool Grid::is_blank()
{
    //Check if is all blank
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(_grid[i][j] != nullptr && _grid[i][j]->get_type() != 1)
            {
                return false;
            }
        }
    }
    return true;
}

bool Grid::all_prey()
{
    //Check if it is all preys
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            //If it is null pointer, return false
            if(_grid[i][j] == nullptr)
                return false;

            //If it is not type prey and wall, then it is not all prey
            if(_grid[i][j]->get_type() != 2 && _grid[i][j]->get_type() != 1)
            {
                return false;
            }
        }
    }
    return true;
}

ostream& operator << (ostream& outs, const Grid& print_me)
{
    for(int i = 0; i < MAX; i++)
    {
        outs << "|";
        for(int j = 0; j < MAX; j++)
        {
            if(print_me._grid[i][j] == nullptr)
                outs << " ";
            else
                print_me._grid[i][j]->print();
            outs << "|";
        }
        outs << endl;
    }
    return outs;
}

void Grid::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            Location loc;
            loc._r = i;
            loc._c = j;
            if(_grid[i][j] != nullptr)
                _grid[i][j]->draw(window, loc);
            else
            {
                //cout << "Drawing blank" << endl;
                sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                rectangle.move(sf::Vector2f(loc._r * CELL_SIZE, loc._c * CELL_SIZE));
                rectangle.setFillColor(sf::Color::White);
                window.draw(rectangle);
            }
        }
    }
}

void Grid::command_functions_to(int command, Location loc)
{
    //command = 1: B is pressed: randomly breed a grid
    //command = 2: K is pressed: randomly kill a grid
    //command = 3: left click: if it is empty, create prey
    //command = 3: left click: if it is not empty, kill
    //command = 4: right click: if it is empty, create predator
    //command = 4: right click: if it is not empty, breed
    Location temp;

    switch (command) {
    case 1:
        cout << "Randomly Breed" << endl;
        if(all_prey() || is_blank())
            break;
        temp = random_location();
        //If it is nullptr or it does not have blank space around it for it to breed, then find another location
        while (_grid[temp._r][temp._c] == nullptr || _grid[temp._r][temp._c]->find_blank(_grid)._r == -1) {
            temp = random_location();
        }
        _grid[temp._r][temp._c]->force_breed(_grid);
        break;
    case 2:
        cout << "Randomly Kill" << endl;
        if(is_blank())
            break;
        temp = random_location();
        //If it is nullptr, it cannot kill
        while (_grid[temp._r][temp._c] == nullptr || _grid[temp._r][temp._c]->get_type() == 1) {
            temp = random_location();
        }
        _grid[temp._r][temp._c]->kill(_grid);
        break;
    case 3:
        if(_grid[loc._r][loc._c] == nullptr)
        {
            cout << "Adding Prey" << endl;
            _grid[loc._r][loc._c] = new Prey(loc);
        }
        else {
            cout << "Killing" << endl;
            if(_grid[loc._r][loc._c]->get_type() != 1)
                _grid[loc._r][loc._c]->kill(_grid);
        }
        break;
    case 4:
        if(_grid[loc._r][loc._c] == nullptr)
        {
            cout << "Adding Predator" << endl;
            _grid[loc._r][loc._c] = new Predator(loc);
        }
        else {
            cout << "Breeding" << endl;
            _grid[loc._r][loc._c]->force_breed(_grid);
        }
        break;
    }
}

Location Grid::random_location()
{
    Location loc;
    srand(time(0));
    loc._r = (rand() % MAX);
    loc._c = (rand() % MAX);
    return loc;
}

void Grid::calculate()
{
    pred_num = 0;
    prey_num = 0;
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(_grid[i][j] != nullptr)
            {
                if(_grid[i][j]->get_type() == 2)
                    prey_num ++;
                else if(_grid[i][j]->get_type() == 3)
                    pred_num ++;
            }
        }
    }
}

int Grid::get_pred_num()
{
    return pred_num;
}

int Grid::get_prey_num()
{
    return prey_num;
}

int Grid::get_generation()
{
    return generation;
}

