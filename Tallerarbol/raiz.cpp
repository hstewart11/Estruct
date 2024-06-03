// Harold Stewart Viveros Quiñones
// Santiago Andres Guarnizo Patiño

#include <iostream>
#include <malloc.h>
using namespace std;

struct nodo {
    char est[60];
    int cod;
    int an;
    int mes;
    int dia;
    int gen;
    nodo *izq;
    nodo *der;
}; 

nodo *raiz=NULL, *raiz2=NULL, *aux=NULL, *aux2=NULL, *aux3=NULL;

int posicionar() {
    if (aux->an < aux2->an) {
        if (aux2->izq != NULL) {
            aux2 = aux2->izq;
            posicionar();
        } else {
            aux2->izq = aux;
            return 0;
        }
    } else if (aux->an > aux2->an) {
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            posicionar();
        } else {
            aux2->der = aux;
            return 0;
        }
    } else { 
        if (aux->mes < aux2->mes) {
            if (aux2->izq != NULL) {
                aux2 = aux2->izq;
                posicionar();
            } else {
                aux2->izq = aux;
                return 0;
            }
        } else if (aux->mes > aux2->mes) {
            if (aux2->der != NULL) {
                aux2 = aux2->der;
                posicionar();
            } else {
                aux2->der = aux;
                return 0;
            }
        } else { 
            if (aux->dia < aux2->dia) {
                if (aux2->izq != NULL) {
                    aux2 = aux2->izq;
                    posicionar();
                } else {
                    aux2->izq = aux;
                    return 0;
                }
            } else if (aux->dia > aux2->dia) {
                if (aux2->der != NULL) {
                    aux2 = aux2->der;
                    posicionar();
                } else {
                    aux2->der = aux;
                    return 0;
                }
            } else {
                cout << "El estudiante ya está registrado." << endl;
                free(aux);
                return 0;
            }
        }
    }
    return 0;
}
int posicionar2() {
    aux3 = aux;
    if (aux3->cod < aux2->cod) {
        if (aux2->izq != NULL) {
            aux2 = aux2->izq;
            posicionar2();
        } else {
            aux2->izq = aux3;
             aux2 = raiz2;
             return 0;
    
        }
    } else if(aux3->cod > aux2->cod)  {
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            posicionar2();
        } else {
            aux2->der = aux3;
            aux2 = raiz2;
             return 0;
        }
 
    }

    return 0;
}
int registrar(){
     aux = ((struct nodo *) malloc (sizeof(struct nodo)));
    cout<<"\nIngrese el nombre del estudiante"<<endl;
    cin.ignore();
    cin.getline(aux->est, 60);
    cout<<"\nIngrese el codigo del estudiante"<<endl;
    cin>>aux->cod;
    cout<<"\nIngrese el año de nacimiento"<<endl;
    cin>>aux->an;
    cout<<"\nIngrese el mes de nacimiento"<<endl;
    cin>>aux->mes;
    cout<<"\nIngrese el dia de nacimiento"<<endl;
    cin>>aux->dia;
    cout<<"\nIngrese con que genero se identifica( 1. Masculino, 2. Femenino, 3. Np)"<<endl;
    cin>>aux->gen;
    
    aux->izq = NULL;
    aux->der = NULL;
   
    if(raiz==NULL){
        raiz = aux;
        // aux = NULL;
        // // free(aux);
    } else {
        aux2 = raiz;
        posicionar();
    }
    if(raiz2==NULL){
        raiz2 = aux2;
        // free(aux);
    } else {
        aux2 = raiz2;
        posicionar2();
    }
    return 0;
}

// int mgen(){
//     int mas = 0;
//     int fem = 0;
//     int npe = 0;
//     aux3 = aux;
//     if (aux3->gen == 1) {
//         mas++;
//         cout<<"hombre"<< mas;
//     }
//     else if(aux3->gen == 2) {
//         fem++;
//         cout<<"mujer"<< fem;
//     }
//     else if(aux3->gen == 3) {
//         npe++;
//         cout<<"no respondió"<< npe;
//     }
//              return 0;
    

// }
int preorden(nodo *recursive){
    cout<<"Nombre: "<<recursive->est<<", Año: "<<recursive->an<<", Mes: "<<recursive->mes<<", Dia: "<<recursive->dia<<endl;
    if(recursive->izq != NULL){
        preorden(recursive->izq);
    }
    if(recursive->der != NULL){
        preorden(recursive->der);
    }
    return 0;
}
int mgen(nodo *recursive){
     int mas = 0;
    int fem = 0;
    int npe = 0;
    aux3 = aux;
    if (aux3->gen == 1) {
        mas++;
        cout<<"Se identifican "<<mas<< "como masculino";
    }
    else if(aux3->gen == 2) {
        fem++;
        cout<<"Se identifican "<<fem<<"como femenino";
    }
    else if(aux3->gen == 3) {
        npe++;
        cout<<npe<<" No respondieron";
    }
    if(recursive->izq != NULL){
        preorden(recursive->izq);
    }
    if(recursive->der != NULL){
        preorden(recursive->der);
    }
    return 0;
}
int preorden2(nodo *recursive){
    cout<<"Nombre: "<<recursive->est<<", Codigo: "<<recursive->cod<<endl;
    if(recursive->izq != NULL){
        preorden2(recursive->izq);
    }
    if(recursive->der != NULL){
        preorden2(recursive->der);
    }
    return 0;
}
int inorden(nodo *recursive){
    if(recursive->izq != NULL){
        inorden(recursive->izq);
    }
    cout<<"Nombre: "<<recursive->est<<", Año: "<<recursive->an<<", Mes: "<<recursive->mes<<", Dia: "<<recursive->dia<<endl;
    if(recursive->der != NULL){
        inorden(recursive->der);
    }
    return 0;
}
int inorden2(nodo *recursive){
    if(recursive->izq != NULL){
        inorden2(recursive->izq);
    }
    cout<<"Nombre: "<<recursive->est<<", Codigo: "<<recursive->cod<<endl;
    if(recursive->der != NULL){
        inorden2(recursive->der);
    }
    return 0;
}
int postorden(nodo *recursive){
    if(recursive->izq != NULL){
        postorden(recursive->izq);
    }
    if(recursive->der != NULL){
        postorden(recursive->der);
    cout<<"Nombre: "<<recursive->est<<", Año: "<<recursive->an<<", Mes: "<<recursive->mes<<", Dia: "<<recursive->dia<<endl;
    }
    return 0;
}
int postorden2(nodo *recursive){
    if(recursive->izq != NULL){
        postorden2(recursive->izq);
    }
    if(recursive->der != NULL){
        postorden2(recursive->der);
    cout<<"Nombre: "<<recursive->est<<", Codigo: "<<recursive->cod<<endl;
    }
    return 0;
}

