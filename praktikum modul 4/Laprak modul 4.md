# <h1 align="center">Modul 4  SINGLY LINKED LIST (BAGIAN PERTAMA) </h1>
<p align="center">Antonny Dzaka Fadhillah - 109082500038</p>

## Guided 

### 1. Guided mahasiswa

```C++
// list.cpp
    // list.cpp
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nill) {
        return true;
    } else {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nill;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /*
       I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nill
    */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nill;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /*
       I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem
    */
    node->next = Nill;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /*
       I.S. sembarang, P sudah dialokasi
       F.S. menempatkan elemen list (node) pada awal list
    */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /*
       I.S. sembarang, nodeBaru dan Prev adalah salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev
    */
    if (Prev != Nill) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /*
       I.S. sembarang, nodeBaru sudah dialokasi
       F.S. menempatkan elemen pada akhir list
    */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;

        while (nodeBantu->next != Nill) {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada di dalam list
void delFirst(linkedList &List) {
    /*
       I.S. list tidak kosong
       F.S. node pertama di list terhapus
    */
    address nodeHapus;

    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nill;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    /*
       I.S. list tidak kosong
       F.S. node terakhir di list terhapus
    */
    address nodeHapus, nodePrev;

    if (isEmpty(List) == false) {
        nodeHapus = List.first;

        if (nodeHapus->next == Nill) {
            List.first->next = Nill;
            dealokasi(nodeHapus);
            List.first = Nill;
        } else {
            while (nodeHapus->next != Nill) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }

            nodePrev->next = Nill;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    /*
       I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list
    */
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nill && nodePrev->next != Nill) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nill;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /*
       I.S. mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list
    */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;

        while (nodeBantu != Nill) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur
                 << endl;

            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node di dalam list
int nbList(linkedList List) {
    /*
       I.S. list sudah ada
       F.S. menampilkan jumlah node di dalam list
    */
    int count = 0;
    address nodeBantu = List.first;

    while (nodeBantu != Nill) {
        count++;
        nodeBantu = nodeBantu->next;
    }

    return count;
}

// prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedList &List) {
    /*
       I.S. list sudah ada
       F.S. menghapus semua node di dalam list
    */
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;

    while (nodeBantu != Nill) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }

    List.first = Nill;
    cout << "List sudah terhapus!" << endl;
}
// list.h
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nill NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isis setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & procedure yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif

// main.cpp
#include "list.h"

#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nill;

    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211100014", 21);
    nodeC = alokasi("Rizal", "2311100029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}

```
### Penjelasan

Program pada bagian guided menerapkan **singly linked list** untuk menyimpan data mahasiswa. Setiap node berisi nama, NIM, umur, serta pointer `next` yang menunjuk ke node berikutnya. Pointer `first` pada `linkedList` menjadi penanda node pertama, sedangkan `Nill` menandakan pointer kosong atau akhir list.

- `createList` menginisialisasi list kosong dengan mengatur `first` ke `Nill`, dan `isEmpty` memeriksa kondisi tersebut.
- `alokasi` membuat node baru secara dinamis, mengisi data mahasiswa dari parameter, lalu mengatur `next` ke `Nill`. `dealokasi` membebaskan memori node yang sudah tidak digunakan.
- `insertFirst`, `insertAfter`, dan `insertLast` menambahkan node di awal, setelah node tertentu, dan di akhir list. Penyisipan dilakukan dengan menyesuaikan hubungan pointer `next`.
- `delFirst`, `delLast`, dan `delAfter` melepaskan node dari list, kemudian memanggil `dealokasi` agar memorinya dibebaskan. `printList` menelusuri list dari `first` sampai `Nill` untuk menampilkan data, sedangkan `nbList` menghitung jumlah node.
- `deleteList` menelusuri dan membebaskan semua node satu per satu, lalu mengatur `first` kembali ke `Nill`.

Pada `main`, lima data mahasiswa dibuat dan dimasukkan berurutan sehingga list menjadi **Dhimas → Rizal → Satrio → Arvin → Joshua**. Setelah `delFirst`, `delLast`, dan `delAfter` (menghapus node setelah Rizal, yaitu Satrio), isi list menjadi **Rizal → Arvin**. Terakhir, `deleteList` mengosongkan list. `printList` dan `nbList` digunakan untuk menampilkan isi serta jumlah node setelah setiap tahap.


## Unguided 

### 1.Buatlah ADT Singly Linked
```C++
// soal.cpp
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
// soal.h
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
// main.cpp
#include "soal.h"
#include <iostream>
#define nil NULL

using namespace std;

int main(){
    list L;
    address P1, P2, P3, P4, P5 = nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1

### Penjelasan
Pada program Unguided 1, ADT singly linked list dibuat dengan setiap node menyimpan sebuah bilangan dan alamat node berikutnya. List diinisialisasi kosong, lalu lima node bernilai 2, 0, 8, 12, dan 9 dimasukkan menggunakan `insertFirst`. Karena setiap node selalu ditambahkan di bagian depan, urutan list menjadi `9 12 8 0 2` saat ditampilkan oleh `printInfo`.

### 2.Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h” folder pelajaran

```C++
// soal.h
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

void delFirst(list &l);
void delLast(list &l);
void delAfter(list &l, address nodeHapus, address nodePrev);
int nbList(list l);
void deleteList(list &l);

#endif
// soal.cpp
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

// main.cpp
#include "soal.h"
#include <iostream>
#define nil NULL

using namespace std;

int main(){
    list L;
    address P1, P2, P3, P4, P5 = nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    delFirst(L);
    delLast(L);
    delAfter(L,P3,P4);
    printInfo(L);
    cout << "l tersisa:"<<nbList(L)<<"\n";
    deleteList(L);
    printInfo(L);
    cout << "l tersisa:"<<nbList(L);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1

### Penjelasan
Pada program Unguided 2, lima node dimasukkan ke bagian depan sehingga urutan awalnya adalah `9 12 8 0 2`. Operasi `delFirst` menghapus nilai 9, `delLast` menghapus nilai 2, dan `delAfter` dengan node sebelumnya bernilai 12 menghapus node setelahnya, yaitu nilai 8. List yang tersisa berisi `12 0`, sehingga `nbList` menghasilkan 2. Selanjutnya, `deleteList` menghapus seluruh node; list menjadi kosong, `printInfo` menampilkan pesan bahwa list kosong, dan jumlah node menjadi 0.

## Kesimpulan

Singly linked list menyimpan data dalam node yang saling terhubung melalui pointer `next`, dengan `first` sebagai penunjuk node pertama. ADT ini mendukung pembuatan list, penambahan dan penghapusan node, penelusuran untuk menampilkan data serta menghitung jumlah node, dan penghapusan seluruh isi list. Pengelolaan pointer dan dealokasi memori yang tepat menjaga list tetap terhubung dengan benar dan mencegah node yang sudah dihapus tetap digunakan.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
