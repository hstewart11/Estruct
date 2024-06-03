
#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;

struct nodo {
     int value;
    nodo *izq;
    nodo *der;
    char nom[30];
    float precio;
    char dest[30];
    char mat[10];
    int dia;
    int mes;
    int anio;
    int cap;
    string iuv;
    int altura;
};
struct nodo *raiz, *aux;

int crearNodo() {
    aux = ((struct nodo *) malloc (sizeof(struct nodo)));
    cout << "Precio del viaje: " << endl;
    cin >> aux->precio;
    cout << "Destino del viaje: " << endl;
    cin >> aux->dest;
    cout << "Matricula de embarcacion: " << endl;
    cin >> aux->mat;
    cout << "Nombre de embarcacion: " << endl;
    cin >> aux->nom;
    cout << "Año del viaje: " << endl;
    cin >> aux->anio;
    cout << "Mes del viaje: " << endl;
    cin >> aux->mes;
    cout << "Dia del viaje: " << endl;
    cin >> aux->dia;
    cout << "Capacidad de la embarcacion: " << endl;
    cin >> aux->cap;
    char pdigito = aux->mat[0];
    char sdigito = aux->mat[1];
    // aux->iuv += pdigito << sdigito << aux->anio << aux->mes << aux->dia;
    aux->iuv = "";
    aux->iuv += pdigito;
    aux->iuv += sdigito;
    aux->iuv += to_string(aux->anio);
    aux->iuv += (aux->mes < 10 ? "0" : "") + to_string(aux->mes);//Nos aseguramos que siempre tenga dos digitos el mes y el dia
    aux->iuv += (aux->dia < 10 ? "0" : "") + to_string(aux->dia);   
    cout << "Identificador unico de viaje es: " <<aux->iuv ;
    

    aux->izq = NULL;
    aux->der = NULL;
    aux->altura = 1;    
}




int obtenerAltura(struct nodo *n) {
    if (n == NULL) {
        return 0;
    }
    return n->altura;
}

int mayor(int a, int b) {
    return (a > b) ? a : b;
}

struct nodo* rotarDerecha(struct nodo *y) {
    struct nodo *x = y->izq;
    struct nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;

    return x;
}

struct nodo* rotarIzquierda(struct nodo *x) {
    struct nodo *y = x->der;
    struct nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;

    return y;
}

int obtenerBalance(struct nodo *n) {
    if (n == NULL) {
        return 0;
    }
    return obtenerAltura(n->izq) - obtenerAltura(n->der);
}

void preOrden(struct nodo *nodo) {
    if (nodo != NULL) {
        preOrden(nodo->izq);
        cout<<nodo->value<<" ";
        preOrden(nodo->der);
    }
}

struct nodo* insertar(struct nodo* nodo) {
    if (nodo == NULL) {
        return aux;
    }

    if (aux->iuv < nodo->iuv) {
        nodo->izq = insertar(nodo->izq);
    } else if (aux->iuv > nodo->iuv) {
        nodo->der = insertar(nodo->der);
    } else {
        return nodo;
    }

    nodo->altura = 1 + mayor(obtenerAltura(nodo->izq), obtenerAltura(nodo->der));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && aux->iuv < nodo->izq->iuv) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && aux->iuv > nodo->der->iuv) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && aux->iuv > nodo->izq->iuv) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && aux->iuv < nodo->der->iuv) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

int main() {
    raiz = NULL;
    int opc = 0;
    do {
        cout << "\tMenu de opciones" << endl;
        cout << "1. Registrar un nuevo viaje." << endl;
        cout << "2. Buscar un viaje por identificador." << endl;
        cout << "3. Listar todos los viajes." << endl;
        cout << "4. Eliminar un viaje por identificador" << endl;
        cout << "5. Registrar un pasajero por viaje" << endl;
        cout << "6. Listar todos los pasajeros de un viaje." << endl;
        cout << "7. Salir" << endl;
        cin >> opc;

        switch (opc) {
            case 1: {
                crearNodo();
                raiz = insertar(raiz);
                break;
            }
            case 3:
                cout << "PreOrden: ";
                preOrden(raiz);
                cout << endl;
                break;
            default:
                break;
        }
    } while (opc != 7);

    return 0;
}
