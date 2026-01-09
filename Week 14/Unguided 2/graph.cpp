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