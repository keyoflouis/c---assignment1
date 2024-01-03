#include "client.hpp"
#include "ui.hpp"
#include "file.hpp"
#include "order_manage.hpp"
#include "conio.h"
#include "order.hpp"
#include <string.h>
#include "clients_manage.hpp"
#include "menu.hpp"
#include <vector>
#include<regex>

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
            while (true)
            {
                System_ui->operat_menu_for_client();
                int choos = kb->get_for_choose();

                switch (choos)
                {
                case 49:
                    this->take_order();
                    break;

                case 50:
                    this->check_my_order();
                    break;
                case 51:
                    this->cancel_order();
                    break;
                default:
                    return;
                    break;
                }
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
    menus->menu_manage.clear();
    menus->menu_manage = fl->load_menu();

    if (for_match_menu_item < menus->menu_manage.size()+1)
    {
        order od(global_client.ID, menus->match(for_match_menu_item-1).name);
        return om->add_order(od);
    }
    else
    {
        return false;
    }
}

void client::check_my_order()
{
    om->order_manage_v.clear();
    om->order_manage_v =fl->load_order();
    vector<order>::iterator i =om-> order_manage_v.begin();
    while (i!=om->order_manage_v.end())
    {
        if(strcmp( i->who_id, global_client.ID)==0){
           cout << i->who_id << " " << i->menu_item_name << " " << i->order_number.Time << " " << i->order_number.sequance << endl;
        }
        i++;
    }
    getchar();
    
}

bool client::cancel_order()
{
    system("cls");
    cout << "If the order is more than 5 minutes old, the cancellation of the order fails" << endl;
    cout << "if that please call the administor to cancel the order" << endl;
    getchar();
    system("cls");

    order_sequance manage_order_check_by_order_sequance;
     regex pattern(R"([A-Za-z]{3} \w{3}  \d{1,2} \d{2}:\d{2}:\d{2} \d{4})");
     string for_pattern;
    while (true)
    {
        this->check_my_order();
        cout << "\t\t type in the order_numb time" << endl;
        getline(cin, for_pattern);
        if (regex_match(for_pattern, pattern)) {
            cout << "formate correct" << endl;


            this->check_my_order();
            strcpy(manage_order_check_by_order_sequance.Time, for_pattern.c_str());
            cout << "\t\t type in the order_numb squance" << endl;
            cin >> manage_order_check_by_order_sequance.sequance;
            getchar();

            order_sequance numb;
            numb = manage_order_check_by_order_sequance;

            om->order_manage_v.clear();
            om->order_manage_v = fl->load_order();

            vector<order>::iterator i = om->order_manage_v.begin();
            while (i != om->order_manage_v.end())
            {
                if (i->order_number == numb) {
                    if (strcmp(i->who_id, global_client.ID) == 0)
                    {
                        order_sequance now_temp = order_sequance();
                        if ((now_temp.the_Time - i->order_number.the_Time) < 300) {
                            // only cancel the order automatly when the time less than 5 min;
                            om->order_manage_v.erase(i);
                            cout << "canceled the order" << endl;
                            getchar();
                            return true;
                            break;
                        }
                        else
                        {
                            cout << "you need to phone the administor" << endl;
                            cout << "11111111" << endl;
                            getchar();
                        }

                    }
                    else {
                        cout << "error ID" << endl;
                    }
                }
                i++;
            }
            fl->write_to_order(om->order_manage_v);
            return false;

            
        }
        else
        {
            cout << "formate error" << endl;
            cout << "again or return to the operate menu" << endl;
            cout << "y or n" << endl;
            int temp = kb->get_for_choose();

            if (temp == (int)'y' || temp == 'Y') {
                return false;
            }
            else if (temp == (int)'n' || temp == 'N')
            {
                break;
            }
        }
    }

}
