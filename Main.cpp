#include "stack.h" // mengimport header file stack.h
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Stack S; // deklarasi stack S bertipe Stack
    CreateStack(S); // inisialisasi stack S menjadi stack kosong

    Push(S, 3); // menambahkan elemen 3 ke stack S
    Push(S, 4); // menambahkan elemen 4 ke stack S
    Push(S, 8); // menambahkan elemen 8 ke stack S
    Pop (S);    // menghapus elemen teratas dari stack S (8)
    Push(S, 2); // menambahkan elemen 2 ke stack S
    Push(S, 3); // menambahkan elemen 3 ke stack S
    Pop (S);    // menghapus elemen teratas dari stack S (3)
    Push(S, 9); // menambahkan elemen 9 ke stack S

    cout << "Stack awal: " << endl;
    printInfo(S); // menampilkan isi stack sebelum dibalik

    cout << " Balik Stack: " << endl;
    balikStack(S); // membalik urutan elemen dalam stack S

    return 0; // mengakhiri program
}
