#ifndef CODIGOS_LISTA_H
#define CODIGOS_LISTA_H

#include "Nodo.h"

class Lista {
private:
    Node * head;
public:

    Lista();

    Node* getHead();
    void createLinkedList(string a, string b);
    void insertAtTheTop(string a, string b);
    Node* deleteValue(Node* current, string a, string b);
    bool searchUsuario(string a);
    bool searchContraseña(string b);
    void printList(Node * current);

};

#endif