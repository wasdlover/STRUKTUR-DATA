#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void insertFirst(List &L, address P) {
    P->next = L.first; 
    P->prev = Nil; 
    if (L.first != Nil) L.first->prev = P; 
    else L.last = P; 
    L.first = P; 
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil; 
    if (L.last != Nil) L.last->next = P; 
    else L.first = P; 
    L.last = P; 
}

void insertAfter(List &L, address P, address R) {
    P->next = R->next; 
    P->prev = R; 
    if (R->next != Nil) R->next->prev = P; 
    else L.last = P; 
    R->next = P; 
}

address alokasi(infotype x) {
    address P = new elmlist; 
    P->info = x; 
    P->next = Nil; 
    P->prev = Nil; 
    return P;
}

void printInfo(List L) {
    address P = L.first; 
    while (P != Nil) { 
        cout << P->info << " "; 
        P = P->next; 
    }
    cout << endl;
}



void insertBefore(List &L, address P, address R) {
    if (R == L.first) {
        insertFirst(L, P);
    } 
    else {
        P->next = R;
        P->prev = R->prev;
        R->prev->next = P; 
        R->prev = P;       
    }
}

void printReverse(List L) {
    address P = L.last; 
    while (P != Nil) { 
        cout << P->info << " "; 
        P = P->prev; 
    }
    cout << endl;
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;
    address P1 = alokasi(1);
    address P3 = alokasi(3);
    address P2 = alokasi(2);
    insertFirst(L, P1);
    insertLast(L, P3); 
    insertLast(L, P2);
    cout << "TASK 1: INSERT OPERATIONS" << endl;
    cout << "List awal:" << endl;
    cout << "Forward: ";
    printInfo(L);
    cout << "Backward: ";
    printReverse(L); 
    address P4 = alokasi(4);
    insertBefore(L, P4, P2);
    cout << "Berhasil insert 4 sebelum 2" << endl;
    address P5 = alokasi(5);
    insertBefore(L, P5, P1); 
    cout << "Berhasil insert 5 sebelum 1" << endl;
    cout << "List setelah insertBefore:" << endl;
    cout << "Forward: ";
    printInfo(L);
    cout << "Backward: ";
    printReverse(L);
    return 0;
}