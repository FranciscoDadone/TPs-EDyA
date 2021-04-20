#include <iostream>
#include "point.h"

using namespace std;

int main() {

    // # Ejercicio 1 # //
    Point a;
    cout << a.getX() << " " << a.getY() << endl;
    a.setX(10);
    a.setY(20);
    cout << a.getX() << " " << a.getY() << endl;

    Point b(40,50);
    cout << b.getX() << " " << b.getY() << endl;

    return 0;
}
