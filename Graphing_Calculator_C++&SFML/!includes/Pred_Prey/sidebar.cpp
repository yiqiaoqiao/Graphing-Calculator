#include "sidebar.h"
#include "../../!includes/Pred_Prey/constant.h"
#include <string.h>

Sidebar::Sidebar(){
    //DO NOTHING
}

Sidebar::Sidebar(float left, float width):_left(left), _width(width){
    cout<<"Sidebar CTOR: TOP"<<endl;
    //items.reserve(50);

    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(225,225,153)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(20);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color::Black);

    ////this is how you would position text on screen:
    //sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

    cout<<"Sidebar: CTOR: Exit."<<endl;
}

void Sidebar::draw(sf::RenderWindow& window, int pred, int prey, int round){

    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;

    window.draw(rect);
    float height = 10;

    string predator = "Predators: " + to_string(pred);
    string s_prey = "Preys: " + to_string(prey);
    string s_round = "Generations: " + to_string(round);
    string total = predator + "\n" + s_prey + "\n" + s_round;

    sb_text.setString(total);
    sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
    height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING;

    window.draw(sb_text);
}

/*
string& Sidebar::operator [](int index){
    return items[index];
}
*/
