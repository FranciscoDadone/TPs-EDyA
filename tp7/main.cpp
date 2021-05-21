#include <iostream>
#include <list>
#include "FilaA.h"
#include <stack>
#include "PilaA.h"
#include "stack.h"

/**
 * Prints stack in reverse order recursively.
 * @tparam T
 * @param s
 */
template<class T>
void print(stack<T> s) {
    if (!s.empty()) {
        T element = s.top();
        s.pop();
        print(s);
        std::cout << " | " << element;
        s.push(element);
    }
}

/**
 * 1) ¿Por qué es importante implementar el constructor de copia en stack del ejercicio 2?
 * Es importante implementar este constructor ya que de otra forma no se podría asignar
 * un stack a otro stack de manera "sencilla".
 *
 * 2) ¿Qué otros operadores considera apropiado implementar? En caso afirmativo programe los
 *    operadores correspondientes.
 *    Es apropiado implementar los operadores de igualdad, desigualdad y el cout.
 */

std::list<std::string> generarNBinarios(unsigned int n) {

    FilaA<std::string> f;
    std::list<std::string> l;

    if (!n) {
        return l;
    } else {
        f.poner("1");
        for (unsigned int i = 1; i < n; i++) {
            std::string a = f.recuperarFrente();
            if(f.cantidad() != 1) f.quitar();
            std::string b = a;
            f.poner(a.append("0"));
            f.poner(b.append("1"));
        }


        for (unsigned int i = 0; i < n; i++) {
            l.push_back(f.recuperarFrente());
            f.quitar();
        }
        return l;
    }
}

void print(std::list<std::string> const &list) {
    for (auto const &i: list) {
        std::cout << i << std::endl;
    }
}
/**
 * To prefix notation.
 * @param pre_exp
 * @return
 */
std::string preToInfix(std::string pre_exp) {
    int i,
            largo = pre_exp.size();
    std::string ret = "";
    stack<char> ope;
    for (i = 0; i < largo; i++) {
        if (pre_exp[i] != ' ') {
            if (pre_exp[i] < 48) {
                ret += '(';
                ope.push(')');
                ope.push(pre_exp[i]);
            } else {
                while (pre_exp[i] != ' ' && i != largo) {
                    ret += pre_exp[i];
                    i++;
                }
                if (i != largo) {
                    ret += ope.top();
                    ope.pop();
                    while (ope.top() != ')') {
                        ret += ope.top();
                        ope.pop();
                    }
                } else {
                    while (!ope.empty()) {
                        ret += ope.top();
                        ope.pop();
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
//    std::stack<int> s;
//
//    s.push(1);
//    s.push(2);
//    s.push(3);
//    s.push(4);
//    s.push(5);
//
//    print(s);

//    stack<int> s;
//    s.push(1);
//    s.push(2);
//    s.push(3);
//    s.push(4);
//    s.push(5);
//    print(s);

//    stack<int> a;
//    a.push(1);
//    a.push(2);
//    a.push(3);
//    stack<int> b(a);
//
//    a.pop();
//    std::cout << a << std::endl;
//    std::cout << b << std::endl;


//
//    cout << "\n";
//
//    FilaA<int> f, g;
//    f.poner(1);
//    f.poner(2);
//    f.poner(3);
//    f.poner(4);
//    f.poner(5);
//
//    std::cout << f << std::endl;
//    f.invertir();
//    std::cout << f << std::endl;

//    std::cout << f << std::endl;



//    g.poner(1);
//    g.poner(2);
//    g.poner(3);
//    g.poner(4);
//    g.poner(5);
//
//    cout << (f == g) << endl;
//    cout << (f != g) << endl;


    //cout<<f.recuperarUltimo()<<endl;
    //f.quitarN(2);
    //f.ponerAlFrente(15);
    //f.ponerAlFrente(15);
    // f.ponerAlFrente(15);
    //f.ponerAlFrente(15);
    //f.invertir();
    print(generarNBinarios(7));
    /*
    const int k= f.cantidad();
    for(int i=0; i<k ;i++){
       cout<< f.recuperarFrente()<<endl;
       f.quitar();
    }
    */

    /*
    PilaA<int> num, num1;
    num.apilar(1);
    num.apilar(2);
    num.apilar(3);
    num.apilar(4);
    num.apilar(5);
    num.apilar(6);
    num.apilar(7);

    num1.apilar(6);
    num1.apilar(7);
    num1.apilar(8);
    num1.apilar(9);
    num1.apilar(10);
    num1.apilar(11);
    num1.apilar(12);
    num1.swap(num);

    while(!num1.estaVacia()){
        cout << num1.recuperarTope() << endl;
        num1.desapilar();
    }
    */


    /*string x="* - A B / + C D * X Y";
    x=preToInfix(x);
    cout<<x;*/
//    stack<int> x, y;
//    x.push(1);
//    x.push(2);
//    x.push(3);
//    x.push(4);
//    x.push(5);
//
//    y.push(1);
//    y.push(2);
//    y.push(3);
//    y.push(4);
//    y.push(5);
//
//    std::cout << (x != y) << std::endl;
//    std::cout << x;
//
//    if(x.empty()){
//        cout<<"esta vacia ["<<x.size()<<"]";
//    }
//    else{
//        cout<<"no esta vacia ["<<x.size()<<"]";
//    }
//    while(!x.empty()){
//        cout<<x.top()<<endl;
//        x.pop();
//    }


    return 0;
}
