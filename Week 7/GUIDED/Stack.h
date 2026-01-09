#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl]; // Array untuk menyimpan elemen stack
    int TOP;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype X); // Menambahkan elemen ke stack
infotype Pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S); 
void balikStack(Stack &S); // Membalik urutan elemen dalam stack

#endif