int eliminar(nodo *&raiz, int codigo) {
    if (raiz == NULL) {
        cout << "El arbol esta vacio." << endl;
        return 0;
    }

    nodo *padre = NULL;
    nodo *actual = raiz;

    // Buscar el nodo a eliminar
    while (actual != NULL && actual->cod != codigo) {
        padre = actual;
        if (codigo < actual->cod) {
            actual = actual->izq;
        } else {
            actual = actual->der;
        }
    }

    if (actual == NULL) {
        cout << "No se encontro el estudiante con el codigo especificado." << endl;
        return 0;
    }

    // Caso 1: El nodo a eliminar sin hijos
    if (actual->izq == NULL && actual->der == NULL) {
        if (padre == NULL) { // Es la raíz
            free(raiz);
            raiz = NULL;
        } else if (padre->izq == actual) {
            padre->izq = NULL;
        } else {
            padre->der = NULL;
        }
        free(actual);
        cout << "Estudiante eliminado exitosamente." << endl;
        return 0;
    }

    // Caso 2: El nodo a eliminar tiene un solo hijo
    if (actual->izq == NULL || actual->der == NULL) {
        nodo *hijo = (actual->izq != NULL) ? actual->izq : actual->der;
        if (padre == NULL) { // Es la raíz
            raiz = hijo;
        } else if (padre->izq == actual) {
            padre->izq = hijo;
        } else {
            padre->der = hijo;
        }
        free(actual);
        cout << "Estudiante eliminado exitosamente." << endl;
        return 0;
    }

    // Caso 3: El nodo a eliminar tiene dos hijos
    nodo *sucesor = actual->der;
    padre = actual;
    while (sucesor->izq != NULL) {
        padre = sucesor;
        sucesor = sucesor->izq;
    }

    
    for (int i = 0; i < 60; i++) {
        actual->est[i] = sucesor->est[i];
    }
    actual->cod = sucesor->cod;
    actual->an = sucesor->an;
    actual->mes = sucesor->mes;
    actual->dia = sucesor->dia;

    if (padre->izq == sucesor) {
        padre->izq = sucesor->der;
    } else {
        padre->der = sucesor->der;
    }
    free(sucesor);
    cout << "Estudiante eliminado exitosamente." << endl;
    return 0;
}


int main(){
    int opc=0;
    do {
        cout<<"\n\t Sistema de registro de estudiantes"<<endl;

        cout<<"1. Registrar"<<endl;
        cout<<"2. Mostrar por año preorden"<<endl;
        cout<<"3. Mostrar por codigo preorden"<<endl;
        cout<<"4. Mostrar por año inorden"<<endl;
        cout<<"5. Mostrar por codigo inorden"<<endl;
        cout<<"6. Mostrar por año postorden"<<endl;
        cout<<"7. Mostrar por codigo postorden"<<endl;
        cout<<"8. Eliminar estudiante"<<endl;
        cout<<"9. Mostrar por genero"<<endl;
        cout<<"10. Salir"<<endl;
        cin>>opc;
        cin.clear();
        switch (opc)
        {
        case 1: 
        do{
                 registrar();               
        cout << "\nDeseas realizar un nuevo registro? (1:Si / 0:No): ";
                    cin >> opc;
                } while (opc == 1);
        break;

        case 2:
        cout<<"\n Mostrar por año de nacimiento. "<<endl; 
            preorden(raiz);
            break;
        case 3:
        cout<<"\n Mostrar por codigo de estudiante. "<<endl; 
            preorden2(raiz2);
            break;
        case 4:
        cout<<"\n Mostrar por año de nacimiento. "<<endl; 
            inorden(raiz);
            break;
        case 5:
        cout<<"\n Mostrar por codigo de estudiante. "<<endl; 
            inorden2(raiz2);
            break;
        case 6: 
        cout<<"\n Mostrar por año de nacimiento. "<<endl; 
            postorden(raiz);
            break;
        case 7:
        cout<<"\n Mostrar por codigo de estudiante. "<<endl; 
            postorden2(raiz2);
            break;
        case 8:  
        int elim;
            cout << "Ingrese el código del estudiante que desea eliminar: ";
            cin >> elim;
            eliminar(raiz, elim);
            break;
            
        case 9:
            mgen(raiz);
            break;
        }

    } while(opc!=10);
}

