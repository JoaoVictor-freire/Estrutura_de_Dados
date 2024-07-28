#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(){
        next = nullptr;
    }
};

class listChain{
    private:
        int size;
        Node head;
    
    public:
        listChain(){
            size == 0;
        }

        ~listChain(){}

        bool empty(){
            if(size == 0) return true;
            else return false;
        }

        int getSise(){
            return size;
        }

        int searchElement(int pos){
            if(empty) return -1;
            if(pos < 1 || pos > size) return -1;

            Node aux = head;
            int cont = 1;
            while(cont < pos){
            }
            
        }

};