#include"menu.hpp"
#include<vector>
#include<fstream>
#include<sstream>
#include"menu_item.hpp"
#include"keyboard.hpp"
#include<string.h>
#include"ui.hpp"

using namespace std;

menu::menu(/* args */)
{
}

menu::~menu()
{
}

void menu::show_menu(vector<menu_item> manage,file* fl)
{
    // depend on the way of store a menu_item 
    manage=fl->load_menu();
    cout<<"\t\t name   price"<<endl;
    for (int i = 0; i < manage.size(); i++)
    {
        
        cout<<manage[i].name<<"    "<<manage[i].price<<endl;
    }
    return ;

}

int menu::add_menu(menu_item temp_add,file* fl,keyboard* kb)
{
    cout<<"Enter the name ,price,  of the dish you want to add to the"<<endl;
    char *name;
    strcpy(name,kb->get_consol());
    strcpy(fl->menu_for_add[(fl->menu_for_add.size()/sizeof(menu_item))-1].name,name);

    int price;
    cin>>price;
    fl->menu_for_add[(fl->menu_for_add.size()/sizeof(menu_item))-1].price=price;

    fl->addtofile_Menu();
    return 0;
}

int menu::remov_menu(char name[64],file* fl,keyboard* kb,ui *System_ui)
{
    menu_manage=fl->load_menu();
    for (int i = 0; i < menu_manage.size(); i++)
    {
        if(strcmp(menu_manage[i].name,name)==0){
            System_ui->remov_menu_ui(name);
        int temp=kb->get_for_choose();
        if (temp==49)
        {
            menu_manage.erase(menu_manage.begin()+i);
            fl->addtofile_Menu();
        }else if(temp=50){
            return 1;
        }else{  
        }
        break;
        }
    }
    
            
    
    return 0;
}

int menu::modify_menu(char* Name,file* fl,keyboard* kb,ui *System_ui)
{   
    menu_manage=fl->load_menu();
    for (int i = 0; i < menu_manage.size(); i++)
    {
        if(strcmp(menu_manage[i].name,Name)==0){
            
            System_ui->modify_menu_ui();
            int temp=kb->get_for_choose();
            while (temp!=49 && temp!=50)
            {
                temp=kb->get_for_choose();
            }
            
            switch (temp)
            {
            case 49:
            // modify name
                cout<<" modifying the menu name"<<endl;
                char* temp_in=kb->get_consol();
                menu_manage=fl->load_menu();
                for (int i = 0; i < menu_manage.size(); i++)
                {
                    if(strcmp(menu_manage[i].name,Name)==0){
                    strcpy(menu_manage[i].name ,temp_in);
                    break;
                    }
                }
                
                fl->write_to_menu(menu_manage);
                break;

            case 50:
            // modify price
                cout<<" modifying the menu price"<<endl;
                int temp_in1;
                cin>>temp_in1;
                getchar();

                menu_manage=fl->load_menu();
                for (int i = 0; i < menu_manage.size(); i++)
                {
                    if(strcmp(menu_manage[i].name,Name)==0){
                        menu_manage[i].price =temp_in1;
                    break;
                    }
                }
               

            default:
                return true;
                break;
            }
            break;
        }else{
            cout<<"cant find"<<endl;
        }
    }
    fl->write_to_menu(menu_manage);
    return true;

}


menu_item menu::match(int numb)
{
    return  menu_manage[numb];
}
