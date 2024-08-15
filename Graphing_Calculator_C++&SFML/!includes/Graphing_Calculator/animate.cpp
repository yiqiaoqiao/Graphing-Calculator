#include "animate.h"

Animate::Animate():_info(new Graph_info()), _sidebar_button(new Sidebar_button(_info)), _system(_info), _sidebar(_info, _sidebar_button)
{
    function_input = false;
    help_sidebar = false;
    function_str = "";
    //Font:
    //Loading font
    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    function_input_text.setFont(font);
    function_input_text.setCharacterSize(30);
    function_input_text.setColor(sf::Color::Blue);

    //Draw input box
    input_box.setSize(sf::Vector2f(_info->graph_dimensions.x - 20, 40));
    input_box.setFillColor(sf::Color(196, 202, 206));
    input_box.setPosition(sf::Vector2f(_info->graph_space + 10, _info->graph_space + 10));

    window.create(sf::VideoMode(_info->window_dimensions.x, _info->window_dimensions.y), "Graphing Calculator");
    window.setFramerateLimit(6);
    window.setVerticalSyncEnabled(true);

    //Tokenizer
    token.set_eqn(_info->equation);
    _info->infix = token.find_infix();
    //cout << "Infix: " << _info->infix << endl;
}

void Animate::run()
{
    int command = -1;
    _system.step(command, _info);
    _system.draw(window);
    _sidebar.draw(window);
    while (window.isOpen()) {
        processEvent(command);
        update(command);
        render();
    }
}

void Animate::render()
{
    window.clear();
    _system.draw(window);
    if(!help_sidebar)
        _sidebar.draw(window);
    else
        help();
    if(function_input)
    {
            //cout << "draw input" << endl;
        draw_input();
    }
    window.display();
}

void Animate::update(int command)
{
    _system.step(command, _info);
}

void Animate::processEvent(int &command)
{
    /*
     * For command:
     * 1 is zoom in --> control + enter
     * 2 is zoom out --> control + right shift
     * 3 is pan up --> arrow up
     * 4 is pan down --> arrow down
     * 5 is pan left --> arrow left
     * 6 is pan right --> arrow right
     */
    sf::Event event;
    command = 0;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        // "close requested" event: we close the window
        case sf::Event::Closed:
            cout<<"close event was encountered!"<<endl;
            window.close();
            break;

            //Text Enter
        case sf::Event::TextEntered:
            if(event.text.unicode == 70 || event.text.unicode == 102)
            {
                    //cout << "f entered" << endl;
                function_input = true;
            }
            else if(function_input)
            {
                    //cout << "text entered" << endl;
                if(event.text.unicode < 128)
                {
                    if(event.text.unicode == '\b')
                    {
                        if(function_str.size() > 0)
                        {
                            function_str.pop_back();
                            //cout << "function str: " << function_str << endl;
                        }
                    }
                    else
                        function_str += static_cast<char>(event.text.unicode);
                    function_input_text.setString(function_str);
                }
            }
            break;

            //Key pressed
        case sf::Event::KeyPressed:

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                //zoom out
                command = 2;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                //pan up, arrow up
                command = 3;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                //pan down, arrow down
                command = 4;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                //pan left, arrow left
                command = 5;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                //pan right, arrow right
                command = 6;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
                //Save button
                _sidebar.save();
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                //If not inputting the function
                if(!function_input)
                {
                    //Reset the origin and domain
                    _info->origin.x = _info->calculator_dimensions.x/2;
                    _info->origin.y = _info->calculator_dimensions.y/2;
                    _info->domain.x = -5;
                    _info->domain.y = 5;
                    command = 10;
                }

            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
                //Exit help sidebar
                help_sidebar = false;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            {
                    //cout << "input function" << endl;
                function_input_text.setString("f(x)=");
                function_input = true;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                if(function_input)
                {
                        //cout << "function: " << function_str << endl;
                    if(function_str != "")
                    {
                        _info->equation = function_str;
                        token = Tokenizer(_info->equation);
                        _info->infix = token.get_infix();
                        _sidebar.add_new_function();
                    }
                    command = 10;
                    function_input = false;
                    //Delete everything
                    function_str = "";
                }
                else
                {
                    //zoom in
                    command = 1;
                }
            }
            break;

            //Mouse click
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                _info->mouse_click.x = event.mouseButton.x;
                _info->mouse_click.y = event.mouseButton.y;
            }

            //Make sure help sidebar is not open
            if(!help_sidebar)
            {
                if(_info->mouse_click.x >= _info->calculator_dimensions.x)
                {
                    if(_sidebar.function_clicked())
                    {
                        //Change equation, need to draw points again
                        command = 10;
                        token = Tokenizer(_info->equation);
                            //cout << "equation: " << _info->equation << endl;
                        _info->infix = token.find_infix();

                    }
                }
                int which_button = 0;
                test_button(which_button);
                if(which_button == 3)
                {
                    //SAVE
                    cout << "SAVE" << endl;
                    _sidebar.save();
                }
                else if(which_button == 4)
                {
                    //DELETE FUNCTION
                    cout << "DELETE FUNCTION" << endl;
                    _info->equation = "";
                    command = 10;
                }
                else if(which_button == 2)
                {
                    //CLEAR HISTORY
                    cout << "CLEAR HISTORY" << endl;
                    _sidebar.clear_history();
                }
                else if(which_button == 1)
                {
                    //HELP
                    help_sidebar = true;
                }
                /*
                 * //TESTED
                if(which_button == 1)
                    cout << "HELP" << endl;
                else if(which_button == 2)
                    cout << "CLEAR HISTORY" << endl;
                else if(which_button == 3)
                    cout << "SAVE" << endl;
                else if(which_button == 4)
                    cout << "DELETE FUNCTION" << endl;
                    */
            }

            break;


        }
    }
}

