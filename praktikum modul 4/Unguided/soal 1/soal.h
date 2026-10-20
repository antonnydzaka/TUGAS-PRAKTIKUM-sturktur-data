#ifndef SOAL_H_INCLUDE 
#define SOAL_H_INCLUDE
#define nil NULL 
#include <iostream>

using namespace std;

typedef int infotype;
typedef struct Elmlist *address;

struct  Elmlist
{
    infotype type;
    address next;
};

struct list
{
    address first;
};

bool isEmpty (list l);
void createList(list &l);
address alokasi(int type);
void dealokasi(address &node);
void printInfo(list l);
void insertFirst(list &l, address nodeBaru);

#endif