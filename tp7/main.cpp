#include <iostream>
#include <list>
#include "filaa.h"

using namespace std;

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

int main()
{
  FilaA<int> f;
  f.poner(5);
  f.poner(6);
  f.poner(7);
  f.poner(8);
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
