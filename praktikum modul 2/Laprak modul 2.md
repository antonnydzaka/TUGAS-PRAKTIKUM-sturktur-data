# <h1 align="center">Laporan Praktikum Modul 2 - PENGENALAN BAHASA C++ (BAGIAN KEDUA) </h1>
<p align="center">Antonny Dzaka Fadhillah - 10982500038</p>

## Guided 

### 1. array 1

```C++
#include <iostream>>
using namespace std;

int main() {
    int nila[5];
    nila[0] = 80;
    nila[1] = 75;
    nila[2] = 90;
    nila[3] = 85;
    nila[4] = 95;   

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << ": " << nila[i] << " = " << nila[i] << endl;
    }
    return 0;
}
```
Program di atas mendemonstrasikan penggunaan array satu dimensi bertipe integer dengan ukuran 5 elemen. Nilai setiap elemen diinisialisasi berdasarkan indeksnya (0 hingga 4), kemudian ditampilkan satu per satu ke layar menggunakan perulangan `for`.

### 2. array 2

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80,75,90},
        {85,90,85},
        {70,85,78}
    };   

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl;
    return 0;
}
```
Program di atas mendemonstrasikan penggunaan array dua dimensi (matriks) berukuran 3x3. Seluruh elemen matriks ditampilkan menggunakan perulangan bersarang (*nested loop*), lalu program mengakses dan mencetak satu elemen tertentu pada baris indeks 1 dan kolom indeks 2 (`nilai[1][2]`).

### 3. array 3

```C++
#include <iostream>
using namespace std;

int main(){
    int data[2][2][3]={
        {
            {10,20,30},
            {40,50,60}
        },
        {
            {70,80,90},
            {100,110,120}
        }
    };

    cout << data[0][1][2]<< endl;
    return 0;
}
```
Program di atas mendemonstrasikan penggunaan array tiga dimensi berukuran 2x2x3. Program menginisialisasi elemen data ke dalam struktur multi-dimensi dan kemudian mengakses serta mencetak nilai elemen pada koordinat indeks `[0][1][2]`.

### 4. alamat 

```C++
#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    cout << "nilai angka:"<< angka << endl;
    cout << "alamat angka:" << &angka << endl;
    return 0;
}
```
Program di atas menunjukkan cara mengakses nilai variabel beserta alamat memorinya di RAM. Simbol ampersand (`&`) digunakan sebagai operator *address-of* untuk menampilkan alamat memori tempat variabel `angka` dialokasikan.

### 5. function

```C++
#include <iostream>
using namespace std;

int maks(int a, int b, int c){
    int temp_max = a;
    if (b > temp_max)
        temp_max = b;
    if (c > temp_max)
        temp_max = c;
    return temp_max;
}

int main(){
    int x,y,z;
    cout << "masukan nilai 1:";
    cin >> x;
    cout << "masukan nilai 2:";
    cin >> y;
    cout << "masukan nilai 3:";
    cin >> z;
    cout << "nilai terbesar adalah:" << maks(x,y,z) << endl;
    return 0; 
}
```
Program di atas mendemonstrasikan penggunaan fungsi (*function*) bernama `maks` yang menerima tiga parameter input dan mengembalikan nilai terbesar di antara ketiganya (*return value*). Nilai input dimasukkan oleh pengguna melalui `cin` dan hasil terbesarnya dicetak di fungsi `main`.

### 6. pointer 

```C++
#include <iostream>
using namespace std;

int main(){
    char arr[6];

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'd';
    arr[4] = 'e';
    arr[5] = 'f';

    cout << arr[3] << endl;
    cout << &(arr[3]) << endl;

    return 0;
}
```
Program di atas mengimplementasikan array bertipe `char` berukuran 6 elemen. Program menampilkan karakter pada indeks ke-3 (`arr[3]`) dan menampilkan representasi alamat memorinya menggunakan operator `&`.

### 7. callby

```C++
#include <iostream>
using namespace std;

