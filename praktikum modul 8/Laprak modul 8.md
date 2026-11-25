# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Antonny Dzaka Fadhillah - 109082500038</p>

## Guided

### 1. Implementasi Queue dengan Linked List

Program Guided pertama mengimplementasikan queue menggunakan linked list. Setiap node menyimpan nilai bertipe `int` dan pointer `next`. Queue menyimpan pointer `head` untuk elemen terdepan serta `tail` untuk elemen terakhir.

#### `queue.h`

```cpp
struct elmQ {
    infotype info;
    address next;
};

struct queue {
    address head, tail;
};
```

#### Implementasi operasi pada `queue.cpp`

```cpp
void insert(queue &Q, address P) {
    if (isEmpty(Q)) {
        Q.head = P;
        Q.tail = P;
    } else {
        Q.tail->next = P;
        Q.tail = P;
    }
}

void deleteQueue(queue &Q, address &P) {
    P = Q.head;
    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = P->next;
    }
    P->next = Nil;
}

void delAll(queue &Q) {
    address P;
    while (!isEmpty(Q)) {
        deleteQueue(Q, P);
        dealokasi(P);
    }
}
```

`CreateQueue` menginisialisasi `head` dan `tail` dengan `Nil`. `insert` menambahkan node di belakang (enqueue), sedangkan `deleteQueue` melepaskan node dari depan (dequeue). Fungsi lain yang digunakan adalah `findElm` untuk mencari nilai, `fFindElm` untuk memeriksa keanggotaan alamat node, dan `nbList` untuk menghitung elemen.

#### Alur pada `main.cpp`

Program memasukkan nilai 5, 2, dan 7, mencari nilai 2 dan 9, menghapus satu elemen, lalu mengosongkan queue.

#### Penjelasan dan hasil

Hasil eksekusi `main.exe`:

```text
isEmpty : 1
Queue kosong
Setelah insert 5, 2, 7
5 2 7
nbList  : 3
findElm(2) ketemu, info = 2
fFindElm : 1
findElm(9) tidak ketemu
Setelah delete, elemen yang keluar = 5
2 7
Setelah delAll
Queue kosong
isEmpty : 1
```

Urutan `5 2 7` menunjukkan prinsip FIFO (*First In, First Out*): elemen yang lebih dahulu dimasukkan, yaitu 5, keluar lebih dahulu. Berkas program tersedia pada [`Guided/guided 1/queue.h`](<Guided/guided 1/queue.h>), [`Guided/guided 1/queue.cpp`](<Guided/guided 1/queue.cpp>), dan [`Guided/guided 1/main.cpp`](<Guided/guided 1/main.cpp>).

### 2. Implementasi Queue Array untuk Data Nama

#### `queue-array.h`

```cpp
const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};
```

Guided kedua menggunakan array berkapasitas lima untuk menyimpan nama. Variabel `head` dan `tail` menunjukkan indeks elemen depan dan belakang. Queue kosong ketika keduanya bernilai `-1`; implementasi yang digunakan menetapkan queue penuh saat `tail` mencapai indeks terakhir.

#### Implementasi operasi pada `queue-array.cpp`

```cpp
void enQueue(queue &Q, string nama) {
    if (isFull(Q)) {
        cout << "Queue sudah penuh!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for (int i = 0; i < Q.tail; i++) {
            Q.nama[i] = Q.nama[i + 1];
        }
        Q.tail--;
        if (Q.tail < 0) {
            Q.head = -1;
            Q.tail = -1;
        }
    }
}
```

Fungsi `enQueue` menambahkan nama setelah elemen terakhir, sedangkan `deQueue` mengeluarkan nama terdepan dan menggeser sisa elemen ke kiri. Program mencoba memasukkan enam nama. Lima nama pertama tersimpan, sementara nama keenam ditolak karena kapasitas array telah penuh.

#### Alur pada `main.cpp`

Program memasukkan enam nama, menampilkan isi queue, lalu memanggil `deQueue` enam kali dan menampilkan queue kembali.

#### Penjelasan dan hasil

