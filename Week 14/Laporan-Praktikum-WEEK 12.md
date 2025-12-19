# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Ariel Ahnaf Kusuma
- **NIM**: 103112400050
- **Kelas**: IF-12-05

## 2. Motivasi Belajar Struktur Data
Agar saya dapat lebih memahami tentang struktur data dan juga bahasa pemrograman C++ ini

## 3. Dasar Teori
**Pengertian Graph**
Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan.

Graph banyak dimanfaatkan untuk menyelesaikan masalah dalam kehidupan, dimana masalah tersebut perlu direpresentasikan atau diimajinasikan seperti sebuah jaringan. Contohnya adalah media sosial (seperti Facebook, Instagram, LinkedIn, dkk).
Dalam beberapa masalah, dapat digunakan untuk mencari solusi optimal, seperti dalam algoritma Travelling Salesman yang mencari rute terpendek yang mengunjungi semua titik yang ada.

**Jenis-jenis Graph**
Graph dapat dibedakan berdasarkan arah jelajahnya dan ada tidaknya label bobot pada relasinya.
Berdasarkan arah jelajahnya graph dibagi menjadi Undirected graph dan Directed graph.

- **Undericted Graph**: Undirected graph adalah graph di mana setiap sisi tidak memiliki arah, sehingga hubungan antara dua simpul bersifat timbal balik.

Misalnya, jika ada sisi yang menghubungkan simpul A dan B, maka A terhubung ke B dan B terhubung ke A. Graph jenis ini sering digunakan untuk merepresentasikan hubungan yang bersifat dua arah, seperti pertemanan dalam jejaring sosial. 

- **Directed Graph**: Berbeda dengan undirected graph, directed graph memiliki sisi yang berarah, sehingga hubungan antara dua simpul memiliki arah tertentu.

Jika ada sisi dari simpul A ke B, itu berarti ada hubungan dari A ke B, tetapi tidak sebaliknya, kecuali ada sisi  lain yang mengarah dari B ke A.

Directed graph sering digunakan untuk merepresentasikan hubungan yang memiliki arah, seperti aliran data atau proses dalam sistem.  

## 4. Guided
### 4.1 Guided 1
#### graph.h

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited; 
    adrEdge firstEdge; // untuk mengetahui alamat pertama pertama dari elemen pertama
    adrNode next;
};

struct ElmEdge {
    adrNode node; // pointer yang mengraha ke node
    adrEdge next; // pinter yang mengarah ke next
};

struct Graph {
    adrNode first;
};

// Prototypes
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif


#### graph_init.cpp

#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

#### graph_edge.cpp

#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge; 
        pStart->firstEdge = newEdge;
    }
} 

#### graph_print.cpp

#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

#### main.cpp

#include "graph.h"
#include <iostream>
#include "graph_init.cpp"
#include "graph_edge.cpp"
#include "graph_print.cpp"

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // Menambahkan Node A, B, C, D
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // Menghubungkan Node (Sesuai contoh materi)
    connectNode(G, 'A', 'B'); // A ke B
    connectNode(G, 'A', 'C'); // A ke C
    connectNode(G, 'B', 'D'); // B ke D
    connectNode(G, 'C', 'D'); // C ke D

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}

#### Output Code

![Guided](<Screenshot 2025-12-18 220205.png>)

#### Penjelasan

Program ini berfungsi mencetak semua tetangga dari node yg ada pada graph menggunakan printGraph(G) dimana G adalah list graph. Lalu membuat variabel sementara yg menyimpan node first pada list graph. Disini menggunakan perulangan untuk mencetak node tetangganya dimana membuat variabel sementara yaitu E yang menyimpan firstEdge pada node tadi, lalu perulangan bakal terus berjalan selama E tidak kosong lalu mencetak node yang ditunjuk oleh E, setelah itu E akan berpindah ke edge selanjutnya.

## 5. Unguided
### 5.1 Unguided 1
#### graph.h

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited; 
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif

#### graph.cpp

#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}


adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void insertNode(Graph &G, infoGraph X) {
    if (findNode(G, X) == NULL) { 
        adrNode P = allocateNode(X);
        if (G.first == NULL) {
            G.first = P;
        } else {
            adrNode Q = G.first;
            while (Q->next != NULL) {
                Q = Q->next;
            }
            Q->next = P;
        }
    }
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge edge1 = new ElmEdge;
        edge1->node = pEnd;
        edge1->next = pStart->firstEdge;
        pStart->firstEdge = edge1;

        adrEdge edge2 = new ElmEdge;
        edge2->node = pStart;
        edge2->next = pEnd->firstEdge;
        pEnd->firstEdge = edge2;
    }
}

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << ":";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << " -> " << E->node->info;
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

#### main.cpp

#include "graph.h"
#include "graph.cpp"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');
    
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');

   
    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');

    
    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');

    cout << "=== TAMPILAN GRAPH (Undirected) ===" << endl;
    printGraph(G);

    return 0;
}

#### Output Code

![Unguided 1](<Screenshot 2025-12-18 234102.png>)

#### Penjelasan

Fungsi Program ini hampir sama dengan guided, dan program ini menggunakan Graph tipe undirected, yang di mana hubungan antar node (dari A sampe H) dibangun secara dua arah alias mutual. Di sini core logic-nya ada pada fungsi insertNode yang ngejaga biar nggak ada node kembar yang masuk, dan connectNode yang memastikan tiap koneksi langsung "diikat" bolak-balik biar valid. Meskipun di kode ini belum ada algoritma searching kayak DFS atau BFS, setup-nya udah solid banget untuk nyusun topologi jaringan, yang akhirnya langsung divisualisasiin lewat printGraph untuk ngasih liat siapa aja yang lagi connected satu sama lain.

### 5.2 Unguided 2
#### graph.h

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited; 
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

void resetVisited(Graph &G);
void printDFS(Graph G, adrNode start);

#endif

#### graph.cpp

#include "graph.h"
#include <stack> 

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void insertNode(Graph &G, infoGraph X) {
    if (findNode(G, X) == NULL) {
        adrNode P = allocateNode(X);
        if (G.first == NULL) {
            G.first = P;
        } else {
            adrNode Q = G.first;
            while (Q->next != NULL) {
                Q = Q->next;
            }
            Q->next = P;
        }
    }
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge edge1 = new ElmEdge;
        edge1->node = pEnd;
        edge1->next = pStart->firstEdge;
        pStart->firstEdge = edge1;

        adrEdge edge2 = new ElmEdge;
        edge2->node = pStart;
        edge2->next = pEnd->firstEdge;
        pEnd->firstEdge = edge2;
    }
}

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << ":";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << " -> " << E->node->info;
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}


void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}

void printDFS(Graph G, adrNode start) {
    if (start == NULL) return;
    
    resetVisited(G);
    
    stack<adrNode> S;
    S.push(start);
    
    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrNode curr = S.top();
        S.pop();
        
        if (!curr->visited) {
            curr->visited = true;
            cout << curr->info << " ";
            
            adrEdge E = curr->firstEdge;
            while (E != NULL) {
                if (!E->node->visited) {
                    S.push(E->node);
                }
                E = E->next;
            }
        }
    }
    cout << endl;
}

#### main.cpp

#include "graph.h"
#include <stack>
#include "graph.cpp"

adrNode findNodeMain(Graph G, char x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x) return P;
        P = P->next;
    }
    return NULL;
}

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A'); insertNode(G, 'B'); 
    insertNode(G, 'C'); insertNode(G, 'D');
    insertNode(G, 'E'); insertNode(G, 'F'); 
    insertNode(G, 'G'); insertNode(G, 'H');

    connectNode(G, 'A', 'B'); connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D'); connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F'); connectNode(G, 'C', 'G');
    connectNode(G, 'D', 'H'); connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H'); connectNode(G, 'G', 'H');

    
    printDFS(G, findNodeMain(G, 'A'));

    return 0;
}

#### Output Code

![Unguided 2](<Screenshot 2025-12-19 003152.png>)

#### Penjelasan

