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
    void   setX(T x) { this -> x = x; }
    /**
     * Sets y from a parameter.
     * @param y
     */
    void   setY(T y) { this -> y = y; }

    // Operator
    /**
     * Outputs to console a given point.
     * @param out
     * @param p
     * @return
     */
    friend std::ostream& operator<<(std::ostream& out, Point p) {
        return out << "(" << p.getX() << ", " << p.getY() << ")";
    }

private:
    T x, y;
};

#endif //TP3_POINT_H
