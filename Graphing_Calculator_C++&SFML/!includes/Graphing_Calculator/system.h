#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include "../../!includes/Graphing_Calculator/graph.h"
#include "../../!includes/Graphing_Calculator/graph_info.h"
#include <SFML/Graphics.hpp>

using namespace std;

class System
{
public:
    System(Graph_info* info);
    void draw(sf::RenderWindow& window);
    void step(int command, Graph_info* info);
private:
    Graph _g;
    //Graph_info* _info;
};

#endif // SYSTEM_H
