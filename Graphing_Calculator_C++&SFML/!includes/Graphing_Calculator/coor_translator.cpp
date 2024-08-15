#include "coor_translator.h"

Coor_translator::Coor_translator(Graph_info* info):_info(info)
{
    //DO NOTHING
}

sf::Vector2f Coor_translator::translate(sf::Vector2f point)
{
    double x_space = _info->graph_dimensions.x / (_info->domain.y - _info->domain.x);
    double y_space = _info->graph_dimensions.y / (_info->domain.y - _info->domain.x);
    double x = _info->origin.x + (x_space * point.x);
    double y = _info->origin.y + (y_space * (-point.y));
        //cout << "x: " << x << endl;
        //cout << "y: " << y << endl;
    sf::Vector2f result(x,y);
    return result;
}
