// grafo.cpp
#include "grafo.h"
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>

using namespace std;

Grafo::Grafo(int n) {
    numVertices = n;
    matrizAdjacencia.resize(n, vector<int>(n, 0));
    listaAdjacencia.resize(n);
}

void Grafo::readInput(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    int numVertices;
    arquivo >> numVertices;  // Lê o número de vértices

    // Redimensiona a estrutura de acordo com o número de vértices
    this->numVertices = numVertices;
    matrizAdjacencia.resize(numVertices, vector<int>(numVertices, 0));
    listaAdjacencia.resize(numVertices);

    // Lê a matriz de adjacência
    for (int i = 0; i < numVertices; ++i) {

        for (int j = 0; j < numVertices; ++j) {

            int valor;
            arquivo >> valor;  // Lê o valor da matriz de adjacência

            if (valor != 0) {
                matrizAdjacencia[i][j] = valor;
                listaAdjacencia[i].push_back(j);
            }
            
        }
    }

    arquivo.close();
    cout << "Grafo carregado a partir do arquivo " << nomeArquivo << " com sucesso!" << endl;
}


void Grafo::imprimirMatrizAdjacencia() {
    cout << "Matriz de Adjacencia:\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << matrizAdjacencia[i][j] << " ";
        }
        cout << "\n";
    }
}

void Grafo::imprimirListaAdjacencia() {
    cout << "Lista de Adjacencia:\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertice " << i << ": ";
        for (int adj : listaAdjacencia[i]) {
            cout << adj << " ";
        }
        cout << "\n";
    }
}

void Grafo::BFS(int s, int t) {
    vector<bool> visitado(numVertices, false);
    vector<int> anterior(numVertices, -1);
    queue<int> fila;

    visitado[s] = true;
    fila.push(s);

    while (!fila.empty()) {
        int verticeAtual = fila.front();
        fila.pop();

        if (verticeAtual == t) {
            cout << "Caminho encontrado entre " << s << " e " << t << ": ";
            imprimirCaminho(anterior, s, t);
            return;
        }

        for (int adj : listaAdjacencia[verticeAtual]) {
            if (!visitado[adj]) {
                visitado[adj] = true;
                anterior[adj] = verticeAtual;
                fila.push(adj);
            }
        }
    }

    cout << "Nao ha caminho entre " << s << " e " << t << "\n";
}

void Grafo::imprimirCaminho(vector<int>& anterior, int s, int t) {
    vector<int> caminho;
    for (int v = t; v != -1; v = anterior[v]) {
        caminho.push_back(v);
    }
    reverse(caminho.begin(), caminho.end());
    
    for (int i = 0; i < caminho.size(); ++i) {
        if (i != 0) cout << " -> ";
        cout << caminho[i];
    }
    cout << "\n";
}

void Grafo::DFS(int s) {
    vector<bool> visitado(numVertices, false);
    stack<int> pilha;

    pilha.push(s);

    while (!pilha.empty()) {
        int verticeAtual = pilha.top();
        pilha.pop();

        if (!visitado[verticeAtual]) {
            cout << verticeAtual << " ";
            visitado[verticeAtual] = true;
        }

        for (int adj : listaAdjacencia[verticeAtual]) {
            if (!visitado[adj]) {
                pilha.push(adj);
            }
        }
    }
    cout << "\n";
}
