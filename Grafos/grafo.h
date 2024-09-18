// grafo.h
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>
#include <string>

using namespace std;

class Grafo {
private:
    int numVertices;
    vector<vector<int>> matrizAdjacencia;
    vector<list<int>> listaAdjacencia;

public:
    Grafo(int n);  // Construtor

    void imprimirMatrizAdjacencia();  // Imprimir matriz de adjacência
    void imprimirListaAdjacencia();   // Imprimir lista de adjacência
    void BFS(int s, int t);           // Busca em largura (BFS)
    void DFS(int s);                  // Busca em profundidade (DFS) com pilha

    void readInput(const string& nomeArquivo);

private:
    void imprimirCaminho(std::vector<int>& anterior, int s, int t); // Função auxiliar para imprimir o caminho no BFS
};

#endif // GRAFO_H
