#ifndef PLOT_H
#define PLOT_H
#include "../../!includes/Graphing_Calculator/graph_info.h"
#include "../../!includes/Graphing_Calculator/coor_translator.h"
#include "../../!includes/Vector_class/vector.h"
#include "../../!includes/RPN_Shunting_Yard/shunting_yard.h"
#include "../../!includes/List_Functions/queue.h"
#include "../../!includes/RPN_Shunting_Yard/token.h"
#include "../../!includes/Graphing_Calculator/rpn.h"

class Plot
{
public:
    Plot(Graph_info* info);
    Vector<sf::Vector2f> operator()();
private:
    Graph_info* _info;
    Queue<Token*> _post_fix;
};

#endif // PLOT_H
