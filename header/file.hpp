#pragma once
#include<string>
#include<fstream>
#include<vector>
#include"client.hpp"
#include"menu_item.hpp"
#include"admin.hpp"
#include"order.hpp"

using namespace std;

class file
{
public:
    vector<client> client_manage;
    vector<order> order_manage;
    vector<menu_item>  menu_manage;
    vector<menu_item>  menu_for_add;
    
    const char* client_filepath="clients.txt";
    const char* menu_filepath="menu.txt";
    const char* admin_filepath="admin.txt";
    const char* order_filepath="orders.txt";

public:
    file(/* args */);
    ~file();
    fstream openFile(const char* filepath);


    bool addtofile_Client(client temp);
    bool is_has_id_forclient(const char* in_id);  //if is return true , else false
    client find_client(const char* input_id);
    vector<client> load_client();
    bool write_to_client(vector<client> temp);

    vector<menu_item> load_menu();
    bool is_have_menu_item(string );
    bool addtofile_Menu();
    bool write_to_menu(vector<menu_item> temp1);


    bool is_has_id_foradmin(const char* in_id);
    admin find_admin(const char* in_id);
    bool addtofile_admin(admin temp);


    bool addtofile_order(order od);
    vector<order> load_order();
    bool write_to_order(vector<order> temp);
    
};

extern file* fl;