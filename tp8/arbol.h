#ifndef TP8_ARBOL_H
#define TP8_ARBOL_H
#include <cassert>
#include<stack>
#include <array>
#include <vector>
#include <list>
#include <queue>


/**
 * Inserts the array to the binary search tree.
 * @tparam T
 * @param a
 * @param arr
 */
template <class T>
void insertABB(ArbolBin<T> &a, std::vector<T> arr) {
    for(T element: arr) {
        if(*a.raizArbol() == NULL) {
            a.asignarNodo(element, *a.raizArbol());
        } else {
            Nodo<T> * temp = *a.raizArbol();
            while(temp != NULL) {
                if(element == temp->elemento) return;
                else if(element < temp->elemento && temp->HIzq == NULL) {
                    a.asignarNodo(element, *a.hijoIzq(temp));
                    break;
                } else if(element < temp->elemento) {
                    temp = temp->HIzq;
                } else if(element > temp->elemento && temp->HDer == NULL) {
                    a.asignarNodo(element, *a.hijoDer(temp));
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
    std::vector<int> arr;
    std::cout << "[ ";
    for(int i = 0; i <= cant; i++) {
        arr.push_back(rand() % ((N + N) + 1) - N);
        std::cout << arr.at(i) << ((i < cant) ? ", " : "");
    }
    std::cout << " ]";

    ArbolBin<int> a;
    a.insertABB(arr);

//    Nodo<int>* *r=a.raizArbol();
//    assert(r!=nullptr);
//    if(cant < 1) {
//        assert(*a.hijoIzq(*r)==nullptr);
//        assert(*a.hijoDer(*r)==nullptr);
//    }
//    a.talar();
//    assert(*r==nullptr);
//    assert(r!=nullptr);
}

template<class T>
void listarPostOrden(ArbolBin<T> & arbol){
    recorrer(arbol, *arbol.raizArbol());
}
template<class T>
void recorrer(ArbolBin<T> & a,Nodo<T>*n){
    if(n != nullptr) {
        recorrer(a,*a.hijoIzq(n));
        recorrer(a,*a.hijoDer(n));
        std::cout << a.recuperar(n) << " ";
    }
}
template<class T>
size_t contarNodosHojas(ArbolBin<T> &arbol){
    return contH(arbol,*arbol.raizArbol(),0);
}
template<class T>
size_t contH(ArbolBin<T> & a,Nodo<T>*n, size_t c){
    if(n!=nullptr){
        c=contH(a,*a.hijoIzq(n),c);
        c=contH(a,*a.hijoDer(n),c);
        if(*a.hijoIzq(n)==nullptr && *a.hijoDer(n)==nullptr){
            c++;
        }
    }
    return c;
}

template<class T>
std::list<T> listarPorNivel(ArbolBin<T> & arbolito){
    std::list<T> lista;
    std::queue<Nodo<T>*> fila;
    Nodo<T> ** r = arbolito.raizArbol();
    if (r == nullptr) return lista;
    fila.push(*r);
    while(fila.empty() == false){
        Nodo<T> *n = fila.front();
        lista.push_back(n->elemento);
        fila.pop();
        if(n->HIzq!= NULL){
            fila.push(n->HIzq);
        }
        if(n->HDer!= NULL){
            fila.push(n->HDer);
        }
    }
    return lista;
}


#endif //TP8_ARBOL_H
