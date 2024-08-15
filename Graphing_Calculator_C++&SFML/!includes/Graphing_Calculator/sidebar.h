#ifndef SIDEBAR_H
#define SIDEBAR_H
#include "../../!includes/Graphing_Calculator/graph_info.h"
#include "../../!includes/Vector_class/vector.h"
#include "../../!includes/Graphing_Calculator/sidebar_button.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const double LEFT_MARGIN = 10.0;
const float TEXT_HEIGHT = 30.0;

class Sidebar
{
public:
    Sidebar();
    Sidebar(Graph_info* info, Sidebar_button* sidebar_button);
    void draw(sf::RenderWindow& window);
    void draw_functions(sf::RenderWindow& window);
    void read();
    void save();
    void clear_history();
    void add_new_function();
    bool function_clicked();
private:
    Graph_info* _info;
    Vector<string> _functions;
    sf::RectangleShape rect;            //sidebar rectangle
    sf::Font font;                      //used to draw text
    sf::Text sb_text;
    Sidebar_button* _sidebar_button;
    float function_height;
};

#endif // SIDEBAR_H
