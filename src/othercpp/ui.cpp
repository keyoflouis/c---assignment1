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
	cout << "\t\t|  1. �ͻ���¼/ע��             |" << endl;
	cout << "\t\t|  2. ����Ա                    |" << endl;
	cout << "\t\t|  3. �˳�                      |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::signin_signup_ID()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| ������� ID:                  |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::if_Signup()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|ע��һ�����˻���               |" << endl;
	cout << "\t\t|1.��                           |" << endl;
	cout << "\t\t|2.��                           |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::type_your_password()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| �����������                  |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::modify_clientui()
{
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 	1.���� ID                    |" << endl;
	cout << "\t\t| 	2.���� name                  |" << endl;
	cout << "\t\t|  3.��������                   |" << endl;
	cout << "\t\t|  4.�˳�                       |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::signup_ui()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|�����������:                  |" << endl;
	cout << "\t\t|��������Ҫ��id:                |" << endl;
	cout << "\t\t|�����������:                  |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::operat_menu_for_client() {
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|          1.���               |" << endl;
	cout << "\t\t|          2.�鿴�ҵĶ���       |" << endl;
	cout << "\t\t|          3.ȡ������           |" << endl;
	cout << "\t\t|          4.�˳�               |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t---------------------------------" << endl;
}


void ui::remov_menu_ui(char *temp)
{

	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t 	      �Ƿ��Ƴ��˵���" << temp << endl;
	cout << "\t\t|        1.��                    |" << endl;
	cout << "\t\t|        2.��                    |" << endl;
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
	cout << "\t\t|  1.�޸Ĳ���                   |" << endl;
	cout << "\t\t|  2.�����۸�                   |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::signin_admin()
{
	system("cls");
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|       ��ӭ��������Ա����      |" << endl;
	cout << "\t\t|      �������ID��             |" << endl;
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
	cout << "\t\t|  1.������                   |" << endl;
	cout << "\t\t|  2.����ͻ��˻�               |" << endl;
	cout << "\t\t|  3.����˵�                   |" << endl;
	cout << "\t\t|  4.�˳�                       |" << endl;	
	cout << "\t\t---------------------------------" << endl;
}

void ui::manage_orders_ui()
{
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|  1.��Ӷ���                   |" << endl;
	cout << "\t\t|  2.�Ƴ�����                   |" << endl;
	cout << "\t\t|  3.�޸Ķ���                   |" << endl;
	cout << "\t\t|  4.�鿴����                   |" << endl;
	cout << "\t\t|  5.�˳�                       |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::manage_client_ui()
{
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|  1.����û�                   |" << endl;
	cout << "\t\t|  2.�Ƴ��û�                   |" << endl;
	cout << "\t\t|  3.�޸��û�                   |" << endl;
	cout << "\t\t|  4.�鿴�û�                   |" << endl;
	cout << "\t\t|  5.�˳�                       |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::choos_modify_order()
{
	system("cls");
	cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t|    1.�޸Ķ�������             |" << endl;
	cout << "\t\t---------------------------------" << endl;
}
