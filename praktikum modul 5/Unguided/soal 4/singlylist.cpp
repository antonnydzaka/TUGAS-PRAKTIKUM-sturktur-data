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
}

void insertfirst(linkedlist &List, address newinfo) {
    newinfo->next = List.first;
    List.first = newinfo;
}

int sumInfo(linkedlist list) {
    int total = 0;
    address current = list.first;

    while (current != NULL) {
        total += current->info;
        current = current->next;
    }

    return total;
}
