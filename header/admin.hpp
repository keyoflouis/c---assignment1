#pragma once
class admin
{
public:
    char ID[64];
    char Password[64];

public:
    admin(/* args */);
    admin(const char *, const char *);
    ~admin();
};
