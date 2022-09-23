#include <iostream>
#include <string>
#include "Lista.h"
using namespace std;

struct OptionException : public exception {
    const char * what() const noexcept override {
        return "Opcion no valida en el menu, intente de nuevo con valores entre 1 y 7";
    }
};

void menu(){
    cout << "Menu Lista enlazada de usuarios con sus respectivas contraseñas: \n1.Crear Lista \n2.Insertar Elemento al Inicio \n3.Eliminar Elemento por Valor \n4.Buscar Elemento por usuario \n5.Buscar Elemento por contraseña \n6.Imprimir Lista \n7.Salir" << endl;
}

int main() {
    Lista list = Lista();
    int option;

    while(true){
        menu();
        try {
            cin >> option;
            if (cin.fail()){
                throw ios_base::failure("Input no valido");
            }
            if(option == 7){
                break;
            }else if(option < 0 || option > 8){
                throw OptionException();
            }
        }catch (OptionException & e){
            cin.clear();
            cin.ignore();
            cout << e.what() << endl;
            continue;
        }catch (ios_base::failure & e){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Error: Debe Ingresar un Numero Entero Menor de 8 Digitos" << endl;
            continue;
        }
        while (true){
            try {
                int data;
                string a;
                string b;
                switch (option) {
                    case 1:
                        cout << "Ingrese un Numero Entero: ";
                        cin >> data;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        list.createLinkedList(a,b);
                        cout << "Lista Creada Exitosamente" << endl;
                        break;
                    case 2:
                        cout << "Ingrese Valor a Agregar: ";
                        cin >> a, b;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        list.insertAtTheTop(a,b);
                        cout << "Elemento Insertado Exitosamente" << endl;
                        break;
                    
                    
                    case 3:
                        if (list.getHead() == nullptr) {
                            throw out_of_range("Lista Vacia, No Hay Elementos para Eliminar");
                        }
                        cout << "Ingrese el Valor a Eliminar: ";
                        cin >> a, b;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        list.deleteValue(list.getHead(), a, b);
                        cout << "Elemento Eliminado Exitosamente" << endl;

                        break;
                    
                    case 4:
                        if (list.getHead() == nullptr) {
                            throw out_of_range("Lista Vacia, No Hay Elementos para Buscar");
                        }
                        cout << "Ingrese el usuario a Buscar: ";
                        cin >> a;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        if (list.searchUsuario(a)) {
                            cout << "Elemento Encontrado" << endl;
                        } else {
                            cout << "Elemento No Encontrado" << endl;
                        }

                        break;

                    case 5:
                        if (list.getHead() == nullptr) {
                            throw out_of_range("Lista Vacia, No Hay Elementos para Buscar");
                        }
                        cout << "Ingrese contraseña a Buscar: ";
                        cin >> b;

                        if (cin.fail()) {
                            throw ios_base::failure("Input no Valido");
                        }

                        if (list.searchUsuario(b)) {
                            cout << "Elemento Encontrado" << endl;
                        } else {
                            cout << "Elemento No Encontrado" << endl;
                        }

                        break;

                    
                    
                    
                    
                    default:
                        list.printList(list.getHead());
                        break;
                }
            }catch (ios_base::failure & e){
                cin.clear();
                cin.ignore();
                cout << "Error: Debe Ingresar un Numero Entero Menor de 8 Digitos" << endl;
                continue;
            }catch (out_of_range & e){
                cout << e.what() << endl;
            }
            break;
        }

    }
    return 0;
}