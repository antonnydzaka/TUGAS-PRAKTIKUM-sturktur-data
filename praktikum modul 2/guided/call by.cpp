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
