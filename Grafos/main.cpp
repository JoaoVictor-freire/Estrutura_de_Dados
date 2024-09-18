// main.cpp
#include "grafo.h"
#include <iostream>

int main() {
    // Inicialmente, cria o grafo com 0 vértices
    Grafo g(0);

    // Lê o grafo a partir do arquivo
    g.readInput("casos/pcv50.txt");

    // Imprimir as representações para verificar se o grafo foi carregado corretamente
    //g.imprimirMatrizAdjacencia();
    //g.imprimirListaAdjacencia();

    // Testar BFS entre dois vértices
    cout << "BFS entre os parametros:\n";
    g.BFS(1, 44);

    // Testar DFS a partir de um vértice
    cout << "DFS a partir do vertice 0:\n";
    g.DFS(0);

    return 0;
}
