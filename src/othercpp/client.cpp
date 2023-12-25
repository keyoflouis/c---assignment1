#include"client.hpp"
#include<string.h>
using namespace std;
client::client(const char* id,const char* name,const char* password)
{
    strcpy(this->ID,id);
    strcpy(this->Name,name);
    strcpy(this->Password,password);
}

client::client()
{
}

client::~client()
{
}
