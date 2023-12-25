#include"ui.hpp"
#include<iostream>
#include<windows.h>
#include"menu.hpp"
#include"menu_item.hpp"
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
	cout << "\t\t|  1.client sign in/sign up     |" << endl;
	cout << "\t\t|  2.adminitor          		 |" << endl;
	cout << "\t\t|  3.quite             		 |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::signin_signup_ID()
{
    system("cls");
    cout<<"\t\t\t enter your ID:"<<endl;         
}

void ui::if_Signup()
{
	system("cls");
	cout<<"\t\tsign up for a new account?"<<endl;
	cout<<"\t\t 1.yes"<<endl;
	cout<<"\t\t 2.no"<<endl;
}

void ui::type_your_password()
{
	system("cls");
	cout<<"type your password"<<endl;
}

void ui::modify_clientui()
{
	system("cls");
    cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 	1.change ID				     |" << endl;
	cout << "\t\t| 	2.change name 	        	 |" << endl;
	cout << "\t\t|  3.change password			 |" << endl;
	cout << "\t\t|  4.quite						 |" << endl;
	cout << "\t\t|               				 |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::signup_ui()
{
	system("cls");
	cout<<"\t\t type in your new name:"<<endl;
	cout<<"\t\t type in your id:"<<endl;
	cout<<"\t\t type in your password:"<<endl;
}

void ui::operat_menu_for_client()
{
	system("cls");
    cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 	1.order					     |" << endl;
	cout << "\t\t| 	2..............         	 |" << endl;
	cout << "\t\t|  3.quite			        	 |" << endl;
	cout << "\t\t|  							 |" << endl;
	cout << "\t\t|               				 |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::remov_menu_ui(char* temp)
{
	
system("cls");
    cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 	remove or not "<<temp<<endl;
	cout << "\t\t| 	1.y				         	 |" << endl;
	cout << "\t\t|  3.n			        	 	 |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::menu_ui(vector<menu_item> vector_menu)
{
	menus->show_menu(vector_menu );
	
}

void ui::checkout_ui()
{
}

void ui::modify_menu_ui()
{
	cout << "\t\t| 	1.modify name			     |" << endl;
	cout << "\t\t| 	2.modify price          	 |" << endl;
}

void ui::signin_admin()
{
	system("cls");
	cout<<"\t\t this is administor ui "<<endl;
	cout<<"ID,password:"<<endl;

}

void ui::operat_menu_for_admin()
{
	system("cls");
    cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 	1.manage orders			     |" << endl;
	cout << "\t\t| 	2.manage client          	 |" << endl;
	cout << "\t\t|  3.quite			        	 |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::manage_orders_ui()
{
	system("cls");
    cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 	1.add orders			     |" << endl;
	cout << "\t\t| 	2.remove order          	 |" << endl;
	cout << "\t\t|  3.modify orders			     |" << endl;
	cout << "\t\t|  4.show order	        	 |" << endl;
	cout << "\t\t|  5.quite			        	 |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::manage_client_ui()
{
	system("cls");
    cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 	1.add client		  		 |" << endl;
	cout << "\t\t| 	2.remove client       	   	 |" << endl;
	cout << "\t\t|  3.modify client			     |" << endl;
	cout << "\t\t|  4.show client                |" << endl;
	cout << "\t\t|  5.quite              		 |" << endl;
	cout << "\t\t---------------------------------" << endl;
}

void ui::choos_modify_order()
{
	system("cls");
    cout << endl;
	cout << "\t\t---------------------------------" << endl;
	cout << "\t\t| 	1.menu name`		  		 |" << endl;
	cout << "\t\t| 					     	   	 |" << endl;
	cout << "\t\t| 							     |" << endl;
	cout << "\t\t|  			                 |" << endl;
	cout << "\t\t|  		              		 |" << endl;
	cout << "\t\t---------------------------------" << endl;
}
