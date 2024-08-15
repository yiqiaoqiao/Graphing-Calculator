#include "sidebar.h"

Sidebar::Sidebar()
{
    //DO NOTHING
}

Sidebar::Sidebar(Graph_info* info, Sidebar_button* sidebar_button): _info(info), _sidebar_button(sidebar_button)
{
    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(196, 202, 206));
    rect.setPosition(sf::Vector2f(_info->calculator_dimensions.x, 0));
    rect.setSize(sf::Vector2f(_info->sidebar_dimensions.x, _info->sidebar_dimensions.y));

    //Font
    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

        //cout<<"Sidebar CTOR: Text object initialized."<<endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(15);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color::Black);

    read();
}


void Sidebar::draw(sf::RenderWindow& window)
{
    sf::RectangleShape button;
    button.setFillColor(sf::Color(82, 210, 255));
    window.draw(rect);
    float height = 5;
    string text = "";

    //Draw equation
    sb_text.setString(_info->equation);
    sb_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, _sidebar_button->equation_size.x));
    window.draw(sb_text);

    //Draw domain
    text = "(" + to_string(_info->domain.x) + ", " + to_string(_info->domain.y) + ")";
    sb_text.setString(text);
    sb_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, _sidebar_button->domain_size.x));
    window.draw(sb_text);

    //Draw help
    text = "HELP";
    button.setSize(sf::Vector2f(_sidebar_button->help_x_limit.y - _sidebar_button->help_x_limit.x,
                                _sidebar_button->help_y_limit.y - _sidebar_button->help_y_limit.x));
    button.setPosition(sf::Vector2f(_sidebar_button->help_x_limit.x, _sidebar_button->help_y_limit.x));
    window.draw(button);
    sb_text.setString(text);
    sb_text.setPosition(sf::Vector2f(_sidebar_button->help_x_limit.x + 5, _sidebar_button->help_y_limit.x + 5));
    window.draw(sb_text);

    //Draw Clear History
    text = "CLEAR HISTORY";
    button.setSize(sf::Vector2f(_sidebar_button->clear_x_limit.y - _sidebar_button->clear_x_limit.x,
                                _sidebar_button->clear_y_limit.y - _sidebar_button->clear_y_limit.x));
    button.setPosition(sf::Vector2f(_sidebar_button->clear_x_limit.x, _sidebar_button->clear_y_limit.x));
    window.draw(button);
    sb_text.setString(text);
    sb_text.setPosition(sf::Vector2f(_sidebar_button->clear_x_limit.x + 5, _sidebar_button->clear_y_limit.x + 5));
    window.draw(sb_text);


    //Draw SAVE
    text = "SAVE";
    button.setSize(sf::Vector2f(_sidebar_button->save_x_limit.y - _sidebar_button->save_x_limit.x,
                                _sidebar_button->save_y_limit.y - _sidebar_button->save_y_limit.x));
    button.setPosition(sf::Vector2f(_sidebar_button->save_x_limit.x, _sidebar_button->save_y_limit.x));
    window.draw(button);
    sb_text.setString(text);
    sb_text.setPosition(sf::Vector2f(_sidebar_button->save_x_limit.x + 5, _sidebar_button->save_y_limit.x + 5));
    window.draw(sb_text);

    //Draw DELETE f(x)
    text = "DELETE f(x)";
    button.setSize(sf::Vector2f(_sidebar_button->delete_x_limit.y - _sidebar_button->delete_x_limit.x,
                                _sidebar_button->delete_y_limit.y - _sidebar_button->delete_y_limit.x));
    button.setPosition(sf::Vector2f(_sidebar_button->delete_x_limit.x, _sidebar_button->delete_y_limit.x));
    window.draw(button);
    sb_text.setString(text);
    sb_text.setPosition(sf::Vector2f(_sidebar_button->delete_x_limit.x + 5, _sidebar_button->delete_y_limit.x + 5));
    window.draw(sb_text);

    //Draw distinct line
    sf::RectangleShape line(sf::Vector2f(_info->sidebar_dimensions.x, 1));
    line.setPosition(_info->calculator_dimensions.x, _sidebar_button->save_y_limit.y + 10);
    line.setFillColor(sf::Color::Black);
    window.draw(line);
    height = _sidebar_button->save_y_limit.y + 15;

    //Draw functions
    function_height = height;
    draw_functions(window);
}

void Sidebar::read()
{
    ifstream fin;
    string function;
    fin.open("Functions.txt");
    if(fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    while (!fin.eof()) {
        getline(fin, function);
        if(function != "")
            _functions.push_back(function);
    }
    fin.close();
}

void Sidebar::add_new_function()
{
    //Check if equation is nothing
    bool in_list = false;

    if(_info->equation != "")
    {
        //Check if the equation is already in the list, if not, add to the list
        for(int i = 0; i < _functions.size(); i++)
        {
            if(_functions[i] == _info->equation)
            {
                in_list = true;
                break;
            }
        }

        if(!in_list)
            _functions.push_back(_info->equation);
    }

}

void Sidebar::clear_history()
{
        //cout << "FUNCTION SIZE: " << _functions.size() << endl;
    _functions.set_size(0);
        //cout << "function size: " << _functions.size() << endl;
}

void Sidebar::save()
{
    ofstream fout;
    fout.open("Functions.txt");
    if(fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    if(_functions.size() != 0)
        fout << _functions[0];
    //Write everything to the file
    for(int i = 1; i < _functions.size(); i++)
    {
        fout << endl << _functions[i];
    }
    fout.close();
    cout << "Saved" << endl;
}

void Sidebar::draw_functions(sf::RenderWindow& window)
{
    string text = "";
    float height = function_height;
    for(int i = _functions.size() - 1; i >= 0; i--)
    {
        text = _functions[i];
        sb_text.setString(text);
        sb_text.setPosition(sf::Vector2f(_info->calculator_dimensions.x + LEFT_MARGIN, height));
        window.draw(sb_text);
        height += TEXT_HEIGHT;
        if(height > _info->window_dimensions.y)
            break;
    }
}

bool Sidebar::function_clicked()
{
    float height = _info->mouse_click.y - function_height;
    if(height >= 0)
    {
        int entry = height / TEXT_HEIGHT;
        //cout << "entry: " << entry << endl;
        //cout << "size: " << _functions.size() << endl;
        if(entry < _functions.size() && entry >= 0)
        {
                //cout << "FUNCTION CLICKED" << endl;
            _info->equation = _functions[_functions.size() - 1 - entry];
            return true;
        }
    }

    return false;
}
