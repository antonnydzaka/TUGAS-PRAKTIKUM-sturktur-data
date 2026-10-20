#include "soal.h"
#include <iostream>
#define nil NULL 
using namespace std;

bool isEmpty(list L) {
    if (L.first == nil) {
        return true;
    } else {
        return false;
    }
}

void createList(list &L) {
    L.first = nil;
}

address alokasi(int angka) {
    address nodeBaru = new Elmlist;
    nodeBaru-> type = angka ;
    nodeBaru->next = nil ;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = nil;
    delete node;
}

void insertFirst(list &l, address nodeBaru) {
    nodeBaru->next = l.first;
    l.first = nodeBaru;
}

void printInfo(list l) {
    if (isEmpty(l)) {
        cout << "l kosong." << endl;
    } else {
        address nodeBantu = l.first;

        while (nodeBantu != nil) {
            cout << nodeBantu->type << " ";

            nodeBantu = nodeBantu->next;
        }
    }
}