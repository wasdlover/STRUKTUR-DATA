#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) { S.TOP = Nil; }
bool IsEmpty(Stack S) { return S.TOP == Nil; }
bool IsFull(Stack S) { return S.TOP == MaxEl - 1; }

void Push(Stack &S, infotype X) {
    if (!IsFull(S)) {
        S.TOP++;
        S.info[S.TOP] = X;
    }
}

infotype Pop(Stack &S) {
    infotype X = -999;
    if (!IsEmpty(S)) {
        X = S.info[S.TOP];
        S.TOP--;
    }
    return X;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.TOP; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (!IsEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);
        while (!IsEmpty(S)) { Push(temp1, Pop(S)); }
        while (!IsEmpty(temp1)) { Push(temp2, Pop(temp1)); }
        while (!IsEmpty(temp2)) { Push(S, Pop(temp2)); }
    }
}