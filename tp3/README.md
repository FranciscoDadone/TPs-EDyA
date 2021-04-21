# Documentación

## Polygon
#### Constructores
 - `Polygon()` Constructor por defecto: genera un polígino por defecto (un cuadrado de 1x1).
 - `Polygon(vector<Point>)` Constructor con parámetro: se le pasa un vector de puntos, este vector tiene que contener más de 3 puntos que no estén alineados ni sean los mismos para que se genere el polígino y no sea inválido. (Si el polígono es inválido se generará uno por defecto (Siguiendo con esto, en vez de generarse uno por defecto se debería de tirar una excepción pero consideré que en el curso todavía no vimos excepciones)).

#### Métodos
 - `void addPoint(Point point)` Se usa para agregar un punto a un polígono.
 - `vector<Point> getPoints()` Devuelve todos los puntos del polígono.
 - `Point getPoint(unsigned short int index)` Devuelve un punto específico de un polígono. Se le pasa como parámetro el index del punto dentro del vector de puntos que tiene el polígono.
 - `bool setPoint(unsigned short int index, Point point)` Reemplaza un punto del polígono por otro pasado por parámetro. Devuelve un booleano si la operación fue exitosa o no.
 - `bool removePoint(unsigned short int index)` Remueve un punto específico el cual se le pasa el index por parámetro. Devuelve un booleano si la operación fue exitosa o no.
 - `int getNumberOfPoints()` Devuelve el número de puntos que tiene un polígono.

#### Operadores
 - ` + ` Para sumar 2 polígonos de la misma cantidad de puntos. Retorna un nuevo polígono.
 - ` - ` Para restar 2 polígonos de la misma cantidad de puntos. Retorna un nuevo polígono.
 - ` * ` Para multiplicar un polígono por un escalar. Retorna un nuevo polígono.
 - ` / ` Para dividir un polígono por un escalar. Retorna un nuevo polígono.
 - ` == ` Para comparar si 2 polígonos son iguales. Retorna un booleano.
 - ` != ` Para comparar si 2 polígonos son diferentes. Retorna un booleano.
 - ` << ` Imprime el objeto polígono pasado.