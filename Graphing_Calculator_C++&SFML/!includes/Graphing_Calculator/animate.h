#ifndef ANIMATE_H
#define ANIMATE_H
#include "../../!includes/Graphing_Calculator/graph_info.h"
#include "../../!includes/Graphing_Calculator/system.h"
#include "../../!includes/Graphing_Calculator/sidebar.h"
#include "../../!includes/Graphing_Calculator/tokenizer.h"
#include "../../!includes/Graphing_Calculator/sidebar_button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Animate
{
public:
    Animate();
    void run();
    void processEvent(int& command);
    void update(int command);
    void render();
    void draw_input();
    void test_button(int& which_button);
    void help();
private:
    Graph_info* _info;
    Sidebar_button* _sidebar_button;
    System _system;
    sf::RenderWindow window;
    sf::Text function_input_text;
    sf::RectangleShape input_box;
    string function_str;
    sf::Font font;
    Sidebar _sidebar;
    Tokenizer token;
    bool function_input;
    bool help_sidebar;
};

#endif // ANIMATE_H
