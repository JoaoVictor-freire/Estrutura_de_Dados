#include <iostream>
#include <vector>
#include <string>

using namespace std;

class listaSeq {

    private:
        int maxsize;
        int size;
        int* data;

    public:
        listaSeq(){
            maxsize = 50;
            size = 0;
            data = new int[maxsize];
        }

        ~listaSeq(){
            delete[] data;
        }

        bool empty(){
            if(size == 0) return true;
            else return false;
        }

        bool full(){
            if(size == maxsize) return true;
            else return false;
        }

        int getSize(){
            return size;
        }

        int searchElement(int pos){
            if(pos > size || pos <= 0){
                return -1;
            }

            return data[pos -1];
        }

        int searchPosition(int dt){
            for(int i = 0; i < size; i++){
                if (data[i] == dt) return (i +1);
            }
            return -1;
        }

        bool insert(int pos, int dt){
            if(full() || pos > size +1 || pos <= 0) return false;

            for(int i = size; i >= pos; i--){
                data[i] = data[i-1];
            }

            data[pos -1] = dt;
            size++;
            return true;
        }

        int remove(int pos){
            int dt;

            if(pos > size || pos < 1) return -1;

            dt = data[pos -1];
            for(int i = pos -1; i < size -1; i++){
                data[i] = data[i +1];
            }

            size--;
            return dt;
        }

};

int main() {
    listaSeq lista;

    // Testando se a lista está vazia
    cout << "A lista esta vazia? " << (lista.empty() ? "Sim" : "Nao") << endl;

    // Inserindo elementos na lista

    cout << "Inserindo elementos." << endl;
    lista.insert(1, 10);
    lista.insert(2, 20);
    lista.insert(3, 30);
    lista.insert(2, 15);

    // Exibindo o tamanho da lista
    cout << "Tamanho da lista: " << lista.getSize() << endl;

    // Exibindo os elementos da lista
    cout << "Elementos da lista: ";
    for (int i = 1; i <= lista.getSize(); i++) {
        cout << lista.searchElement(i) << " ";
    }
    cout << endl;

    // Procurando por um elemento
    int pos = lista.searchPosition(20);
    if (pos != -1) {
        cout << "Elemento 20 encontrado na posicao: " << pos << endl;
    } else {
        cout << "Elemento 20 não encontrado" << endl;
    }

    // Removendo um elemento da lista
    int removedElement = lista.remove(2);
    if (removedElement != -1) {
        cout << "Elemento removido: " << removedElement << endl;
    } else {
        cout << "Falha ao remover o elemento" << endl;
    }

    // Exibindo os elementos da lista após remoção
    cout << "Elementos da lista apos remocao: ";
    for (int i = 1; i <= lista.getSize(); i++) {
        cout << lista.searchElement(i) << " ";
    }
    cout << endl;

    // Testando se a lista está cheia
    cout << "A lista esta cheia? " << (lista.full() ? "Sim" : "Nao") << endl;

    return 0;
}