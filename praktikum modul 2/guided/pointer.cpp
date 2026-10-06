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