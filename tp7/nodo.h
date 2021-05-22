/*************************
    Trabajo Práctico 7
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

template<class T>
class Nodo{
public:
    Nodo(){
        //cout<<endl<< "new Lista "<< this<<endl;
    }
    ~Nodo(){
        //cout<<endl<< "delete Lista "<< this<<endl;
    }
    T elemento;
    Nodo<T> *sig;
private:

};
