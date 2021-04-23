#include <iostream>
#include "point.h"
#include "polygon.h"

using namespace std;

int main() {

    // # Ejercicio 1 # //
    /*
    Point<int> a;
    cout << a << endl;
    a.setX(10);
    a.setY(20);
    cout << a << endl;

    Point<double> b(40,50);
    cout << b << endl;
    */

    // # Ejercicio 2 # //
    /*
    Polygon<int> defaultConstructor;
    cout << defaultConstructor << endl;
    */
    /*
    Polygon<int> withPoints({
        {1,1},
        {2, 3},
        {5, 9}
    });
    cout << withPoints << endl;
    */
    /*
    Polygon<int> invalidPolygon({
        {1,1},
        {1,2},
        {1,3}
    }); // como es inválido, genera un polígono por defecto.
    cout << invalidPolygon << endl;
    Polygon<int> voidPolygon(NULL);
    cout << voidPolygon << endl;
    */
    /*
    Polygon<int> demo;
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
    /*
    Polygon<int> a({
        {10,20},
        {30,1},
        {99,7},
        {1,2},
        {4,3}
    });
    Polygon<int> b({
        {1,2},
        {3,1},
        {9,1},
        {1,4},
        {4,3}
    });
    cout << "a:     " << a << endl;
    cout << "b:     " << b << endl;
    Polygon<int> j = a + b;
    cout << "a + b: " << j << endl;
    j = a - b;
    cout << "a - b: " << j << endl;
    j = a * 2;
    cout << "a * 2: " << j << endl;
    j = a / 2;
    cout << "b / 2: " << j << endl;
    */
    return 0;
}
