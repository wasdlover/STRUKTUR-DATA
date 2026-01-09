#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.TOP = Nil;
}

bool IsEmpty(Stack S) {
    return S.TOP == Nil;
}

bool IsFull(Stack S) {
    return S.TOP == MaxEl - 1;
}

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
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
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

void pushAscending(Stack &S, infotype X) {
    if (IsEmpty(S) || S.info[S.TOP] <= X) {
        Push(S, X);
    } else {
        Stack temp;
        CreateStack(temp);
        while (!IsEmpty(S) && S.info[S.TOP] > X) {
            Push(temp, Pop(S));
        }
        Push(S, X);
        while (!IsEmpty(temp)) {
            Push(S, Pop(temp));
        }
    }
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan serangkaian angka (akhiri dengan Enter): ";
    while (cin.peek() != '\n') {
        ch = cin.get();
        if (isdigit(ch)) {
            Push(S, ch - '0');
        }
    }
}