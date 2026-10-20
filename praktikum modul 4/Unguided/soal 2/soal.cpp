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

void delFirst(list &l) {
    address nodeHapus;

    if (isEmpty(l) == false) {
        nodeHapus = l.first;
        l.first = l.first->next;
        nodeHapus->next = nil;
        dealokasi(nodeHapus);
    } else {
        cout << "l kosong!" << endl;
    }
}

void delLast(list &l) {
    address nodeHapus, nodePrev;

    if (isEmpty(l) == false) {
        nodeHapus = l.first;

        if (nodeHapus->next == nil) {
            l.first->next = nil;
            dealokasi(nodeHapus);
            l.first = nil;
        } else {
            while (nodeHapus->next != nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }

            nodePrev->next = nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "l kosong" << endl;
    }
}

void delAfter(list &l, address nodeHapus, address nodePrev) {
    if (isEmpty(l) == true) {
        cout << "l kosong!" << endl;
    } else {
        if (nodePrev != nil && nodePrev->next != nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
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
        cout << "\n";
    }
}

int nbList(list l) {
    int count = 0;
    address nodeBantu = l.first;

    while (nodeBantu != nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    
    return count;
}

void deleteList(list &l) {
    address nodeBantu, nodeHapus;
    nodeBantu = l.first;

    while (nodeBantu != nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }

    l.first = nil;
    cout << "l sudah terhapus!" << endl;
}
