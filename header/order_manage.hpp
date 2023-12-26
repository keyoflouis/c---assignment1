#pragma once
#include <vector>
#include "order.hpp"
#include "file.hpp"
#include "keyboard.hpp"
using namespace std;

class order_manage
{
public:
    vector<order> order_manage_v;

public:
    order_manage(/* args */);
    ~order_manage();

    bool add_order();
    bool add_order(order);
    void show_orders();
    bool remov_order();
    bool modify_order();
};
extern order_manage *om;
