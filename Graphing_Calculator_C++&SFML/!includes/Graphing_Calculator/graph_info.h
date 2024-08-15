#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include "../../!includes/List_Functions/queue.h"
#include "../../!includes/RPN_Shunting_Yard/token.h"
#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>

using namespace std;

struct Graph_info
{
public:
    Graph_info();
    string equation;
    Queue<Token*> infix;
    int points;
    double scale;
    int graph_space;
    sf::Vector2f origin;
    sf::Vector2f domain;
    sf::Vector2f window_dimensions;
    sf::Vector2f sidebar_dimensions;
    sf::Vector2f calculator_dimensions;
    sf::Vector2f graph_dimensions;
    sf::Vector2f mouse_click;
};

#endif // GRAPH_INFO_H
