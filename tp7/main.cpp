#include <iostream>
#include <list>
#include "FilaA.h"
#include <stack>
#include "pila_a.h"
#include "pila_p.h"

using namespace std;

/**
 * Prints stack in reverse order recursively.
 * @tparam T
 * @param s
 */
template <class T> void print(stack<T> s) {
    if (!s.empty()) {
        T element = s.top();
        s.pop();
        print(s);
        cout << element << " ";
        s.push(element);
    }
}

list<string> generarNBinarios(unsigned int n){
    FilaA <string> f;
    list<string> l;
    if(n==0){
        f.vaciar();
        for (unsigned int i=0; i<n ;i++){
            l.push_back(f.recuperarFrente());
            f.quitar();
        }
        return l;
    }
    else{
        f.poner("1");
        for(unsigned int i = 1; i< n; i++){
            string a = f.recuperarFrente();
            f.quitar();
            string b = a;
            f.poner(a.append("0"));
            f.poner(b.append("1"));
        }
        for(unsigned int i=0; i< n ;i++){
            l.push_back(f.recuperarFrente());
            f.quitar();
        }
        return l;
    }
}
void print(list<string> const &list)
{
    for (auto const &i: list) {
        cout << i << endl;
    }
}

string preToInfix(string pre_exp){
    int i,largo=pre_exp.size();
    string ret="";
    Stack<char> stk;
    for(i=0;i<largo;i++){
        if(pre_exp[i]!=' '){
            if(pre_exp[i]<48){
                ret+='(';
                stk.push(')');
                stk.push(pre_exp[i]);
            }
            else{
                while(pre_exp[i]!=' ' && i!=largo){
                    ret+=pre_exp[i];
                    i++;
                }
                if(i!=largo){
                    ret+=stk.top();
                    stk.pop();
                    while(stk.top()!=')'){
                        ret+=stk.top();
                        stk.pop();
                    }
                }
                else{
                    while(!stk.empty()){
                        ret+=stk.top();
                        stk.pop();
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
//    stack<int> s;
//
//    s.push(1);
//    s.push(2);
//    s.push(3);
//    s.push(4);
//    s.push(5);
//
//    print(s);
//
//    cout << "\n";
//
//    FilaA<int> f, g;
//    f.poner(1);
//    f.poner(2);
//    f.poner(3);
//    f.poner(4);
//    f.poner(5);
//    cout << f << endl;
//
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
//    print(generarNBinarios(2));
    /*
    const int k= f.cantidad();
    for(int i=0; i<k ;i++){
       cout<< f.recuperarFrente()<<endl;
       f.quitar();
    }
    */


    /*PilaA<int> num;
    num.apilar(1);
    num.apilar(2);
    num.apilar(3);
    num.apilar(4);
    num.apilar(5);
    swap(num);
    while(!num.estaVacia()){
        cout<<num.recuperarTope()<<endl;
        num.desapilar();
    }*/
    /*string x="* - A B / + C D * X Y";
    x=preToInfix(x);
    cout<<x;*/
//    Stack<int> x;
//    x.push(1);
//    x.push(2);
//    x.push(3);
//    x.push(4);
//    x.push(5);
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
