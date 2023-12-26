#include "menu_item.hpp"
#include <string.h>

menu_item::menu_item(const char *Name, int Price)
{
    strcpy_s(name, Name);
    price = Price;
}

menu_item::menu_item()
{
}

menu_item::~menu_item()
{
}
