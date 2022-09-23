


#ifndef CODIGOS_NODO_H
#define CODIGOS_NODO_H
#include<iostream>
using namespace std;


class Node {
private:
    string usuario;
    string contraseña;
    Node * next;
public:
    Node();
    Node(string usuario, string contraseña);
    Node(string usuario, string contraseña,Node* next);
    string getUsuario();
    string getContraseña();
    void setUsuario(string u);
    void setContraseña(string c);
    Node * getNext();
    void setNext(Node * following);
};


#endif