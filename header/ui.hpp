#pragma once
#include <vector>
#include"menu_item.hpp"
#include"menu.hpp"
using namespace std;
class ui
{
private:
    /* data */
public:
    ui(/* args */);
    ~ui();

    void firstPage();
    
    //  page for client
    void signin_signup_ID();
    void if_Signup();           /*newfish*/
    void type_your_password();
    void modify_clientui();
    
    void signup_ui();
    void operat_menu_for_client();
    void remov_menu_ui(char *temp);
    

    void menu_ui(menu* menus ,vector<menu_item> vector_menu ,file* fl);
    void checkout_ui();
    void modify_menu_ui();

    //  page for admin
    void signin_admin();
    void operat_menu_for_admin();
    void manage_orders_ui();
    void manage_client_ui();

    void choos_modify_order();
};

/*the basic logic is sign in ,password, operat_menu , menu,checkout_ui*/
/*                         or if_Signup ,password ,,,,   sign in      */