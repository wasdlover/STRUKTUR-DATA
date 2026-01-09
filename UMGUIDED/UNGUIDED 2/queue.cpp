#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = nil;
    Q.tail = nil;
    Q.count = 0;
}

bool isEmptyQueue(Queue Q) {
    return Q.count == 0;
}

bool isFullQueue(Queue Q) {
    return Q.tail == max;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (Q.count == 0) {
            Q.head++; Q.tail++;
            Q.info[Q.head] = x;
            Q.count++;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
            Q.count++;
        }
    }
}

infotype dequeue(Queue &Q) {
    if (Q.count == 0) {
        cout << "Queue Kosong!" << endl;
        return -999;
    } else {
        infotype x = Q.info[Q.head];
        Q.info[Q.head] = 0;
        Q.count--; Q.head++;
        if (isEmptyQueue(Q)) {Q.head = nil; Q.tail = nil;}
        return x;
    }
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.head << " -- " << Q.tail << "\t | empty queue" << endl;
    } else {
        int i = Q.head;
        cout << Q.head << " -- " << Q.tail << "\t | ";
        while (i <= Q.tail) {
            cout << Q.info[i] << " ";
            i++;
        }
        cout << endl;
    }
}