```text
nama Dimas berhasil ditambahkan kedalam queue!
nama Arvin berhasil ditambahkan kedalam queue!
nama Rizal berhasil ditambahkan kedalam queue!
nama Hafizh berhasil ditambahkan kedalam queue!
nama Fathur berhasil ditambahkan kedalam queue!
Queue sudah penuh!

--- Isi Queue Setelah enQueue ---
1. Dimas
2. Arvin
3. Rizal
4. Hafizh
5. Fathur

Mengahapus data Dimas...
Mengahapus data Arvin...
Mengahapus data Rizal...
Mengahapus data Hafizh...
Mengahapus data Fathur...
Queue kosong!

--- Isi Queue Setelah deQueue ---
Queue kosong!
```

Setelah semua nama dikeluarkan, queue kembali kosong. Karena implementasi array ini mengandalkan pergeseran dan pemeriksaan `tail`, ruang yang sudah kosong di depan tidak digunakan kembali sebelum seluruh elemen habis. Kode tersedia pada [`Guided/guided 2/queue-array.h`](<Guided/guided 2/queue-array.h>), [`Guided/guided 2/queue-array.cpp`](<Guided/guided 2/queue-array.cpp>), dan [`Guided/guided 2/main.cpp`](<Guided/guided 2/main.cpp>).

## Unguided

Ketiga latihan Unguided menggunakan array berkapasitas lima untuk menyimpan bilangan bulat. Seluruh program menjalankan urutan operasi yang sama: memasukkan 5, 2, dan 7; mengeluarkan satu elemen; memasukkan 4; kemudian mengeluarkan elemen hingga queue kosong. Perbedaannya terletak pada cara mengelola indeks dan ruang array setelah dequeue.

### 1. Queue Linear dengan Pergeseran Elemen

#### Struktur data dan operasi

Pada latihan pertama, `head` dan `tail` dimulai dari `-1`. Setelah elemen dikeluarkan, fungsi `dequeue` menggeser elemen berikutnya ke depan. Dengan demikian, elemen pertama queue selalu berada pada indeks 0 dan `tail` berkurang satu setiap dequeue.

#### Implementasi `dequeue`

```cpp
void dequeue(queue &q) {
    if (isEmptyQueue(q)) {
        cout << "antrian kosong\n";
    } else {
        for (int i = q.head; i < q.tail; i++) {
            q.info[i] = q.info[i + 1];
        }
        q.tail--;
        if (q.tail < 0) {
            q.head = -1;
            q.tail = -1;
        }
    }
}
```

#### Hasil dan penjelasan

```text
-1 - -1 | empty queue
0 - 0   | 5
0 - 1   | 5 2
0 - 2   | 5 2 7
0 - 1   | 2 7
0 - 2   | 2 7 4
0 - 1   | 7 4
0 - 0   | 4
-1 - -1 | empty queue
```

Setelah 5 dikeluarkan, nilai 2 dan 7 bergeser ke depan sehingga nilai 4 dapat ditambahkan di belakangnya. Kode program terdapat pada [`Unguided/Unguided 1/queue.h`](<Unguided/Unguided 1/queue.h>), [`Unguided/Unguided 1/queue.cpp`](<Unguided/Unguided 1/queue.cpp>), dan [`Unguided/Unguided 1/main.cpp`](<Unguided/Unguided 1/main.cpp>).

### 2. Queue Linear dengan Indeks `head` dan `tail`

#### Struktur data dan operasi

Latihan kedua mengeluarkan elemen dengan menaikkan indeks `head`, tanpa langsung menggeser elemen. Karena itu, indeks depan terus berubah selama dequeue. Pada contoh, setelah nilai 5 dikeluarkan, `head` berubah menjadi 1 dan elemen yang tersisa tetap berada pada indeks berikutnya.

#### Implementasi `enqueue`

```cpp
void enqueue(queue &q, int x) {
    if (isFullQueue(q)) {
        cout << "antrian full\n";
    } else {
        if (isEmptyQueue(q)) {
            q.head = 0;
            q.tail = 0;
        } else if (q.tail == maximum - 1) {
            int selisih = q.head;
            for (int i = q.head; i <= q.tail; i++) {
                q.info[i - selisih] = q.info[i];
            }
            q.tail++;
        } else {
            q.tail++;
        }
        q.info[q.tail] = x;
    }
}
```