void Animate::test_button(int& which_button)
{
        //cout << "Checking buttons" << endl;
        //cout << "mouse click: " << _info->mouse_click.x << endl;
        //cout << "save x length: " << _sidebar_button->save_x_limit.x << ", " << _sidebar_button->save_x_limit.y << endl;
        //cout << "mouse click: " << _info->mouse_click.y << endl;
        //cout << "save x length: " << _sidebar_button->save_y_limit.x << ", " << _sidebar_button->save_y_limit.y << endl;
    /*
     * botton is 1 if it click on help
     * botton is 2 if it click on clear history
     * botton is 3 if it click on save
     * botton is 4 if it click on delete function
     */
    if(_info->mouse_click.x >= _sidebar_button->help_x_limit.x && _info->mouse_click.x <= _sidebar_button->help_x_limit.y)
    {
        if(_info->mouse_click.y >= _sidebar_button->help_y_limit.x && _info->mouse_click.y <= _sidebar_button->help_y_limit.y)
        {
            which_button = 1;
        }
    }

    if(_info->mouse_click.x >= _sidebar_button->save_x_limit.x && _info->mouse_click.x <= _sidebar_button->save_x_limit.y)
    {
        if(_info->mouse_click.y >= _sidebar_button->save_y_limit.x && _info->mouse_click.y <= _sidebar_button->save_y_limit.y)
        {
            which_button = 3;
        }
    }

    if(_info->mouse_click.x >= _sidebar_button->delete_x_limit.x && _info->mouse_click.x <= _sidebar_button->delete_x_limit.y)
    {
        if(_info->mouse_click.y >= _sidebar_button->delete_y_limit.x && _info->mouse_click.y <= _sidebar_button->delete_y_limit.y)
        {
            which_button = 4;
        }
    }

    if(_info->mouse_click.x >= _sidebar_button->clear_x_limit.x && _info->mouse_click.x <= _sidebar_button->clear_x_limit.y)
    {
        if(_info->mouse_click.y >= _sidebar_button->clear_y_limit.x && _info->mouse_click.y <= _sidebar_button->clear_y_limit.y)
        {
            which_button = 2;
        }
    }

        //cout << "WHICH BUTTON: " << which_button << endl;
}

