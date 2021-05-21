#include <iostream>
#include <stack>
#include "FilaA.h"

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

    return 0;
}
