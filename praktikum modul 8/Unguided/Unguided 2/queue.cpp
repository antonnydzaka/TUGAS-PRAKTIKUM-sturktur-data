#include "queue.h"
#include <iostream>
using namespace std;

void createqueue(queue &q){
    q.head = -1;
    q.tail = -1;
}

bool isEmptyQueue(queue q){
    return (q.head == -1);
}

bool isFullQueue(queue q){
    if(q.tail == maximum - 1 && q.head == 0){
        return true;
    } else {
        return false;
    }
}

void enqueue(queue &q, int x){
    if (isFullQueue(q))
    {
        cout << "antrian full\n";
    }else{
        if (isEmptyQueue(q))
        {
            q.head = 0;
            q.tail = 0;
        }else if (q.tail == maximum -1)
        {
            int selisih = q.head;
            for (int i = q.head; i <= q.tail; i++)
            {
                q.info[i-selisih]= q.info[i];
            }
            q.tail++;
        }else{
            q.tail++;
        }
        q.info[q.tail]=x;
    }
}

void dequeue(queue &q){
    if (isEmptyQueue(q))
    {
        cout << "antrian kosong\n";
    }else{
        q.head++;
        if (q.head > q.tail)
        {
            q.head = -1;
            q.tail = -1;
        }
    }
}

void printInfo(queue q){
    if (isEmptyQueue(q))
    {
        cout << "-1 - -1 | empty queue\n";
        return;
    }

    cout << q.head << " - " << q.tail << "   | ";
    for (int i = q.head; i <= q.tail; i++)
    {
        if (i > q.head)
        {
            cout << " ";
        }
        cout << q.info[i];
    }
    cout << "\n";
}
