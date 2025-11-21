# Template Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- *Nama*: Ariel Ahnaf Kusuma
- *NIM*: 103112400050
- *Kelas*: IF-12-05

## 2. Motivasi Belajar Struktur Data
untuk lebih dapat memepelajari lebih dalam tentang bahasa c++ ini dan juga untuk lebih paham nantinya

## 3. Dasar Teori
### Pengertian Queue
Queue adalah struktur data linier yang menerapkan prinsip operasi dimana elemen data yang masuk pertama akan keluar lebih dulu. Prinsip ini dikenal dengan istilah FIFO (First In, First Out).

Berbeda dengan struktur data stack yang menyimpan data secara bertumpuk dimana hanya terdapat satu ujung yang terbuka untuk melakukan operasi data, struktur data queue justru disusun secara horizontal dan terbuka di kedua ujungnya. Ujung pertama (head) digunakan untuk menghapus data sedangkan ujung lainnya (tail) digunakan untuk menyisipkan data.

### Jenis-jenis Struktur Data Queue
*Circular Queue*
Jenis data circular queue merupakan simpul terakhir yang terhubung ke simpul yang pertama. Jenis data queue satu ini juga dikenal dengan Ring Buffer sebab seluruh ujungnya akan terhubung dengan bagian ujung yang lainnya. Penyisipan terjadi pada akhir antrian serta penghapusan di depan antrian.

*Simple Queue*
Simple queue merupakan struktur data yang sangat dasar karena penyisipan item dilakukan pada simpul belakang, yaitu tail atau rear dan penghapusannya terjadi pada simpul depan atau front maupun head.

