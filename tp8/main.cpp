#include <iostream>
#include "include/arbolbin.h"
#include <algorithm>
#include "arbol.h"
#include "include/arbol_test.h"


using namespace std;

int main() {

    ArbolBin<int> a;
    vector<int> arr = { 5, 4, 10, 1, 9 };


    Nodo<int>* *r=a.raizArbol();
//    a.asignarNodo(1, *r);
//    a.asignarNodo(2, *a.hijoIzq(*r));
//    a.asignarNodo(3, *a.hijoDer(*r));
//    a.asignarNodo(4, *a.hijoIzq(*a.hijoIzq(*r)));
//    a.asignarNodo(5, *a.hijoDer(*a.hijoIzq(*r)));
//    a.asignarNodo(6, *a.hijoDer(*a.hijoDer(*r)));



//    insertABB(a, arr);
    a.insertABB(arr);
//    Mostrar(a,*r,0);
//    test_abb(5, 10);
    listarPorNivel(a);



//    a.insertABB(arr);

//    cout << a.recuperar(*a.hijoDer(*a.raizArbol())) << endl;

//
//    cout << a.recuperar(*a.raizArbol()) << endl;
//    cout << a.recuperar(*a.hijoIzq(*a.raizArbol())) << endl;
//    cout << a.recuperar(*a.hijoIzq(*a.hijoIzq(*a.raizArbol()))) << endl;


//    test_abb(10, 5);

//    listarPostOrden(a);

//    cout << endl << endl << endl;
//    a.listarPostOrden();
//    cout << endl << contarNodosHojas(a) << endl;



    return 0;
}



