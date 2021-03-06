/* Copyright 2020 EDyA */
/*************************
    Trabajo Práctico 7
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef FILAA_H
#define FILAA_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#ifndef EXIT_ERROR
#define EXIT_ERROR 254
#endif

/**
 * Implementación parametrizable del TDA Fila Circular.
 * Estructura de datos lineal de tipo FIFO con
 * complejidad temporal O(1) para todas las operaciones.
 */
template <class T, unsigned int LONG_MAX_FILA=15>
class FilaA {
public:
    FilaA() {
        ultimo = 0;
        primero = 1;
        cant = 0;
    }

    int estaVacia() {
        return primero == (ultimo+1)%LONG_MAX_FILA;
    }

    void poner(T x) {
        if (((((ultimo+1)%LONG_MAX_FILA)+1)%LONG_MAX_FILA) == primero) {
            std::cerr << "Ha intentado poner en una fila llena";
            exit(EXIT_ERROR);
        } else {
            ultimo = (ultimo+1)%LONG_MAX_FILA;
            elementos[ultimo] = x;
            cant++;
        }
    }

    void quitar() {
        if (primero != (ultimo+1)%LONG_MAX_FILA) {
            primero = (primero+1)%LONG_MAX_FILA;
            cant--;
        } else {
            std::cerr << "Ha intentado retirar de una fila vacia";
            exit(EXIT_ERROR);
        }
    }

    T recuperarFrente() {
        if (primero == (ultimo+1)%LONG_MAX_FILA) {
            std::cerr << "Ha intentado obtener el frente de una fila vacia";
            exit(EXIT_ERROR);
        }
        return elementos[primero];
    }

    /**
     * Returns the last element.
     * @return
     */
    T recuperarUltimo(){
        if (primero == (ultimo + 1) % LONG_MAX_FILA) {
            std::cerr << "Ha intentado obtener el frente de una fila vacia";
            exit(EXIT_ERROR);
        }
        return elementos[ultimo];
    }
    /**
     * Takes the firsts n elements.
     * @param n
     */
    void quitarN(unsigned int n){
        if(n > this->cantidad()) {
            this->vaciar();
        } else {
            for(int i = 0; i < n; i++) {
                this->quitar();
            }
        }
    }
    /**
     * Puts a new element in front of the array.
     * @param x
     */
    void ponerAlFrente(T x){
        if (((((ultimo + 1) % LONG_MAX_FILA) + 1) % LONG_MAX_FILA) == primero) {
            std::cerr << "Ha intentado poner en una fila llena";
            exit(EXIT_ERROR);
        } else {
            cant++;
            for(int i = cant; i > primero; i--) {
                elementos[i] = elementos[i-1];
            }
            elementos[primero] = x;
        }
    }
    /**
     * Inverts the array.
     */
    void invertir() {
        T aux[cant + 1];
        for(int i = 1; i < cant + 1; i++) {
            aux[i] = elementos[i];
        }
        for(int i = cant; i > -1; i--) {    // es -1 porque los array empiezan en 1.
            elementos[cant - i] = aux[i + 1];
        }
    }

    int cantidad() {
        return cant;
    }

    void vaciar() {
        ultimo = 0;
        primero = 1;
        cant = 0;
    }

    /**
     * Out operator.
     * @param out
     * @param f
     * @return
     */
    friend std::ostream& operator << (std::ostream& out, const FilaA &f) {

        for(int i = 1; i < f.cant + 1; i++) {
            out << f.elementos[i] << " ";
        }
        return out;
    }
    /**
     * Equals operator.
     * @param lhs
     * @param rhs
     * @return
     */
    friend bool operator == (const FilaA& lhs, const FilaA& rhs){
        if(lhs.cant != rhs.cant) return false;
        for(int i = 1; i < lhs.cant + 1; i++) {
            if(lhs.elementos[i] != rhs.elementos[i]) return false;
        }
        return true;
    }
    /**
     * Not equal operator.
     * @param lhs
     * @param rhs
     * @return
     */
    friend bool operator != (const FilaA& lhs, const FilaA& rhs){
        return !(lhs == rhs);
    }


private:
    T elementos[LONG_MAX_FILA];
    unsigned int ultimo, primero;
    unsigned int cant;
};


void test_fila() {

    std::cout << std::endl << __func__ << std::endl;
    FilaA<int> numeros;
    std::cout << "La fila posee " << numeros.cantidad()<< " elementos." << std::endl;
    /////////////////////////////////////////////////////////
    for (auto i : {1,2,3,4,5,6,7,8,9,10})
        numeros.poner(i);
//    while(true)
//        numeros.poner(10001);
    /////////////////////////////////////////////////////////
    std::cout << "El elemento que se encuentra en el frente es " <<
              numeros.recuperarFrente() << "." << std::endl;
    if (!numeros.estaVacia())
        numeros.quitar();
    std::cout << "El elemento que se encuentra en el frente es " <<
              numeros.recuperarFrente() << "." << std::endl;
    std::cout << "La fila posee " << numeros.cantidad() << " elementos"
              << "." << std::endl;
    /////////////////////////////////////////////////////////
    std::cout << "Elementos:"  << std::endl;
    while (!numeros.estaVacia()) {
        std::cout << std::setw(3) << std::setfill('0') <<
                  numeros.recuperarFrente() << std::endl;
        numeros.quitar();
    }
    /////////////////////////////////////////////////////////
    std::cout << "La fila posee " << numeros.cantidad() << " elementos." << std::endl;
    std::cout << "La fila esta vacia " <<(numeros.estaVacia()?"Si":"No");
    std::cout << std::endl << std::endl;

    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    std::cout << std::endl << __func__ << " string" << std::endl<< std::endl;
    FilaA<std::string, 100> stringQueue;
    std::string s = "\
Queues are a type of container adaptor, specifically designed to operate \
in a FIFO context (first-in first-out), where elements are \
inserted into one end of the container and extracted from the other.";
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        stringQueue.poner(token);
        s.erase(0, pos + delimiter.length());
    }
    stringQueue.poner(s);
    while (!stringQueue.estaVacia()) {
        std::cout << stringQueue.recuperarFrente() << std::endl;
        stringQueue.quitar();
    }
}


#endif  // FILAA_H