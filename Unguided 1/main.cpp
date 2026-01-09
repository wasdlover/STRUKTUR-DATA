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