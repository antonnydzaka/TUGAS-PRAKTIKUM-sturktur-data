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