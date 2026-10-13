# <h1 align="center">Modul 3 ABSTRACT DATA TYPE (ADT) </h1>
<p align="center">Antonny Dzaka Fadhillah - 109082500038</p>

## Guided 

### 1. mahasiswa

```C++
// mahasiswa.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m){
    cout << "input nim =";
    cin >> (m).nim;
    cout << "input nilai 1 =";
    cin >> (m).nilai1;
    cout << "input nilai 2=";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m){
    return float(m.nilai1+m.nilai2/2);
}
// mahasiswa.h
#ifndef MAHASISWA_H_INCLUDE 
#define MAHASISWA_H_INCLUDE

struct mahasiswa{
    char nim[10];
    int nilai1,nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif
// main.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata rata " << rata2(mhs) << endl;
    return 0;
}

```
### Penjelasan
`struct mahasiswa` menyimpan NIM dan dua nilai. Fungsi `inputMhs` menerima data tersebut, lalu `rata2` menghitung hasil nilai yang ditampilkan oleh `main`. Agar benar-benar menghitung rata-rata, rumusnya perlu ditulis `(m.nilai1 + m.nilai2) / 2`.

## Unguided 

### 1.Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas. folder mahasiswa

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    char nama[50];
    int nim, uts, uas, tugas;
    float tugasakhir;
};

mahasiswa dataMahasiswa[10];

float nilaiAkhir(mahasiswa *x) {
    x->tugasakhir = 0.3f * x->uts + 0.4f * x->uas + 0.3f * x->tugas;
    return x->tugasakhir;
}

int main() {
    int y;
    cout << "masukan banyaknya mahasiswa: ";
    cin >> y ;
    for (int i = 1; i <= y; i++) {
        cout << "masukan mahasiswa ke"<< i<< "\n";
        cout << "Masukan nama: ";
        cin >> dataMahasiswa[i].nama;
        cout << "Masukan nim: ";
        cin >> dataMahasiswa[i].nim;
        cout << "Masukan uts: ";
        cin >> dataMahasiswa[i].uts;
        cout << "Masukan uas: ";
        cin >> dataMahasiswa[i].uas;
        cout << "Masukan tugas: ";
        cin >> dataMahasiswa[i].tugas;
        dataMahasiswa[i].tugasakhir = nilaiAkhir(&dataMahasiswa[i]);
    }

    for (int i = 1; i <= y; i++)
    {
        cout << "Nilai akhir " << dataMahasiswa[i].nama << ": " << dataMahasiswa[i].tugasakhir << "\n";
    }
    
    return 0;
}
```
### Output Unguided 1 :
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-sturktur-data/blob/main/praktikum%20modul%203/Unguided/mahasiswa/Screenshot%202026-10-14%20033955.png

##### Output 1

penjelasan unguided 1 :
Program menggunakan `struct mahasiswa` dan array `dataMahasiswa` untuk menyimpan data nilai mahasiswa. Fungsi `nilaiAkhir()` dengan parameter pointer digunakan untuk menghitung nilai akhir berdasarkan bobot 30% UTS, 40% UAS, dan 30% tugas, lalu hasilnya ditampilkan ke layar.

### 2.Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h” folder pelajaran

```C++
// pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel)
{
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel)
{
    cout << "nama mapel: " << pel.namaMapel << "\n";
    cout << "nama kode mapel: " << pel.kodeMapel << "\n";
}
// pelajaran.h
#ifndef PELAJARAN_H_INCLUDE
#define PELAJARAN_H_INCLUDE
#include <iostream>
using namespace std;

struct pelajaran
{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran (string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif 
// main.cpp
#include <iostream>
#include "pelajaran.h"

using namespace std; 

int main()
{  string namapel = "Struktur Data";
    string kodepel = "STD"; 
    pelajaran pel = create_pelajaran(namapel,kodepel);  
    tampil_pelajaran(pel);   
    return 0; 
}   
```
### Output Unguided 2 :

##### Output 1

penjelasan unguided 2 :
Program mengimplementasikan ADT mata pelajaran secara modular dengan membagi kode ke dalam tiga file: `pelajaran.h` untuk deklarasi struct dan fungsi, `pelajaran.cpp` untuk implementasi fungsi pembuatan serta penampilan data, dan `main.cpp` sebagai program utama pemanggil ADT.

### 3.Buatlah program dengan ketentuan : - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer - fungsi/prosedur yang menampilkan isi sebuah array integer 2D - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu  fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer folder array

```C++
#include <iostream>
using namespace std;


void tampilkan(int array[2][3][3])
{
    for (int i = 1; i <= 2; i++)
    {
        cout << "matrik ke"<< i<<"\n";
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << array[i-1][j][k] << " ";
            }
            cout << "\n";
        }
    }
}

void ubah(int x1,int y1,int x2, int y2, int array[2][3][3])
{
    int temp = array[0][x1-1][y1-1] ;
    array[0][x1-1][y1-1] = array[1][x2-1][y2-1];
    array[1][x2-1][y2-1] = temp;
}

void ubahmatriks(int array[2][3][3])
{
    int x1,y1;
    int x2,y2;
    cout << "masukan index yang mau di tukar di array 1 baris dan kolom ke :";
    cin >> x1;
    cin >> y1;
    cout << "masukan index yang mau di tukar di array 2 baris dan kolom ke :";
    cin >> x2;
    cin >> y2;
    ubah(x1,y1,x2,y2,array);
}

int main ()
{
    int data[2][3][3] =
    {
        {
            {17,25,37},
            {14,32,23},
            {12,22,36}
        },
        {
            {15,23,35},
            {81,82,37},
            {65,67,13}
        }
    };
    cout << "sebelum \n";
    tampilkan(data);
    ubahmatriks(data);
    cout << "sesudah \n";
    tampilkan(data);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-sturktur-data/blob/main/praktikum%20modul%203/Unguided/array/Screenshot%202026-10-14%20034047.png

penjelasan unguided 3 :
Program menggunakan array 3 dimensi untuk merepresentasikan dua matriks 3x3. Prosedur `tampilkan()` digunakan untuk mencetak isi matriks, sedangkan prosedur `ubah()` dan `ubahmatriks()` menukarkan nilai elemen antarmatriks pada baris dan kolom yang ditentukan pengguna.


## Kesimpulan
Berdasarkan praktikum Modul 3, dapat disimpulkan bahwa:
1. **Abstract Data Type (ADT)**: Mengabstraksikan struktur data dan operasinya agar program lebih terorganisir dan modular.
2. **Struct**: Digunakan di C++ untuk mengelompokkan beragam tipe data menjadi satu kesatuan tipe bentukan.
3. **Modularitas**: Pemisahan file header (`.h`) dan implementasi (`.cpp`) mempermudah pemeliharaan serta penggunaan ulang kode (*reusable*).
4. **Pointer**: Memungkinkan pemrosesan dan manipulasi elemen data pada memori secara langsung dan efisien.



## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
