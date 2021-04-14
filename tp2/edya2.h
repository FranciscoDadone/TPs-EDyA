#ifndef EDYA2_H_INCLUDED
#define EDYA2_H_INCLUDED

#include <stack>
#include <vector>

using namespace std;

// ## EJERCICIO 4 ## //

bool palindrome(const string& str) {
    stack <char> s;

    for(char c: str) s.push(c);

    unsigned short int i = 0;
    while(!s.empty()) {
        if(s.top() != str[i]) return false;
        s.pop();
        i++;
    }
    return true;
    // Agregue el correspondiente control al EJERCICIO 2 para
    // solo construir la pirámide en el caso de que la entrada sea palíndroma.
}


// ## EJERCICIO 5 ## //

vector<unsigned int> create(unsigned int N, unsigned int from, unsigned int to) {
    vector<unsigned int> v;
    while(N != 0) {
        v.push_back(rand() % ((to - from) + 1) + from);
        N--;
    }
    return v;
}

enum format { FMT_LIST, FMT_LINE };
void print(vector<unsigned int> v, format f=FMT_LIST) {
    for(unsigned int i = 0; i < (unsigned int)v.size(); i++) {
        cout << v.at(i) << ((f == FMT_LINE && i != (v.size() - 1)) ? ", " : "\n");
    }
}

void sort(vector<unsigned int> &v) {
    for(unsigned int i = 0; i <= v.size(); i++) {
        bool cont = false;
        for(unsigned int j = 0; j < (v.size() - 1); j++) {
            if(v[j] > v[j + 1]) {
                unsigned int temp = v[j];
                v[j]              = v[j + 1];
                v[j + 1]          = temp;
                cont = true;
            }
        }
        if(!cont) break;
    }
}

vector<unsigned int> insert(vector<unsigned int> v1, vector<unsigned int> v2, unsigned int pos) {
    vector<unsigned int> merged;
    if(!v1.size()) return merged;

    bool cpyV2 = false;
    unsigned int v2VectorIndex = 0,
                 v1VectorIndex = 0;
    for(unsigned int i = 0; i < (unsigned int)(v1.size() + v2.size()); i++) {
        if(i == pos) cpyV2 = true;

        merged.push_back((cpyV2 && v2VectorIndex < v2.size()) ?
                         v2.at(v2VectorIndex) : v1.at(v1VectorIndex));
        if(cpyV2 && v2VectorIndex < v2.size()) v2VectorIndex++;
        else                                   v1VectorIndex++;
    }
    return merged;
}

void print_frequency(vector<unsigned int> v) {
    vector<unsigned int> numbers;
    for(unsigned int i = 0; i < v.size(); i++) {
        unsigned int ocurr = 0;
        for(unsigned int j = i; j < v.size(); j++)
            if(v.at(i) == v.at(j)) ocurr++;
        if(!count(numbers.begin(), numbers.end(), v.at(i))) {
            cout << v.at(i) << " : " << ocurr << endl;
            numbers.push_back(v.at(i));
        }
    }
}

#endif // EDYA2_H_INCLUDED
