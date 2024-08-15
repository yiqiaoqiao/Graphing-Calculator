#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "../../!includes/Vector_class/vector.h"
#include "../../!includes/Graphing_Calculator/graph_info.h"
#include "../../!includes/Graphing_Calculator/plot.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Graph
{
public:
    Graph(Graph_info* info);
    void draw(sf::RenderWindow& window);
    void draw_plane(sf::RenderWindow& window);
    void draw_graph_border(sf::RenderWindow& window);
    void update(Graph_info* info);
private:
    Vector<sf::Vector2f> _points;
    Graph_info* _info;
    Plot _plotter;
};

#endif // GRAPH_H
