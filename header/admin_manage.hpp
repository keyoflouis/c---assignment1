#pragma once
#include"admin.hpp"
#include<vector>
using namespace std;
class admin_manage
{
public:
    vector<admin> admin_manage_v;

public:
    admin_manage(/* args */);
    ~admin_manage();

    bool sign_in();
    bool sign_up();
    void manage_client_ad();
    void manage_order_ad();
    void manage_menu_ad();
    
    void admin_start();
    void admin_manage_choose();

};

extern admin_manage* am;
