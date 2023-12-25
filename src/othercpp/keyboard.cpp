#include"keyboard.hpp"
#include<iostream>
#include<conio.h>
using namespace std;

keyboard::keyboard(/* args */)
{
}

keyboard::~keyboard()
{
	delete[] kb_in;
}

int keyboard::get_for_choose()
{
    
	while(true){
		if (kbhit())
		{
            return getch();
		}
	}
}

char* keyboard::get_consol()
{
    cin>>kb_in;
	getchar();
    return kb_in;
}
