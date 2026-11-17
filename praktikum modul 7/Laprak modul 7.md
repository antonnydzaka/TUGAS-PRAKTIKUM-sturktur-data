# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Antonny Dzaka Fadhillah - 109082500038</p>

## Guided

### 1. Implementasi Stack Data Mahasiswa

Program Guided mengimplementasikan stack menggunakan array berkapasitas 10 elemen. Setiap elemen menyimpan NIM dan nama mahasiswa, sedangkan variabel `top` menandai posisi teratas. Operasi yang dicontohkan adalah membuat stack, menambahkan data dengan `push`, mengambil data dengan `pop`, dan menampilkan stack.

#### Struktur data pada `stack.h`

```cpp
struct infotype {
    char nim[20];
    char nama[20];
};

struct stack {
    infotype info[10];
    int top;
};
```

Pada program ini, `creatstack` menginisialisasi `top` dengan 1. `push` menaikkan nilai `top` lalu menyimpan data, sedangkan `pop` mengambil elemen pada posisi `top - 1` dan menurunkan `top`. Karena stack mengikuti prinsip LIFO (*Last In, First Out*), data yang terakhir dimasukkan akan menjadi data pertama yang diambil.

#### Alur program dan hasil

Program mencoba memasukkan tiga data, mengambil satu data, lalu melakukan beberapa operasi `pop`. Hasil eksekusi `Guided/main.exe` adalah:

```text
Stack baru dibuat, top = 1

--- Push 3 data ---

--- Pop 1 data ---
Data yang diambil: 109082500142 - C

--- Pop sampai kosong ---
stack kosonng
```

Terdapat ketidaksesuaian pada implementasi yang memengaruhi hasil demonstrasi. `isEmty` hanya menganggap stack kosong ketika `top == 0`, sementara `creatstack` menetapkan `top = 1`; akibatnya `viewstack` tidak menampilkan isi stack saat stack baru atau masih berisi data. Selain itu, `main.cpp` mengisi nama data kedua ke `data.nim`, bukan ke `data.nama`. Hasil di atas merupakan keluaran program sebagaimana adanya. Berkas program terdapat pada [`Guided/stack.h`](Guided/stack.h), [`Guided/stack.cpp`](Guided/stack.cpp), dan [`Guided/main.cpp`](Guided/main.cpp).

## Unguided

Ketiga latihan Unguided menggunakan stack array bertipe `int` dengan kapasitas 20 elemen. Fungsi `printinfo` menampilkan elemen dari posisi top menuju dasar stack, sedangkan `balikstack` memindahkan elemen ke stack sementara lalu memasukkannya kembali untuk membalik urutan.

### 1. Membalik urutan elemen stack

Latihan pertama melakukan serangkaian operasi push dan pop untuk membentuk isi stack, kemudian menampilkan stack sebelum dan sesudah pemanggilan `balikstack`.

#### Hasil dan penjelasan

```text
[TOP]9 2 4 3
balik stack
[TOP]3 4 2 9
```

Hasil menunjukkan bahwa elemen yang semula berada di top menjadi elemen terbawah setelah urutan stack dibalik.

![Output Unguided 1](<Unguided/Unguided 1/Screenshot 2026-11-18 001800.png>)

Kode program tersedia pada [`Unguided/Unguided 1/stack.h`](<Unguided/Unguided 1/stack.h>), [`Unguided/Unguided 1/stack.cpp`](<Unguided/Unguided 1/stack.cpp>), dan [`Unguided/Unguided 1/main.cpp`](<Unguided/Unguided 1/main.cpp>).

### 2. Menyusun elemen stack secara ascending

Latihan kedua menambahkan fungsi `pushAscending`. Fungsi ini menyisipkan nilai pada posisi yang sesuai agar elemen di dalam stack tersusun menaik dari dasar menuju top.

```cpp
void pushAscending(stack &s, infotype x) {
    int i = s.top;
    while (i > 1 && s.info[i - 1] > x) {
        s.info[i] = s.info[i - 1];
        i--;
    }
    s.info[i] = x;
    s.top++;
}
```

#### Hasil dan penjelasan

Nilai 3, 4, 8, 2, 3, dan 9 dimasukkan menggunakan `pushAscending`. Karena pencetakan dimulai dari top, urutan yang terlihat sebelum pembalikan adalah menurun. Setelah stack dibalik, urutan tampilannya menjadi menaik.

```text
[TOP]9 8 4 3 3 2
balik stack
[TOP]2 3 3 4 8 9
```

![Output Unguided 2](<Unguided/Unguided 2/Screenshot 2026-11-18 001639.png>)

Kode program tersedia pada [`Unguided/Unguided 2/stack.h`](<Unguided/Unguided 2/stack.h>), [`Unguided/Unguided 2/stack.cpp`](<Unguided/Unguided 2/stack.cpp>), dan [`Unguided/Unguided 2/main.cpp`](<Unguided/Unguided 2/main.cpp>).

### 3. Membentuk stack dari input angka

Latihan ketiga membaca karakter dari satu baris input. Fungsi `getInputStream` mengabaikan karakter selain digit, mengubah setiap digit menjadi bilangan bulat, lalu memasukkannya ke stack.

```cpp
void getInputStream(stack &s) {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            infotype x = c - '0';
            push(s, x);
        }
    }
}
```

#### Hasil dan penjelasan

Pada contoh, input `4729601` dibaca satu digit demi satu digit. `printinfo` menampilkan digit dari yang terakhir masuk hingga yang pertama, kemudian `balikstack` membalik urutan tersebut.

```text
4729601
[TOP]1 0 6 9 2 7 4
balik stack
[TOP]4 7 2 9 6 0 1
```

![Output Unguided 3](<Unguided/Unguided 3/Screenshot 2026-11-18 001441.png>)

Kode program tersedia pada [`Unguided/Unguided 3/stack.h`](<Unguided/Unguided 3/stack.h>), [`Unguided/Unguided 3/stack.cpp`](<Unguided/Unguided 3/stack.cpp>), dan [`Unguided/Unguided 3/main.cpp`](<Unguided/Unguided 3/main.cpp>).

## Kesimpulan

Stack merupakan struktur data linear dengan prinsip LIFO. Praktikum ini menerapkan operasi dasar `push` dan `pop`, menampilkan elemen dari top, membalik isi stack, menyisipkan nilai agar tersusun, serta membaca digit dari input. Hasil latihan Unguided memperlihatkan bahwa urutan tampilan bergantung pada posisi top dan dapat diubah dengan memindahkan elemen melalui stack sementara. Pada program Guided, pemeriksaan kondisi kosong dan pengisian data kedua perlu diperhatikan karena ketidaksesuaian tersebut terlihat pada hasil eksekusi.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4
