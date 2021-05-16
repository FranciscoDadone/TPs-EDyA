/* Copyright 2017 EDyA */
/*************************
    Trabajo Práctico 6
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef NODO_H
#define NODO_H

#include <iostream>

template<class T>
class Nodo {
 public:
    Nodo() {
        std::cout << std::endl << "new Nodo " << this << std::endl;
    }
    ~Nodo() {
        std::cout << std::endl << "delete Nodo " << this << std::endl;
    }
    T elemento;
    Nodo<T> *siguiente;
 protected:
 private:
};
#endif  // NODO_H
