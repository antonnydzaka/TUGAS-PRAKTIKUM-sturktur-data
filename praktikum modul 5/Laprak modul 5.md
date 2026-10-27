# <h1 align="center">Modul 5 SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">Antonny Dzaka Fadhillah - 109082500038</p>

## Guided

### 1. Singly Linked List Data Buah

Program Guided mengembangkan ADT singly linked list dari Modul 4. Setiap node menyimpan nama buah, jumlah, harga, dan pointer ke node berikutnya. Operasi yang ditambahkan pada Modul 5 adalah pembaruan data serta pencarian node berdasarkan nama, alamat, dan rentang harga.

#### `listBuah.h`

```cpp
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

#### `listBuah.cpp`

```cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    return List.first == Nil;
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List) {
    if (!isEmpty(List)) {
        address nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    if (!isEmpty(List)) {
        address nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            address nodePrev;
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else if (nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node setelah node " << nodePrev->isidata.nama
             << " berhasil terhapus!" << endl;
    } else {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama
                 << ", Jumlah : " << nodeBantu->isidata.jumlah
                 << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedlist &List) {
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        address nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

void updateFirst(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else if (nodePrev != Nil && nodePrev->next != Nil) {
        address nodeBantu = nodePrev->next;
        cout << "masukkan update data node setelah node "
             << nodePrev->isidata.nama << " : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    } else {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
    }
}

void FindNodeByData(linkedlist list, string data) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu->isidata.nama == data) {
                cout << "Data " << data << " ditemukan pada posisi ke-"
                     << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama
                     << ", Jumlah : " << nodeBantu->isidata.jumlah
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (!found) {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByAddress(linkedlist list, address node) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!"
                     << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama
                     << ", Jumlah : " << nodeBantu->isidata.jumlah
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (!found) {
            cout << "Node dengan alamat " << node
                 << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - "
             << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if (harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :"
                     << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama
                     << ", Jumlah : " << nodeBantu->isidata.jumlah
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (!found) {
            cout << "Tidak ada data buah dalam range harga tersebut!"
                 << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

#### `main.cpp`

```cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);
    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl << endl;
    return 0;
}
```

#### Penjelasan dan hasil

`main` membentuk list awal `Jeruk → Pir → Semangka → Apel → Durian`. List dibentuk dengan kombinasi `insertFirst`, `insertAfter`, dan `insertLast`. Kemudian program meminta input untuk memperbarui node pertama, node terakhir, dan node setelah Semangka.

Sebagai contoh pengujian, data pembaruan yang dimasukkan adalah `Mangga 50 6000`, `Apel 75 4000`, dan `Nanas 30 9000`. Sesudah pembaruan, program mencari nama `kelapa` (tidak ditemukan), mencari node `nodeC` (Pir), dan mencari buah dengan harga antara 5000 dan 10000 (Mangga, Pir, dan Nanas). Setelah `delFirst`, `delLast`, dan `delAfter`, tersisa Pir dan Nanas. `deleteList` menghapus semua node dan jumlah node menjadi 0.

Output pencarian dan akhir program:

```text
Node dengan data kelapa tidak ditemukan!
Node ditemukan pada posisi ke-2!
Nama Buah : Pir, Jumlah : 87, Harga : 5000

Buah dalam range harga 5000 - 10000:
Mangga, Pir, Nanas

Isi list setelah delete:
Pir
Nanas
jumlah node : 2
List berhasil terhapus!
List kosong.
jumlah node : 0
```

## Unguided

Folder Unguided Modul 5 berisi Soal 2, Soal 3, dan Soal 4. Ketiganya memakai singly linked list dengan node berisi bilangan bulat; setiap node dimasukkan ke awal list sehingga urutan tampilannya terbalik dari urutan alokasi.

### 2. Menampilkan elemen singly linked list

#### `singlylist.h`

```cpp
#ifndef SINGLYLIST_H_INCLUDE
#define SINGLYLIST_H_INCLUDE
#include <iostream>
using namespace std;

typedef int infoType;
typedef struct singlylist *address;

struct singlylist {
    infoType info;
    address next;
};

struct linkedlist {
    address first;
};

void createlist(linkedlist &list);
address alokasi(int angka);
void dealokasi(address &node);
void printinfo(linkedlist list);
void insertfirst(linkedlist &list, address newinfo);

#endif
```

#### `singlylist.cpp`

```cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

void createlist(linkedlist &List) {
    List.first = NULL;
}

address alokasi(int angka) {
    address newinfo = new singlylist;
    newinfo->info = angka;
    newinfo->next = NULL;
    return newinfo;
}

void dealokasi(address &node) {
    delete node;
    node = NULL;
}

void printinfo(linkedlist list) {
    address helper = list.first;
    while (helper != NULL) {
        cout << helper->info << " ";
        helper = helper->next;
    }
}

void insertfirst(linkedlist &List, address newinfo) {
    newinfo->next = List.first;
    List.first = newinfo;
}
```

#### `main.cpp`

```cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist L;
    address p1, p2, p3, p4, p5 = NULL;
    createlist(L);
    p1 = alokasi(2);
    insertfirst(L, p1);
    p2 = alokasi(0);
    insertfirst(L, p2);
    p3 = alokasi(8);
    insertfirst(L, p3);
    p4 = alokasi(12);
    insertfirst(L, p4);
    p5 = alokasi(9);
    insertfirst(L, p5);
    printinfo(L);
    return 0;
}
```

#### Output Unguided 2

![Output Soal 2](Unguided/soal%202/Screenshot%202026-10-28%20001013.png)

#### Penjelasan

Lima node bernilai 2, 0, 8, 12, dan 9 dimasukkan memakai `insertfirst`. Karena setiap node baru menjadi `first`, list yang tercetak adalah `9 12 8 0 2`.

### 3. Mencari elemen pada singly linked list

Soal 3 menambahkan fungsi `findElm` untuk mencari elemen yang nilainya sama dengan nilai pada node acuan.

Berkas lengkap: [`singlylist.h`](Unguided/soal%203/singlylist.h), [`singlylist.cpp`](Unguided/soal%203/singlylist.cpp), dan [`main.cpp`](Unguided/soal%203/main.cpp). ADT dasar sama dengan Soal 2; berikut deklarasi dan implementasi fungsi tambahan.

#### Deklarasi tambahan pada `singlylist.h`

```cpp
address findElm(linkedlist L, address x);
```

#### Implementasi `findElm` pada `singlylist.cpp`

```cpp
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
```

Fungsi menerima `address x`, lalu membandingkan `info` setiap node dengan `x->info`. Pada program utama, `p3` menunjuk node bernilai 8, sehingga hasil pencarian adalah node bernilai 8.

#### `main.cpp`

```cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist L;
    address p1 = NULL, p2 = NULL, p3 = NULL, p4 = NULL, p5 = NULL;
    createlist(L);
    p1 = alokasi(2);
    insertfirst(L, p1);
    p2 = alokasi(0);
    insertfirst(L, p2);
    p3 = alokasi(8);
    insertfirst(L, p3);
    p4 = alokasi(12);
    insertfirst(L, p4);
    p5 = alokasi(9);
    insertfirst(L, p5);
    printinfo(L);

    address found = findElm(L, p3);
    if (found != NULL) {
        cout << found->info << " ditemukan dalam list\n";
    } else {
        cout << "Data tidak ditemukan dalam list\n";
    }
    return 0;
}
```

#### Output Unguided 3

![Output Soal 3](Unguided/soal%203/Screenshot%202026-10-28%20002658.png)

#### Penjelasan

Urutan list adalah `9 12 8 0 2`. Fungsi `findElm(L, p3)` menemukan nilai 8 dan program menampilkan `8 ditemukan dalam list`.

### 4. Menjumlahkan seluruh info dalam list

Soal 4 menambahkan fungsi `sumInfo`, yang menelusuri node dari `first` sampai `NULL` dan menjumlahkan seluruh nilai `info`.

Berkas lengkap: [`singlylist.h`](Unguided/soal%204/singlylist.h), [`singlylist.cpp`](Unguided/soal%204/singlylist.cpp), dan [`main.cpp`](Unguided/soal%204/main.cpp). ADT dasar sama dengan Soal 2; berikut deklarasi dan implementasi fungsi tambahan.

#### Deklarasi tambahan pada `singlylist.h`

```cpp
int sumInfo(linkedlist list);
```

#### Implementasi `sumInfo` pada `singlylist.cpp`

```cpp
int sumInfo(linkedlist list) {
    int total = 0;
    address current = list.first;

    while (current != NULL) {
        total += current->info;
        current = current->next;
    }

    return total;
}
```

#### `main.cpp`

```cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist L;
    address p1 = NULL, p2 = NULL, p3 = NULL, p4 = NULL, p5 = NULL;
    createlist(L);
    p1 = alokasi(2);
    insertfirst(L, p1);
    p2 = alokasi(0);
    insertfirst(L, p2);
    p3 = alokasi(8);
    insertfirst(L, p3);
    p4 = alokasi(12);
    insertfirst(L, p4);
    p5 = alokasi(9);
    insertfirst(L, p5);
    printinfo(L);
    cout << "Jumlah total info: " << sumInfo(L) << endl;
    return 0;
}
```

#### Output Unguided 4

![Output Soal 4](Unguided/soal%204/Screenshot%202026-10-28%20002758.png)

#### Penjelasan

Isi list adalah `9 12 8 0 2`. Fungsi `sumInfo` menjumlahkan kelima elemen tersebut: **9 + 12 + 8 + 0 + 2 = 31**.

## Kesimpulan

Singly linked list menyimpan setiap elemen dalam node yang memiliki data dan pointer `next`. Pointer `first` mengacu pada node pertama. Modul ini menggunakan operasi dasar untuk membuat list, mengalokasikan node, menyisipkan node di awal, menelusuri list, mencari elemen, dan menghitung jumlah data. Pada Guided, operasi diperluas dengan pembaruan, pencarian berdasarkan data/alamat/rentang, serta penghapusan node dan seluruh list. Pengelolaan tautan antarnode dan memori diperlukan agar operasi list berjalan dengan benar.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4
