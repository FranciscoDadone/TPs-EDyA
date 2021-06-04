#include <iostream>
#include<stack>
#include"arbol.h"
using namespace std;
template<class T>
void listarPostOrden(ArbolBin<T> &);
template<class T>
size_t contarNodosHojas(ArbolBin<T> &);
template<class T>
void recorrer(ArbolBin<T> &,Nodo<T>*);
template<class T>
size_t contH(ArbolBin<T> & a,Nodo<T>*n, size_t c);

int main()
{
    ArbolBin<char> x;
    x.asignarNodo('A',*x.raizArbol());
    x.asignarNodo('B',*x.hijoDer(*x.raizArbol()));
    x.asignarNodo('C',*x.hijoIzq(*x.raizArbol()));
    x.listarPostOrden();
    cout<<endl<<contarNodosHojas(x);
    return 0;
}

template<class T>
void listarPostOrden(ArbolBin<T> & arbol){
    recorrer(arbol,*arbol.raizArbol());
}
template<class T>
size_t contarNodosHojas(ArbolBin<T> &arbol){
    return contH(arbol,*arbol.raizArbol(),0);
}
template<class T>
void recorrer(ArbolBin<T> & a,Nodo<T>*n){
    if(n!=nullptr){
        recorrer(a,*a.hijoIzq(n));
        recorrer(a,*a.hijoDer(n));
        cout<<" "<<a.recuperar(n);
    }
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
