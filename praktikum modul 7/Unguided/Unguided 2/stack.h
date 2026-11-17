#ifndef STACK_H_INCLUDE 
#define STACK_H_INCLUDE 
typedef int infotype;
struct stack
{
    int info[20];
    int top;
};

void createstack(stack &s);
void push(stack &s, infotype x);
infotype pop(stack &s);
void printinfo(stack s);
void balikstack(stack &s);
void pushAscending(stack &s, infotype x);
#endif