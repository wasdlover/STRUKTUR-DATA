# Template Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Ariel Ahnaf Kusuma
- **NIM**: 103112400050
- **Kelas**: IF-12-05

## 2. Motivasi Belajar Struktur Data
Agar dapat menguasai pemrograman dan juga dapat mempelajari ilmu dan hal baru 

## 3. Dasar Teori
Dalam praktikum ini kita memelajari tentang multi linked list.
Apa itu multi linked list?

Multilinked list adalah linked list di mana setiap node dapat berisi pointer ke lebih dari satu node dalam linked list

Circular Linked List adalah struktur data di mana node terakhir menunjuk kembali ke node pertama, membentuk closed circle

- Struktur: Semua node terhubung pada circle, memungkinkan penelusuran terus menerus tanpa menemui hambatan NULL.
- Perbedaan dengan Linked List Biasa: Pada linked list biasa, node terakhir menunjuk ke NULL, sedangkan pada Circular Linked List, node terakhir menunjuk ke node       pertama.


## 4. Guided
### 4.1 Guided 1
**Header Multilist**
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef int infotype;
typedef struct elemen_induk *address_induk;
typedef struct elemen_anak *address_anak;

struct elemen_anak {
    infotype info;
    address_anak next, prev;
};

struct list_anak {
    address_anak first, last;
};

struct elemen_induk {
    infotype info;
    list_anak anak;
    address_induk next, prev;
};

struct list_induk {
    address_induk first, last;
};

void createList(list_induk &L);
address_induk alokasi(infotype x);
void insertLastInduk(list_induk &L, address_induk P);
address_induk findInduk(list_induk L, infotype x);
void insertLastAnak(list_anak &LA, address_anak PA);
address_anak alokasiAnak(infotype x);
void printInfo(list_induk L);

#endif

**Multilist.cpp**
#include "multilist.h"
#include <iostream>
using namespace std;

void createList(list_induk &L) {
    L.first = Nil;
    L.last = Nil;
}

address_induk alokasi(infotype x) {
    address_induk P = new elemen_induk;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    P->anak.first = Nil;
    P->anak.last = Nil;
    return P;
}

void insertLastInduk(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

address_induk findInduk(list_induk L, infotype x) {
    address_induk P = L.first;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}

**multilist_anak**
#include "multilist.h"
#include <iostream>
using namespace std;

address_anak alokasiAnak(infotype x) {
    address_anak P = new elemen_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertLastAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        LA.first = PA;
        LA.last = PA;
    } else {
        LA.last->next = PA;
        PA->prev = LA.last;
        LA.last = PA;
    }
}

void printInfo(list_induk L) {
    address_induk PI = L.first;
    while (PI != Nil) {
        cout << "Induk: " << PI->info << endl;
        address_anak PA = PI->anak.first;
        while (PA != Nil) {
            cout << "  Anak: " << PA->info << endl;
            PA = PA->next;
        }
        PI = PI->next;
    }
}

**Main.cpp**
#include "multilist.h"
#include "multilist.cpp"
#include "multilist_anak.cpp"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    address_induk P1 = alokasi(1);
    insertLastInduk(L, P1);

    address_anak PA1 = alokasiAnak(10);
    insertLastAnak(P1->anak, PA1);

    address_induk P2 = alokasi(2);
    insertLastInduk(L, P2);

    address_anak PA2 = alokasiAnak(20);
    insertLastAnak(P2->anak, PA2);

    printInfo(L);
    return 0;
}

### Output Code
![Guided 1](image.png)

### Penjelasan
Program ini menunjukan bagaimana menghapus, membuat node induk/anak pada list menggunakan fungsi insertAnak yang nantinya kode induk dapat memasukan, membuat dan menghapus nodenya

## 5. Unguided
### 5.1 Unguided 1
**Header Multilinked list**
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

**Multilinkedlist**
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

**Multilist_anak**
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

**Main**
#include "multilist.h"
#include "multilist.cpp"
#include "multilist_anak.cpp"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    address_induk P1 = alokasi(1);
    insertLast(L, P1);

    address_induk P2 = alokasi(2);
    insertLast(L, P2);
    
    address_induk P3 = alokasi(3);
    insertLast(L, P3);
    
    address_induk P4 = alokasi(4);
    insertLast(L, P4);

    insertLastAnak(anak(P1), alokasiAnak(10));
    insertLastAnak(anak(P1), alokasiAnak(11));

    insertLastAnak(anak(P2), alokasiAnak(20));
    insertLastAnak(anak(P2), alokasiAnak(21));
    insertLastAnak(anak(P2), alokasiAnak(22));
    
    insertLastAnak(anak(P4), alokasiAnak(40));

    cout << "KONDISI AWAL" << endl;
    printInfo(L);
    
    cout << "\nDELETE ANAK 21 DARI INDUK 2" << endl;
    address_induk cari = findElm(L, 2); 
    if (cari != Nil) {
        deletePAnak(anak(cari), 21);
    }
    printInfo(L);

    cout << "\nDELETE INDUK 1 (BESERTA ANAKNYA)" << endl;
    deleteP(L, 1);
    printInfo(L);

    return 0;
}

