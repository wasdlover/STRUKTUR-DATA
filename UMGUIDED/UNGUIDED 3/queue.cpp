#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0; 
}

bool isEmptyQueue(Queue Q) {
    return Q.count == 0; 
}

bool isFullQueue(Queue Q) {
    return Q.count == MAX_QUEUE; 
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; 
    } else {
        cout << "Antrean Penuh!" << endl;
    }
}

int dequeue(Queue &Q) {
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE; 
        Q.count--; 
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
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
        int i = Q.head;
        int n = 0;
        while (n < Q.count) { 
            cout << Q.info[i];
            i = (i + 1) % MAX_QUEUE;
            n++;
            if (n < Q.count) cout << " "; 
        }
        cout << endl;
    }
}
