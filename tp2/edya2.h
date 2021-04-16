/*************************
    Trabajo Práctico 2
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef EDYA2_H_INCLUDED
#define EDYA2_H_INCLUDED

#include <stack>
#include <vector>

using namespace std;

bool palindrome(const string& str);

//########### Ejercicio 1 #############
void metodo_at(const string& str){
    for (char i: str) cout << i << " ";
}
void operador_de_inter(const string& str){
    for(char i : str) cout << i << " ";
}
void iterador(const string& str){
    for (auto it = str.begin(); it != str.end(); ++it) cout << *it << " ";
}
void bucle_rang(const string& str) {
    for(char j: str) cout << j << " ";
}

//########### Ejercicio 2 #############
string palindromePyramid(const string& str) {
    string ret;
    if(!palindrome(str)) return "No es palíndromo.";

    int sav = (str.length() % 2 != 0) ? (str.length() / 2) : ((str.length() / 2) - 1),
        j = (str.length() % 2 != 0) ? 1 : 2;

    for(int i = sav; i >= 0; i--) { //genero el nuevo string
        ret.append(i, ' ');
        ret += str.substr(i, j) + "\n";
        j += 2;
    }
    return ret;
}

//########### Ejercicio 3 #############
string replaceAll(const string& str, const string& from, const string& to){
    if(from.empty()) return str;
    string ret;
    for(unsigned int i = 0; i < str.length(); i++) {
        ret += (str.substr(i, from.length()) == from) ? to : str.substr(i,1);
        if(str.substr(i, from.length()) == from) i += (from.length() - 1);
    }
    return ret;
}

// ## EJERCICIO 4 ## //
bool palindrome(const string& str) {
    if(str.empty()) return false;
    stack <char> s;
    for(char c: str) s.push(c);
    for(char character: str) {
        if(s.top() != character) return false;
        s.pop();
    }
    return true;
}

// ## EJERCICIO 5 ## //
vector<unsigned int> create(unsigned int N, unsigned int from, unsigned int to) {
    if(from > to) return {};
    vector<unsigned int> v;
    for(unsigned int i = 0; i < N; i++) v.push_back(rand() % ((to - from) + 1) + from);
    return v;
}

enum format { FMT_LIST, FMT_LINE };
void print(vector<unsigned int> v, format f=FMT_LIST) {
    for(unsigned int i = 0; i < (unsigned int)v.size(); i++) {
        cout << v.at(i) << ((f == FMT_LINE && i != (v.size() - 1)) ? ", " : "\n");
    }
}

void sort(vector<unsigned int> &v) {
    if(v.empty()) return;
    for(unsigned int i = 0; i <= v.size(); i++) {
        bool cont = false;          // para optimizar en tiempo de ejecución
        for(unsigned int j = 0; j < (v.size() - 1); j++) {
            if(v[j] > v[j + 1]) {
                unsigned int temp = v[j];
                v[j]              = v[j + 1];
                v[j + 1]          = temp;
                cont = true;        // si hubo un cambio...
            }
        }
        if(!cont) break;
    }
}

vector<unsigned int> insert(vector<unsigned int> v1, vector<unsigned int> v2, unsigned int pos) {
    if(v1.empty()) return v2;
    vector<unsigned int> merged;

    bool cpyV2 = false;
    unsigned int v2VectorIndex = 0, v1VectorIndex = 0;
    for(unsigned int i = 0; i < (unsigned int)(v1.size() + v2.size()); i++) {
        if(i == pos) cpyV2 = true;
        merged.push_back((cpyV2 && v2VectorIndex < v2.size()) ? v2.at(v2VectorIndex) : v1.at(v1VectorIndex));
        (cpyV2 && v2VectorIndex < v2.size()) ? v2VectorIndex++ : v1VectorIndex++;
    }
    return merged;
}

void print_frequency(vector<unsigned int> v) {
    vector<unsigned int> numbers;
    for(unsigned int i = 0; i < v.size(); i++) {
        if(!count(numbers.begin(), numbers.end(), v.at(i))) {
            cout << v.at(i) << " : " << count(v.begin(), v.end(), v.at(i)) << endl;
            numbers.push_back(v.at(i));
        }
    }
}

// ## EJERCICIO 7 ## //
void print(std::queue <int> &myqueue){
    queue<int> aux = myqueue; // para no modificar el original
    while (!aux.empty()) {
        cout << aux.front() << " ";
        aux.pop();
    }
}

// ## EJERCICIO 8 ## //
std::queue<int>& reverse(std::queue <int> &myqueue){
    stack<int> s;
    while (!myqueue.empty()) {
        s.push (myqueue.front());
        myqueue.pop();
    }
    while (!s.empty()) {
        myqueue.push(s.top());
        s.pop();
    }
    return myqueue;
}

#endif // EDYA2_H_INCLUDED