### Output Code
![Unguided1](image-1.png)

### Penjelasan
Program ini kuranglebih sama seperti pada program guided diiatas, hanya saja code unguided ini lebih kompleks pada main.cpp nya. 
multilist.h berfungsi untuk mendefinisikan semua fungsi yang akan digunakan, seperti membuat node dan list lalu memasukan node kedalam list yag sudah sesuai dengan fungsi yg digunakan
multilist.cpp program ini lebih kompleks dan jelas, menggunakan fungsi seperti alokasi dan deleteP
pada multilist_anak.cpp program ini berisi standar list sperti delete,insert,first,last, hanya pada list_anak dan code ini menggunakan fungsi deleteAnaka yang berfungsi untuk mencari nilai anak dalam list anak tertentu lalu menghapusnya dan lalu disambungkan pda pointer next dan prev
main.cpp terakhir pada program ini yaitu berfungsi untuk memanggil semua fungsi pada multilist.h 

### 5.2 Unguided 2
**Header Circularlist**
#ifndef CIRCULAR_H_INCLUDED
#define CIRCULAR_H_INCLUDED
#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef mahasiswa infotype;
typedef struct elemen *address;

struct elemen {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
address findElm(List L, string nim);
void printInfo(List L);

#endif

**Circularlist.cpp**
#include "circular.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new elemen;
    P->info = x;
    P->next = Nil;
    return P;
}

void insertFirst(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        P->next = L.first;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        insertFirst(L, P);
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        if (P->next == L.first) {
            L.first = Nil;
        } else {
            address last = L.first;
            while (last->next != L.first) {
                last = last->next;
            }
            L.first = P->next;
            last->next = L.first;
        }
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        address last = L.first;
        address prec = Nil;
        while (last->next != L.first) {
            prec = last;
            last = last->next;
        }
        P = last;
        if (prec == Nil) {
            L.first = Nil;
        } else {
            prec->next = L.first;
        }
        P->next = Nil;
    }
}

address findElm(List L, string nim) {
    if (L.first == Nil) return Nil;
    address P = L.first;
    do {
        if (P->info.nim == nim) return P;
        P = P->next;
    } while (P != L.first);
    return Nil;
}

void printInfo(List L) {
    if (L.first == Nil) {
        cout << "List Kosong" << endl;
        return;
    }
    address P = L.first;
    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "L/P  : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl;
        cout << endl; 
        P = P->next;
    } while (P != L.first);
}

**Main**

#include "circular.h"
#include "circular.cpp"
#include <iostream>

using namespace std;

int main() {
    List L;
    createList(L);
    
    cout << "coba insert first, last, dan after" << endl;

    infotype m4 = {"Danu", "04", '1', 4.0};
    insertFirst(L, alokasi(m4));

    infotype m1 = {"Ali", "01", '1', 3.3};
    insertFirst(L, alokasi(m1));

    infotype m6 = {"Fahmi", "06", '1', 3.45};
    insertLast(L, alokasi(m6));

    address pAli = findElm(L, "01");
    infotype m2 = {"Bobi", "02", '1', 3.71};
    insertAfter(L, pAli, alokasi(m2));

    address pBobi = findElm(L, "02");
    infotype m3 = {"Cindi", "03", 'p', 3.5};
    insertAfter(L, pBobi, alokasi(m3));

    address pDanu = findElm(L, "04");
    infotype m5 = {"Eli", "05", 'p', 3.4};
    insertAfter(L, pDanu, alokasi(m5));

    infotype m7 = {"Gita", "07", 'p', 3.75};
    insertLast(L, alokasi(m7));

    address pGita = findElm(L, "07");
    infotype m8 = {"Hilmi", "08", '1', 3.3};
    insertAfter(L, pGita, alokasi(m8));

    printInfo(L);

    return 0;
}


### Output Code
![Unguided2](image-2.png)

### Penjelasan
Program ini menggunakan tipe linkedlist circular dimana ujung inked listnya itu menuju ke elemen pertama, jadi pada program ini ada beberapa hal yang berbeda dngan multilinkedlist seperti pada inputnya atau pada delete nodenya

## 6. Kesimpulan
Dalam Praktikum ini para mahasiswa mempelajari tentang linked list tapi yang memiliki banyak cabang atau multi linked list dengan adanya list induk dan anak, ini dapat membuat data lebih rapih jika dibandingkan dengan array 

## 7. Referensi
1. https://stackoverflow.com/questions/22808713/doubly-linked-list-vs-multi-linked-list-in-c-c
2. https://www.geeksforgeeks.org/dsa/circular-linked-list/