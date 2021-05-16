/*************************
    Trabajo Práctico 6
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef LISTAP_H
#define LISTAP_H

#ifndef EXIT_ERROR
#define EXIT_ERROR 251
#endif

#include <iostream>
#include <cstdlib>
#include "nodo.h"

template<class T>
class ListaP {
public:


    typedef Nodo<T> *posicion;

    ListaP() {
        primero = new Nodo<T>;
        ultimo = primero;
        primero->siguiente = NULL;
        cant = 0;
    };

    ~ListaP() {};

    int cantidad() {
        return(cant);
    };

    void insertar(T x, posicion p) {
        posicion temp;
        if(p!=NULL) {
            temp = p->siguiente;
            p->siguiente = new Nodo<T>;
            p->siguiente->elemento = x;
            p->siguiente->siguiente = temp;
            if(p==ultimo)
                ultimo = p->siguiente;
            cant++;
        } else {
            std::cerr << "\nHa intentado insertar en una posicion invalida\n";
            exit(EXIT_ERROR);
        }
    };

    void eliminar(posicion p) {
        if((p!=NULL) && (p!=ultimo)) {
            posicion temp = p->siguiente;
            p->siguiente = p->siguiente->siguiente;
            if(temp==ultimo)
                ultimo=p;
            delete temp;
            cant--;
        } else {
            std::cerr << "\nHa intentado eliminar en una posicion invalida\n";
            exit(EXIT_ERROR);
        }
    };

    T recuperar(posicion p) {
        T result;
        if(p!=NULL && p->siguiente!=NULL)
            result = p->siguiente->elemento;
        else {
            std::cerr << "\nHa intentado recuperar en una posicion invalida\n";
            exit(EXIT_ERROR);
        }
        return(result);
    };

    posicion siguiente(posicion p) {
        posicion result;
        if(p!=NULL && p!=ultimo)
            result = p->siguiente;
        else {
            std::cerr << "\nHa intentado encontrar el proximo de una posicion invalida\n";
            exit(EXIT_ERROR);
        }
        return(result);
    };

    posicion anterior(posicion p) {
        posicion q = primero;
        if(p!=NULL) {
            if(p!=q) {
                while(q->siguiente!=NULL &&q->siguiente!=p)
                    q=q->siguiente;
            }
        } else {
            std::cerr << "\nHa intentado encontrar el anterior de una posicion invalida\n";
            exit(EXIT_ERROR);
        }
        return (q);
    };

    posicion fin() {
        return(ultimo);
    };

    posicion primer() {
        return(primero);
    };

    void vaciar() {
        posicion p = primero;
        while(p->siguiente!=NULL) {
            posicion temp = p->siguiente;
            p->siguiente = p->siguiente->siguiente;
            delete temp;
        }
        ultimo = p;
        cant = 0;
    };

    posicion localizar (T x) {
        posicion p;
        p=primero;
        while(p->siguiente!=NULL && p->siguiente->elemento!=x) {
            p=p->siguiente;
        }
        return (p);
    };

    /**
     * Ejercicio 3 B
     * @param l
     * @return
     */
    ListaP<T> mixList(ListaP<T> l){
        ListaP<T>aux;
        ListaP<T>::posicion p1 = this->primer(),
                            p2 = l.primer();
        while(aux.cantidad() != this->cantidad() + l.cantidad()){
            if(p1 != this->fin()){
                aux.insertar(this->recuperar(p1), aux.fin());
                p1 = this->siguiente(p1);
            }
            if(p2 != l.fin()){
                aux.insertar(l.recuperar(p2), aux.fin());
                p2 = l.siguiente(p2);
            }
        }
        return aux;
    }

    bool estaVacia(){
        return primero == ultimo;
    }

    T recuperarPrimero() {
        return recuperar(0);
    }

    T recuperarUltimo() {
        return recuperar(cant - 1);
    }

    void eliminarPrimerElemento() {
        eliminar(0);
    }

    void eliminarUltimoElemento() {
        eliminar(cant - 1);
    }

    void insertarPrimero(T e) {
        insertar(e, 0);
    }

    void insertarUltimo(T e) {
        insertar(e, cant - 1);
    }

    void intercambiar(ListaP<T> &lista2) {
        int cantidad = this->cantidad();
        T aux[cantidad];

        ListaP<T>::posicion p1 = this->primer(), p2 = lista2.primer();

        for(int i = 0; i < this->cantidad(); i++) {
            aux[i] = this->recuperar(p1); // copia el primero al aux
            p1 = this->siguiente(p1);
        }
        this->vaciar();
        for(int i = 0; i < lista2.cantidad(); i++) {
            this->insertar(lista2.recuperar(p2), this->fin()); // copiar el segundo en el primero
            p2 = lista2.siguiente(p2);
        }
        lista2.vaciar();
        for(int i = 0; i < cantidad; i++) {
            lista2.insertar(aux[i], lista2.fin()); // copiar el aux al segundo
        }
    }

    void juntar(posicion pos, ListaP<T> &lista2) {
        ListaP<T>::posicion p = this->primer();
        T aux[this->cantidad()];
        for(int i = this->cantidad() - 1; i >= 0; i--) {
            aux[i] = this->recuperar(p);
            p = siguiente(p);
        }
        for(T e: aux) { lista2.insertar(e, pos); }
    }

    void eliminarElemento(T elem) {
        ListaP<T>::posicion p = this->primer();
        for(int i = 0; i < this->cantidad(); i++) {
            if(this->recuperar(p) == elem) eliminar(p);
            p = siguiente(p);
        }
    }

    void unicos() {
        ListaP<T>::posicion p = this->primer(), p1;
        for(int i = 0; i < this->cantidad(); i++) {
            p1 = p;
            for(int j = i; j < this->cantidad() - 1; j++) {
                p1 = siguiente(p1);
                if(this->recuperar(p) == this->recuperar(p1)) {
                    this->eliminar(p1);
                }
            }
            p = this->primer();
        }
    }


protected:

private:
    posicion primero;
    posicion ultimo;
    unsigned int cant;
};


void test_lista_p(){
    std::cout << std::endl << "Test lista puntero" << std::endl;
    int cantidad;
    ListaP<int> numeros;
    numeros.vaciar();

    for (cantidad=0; cantidad<10; cantidad++)
        numeros.insertar(cantidad, numeros.fin());

    ListaP<int>::posicion pos = numeros.primer();
    while(pos != numeros.fin()){
        std::cout << numeros.recuperar(pos)<<"; ";
        pos = numeros.siguiente(pos);
    }
}

#endif // LISTAP_H
