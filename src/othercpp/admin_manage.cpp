#include "admin_manage.hpp"
#include "admin.hpp"
#include "ui.hpp"
#include "file.hpp"
#include "clients_manage.hpp"
#include "order_manage.hpp"
#include <iostream>
#include <string.h>
using namespace std;

admin_manage::admin_manage(/* args */)
{
}

admin_manage::~admin_manage()
{
}

bool admin_manage::sign_in()
{
    System_ui->signin_admin();
    char from_consol_to_sign_in_admin[64];
    strcpy(from_consol_to_sign_in_admin, kb->get_consol());

    if (fl->is_has_id_foradmin(from_consol_to_sign_in_admin))
    {
        system("cls");
        cout << "\t\t---------------------------------" << endl;
        cout << "\t\t type in your id:" << endl;
        cout << "\t\t---------------------------------" << endl;

        strcpy(from_consol_to_sign_in_admin, kb->get_consol());
        admin the_admin = fl->find_admin(from_consol_to_sign_in_admin);

        system("cls");
        cout << "\t\t---------------------------------" << endl;
        cout << "\t\t type in your password:" << endl;
        cout << "\t\t---------------------------------" << endl;

        strcpy(from_consol_to_sign_in_admin, kb->get_consol());
        if (strcmp(from_consol_to_sign_in_admin, the_admin.Password) == 0)
        {
            return true;
        }
    }
    else
    {
        sign_up();

        return false;
    }
}

bool admin_manage::sign_up()
{
    System_ui->admin_signup_ui();
    char temp_id[64];
    char temp_password[64];

    cin >> temp_id;
    getchar();
    cin >> temp_password;
    getchar();

    if (fl->addtofile_admin(admin(temp_id, temp_password)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void admin_manage::manage_client_ad()
{
    System_ui->manage_client_ui();
    int tempi = kb->get_for_choose();

    switch (tempi)
    {
    case 49:
        // add client
        cm->sign_up();
        break;
    case 50:
        // remove client
        cm->remove();

        break;
    case 51:
        // modify client
        cm->modify();
        break;
    case 52:
        // show client
        cm->show_client();
        break;
    case 53:
        // quite
        break;
    default:
        break;
    }
}

void admin_manage::manage_order_ad()
{
    System_ui->manage_orders_ui();
    int tempi = kb->get_for_choose();
    switch (tempi)
    {
    case 49:
        // add order
        om->add_order();

        break;
    case 50:
        // remove order
        om->remov_order();

        break;
    case 51:
        // modify order
        om->modify_order();

        break;
    case 52:
        // show orders
        om->show_orders();
        break;
    case 53:
        // quite
        break;
    default:
        break;
    }
}

void admin_manage::manage_menu_ad()
{
    system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 1.add menu                    |" << endl;
	cout << "\t\t| 2.modify menu				 |" << endl;
	cout << "\t\t| 3.delete menu				 |" << endl;
    cout << "\t\t| 4.display menu			     |" << endl;
	cout << "\t\t---------------------------------" << endl;

    int tempi = kb->get_for_choose();
    switch (tempi)
    {
    case 49:
        // add menu
        menus->add_menu();

        break;
    case 50:
        // modify order
        menus->modify_menu();

        break;
    case 51:
        // delet order
       menus->remov_menu();

        break;
    case 52:
        // show orders
        menus->show_menu();
        break;
    case 53:
        // quite
        break;
    default:
        break;
    }
}

void admin_manage::admin_start()
{
    if (am->sign_in())
    {
        admin_manage_choose();
    }
    else
    {
        cout << "\t\t password worn" << endl;
    }
}

void admin_manage::admin_manage_choose()
{
    while (true)
    {

        System_ui->operat_menu_for_admin();
        int tempi = kb->get_for_choose();

        switch (tempi)
        {
        case 49:
            // manage order
            am->manage_order_ad();
            break;
        case 50:
            // manage client
            am->manage_client_ad();
            break;
        case 51:
            // manage menu
            am->manage_menu_ad();
        default:
            return;
            break;
        }
    }
}
