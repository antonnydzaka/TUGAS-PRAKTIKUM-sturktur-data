# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST</h1>
<p align="center">Antonny Dzaka Fadhillah - 109082500038</p>

## Guided

### 1. Operasi Doubly Linked List

Program Guided mengimplementasikan doubly linked list untuk menyimpan data barang berupa kode, nama, dan tahun. Setiap node memiliki dua pointer: `prev` untuk menunjuk node sebelumnya dan `next` untuk menunjuk node sesudahnya. List menyimpan alamat node pertama (`first`) dan terakhir (`last`).

#### `Doublylist.h`

```cpp
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

struct elmlist {
    infotype info;
    address prev;
    address next;
};

struct List {
    address first;
    address last;
};

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
```

#### Implementasi operasi pada `Doublylist.cpp`

```cpp
void CreateList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

address alokasi(const infotype &x) {
    address P = new elmlist;
    P->info = x;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void insertFirst(List &L, address P) {
    P->prev = nullptr;
    P->next = L.first;
    if (L.first) L.first->prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->next = nullptr;
    P->prev = L.last;
    if (L.last) L.last->next = P;
    else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address R, address P) {
    P->prev = R;
    P->next = R->next;
    if (R->next) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

void insertBefore(List &L, address R, address P) {
    P->next = R;
    P->prev = R->prev;
    if (R->prev) R->prev->next = P;
    else L.first = P;
    R->prev = P;
}

address findElm(const List &L, const string &kode) {
    address P = L.first;
    while (P) {
        if (P->info.kode == kode) return P;
        P = P->next;
    }
    return nullptr;
}
```

Fungsi penghapusan menyesuaikan tautan tetangga serta `first` atau `last` bila node yang dihapus berada di ujung list. Node yang dilepas dikembalikan melalui parameter `P`, lalu memorinya dibebaskan dengan `dealokasi(P)`. Implementasi lengkap seluruh fungsi terdapat pada [`Guided/Doublylist.cpp`](Guided/Doublylist.cpp).

#### Alur pada `main.cpp`

Program membuat empat data barang: B001 (Laptop, 2020), B002 (Monitor, 2022), B003 (Keyboard, 2023), dan B004 (Mouse, 2024). Data dimasukkan dengan `insertFirst`, `insertLast`, `insertAfter`, dan `insertBefore`. Setelah itu program mencari B003, menghapus node setelah B002, menghapus node sebelum B004, lalu menghapus node pertama dan terakhir. Setiap node yang dihapus dibebaskan dengan `dealokasi`.

#### Penjelasan dan hasil

Pada setiap operasi penyisipan dan penghapusan, hubungan dua arah antarnode harus tetap konsisten: jika `A->next` menunjuk `B`, maka `B->prev` harus menunjuk `A`. Contoh hasil akhirnya, setelah seluruh penghapusan pada demonstrasi, list menjadi kosong dan kedua pointer ujung bernilai `nullptr`. Implementasi program utama dapat dilihat pada [`Guided/main.cpp`](Guided/main.cpp).

## Unguided

Ketiga latihan Unguided menggunakan doubly linked list untuk menyimpan informasi kendaraan, yaitu nomor polisi, warna, dan tahun kendaraan. Berkas program terdapat pada folder masing-masing latihan.

### 1. Mendeteksi nomor polisi duplikat

#### Struktur data dan operasi

ADT pada [`Unguided/Unguided 1/Doublylist.h`](<Unguided/Unguided 1/Doublylist.h>) mendefinisikan node dengan `next` dan `prev`, serta list dengan pointer `First` dan `Last`. Fungsi `cekDuplikat` menelusuri node dari `First` dan mengembalikan `true` jika nomor polisi sudah ada.

```cpp
bool cekDuplikat(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}
```

#### Hasil dan penjelasan

Program memasukkan kendaraan D001 (hitam, 90) dan D003 (putih, 70). Saat nomor D001 dimasukkan lagi, program menampilkan pesan bahwa nomor polisi sudah terdaftar dan tidak menambahkan data duplikat. Kemudian D004 (kuning, 90) ditambahkan. `printInfo` menelusuri list dari `Last` melalui `prev`, sehingga urutan tampilan adalah D004, D003, lalu D001.

