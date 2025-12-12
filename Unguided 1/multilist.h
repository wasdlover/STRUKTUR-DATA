#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define anak(P) P->lanak


typedef int infotypeinduk;
typedef int infotypeanak;

typedef struct elemen_list_induk *address_induk;
typedef struct elemen_list_anak *address_anak;


struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct list_anak {
    address_anak first;
    address_anak last;
};


struct elemen_list_induk {
    infotypeinduk info;
    list_anak lanak;
    address_induk next;
    address_induk prev;
};

struct list_induk {
    address_induk first;
    address_induk last;
};


void createList(list_induk &L);
address_induk alokasi(infotypeinduk x);
void dealokasi(address_induk P);
void insertFirst(list_induk &L, address_induk P);
void insertLast(list_induk &L, address_induk P);
void deleteFirst(list_induk &L, address_induk &P);
void deleteLast(list_induk &L, address_induk &P);
void deleteP(list_induk &L, infotypeinduk x);
address_induk findElm(list_induk L, infotypeinduk x);
void printInfo(list_induk L);


void createListAnak(list_anak &L);
address_anak alokasiAnak(infotypeanak x);
void dealokasiAnak(address_anak P);
void insertFirstAnak(list_anak &L, address_anak P);
void insertLastAnak(list_anak &L, address_anak P);
void deleteFirstAnak(list_anak &L, address_anak &P);
void deleteLastAnak(list_anak &L, address_anak &P);
void deletePAnak(list_anak &L, infotypeanak x);

#endif