#include <string.h>
#include "order.hpp"
/*
order::order(const order &other)
{
    order_number = new order_sequance(*(other.order_number));
    strcpy_s(this->who_id, sizeof(this->who_id), other.who_id);
    strcpy_s(this->menu_item_name, sizeof(this->menu_item_name), other.menu_item_name);
}
*/

order::order(/* args */)
{
   order_sequance order_number();
}

order::order(char *id, char *menu_item_name)
{
   order_sequance order_number();
    strcpy_s(this->who_id, id);
    strcpy_s(this->menu_item_name, menu_item_name);
}

order::~order()
{
}