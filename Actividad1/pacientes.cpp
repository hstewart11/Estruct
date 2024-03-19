#include <iostream>
using namespace std;

struct nodo {
    int codigo;
    string nombre;
    string cedula;
    string telefono;
    string motivo;
    struct nodo* sig;
};

struct nodo* cab = NULL;
struct nodo* aux = NULL;
struct nodo* aux2 = NULL;

void registrar() {
    aux = new nodo;
    cout << "Ingrese el nombre del paciente: ";
    cin.ignore();
    getline(cin, aux->nombre);
    cout << "Ingrese la cedula: ";
    cin.ignore();
    getline(cin, aux->cedula);
    cout << "Cual es el telefono: ";
    cin >> aux->telefono;
    cout << "Ingrese el motivo de visita: ";
    cin.ignore();
    getline(cin, aux->motivo);
    aux->sig = NULL;
    if (cab == NULL) {
        cab = aux;
        cab->codigo = 1;
    } else {
        aux2 = cab;
        while (aux2->sig != NULL) {
            aux2 = aux2->sig;
        }        
        aux->codigo = aux2->codigo + 1;
        aux2->sig = aux;
    }
}


void mostrar() {
    for (aux = cab; aux != NULL; aux = aux->sig) {
        cout << "REGISTRO DE VISITAS: " << endl << endl;
        cout << "Codigo unico de visita: " << aux->codigo << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "cedula: " << aux->cedula << endl;
        cout << "Telefono: " << aux->telefono << endl;
        cout << "motivo de visita: " << aux->motivo << endl << endl;
        
    }
}

int main() {
    int opc = 0;
    do { 
        cout << "BIENVENIDO AL SISTEMA DE REGISTRO DE PACIENTES"<< endl;
        cout << "Que deseas realizar?"<< endl << endl;
        cout << "1. Registrar paciente" << endl;
        cout << "2. Ver registros unicos de visita" << endl;
        cout << "3. Salir "<<endl<<endl;
        cout << "Ingrese que va ha hacer: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case 1:
                registrar();
                break;
            case 2:
                mostrar();
                break;
        }
    } while (opc != 3);

    aux = cab;
    while (aux != NULL) {
        aux2 = aux;
        aux = aux->sig;
        delete aux2;
    }

    return 0;
}