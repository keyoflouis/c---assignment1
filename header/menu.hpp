#pragma once
#include<vector>
#include"file.hpp"
#include"menu_item.hpp"

using namespace std;
class menu
{
public:
vector<menu_item> menu_manage;

public:
    menu(/* args */);
    ~menu();
    void show_menu(vector<menu_item> manage,file *fl);
    int add_menu(menu_item temp_add,file* fl,keyboard*);
    int remov_menu(char name[64],file* fl,keyboard* kb,ui *System);
    int modify_menu(char *Name,file* fl,keyboard* kb,ui *System);
    menu_item match(int numb);
};
