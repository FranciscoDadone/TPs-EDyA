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
 * Implementación parametrizable del TDA Pila.
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
template <class T, unsigned int LONG_MAX_PILA=15>
void swap(PilaA<T, LONG_MAX_PILA> &x){
   std::queue<T> c;
    while(!x.estaVacia()){
        c.push(x.recuperarTope());
        x.desapilar();
    }
    while(!c.empty()){
        x.apilar(c.front());
        c.pop();
    }
}


#endif  // PILAA_H
