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
