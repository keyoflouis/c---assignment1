#pragma once
#include<iostream>
#include<string>
using namespace std;

class client
{
public:
    char ID[64];
    char Name[64];
    char Password[64];
public:
    client(const char* id,const char* name,const char* password);
    client();
    ~client();
};
