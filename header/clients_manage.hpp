#include<vector>
#include"client.hpp"
#include"ui.hpp"
#include"keyboard.hpp"
#include"file.hpp"

using namespace std;

class clients_manage
{
public:
    vector<client> client_manage_v;
public:
    clients_manage(/* args */);
    ~clients_manage();
    bool sign_up(ui* System_ui,keyboard* kb,file* fl);
    bool sign_in(client the_client ,ui* System_ui,keyboard* kb,file* fl);

    bool remove(char id[64],ui* System_ui,keyboard* kb,file* fl);
    bool modify(char id[64],ui* System_ui,keyboard* kb,file* fl);

    void show_client(char* id,ui* System_ui,keyboard* kb,file* fl);
    void show_client(ui* System_ui,keyboard* kb,file* fl);

};
