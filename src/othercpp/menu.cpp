#include "menu.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include "menu_item.hpp"
#include "keyboard.hpp"
#include <string.h>
#include "ui.hpp"

using namespace std;

menu::menu(/* args */)
{
}

menu::~menu()
{
}

void menu::show_menu()
{
    // depend on the way of store a menu_item
    vector<menu_item> manage;
    manage = fl->load_menu();
    cout << "\t\t name   price" << endl;
    for (int i = 0; i < manage.size(); i++)
    {
        cout << manage[i].name << "    " << manage[i].price << endl;
    }
    getchar();
    return;
}

int menu::add_menu()
{
    cout << "Enter the name ,price,  of the dish you want to add to the" << endl;
    char name[64];
    strcpy(name, kb->get_consol());

    int price;
    cin >> price;
    fl-> menu_for_add.push_back(menu_item(name, price));

    fl->addtofile_Menu();
    return 0;
}

int menu::remov_menu()
{
    cout << " removing the menu ,type in the name" << endl;
    char name[64];
    strcpy(name, kb->get_consol());
    menu_manage = fl->load_menu();
    
    for (int i = 0; i < menu_manage.size(); i++)
    {
        if (strcmp(menu_manage[i].name, name) == 0)
        {
            System_ui->remov_menu_ui(name);
            int temp = kb->get_for_choose();
            if (temp == 49)
            {
                menu_manage.erase(menu_manage.begin() + i);
                fl->addtofile_Menu();
            }
            else if (temp == 50)
            {
                return 1;
            }
            else
            {
            }
            break;
        }
    }

    return 0;
}

int menu::modify_menu()
{
    cout << "modifying menu , type in the name " << endl;
    char Name[64];
    strcpy(Name, kb->get_consol());

    menu_manage = fl->load_menu();
    for (int i = 0; i < menu_manage.size(); i++)
    {
        if (strcmp(menu_manage[i].name, Name) == 0)
        {

            System_ui->modify_menu_ui();
            int temp = kb->get_for_choose();
            while (temp != 49 && temp != 50)
            {
                temp = kb->get_for_choose();
            }
            
            char *temp_49;
            int temp_50;
            switch (temp)
            {
            case 49:
                // modify name
                cout << " modifying the menu name" << endl;
                strcpy(temp_49, kb->get_consol());
                menu_manage = fl->load_menu();
                for (int i = 0; i < menu_manage.size(); i++)
                {
                    if (strcmp(menu_manage[i].name, Name) == 0)
                    {
                        strcpy(menu_manage[i].name, temp_49);
                        break;
                    }
                }

                fl->write_to_menu(menu_manage);
                break;

            case 50:
                // modify price
                cout << " modifying the menu price" << endl;

                cin >> temp_50;
                getchar();

                menu_manage = fl->load_menu();
                for (int i = 0; i < menu_manage.size(); i++)
                {
                    if (strcmp(menu_manage[i].name, Name) == 0)
                    {
                        menu_manage[i].price = temp_50;
                        break;
                    }
                }

            default:
                return true;
                break;
            }
            break;
        }
        else
        {
            cout << "cant find" << endl;
        }
    }
    fl->write_to_menu(menu_manage);
    return true;
}

menu_item menu::match(int numb)
{
    menu_manage=fl->load_menu();
    return menu_manage[numb];
}
