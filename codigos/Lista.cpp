#include "Lista.h"
#include "iostream"

using namespace std;

Node* Lista::getHead() {
    return this -> head;
}

Lista::Lista() {
    this -> head = nullptr;
}


void Lista::createLinkedList(string a, string b) {
    Node * newNode = new Node(a, b);
    this -> head = newNode;
}

void Lista::insertAtTheTop(string a, string b) {
    Node * newNode = new Node(a, b,  this -> head);

    this -> head = newNode;
}





void Lista::printList(Node * current) {
    if (current != nullptr) {
        cout << current -> getUsuario() << " -> ";
        this -> printList(current -> getNext());
    }else{
        cout << "NULL" <<endl;
    }
}



Node* Lista::deleteValue(Node* current, string a, string b) {
    if(current == nullptr) {
        return nullptr;
    }else if(current -> getUsuario() == a && current ->getContraseña() == b){
        Node * new_next = current -> getNext();
        delete current;

        return new_next;
    }else{
        current -> setNext(deleteValue(current -> getNext(), a,b));
        return current;
    }
}

bool Lista::searchUsuario(string a) {
    Node * current = this -> head;

    while (current != nullptr) {
        if (current -> getUsuario() == a) {
            return true;
        }
        current = current -> getNext();
    }

    return false;
}

bool Lista::searchContraseña(string b) {
    Node * current = this -> head;

    while (current != nullptr) {
        if (current -> getContraseña() == b) {
            return true;
        }
        current = current -> getNext();
    }

    return false;
}







