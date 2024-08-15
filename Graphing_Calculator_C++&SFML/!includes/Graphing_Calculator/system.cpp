#include "system.h"

System::System(Graph_info* info):_g(info)
{
    //DO NOTHING
}

void System::draw(sf::RenderWindow& window)
{
    _g.draw(window);
}

void System::step(int command, Graph_info* info)
{
    //double zoom_size = (info->domain.y - info->domain.x) / 10;
    float size = (info->domain.y - info->domain.x) / info->scale;
    //float zoom_in_size = 2/3;
    //float zoom_out_size = 3/2;
    //cout << "pansize: " << pan_size << endl;
    //cout << "domain_pan_size: " << domain_pan_size << endl;
    //cout << "origin.y: " << info->origin.y << endl;
    //cout << "command: " << command << endl;
    switch(command)
    {
    case 1:
        //zoom in
            //cout << "zoom in" << endl;
        info->domain.x *= 0.66f;
        info->domain.y *= 0.66f;
        info->scale = info->calculator_dimensions.x / (info->domain.y - info->domain.x);
        break;
    case 2:
        //zoom out
        info->domain.x *= 1.5f;
        info->domain.y *= 1.5f;
        info->scale = info->calculator_dimensions.x / (info->domain.y - info->domain.x);
        break;
    case 3:
        //pan up
        info->origin.y -= size * info->scale;
        break;
    case 4:
        //pan down
        info->origin.y += size * info->scale;
        break;
    case 5:
        //pan left
        info->origin.x += size * info->scale;
        info->domain.x -= size;
        info->domain.y -= size;
        //info->scale = info->calculator_dimensions.x / (info->domain.y - info->domain.x);
        break;
    case 6:
        //pan right
        info->origin.x -= size * info->scale;
        info->domain.x += size;
        info->domain.y += size;
        //info->scale = info->calculator_dimensions.x / (info->domain.y - info->domain.x);
        break;
    default:
        break;
    }

    if(command != 0)
        _g.update(info);
}
