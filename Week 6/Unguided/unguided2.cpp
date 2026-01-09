#include <iostream>
using namespace std;
#define Nil NULL

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


address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil) L.first->prev = P;
    else L.last = P;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    L.first = L.first->next;
    if (L.first != Nil) L.first->prev = Nil;
    else L.last = Nil;
    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last;
    L.last = L.last->prev;
    if (L.last != Nil) L.last->next = Nil;
    else L.first = Nil;
    P->prev = Nil;
    P->next = Nil;
}

void deleteAfter(List &L, address &P, address Prec) {
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil) P->next->prev = Prec;
    else L.last = Prec;
    P->prev = Nil;
    P->next = Nil;
}


address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}


void deleteByValue(List &L, infotype x) {
    address target = findElm(L, x);
    if (target == Nil) {
        cout << "Nilai " << x << " tidak ditemukan" << endl;
        return;
    }

    address P;
    if (target == L.first) {
        deleteFirst(L, P);
    } else if (target == L.last) {
        deleteLast(L, P);
    } else {
        deleteAfter(L, P, target->prev);
    }
    dealokasi(P);
    cout << "Nilai " << x << " berhasil dihapus" << endl;
}


void deleteAll(List &L) {
    int count = 0;
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
        count++;
    }
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}


int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(2));

    cout << "TASK 1: DELETE OPERATIONS" << endl; 
    cout << "List awal: ";
    printInfo(L);
    cout << endl;

    deleteByValue(L, 2);
    cout << "Setelah deleteByValue(2): ";
    printInfo(L);
    cout << endl;

    deleteByValue(L, 5);
    cout << "List tetap: ";
    printInfo(L);
    cout << endl;

    deleteAll(L);

    cout << "List setelah tambah data: ";
    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(4));
    insertFirst(L, alokasi(5));
    printInfo(L);
    cout << endl;
    deleteAll(L);

    return 0;
}