#include "stack.h" // mengimport header file stack.h

using namespace std;

// fungsi untuk membuat stack baru dengan inisialisasi TOP = Nil
void CreateStack(Stack &S) {
    S.TOP = Nil; // inisiasi TOP dengan Nil (biasanya -1) untuk menandakan stack kosong
}

// fungsi untuk mengecek apakah stack kosong
bool IsEmpty(Stack S) {
    return S.TOP == Nil; // stack kosong jika TOP sama dengan Nil
}

// fungsi untuk mengecek apakah stack penuh
bool IsFull(Stack S) {
    return S.TOP == MaxEl - 1; // stack penuh jika TOP mencapai indeks maksimal
}

// Fungsi untuk menambahkan elemen ke stack (Push)
void Push(Stack &S, infotype X) {
    if (!IsFull(S)) { // cek apakah stack tidak penuh
        S.TOP++; // naikkan TOP
        S.info[S.TOP] = X; // tambahkan elemen baru di posisi TOP
    } else {
        cout << "Stack is full. Cannot push " << X << endl; // pesan error jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (Pop)
infotype Pop(Stack &S) {
    infotype X = -999; // variabel untuk menyimpan elemen yang di-pop
    if (!IsEmpty(S)) { // cek apakah stack tidak kosong
        X = S.info[S.TOP]; // ambil elemen di posisi TOP
        S.TOP--; // turunkan TOP
    }else {
        cout << "Stack Kosong. Gabisa pop." << endl; // pesan error jika stack kosong
    }
        return X; // kembalikan elemen yang di-pop
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl; // pesan jika stack kosong
    } else {
        cout << "[TOP] "; // Tampilkan penanda TOP
        for (int i = S.TOP; i >= 0; i--) { // iterasi dari TOP ke bawah
            cout << S.info[i] << " "; // tampilkan elemen
        }
        cout << endl;
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!IsEmpty(S)) { // Cek apakah stack tidak kosong
        Stack temp1, temp2; // deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2); // inisialisasi kedua stack temporary

        while (!IsEmpty(S)) { // Pindahkan semua elemen dari S ke temp1 (urutan terbalik)
            Push(temp1, Pop(S));
        }

        while (!IsEmpty(temp1)) { // Pindahkan semua elemen dari temp1 ke temp2 (urutan terbalik lagi)
            Push(temp2, Pop(temp1));
        }

        while (!IsEmpty(temp2)) { // Pindahkan semua elemen dari temp2 kembali ke S (urutan sudah benar)
            Push(S, Pop(temp2));
        }

    }
}