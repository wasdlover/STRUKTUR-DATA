
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
