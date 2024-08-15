#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include "../../!includes/Pred_Prey/constant.h"
#include "../../!includes/Pred_Prey/grid.h"
#include "../../!includes/Pred_Prey/sidebar.h"

class Anim{
public:
    Anim();
    void run();                         //call process, update, and render
    void processEvents();               //handle keyboard and mouse events
    void update();                      //prepare the next frame
    void sidebar_update();
    void render();                      //draw and display the next frame
    int get_predator();
    int get_prey();
    int get_generation();
private:
    sf::RenderWindow window;
    Grid grid;
    bool pause;
    Sidebar sidebar;
};

#endif // ANIMATION_H
