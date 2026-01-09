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
