#include "stack.h"
#include <iostream>
using namespace std;

void createstack(stack &s){
    s.top = 1;
}

void push(stack &s,infotype x){
    if (s.top < 20)
    {
        s.top += 1;
        s.info[s.top-1]= x;
    }else{
        cout << "stack penuh \n";
    }
}

infotype pop(stack &s){
    if (s.top == 1){
        cout << "stack kosong \n";
        return 0;
    }else{
        s.top -= 1;
        return s.info[s.top];
    }
}

void printinfo(stack s){
    cout << "[TOP]";
    for (int i = 1 ; i < s.top; i++)
    { 
        cout << s.info[s.top-i] << " ";
    }
    cout << "\n";
}

void balikstack(stack &s){
    stack temp;
    createstack (temp);
    temp = s;
    int x;
    createstack(s);
    while (temp.top > 1)
    {
        x = pop(temp);
        push (s,x);
    }
}

void getInputStream(stack &s){
    char c;
    while (cin.get(c) && c != '\n')
    {
        if (c >= '0' && c <= '9'){
            infotype x = c - '0';
            push(s,x);
        }
    }
}

