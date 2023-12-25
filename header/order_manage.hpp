#pragma once
#include<vector>
#include"order.hpp"
#include"file.hpp"

using namespace std;

class order_manage
{
public:
    vector<order> order_manage_v;
    
public:
    order_manage(/* args */);
    ~order_manage();

    bool add_order(file*,order);
    void show_orders(file*);
    bool remov_order(file*,order_sequance );
    bool modify_order(file *fl, order_sequance numb,keyboard* kb,ui* System_ui);

};

