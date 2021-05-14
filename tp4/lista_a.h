#ifndef LISTAA_H
#define LISTAA_H

#ifndef EXIT_ERROR
	#define EXIT_ERROR 250
#endif

#include <iostream>
#include <cstdlib>

template<class T, unsigned short CANTELE=100>
class ListaA {
public:

    typedef int posicion;

    ListaA() {
        ultimo=-1;
        cant=0;
    };

    void insertar(T x, posicion p) {
        if((p>=0) && (p<=ultimo+1)) {
            int i;
            for(i=ultimo; i>=p; i--) {
                elementos[i+1] = elementos[i];
            }
            elementos[p] = x;
            ultimo++;
            cant++;
        } else {
            std::cerr << "\nHa intentado insertar en una posicion invalida\n";
            exit(EXIT_ERROR);
        }
    };

    void eliminar(posicion p) {
        if((p>=0) && (p<=ultimo)) {
            int i;
            for(i=p; i<ultimo; i++) {
                elementos[i] = elementos[i+1];
            }
            ultimo--;
            cant--;
        } else {
            std::cerr << "\nHa intentado eliminar en una posicion invalida\n";
            exit(EXIT_ERROR);
        }
    };

    int cantidad() {
        return(cant);
    };

    posicion localizar(T x) {
        int i;
        for(i=0; ((i<=ultimo)&&(elementos[i]!=x)); i++);
        return(i);
    };

    T recuperar(posicion p) {
        T result;
        if((p>=0) && (p<=ultimo))
            result = elementos[p];
        else {
            std::cerr << "\nHa intentado recuperar en una posicion invalida\n";
            exit(EXIT_ERROR);
        }
        return(result);
    };

    posicion siguiente(posicion p) {
        posicion result;
        if((p>=0) && (p<=ultimo)) {
                result=p+1;
        } else {
             std::cerr << "\nHa intentado encontrar el proximo de una posicion invalida\n";
            exit(EXIT_ERROR);
        }
        return(result);
    };

    posicion anterior(posicion p) {
        posicion result;
        if((p>0) && (p<=ultimo+1)) {
                result = p-1;
        } else {
            std::cerr << "\nHa intentado obtener el anterior de una posicion invalida\n";
            exit(EXIT_ERROR);
        }
        return(result);
    };

    posicion fin() {
        return(ultimo+1);
    };

    posicion primer() {
        return 0;
    };

    void vaciar() {
        ultimo = -1;
        cant = 0;
    }

    bool estaVacia() {
        return this->cantidad() == 0;
    }

    T recuperarPrimero() {
        return elementos[0];
    }

    T recuperarUltimo() {
        return elementos[cantidad() - 1];
    }

    void eliminarPrimerElemento() {
        this->eliminar(0);
    }

    void eliminarUltimoElemento() {
        this->eliminar(cantidad() - 1);
    }

    void insertarPrimero(T elemento) {
        insertar(elemento, 0);
    }

    void insertarUltimo(T elemento) {
        insertar(elemento, this->recuperarUltimo());
    }

    void intercambiar(ListaA<T> &lista2) {
        T aux[] = this->elementos;
        this->elementos = lista2;
        lista2 = aux;
    }

    void juntar(posicion pos, ListaA<T> &lista2) {
        if(pos > lista2.cantidad()) return;
        for(T elemento: this->elementos) {
            lista2.insertar(pos, elemento);
        }
    }

    void eliminarElemento(T elemento) {
        int i = 0;
        for(T e: this->elementos) {
            if(e == elemento) eliminar(i);
            i++;
        }
    }

    void unicos() {
        for(int i = 0; i < this->cantidad(); i++) {
            for(int j = i; j < this->cantidad() - 1; j++) {
                if(elementos[i] == elementos[j + 1]) this->eliminar(j + 1);
            }
        }
    }

protected:

private:
    T elementos[CANTELE];
    posicion ultimo;
    int cant;
};

void test_lista_a(){
    std::cout << std::endl << "Test lista array" << std::endl;
    int cantidad;
	ListaA<int> numeros;
	numeros.vaciar();

	for (cantidad=0;(cantidad<10);cantidad++)
			numeros.insertar(cantidad, numeros.fin());

	ListaA<int>::posicion pos=numeros.primer();
	while(pos!=numeros.fin()){
		std::cout << numeros.recuperar(pos) << "; ";
		pos=numeros.siguiente(pos);
	}
}

#endif // LISTAA_H