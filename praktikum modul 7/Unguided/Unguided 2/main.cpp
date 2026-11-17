#include "stack.h"
#include <iostream>
using namespace std;

int main() { 
    cout << "Hello world!" << endl; 
    stack S; 
    createstack(S); 
    pushAscending(S,3); 
    pushAscending(S,4); 
    pushAscending(S,8); 
    pushAscending(S,2); 
    pushAscending(S,3); 
    pushAscending(S,9); 
    printinfo(S); 
    cout<<"balik stack"<<endl; 
    balikstack(S); 
    printinfo(S); 
    return 0; 
} 