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
    if((q.tail+1)%maximum==q.head){
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
        }else
        {
            q.tail = (q.tail+1)%maximum;
        }
        q.info[q.tail]=x;
    }
}

void dequeue(queue &q){
    if (isEmptyQueue(q))
    {
        cout << "antrian kosong\n";
    }else{
        if (q.head == q.tail)
        {
            q.head = -1;
            q.tail = -1;
        }else{
            q.head = (q.head + 1)%maximum;
        }
    }
}

void printInfo(queue q){
    if (isEmptyQueue(q))
    {
        cout <<q.head << " - " << q.tail << " |  ";
        cout << "empty queue\n";
    }else{
        cout <<q.head << " - " << q.tail << "   |  ";
        int i = q.head;
        while (true)
        {
            cout << q.info[i] << " ";
            if (i == q.tail)
            {
                cout << "\n";
                break;
            }
            
            i = (i+1)%maximum;   
        }
        
    }
    
}
