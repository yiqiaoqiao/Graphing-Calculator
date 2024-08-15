#ifndef GRID_H
#define GRID_H

#include "../../!includes/Pred_Prey/creature.h"
#include "../../!includes/Pred_Prey/wall.h"
#include "../../!includes/Pred_Prey/predator.h"
#include "../../!includes/Pred_Prey/prey.h"
#include <iostream>
#include "../../!includes/Pred_Prey/constant.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

using namespace std;


class Grid
{   
public:
    Grid();

    void fill_grid();
    void fill_wall();
    void fill_prey();
    void fill_predator();

    void step();        //calls functions move, breed, kill
    void move();
    void breed();
    void reset_move();      //Reset all the moved to false
    bool is_blank();     //Check if the array is empty
    bool all_prey();     //Check if the array is all preys
    friend ostream& operator << (ostream& outs, const Grid& print_me);

    //SFML
    void draw(sf::RenderWindow& window);
    void command_functions_to(int command, Location loc);
    void calculate();
    int get_pred_num();
    int get_prey_num();
    int get_generation();

    //Functions to support command functions to
    Location random_location();

private:
    Creature* _grid[MAX][MAX];
    int pred_num;
    int prey_num;
    int generation;
};

#endif // GRID_H
