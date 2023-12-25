#pragma once
#include<string>
using namespace std;

class keyboard
{
private:
    char* kb_in=new char[64];
public:
    keyboard(/* args */);
    ~keyboard();
    
    int get_for_choose();
    char* get_consol();
};
