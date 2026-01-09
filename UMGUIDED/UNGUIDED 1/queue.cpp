#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1; 
    Q.tail = -1; 
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

int dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
        return -1;
    } else {
        int x = Q.info[Q.head]; 
        
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--; 
        
        if (Q.tail == -1) {
            Q.head = -1;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    
    if (Q.head >= 0) {
        cout << " ";
    }
    cout << Q.head << " -- ";

   
    if (Q.tail >= 0) {
        cout << " ";
    }
    cout << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << (i == Q.tail ? "" : " ");
        }
        cout << endl;
    }
}
