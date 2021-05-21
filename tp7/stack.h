#include"nodo.h"

template<class T>
class stack {
public:
    typedef Nodo<T> *posicion;
    /**
     * Constructors and destructors
     */
    stack() {
        tope = NULL;
    }
    stack(stack& s) {
        tope = NULL;
        posicion temp = s.tope;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < (s.size() - i) - 1; j++) {
                temp = temp->sig;
            }
            push(temp->elemento);
            temp = s.tope;
        }
    }
    ~stack() {}  /* el liberado de memoria está en el pop() */

    /**
     * Returns if the stack is empty
     * @return bool
     */
    bool empty() {
        return tope == NULL;
    }
    /**
     * Returns the size
     * @return
     */
    unsigned int size() {
        posicion recolocar = tope;
        unsigned int cont = 0;
        while (recolocar != NULL){
            recolocar = recolocar->sig;
            cont++;
        }
    return cont;
    }
    /**
     * Returns the top element.
     * @return
     */
    T top() {
        if(tope == NULL) {
            std::cerr << "No hay un tope.";
            exit(EXIT_FAILURE);
        }
        return tope->elemento;
    }
    /**
     * Pushes a new element to the stack.
     * @param x
     */
    void push(T x){
        posicion nuevo = new Nodo<T>;
        nuevo->elemento = x;
        if (tope == NULL) {
            tope = nuevo;
            nuevo->sig = NULL;
        } else {
            nuevo->sig = tope;
            tope = nuevo;
        }
    }
    /**
     * Pops the top element.
     */
    void pop() {
        if (tope != NULL) {
            posicion sav = tope;
            tope = tope->sig;
            delete sav;
        }
    }

    /**
     * Equals operator
     * @param lhs
     * @param rhs
     * @return
     */
    friend bool operator == (stack& lhs, stack& rhs) {
        if(lhs.size() != rhs.size()) return false;
        while(lhs.tope != NULL) {
            if(lhs.tope->elemento != rhs.tope->elemento) return false;
            lhs.tope = lhs.tope->sig;
            rhs.tope = rhs.tope->sig;
        }
        return true;
    }

    /**
     * Not equal operator
     * @param lhs
     * @param rhs
     * @return
     */
    friend bool operator != (stack& lhs, stack& rhs) {
        return !(lhs == rhs);
    }

    /**
     * Print operator.
     * @param out
     * @param f
     * @return
     */
    friend std::ostream& operator << (std::ostream& out, stack& f) {
        posicion pos = f.tope;
        while(pos != NULL) {
            out << pos->elemento << " ";
            pos = pos->sig;
        }
        return out;
    }

private:
    posicion tope;
};














