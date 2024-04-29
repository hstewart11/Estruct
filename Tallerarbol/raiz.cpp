#include <iostream>
using namespace std;

struct nodo {
    string est;
    int cod;
    int an;
    int mes;
    int dia;
    nodo *izq;
    nodo *der;
}; 

nodo *raiz, *aux, *aux2; 

int posicionar() {
    if (aux->an < aux2->an) {
        if (aux2->izq != NULL) {
            aux2 = aux2->izq;
            posicionar();
        } else {
            aux2->izq = aux;
        }
    } else if (aux->an >= aux2->an) {
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            posicionar();
        } else {
            aux2->der = aux;
        }
    }
}
int registrar(){
    aux = ((struct nodo *) malloc (sizeof(struct nodo)));
    cout<<"\nIngrese el nombre del estudiante"<<endl;
    cin.ignore();
    getline(cin, aux->est);
    cout<<"\nIngrese el codigo del estudiante"<<endl;
    cin>>aux->cod;
    cout<<"\nIngrese el año de nacimiento"<<endl;
    cin>>aux->an;
    cout<<"\nIngrese el mes de nacimiento"<<endl;
    cin>>aux->mes;
    cout<<"\nIngrese el dia de nacimiento"<<endl;
    cin>>aux->dia;
    aux->izq = aux->der = NULL;
   
    if(raiz==NULL){
        raiz = aux;
        aux = NULL;
        free(aux);
    } else {
        aux2 = raiz;
        posicionar();
    }
}

void preorden(nodo *recursive){
    cout<<"Nombre: "<<recursive->est<<", Codigo: "<<recursive->cod<<", Año de nacimiento: "<<recursive->an<<endl;
    if(recursive->izq != NULL)
        preorden(recursive->izq);
    if(recursive->der != NULL)
        preorden(recursive->der);
}

void recorrer(){
    if(raiz != NULL){
        preorden(raiz);
    }
}
int main(){
    int opc=0;
    do {
        cout<<"\n\t Sistema de registro de estudiantes"<<endl;

        cout<<"1. Registrar"<<endl;
        cout<<"2. Mostrar preorden"<<endl;
        cout<<"3. Eliminar estudiante"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1: registrar();
            break;
        case 2: recorrer();
            break;
        }

    } while(opc!=3);
}

// Harold Stewart Viveros Quiñones
// Santiago Andres Guarnizo Patiño