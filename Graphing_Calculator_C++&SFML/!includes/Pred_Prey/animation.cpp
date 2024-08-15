#include "animation.h"

Anim::Anim():sidebar(WORK_PANEL, SIDE_BAR){
    pause = true;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Predator - Prey");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    //
    //or... window.create(sf::VideoMode(...
    window.setFramerateLimit(3);
}

void Anim::run()
{
   while (window.isOpen())
   {
       processEvents();
       if(!pause)
           update();
       sidebar_update();
       render();
   }
}

void Anim::processEvents()
   {
       sf::Event event;
       while (window.pollEvent(event))//or waitEvent
           {
           // check the type of the event...
             switch (event.type)
             {
                   // window closed
                   // "close requested" event: we close the window
              case sf::Event::Closed:
                       window.close();
                       break;

                   // key pressed
              case sf::Event::KeyPressed:
                       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                       {
                           if(pause)
                               pause = false;
                           else
                               pause = true;
                       }
                       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                       {
                           Location loc;
                           loc._r = 0;
                           loc._c = 0;
                           grid.command_functions_to(1, loc);
                       }
                       else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                       {
                           Location loc;
                           loc._r = 0;
                           loc._c = 0;
                           grid.command_functions_to(2, loc);
                       }
                       break;
               case sf::Event::MouseButtonReleased:
                       if (event.mouseButton.button == sf::Mouse::Right)
                       {
                           Location loc;
                           loc._r = event.mouseButton.x / CELL_SIZE;
                           loc._c = event.mouseButton.y / CELL_SIZE;
                           /*
                           std::cout << "the right button was pressed" << std::endl;
                           std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                           std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                           */
                           grid.command_functions_to(4, loc);
                       }
                       else
                       {
                           Location loc;
                           loc._r = event.mouseButton.x / CELL_SIZE;
                           loc._c = event.mouseButton.y / CELL_SIZE;
                           /*
                           std::cout << "the left button was pressed" << std::endl;
                           std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                           std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                           */
                           grid.command_functions_to(3, loc);
                       }
                       break;
               default:
                       break;
               }
           }
    }


void Anim::update()
{
    grid.step();
}

void Anim::sidebar_update()
{
    grid.calculate();
}

void Anim::render(){
       window.clear();
       grid.draw(window);
       sidebar.draw(window, get_predator(), get_prey(), get_generation());
       window.display();
}

int Anim::get_predator()
{
    return grid.get_pred_num();
}

int Anim::get_prey()
{
    return grid.get_prey_num();
}

int Anim::get_generation()
{
    return grid.get_generation();
}
