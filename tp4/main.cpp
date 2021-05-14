#include <iostream>
#include <stack>
#include"lista_a.h"
#include"lista_p.h"
using namespace std;
#define Lista Lista_P


void insertarOrdenado(Lista<string> &listaOrdenada, string entrada){
    listaOrdenada.insertar(entrada,listaOrdenada.fin());
}
template <class T>
void invertir(Lista<T> &aInvertir){
    stack<T> p;
    while (aInvertir.primer()!=aInvertir.fin()){
        p.push(aInvertir.recuperar(aInvertir.primer()));
        aInvertir.eliminar(aInvertir.primer());
    }
    while (!p.empty()){
        aInvertir.insertar(p.top(),aInvertir.fin());
        p.pop();
    }
}
int main()
{
    Lista<string> num;
    insertarOrdenado(num,"gato");
    insertarOrdenado(num,"perro");
    insertarOrdenado(num,"toro");
    insertarOrdenado(num,"serpiente");
    invertir(num);
    while(num.primer()!=num.fin()){
        cout<<num.recuperar(num.primer())<<endl;
        num.eliminar(num.primer());
    }


    return 0;
}

