#include "client.hpp"
#include "ui.hpp"
#include "file.hpp"
#include "order_manage.hpp"
#include "conio.h"
#include "order.hpp"
#include <string.h>
#include "clients_manage.hpp"
#include "menu.hpp"
using namespace std;
client::client(const char *id, const char *name, const char *password)
{
    strcpy(this->ID, id);
    strcpy(this->Name, name);
    strcpy(this->Password, password);
}

client::client()
{
}

client::~client()
{
}

bool client::order_c()
{
    // clinet order
    System_ui->menu_ui();

    // order ...
    int in_for_order;
    in_for_order = getch();
    if (in_for_order < menus->menu_manage.size())
    {
        om->add_order(order(global_client.ID, menus->match(in_for_order).name));
    }

    return false;
}

void client::client_start()
{
    char *type_in1;
    System_ui->signin_signup_ID();
    type_in1 = kb->get_consol();
    if (fl->is_has_id_forclient(type_in1))
    {
        // sign in
        if (cm->sign_in())
        {
            System_ui->operat_menu_for_client();
            int choos = kb->get_for_choose();

            switch (choos)
            {
            case 49:
                this->take_order();
                break;

            case 50:
                
                break;
            default:
                break;
            }
        }
    }
    else
    {
        cm->sign_up();
    }
}

bool client::take_order()
{
    int for_match_menu_item;
    menus->show_menu();
    cin >> for_match_menu_item ;
    menus->menu_manage = fl->load_menu();

    if (for_match_menu_item < menus->menu_manage.size())
    {
        order od(global_client.ID, menus->match(for_match_menu_item).name);
        return om->add_order(od);
    }
    else
    {
        return false;
    }
}
