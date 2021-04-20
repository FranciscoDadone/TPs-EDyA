#include <iostream>
#include "point.h"
#include "polygon.h"

using namespace std;

int main() {

    // # Ejercicio 1 # //
    /*
    Point a;
    cout << a.getX() << " " << a.getY() << endl;
    a.setX(10);
    a.setY(20);
    cout << a.getX() << " " << a.getY() << endl;

    Point b(40,50);
    cout << b.getX() << " " << b.getY() << endl;
    */


    // # Ejercicio 2 # //

    Polygon a({{1,1}, {1,2}, {3,4}});
    Polygon b({{2,2}, {2,3}, {4,5}});

    Polygon c = a+b;

    cout << c.getPoints().at(1) << endl;


    return 0;
}
