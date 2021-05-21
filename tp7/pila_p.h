#include"nodo.h"
template<class T>
class Stack {
public:
    typedef Nodo<T> *posicion;
    Stack(){
        tope=NULL;
    }
    ~Stack(){
        posicion reco = tope;
        while (reco != NULL){
            reco = reco->sig;
            pop();
        }
    }
    bool empty(){
        return tope==NULL;
    }
    unsigned int size(){
        posicion reco = tope;
        unsigned int cont=0;
        while (reco != NULL){
            reco = reco->sig;
            cont++;
        }
    return cont;
    }
    T top(){
        if(tope==NULL){
            std::cout<<"no hay un tope";
            exit(EXIT_FAILURE);
        }
        return tope->elemento;
    }
    void push(T x){
        posicion nuevo;
        nuevo = new Nodo<T>;
        nuevo->elemento = x;
        if (tope == NULL){
            tope = nuevo;
            nuevo->sig = NULL;
        }
        else{
            nuevo->sig = tope;
            tope = nuevo;
        }
    }
    void pop(){
        posicion sav=tope;
        if (tope!=NULL){
            tope=tope->sig;
            delete tope;//revisar
        }

    }
    private:
        posicion tope;
};