#### Hasil dan penjelasan

```text
-1 - -1 | empty queue
0 - 0   | 5
0 - 1   | 5 2
0 - 2   | 5 2 7
1 - 2   | 2 7
1 - 3   | 2 7 4
2 - 3   | 7 4
3 - 3   | 4
-1 - -1 | empty queue
```

Kode memiliki cabang pemindahan elemen ketika `tail` sudah berada di ujung array tetapi `head` tidak lagi 0. Cabang tersebut belum diuji oleh urutan operasi di atas dan implementasinya perlu diperbaiki sebelum digunakan pada kondisi itu: indeks `head` tidak direset dan `tail` justru dinaikkan setelah pemindahan, sehingga dapat mengakses indeks di luar kapasitas array. Berkas latihan tersedia pada [`Unguided/Unguided 2/queue.h`](<Unguided/Unguided 2/queue.h>), [`Unguided/Unguided 2/queue.cpp`](<Unguided/Unguided 2/queue.cpp>), dan [`Unguided/Unguided 2/main.cpp`](<Unguided/Unguided 2/main.cpp>).

### 3. Queue Melingkar (*Circular Queue*)

#### Struktur data dan operasi

Latihan ketiga menerapkan queue melingkar. Ketika indeks mencapai akhir array, operasi `enqueue` dan `dequeue` mengembalikannya ke awal menggunakan sisa bagi (`% maximum`). Pemeriksaan penuh dilakukan dengan kondisi `(tail + 1) % maximum == head`, sehingga posisi kosong yang tersedia di awal array dapat digunakan kembali.

#### Implementasi operasi melingkar

```cpp
void enqueue(queue &q, int x) {
    if (isFullQueue(q)) {
        cout << "antrian full\n";
    } else if (isEmptyQueue(q)) {
        q.head = q.tail = 0;
        q.info[q.tail] = x;
    } else {
        q.tail = (q.tail + 1) % maximum;
        q.info[q.tail] = x;
    }
}

void dequeue(queue &q) {
    if (isEmptyQueue(q)) {
        cout << "antrian kosong\n";
    } else if (q.head == q.tail) {
        q.head = q.tail = -1;
    } else {
        q.head = (q.head + 1) % maximum;
    }
}
```

#### Hasil dan penjelasan

```text
-1 - -1 |  empty queue
0 - 0   |  5
0 - 1   |  5 2
0 - 2   |  5 2 7
1 - 2   |  2 7
1 - 3   |  2 7 4
2 - 3   |  7 4
3 - 3   |  4
-1 - -1 |  empty queue
```

Pada urutan uji ini, hasil isi queue tampak sama dengan latihan kedua, tetapi pengelolaan indeksnya berbeda. Queue melingkar membungkus indeks ke awal array saat mencapai batas, tanpa perlu menggeser elemen. Berkas program terdapat pada [`Unguided/Unguided 3/queue.h`](<Unguided/Unguided 3/queue.h>), [`Unguided/Unguided 3/queue.cpp`](<Unguided/Unguided 3/queue.cpp>), dan [`Unguided/Unguided 3/main.cpp`](<Unguided/Unguided 3/main.cpp>).

## Kesimpulan

Queue adalah struktur data linear dengan prinsip FIFO: elemen dimasukkan dari belakang dan dikeluarkan dari depan. Praktikum ini menerapkan queue menggunakan linked list dan array, serta membandingkan array dengan pergeseran, array linear dengan indeks `head` dan `tail`, dan queue melingkar. Linked list mengelola node secara dinamis, sedangkan queue array memiliki kapasitas tetap. Queue melingkar menggunakan kembali ruang kosong secara efisien dengan memutar indeks. Pengujian juga menunjukkan pentingnya menguji kondisi batas, terutama ketika indeks queue linear telah mencapai ujung array.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4
