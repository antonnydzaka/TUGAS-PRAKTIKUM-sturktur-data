#include "stack.h"
#include <iostream>
using namespace std;

int isEmty(stack s){
    if (s.top == 0){
        return 1;
    }else{
        return 0;
    }
}

void creatstack(stack &s){
    s.top = 1;
}

void push(stack &s,infotype x){
    if (s.top < 10)
    {
        s.top += 1;
        s.info[s.top - 1] = x;
    }else{
        cout << "stack penuh \n";
    }  
}

void pop(stack &s, infotype &x){
    if (isEmty(s))
    {
        cout << "stack kosong \n";
    }else{
        x = s.info[s.top -1];
        s.top -= 1;
    }
}

void viewstack(stack s){
    if (isEmty(s))
    {
        cout << "stack kosonng \n";
    }
    
}