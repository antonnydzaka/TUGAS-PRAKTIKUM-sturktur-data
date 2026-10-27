#include "singlylist.h"
#include <iostream>
using namespace std;

void createlist(linkedlist &List){
    List.first = NULL;
}

address alokasi(int angka){
    address newinfo = new singlylist;
    newinfo ->info = angka;
    newinfo -> next = NULL;
    return newinfo;
}

void dealokasi(address &node){
    delete node;
    node = NULL;
}

void printinfo(linkedlist list){
    address helper = list.first;

    while (helper != NULL)
    {
        cout << helper->info <<" ";
        helper = helper->next;
    }
    cout << endl;
}

void insertfirst(linkedlist &List, address newinfo) {
    newinfo->next = List.first;
    List.first = newinfo;
}

address findElm(linkedlist list, address x) {
    if (x == NULL) {
        return NULL;
    }

    address P = list.first;
    while (P != NULL) {
        if (P->info == x->info) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}