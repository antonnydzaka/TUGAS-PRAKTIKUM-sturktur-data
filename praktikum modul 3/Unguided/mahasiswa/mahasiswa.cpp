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