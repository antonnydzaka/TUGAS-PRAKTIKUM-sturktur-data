#include "stack.h"
#include <iostream>
using namespace std;

int main() { 
    cout << "Hello world!" << endl; 
    stack S; 
    createstack(S); 
    getInputStream(S); 
    printinfo(S); 
    cout<<"balik stack"<<endl; 
    balikstack(S); 
    printinfo(S); 
    return 0; 
} 