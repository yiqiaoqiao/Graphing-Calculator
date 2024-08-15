#include "plot.h"

Plot::Plot(Graph_info* info):_info(info)
{
    //DO NOTHING
}

Vector<sf::Vector2f> Plot::operator()()
{
    cout << "Updating plot" << endl;
    Vector<sf::Vector2f> points;
    if(_info->equation != "")
    {

        Coor_translator trans(_info);

        //Shunting Yard works
        Shunting_yard sy(_info->infix);
        _post_fix = sy.get_postfix();
            //cout << "SY:" << sy << endl;

        RPN rpn(_post_fix);
        double min = _info->domain.x;
        double max = _info->domain.y;
            //cout << "Min: " << min << endl;
            //cout << "Max: " << max << endl;
        double space = (max - min)/(_info->points);

        //Find all the points that is screen x and y
        for(double i = min; i <= max; i += space)
        {
            sf::Vector2f pt(i, rpn.get_y(i));
                //cout << "points: " << "(" << i << ", " << i << ")" << endl;
            sf::Vector2f graph_pt = trans.translate(pt);

            //Check if points is more than the graphing area
            if(graph_pt.y > _info->graph_space && graph_pt.y < (_info->graph_dimensions.y + _info->graph_space))
                points.push_back(graph_pt);
        }
    }

    return points;
}
