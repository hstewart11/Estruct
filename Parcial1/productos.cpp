/*
Desarrolla un programa que implemente un arreglo tipo FIFO (First In, First Out) para gestionar el inventario y las ventas de productos de un almacén.

Cada producto en el inventario debe registrarse con la siguiente información:

ID del producto: un número entero único para cada producto.
Nombre del producto: una cadena de caracteres.
Cantidad: un número entero que representa la cantidad de unidades disponibles del producto.
Precio por unidad: un valor decimal que representa el costo de cada unidad del producto.
El programa debe ser capaz de realizar las siguientes operaciones:

Registrar Producto: Agregar un nuevo producto al final de la cola del inventario. (+10 Puntos)
Mostrar Inventario: Listar todos los productos en el inventario, mostrando su ID, nombre, cantidad y precio por unidad. (+10 Puntos)
Buscar Producto por ID: Buscar y mostrar la información de un producto utilizando su ID. (+10 Puntos)
Eliminar Producto: Eliminar un producto del inventario basado en su ID. Esta operación debe remover el primer producto que coincida con el ID proporcionado. (+20 Puntos)
Calcular el Valor Total del Inventario: Sumar el valor total de todos los productos en el inventario (Cantidad * Precio por unidad) y mostrar el resultado. (+10 Puntos)
Calcular el Promedio de Precios: Determinar el precio promedio por unidad de todos los productos en el inventario. (+10 Puntos)
Vender Productos: Permitir la venta de productos mediante el siguiente proceso:

Solicitar al usuario el ID del producto a vender.
Buscar el producto por su ID y mostrar su información.
Preguntar al usuario la cantidad de unidades que desea comprar. 
Verificar si hay existencias suficientes del producto. Si no hay suficientes, informar al usuario y cancelar la venta.(+10 Puntos)
Si hay existencias suficientes, descontar la cantidad vendida del inventario y calcular el total a pagar (Cantidad * Precio por unidad). (+10 Puntos)
Mostrar al usuario el total a pagar por los productos vendidos. (+10 Puntos)
*/

#include <iostream>
#include <malloc.h>
using namespace std;

struct nodo {
    int codigo;
    char nombre[30];
    int id;
    int cantidad;
    float precio;
    struct nodo* sig;
};

nodo* cab = NULL;
nodo* aux = NULL;
nodo* aux2 = NULL;

int registrar() {
    aux = (struct nodo *)malloc(sizeof(struct nodo));
    if (aux == NULL) {
        
        return -1;
    }
    cout << "\nIngrese el nombre del producto: ";
    cin >> aux->nombre;
    cout << "Ingrese el codigo: ";
    cin >> aux->id;
    cout << "Cual es la cantidad: ";
    cin >> aux->cantidad;
    cout << "Ingrese precio unitario: ";
    cin >> aux->precio;
    aux->sig = NULL;
    if (cab == NULL) {
        cab = aux;
    } else {
        aux2 = cab;
        while (aux2->sig != NULL) {
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
    return 0;
}

void mostrar() {
    for (aux = cab; aux != NULL; aux = aux->sig) {
        cout << "REGISTRO DE PRODUCTOS: " << endl << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "ID unico: " << aux->id << endl;
        cout << "cantidad disponible: " << aux->cantidad << endl;
        cout << "precio unitario: " << aux->precio << endl << endl;
    }
}

int eliminar() {
    int opc2 = 0;
    cout << "Digite el id del producto a eliminar: ";
    cin >> opc2;
    aux = cab;
    while (aux != NULL) {
        if (aux->id == opc2) {
            if (aux == cab) {
                cab = aux->sig;
                free(aux);
                cout << "PRODUCTO ELIMINADO." << endl;
                return 0;
            } else {
                aux2->sig = aux->sig;
                free(aux);
                cout << "PRODUCTO ELIMINADO." << endl;
                return 0;
            }
        }
        aux2 = aux;
        aux = aux->sig;
    }
    cout << "Este ID no existe. " << endl;
    return -1;
}

int buscar(){
    
    int buscarid;
   cout<<"Cual es el ID a buscar: "<<endl;
   
   cin>>buscarid;


    for(aux=cab; aux!=NULL; aux = aux->sig){
        if(aux->id==buscarid){
            cout<<"ID: "<<aux->id<<endl;
            cout<<"Nombre: "<<aux->nombre<<endl;
            cout<<"Cantidad: "<<aux->cantidad<<endl;
            cout<<"Precio unitario: "<<aux->precio<<endl<<endl;
            
        }
    } 

}

float calcularTotal() {
    float total = 0.0;
    for (aux = cab; aux != NULL; aux = aux->sig) {
        total += aux->cantidad * aux->precio;
    }
    return total;
}
float promedio() {
 
    float ptotal = 0.0;
    for (aux = cab; aux != NULL; aux = aux->sig) {
        ptotal += (1 * aux->precio)/2;
    }
    return ptotal;
}

void vender() {
    int idVenta, cantidadVenta;
    cout << "Ingrese el ID del producto a vender: ";
    cin >> idVenta;
    for (aux = cab; aux != NULL; aux = aux->sig) {
        if (aux->id == idVenta) {
            cout << "Informacion del producto: " << endl;
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Cantidad disponible: " << aux->cantidad << endl;
            cout << "Precio por unidad: " << aux->precio << endl;
            cout << "\nIngrese la cantidad que desea comprar: ";
            cin >> cantidadVenta;
            if (cantidadVenta > aux->cantidad) {
                cout << "\nNo hay suficientes existencias del producto." << endl;
                return;
            } else {
                aux->cantidad -= cantidadVenta;
                float totalVenta = cantidadVenta * aux->precio;
                cout << "Total a pagar por los productos vendidos: $" << totalVenta << endl;
                return;
            }
        }
    }
    cout << "El producto con el ID especificado no existe en el inventario." << endl;
}



int main() {
    int opc = 0;
    do {
        cout << "\tBIENVENIDO AL SISTEMA DE REGISTRO DE PRODUCTOS" << endl;
        cout << "\nQue deseas realizar?" << endl << endl;
        cout << "1. Registrar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Eliminar producto" << endl;
        cout << "4. buscar" << endl;
        cout << "5. Precio total de inventario" << endl;
        cout << "6. Promedio " << endl;
        cout << "7. Realizar ventas" << endl;
        cout << "8. Salir" << endl << endl;
        cout << "\nIngrese que va a hacer: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case 1:
                do {
                    registrar();
                    cout << "\nDeseas realizar un nuevo registro? (1:Si / 0:No): ";
                    cin >> opc;
                } while (opc == 1);
                break;
            case 2:
                mostrar();
                break;
            case 3:
                  do {
                    eliminar();
                    cout << "\nDeseas eliminar otro producto? (1:Si / 0:No): ";
                    cin >> opc;
                } while (opc == 1);
                break;
            case 4:
            do {
                    buscar();
                    cout << "\nDeseas realizar una nueva busqueda? (1:Si / 0:No): ";
                    cin >> opc;
                } while (opc == 1);
                break;
            case 5:
                cout << "\nEl valor total de todos los productos en el inventario es: $" << calcularTotal() << endl;
                break;
            case 6:
                cout << "\nEl promedio unitario de los productos en el inventario es: $" << promedio() << endl;
                break;
            case 7:
                    do {
                    vender();
                    cout << "\nDeseas realizar una nueva venta? (1:Si / 0:No): ";
                    cin >> opc;
                } while (opc == 1);
                break;
        }
    } while (opc != 8);

    return 0;
}

// Santiago Andres Guarnizo Patiño
// Harold Stewart Viveros Quiñones