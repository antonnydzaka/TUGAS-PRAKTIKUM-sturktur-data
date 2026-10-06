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
    int a,b,c;
    cin >> a >> b >> c;
    cout << "sebelum ditukar: " << a << " " << b << " " << c << endl;  
    tukarbyreference(a, b, c);
    cout << "sesudah ditukar by reference: " << a << " " << b << " " << c << endl;  
    tukarbypointer(&a, &b, &c);
    cout << "sesudah ditukar by pointer: " << a << " " << b << " " << c << endl;    
}