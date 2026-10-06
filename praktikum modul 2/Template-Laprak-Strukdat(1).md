# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Antonny Dzaka Fadhillah - 109082500038</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Unguided 

### 1.Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut. 

```C++
#include <iostream>
using namespace std;

main(){
    float a, b;
    cout<<"masukan dua angka:";
    cin>>a >>b;
    cout<<"penjumlahan:"<< a + b<< '\n';
    cout<<"pengurangan:"<< a - b<< '\n';
    cout<<"perkalian:"<< a * b<< '\n';
    cout<<"pembagian:"<< a / b<< '\n';
    return 0;
}

```
### Output Unguided 1 :

##### Output 1
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-1-sturktur-data-/blob/main/Unguided/Unguided%201/Screenshot%202026-09-29%20232932.png

##### Output 2
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-1-sturktur-data-/blob/main/Unguided/Unguided%201/Screenshot%202026-09-29%20233144.png

penjelasan unguided 1 
### variabel a dan b, lalu masukan inputan variable a dan b setelah itu output penjumlahan, pengurangan, perkalian, pembagian

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
#include <string>

using namespace std;

string bilangan (int angka) {
	string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (angka == 100) {
        return "seratus";
    }
    if (angka < 100) {
        int puluhan = angka / 10;
        int sisa = angka % 10;
        string hasil = satuan[puluhan] + " puluh";
        if (sisa != 0) {
            hasil += " " + satuan[sisa];
        }
        return hasil;
    }
    if (angka < 20) {
        return satuan[angka - 10] + " belas";
    }
    if (angka == 11) {
        return "sebelas";
    }
    if (angka == 10) {
        return "sepuluh";
    }
	if (angka < 10) {
		return satuan[angka];
	}

	return "";
}

int main() {
	int angka;
	cout << "Masukkan angka (0-100): ";
	cin >> angka;
	cout << bilangan (angka) << endl;
	return 0;
}
```
### Output Unguided 2 :

##### Output 1
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-1-sturktur-data-/blob/main/Unguided/Unguided%202/Screenshot%202026-09-30%20000603.png

##### Output 2
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-1-sturktur-data-/blob/main/Unguided/Unguided%202/Screenshot%202026-09-30%20000611.png

penjelasan unguided 2
## membuat fungsi bilangan untuk membaca angka inputan lalu di bagian fungsi main melakukan input angka lalu output dengan fungsi bilangan dengan parameter angka 

### 3. Buatlah program yang dapat memberikan input dan output, foto soal ada di modul.

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cin >> angka;
    for (int i = 0; i < angka ; i++) {
        for (int k = 0; k < i; k++) {
            cout << "  ";
        }
        for (int j = angka-i; j > 0; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int j = 1 ; j <= angka-i; j++) {
            cout << j << " ";
        }   
        cout << '\n';
    }
    for (int i = 0; i < angka; i++)
    {
        cout << "  ";
    }
    
    cout << "*";
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-1-sturktur-data-/blob/main/Unguided/Unguided%203/Screenshot%202026-09-30%20004224.png

##### Output 2
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-1-sturktur-data-/blob/main/Unguided/Unguided%203/Screenshot%202026-09-30%20004241.png

penjelasan unguided 3
## masukan inputan angka lalu melakukan perulangan increment sebanyak angka, di dalam perulangan pertama ada 3 perulangan menghasilkan output segitiga kebalik dengan tinggi variable angka 

## Kesimpulan
modul 1 menjelaskan bagaimana membuat program sederhana mengunakan bahasa c++
## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
