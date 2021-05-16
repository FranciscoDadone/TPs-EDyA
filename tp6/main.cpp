/*************************
    Trabajo Práctico 6
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#include <iostream>
#include "graph_list.h"
#include <iostream>
#include <stack>
#include "lista_p.h"
#include "lista_a.h"

#define Lista ListaP
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

    Lista<int> l, k;
    for(int i = 0; i < 5; i++) {
        l.insertar(i, l.fin());
    }
    for(int i = 5; i < 15; i++) {
        k.insertar(i, k.fin());
    }
    l.insertar(1, l.primer());
    l.insertar(1, l.primer());

    Lista<int>::posicion p1 = l.primer(), p2 = k.primer();
    cout << "Lista l" << endl;
    for(int i = 0; i < l.cantidad(); i++) {
        cout << l.recuperar(p1) << endl;
        p1 = l.siguiente(p1);
    }
    cout << "Lista k" << endl;
    for(int i = 0; i < k.cantidad(); i++) {
        cout << k.recuperar(p2) << endl;
        p2 = k.siguiente(p2);
    }
    cout << "-----------------------" << endl;


    /*
    Lista<int> j = l.mixList(k);

    Lista<int>::posicion p2 = j.primer();
    for(int i = 0; i < j.cantidad(); i++) {
        cout << j.recuperar(p2) << endl;
        p2 = j.siguiente(p2);
    }*/


    //p2 = k.primer();
    //l.juntar(p2, k);
    //k.insertar(14, k.fin());
    //k.unicos();
    //l.eliminarElemento(1);
    //l.intercambiar(k);


    //l.unicos();

    p1 = l.primer();
    cout << "Lista l" << endl;
    for(int i = 0; i < l.cantidad(); i++) {
        cout << l.recuperar(p1) << endl;
        p1 = l.siguiente(p1);
    }
    cout << "Lista k" << endl;
    p2 = k.primer();
    for(int i = 0; i < k.cantidad(); i++) {
        cout << k.recuperar(p2) << endl;
        p2 = k.siguiente(p2);
    }


    //cout << l.eliminarPrimerElemento() << endl;



    return 0;
}
