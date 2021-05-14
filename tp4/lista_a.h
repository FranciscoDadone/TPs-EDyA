using namespace std;
template<class T, unsigned int CANT=100>
class Lista_A{
public:
    typedef int posicion;
    Lista_A(){
        ultimo=-1;
        cant=0;
    }
    posicion primer(){
        return 0;
    }
    posicion fin(){
        return ultimo+1;
    }
    posicion siguiente(posicion p){
        posicion ret;
        if(p<0 or p>ultimo){
            cerr<<"Ha intentado encontrar el proximo de una posicion invalida";
            exit(EXIT_FAILURE);
        }
        return p+1;
    }
    posicion anterior(posicion p){
    if(p<=0 or p>ultimo+1){
        cerr<<"Ha intentado encontrar el anterior de una posicion invalida";
        exit(EXIT_FAILURE);
    }
    return p-1;
    }
    void insertar(T x,posicion p){
        if (p>=0 and p<=ultimo+1){
            for(int i=ultimo;i>=p;i--){
                elemento[i+1]=elemento[i];
            }
            elemento [p]=x;
            ultimo++;
            cant++;
        }
        else{
            cerr<<"Ha intentado incertar un elemento en una posicion invalida";
            exit(EXIT_FAILURE);
        }
    }
    void eliminar(posicion p){
        if(p>=0 and p<=ultimo){
            for (int i=p;i<ultimo;i++){
                elemento[i]=elemento[i+1];
            }
            ultimo--;
            cant--;
        }
        else{
            cerr<<"Ha intentado eliminar un elemento en una posicion invalida";
            exit(EXIT_FAILURE);
        }
    }
    T recuperar(posicion p){
        if(p<0 or p>ultimo){
             cerr<<"Ha intentado recuperar un elemento en una posicion invalida";
            exit(EXIT_FAILURE);
        }
        return elemento[p];
    }
    int cantidad(){
        return cant;
    }
    void vaciar(){
        ultimo=-1;
        cant=0;
    }
    posicion localizar(T x){
        int i;
        for (i=0;(i<=ultimo)and(elemento[i]!=x);i++);
        if(i==ultimo+1){//revisar
            i=-1;
        }
        return(i);
    }
private:
    T elemento[CANT];
    int ultimo,cant;
};

