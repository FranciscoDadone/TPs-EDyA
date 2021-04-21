#ifndef TP3_POINT_H
#define TP3_POINT_H

class Point {

public:
    // Constructors
    Point() {
        this -> x = 0;
        this -> y = 0;
    }

    Point(double x, double y) {
        this -> x = x;
        this -> y = y;
    }

    // Methods implementation
    double getX();
    double getY();
    void   setX(double x);
    void   setY(double y);

    // Operator
    friend std::ostream& operator<<(std::ostream& out, Point p) {
        return out << "(" << p.getX() << ", " << p.getY() << ")";
    }

private:
    double x, y;
};

// ## Methods ## //
// Getters
double Point::getX() { return this -> x; }
double Point::getY() { return this -> y; }

// Setters
void Point::setX(double x) { this -> x = x; }
void Point::setY(double y) { this -> y = y; }




#endif //TP3_POINT_H
