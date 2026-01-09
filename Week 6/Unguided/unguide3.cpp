#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct dimasList *address;

struct dimasList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

address alokasi(infotype x) {
    address P = new dimasList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &x){
    delete x;
    x = Nil;
}

bool isEmpty(List L) {
    return (L.first == Nil);
}

address cariElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info != x) {
        P = P->next;
    }
    return P;
}

/* ---------- Operasi insert ---------- */
void insertFirst(List &L, infotype D) {
    address P = alokasi(D);
    if (isEmpty(L)) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(List &L, infotype D) {
    address P = alokasi(D);
    if (isEmpty(L)) {
        L.first = L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter(List &L, infotype D, address target) {
    if (target == Nil) {
        cout << "Data tidak ditemukan";
        return;
    }
    if (target == L.last) {
        insertLast(L, D);   
        return;
    }
    address P = alokasi(D);
    P->next = target->next;
    P->prev = target;
    target->next->prev = P;
    target->next = P;
}

void insertBefore(List &L, infotype D, address target) {
    if (target == Nil) {
        cout << "Data tidak ditemukan";
        return;
    } else if (target == L.first) {
        insertFirst(L, D);
        return;
    }
    address P = alokasi(D);
    P->prev = target->prev;
    P->next = target;
    target->prev->next = P;
    target->prev = P;
}


/* ---------- Cetak ---------- */
void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " "; 
        P = P->next;
    }
    cout << endl;
}

void printReverse(List L) {
    address P = L.last;
    cout << "Backward: ";
    while (P != Nil) {
        cout << P->info << " "; 
        P = P->prev;
    }
    cout << endl;
}

/* ---------- SMART INSERT (≥4 kondisi + edge cases + pesan) ---------- */
void smartInsert(List &L, infotype x){
    cout << "Smart Insert: ";
    if (isEmpty(L)) {
        cout << "list kosong, insert " << x << " di first";
        insertFirst(L, x);
    } else if (x < L.first->info) {
        cout << x <<" < first, insert di first";
        insertFirst(L, x);
    } else if (x % 2 == 0) {
        cout << x << " genap, insert di last";
        insertLast(L, x);
    } else {
        address ada = cariElm(L, x);
        if (ada != Nil) {
            cout << " sudah ada, insert setelah " << x;
            insertAfter(L, x, ada);
        } else {
            address P = L.first;
            address target = Nil;
            while (P != Nil && P->info <= x) {
                P = P->next;
            }
            target = P;
            if (target == Nil) {
                cout << x << " lebih besar dari semua, insert di last";
                insertLast(L, x);
            } else {
                int left = (target->prev ? target->prev->info : -9999);
                cout << x << " di antara " << left << " dan " << target->info;
                insertBefore(L, x, target);
            }
        }
    }
    cout << endl;
}

/* ---------- Operasi delete (bantuan) ---------- */
void hapusNode(List &L, address aku) {
    if (aku == Nil) return;
    if (aku == L.first && aku == L.last) {
        L.first = L.last = Nil;
    } else if (aku == L.first) {
        L.first = aku->next;
        if (L.first) L.first->prev = Nil;
    } else if (aku == L.last) {
        L.last = aku->prev;
        if (L.last) L.last->next = Nil;
    } else {
        aku->prev->next = aku->next;
        aku->next->prev = aku->prev;
    }
    dealokasi(aku);
}

/* ---------- DELETION ---------- */
void hapusGanjil(List &L){
    if (isEmpty(L)){
        cout << "Conditional Delete: List kosong, tidak ada yang dihapus\n";
        return;
    }
    int jumlahAngka = 0;
    address P = L.first;
    while (P != Nil) {
        address next = P->next;
        if (P->info%2 != 0) {
            hapusNode(L, P);
            jumlahAngka++;
        }
        P = next;
    } 
    cout << "Contiditional delete: " << jumlahAngka << " elemen ganjil dihapus\n";
}

void hapusByValue(List &L, infotype x) {
    if (L.first == Nil) {
        cout << "Dalam list ini tidak ada data yang tersisa\n";
        return;
    } 
    address P = L.first;
    while (P != Nil && P->info != x) {
        P = P->next;
    }
    if (P == Nil){
        cout << "Nilai " << x << " tidak ditemukan\n";
    } else {
        hapusNode(L, P);
        cout << "Nilai " << x << " berhasil dihapus\n";
    }
}

void hapusSemua(List &L) {
    address P = L.first;
    int jumlahBilangan = 0;
    while (P!=Nil){
        address next = P->next;
        hapusNode(L, P);
        P = next;
        jumlahBilangan++;
    }
    cout << "Semua elemen (" << jumlahBilangan << ") berhasil dihapus";
}

int main () {
    List data;
    infotype value;
    data.first = Nil;
    data.last = Nil;
    cout << "ADVANCE OPERATIONS\n" << "SMART INSERT DEMO\n";
    smartInsert(data, 7);
    smartInsert(data, 3);
    smartInsert(data, 5);
    smartInsert(data, 11);
    smartInsert(data, 32);
    smartInsert(data, 9);
    smartInsert(data, 4);

    cout << "\nHasil smart insert\n" << "Forward: ";
    printInfo(data);
    printReverse(data);

    cout << "\nCONDITIONAL DELETE (ANGKA GANJIL)\n" << "Sebelum conditional delete: ";
    printInfo(data);
    hapusGanjil(data);
    cout << "Setelah conditional delete: ";
    printInfo(data);
    
    cout << "\nDELETE BY VALUE DEMO\n";
    hapusByValue(data, 9);
    hapusByValue(data, 5);
    hapusByValue(data, 4);
    cout << "List akhir: ";
    printInfo(data);

    cout << "\nDELETE ALL DEMO\n";
    hapusSemua(data);
}