#ifndef SINGLYLIST_H_INCLUDE
#define SINGLYLIST_H_INCLUDE
#include <iostream>
using namespace std;

typedef int infoType;
typedef struct singlylist *address;

struct singlylist
{
    infoType info;
    address next;
    
};

struct linkedlist
{
    address first;
};

void createlist(linkedlist &list);
address alokasi(int angka);
void dealokasi(address &node);
void printinfo(linkedlist list);
void insertfirst(linkedlist &list, address newinfo);
address findElm(linkedlist L, address x);

#endif