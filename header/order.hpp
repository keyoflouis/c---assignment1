#pragma once
#include <ctime>
#include <string.h>

struct order_sequance
{
private:

public:
    char Time[64];
    unsigned int sequance;
    time_t the_Time ;

    order_sequance():sequance(0)
    {
        time_t now = time(0);
        the_Time = now;

        char dt[64];

        ctime_s(dt, 64, &now);
        dt[strcspn(dt, "\n")] = 0;

        strcpy_s(this->Time, dt);
    }

    bool operator==(order_sequance &temp)
    {
        if (this->sequance == temp.sequance && strcmp(this->Time, temp.Time) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class order
{
public:
    order_sequance order_number;
    char who_id[64];
    char menu_item_name[64];

public:
    
    order(/* args */);
    order(char *id, char *menu_item_name);
    ~order();
};
