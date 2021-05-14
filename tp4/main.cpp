#include <iostream>
#include "graph_list.h"
#include <iostream>
#include <stack>
#include "lista_p.h"
#include "lista_a.h"

#define Lista ListaA
//#define Lista ListaP
using namespace std;

/**
 * Ejercicio 1
 * @param listaOrdenada
 * @param entrada
 */
void insertarOrdenado(Lista<std::string> &listaOrdenada, std::string entrada){
    listaOrdenada.insertar(entrada,listaOrdenada.fin());
}

/**
 * Ejercicio 2
 * @tparam T
 * @param aInvertir
 */
template <class T>
void invertir(Lista<T> &aInvertir){
    std::stack<T> p;
    while (aInvertir.primer()!=aInvertir.fin()){
        p.push(aInvertir.recuperar(aInvertir.primer()));
        aInvertir.eliminar(aInvertir.primer());
    }
    while (!p.empty()){
        aInvertir.insertar(p.top(),aInvertir.fin());
        p.pop();
    }
}

/**
 * Ejercicio 3 A
 * @tparam T
 * @param l1
 * @param l2
 * @return
 */
template <class T>
Lista<T> mixList (Lista<T> l1 ,Lista<T> l2){
    Lista<T>aux;
    Lista<std::string>::posicion p1=l1.primer(),p2=l2.primer();
    int sav1=l1.cantidad();
    int sav2=l2.cantidad();
    while(aux.cantidad()!=l1.cantidad()+l2.cantidad()){
        if(sav1!=0){
            aux.insertar(l1.recuperar(p1),aux.fin());
            p1=l1.siguiente(p1);
            sav1--;
        }
        if(sav2!=0){
            aux.insertar(l2.recuperar(p2),aux.fin());
            p2=l2.siguiente(p2);
            sav2--;
        }
    }
    return aux;
}






int main() {
    /*
    GraphList<int> a;
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    a.addNode(4);
    a.addEdge(2,3);
    a.addEdge(2,5);
    a.print();
    std::cout << "2 and 5 connected: " << a.isConnected(2, 5) << std::endl;
    std::cout << "2 and 1 connected: " << a.isConnected(2, 1) << std::endl;
    */

    /*
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
     */

    ListaA<int> l;
    l.insertarPrimero(1);
    l.insertarPrimero(2);
    l.insertarPrimero(3);
    l.insertarPrimero(4);

    l.insertarPrimero(6);
    for(int i = 0; i < l.cantidad(); i++) {
        cout << l.recuperar(i) << endl;
    }

    //cout << l.eliminarPrimerElemento() << endl;



    return 0;
}
