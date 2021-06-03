// Copyright [2019] <Estructura de Datos y Algoritmos>

#include <iostream>
#include <string>

#define EXIT_ERROR 255


/**
 * @brief Imprime mensaje de error y finaliza el programa
 * @param mensaje
 * @param cod
 */
void error(const std::string &mensaje, int cod) {
    std::cerr << mensaje;
    exit(cod);
}

template<class T>
struct Nodo {
 public:
    T elemento;
    Nodo<T> *HIzq;
    Nodo<T> *HDer;
};


template<class T>
class ArbolBin{
 private:
        Nodo<T> *raiz;
        void talarR(Nodo<T> *pos);
 public:
        ArbolBin();
        Nodo<T>* padre(Nodo<T>*, Nodo<T>*);
        Nodo<T>* *hijoIzq(Nodo<T>*);
        Nodo<T>* *hijoDer(Nodo<T>*);
        T recuperar(Nodo<T>*);
        Nodo<T>* *raizArbol();
        void asignarNodo(const T &, Nodo<T>* &);
        void modificarDato(const T &, Nodo<T>*);
        void talar();
        void insertABB(T arr[]);
};

template<class T>
ArbolBin<T>::ArbolBin() {
    raiz = nullptr;
}

template<class T>
Nodo<T>* *ArbolBin<T>::raizArbol() {
    return &raiz;
}

template<class T>
void ArbolBin<T>::asignarNodo(const T &x, Nodo<T>* &p) {
    if (p == nullptr) {
        p = new Nodo<T>;
        if (p) {
            p->HDer = p->HIzq = nullptr;
            p->elemento = x;
        }
    } else {
        p->elemento = x;
    }
}

template<class T>
Nodo<T>* ArbolBin<T>::padre(Nodo<T> *p, Nodo<T> *A) {
    Nodo<T> *R;
    if ((A == nullptr) || (p == nullptr)) {
        R = nullptr;
    } else {
        if (A->HIzq == p || A->HDer == p) {
            R = A;
        } else {
            R = padre(p, A->HIzq);
            if (R == nullptr)
                R = padre(p, A->HDer);
        }
    }
    return R;
}

template<class T>
Nodo<T>* *ArbolBin<T>::hijoIzq(Nodo<T> *p) {
    if (p == nullptr)
        error("Ha intentado obtener el hijo izq. de un nodo inexistente",
        EXIT_ERROR);
    return &(p->HIzq);
}

template<class T>
Nodo<T>* *ArbolBin<T>::hijoDer(Nodo<T> *p) {
    if (p == nullptr)
        error("Ha intentado obtener el hijo der. de un nodo inexistente",
        EXIT_ERROR);
    return &(p->HDer);
}

template<class T>
T ArbolBin<T>::recuperar(Nodo<T> *p) {
    T r;
    if (p)
        r = p->elemento;
    else
        error("Ha intentado recuperar en una posicion inexistente", EXIT_ERROR);
    return r;
}

template<class T>
void ArbolBin<T>::modificarDato(const T &x, Nodo<T> *p) {
    if (p)
        p->elemento = x;
    else
        error("Ha intentado modificar en una posicion inexistente", EXIT_ERROR);
}

template<class T>
void ArbolBin<T>::talar() {
    if (raiz) {
        talarR(raiz);
        delete raiz;
        raiz = nullptr;
    }
}

template<class T>
void ArbolBin<T>::talarR(Nodo<T> *p) {
    if (p) {
        if (p->HIzq) {
            talarR(p->HIzq);
            delete p->HIzq;
            p->HIzq = nullptr;
        }
        if (p->HDer) {
            talarR(p->HDer);
            delete p->HDer;
            p->HDer = nullptr;
        }
    }
}

template<class T>
void ArbolBin<T>::insertABB(T arr[]) {
    for(int i = 0; i <= (sizeof(arr)/sizeof(*arr)); i++) {
        if(this->raiz == NULL) {
            this->asignarNodo(arr[i], this->raiz);
        } else {
            Nodo<T> * temp = this->raiz;
            while(temp != NULL) {
                if(arr[i] == temp->elemento) return;
                else if(arr[i] < temp->elemento && temp->HIzq == NULL) {
                    this->asignarNodo(arr[i], *this->hijoIzq(temp));
                    break;
                } else if(arr[i] < temp->elemento) {
                    temp = temp->HIzq;
                } else if(arr[i] > temp->elemento && temp->HDer == NULL) {
                    this->asignarNodo(arr[i], *this->hijoDer(temp));
                    break;
                } else temp = temp->HDer;
            }
        }
    }
}
