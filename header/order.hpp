#pragma once


class order
{
public:
    order_sequance order_number;
    char who_id[64];
    char menu_item_name[64];
public:
    order(/* args */);
    order(char* id,char* menu_item_name);
    ~order();
};

struct order_sequance
{
    int time;
    int sequance;

    bool operator==(order_sequance& temp){
        if(this->sequance==temp.sequance && this->time==temp.time){
            return true;
        }else{
            return false;
        }
    }
};
