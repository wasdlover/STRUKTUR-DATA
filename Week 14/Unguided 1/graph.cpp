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