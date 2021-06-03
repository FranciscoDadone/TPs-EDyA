#include <iostream>
#include "include/arbolbin.h"
#include <algorithm>
#include "arbol.h"

using namespace std;


int main() {

    int arr[] = { 5, 4, 3 };
    ArbolBin<int> a;

//    insertABB(a, arr);
//    a.insertABB(arr);
//
//    cout << a.recuperar(*a.raizArbol()) << endl;
//    cout << a.recuperar(*a.hijoIzq(*a.raizArbol())) << endl;
//    cout << a.recuperar(*a.hijoIzq(*a.hijoIzq(*a.raizArbol()))) << endl;


    test_abb(10, 5);


    return 0;
}


