#ifndef COOR_TRANSLATOR_H
#define COOR_TRANSLATOR_H
#include "../../!includes/Graphing_Calculator/graph_info.h"
#include <SFML/Graphics.hpp>

class Coor_translator
{
public:
    Coor_translator(Graph_info* info);
    sf::Vector2f translate(sf::Vector2f point);
private:
    Graph_info* _info;
};

#endif // COOR_TRANSLATOR_H
