/*************************
    Trabajo Práctico 1
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef BITFIELDSEXAMPLE_H_INCLUDED
#define BITFIELDSEXAMPLE_H_INCLUDED


struct dateWithoutBitFields {
    unsigned int d, m, y;
};

// Como sabemos que los dias van de 1 a 31  (2^5)-1,
//                      los meses de 1 a 12 (2^4)-1
//                      y los años...       (2^16)-1
struct dateWithBitFields {
    unsigned int d:5, m:4, y:16;
};

dateWithoutBitFields a = {31, 12, 2021};
dateWithBitFields    b = {31, 12, 2021};

cout << "Tamaño sin usar bit fields:    " << sizeof(dateWithoutBitFields) << " bytes"<< endl;
cout << "Tamaño usando bit fields:      " << sizeof(dateWithBitFields)    << " bytes"<< endl;
cout << "\nResultado sin usar bit fields: " << a.d << " " << a.m << " " << a.y << endl;
cout << "Resultado usando bit fields:   " << b.d << " " << b.m << " " << b.y << endl;


#endif // BITFIELDSEXAMPLE_H_INCLUDED
