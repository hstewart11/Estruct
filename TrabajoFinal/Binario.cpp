#include <iostream>
#include <string>
using namespace std;

struct nodo {
    int value = 0;
    nodo *izq;
    nodo *der;
    char nom[30];
    int precio = 0;
    char dest[30];
    char mat[10];
    int dia = 0;
    int mes = 0;
    int anio = 0;
    int cap = 0;
    string iuv;
    int altura;
};

struct pasajeros {
    char nombre[30];
    char cedula[15];
    string matricula;
    pasajeros *sig;
};

struct nodo *raiz = NULL, *aux = NULL;
struct pasajeros *cab = NULL, *aux1 = NULL, *aux2 = NULL;
char buscador[10];

int crearNodo() {
    aux = new nodo();
    cout << "Precio del viaje: ";
    cin >> aux->precio;
    cout << "Destino del viaje: ";
    cin >> aux->dest;
    cout << "Matricula de embarcacion: ";
    cin >> aux->mat;
    cout << "Nombre de embarcacion: ";
    cin >> aux->nom;
    cout << "Año del viaje: ";
    cin >> aux->anio;
    cout << "Mes del viaje: ";
    cin >> aux->mes;
    cout << "Dia del viaje: ";
    cin >> aux->dia;
    cout << "Capacidad de la embarcacion: ";
    cin >> aux->cap;
    char pdigito = aux->mat[0];
    char sdigito = aux->mat[1];
    aux->iuv = "";
    aux->iuv += pdigito;
    aux->iuv += sdigito;
    aux->iuv += to_string(aux->anio);
    aux->iuv += (aux->mes < 10 ? "0" : "") + to_string(aux->mes);
    aux->iuv += (aux->dia < 10 ? "0" : "") + to_string(aux->dia);

    aux->izq = NULL;
    aux->der = NULL;
    aux->altura = 1;

    return 0;
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

void InOrden(struct nodo *nodo){
//    if (nodo == NULL){
//         return; 
//     }

    if (nodo->izq != NULL){
        InOrden(nodo->izq);
    }
    cout << "Nombre de la embarcacion: " << nodo->nom << endl;
    cout << "Destino del viaje: " << nodo->dest<< endl;
    cout << "Precio del viaje: " << nodo->precio<< endl;
    cout << "Matricula: " << nodo->mat<< endl;
    cout << "Fecha de salida: " << nodo->dia<< "/" << nodo->mes<< "/" << nodo->anio<< endl;
    cout << "Numero de pasajeros: " << nodo->cap<< endl;
    cout << "Identificador: " << nodo->iuv<< endl;

    if (nodo->der != NULL){
        InOrden(nodo->der);
    }
    // return 0;
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

int buscar(){
    if (aux == NULL){
        cout << "No hay embarcaciones en el sistema" << endl;
        return 0;
    }
    if (aux != NULL){
        if (aux->iuv == buscador){
            cout << "Nombre de la embarcacion: " << aux->nom<< endl;
            cout << "Destino del viaje: " << aux->dest<< endl;
            cout << "Precio del viaje: " << aux->precio<< endl;
            cout << "Matricula: " << aux->mat<< endl;
            cout << "Fecha de salida: " << aux->dia<< "/" << aux->mes<< "/" << aux->anio<< endl;
            cout << "Numero de pasajeros: " << aux->cap<< endl;
            cout << "Identificador: " << aux->iuv<< endl;
            cout << "------------------------------------------------" << endl;
        }
        if (aux->iuv != buscador) {
            if (aux->der != NULL){
                aux = aux->der;
                buscar();
            }
            if (aux->izq != NULL){
                aux = aux->izq;
                buscar();
            }
        }
    }
    return 0;
}

int registrar(){
    if (aux == NULL)
    {
        cout << "No hay embarcaciones registradas" << endl;
        return 0;
    }
    if (aux != NULL){
        if (aux->iuv == buscador){
            if (cab == NULL) {
                cab = (struct pasajeros *)malloc(sizeof(struct pasajeros));
                cout << "Ingrese su nombre: ";
                cin >> cab->nombre;
                cout << "Ingrese su cedula: ";
                cin >> cab->cedula;

                cab->matricula = aux->iuv;

                if (aux->cap < aux->value){
                    aux->value = aux->value + 1;
                }
                else if (aux->cap <= aux->value){
                    cout << "Ya no hay cupos disponibles" << endl;
                    registrar();
                }

                cab->sig = NULL;
                return 0;
            }
            if (cab != NULL){
                aux1 = (struct pasajeros *)malloc(sizeof(struct pasajeros));
                cout << "ingrese su nombre: ";
                cin >> aux1->nombre;
                cout << "ingrese su cedula: ";
                cin >> aux1->cedula;

                aux1->matricula = aux->iuv;

                if (aux->cap < aux->value){
                    aux->value = aux->value + 1;
                }
                else if (aux->cap <= aux->value){
                    cout << "No hay capacidad en la embarcacion " << endl;
                    registrar();
                }
                aux1->sig = NULL;
                aux2 = cab;

                while (aux2->sig != NULL){
                    aux2 = aux2->sig;
                }
                aux2->sig = aux1;
                aux1 = NULL;
                aux2 = aux1;

                free(aux1);
                free(aux2);
            }
        }
        if (aux->iuv != buscador){
            if (aux->der != NULL){
                aux = aux->der;
                registrar();
            }
            if (aux->izq != NULL){
                aux = aux->izq;
                registrar();
            }
        }
    }
    return 0;
}

int mostrar(){
    if (aux == NULL){
        cout << "No hay embarcaciones en el sistema" <<endl;
        return 0;
    }
    if (aux != NULL){
        for (aux1 = cab; aux1 != NULL; aux1 = aux1->sig){
            if (aux1->matricula == buscador){
                cout << "Nombre: " << aux1->nombre<<endl;
                cout << "Numero de Cedula: " <<aux1->cedula<<endl;
            }
        }
    }
    return 0;
}

nodo* eliminar(nodo* raiz, string buscador) {
    // Caso base: el árbol está vacío
    if (raiz == NULL) {
        return raiz;
    }

    if (buscador < raiz->iuv) {
        raiz->izq = eliminar(raiz->izq, buscador);
    }
    else if (buscador > raiz->iuv) {
        raiz->der = eliminar(raiz->der, buscador);
    }
    else {
        // Caso 1: El nodo no tiene hijos o tiene un solo hijo
        if (raiz->izq == NULL) {
            nodo* temp = raiz->der;
            free (raiz);
            return temp;
        }
        else if (raiz->der == NULL) {
            nodo* temp = raiz->izq;
            free (raiz);
            return temp;
        }
        // Caso 2: El nodo tiene dos hijos
       
        nodo* temp = raiz->der;
        while (temp->izq != NULL) {
            temp = temp->izq;
        }
        raiz->iuv = temp->iuv;
        raiz->der = eliminar(raiz->der, temp->iuv);
    }

    if (raiz == NULL) {
        return raiz;
    }

    raiz->altura = 1 + max(obtenerAltura(raiz->izq), obtenerAltura(raiz->der));

    int balance = obtenerBalance(raiz);

    if (balance > 1 && obtenerBalance(raiz->izq) >= 0) {
        return rotarDerecha(raiz);
    }

    if (balance < -1 && obtenerBalance(raiz->der) <= 0) {
        return rotarIzquierda(raiz);
    }

    if (balance > 1 && obtenerBalance(raiz->izq) < 0) {
        raiz->izq = rotarIzquierda(raiz->izq);
        return rotarDerecha(raiz);
    }

    if (balance < -1 && obtenerBalance(raiz->der) > 0) {
        raiz->der = rotarDerecha(raiz->der);
        return rotarIzquierda(raiz);
    }

    return raiz;
}


int main() {
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
            case 1:
                crearNodo();
                raiz = insertar(raiz);
                break;
            case 2:
                aux = raiz;
                cout << "Ingrese la matricula de la embarcacion: ";
                cin >> buscador;
                buscar();
                break;
            case 3:
                cout << "Embarcaciones registradas: " << endl;
                InOrden(raiz);
                cout << endl;
                break;
            case 4:
                aux = raiz;
                cout << "Ingrese el identificador de la embarcacion: ";
                cin >> buscador;
                eliminar(raiz, buscador);
                break;
            case 5:
                aux = raiz;
                cout << "Ingrese el identificador de la embarcacion: ";
                cin >> buscador;
                registrar();
                break;
            case 6:
                cout << "Ingrese la identificador de la embarcacion: ";
                cin >> buscador;
                cout << "Pasajeros registrados en la embarcacion: " << endl;
                mostrar();
                break;
        }
    } while (opc != 7);

    return 0;
}