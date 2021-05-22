/*************************
    Trabajo Práctico 7
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef PILAA_H
#define PILAA_H
#ifndef EXIT_ERROR
#define EXIT_ERROR 253
#endif
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include<queue>
/**
 * Implementaci?n parametrizable del TDA Pila.
 * Se utiliza un array de tipo T para almacenar los elementos en memoria.
 */
template <class T, unsigned int LONG_MAX_PILA=15>
class PilaA {
public:
    PilaA() {
        tope = LONG_MAX_PILA;
        cant = 0;
    };
    ~PilaA() {}
    bool estaVacia() {
        return tope == LONG_MAX_PILA;
    }
    void apilar(T x) {
        if (tope==0) {
            std::cout << "La pila esta llena" << std::endl;
            exit(EXIT_ERROR);
        } else {
            tope--;
            elementos[tope] = x;
            cant++;
        }
    }
    void desapilar() {
        if (tope==LONG_MAX_PILA) {
            std::cerr<<"Ha intentado despilar de una pila vacia"<<std::endl;
            exit(EXIT_ERROR);
        } else {
            tope++;
            cant--;
        }
    }
    T recuperarTope() {
        T resul;
        if (tope==LONG_MAX_PILA) {
            std::cerr<<"Ha intentado obtener el tope de una pila vacia"<<std::endl;
            exit(EXIT_ERROR);
        } else
            resul = elementos[tope];
        return resul;
    }
    int cantidad() {
        return cant;
    }
    /**
     * Intercambia dos pilas.
     * @tparam T
     * @tparam LONG_MAX_PILA
     * @param x
     */
    void swap(PilaA<T, LONG_MAX_PILA> &x) {
        T tmp[x.cant];
        int i = 0, d = this->cant - x.cant;
        while(!x.estaVacia()) {
            tmp[i] = x.recuperarTope();
            x.desapilar();
            i++;
        }
        for(int i = this->cant; i > 0; i--) {
            x.apilar(this->recuperarTope());
            this->desapilar();
        }
        for(int i = 0; i < x.cant - d; i++) {
            this->apilar(tmp[i]);
        }
    }
protected:
private:
    T elementos[LONG_MAX_PILA];
    int tope;
    int cant;
};

void test_pila() {
    PilaA<int> numeros;

    std::cout << std::endl << __func__ << std::endl;
    std::cout << "La pila posee " << numeros.cantidad() << " elementos" << std::endl;
    ///////////////////////////////////////////////////
    for (unsigned short i=0; i<10; ++i)
        numeros.apilar(1+i);
    ///////////////////////////////////////////////////
    if (!numeros.estaVacia())
        std::cout << "El elemento que se encuentra en el tope es " << numeros.recuperarTope() << std::endl;
    if (!numeros.estaVacia())
        numeros.desapilar();
    if (!numeros.estaVacia())
        std::cout << "El elemento que se encuentra en el tope es " << numeros.recuperarTope() << std::endl;
    ///////////////////////////////////////////////////
    std::cout << "La pila posee " << numeros.cantidad() << " elementos" << std::endl;
    ///////////////////////////////////////////////////
    std::cout << "Elementos: ";
    while (!numeros.estaVacia()) {
        std::cout << std::setw(3) << std::setfill(' ') << numeros.recuperarTope() << ", ";
        numeros.desapilar();
    }
    ///////////////////////////////////////////////////
    std::cout << std::endl << "La pila posee " << numeros.cantidad() << " elementos" << std::endl;
    std::cout << "La pila esta vacia " << (numeros.estaVacia()?"Si":"No") << std::endl;

}


#endif  // PILAA_H
