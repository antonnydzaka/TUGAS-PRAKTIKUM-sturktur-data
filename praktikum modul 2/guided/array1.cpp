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