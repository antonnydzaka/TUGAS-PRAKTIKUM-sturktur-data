#ifndef QUEUE_H_INCLUDE 
#define QUEUE_H_INCLUDE 
#include <iostream>

typedef int infotype;
const int maximum = 5;
struct queue
{
    infotype info[maximum];
    int head,tail;
};

void createqueue(queue &q);
bool isEmptyQueue(queue q);
bool isFullQueue(queue q);
void enqueue(queue &q, int x);
void dequeue(queue &q);
void printInfo(queue q);

#endif