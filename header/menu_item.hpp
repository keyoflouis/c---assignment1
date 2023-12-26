#pragma once
#include <vector>
#include <string>

using namespace std;

class menu_item
{
public:
    char name[64];
    int price;
    

public:
    menu_item(const char *Name, int Price);
    menu_item();
    ~menu_item();
};