void tukarbypointer(int *x, int *y) {
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

void tukarbyvalue(int x, int y) {
    int temp;
    
    temp = x;
    x = y;
    y = temp;
}

void tukarbyreference (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout<< "nilai akhir pada fungsi tukar \n";
    cout << " x = "<<x<<" y="<<y<<endl;
}
int main() {
    int a = 4;
    int b = 6;
    
    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    tukarbyvalue(a, b);
    
    cout << "Setelah ditukar:" << endl;
    cout << "a = " << a <<  endl;
    cout << "b = " << b << endl;
    
    int a = 4;
    int b = 6;
    
    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    tukarbypointer(&a, &b);
    
    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
    
    int a, b;
    a=4;  b=6;
    cout << "kondisi sebelum ditukar \n";
    cout << " a = "<<a<<" b = "<<b<<endl;
    tukarbyreference(a,b);
    cout<<"kondisi setelah ditukar \n";
    cout << " a = "<<a<<" b = "<<b<<endl;
    return 0;
}
```
Program di atas menunjukkan konsep *parameter passing* pada C++, yaitu *call by value* (mengirim salinan nilai sehingga variabel asli tidak berubah), *call by pointer* (mengirim alamat memori menggunakan pointer), dan *call by reference* (menggunakan alias variabel asli sehingga perubahan di fungsi memengaruhi variabel asli).

### 8. procedure

```C++
#include <iostream>
using namespace std;

void sapa(){
    cout << "selamat datang"<< endl;
}

int main(){
    sapa();
    return 0;
}
```
Program di atas mendemonstrasikan pembuatan dan pemanggilan prosedur menggunakan fungsi bertipe `void` bernama `sapa()`. Prosedur ini tidak mengembalikan nilai (*return value*), melainkan langsung menjalankan aksi untuk mencetak teks sapaan ke layar saat dipanggil.

## Unguided 

### 1.Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3  

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][3][3];
    cout << "masukan inputan matrix 3X3\n";
    for (int k = 0; k < 2; k++)
    {
        cout << "==========================="<< "\n";
        cout << "masukan inputan matriks ke "<< k + 1 << "\n";
        cout << "==========================="<< "\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "==========================="<< "\n";
            cout << "masukan inputan baris ke "<< i + 1 <<"\n";
            cout << "==========================="<< "\n";
            for (int j = 0; j < 3; j++)
            {
                cout << "masukan inputan kolom ke "<< j + 1 << ":";
                cin >> data[k][i][j];
            }
        
        }
    }

    int hasil [3][3];

    cout << "penjumlahan\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = data[0][i][j] + data[1][i][j];
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    cout << "pengurangan\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = data[0][i][j] - data[1][i][j];
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    cout << "perkalian\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = data[0][i][j] * data[1][i][j];
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-sturktur-data/blob/main/praktikum%20modul%202/Unguided/Unguided%201/Screenshot%202026-10-06%20211134.png

##### Output 2
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-sturktur-data/blob/main/praktikum%20modul%202/Unguided/Unguided%201/Screenshot%202026-10-06%20211525.png

penjelasan unguided 1 :
Program menggunakan array 3 dimensi untuk menginputkan elemen dua matriks 3x3, lalu menghitung serta menampilkan hasil operasi penjumlahan, pengurangan, dan perkalian elemen-elemen matriks tersebut.

### 2.Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel  

```C++
#include <iostream>
using namespace std;

void tukarbyreference (int &a, int &b, int &c) {
    int temp;
    temp = a;
    a = b;
    b = c;
    c = temp;
}

void tukarbypointer(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << "sebelum ditukar: " << a << " " << b << " " << c << endl;  
    tukarbyreference(a, b, c);
    cout << "sesudah ditukar by reference: " << a << " " << b << " " << c << endl;  
    tukarbypointer(&a, &b, &c);
    cout << "sesudah ditukar by pointer: " << a << " " << b << " " << c << endl;    
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1] (https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-sturktur-data/blob/main/praktikum%20modul%202/Unguided/Unguided%202/Screenshot%202026-10-06%20213832.png)

##### Output 2
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-sturktur-data/blob/main/praktikum%20modul%202/Unguided/Unguided%202/Screenshot%202026-10-06%20213852.png

penjelasan unguided 2 :
Program menukar nilai dari tiga variabel secara berputar menggunakan fungsi `tukarbyreference` dengan parameter reference (`&`) serta fungsi `tukarbypointer` dengan parameter pointer (`*`) dengan bantuan variabel penampung `temp`.

### 3.Diketahui sebuah array 1 dimensi sebagai berikut :  arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : --- Menu Program Array ---  
• Tampilkan isi array  
• cari nilai maksimum 
• cari nilai minimum  
• Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int cariMinimum(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

void hitungRataRata(int arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    double rata = total / n;
    cout << "Nilai rata-rata dari array: " << rata << endl;
}

void tampilkanArray(int arr[], int n) {
    cout << "Isi array arrA: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilih;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tampilkanArray(arrA, n);
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            case 5:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan pilih menu 1 sampai 5." << endl;
                break;
        }
    } while (pilih != 5);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
https://github.com/antonnydzaka/TUGAS-PRAKTIKUM-sturktur-data/blob/main/praktikum%20modul%202/Unguided/Unguided%203/Screenshot%202026-10-06%20221511.png

penjelasan unguided 3 :
Program mengolah data array 1 dimensi dengan fungsi `cariMaksimum()` untuk mencari nilai terbesar, fungsi `cariMinimum()` untuk mencari nilai terkecil, dan prosedur `hitungRataRata()` untuk menghitung rata-rata nilai, yang seluruhnya dijalankan melalui menu interaktif `switch-case`.

## Kesimpulan
Berdasarkan praktikum Modul 2, dapat disimpulkan bahwa:
1. **Array**: Digunakan untuk menyimpan sekumpulan data homogen berurutan dalam memori, baik dalam dimensi 1, dimensi 2 (matriks), maupun 3 dimensi.
2. **Pointer dan Reference**: Pointer menyimpan alamat memori variabel lain dan diakses dengan operator `*`, sedangkan reference (`&`) bertindak sebagai alias langsung dari variabel asli.
3. **Parameter Passing**: *Call by value* menyalin nilai variabel tanpa mengubah nilai aslinya, sedangkan *call by reference* dan *call by pointer* dapat memanipulasi nilai variabel asli secara langsung pada memori.
4. **Fungsi dan Prosedur**: Fungsi mengembalikan nilai balik (*return value*), sedangkan prosedur bertipe `void` mengeksekusi instruksi tanpa nilai balik. Penggunaannya bersama struktur kontrol `switch-case` membuat kode lebih modular dan terstruktur.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