void Animate::draw_input()
{
    //DRAW BORDERS
    //Construct
    sf::RectangleShape upper_border(sf::Vector2f(_info->graph_dimensions.x - 20, 2));
    sf::RectangleShape lower_border(sf::Vector2f(_info->graph_dimensions.x - 20, 2));
    sf::RectangleShape left_border(sf::Vector2f(2, 40));
    sf::RectangleShape right_border(sf::Vector2f(2, 42));

    //Fill color
    upper_border.setFillColor(sf::Color(82, 210, 255));
    lower_border.setFillColor(sf::Color(82, 210, 255));
    left_border.setFillColor(sf::Color(82, 210, 255));
    right_border.setFillColor(sf::Color(82, 210, 255));

    //Move position
    upper_border.setPosition(sf::Vector2f(_info->graph_space + 10, _info->graph_space + 10));
    lower_border.setPosition(sf::Vector2f(_info->graph_space + 10, _info->graph_space + 50));
    left_border.setPosition(sf::Vector2f(_info->graph_space + 10, _info->graph_space + 10));
    right_border.setPosition(sf::Vector2f(_info->graph_dimensions.x + 10, _info->graph_space + 10));

    function_input_text.setPosition(sf::Vector2f(_info->graph_space + 10, _info->graph_space + 10));
    window.draw(input_box);
    window.draw(upper_border);
    window.draw(lower_border);
    window.draw(left_border);
    window.draw(right_border);
    window.draw(function_input_text);
}

void Animate::help()
{
    float height = 5;
    float TEXT_HEIGHT = 30;
    float LEFT_MARGIN = 10;
    sf::RectangleShape help_sidebar;
    help_sidebar.setFillColor(sf::Color(196, 202, 206));
    help_sidebar.setPosition(sf::Vector2f(_info->calculator_dimensions.x, 0));
    help_sidebar.setSize(sf::Vector2f(_info->sidebar_dimensions.x, _info->sidebar_dimensions.y));
    window.draw(help_sidebar);

    sf::Text help_text;
    help_text.setFont(font);
    help_text.setCharacterSize(15);
    help_text.setStyle(sf::Text::Bold);
    help_text.setColor(sf::Color::Black);

    string text = "Help:";
    help_text.setString(text);
    help_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, height));
    window.draw(help_text);
    height += TEXT_HEIGHT;

    //Zoom in
    text = "Zoom in: Enter";
    help_text.setString(text);
    help_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, height));
    window.draw(help_text);
    height += TEXT_HEIGHT;

    //Zoom out
    text = "Zoom out: Shift + Enter";
    help_text.setString(text);
    help_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, height));
    window.draw(help_text);
    height += TEXT_HEIGHT;

    //Pan
    text = "Pan: Up, Down, Left, Right";
    help_text.setString(text);
    help_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, height));
    window.draw(help_text);
    height += TEXT_HEIGHT;

    //Save
    text = "Save: F1";
    help_text.setString(text);
    help_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, height));
    window.draw(help_text);
    height += TEXT_HEIGHT;

    //Function Input
    text = "Function Input: f / Enter";
    help_text.setString(text);
    help_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, height));
    window.draw(help_text);
    height += TEXT_HEIGHT;

    //Center
    text = "Reset (origin and domain): Space";
    help_text.setCharacterSize(14);
    help_text.setString(text);
    help_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, height));
    window.draw(help_text);
    height += TEXT_HEIGHT;

    //Exit help sidebar
    text = "Exit help sidebar: h";
    help_text.setCharacterSize(15);
    help_text.setString(text);
    help_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, height));
    window.draw(help_text);
    height += TEXT_HEIGHT;
}
