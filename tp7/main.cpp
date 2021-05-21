#include <iostream>
#include <stack>

using namespace std;

/**
 * Prints stack in reverse order recursively.
 * @tparam T
 * @param s
 */
template <class T> void print(stack<T> s) {
    if (!s.empty()) {
        int element = s.top();
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



    return 0;
}
