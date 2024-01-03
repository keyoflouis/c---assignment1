#include "clients_manage.hpp"
#include "ui.hpp"
#include "keyboard.hpp"
#include "file.hpp"
#include "client.hpp"
#include <string.h>
#include<vector>
using namespace std;

clients_manage::clients_manage(/* args */)
{
}

clients_manage::~clients_manage()
{
}

bool clients_manage::sign_up()
{
    // sign up
    System_ui->if_Signup();
    int tempi = kb->get_for_choose();
    if (tempi == 49)
    {
        System_ui->signup_ui();
        char temp_name[64];
        char temp_id[64];
        char temp_password[64];
        // cin>>temp_name;
        // cin>>temp_id;
        // cin>>temp_password;   getline seems better than cin,but why
        cin >> temp_name;
        getchar();
        cin >> temp_id;
        getchar();
        cin >> temp_password;
        getchar();
        
        if (fl->is_id_forclient(temp_id))
        {
            cout << "ID 重复" << endl;
        }
        else
        {
            fl->addtofile_Client(client(temp_id, temp_name, temp_password));
        }
    }
    else if (tempi == 50)
    {
    }

    return false;
}

bool clients_manage::sign_in()
{
    char* type_in1;
    System_ui->signin_signup_ID();
    type_in1 = kb->get_consol();
    if (fl->is_id_forclient( type_in1))
    {
        global_client = fl->find_client(type_in1);
        System_ui->type_your_password();

        if (strcmp(kb->get_consol(), global_client.Password) == 0)
        {
            cout << "ok" << endl;
            return true;
        }
        else
        {
            cout << "密码错误" << endl;
            getchar();
        }
    }
  
    return false;
}

bool clients_manage::remove()
{
    system("cls");
    cout << "\t\t 输入要删除的ID" << endl;

    char id[64];
    strcpy(id, kb->get_consol());
    client_manage_v.clear();
    client_manage_v = fl->load_client();

    for (int i = 0; i < client_manage_v.size(); i++)
    {
        if (strcmp(client_manage_v[i].ID, id) == 0)
        {
            client_manage_v.erase(client_manage_v.begin() + i);
            fl->write_to_client(client_manage_v);
            system("cls");
            cout << "\n\t\t 移除成功" << endl;
            return true;
        }
    }

    cout << "找不到" << id << endl;
    getchar();
    return false;
}

bool clients_manage::modify()
{
    cout << "输入要修改的ID" << endl;


    char id[64];
    strcpy(id, kb->get_consol());

    client_manage_v.clear();
    client_manage_v = fl->load_client();

    vector<client>::iterator i = client_manage_v.begin();

    while (i!=client_manage_v.end())
    {

        if (strcmp(i->ID, id) == 0)
        {

            System_ui->modify_clientui();

            int temp = kb->get_for_choose();
            while (temp != 49 && temp != 50 && temp != 51 && temp != 52)
            {
                temp = kb->get_for_choose();
            }

            switch (temp)
            {
            case 49:
                // modify id
                system("cls");
                cout << "\n\t\t 正在修改id号" << endl;
                char temp[64];
                strcpy_s(temp, kb->get_consol());
                if (fl->is_id_forclient(temp))
                {
                    cout << "\t\t 这个ID号已经存在，请尝试重新输入" << endl;
                    kb->get_for_choose();
                }
                else
                {
                    strcpy_s(i->ID, temp);
                    cout << "\t\t 修改成功" << endl;
                }

                break;
            case 50:
                // modify name
                system("cls");
                cout << "\n\t\t 正在修改账户名称" << endl;
                char temp_case50[64];
                strcpy_s(temp_case50, kb->get_consol());
                strcpy_s(i->Name, temp_case50);

                break;
            case 51:
                // modify password
                system("cls");
                cout << "\n\t\t 正在修改密码" << endl;
                char temp_case51[64];
                strcpy_s(temp_case51, kb->get_consol());
                strcpy_s(i->Password, temp_case51);
                break;
            default:
                return true;
                break;
            }
            break;
        }
        else
        {
            cout << "\n\t\t 找不到" << endl;
           
        }
        i++;
    }
    fl->write_to_client(client_manage_v);
    return true;
}

void clients_manage::show_client(char *id)
{
    client temp = fl->find_client(id);
    cout << temp.ID << " " << temp.Name << " " << temp.Password << endl;
    return;
}

void clients_manage::show_client()
{
    client_manage_v.clear();
    client_manage_v=fl->load_client();
    cout << "ID:" << " " << "Name" << " " << "Password" << endl;
    for (int i = 0; i < client_manage_v.size(); i++)
    {
        cout << client_manage_v[i].ID << " " << client_manage_v[i].Name << " " << client_manage_v[i].Password << endl;
    }
    cout << "\n\t\t 按任意键继续 ";
    kb->get_for_choose();
    return;
}
