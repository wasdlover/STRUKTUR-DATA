#include "multilist.h"



void createListAnak(list_anak &L) {
    first(L) = Nil;
    last(L) = Nil;
}

address_anak alokasiAnak(infotypeanak x) {
    address_anak P = new elemen_list_anak;
    info(P) = x;
    next(P) = Nil;
    prev(P) = Nil;
    return P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

void insertFirstAnak(list_anak &L, address_anak P) {
    if (first(L) == Nil) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastAnak(list_anak &L, address_anak P) {
    if (first(L) == Nil) {
        insertFirstAnak(L, P);
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirstAnak(list_anak &L, address_anak &P) {
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

void deleteLastAnak(list_anak &L, address_anak &P) {
    if (first(L) == Nil) {
        P = Nil;
    } else if (first(L) == last(L)) {
        deleteFirstAnak(L, P);
    } else {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = Nil;
        prev(P) = Nil;
    }
}

void deletePAnak(list_anak &L, infotypeanak x) {
    address_anak P = first(L);
    while (P != Nil && info(P) != x) {
        P = next(P);
    }

    if (P != Nil) {
        address_anak hapus;
        if (P == first(L)) {
            deleteFirstAnak(L, hapus);
        } else if (P == last(L)) {
            deleteLastAnak(L, hapus);
        } else {
            hapus = P;
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = Nil;
            prev(P) = Nil;
        }
        dealokasiAnak(hapus);
    }
}