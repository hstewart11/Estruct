// Harold Stewart Viveros Quiñones
// Santiago Andres Guarnizo Patiño

#include <iostream>
#include <malloc.h>
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
    }  else if (aux->an == aux2->an) {
     
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            posicionar();
        } else {
            aux2->der = aux;
         } 
        } else  {
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            posicionar();
        } else {
            aux2->der = aux;
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
    getline(cin, aux->est);
    cout<<"\nIngrese el codigo del estudiante"<<endl;
    cin>>aux->cod;
    cout<<"\nIngrese el año de nacimiento"<<endl;
    cin>>aux->an;
    cout<<"\nIngrese el mes de nacimiento"<<endl;
    cin>>aux->mes;
    cout<<"\nIngrese el dia de nacimiento"<<endl;
    cin>>aux->dia;
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
        // case 8: eliminar();
        //     break;
        }

    } while(opc!=10);
}

