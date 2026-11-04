#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct barang {
    string kode;
    string nama;
    int tahun;
};

using infotype = barang;
struct elmlist;
using address = elmlist*;
struct elmlist { infotype info; address prev; address next; };
struct List { address first; address last; };

void CreateList(List &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address R, address P);
void insertBefore(List &L, address R, address P);
void printInfo(const List &L);
address findElm(const List &L, const string &kode);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address R, address &P);
void deleteBefore(List &L, address R, address &P);
#endif