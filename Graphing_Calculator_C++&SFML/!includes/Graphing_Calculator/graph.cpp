#include "graph.h"

Graph::Graph(Graph_info* info):_info(info), _plotter(info)
{
    //DO NOTHING
}

void Graph::draw(sf::RenderWindow& window)
{
    draw_plane(window);
    draw_graph_border(window);

    //Draw all the points
    for(int i = 0; i < _points.size(); i++)
    {
        sf::CircleShape point = sf::CircleShape(1);
        point.setPosition(_points[i].x, _points[i].y);
        window.draw(point);
    }
}

void Graph::draw_plane(sf::RenderWindow& window)
{
    //Draw x and y axis
    //Construct
    sf::RectangleShape x_axis(sf::Vector2f(_info->calculator_dimensions.x, 1));
    sf::RectangleShape y_axis(sf::Vector2f(1, _info->calculator_dimensions.y));

    //Move position
    x_axis.setPosition(sf::Vector2f(0, _info->origin.y));
    y_axis.setPosition(sf::Vector2f(_info->origin.x, 0));

    //Set color
    x_axis.setFillColor(sf::Color(82, 210, 255));
    y_axis.setFillColor(sf::Color(82, 210, 255));

    //draw
    if(_info->origin.y >= 0)
        window.draw(x_axis);
    if(_info->origin.x >= 0)
        window.draw(y_axis);
}

void Graph::draw_graph_border(sf::RenderWindow& window)
{
    //Construct
    sf::RectangleShape left_border(sf::Vector2f(1, _info->graph_dimensions.y));
    sf::RectangleShape right_border(sf::Vector2f(1, _info->graph_dimensions.y));
    sf::RectangleShape top_border(sf::Vector2f(_info->graph_dimensions.x, 1));
    sf::RectangleShape bottom_border(sf::Vector2f(_info->graph_dimensions.x, 1));

    //Set color
    left_border.setFillColor(sf::Color(82, 210, 255));
    right_border.setFillColor(sf::Color(82, 210, 255));
    top_border.setFillColor(sf::Color(82, 210, 255));
    bottom_border.setFillColor(sf::Color(82, 210, 255));

    //Move position
    left_border.setPosition(_info->graph_space, _info->graph_space);
    right_border.setPosition(_info->graph_space + _info->graph_dimensions.x, _info->graph_space);
    top_border.setPosition(_info->graph_space, _info->graph_space);
    bottom_border.setPosition(_info->graph_space, _info->graph_space + _info->graph_dimensions.y);

    //Draw
    window.draw(left_border);
    window.draw(right_border);
    window.draw(top_border);
    window.draw(bottom_border);
}

void Graph::update(Graph_info* info)
{
    _info = info;
        //cout << "FUNC:" << _info->equation << endl;
    //Plot class
    _points = _plotter();
}
