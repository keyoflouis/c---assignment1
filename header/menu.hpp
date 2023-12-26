#pragma once
#include <vector>
#include "file.hpp"
#include "menu_item.hpp"
#include "keyboard.hpp"
#include "ui.hpp"

using namespace std;
class menu
{
public:
    vector<menu_item> menu_manage;

public:
    menu(/* args */);
    ~menu();
    void show_menu();
    int add_menu();
    int remov_menu();
    int modify_menu();
    menu_item match(int numb);
};
extern menu *menus;
