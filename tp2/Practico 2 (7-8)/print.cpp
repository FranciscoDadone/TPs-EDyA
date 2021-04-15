#include <queue>
#include <iostream>

void print(std::queue <int> &myqueue){
    std::queue <int> aux = myqueue;
    while (!aux.empty()) {           //copia para no modificar el original??
        std::cout << " " << aux.front();
        aux.pop();
    }
}
