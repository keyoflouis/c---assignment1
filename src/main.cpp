#include <iostream>
#include "ui.hpp"
#include "keyboard.hpp"
#include "file.hpp"
#include "menu.hpp"
#include <string.h>
#include <conio.h>
#include "order.hpp"
#include "order_manage.hpp"
#include "clients_manage.hpp"
#include "admin_manage.hpp"
using namespace std;

ui *System_ui = new ui();
keyboard *kb = new keyboard();
file *fl = new file();
menu *menus = new menu();
order_manage *om = new order_manage();
clients_manage *cm = new clients_manage();
admin_manage *am = new admin_manage();
client global_client;

int main()
{
    char *type_in1;

    while (true)
    {
        System_ui->firstPage();
        int choic = kb->get_for_choose();

        switch (choic)
        {
        case 49:
            // client
            global_client.client_start();
            break;
        case 50:
            // admin
            am->admin_start();
        default:
            break;
        }
    }

    return 0;
}
