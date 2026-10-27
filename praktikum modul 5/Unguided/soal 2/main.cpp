#include "singlylist.h"
#include <iostream>
using namespace std;

int main(){
    linkedlist L;
    address p1, p2,p3 ,p4 ,p5 = NULL;
    createlist(L);
    p1 = alokasi(2);
    insertfirst(L,p1);
    p2 = alokasi(0);
    insertfirst(L,p2);
    p3 = alokasi(8);
    insertfirst(L,p3);
    p4 = alokasi(12);
    insertfirst(L,p4);
    p5 = alokasi(9);
    insertfirst(L,p5);
    printinfo(L);
    return 0;
}

