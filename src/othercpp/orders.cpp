#include<string.h>
#include"order.hpp"

order::order(/* args */)
{
}

order::order(char *id, char *menu_item_name)
{
    
    strcpy_s(this->who_id,id);
    strcpy_s(this->menu_item_name,menu_item_name);
}

order::~order()
{
}