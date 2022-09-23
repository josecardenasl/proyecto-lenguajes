#include "Nodo.h"

Node::Node() {
    this -> usuario = "";
    this -> next = nullptr;
    this->contraseña = "";
}
Node::Node(string usuario, string contraseña) {
    this -> usuario = usuario;
    this->contraseña = contraseña;
    this -> next = nullptr;
}
Node::Node(string usuario, string contraseña,Node * next) {
    this -> usuario = usuario;
    this->contraseña = contraseña;
    this -> next = next;
}
string Node::getUsuario() {
    return this -> usuario;
}

string Node::getContraseña() {
    return this -> contraseña;
}

void Node::setUsuario(string u) {
    this -> usuario = u;
}

void Node::setContraseña(string c) {
     this -> contraseña = c;
}

Node * Node::getNext() {
    return this -> next;
}
void Node::setNext(Node *following) {
    this -> next = following;
}