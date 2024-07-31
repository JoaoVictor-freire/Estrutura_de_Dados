#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {

private:
    int data;
    Node* next;

public:
    Node(){
        next = NULL;
    }

    int getData(){
        return data;
    }

    Node* getNext(){
        return next;
    }

    void setNext(Node* p){
        next = p;
    }

    void setData(int v){
        data = v;
    }
};



class listChain{
    private:
        int size;
        Node *head;

        bool insertBegin(int v){
            Node *newNode = new Node();

            newNode->setData(v);
            newNode->setNext(head);
            head = newNode;
            size++;
            return true;
        }

        bool insertEnd(int v){
            Node *newNode = new Node;
            newNode->setData(v);

            Node *aux = head;
            while(aux->getNext() != NULL){
                aux = aux->getNext();
            }

            newNode->setNext(NULL);
            aux->setNext(newNode);
            size++;
            return true;
        }

        bool insertMiddle(int pos, int dt){
            int cont = 1;
            Node *newNode = new Node();
            newNode->setData(dt);

            Node *aux = head;
            while(cont < pos-1 && aux!= NULL){
                aux = aux->getNext();
                cont++;
            }
            if(aux == NULL) return false;

            newNode->setNext(aux->getNext());
            aux->setNext(newNode);
            size++;
            return true;
        }

        int rmBeginList(){
            Node *p = head;
            int dt = p->getData();

            head = p->getNext();
            size--;
            delete p;

            return dt;
        }

        int rmElementeList(int pos){
            Node *atual = head, *ant = NULL;
            int dt = -1, cont = 1;
            
            while(cont < pos && atual != NULL){
                ant = atual;
                atual = atual->getNext();
                cont++;
            }
            if(atual == NULL) return -1;

            dt = atual->getData();
            ant->setNext(atual->getNext());
            size--;
            delete atual;

            return dt;
        }
    
    public:
        listChain(){
            this->setSize(0);
            head = nullptr;
        }

        ~listChain(){
            delete head;
        }

        bool empty(){
            if(size == 0) return true;
            else return false;
        }

        int getSize(){
            return size;
        }

        int setSize(int dt){
            size = dt;
        }



        bool insertElement(int pos, int dt){
            if(empty() && pos != 1){
                return false;

            }else if(pos == 1){
                return insertBegin(dt);

            }else if(pos == size +1){
                return insertEnd(dt);

            }else{
                insertMiddle(pos, dt);
            }
        }

        int searchElement(int pos){
            if(empty()) return -1;
            if(pos < 1 || pos > size) return -1;

            Node *aux = head;
            int cont = 1;

            while(cont < pos){
                aux = aux->getNext();
                cont++;
            }
            return aux->getData();
        }

        void printElements(){
            if (empty()) {
                cout << "A lista está vazia." << endl;
            }else{
                Node* aux = head;
                while (aux != nullptr) {
                    cout << aux->getData() << " -> ";
                    aux = aux->getNext();
                }
                cout << "NULL" << endl;
            }

        }

        int remove(int pos){
            if(empty()){
                return -1;
            }else if(pos == 1){
                return rmBeginList();
            }else{
                return rmElementeList(pos);
            }

        }

};

int main() {
    listChain list;

    // Testando a inserção de elementos
    cout << "Inserindo elementos na lista:" << endl;
    list.insertElement(1, 10);
    list.insertElement(2, 20);
    list.insertElement(3, 30);
    list.insertElement(2, 15);
    list.printElements();

    // Testando a busca de elementos
    cout << "Buscando elementos na lista:" << endl;
    cout << "Elemento na posicao 1: " << list.searchElement(1) << endl;
    cout << "Elemento na posicao 2: " << list.searchElement(2) << endl;
    cout << "Elemento na posicao 3: " << list.searchElement(3) << endl;
    cout << "Elemento na posicao 4: " << list.searchElement(4) << endl;
    cout << endl;

    // Testando a remoção de elementos
    cout << "Removendo elemento da posicao 2: " << list.remove(2) << endl;
    list.printElements();
    cout << "Removendo elemento do inicio: " << list.remove(1) << endl;
    list.printElements();
    cout << endl;

    // Testando se a lista está vazia
    cout << "A lista esta vazia? " << (list.empty() ? "Sim" : "Nao") << endl;

    // Testando o tamanho da lista
    cout << "Tamanho da lista: " << list.getSize() << endl;

    return 0;
}