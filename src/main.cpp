#include<iostream>
#include"ui.hpp"
#include"keyboard.hpp"
#include"file.hpp"
#include"menu.hpp"
#include<string.h>
#include<conio.h>
#include"order.hpp"
#include"order_manage.hpp"
#include"clients_manage.hpp"
using namespace std;


ui *System_ui=new ui();
keyboard *kb=new keyboard();
file *fl=new file();
menu *menus=new menu();
order_manage* om=new order_manage();
clients_manage* cm=new clients_manage();
int main(){
    char* type_in1;
    
    
    /* signin/signup ,admin ,quite*/
    while (true)
    {
/*
        fstream fs(fl->client_filepath,ios::out|ios::binary);
        client test;
        if (!fs.is_open())
        {
           cout<<"cuow wu"<<endl;
           
        }
        
        while ( fs.read((char*)&test,sizeof(test)))
        {
             cout<<test.ID<<" "<<test.Name<<" "<<test.Password<<endl;
             int x;
             cin >> x;
        }
  */      
        System_ui->firstPage();
        int choic=kb->get_for_choose();
        char* from_consol_to_sign_in_admin;

        switch (choic)
        {
        case 49:
            
            System_ui->signin_signup_ID();
            type_in1= kb->get_consol();
            if(fl->is_has_id_forclient(type_in1)){    
                // sign in
                client the_client =fl->find_client(type_in1);
                if(cm->sign_in(the_client)){


                    System_ui->operat_menu_for_client();
                    int choos=kb->get_for_choose();


                    switch (choos)
                    {
                    case 49:
                        System_ui->menu_ui(fl->load_menu());

                        // order ...
                        int in_for_order;
                        in_for_order=getch();
                        if(in_for_order<menus->menu_manage.size()){
                            om->add_order(order(the_client.ID,menus->match(in_for_order).name));

                        }
                        break;


                    case 50:

                        break;
                    case 51:

                        break;
                    default:
                        break;
                    }



                }

                
            }else{
               cm->sign_up();
            }

            break;
        case 50:
                    // admin
            System_ui->signin_admin();
             from_consol_to_sign_in_admin=kb->get_consol();
            if( fl->is_has_id_foradmin(from_consol_to_sign_in_admin)){
                cout<<"\t\t type in your id:"<<endl;

                from_consol_to_sign_in_admin=kb->get_consol();
                admin the_admin = fl->find_admin(from_consol_to_sign_in_admin);
 
                cout<<"\t\t type in your password:"<<endl;
                from_consol_to_sign_in_admin=kb->get_consol();

                if(strcmp(from_consol_to_sign_in_admin,the_admin.Password)==0){
                    System_ui->operat_menu_for_admin();
                    int tempi=kb->get_for_choose();

                    order_sequance manage_order_check_by_order_sequance;
                    switch (tempi)
                    {
                    case 49:
                        System_ui->manage_orders_ui();
                        tempi=kb->get_for_choose();
                        switch (tempi)
                        {
                        case 49:
                        // add order
                            char* temp;
                            char* temp1;

                            cout<<" \t\t id:"<<endl;
                            strcpy( temp,kb->get_consol());

                            cout<<"\t\t menu_item_name:"<<endl;
                            strcpy(temp1,kb->get_consol());

                            om->add_order(order(temp,temp1));

                            break;
                        case 50:
                        // remove order
                            cout<<"\t\t type in the order_numb time"<<endl;
                           
                            cin>>manage_order_check_by_order_sequance.time;
                            cout<<"\t\t type in the order_numb squance"<<endl;
                            cin>>manage_order_check_by_order_sequance.sequance;

                            om->remov_order(manage_order_check_by_order_sequance);

                            break;
                        case 51:
                        // modify order
                            cout<<"\t\t type in the order_numb time"<<endl;
                            
                            cin>> manage_order_check_by_order_sequance.time;
                            cout<<"\t\t type in the order_numb squance"<<endl;
                            cin>> manage_order_check_by_order_sequance.sequance;

                            om->modify_order(manage_order_check_by_order_sequance);

                            break;
                        case 52:
                        // show orders
                            om->show_orders();
                            break;
                        case 53:
                        // quite
                            break;
                        default:
                            break;
                        }
                        break;


                    case 50:
                        System_ui->manage_client_ui();
                        tempi=kb->get_for_choose();
                        char* modify_client_by_id;

                        switch (tempi)
                        {
                        case 49:
                        // add client
                            cm->sign_up();
                            break;
                        case 50:
                        // remove client
                           cm->remove(kb->get_consol());

                            break;
                        case 51:
                        // modify client
                            cout<<"type in the id"<<endl;
                            modify_client_by_id=kb->get_consol();
                            cm->modify(modify_client_by_id);
                            break;
                        case 52:
                        // show client
                            cm->show_client();
                            break;
                        case 53:
                        // quite
                            break;
                        default:
                            break;
                        }
                        break;
                    case 51:

                        break;
                    default:

                        break;
                    }


                }else{
                    cout<<"\t\t password worn"<<endl;
                }
            }else{
                char temp_id[64];
                char temp_password[64];

                getchar();
                cin>>temp_id;
                getchar();
                cin>>temp_password;
                getchar();

                fl->addtofile_admin(admin(temp_id,temp_password));
            }
            break;
        case 51:

            return 0;
        default:
            break;
        }
    }
    

    return 0;
}
