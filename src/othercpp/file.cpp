#include "file.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include "client.hpp"
#include "admin.hpp"
using namespace std;

file::file(/* args */)
{
}

file::~file()
{
}

bool file::addtofile_Client(client temp)
{

  fstream client_file(client_filepath, ios::app | ios::binary);
  if (!client_file.is_open())
  {
    cout << "cant open clients.txt" << endl;
    return false;
  }
  client_file.write((char *)&temp, sizeof(temp));

  //   for(int i=0;i<client_add.size();i++){
  //       if(i==0){
  //           client_file<<"\n"<<client_add[i].ID<<" "<<client_add[i].Name<<" "<<client_add[i].Password<<endl;
  //
  //       }
  //       client_file<<client_add[i].ID<<" "<<client_add[i].Name<<" "<<client_add[i].Password<<endl;
  //   }

  client_file.close();
  cout << "successed" << endl;
  getchar();
  return true;
}

bool file::is_has_id_forclient(const char *in_id)
{
  fstream client_file(client_filepath, ios::in | ios::binary);
  /*get each line from the clients.txt */
  client temp_client;
  while (client_file.read((char *)&temp_client, sizeof(temp_client)))
  {
    if (strcmp(temp_client.ID, in_id) == 0)
    {

      client_file.close();
      return true;
    }
  }

  client_file.close();
  return false;
}

client file::find_client(const char *in_id)
{
  fstream client_file(client_filepath, ios::in | ios::binary);
  /*get each line from the clients.txt */
  client temp_client;
  while (client_file.read((char *)&temp_client, sizeof(temp_client)))
  {
    if (strcmp(temp_client.ID, in_id) == 0)
    {
      client_file.close();
      return temp_client;
    }
  }

  client_file.close(); // cout<<client_manage[i].ID<<client_manage[i].Name<<client_manage[i].Password<<endl;
}

vector<client> file::load_client()
{
  client temp;
  fstream menu_file(client_filepath, ios::in | ios::binary);

  while (menu_file.read((char *)&temp, sizeof(temp)))
  {
    client_manage.push_back(temp);
  }

  menu_file.close();
  return client_manage;
}

bool file::write_to_client(vector<client> temp1)
{
  client_manage = temp1;
  fstream temp(client_filepath, ios::out | ios::binary);
  for (int i = 0; i < client_manage.size(); i++)
  {
    temp.write((char *)&client_manage[i], sizeof(client));
  }
  temp.close();
  return true;
}

vector<menu_item> file::load_menu()
{
  menu_item temp;
  fstream menu_file(menu_filepath, ios::in | ios::binary);

  while (menu_file.read((char *)&temp, sizeof(temp)))
  {
    menu_manage.push_back(temp);
  }

  menu_file.close();
  return menu_manage;
}

bool file::is_have_menu_item(string name)
{
  fstream menu_file = openFile(menu_filepath);
  /*get each line from the menus.txt */
  string temp;
  while (getline(menu_file, temp, ' '))
  {
    // cout<<temp<<endl;
    if (temp == name)
    {

      // cout << "true"<<endl;
      return true;
    }
  }

  menu_file.close();
  return false;
}

bool file::addtofile_Menu()
{
  fstream menu_file(menu_filepath, ios::app | ios::binary);

  for (int i = 0; i < menu_for_add.size(); i++)
  {
    menu_file.write((char *)&menu_for_add[i], sizeof(menu_item));
  }

  return false;
}

bool file::write_to_menu(vector<menu_item> temp1)
{
  menu_manage = temp1;
  fstream temp(menu_filepath, ios::out | ios::binary);
  for (int i = 0; i < menu_manage.size(); i++)
  {
    temp.write((char *)&menu_manage[i], sizeof(menu_item));
  }
  return true;
}

fstream file::openFile(const char *filepath)
{
  fstream file(filepath);
  if (!file.is_open())
  {
    cout << "cant open file" << filepath << endl;
  }
  return file;
}

bool file::is_has_id_foradmin(const char *in_id)
{
    fstream admin_file(admin_filepath, ios::in | ios::binary);
    /*get each line from the clients.txt */
    admin temp_admin;
    while (admin_file.read((char*)&temp_admin, sizeof(temp_admin)))
    {
        if (strcmp(temp_admin.ID, in_id) == 0)
        {

            admin_file.close();
            return true;
        }
    }

    admin_file.close();
    return false;
}


admin file::find_admin(const char *in_id)
{
  fstream admin_file(admin_filepath, ios::in | ios::binary);
  /*get each line from the clients.txt */
  admin temp_admin;
  while (admin_file.read((char *)&temp_admin, sizeof(temp_admin)))
  {
    if (strcmp(temp_admin.ID, in_id) == 0)
    {

      admin_file.close();
      return temp_admin;
    }
  }

  admin_file.close();
}

bool file::addtofile_admin(admin temp)
{

  fstream admin_file(admin_filepath, ios::app | ios::binary);
  if (!admin_file.is_open())
  {
    cout << "cant open admin.txt" << endl;
    return false;
  }
   admin_file.write((char *)&temp, sizeof(temp));

  admin_file.close();
  cout << "successed" << endl;
  getchar();
  return true;
}

bool file::addtofile_order(order od)
{

  fstream order_file(order_filepath, ios::app | ios::binary);
  if (!order_file.is_open())
  {
    cout << "cant open orders.txt" << endl;
    return false;
  }
  order_file.write((char *)&od, sizeof(od));

  order_file.close();
  cout << "successed order" << endl;
  getchar();
  return true;
}

vector<order> file::load_order()
{
  order temp;
  vector<order> order_manage_load_order;
  fstream order_file(order_filepath, ios::in | ios::binary);

  while (order_file.read((char *)&temp, sizeof(temp)))
  {
    order_manage_load_order.push_back(temp);
  }

  order_file.close();
  return order_manage_load_order;
}

bool file::write_to_order(vector<order> temp1)
{
  order_manage = temp1;
  fstream temp(order_filepath, ios::out | ios::binary);
  for (int i = 0; i < order_manage.size(); i++)
  {
    temp.write((char *)&order_manage[i], sizeof(order));
  }
  return true;
}
