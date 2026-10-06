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