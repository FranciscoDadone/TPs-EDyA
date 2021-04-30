/*************************
    Trabajo Práctico 3
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef TP3_POINT_H
#define TP3_POINT_H

template <class T>
/**
 * Class to make a point.
 * DOUBLE || FLOAT || INT
 * @class Point
 */
class Point {
public:
    /**
     * Constructor
     * Default: x = y = 0
     * @param x
     * @param y
     */
    Point(T x = 0, T y = 0) {
        this -> x = x;
        this -> y = y;
    }

    // ## Methods ## //
    // Getters
    /**
     * Gets the x coordinate of a point.
     * @return returns x
     */
    T      getX() { return this -> x; }
    /**
     * Gets the y coordinate of a point.
     * @return returns y
     */
    T      getY() { return this -> y; }
    // Setters
    /**
     * Sets x from a parameter.
     * @param x
     */
    void   setX(T newX) { this -> x = newX; }
    /**
     * Sets y from a parameter.
     * @param y
     */
    void   setY(T newY) { this -> y = newY; }

    // Operator
    /**
     * Outputs to console a given point.
     * @param out
     * @param p
     * @return
     */
    friend std::ostream& operator << (std::ostream& out, Point p) {
        return out << "(" << p.getX() << ", " << p.getY() << ")";
    }
    /**
     * Takes an input from the user and creates a new object.
     * @param in
     * @param p
     * @return returns a Point.
     */
    friend std::istream& operator >> (std::istream& in, Point &p) {
        return in >> p.x >> p.y;
    }
    /**
     * Plus operator
     * @param rhs
     * @return Point
     */
    Point<T> operator + (Point<T> rhs) {
        return { this->x + rhs.getX(), this->y + rhs.getY() };
    }
    /**
     * Minus operator
     * @param rhs
     * @return Point
     */
    Point<T> operator - (Point<T> rhs) {
        return { this->x - rhs.getX(), this->y - rhs.getY() };
    }
    /**
     * Multiply operator
     * @param scalar
     * @return Point
     */
    Point<T> operator * (double scalar) {
        return { this->x * scalar, this->y * scalar };
    }
    /**
     * Division operator
     * @param scalar
     * @return Point
     */
    Point<T> operator / (double scalar) {
        return this * (1 / scalar);
    }

private:
    T x, y;
};

#endif //TP3_POINT_H
