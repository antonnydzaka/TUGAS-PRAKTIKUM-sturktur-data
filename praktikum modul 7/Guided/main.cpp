#include <iostream>
#include <string>
#include <cstring>
#include "stack.h"
using namespace std;

int main() {
    stack S;
    infotype data, hasil;

    creatstack (S);
    cout << "Stack baru dibuat, top = " << S.top << endl;
    viewstack(S);

    cout << endl << "--- Push 3 data ---" << endl;
    strcpy(data.nim, "109082500144");
    strcpy(data.nama, "A");
    push(S, data);

    strcpy(data.nim, "109082500141");
    strcpy(data.nim, "B");
    push(S, data);

    strcpy(data.nim, "109082500142");
    strcpy(data.nama, "C");
    push(S, data);
    viewstack(S);

    cout << endl << "--- Pop 1 data ---" << endl;
    pop(S, hasil);
    cout << "Data yang diambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewstack(S);
    cout << endl << "--- Pop sampai kosong ---" << endl;
    pop(S, hasil);
    pop(S, hasil);
    pop(S, hasil);
    viewstack(S);

    return 0;
}