![Output Unguided 1](Unguided/Unguided%201/Screenshot%202026-11-05%20005225.png)

Kode utama dan implementasi lengkap dapat dilihat pada [`Unguided/Unguided 1/main.cpp`](<Unguided/Unguided 1/main.cpp>) dan [`Unguided/Unguided 1/Doublylist.cpp`](<Unguided/Unguided 1/Doublylist.cpp>).

### 2. Mencari data kendaraan

Latihan kedua menambahkan fungsi `findElm` untuk mencari node berdasarkan nomor polisi. Fungsi membandingkan `x.nopol` dengan setiap `info.nopol` mulai dari `First`; alamat node dikembalikan jika ditemukan, dan `NULL` dikembalikan jika tidak ditemukan.

```cpp
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
```

#### Hasil dan penjelasan

Dengan data kendaraan yang sama seperti latihan pertama, program meminta nomor polisi yang dicari. Pada contoh pengujian, nomor D004 ditemukan dan program menampilkan nomor polisi, warna kuning, dan tahun 90. Jika nomor tidak ada di dalam list, program menampilkan pesan bahwa kendaraan tidak ditemukan.

![Output Unguided 2](Unguided/Unguided%202/Screenshot%202026-11-05%20005406.png)

Kode program tersedia pada [`Unguided/Unguided 2/Doublylist.h`](<Unguided/Unguided 2/Doublylist.h>), [`Unguided/Unguided 2/Doublylist.cpp`](<Unguided/Unguided 2/Doublylist.cpp>), dan [`Unguided/Unguided 2/main.cpp`](<Unguided/Unguided 2/main.cpp>).

### 3. Menghapus data kendaraan

Latihan ketiga menambahkan operasi penghapusan node pertama, node terakhir, dan node setelah node acuan. Program terlebih dahulu mencari node berdasarkan nomor polisi. Jika node ditemukan, program memilih operasi sesuai posisinya:

```cpp
if (pDel == L.First) {
    deleteFirst(L, pDel);
} else if (pDel == L.Last) {
    deleteLast(L, pDel);
} else {
    deleteAfter(pDel->prev, pDel);
}
dealokasi(pDel);
```

`deleteFirst` dan `deleteLast` memperbarui pointer ujung list. `deleteAfter` menyambungkan node sebelum dan sesudah node yang dihapus. Setelah tautannya diperbaiki, `dealokasi` membebaskan memori node tersebut.

#### Hasil dan penjelasan

Pada contoh pengujian, nomor polisi D003 dihapus dari list yang berisi D001, D003, dan D004. Program menampilkan pesan bahwa data berhasil dihapus, lalu mencetak list kembali. Karena pencetakan dimulai dari `Last`, hasil setelah penghapusan menampilkan D004 kemudian D001.

![Output Unguided 3](Unguided/Unguided%203/Screenshot%202026-11-05%20005534.png)

Kode program tersedia pada [`Unguided/Unguided 3/Doublylist.h`](<Unguided/Unguided 3/Doublylist.h>), [`Unguided/Unguided 3/Doublylist.cpp`](<Unguided/Unguided 3/Doublylist.cpp>), dan [`Unguided/Unguided 3/main.cpp`](<Unguided/Unguided 3/main.cpp>).

## Kesimpulan

Doubly linked list menyimpan setiap elemen dalam node yang memiliki pointer ke node sebelum dan sesudahnya. Pointer `First` dan `Last` memudahkan akses ke kedua ujung list, sedangkan tautan `prev` dan `next` memungkinkan penelusuran dua arah. Praktikum ini menerapkan pembuatan list, alokasi node, penyisipan di beberapa posisi, pencarian data, deteksi duplikasi, penghapusan node, dan dealokasi memori. Setiap operasi harus memperbarui tautan kedua arah dan pointer ujung dengan benar agar struktur list tetap valid.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4
