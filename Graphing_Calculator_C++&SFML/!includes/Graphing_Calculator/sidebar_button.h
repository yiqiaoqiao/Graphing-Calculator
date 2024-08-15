#ifndef SIDEBAR_BUTTON_H
#define SIDEBAR_BUTTON_H
#include "../../!includes/Graphing_Calculator/graph_info.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Sidebar_button
{
public:
    Sidebar_button(Graph_info* info);
    float TEXT_HEIGHT = 30;
    sf::Vector2f help_x_limit;
    sf::Vector2f help_y_limit;
    sf::Vector2f delete_x_limit;
    sf::Vector2f delete_y_limit;
    sf::Vector2f clear_x_limit;
    sf::Vector2f clear_y_limit;
    sf::Vector2f save_x_limit;
    sf::Vector2f save_y_limit;
    sf::Vector2f equation_size;
    sf::Vector2f domain_size;
};

#endif // SIDEBAR_BUTTON_H
