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
        ListaP<T> m;
        posicion p = primero, p1=l.primero;
        while(p1!=l.fin()){
            if(p1!=p){
                insertar(recuperar(p1),p);
                p1=l.siguiente(p1);
                p= siguiente(p);
            }
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
