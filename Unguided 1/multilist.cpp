#include "multilist.h"



void createList(list_induk &L) {
    first(L) = Nil;
    last(L) = Nil;
}

address_induk alokasi(infotypeinduk x) {
    address_induk P = new elemen_list_induk;
    info(P) = x;
    next(P) = Nil;
    prev(P) = Nil;
    createListAnak(anak(P)); 
    return P;
}

void dealokasi(address_induk P) {
    delete P;
}

void insertFirst(list_induk &L, address_induk P) {
    if (first(L) == Nil) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(list_induk &L, address_induk P) {
    if (first(L) == Nil) {
        insertFirst(L, P);
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(list_induk &L, address_induk &P) {
    if (first(L) == Nil) {
        P = Nil;
    } else if (first(L) == last(L)) {
        P = first(L);
        first(L) = Nil;
        last(L) = Nil;
    } else {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = Nil;
        next(P) = Nil;
    }
}

void deleteLast(list_induk &L, address_induk &P) {
    if (first(L) == Nil) {
        P = Nil;
    } else if (first(L) == last(L)) {
        deleteFirst(L, P);
    } else {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = Nil;
        prev(P) = Nil;
    }
}

 
void deleteP(list_induk &L, infotypeinduk x) {
    address_induk P = findElm(L, x);
    if (P != Nil) {
        
        address_anak anakHapus;
        while (first(anak(P)) != Nil) {
            deleteFirstAnak(anak(P), anakHapus);
            dealokasiAnak(anakHapus);
        }
        
       
        if (P == first(L)) {
            deleteFirst(L, P);
        } else if (P == last(L)) {
            deleteLast(L, P);
        } else {
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = Nil;
            prev(P) = Nil;
        }
        dealokasi(P);
    }
}

address_induk findElm(list_induk L, infotypeinduk x) {
    address_induk P = first(L);
    while (P != Nil) {
        if (info(P) == x) return P;
        P = next(P);
    }
    return Nil;
}

void printInfo(list_induk L) {
    address_induk P = first(L);
    if (P == Nil) {
        cout << "List Kosong" << endl;
    } else {
        while (P != Nil) {
            cout << "[INDUK] : " << info(P) << endl;
            // Akses list anak untuk dicetak
            address_anak Q = first(anak(P));
            if (Q == Nil) {
                cout << "    (Tidak ada anak)" << endl;
            } else {
                while (Q != Nil) {
                    cout << "    -> [ANAK] : " << info(Q) << endl;
                    Q = next(Q);
                }
            }
            P = next(P);
            cout << "------------------------" << endl;
        }
    }
}