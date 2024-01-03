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
    cout << " \t\t  Ϊ�Ǹ��û���Ӷ���:" << endl;
    strcpy(temp, kb->get_consol());

    cout << "\t\t ʲô��(����):" << endl;
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
    cout << "\n\t\t ��ӳɹ�" << endl;
    cout << "\t\t �����������" << endl;
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
        cout << "\t\t ���붩��ʱ�� " << endl;
        getline(cin, for_pattern);
        if (regex_match(for_pattern, pattern)) { 
            strcpy(manage_order_check_by_order_sequance.Time, for_pattern.c_str());
            cout << "\t\t ���붩�����" << endl;
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
            cout << "\t\t �Ƴ��ɹ�" << endl;
            return false;
        }
        else
        {
            cout << "\n\t\t ��ʽ����" << endl;
            cout << "\t\t ����һ�飿" << endl;
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
        cout << "\t\t ���붩��ʱ�� " << endl;
        getline(cin, for_pattern);
        if (regex_match(for_pattern, pattern)) {
            strcpy(manage_order_check_by_order_sequance.Time, for_pattern.c_str());
            cout << "\t\t ���붩�����" << endl;
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
                    cout << "\t\t �����޸Ķ����Ĳ������������" << endl;
                    strcpy_s(i->menu_item_name, kb->get_consol());
                }
                i++;
            }

            fl->write_to_order(order_manage_v);
            return false;
        }
        else
        {
            cout << "\n\t\t ��ʽ����" << endl;
            cout << "\t\t ����һ�飿" << endl;
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
