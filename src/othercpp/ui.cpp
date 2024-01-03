#include "ui.hpp"
#include <iostream>
#include <windows.h>
#include "menu.hpp"
#include "menu_item.hpp"
using namespace std;
ui::ui(/* args */)
{
}

ui::~ui()
{
}

void ui::firstPage()
{

	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|  1. 客户登录/注册             |" << endl;
	cout << "\t\t|  2. 管理员                    |" << endl;
	cout << "\t\t|  3. 退出                      |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::signin_signup_ID()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 输入你的 ID:                  |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::if_Signup()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|注册一个新账户？               |" << endl;
	cout << "\t\t|1.是                           |" << endl;
	cout << "\t\t|2.否                           |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::type_your_password()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 输入你的密码                  |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::modify_clientui()
{
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 	1.更改 ID                    |" << endl;
	cout << "\t\t| 	2.更改 name                  |" << endl;
	cout << "\t\t|  3.更改密码                   |" << endl;
	cout << "\t\t|  4.退出                       |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::signup_ui()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|输入你的名称:                  |" << endl;
	cout << "\t\t|输入你想要的id:                |" << endl;
	cout << "\t\t|输入你的密码:                  |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::operat_menu_for_client() {
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|          1.点餐               |" << endl;
	cout << "\t\t|          2.查看我的订单       |" << endl;
	cout << "\t\t|          3.取消订单           |" << endl;
	cout << "\t\t|          4.退出               |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t---------------------------------" << endl;
}


void ui::remov_menu_ui(char *temp)
{

	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t 	      是否移除菜单：" << temp << endl;
	cout << "\t\t|        1.是                    |" << endl;
	cout << "\t\t|        2.否                    |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::menu_ui()
{
	menus->show_menu();
}

void ui::modify_menu_ui()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|  1.修改菜名                   |" << endl;
	cout << "\t\t|  2.调整价格                   |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::signin_admin()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|       欢迎来到管理员界面      |" << endl;
	cout << "\t\t|      输入你的ID：             |" << endl;
	cout << "\t\t---------------------------------" << endl;
}
void ui::admin_signup_ui()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|		sign up a admistor		 |" << endl;
	cout << "\t\t| 		ID,password:          	 |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::operat_menu_for_admin()
{
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|  1.管理订单                   |" << endl;
	cout << "\t\t|  2.管理客户账户               |" << endl;
	cout << "\t\t|  3.管理菜单                   |" << endl;
	cout << "\t\t|  4.退出                       |" << endl;	
	cout << "\t\t---------------------------------" << endl;
}

void ui::manage_orders_ui()
{
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|  1.添加订单                   |" << endl;
	cout << "\t\t|  2.移除订单                   |" << endl;
	cout << "\t\t|  3.修改订单                   |" << endl;
	cout << "\t\t|  4.查看订单                   |" << endl;
	cout << "\t\t|  5.退出                       |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::manage_client_ui()
{
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|  1.添加用户                   |" << endl;
	cout << "\t\t|  2.移除用户                   |" << endl;
	cout << "\t\t|  3.修改用户                   |" << endl;
	cout << "\t\t|  4.查看用户                   |" << endl;
	cout << "\t\t|  5.退出                       |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::choos_modify_order()
{
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|    1.修改订单菜名             |" << endl;
	cout << "\t\t---------------------------------" << endl;
}
