/*************************
    Trabajo Práctico 3
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#include <iostream>
#include <chrono>
#include "point.h"
#include "polygon.h"
#include "counter.h"
#include "hour.h"
#include "fraction.h"
#include "date.h"

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
    cin >> a;
    cout << a << endl;
    */

    // # Ejercicio 2 # //
    /*
    Counter c, c3;
    cout << "C " << c << endl;
    Counter c1(c);
    cout<<"C1 "<< c1<< endl;
    Counter c2(88);
    cout<<"C2 "<< c2<< endl;
    c3=9;
    c2=c3;
    ++c2;
    c1++;
    cout<<"C3 "<< c3<<c2<<c1<<endl;
    c3+=5;
    cout<<"C3 "<< c3;
    */
    // # Ejercicio 3 # //
    /*
    Hour x(21,30,29);
    Hour y(20,30,29);
    Hour z;
    x.setMinuto(2);
    z=x+y;
    cout << y << "   " << x << "   " << z << endl;
    cout << (x >= y) << endl;
    */

    // # Ejercicio 4 # //
    /*
    Fraction<int> f(20,24);
    cout << f << endl;
    Fraction <int> g (3,5);
    Fraction <int> r;
    float z;
    string x;
    z=f.toFloat();
    cout<<z<<endl;
    cout << f << endl;
    if (f.simplify()){
        cout<<"es simplificable" << endl;
    }
    else{
        cout<<"no es simplificable" << endl;
    }
    cout << f << endl;
    r=f+g;
    cout<<endl<<r;
    cout<<endl<<f;
    cout<<endl<<g;
    cout << endl << g.toString();
    */

    // # Ejercicio 5 # //
    /*
    Date a("10/10/2001");
    Date b("11/10/2001");
    cout << (b<a) << endl;
    cout << (b>a) << endl;

    Date c;
    cin >> c;
    cout << (c == b) << endl;
    cout << (c != b) << endl;
    cout << (c < b) << endl;
    cout << (c > b) << endl;
    */

    // # Ejercicio 6 # //
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
    cout << "a: " << a << endl;

    Polygon<int> c({
        {0,0},
        {0,2},
        {2,2},
        {2,0}
    });
    cout << c.getArea() << endl;
    cout << c.getPerimeter() << endl;
    cout << c.getAngleSum() << endl;
    cout << c.getNumberOfDiagonals() << endl;
    */

    return 0;
}