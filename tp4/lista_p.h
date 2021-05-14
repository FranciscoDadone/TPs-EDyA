using namespace std;

template<class T>
class Nodo{
public:
    Nodo(){
        //cout<<endl<< "new Lista "<< this<<endl;//revisar estos
    }
    ~Nodo(){
        //cout<<endl<< "delete Lista "<< this<<endl;
    }
    T elemento;
    Nodo<T> *sig;
private:


};

template<class T>
class Lista_P{
public:
    typedef Nodo<T> *posicion;

    Lista_P(){
        primero=new Nodo<T>;
        ultimo=primero;
        primero->sig=NULL;
        cant=0;
    }
    posicion primer(){
        return primero;
    }
    posicion fin(){
        return ultimo;
    }
    posicion siguiente(posicion p){
        if(p==NULL or p==ultimo){
            cerr<<"Ha intentado encontrar el proximo de una posicion invalida";
            exit(EXIT_FAILURE);
        }
        return p->sig;
    }
    posicion anterior(posicion p){
        posicion q=primero;
        if(p!=NULL){
            if(p!=q){
                while(q->sig!=NULL and q->sig!=p){
                    q=q->sig;
                }
            }
        }
        else{
            cerr<<"Ha intentado encontrar el anterior de una posicion invalida";
            exit(EXIT_FAILURE);
        }
        return q;
    }

    void insertar(T x, posicion p){
        posicion sav;
        if(p!=NULL){
            sav=p->sig;
            p->sig=new Nodo<T>;
            p->sig->elemento=x;
            p->sig->sig=sav;
            if(p==ultimo){ultimo=p->sig;}
            cant++;
        }
        else{
          cerr<<"Ha intentado incertar un elemento en una posicion invalida";
            exit(EXIT_FAILURE);
        }
    }
    void eliminar(posicion p){
        posicion sav;
        if(p!=NULL and p!=ultimo){
            sav=p->sig;
            p->sig=p->sig->sig;
            if(sav==ultimo){ultimo=p;}
            delete sav;
            cant--;
        }
        else{
            cerr<<"Ha intentado eliminar un elemento en una posicion invalida";
            exit(EXIT_FAILURE);
        }
    }
    T recuperar (posicion p){
        if(p==NULL or p==ultimo){
            cerr<<"Ha intentado recuperar un elemento en una posicion invalida";
            exit(EXIT_FAILURE);
        }
        return p->sig->elemento;
    }
    void vaciar(){
        posicion q=primero;
        posicion sav;
        while(q->sig!=NULL){
            sav=q->sig;
            q->sig=q->sig->sig;
            delete sav;
        }
        ultimo=q;
        cant=0;
    }
    posicion localizar(T x){
        posicion q=primero;
        while(q->sig!=NULL and q->sig->elemento!=x){
            q=q->sig;
        }
        return q;
    }
    bool estaVacia(){
        return primero==ultimo;
    }
private:
    posicion primero,ultimo;
    unsigned int cant;
};
