#ifndef TP8_ARBOL_H
#define TP8_ARBOL_H
#include <cassert>


//#include "include/arbol_test.h"

/**
 * Inserts the array to the binary search tree.
 * @tparam T
 * @param a
 * @param arr
 */
template <class T>
void insertABB(ArbolBin<T> &a, T arr[]) {
    for(int i = 0; i <= (sizeof(arr)/sizeof(*arr)); i++) {
        if(*a.raizArbol() == NULL) {
            a.asignarNodo(arr[i], *a.raizArbol());
        } else {
            Nodo<T> * temp = *a.raizArbol();
            while(temp != NULL) {
                if(arr[i] == temp->elemento) return;
                else if(arr[i] < temp->elemento && temp->HIzq == NULL) {
                    a.asignarNodo(arr[i], *a.hijoIzq(temp));
                    break;
                } else if(arr[i] < temp->elemento) {
                    temp = temp->HIzq;
                } else if(arr[i] > temp->elemento && temp->HDer == NULL) {
                    a.asignarNodo(arr[i], *a.hijoDer(temp));
                    break;
                } else temp = temp->HDer;
            }
        }
    }
}

/**
* @brief Prueba la carga en un ABB con valores enteros entre [-N, N]
* @param cant Cantidad máxima de números a insertar en el ABB
* @param N Rango de valores
*/
void test_abb(unsigned int cant, unsigned int N) {
    int arr[cant];

    std::cout << "[ ";
    for(int i = 0; i <= cant; i++) {
        arr[i] = rand() % ((N + N) + 1) - N;
        std::cout << arr[i] << ((i < cant) ? ", " : "");
    }
    std::cout << " ]";


    ArbolBin<int> a;
    a.insertABB(arr);

    Nodo<int>* *r=a.raizArbol();
    assert(r!=nullptr);
    if(cant < 1) {
        assert(*a.hijoIzq(*r)==nullptr);
        assert(*a.hijoDer(*r)==nullptr);
    }
    a.talar();
    assert(*r==nullptr);
    assert(r!=nullptr);


}


#endif //TP8_ARBOL_H
