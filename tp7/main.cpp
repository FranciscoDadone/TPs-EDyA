#include <iostream>
#include <list>
#include "FilaA.h"
#include <stack>

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

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);

    cout << "\n";

    FilaA<int> f, g;
    f.poner(1);
    f.poner(2);
    f.poner(3);
    f.poner(4);
    f.poner(5);
    cout << f << endl;

    g.poner(1);
    g.poner(2);
    g.poner(3);
    g.poner(4);
    g.poner(5);

    cout << (f == g) << endl;
    cout << (f != g) << endl;


  //cout<<f.recuperarUltimo()<<endl;
  //f.quitarN(2);
  //f.ponerAlFrente(15);
  //f.ponerAlFrente(15);
  // f.ponerAlFrente(15);
  //f.ponerAlFrente(15);
  //f.invertir();
  print(generarNBinarios(2));
  /*
  const int k= f.cantidad();
  for(int i=0; i<k ;i++){
     cout<< f.recuperarFrente()<<endl;
     f.quitar();
  }
  */


    return 0;
}
