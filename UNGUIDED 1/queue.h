#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5 
typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif