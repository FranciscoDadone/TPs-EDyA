#include <iostream>
#include <math.h>
#include "date.h"
#include "card.h"
#include "word.h"

using namespace std;

int main()
{

    // ## EJERCICIO 1 ## //
    /*
    Month m = DECEMBER;
    cout << "Mes siguiente: " << next(m)     << endl;
    cout << "Mes anterior:  " << previous(m) << endl;
    cout << "to_int(m):     " << to_int(m)   << endl;
    cout << "to_str(m):     " << to_str(m)   << endl;
    cout << "to_month(m):   " << to_month(m) << endl;
    */


    // ## EJERCICIO 2 ## //
    /*
    Date d = {29, FEBRUARY, 2020};
    cout << "to_str(d):                   " << to_str(d)                  << endl;
    cout << "to_date('11/10/2021').day:   " << to_date((char*)("11/10/2021")).day   << endl;
    cout << "to_date('11/10/2021').month: " << to_date((char*)("11/10/2021")).month << endl;
    cout << "to_date('11/10/2021').year:  " << to_date((char*)("11/10/2021")).year  << endl;
    cout << "leapYear(d):                 " << leapYear(d)                << endl;
    cout << "isValidDate(d):              " << isValidDate(d)             << endl;
    Date d1 = {26, OCTOBER, 2010};
    Date d2 = {26, OCTOBER, 2001};
    cout << "getDifference(d1, d2):       " << getDifference(d1, d2)      << endl;
    cout << "getDifference(d2, d1):       " << getDifference(d2, d1)      << endl;
    */


    // ## EJERCICIO 3 ## //
    /*
    word w = {0xA0B1C2D3};
    cout << endl << "word: "<< hex << w.data;
    w.b0 = 0xD3;
    w.b1 = 0xC2;
    w.b2 = 0xB1;
    w.b3 = 0xA1;
    cout << endl << "b0: "<< hex << int(w.b0);
    cout << endl << "b1: "<< hex << int(w.b1);
    cout << endl << "b2: "<< hex << int(w.b2);
    cout << endl << "b3: "<< hex << int(w.b3);

    cout << endl << endl << "&w: " << &w << endl;
    cout << "sizeof(w): " << sizeof(w) << " bytes" << endl;
    */
    // La relación que hay entre las direcciones de memoria de la estructura es que todas empiezan igual (están en el mismo sector) y solo varían los 2 últimos dígitos en el hex. Osea, se encuentran definidos en memoria de forma conjunta y ordenada a como fueron definidos.




    // ## EJERCICIO 4 ## //
    /*
    size_t arr_size = 6;
    Date  *dates    = new Date[arr_size];
    dates[0] = {26, OCTOBER,  2001};
    dates[1] = {11, OCTOBER,  2004};
    dates[2] = {20, OCTOBER,  2001};
    dates[3] = {01, JANUARY,  2020};
    dates[4] = {20, FEBRUARY, 2020};
    dates[5] = {19, FEBRUARY, 2020};

    sort(dates, arr_size, desc);

    for(unsigned char i = 0; i < (unsigned char)arr_size; i++) {
        cout << dates[i].day << "/" << dates[i].month << "/" << dates[i].year << endl;
    }
    */

    /****************************************************************************************
     # Comentar: ¿Cómo se pueden hacer distintos ordenamientos sin modificar el arreglo original y
     sin crear una copia completa de la estructura (“no programar”)?
     * Rta: Para no modificar el arreglo original se puede hacer una copia del mismo. En esa copia
     para no crear una copia completa de la estructura, se puede verificar cada campo (dia, mes año)
     y si coinciden los días y los meses, se puede ingresar a la dirección de memoria de los años y
     cambiar solo el valor de los años sin tener que copiar toda la estructura completa.
     # Ej: 10/10/2001
         10/10/2020
     Sólo se copiarían los años sin tener que copiar la estructura (Date) completa.
    *****************************************************************************************/



    // ## EJERCICIO 5 ## //
    /****************************************************************************************
     Los campos de bits nos ayudan a especificiar cuantos bits necesitamos que una variable
     almacene, por ejemplo, normalmente creamos variables que son de 8, 16, 32, 64 bits,
     pero a lo mejor solo necesitamos 3 bits de esa variable. Un campo de bits nos deja
     especificar cuantos exactamente una variable va a necesitar.

    # Desventajas : hay cosas que dependen mucho de los compiladores que se usen, como por
    ejemplo sumar 1 a un unsigned char de x bits. Y otros problemas como que si hay un
    overflow está todo en manos del compilador, etc...

    # Ventajas : son más conservadores en el uso de la ram. Si se quiere mandar paquete por
    la red, es otra forma de economizar en el peso.
    *****************************************************************************************/

    // Ejemplo de bit fields

    /*
    #include "bitFieldsExample.h"
    */



    // ## EJERCICIO 6 ## //
    /*
    Card * deck = initCards();
    for(unsigned char cardNumber = 0; cardNumber < 52; cardNumber++) {
        cout << "Number: "   << +cardNumber             <<
                " | Color: " << +deck[cardNumber].color <<
                " | Suit: "  << +deck[cardNumber].suit  <<
                " | Value: " << +deck[cardNumber].value << endl;
    }
    cout << "Size of struct Card: " << sizeof(Card) << " bytes" << endl;
    */
    return 0;
}
