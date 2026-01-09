#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#define max 10
#define nil -1

typedef int infotype;

struct Queue {
    infotype info[max];
    int head;
    int tail;
    int count;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
