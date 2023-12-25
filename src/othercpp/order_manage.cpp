#include"order_manage.hpp"
#include"order.hpp"
#include"keyboard.hpp"
#include"ui.hpp"
#include<string.h>

order_manage::order_manage(/* args */)
{
}



order_manage::~order_manage()
{
}

bool order_manage::add_order(file *fl, order od) 
{
    fl->addtofile_order(od);
    return false;
}

void order_manage::show_orders(file *fl)
{
    order_manage_v=fl->load_order();
     // depend on the way of store a menu_item 
    cout<<"\t\t name   price"<<endl;
    for (int i = 0; i < order_manage_v.size(); i++)
    {
        
        cout<<order_manage_v[i].who_id<<" "<<order_manage_v[i].menu_item_name<<" "<<order_manage_v[i].order_number.time<<" "<<order_manage_v[i].order_number.sequance<<endl;
    }
    return ;

}

bool order_manage::remov_order(file *fl,order_sequance numb)
{
    order_manage_v=fl->load_order();
    for (int i = 0; i < order_manage_v.size(); i++)
    {
        if(order_manage_v[i].order_number==numb){
            order_manage_v.erase(order_manage_v.begin()+i);
        }
    }
    fl->write_to_order(order_manage_v);
    return false;
}

bool order_manage::modify_order(file *fl, order_sequance numb,keyboard* kb,ui* System_ui)
{
  order_manage_v=fl->load_order();
    for (int i = 0; i < order_manage_v.size(); i++)
    {
        if(order_manage_v[i].order_number==numb){
            cout<<"\t\t choos what to modify"<<endl;
            System_ui->choos_modify_order();

            int temp_for_choose=kb->get_for_choose();
            switch (temp_for_choose)
            {
            case 49:
                // menu_item_name;
                cout<<"\t\t type in the menu name"<<endl;
                strcpy_s(order_manage_v[i].menu_item_name,kb->get_consol());
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
