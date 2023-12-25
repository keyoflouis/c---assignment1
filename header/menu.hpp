#pragma once
#include<vector>
#include"file.hpp"
#include"menu_item.hpp"
#include"keyboard.hpp"
#include"ui.hpp"

using namespace std;
class menu
{
public:
vector<menu_item> menu_manage;

public:
    menu(/* args */);
    ~menu();
    void show_menu(vector<menu_item> manage);
    int add_menu(menu_item temp_add);
    int remov_menu(char name[64]);
    int modify_menu(char *Name);
    menu_item match(int numb);
};
extern menu*  menus;
