#include <iostream>
#include "include/arbolbin.h"
#include <algorithm>

using namespace std;

template <class T>
ArbolBin<T> arbolBinarioBusqueda(T *arr, unsigned int size, unsigned int i, Nodo<T> ** pos) {
    ArbolBin<T> a;
    if(a.recuperar(*a.raizArbol()) == NULL) {
        a.asignarNodo(arr[i], *a.raizArbol());
        arbolBinarioBusqueda(arr, size, (i + 1), pos);
    } else if(arr[i] > a.recuperar(*pos)) {
        a.asignarNodo(arr[i], *a.hijoDer(*pos));
        arbolBinarioBusqueda(arr, size, (i + 1), a.raizArbol());
    } else if(arr[i] < a.recuperar(*pos)) {
        a.asignarNodo(arr[i], *a.hijoIzq(*pos));
        arbolBinarioBusqueda(arr, size, (i + 1), a.raizArbol());
    }

    return a;

}

int main() {

    int arr[] = { 5, 4, 1, 2, 3 };
    ArbolBin<int> a = arbolBinarioBusqueda(arr, 5, 0, a.raizArbol());

//    cout << a.recuperar(*a.raizArbol()) << endl;


    return 0;
}


