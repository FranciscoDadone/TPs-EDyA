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
    /*
    Polygon defaultConstructor;
    cout << defaultConstructor << endl;
    */
    /*
    Polygon withPoints({
        {1,1},
        {2, 3},
        {5, 9}
    });
    cout << withPoints << endl;
    */
    /*
    Polygon invalidPolygon({
        {1,1},
        {1,2},
        {1,3}
    }); // como es inválido, genera un polígono por defecto.
    cout << invalidPolygon << endl;
    */
    /*
    Polygon demo;
    demo.addPoint({1,2});
    demo.addPoint({3,4});
    demo.addPoint({5,6});
    cout << demo << endl;
    cout << demo.getPoints().at(0) << endl;
    cout << demo.getNumberOfPoints() << endl;
    cout << demo.getPoint(1) << endl;
    demo.addPoint({6,7});
    cout << demo << endl;
    demo.removePoint(3);
    cout << demo << endl;
    demo.setPoint(1, {0,0});
    cout << demo << endl;
    */

    Polygon a({
        {10,20},
        {30,1},
        {99,7},
        {1,2},
        {4,3}
    });
    Polygon b({
        {1,2},
        {3,1},
        {9,1},
        {1,4},
        {4,3}
    });
    cout << "a:     " << a << endl;
    cout << "b:     " << b << endl;
    cout << "a + b: " << (a + b) << endl;
    cout << "a - b: " << (a - b) << endl;
    cout << "a * 2: " << (a * 2) << endl;
    cout << "b / 2: " << (b / 2) << endl;

    return 0;
}
