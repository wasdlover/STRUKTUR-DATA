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