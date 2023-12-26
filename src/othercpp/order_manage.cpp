#include "order_manage.hpp"
#include "order.hpp"
#include "keyboard.hpp"
#include "ui.hpp"
#include <string.h>

order_manage::order_manage(/* args */)
{
}

order_manage::~order_manage()
{
}

bool order_manage::add_order()
{
    // add order
    char temp[64];
    char temp1[64];

    cout << " \t\t id:" << endl;
    strcpy(temp, kb->get_consol());

    cout << "\t\t menu_item_name:" << endl;
    strcpy(temp1, kb->get_consol());
    order od(temp, temp1);

    order_manage_v = fl->load_order();
    od.order_number.sequance = order_manage_v.back().order_number.sequance + 1;
    order_manage_v.push_back(od);

    fl->write_to_order(order_manage_v);
    return true;
}

bool order_manage::add_order(order od)
{
    // generat order number
    order_manage_v = fl->load_order();


    if (order_manage_v.size() == 0) {
        od.order_number.sequance = 1;
    }
    else
    {
        od.order_number.sequance = order_manage_v.back().order_number.sequance + 1;
    }//try 0
    order_manage_v.push_back(od);

    fl->write_to_order(order_manage_v);
    return true;
}

void order_manage::show_orders()
{
    vector<order> order_manage_show_orders = fl->load_order();
    system("cls");
    for (int i = 0; i < order_manage_show_orders.size(); i++)
    {
        cout << order_manage_show_orders[i].who_id << " " << order_manage_show_orders[i].menu_item_name << " " << order_manage_show_orders[i].order_number.Time << " " << order_manage_show_orders[i].order_number.sequance << endl;
    }
    getchar();
    return;
}

bool order_manage::remov_order()
{
    order_sequance manage_order_check_by_order_sequance;
    cout << "\t\t type in the order_numb time" << endl;
    cin >> manage_order_check_by_order_sequance.Time;

    cout << "\t\t type in the order_numb squance" << endl;
    cin >> manage_order_check_by_order_sequance.sequance;

    order_sequance numb;
    numb = manage_order_check_by_order_sequance;
    order_manage_v = fl->load_order();


    for (int i = 0; i < order_manage_v.size(); i++)
    {
        if (order_manage_v[i].order_number == numb)
        {
            order_manage_v.erase(order_manage_v.begin() + i);
        }
    }

    fl->write_to_order(order_manage_v);
    return false;
}

bool order_manage::modify_order()
{
    order_sequance manage_order_check_by_order_sequance;
    cout << "\t\t type in the order_numb time" << endl;
    cin >> manage_order_check_by_order_sequance.Time;

    cout << "\t\t type in the order_numb squance" << endl;
    cin >> manage_order_check_by_order_sequance.sequance;

    order_sequance numb = manage_order_check_by_order_sequance;
    order_manage_v = fl->load_order();
    for (int i = 0; i < order_manage_v.size(); i++)
    {
        if (order_manage_v[i].order_number == numb)
        {
            cout << "\t\t choos what to modify" << endl;
            System_ui->choos_modify_order();

            int temp_for_choose = kb->get_for_choose();
            switch (temp_for_choose)
            {
            case 49:
                // menu_item_name;
                cout << "\t\t type in the menu name" << endl;
                strcpy_s(order_manage_v[i].menu_item_name, kb->get_consol());
                break;
            case 50:

                break;
            case 51:

                break;
            default:
                break;
            }
        }
    }
    fl->write_to_order(order_manage_v);
    return false;
}
