#include "graph_info.h"

Graph_info::Graph_info()
{
    equation = "";
    points = 1000;
    domain.x = -5;
    domain.y = 5;
    graph_space = 20;
    window_dimensions.x = 1050;
    window_dimensions.y = 550;
    sidebar_dimensions.x = 250;
    sidebar_dimensions.y = 550;
    calculator_dimensions.x = 800;
    calculator_dimensions.y = 550;
    graph_dimensions.x = calculator_dimensions.x - 2*graph_space;
    graph_dimensions.y = calculator_dimensions.y - 2*graph_space;
    scale = graph_dimensions.x / (domain.y - domain.x);
    origin.x = calculator_dimensions.x / 2;
    origin.y = calculator_dimensions.y / 2;
    mouse_click.x = 0;
    mouse_click.y = 0;
}
