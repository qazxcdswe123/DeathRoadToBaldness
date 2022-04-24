#ifndef RDATABASE_H
#define RDATABASE_H

#include "Reader.h"
#include <iostream>

using namespace std;

const int Maxr = 100;
class RDatabase
{
private:
    int top;
    Reader read[Maxr];

public:
    RDatabase();
    void clear();
    int addreader(int n, char *na);
    Reader *query(int readerid);
    void list();
    void readerdata();
    ~RDatabase();
};
#endif