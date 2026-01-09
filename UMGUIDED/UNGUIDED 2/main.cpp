#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q); printInfo(Q);

    enqueue(Q,4); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    
    enqueue(Q,10); printInfo(Q);
    enqueue(Q,3); printInfo(Q);
    enqueue(Q,13); printInfo(Q);
    return 0;
}
