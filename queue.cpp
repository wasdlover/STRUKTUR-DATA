#include "queue.h"
#include <iostream>
using namespace std;

// Definisi fungsi untuk membuat antrian kosong
void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0; // Set count to 0
}

// Definisi fungsi untuk memeriksa apakah antrian kosong
bool isEmpty(Queue Q) {
    return Q.count == 0; // Kembalian true jika count adalah 0
}

// Definisi fungsi untuk memeriksa apakah antrian penuh
bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalian true jika count mencapai kapasitas maksimum
}

// Definisi fungsi untuk menambahkan elemen ke antrian
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) {
        Q.info[Q.tail] = x; // Tambahkan elemen di posisi tail
        Q.tail = (Q.tail + 1) % MAX_QUEUE; // Update tail secara melingkar
        Q.count++; // Increment count
    } else {
        cout << "Antrean Penuh!" << endl; // Pesan jika antrian penuh
    }
}

// Definisi fungsi untuk menghapus elemen dari antrian
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) {
        int x = Q.info[Q.head]; // Ambil elemen dari posisi head
        Q.head = (Q.head + 1) % MAX_QUEUE; // Update head secara
        Q.count--; // Decrement count
        return x; // Kembalikan elemen yang di-dequeue
    } else {
        cout << "Antrean Kosong!" << endl; // Pesan jika antrian kosong
        return -1; // Kembalikan nilai -1 sebagai indikasi antrian kosong
    }
}

// Definisi prosedur untuk menampilkan isi queue
void printInfo(Queue Q) {
    cout << "Isi Queue: [";
    if(!isEmpty (Q)){
        int i = Q.head; // Mulai dari kepala (head)
        int n = 0; // Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen 
            cout << Q.info[i]; // Cetak info
            i = (i + 1) % MAX_QUEUE; // geser 'i' secara circular
            n++; // Tambah penghitung elemen
    }
 }
    cout << "]" << endl;
}
