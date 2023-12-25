#include"clients_manage.hpp"
#include"ui.hpp"
#include"keyboard.hpp"
#include"file.hpp"
#include"client.hpp"
#include<string.h>

clients_manage::clients_manage(/* args */)
{
}

clients_manage::~clients_manage()
{
}



bool clients_manage::sign_up(ui* System_ui,keyboard* kb,file* fl)
{
    // sign up
    System_ui->if_Signup();
    int tempi=kb->get_for_choose();
    if(tempi==49){
        System_ui->signup_ui();    
        char temp_name[64];
        char temp_id[64];
        char temp_password[64];
        // cin>>temp_name;
        // cin>>temp_id;
        // cin>>temp_password;   getline seems better than cin,but why
        cin>>temp_name;
        getchar();
        cin>>temp_id;
        getchar();
        cin>>temp_password;
        getchar();  
        if(fl->is_has_id_forclient(temp_id))
        {
            cout<<"id repeat error"<<endl;
        }else{
            fl->addtofile_Client(client(temp_id,temp_name,temp_password));
        }  
     }else if(tempi==50){

     }

    return false;
}

bool clients_manage::sign_in(client the_client ,ui* System_ui,keyboard* kb,file* fl)
{
    System_ui->type_your_password();
    if(strcmp(kb->get_consol(),the_client.Password)==0){
    cout<<"ok"<<endl;
    return true;
}
}

bool clients_manage::remove(char id[64],ui* System_ui,keyboard* kb,file* fl)
{
    client_manage_v=fl->load_client();
    for (int i = 0; i < client_manage_v.size(); i++)
    {
       if(strcmp(client_manage_v[i].ID,id)==0){
        client_manage_v.erase(client_manage_v.begin()+i);
        return true;
       }
    }
    
    return false;
}

bool clients_manage::modify(char id[64],ui* System_ui,keyboard* kb,file* fl)
{
    
    client_manage_v=fl->load_client();
    for (int i = 0; i < client_manage_v.size(); i++)
    {
        if(strcmp(client_manage_v[i].ID,id)==0){
            
            System_ui->modify_clientui();

            int temp=kb->get_for_choose();
            while (temp!=49 && temp!=50 && temp!=51 && temp!=52)
            {
                temp=kb->get_for_choose();
            }
            
            switch (temp)
            {
            case 49:
            // modify id
                cout<<" modifying your id"<<endl;
                char temp[64];
                temp==kb->get_consol();
               if( fl->is_has_id_forclient(temp)){
                cout<<"this id is already there,try another one"<<endl;
               }else{
                strcpy(client_manage_v[i].ID ,temp);

               }


                break;
            case 50:
            // modify name
                cout<<" modifying your name"<<endl;
                char temp[64];
                temp==kb->get_consol();
                strcpy(client_manage_v[i].Name,temp);

                break;
            case 51:
            // modify password

                cout<<" modifying your password"<<endl;
                char temp[64];
                temp==kb->get_consol();
                strcpy(client_manage_v[i].Password,temp);
                break;

            case 52:
                return true;
                break;

            default:
                return true;
                break;
            }
            break;
        }else{
            cout<<"cant find"<<endl;
        }
    }
    fl->write_to_client(client_manage_v);
    return true;
}

void clients_manage::show_client(char *id,ui* System_ui,keyboard* kb,file* fl)
{
    client temp=fl->find_client(id);
    cout<<temp.ID<<" "<<temp.Name<<" "<<temp.Password<<endl;
    return ;
}

void clients_manage::show_client(ui* System_ui,keyboard* kb,file* fl)
{
    for (int i = 0; i < client_manage_v.size(); i++)
    {
        cout<<client_manage_v[i].ID<<" "<<client_manage_v[i].Name<<" "<<client_manage_v[i].Password<<endl;
    }
    return ;
}
