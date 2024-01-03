#include "menu.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include "menu_item.hpp"
#include "keyboard.hpp"
#include <string.h>
#include "ui.hpp"

using namespace std;

menu::menu(/* args */)
{
}

menu::~menu()
{
}

void menu::show_menu()
{
    // depend on the way of store a menu_item
    vector<menu_item> manage;
    manage = fl->load_menu();
    system("cls");
    cout << "\t\t---------------------------------" << endl;
    cout << "\t\t|         ����   �۸�           |" << endl<<endl;
    for (int i = 0; i < manage.size(); i++)
    {
        cout <<"\t\t         " << manage[i].name << "    " << manage[i].price << endl;
        if (i==manage.size()-1) {
            cout << "\t\t---------------------------------" << endl;
        }
    }
    cout << "\n �������������:" << endl;
    kb->get_for_choose();
    return;
}

int menu::add_menu()
{
    system("cls");
    cout << "\n\t\t ������ӵĲ��� ,�۸�" << endl;
    char name[64];
    strcpy(name, kb->get_consol());

    int price;
    cin >> price;
    fl-> menu_for_add.push_back(menu_item(name, price));


    fl->addtofile_Menu();
    system("cls");
    cout << "\n\t\t ��ӳɹ�" << endl;
    cout << "\n �������������:" << endl;
    kb->get_for_choose();
    return 0;
}

int menu::remov_menu()
{
    system("cls");
    cout << "\n\t\t ����ɾ���˵����������" << endl;
    char name[64];
    strcpy(name, kb->get_consol());

    menu_manage.clear();
    menu_manage = fl->load_menu();
    
    for (int i = 0; i < menu_manage.size(); i++)
    {
        if (strcmp(menu_manage[i].name, name) == 0)
        {
            System_ui->remov_menu_ui(name);
            int temp = kb->get_for_choose();
            if (temp == 49)
            {
                menu_manage.erase(menu_manage.begin() + i);
                fl->write_to_menu(menu_manage);

                system("cls");
                cout << "\n\t\t �Ƴ��ɹ�" << endl;
                cout << "\n �������������:" << endl;
                kb->get_for_choose();
            }
            else if (temp == 50)
            {
                return 1;
            }
            else
            {
            }
            break;
        }
    }

    return 0;
}

int menu::modify_menu()
{
    system("cls");
    cout << "�����޸Ĳ˵� , ���뱻�޸ĵĲ˵�����" << endl;
    char Name[64];
    strcpy(Name, kb->get_consol());
    menu_manage.clear();
    menu_manage = fl->load_menu();

    for (int i = 0; i < menu_manage.size(); i++)
    {
        if (strcmp(menu_manage[i].name, Name) == 0)
        {

            System_ui->modify_menu_ui();
            int temp = kb->get_for_choose();
            while (temp != 49 && temp != 50)
            {
                temp = kb->get_for_choose();
            }
            
            char temp_49[64];
            int temp_50;
            vector<menu_item>::iterator i = menu_manage.begin();

            switch (temp)
            {
            case 49:
                // modify name
                system("cls");
                cout << "\n\t\t �����޸ĺ�Ĳ˵����ƣ�" << endl;
                strcpy(temp_49, kb->get_consol());


                while (i!=menu_manage.end())
                {
                    if (strcmp(i->name, Name) == 0)
                    {
                        strcpy(i->name, temp_49);
                        break;
                    }
                    i++;
                }

                fl->write_to_menu(menu_manage);
                system("cls");
                cout << "\n\t\t �޸ĳɹ�" << endl;
                cout << "\n �������������:" << endl;
                kb->get_for_choose();
                break;

            case 50:
                // modify price
                system("cls");
                cout << " \n\t\t �����޸ĺ�ļ۸�" << endl;

                cin >> temp_50;
                while (i!=menu_manage.end())
                {
                    if (strcmp(i->name, Name) == 0)
                    {
                        i->price = temp_50;
                        break;
                    }
                    i++;
                }
                fl->write_to_menu(menu_manage);
                system("cls");
                cout << "\n\t\t �޸ĳɹ�" << endl;
                cout << "\n �������������:" << endl;
                kb->get_for_choose();
                break;

            default:
                return true;
                break;
            }
            break;
        }
        else
        {
            cout << "\n\t\t �Ҳ���" << endl;
        }
    }
    fl->write_to_menu(menu_manage);
    return true;
}

menu_item menu::match(int numb)
{
    menu_manage.clear();
    menu_manage=fl->load_menu();
    return menu_manage[numb];
}