Program ini berfungsi buat bangun Graph tipe undirected yang disusun pakai metode Adjacency List, jadi tiap node dari A sampe H bakal saling di-link agar ngebentuk jaringan yang utuh. Main character di kode ini tuh adalah algoritma DFS (Depth First Search) yang manfaatin Stack buat eksplorasi jalur sedalam mungkin alias "gas terus sampai ujung" sebelum dia backtracking, dan udah dilengkapi fitur visited biar tidak mungkin terjebak infinite loop, jadi proses traversal-nya dijamin benar.

### 5.3 Unguided 3
#### graph.h

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

void resetVisited(Graph &G);
void printBFS(Graph G, adrNode start);

#endif

#### graph.cpp


#include "graph.h"
#include <queue> 

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void insertNode(Graph &G, infoGraph X) {
    if (findNode(G, X) == NULL) {
        adrNode P = allocateNode(X);
        if (G.first == NULL) {
            G.first = P;
        } else {
            adrNode Q = G.first;
            while (Q->next != NULL) {
                Q = Q->next;
            }
            Q->next = P;
        }
    }
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge edge1 = new ElmEdge;
        edge1->node = pEnd;
        edge1->next = pStart->firstEdge;
        pStart->firstEdge = edge1;

        adrEdge edge2 = new ElmEdge;
        edge2->node = pStart;
        edge2->next = pEnd->firstEdge;
        pEnd->firstEdge = edge2;
    }
}

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << ":";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << " -> " << E->node->info;
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}

void printBFS(Graph G, adrNode start) {
    if (start == NULL) return;
    
    resetVisited(G);
    
    queue<adrNode> Q;
    Q.push(start);
    start->visited = true;
    
    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";
        
        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (!E->node->visited) {
                E->node->visited = true;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
    cout << endl;
}


#### main.cpp

#include "graph.h"
#include <queue>
#include "graph.cpp"

adrNode findNodeMain(Graph G, char x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x) return P;
        P = P->next;
    }
    return NULL;
}

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A'); insertNode(G, 'B'); 
    insertNode(G, 'C'); insertNode(G, 'D');
    insertNode(G, 'E'); insertNode(G, 'F'); 
    insertNode(G, 'G'); insertNode(G, 'H');

    connectNode(G, 'A', 'B'); connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D'); connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F'); connectNode(G, 'C', 'G');
    connectNode(G, 'D', 'H'); connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H'); connectNode(G, 'G', 'H');


    printBFS(G, findNodeMain(G, 'A'));

    return 0;
}

#### Output Code

![Unguided 3](<Screenshot 2025-12-19 004054.png>)

#### Penjelasan

Program ini mwnggunakan Graph tipe undirected, di mana node dari A sampe H bakal saling connect membentuk jaringan yang solid. Spotlight utamanya ada pada fungsi printBFS yang manfaatin Queue untuk menjalankan algoritma Breadth First Search (BFS), jadi beda dengan DFS yang "main dalam", BFS ini gayanya "melebar" alias layer-by-layer dia bakal scan semua tetangga terdekat dulu baru lanjut ke layer berikutnya. Logikanya juga udah safe banget karena menggunakan penanda visited yang di-reset dulu sebelum mulai, jadi proses traversal-nya dijamin valid, nggak bakal kejebak infinite loop, dan output-nya urut sesuai antrean yang masuk.

## 6. Kesimpulan
Pada Praktikum ini kita dapat mengetahui Graph dan juga jenis-jenis graph, Undericted dan Dericted Graph.Penggambaran graph menggunakan Multi Linked List lebih efisien karena hemat memori dan fleksibel untuk graph dinamis. Setiap node menyimpan daftar tetangganya melalui linked list edge. 

Lalu kita juga mempelajari dua cara penulusuran grap, yaitu BFS (Breadth-First Search)  dan juga  DFS (Depth-First Search)
dan juga membandingkan perbedaan Undirected dan Directed Graph.x

## 7. Referensi
1. https://www.exabytes.co.id/blog/jenis-struktur-data-graph-dan-penerapannya/
2. https://www.programiz.com/dsa/graph
3. https://fikti.umsu.ac.id/graph-pengertian-fungsi-dan-jenisnya/