*Double-ender Queue*
Di double-ender queue, operasi penghapusan dan penyisipan bisa terjadi pada ujung depan dan belakang queue`

### Operasi Struktur Data Queue
*Dequeue* Dequeue dipakai untuk menghapus elemen yang pertama pada queue. 
*Enqueue* Enqueue dipakai untuk menambahkan elemen baru ke queue. 
*IsEmpty* IsEmpty merupakan operasi yang dipakai untuk memeriksa apakah queue kosong maupun tidak. Apabila queue tidak mempunyai elemen, artinya queue kosong dan operasi tersebut bisa mengembalikan nilai benar atau True. 

## 4. Guided
### 4.1 Guided 1
#### queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

#### queue.cpp
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

#### main.cpp
#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    printInfo(Q); // Tampilkan antrian kosong

    cout << "\n Enqueue 3 Elemen" << endl;
    enqueue(Q,5);
    printInfo(Q);
    enqueue(Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 Elemen" << endl;
    enqueue(Q,4);
    printInfo(Q);

    cout << "\n Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;
    printInfo(Q);
    return 0;
}



#### Output:
 ![guided](<Screenshot 2025-11-20 234214.png>)

 #### Penjelasan
 Progranm ini mengimplementasikan Circular Queue dimana variabel yang digunakan adalah count untuk melacak jumlah elemen secara tepat.


## 5. Unguided
### 5.1 Unguided 1
#### queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5 
typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif 

#### queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1; 
    Q.tail = -1; 
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

int dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
        return -1;
    } else {
        int x = Q.info[Q.head]; 
        
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--; // Mundurkan tail
        
        if (Q.tail == -1) {
            Q.head = -1;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    
    if (Q.head >= 0) {
        cout << " ";
    }
    cout << Q.head << " -- ";

   
    if (Q.tail >= 0) {
        cout << " ";
    }
    cout << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << (i == Q.tail ? "" : " ");
        }
        cout << endl;
    }
}

#### main.cpp
#include <iostream>
#include "queue.h" 

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------------------" << endl;
    cout << " H --  T | Queue Info" << endl; 
    cout << "-----------------------------------" << endl;
    
    printInfo(Q); 

    enqueue(Q, 5); printInfo(Q); 
    enqueue(Q, 2); printInfo(Q); 
    enqueue(Q, 7); printInfo(Q); 
    
    
    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 
    
    enqueue(Q, 4); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 

    return 0; 
}

#### Output:
![unguided1](<Screenshot 2025-11-20 231855.png>)

#### Penjelasan
Program ini lambat dikarenakan semua elemen digeser oleh dequeue, dengan CreateQueue diubah menjadi -1 maka outputnya akan sesuai


### 5.2 Unguided 2
#### queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#define max 10
#define nil -1

typedef int infotype;

struct Queue {
    infotype info[max];
    int head;
    int tail;
    int count;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

#### queue.cpp
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = nil;
    Q.tail = nil;
    Q.count = 0;
}

bool isEmptyQueue(Queue Q) {
    return Q.count == 0;
}

bool isFullQueue(Queue Q) {
    return Q.tail == max;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (Q.count == 0) {
            Q.head++; Q.tail++;
            Q.info[Q.head] = x;
            Q.count++;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
            Q.count++;
        }
    }
}

infotype dequeue(Queue &Q) {
    if (Q.count == 0) {
        cout << "Queue Kosong!" << endl;
        return -999;
    } else {
        infotype x = Q.info[Q.head];
        Q.info[Q.head] = 0;
        Q.count--; Q.head++;
        if (isEmptyQueue(Q)) {Q.head = nil; Q.tail = nil;}
        return x;
    }
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.head << " -- " << Q.tail << "\t | empty queue" << endl;
    } else {
        int i = Q.head;
        cout << Q.head << " -- " << Q.tail << "\t | ";
        while (i <= Q.tail) {
            cout << Q.info[i] << " ";
            i++;
        }
        cout << endl;
    }
}

#### main.cpp
#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q); printInfo(Q);

    enqueue(Q,4); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    
    enqueue(Q,10); printInfo(Q);
    enqueue(Q,3); printInfo(Q);
    enqueue(Q,13); printInfo(Q);
    return 0;
}

#### Output:
![unguided2](<Screenshot 2025-11-20 233228.png>)

#### Penjelasan
Program ini mengimplementasi linear queue dengan head and tail bergerak penambahan pada program ini sama seperti nomor satu

### 5.3 Unguided 3
#### queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5 
typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
    int count; 
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

#### queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0; 
}

bool isEmptyQueue(Queue Q) {
    return Q.count == 0; 
}

bool isFullQueue(Queue Q) {
    return Q.count == MAX_QUEUE; 
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; 
    } else {
        cout << "Antrean Penuh!" << endl;
    }
}

int dequeue(Queue &Q) {
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE; 
        Q.count--; 
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

void printInfo(Queue Q) {
    
    if (Q.head >= 0) {
        cout << " ";
    }
    cout << Q.head << " -- ";
    
    
    if (Q.tail >= 0) {
        cout << " ";
    }
    cout << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        int n = 0;
        while (n < Q.count) { 
            cout << Q.info[i];
            i = (i + 1) % MAX_QUEUE;
            n++;
            if (n < Q.count) cout << " "; 
        }
        cout << endl;
    }
}

#### main.cpp
#include <iostream>
#include "queue.h" 
#include "queue.cpp"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------------------" << endl;
    cout << " H --  T | Queue Info" << endl; 
    cout << "-----------------------------------" << endl;
    
    printInfo(Q); 

    enqueue(Q, 5); printInfo(Q); 
    enqueue(Q, 2); printInfo(Q); 
    enqueue(Q, 7); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    enqueue(Q, 4); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 

    return 0; 
}

#### Output:
![unguided3](<Screenshot 2025-11-20 234120.png>)

#### Penjelasan
Program unguided 3 ini mengimplemntasi Circular Queue dengan menggunakan variabel count, sama seperti pada soal guided karena ini adalah cara paling cepat

## 6. Kesimpulan
Dalam Praktikum ini kami memepelajari tentang dasar dasar queue dan juga cara pemngimplementasiannya, di dalam praktikum ini kami mempelajari 2 jalur queue, head dan tail dimana head itu keluar dan tail adalah masuk

## 7. Referensi
1. https://course-net.com/blog/struktur-data-queue-pengertian-jenis-contoh-struktur-data-queue-dalam-mengolah-data/
2. https://www.trivusi.web.id/2022/07/struktur-data-queue.html
3. Modul Praktikum Week 8
