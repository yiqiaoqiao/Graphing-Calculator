#include "sidebar_button.h"

Sidebar_button::Sidebar_button(Graph_info* info)
{
    equation_size.x = 5;
    equation_size.y = equation_size.x + TEXT_HEIGHT;

    domain_size.x = equation_size.y;
    domain_size.y = domain_size.x + TEXT_HEIGHT;

    help_x_limit.x = info->calculator_dimensions.x + 10;
    help_x_limit.y = info->calculator_dimensions.x + 60;
    help_y_limit.x = domain_size.y + 1;
    help_y_limit.y = help_y_limit.x + TEXT_HEIGHT;

    clear_x_limit.x = info->calculator_dimensions.x + 85;
    clear_x_limit.y = info->calculator_dimensions.x + info->sidebar_dimensions.x - 15;
    clear_y_limit.x = domain_size.y + 1;
    clear_y_limit.y = clear_y_limit.x + TEXT_HEIGHT;

    delete_x_limit.x = info->calculator_dimensions.x + 85;
    delete_x_limit.y = info->calculator_dimensions.x + info->sidebar_dimensions.x - 15;
    delete_y_limit.x = help_y_limit.y + 1;
    delete_y_limit.y = delete_y_limit.x + TEXT_HEIGHT;

    save_x_limit.x = info->calculator_dimensions.x + 10;
    save_x_limit.y = info->calculator_dimensions.x + 60;
    save_y_limit.x = help_y_limit.y + 1;
    save_y_limit.y = save_y_limit.x + TEXT_HEIGHT;
}
