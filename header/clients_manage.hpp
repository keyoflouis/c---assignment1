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
    bool sign_up();
    bool sign_in(client the_client );

    bool remove(char id[64]);
    bool modify(char id[64]);

    void show_client(char* id);
    void show_client();

};
extern clients_manage* cm;