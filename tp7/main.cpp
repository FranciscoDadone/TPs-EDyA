#include <iostream>
#include <stack>
#include "pila_a.h"
#include "pila_p.h"
using namespace std;
string preToInfix(string pre_exp);
int main()
{
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
    Stack<int> x;
    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);
    x.push(5);

    if(x.empty()){
        cout<<"esta vacia ["<<x.size()<<"]";
    }
    else{
        cout<<"no esta vacia ["<<x.size()<<"]";
    }
    while(!x.empty()){
        cout<<x.top()<<endl;
        x.pop();
    }
    return 0;
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
