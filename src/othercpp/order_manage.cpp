#include "order_manage.hpp"
#include "order.hpp"
#include "keyboard.hpp"
#include "ui.hpp"
#include <string.h>
#include<iostream>
#include<string>
#include<regex>

using namespace std;

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

    system("cls");
    cout << " \t\t  为那个用户添加订单:" << endl;
    strcpy(temp, kb->get_consol());

    cout << "\t\t 什么菜(菜名):" << endl;
    strcpy(temp1, kb->get_consol());
    order od(temp, temp1);

    order_manage_v.clear();
    order_manage_v = fl->load_order();
    if (order_manage_v.size()==0) {
        od.order_number.sequance = 1;
    }
    else
    {
        od.order_number.sequance = order_manage_v.back().order_number.sequance + 1;

    }
    
    order_manage_v.push_back(od);
    fl->write_to_order(order_manage_v);
    system("cls");
    cout << "\n\t\t 添加成功" << endl;
    cout << "\t\t 按任意键继续" << endl;
    kb->get_for_choose();
    return true;
}

bool order_manage::add_order(order od)
{
    // generat order number
    order_manage_v.clear();
    order_manage_v = fl->load_order();


    if (order_manage_v.size() == 0) {
        od.order_number.sequance = 1;
    }
    else
    {
        vector<order>::iterator i = order_manage_v.begin();
        while (i!=order_manage_v.end())
        {
            od.order_number.sequance = i->order_number.sequance + 1;
            i++;
        }
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
     regex pattern(R"([A-Za-z]{3} \w{3}  \d{1,2} \d{2}:\d{2}:\d{2} \d{4})");
     string for_pattern;
    while (true)
    {
        this->show_orders();
        cout << "\t\t 输入订单时间 " << endl;
        getline(cin, for_pattern);
        if (regex_match(for_pattern, pattern)) { 
            strcpy(manage_order_check_by_order_sequance.Time, for_pattern.c_str());
            cout << "\t\t 输入订单序号" << endl;
            cin >> manage_order_check_by_order_sequance.sequance;

            order_sequance numb;
            numb = manage_order_check_by_order_sequance;

            order_manage_v.clear();
            order_manage_v = fl->load_order();

            vector<order>::iterator i = order_manage_v.begin();
            while (i != order_manage_v.end())
            {
                if (i->order_number == numb) {
                    order_manage_v.erase(i);
                    break;
                }
                i++;

            }
            fl->write_to_order(order_manage_v);
            cout << "\t\t 移除成功" << endl;
            return false;
        }
        else
        {
            cout << "\n\t\t 格式错误" << endl;
            cout << "\t\t 再试一遍？" << endl;
            cout << "\t\t y or n" << endl;
            int temp = kb->get_for_choose();

            if (temp == (int)'y' || temp == (int)'Y'||temp==(int)'1') {
                continue;
            }
            else if (temp == (int)'n' || temp ==(int) 'N'||temp==(int)'2')
            {
                return false;
            }
        }
    }
    
}

bool order_manage::modify_order()
{
    order_sequance manage_order_check_by_order_sequance;
    regex pattern(R"([A-Za-z]{3} \w{3}  \d{1,2} \d{2}:\d{2}:\d{2} \d{4})");
    string for_pattern;
    while (true)
    {
        this->show_orders();
        cout << "\t\t 输入订单时间 " << endl;
        getline(cin, for_pattern);
        if (regex_match(for_pattern, pattern)) {
            strcpy(manage_order_check_by_order_sequance.Time, for_pattern.c_str());
            cout << "\t\t 输入订单序号" << endl;
            cin >> manage_order_check_by_order_sequance.sequance;

            order_sequance numb = manage_order_check_by_order_sequance;
            order_manage_v.clear();
            order_manage_v = fl->load_order();
            vector<order>::iterator i = order_manage_v.begin();

            while (i != order_manage_v.end())
            {
                if (i->order_number == numb)
                {
                    // menu_item_name;
                    system("cls");
                    cout << "\t\t 正在修改订单的菜名，输入菜名" << endl;
                    strcpy_s(i->menu_item_name, kb->get_consol());
                }
                i++;
            }

            fl->write_to_order(order_manage_v);
            return false;
        }
        else
        {
            cout << "\n\t\t 格式错误" << endl;
            cout << "\t\t 再试一遍？" << endl;
            cout << "\t\t y or n" << endl;
            int temp = kb->get_for_choose();

            if (temp == (int)'y' || temp == (int)'Y' || temp == (int)'1') {
                continue;
            }
            else if (temp == (int)'n' || temp == (int)'N' || temp == (int)'2')
            {
                return false;
            }
        }
    }

}
