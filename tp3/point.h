#ifndef TP3_POINT_H
#define TP3_POINT_H

class Point {

public:
    // Constructors
    Point() {
        this -> x = 0;
        this -> y = 0;
    }

    Point(int x, int y) {
        this -> x = x;
        this -> y = y;
    }

    // Methods implementation
    int  getX();
    int  getY();
    void setX(int x);
    void setY(int y);

    // Operator
    friend std::ostream& operator<<(std::ostream& out, Point p) {
        return out << "(" << p.getX() << ", " << p.getY() << ")";
    }

private:
    int x, y;
};



// ## Methods ## //
// Getters
int Point::getX() { return this -> x; }
int Point::getY() { return this -> y; }

// Setters
void Point::setX(int x) { this -> x = x; }
void Point::setY(int y) { this -> y = y; }




#endif //TP3_POINT_H
