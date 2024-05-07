// Harold Stewart Viveros Quiñones
// Santiago Andres Guarnizo Patiño
#include <iostream>
#include <malloc.h>
#include <cstring>
using namespace std;

struct nodo {
    char tipo;
    char placa1[30];
    char placa2[30];
    struct nodo* sig;
};

nodo* cab = NULL;
nodo* aux = NULL;
nodo* aux2 = NULL;

float costoCarro = 1000.0f;
float costoMoto = 500.0f;
float costoVehiculo = 0.0f;

int registrar1() {
    cout << "Ingrese el tipo (c para carro, m para moto): ";
    char tipo;
    cin >> tipo;
    if (tipo != 'c' && tipo != 'm') {
        cout << "Caracter erroneo, vuelva a intentar" << endl;
        return 0;
    }

    cout << "\nIngrese la placa del vehiculo: ";
    char placa[30];
    cin >> placa;

    aux2 = cab;
    while (aux2 != NULL) {
        if ((tipo == 'c' && strncmp(placa, aux2->placa1, 30) == 0) || (tipo == 'm' && strncmp(placa, aux2->placa2, 30) == 0)) {
            cout << "Ya existe un vehiculo con esa placa. Intente nuevamente." << endl;
            return 0;
        }
        aux2 = aux2->sig;
    }

    aux = (struct nodo*)malloc(sizeof(struct nodo));
    aux->tipo = tipo;

    if (tipo == 'c') {
        strncpy(aux->placa1, placa, 30);
        aux->placa2[0] = '\0';
    } else if (tipo == 'm') {
        strncpy(aux->placa2, placa, 30);
        aux->placa1[0] = '\0';
    }

    aux->sig = cab;
    cab = aux;

    return 0;
}

int mostrar1() {
    aux = cab;
    while (aux != NULL) {
        if (aux->tipo == 'c') {
            cout << "Carro : ";
            cout << aux->placa1 << endl;
        }
        aux = aux->sig;
    }
    return 0;
}

int mostrar2() {
    aux = cab;
    while (aux != NULL) {
        if (aux->tipo == 'm') {
            cout << "Moto: ";
            cout << aux->placa2 << endl;
        }
        aux = aux->sig;
    }
    return 0;
}

float calcularCostoIndividual(nodo* vehiculo) {
    float costoIndividual = 0.0f;
    int vehiculosAntes = 0;

    nodo* temp = cab;
    while (temp != vehiculo) {
        if (temp->tipo == vehiculo->tipo) {
            vehiculosAntes++;
        }
        temp = temp->sig;
    }

    costoIndividual = (vehiculo->tipo == 'c') ? costoCarro : costoMoto;
    costoIndividual += (vehiculosAntes * 50);

    return costoIndividual;
}

void eliminar() {
    if (cab != NULL) {
        char placa[30];
        char tipoVehiculo;
        
        cout << "\nIngrese el tipo de vehiculo a eliminar (c para carro, m para moto): ";
        cin >> tipoVehiculo;
        cout << "\nIngrese la placa del vehiculo a eliminar: ";
        cin >> placa;

        aux = cab;
        aux2 = NULL;

        while (aux != NULL) {
            if ((tipoVehiculo == 'c' && strncmp(placa, aux->placa1, 30) == 0) || (tipoVehiculo == 'm' && strncmp(placa, aux->placa2, 30) == 0)) {
                float costoVehiculoActual = calcularCostoIndividual(aux);
                costoVehiculo += costoVehiculoActual;
                cout << "\nSe le cobra al dueño del vehiculo: " << costoVehiculoActual << " pesos." << endl;

                if (aux2 == NULL) {
                    cab = aux->sig;
                } else {
                    aux2->sig = aux->sig;
                }

                delete aux;
                cout << "\nVehiculo eliminado exitosamente." << endl;
                break;
            }

            aux2 = aux;
            aux = aux->sig;
        }

        if (cab == NULL) {
            cout << "\nEl parqueadero esta vacio." << endl;
        }
    } else {
        cout << "\nEl parqueadero esta vacio." << endl;
    }
}

float mostrarDineroReunido() {
    cout << "\nDinero reunido en la sesión: " << costoVehiculo << " pesos." << endl;

    return costoVehiculo;
}

int main() {
    int opc = 0;
    do {
        cout << "\tsistema de registro de parqueadero" << endl;
        cout << "\nQue deseas realizar?" << endl << endl;
        cout << "1. Registrar vehiculo" << endl;
        cout << "2. Mostrar carros" << endl;
        cout << "3. Mostrar motos" << endl;
        cout << "4. Eliminar vehiculo" << endl;
        cout << "5. Mostrar dinero reunido en la sesión" << endl;
        cout << "6. Salir" << endl << endl;
        cout << "\nIngrese que va a hacer: ";
        cin >> opc;

        switch (opc) {
            case 1:
                do {
                    registrar1();
                    cout << "\nDeseas realizar un nuevo registro? (1:Si / 0:No): ";
                    cin >> opc;
                } while (opc == 1);
                break;
            case 2:
                mostrar1();
                break;
            case 3:
                mostrar2();
                break;
            case 4:
                do {
                    eliminar();
                    cout << "\nDeseas eliminar otro vehiculo? (1:Si / 0:No): ";
                    cin >> opc;
                } while (opc == 1);
                break;
            case 5:
                mostrarDineroReunido();
                break;
        }
    } while (opc != 6);

    return 0;
}