#ifndef STACK_H_INCLUDE 
#define STACK_H_INCULDE 
using namespace std;

struct infotype 
{
    char nim[20];
    char nama[20];
};

struct stack{
    infotype info[10];
    int top;
};

int isEmty(stack s);
void creatstack(stack &s);
void push(stack &s, infotype x);
void pop(stack &s, infotype &x);
void viewstack(stack s);

#endif 