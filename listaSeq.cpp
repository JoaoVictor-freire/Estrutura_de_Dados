#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAX 100

class filaSeq{
    private:
        int inicio;
        int fim;
        int *dados;
        int numElement;
    
    public:
        filaSeq(){
            inicio = 0;
            fim = -1;
            numElement = 0;
            dados = new int[MAX];
        }

        bool empty(){
            if(numElement == 0)
                return true;
            else
                return false;
        }

        bool full(){
            if(numElement == MAX)
                return true;
            else
                return false;
        }

        int getSize(){
            return numElement;
        }

        int getPrimeiro(){
            if(empty()) return -1;
            return dados[inicio];
        }

        bool insertElement(int val){
            if(full()) return false;

            fim = (fim + 1) % MAX;
            dados[fim] = val;

            numElement++;
            return true;
        }

        int removeElement(){
            if(empty()) return -1;

            int aux = getPrimeiro();
            inicio = (inicio + 1) % MAX;
            
            numElement--;
            return aux;
        }
};

int main() {
    filaSeq fila;

    // Inserindo valores na fila
    cout << "Inserindo valores na fila:" << endl;
    for (int i = 1; i <= 10; ++i) {
        if (fila.insertElement(i)) {
            cout << "Valor " << i << " inserido na fila." << endl;
        } else {
            cout << "Fila cheia, nao foi possivel inserir " << i << "." << endl;
        }
    }

    // Consultando o inicio da fila
    cout << "O primeiro elemento da fila e: " << fila.getPrimeiro() << endl;

    // Removendo valores da fila
    cout << "Removendo valores da fila:" << endl;
    for (int i = 1; i <= 5; ++i) {
        int removido = fila.removeElement();
        if (removido != -1) {
            cout << "Valor " << removido << " removido da fila." << endl;
        } else {
            cout << "Fila vazia, nao foi possivel remover." << endl;
        }
    }

    // Consultando o inicio da fila novamente
    cout << "O primeiro elemento da fila agora e: " << fila.getPrimeiro() << endl;

    // Indicando se a fila esta vazia
    cout << "A fila esta vazia? " << (fila.empty() ? "Sim" : "Nao") << endl;

    // Indicando se a fila esta cheia
    cout << "A fila esta cheia? " << (fila.full() ? "Sim" : "Nao") << endl;

    // Estado final da fila
    cout << "Numero de elementos na fila: " << fila.getSize() << endl;

    return 0;
}