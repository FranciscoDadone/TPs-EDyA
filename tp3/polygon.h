/*************************
    Trabajo Práctico 3
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef TP3_POLYGON_H
#define TP3_POLYGON_H

#include "vector"
#include "point.h"
#include <cmath>

/**
 * Class to make a polygon based on a vector of points.
 * DOUBLE || FLOAT || INT - To define the vector of points.
 * @class Polygon
 */
template <class T>
class Polygon {
public:
    /**
     * # Constructors
     *    - Default: generates a default polygon (1x1 square).
     *    - Parameterized: gets a vector of points and generates a polygon if it is valid. Refer to isValidPolygon().
     *    - Copy: copies a polygon from parameter.
     *    - Null: if a polygon is initialized with Polygon(NULL) this generates a polygon without points.
     */
    Polygon() { this -> points = getDefaultPolygon(); }
    Polygon(const std::vector<Point<T>> &points) {
        if(isValidPolygon(points)) this -> points = points;
        else this -> points = getDefaultPolygon(); // Si el poligono es inválido se debería de tirar
    }                                              // una excepción, pero como no está contemplado en
    Polygon(Polygon const &pol) {                  // el curso, generé un poligono por defecto.
        this -> points = pol.points;
    }
    Polygon(int null) { if(null != NULL) this -> points = getDefaultPolygon(); }

    // Operators
    /**
     * Checks if the rhs and lhs polygons are equal or not.
     * @param rhs
     * @return bool
     */
    bool operator == (Polygon rhs) {
        if(this -> points.size() != rhs.getPoints().size()) return false;
        for(unsigned short int i = 0; i < this -> points.size(); i++) {
            if(this -> points.at(i).getX() != rhs.getPoints().at(i).getX() ||
               this -> points.at(i).getX() != rhs.getPoints().at(i).getX()) return false;
        }
        return true;
    }
    /**
     * Checks if the rhs and lhs polygons aren't equal.
     * @param rhs
     * @return bool
     */
    bool operator != (Polygon rhs) {
        return *this != rhs;
    }
    /**
     * Prints to console the polygon.
     * @param out
     * @param p
     * @return out
     */
    friend std::ostream& operator << (std::ostream& out, Polygon &p) {
        out << "{";
        for(unsigned short int i = 0; i < p.getPoints().size(); i++) {
            out << p.getPoints().at(i);
            if(i < p.getPoints().size() - 1) out << ", ";
        }
        out << "}";
        return out;
    }

    // # GETTERS # //
    /**
     * Get the vector of points
     * @return returns the vector of points
     */
    std::vector<Point<T>> getPoints() { return (this -> points); }
    /**
     * Gets an specific point from an index.
     * @param index
     * @return returns a Point object.
     */
    Point<T> getPoint(unsigned short int index) { return (this -> points).at(index); }
    /**
     * @return returns the numbers of points of the polygon.
     */
    int getNumberOfPoints() { return (this -> points).size(); }
    /**
     * Gets the area of the polygon.
     * The points in the vector must be in order.
     * @return float
     */
    float getArea() {
        float area = 0;
        for(int i = 0; i < this->points.size() - 1; i++) {
            area += ((this->points.at(i).getX() * this->points.at(i + 1).getY()) - (this->points.at(i + 1).getX() * this->points.at(i).getY()));
        }
        return abs(area) / 2.0;
    }
    /**
     * Returns the perimeter of the polygon.
     * @return float
     */
    float getPerimeter() {
        float perimeter = 0;
        for(int i = 0; i < this->points.size(); i++) {
            perimeter += getModule(this->points.at(i), this->points.at((i == this->points.size() - 1) ? 0 : i + 1));
        }
        return perimeter;
    }
    /**
     * Returns the sum of all the angles.
     * It only works with convex polygons.
     * @return float
     */
    float getAngleSum() {
        return (this->points.size() - 2) * 180;
    }
    /**
     * Gets the number of diagonals in the polygon.
     * @return int
     */
    int getNumberOfDiagonals() {
        return ((this->points.size() * (this->points.size() - 3)) / 2);
    }

    // # SETTERS # //
    /**
     * Adds a point to the end of the vector.
     * @param point
     */
    void addPoint(Point<T> point) { points.push_back(point); }
    /**
     * Removes a point from the index passed by parameter.
     * @param index
     */
    void removePoint(unsigned short int index) {
        if(index >= this->getNumberOfPoints()) return;
        (this -> points).erase((this -> points).begin() + index);
    }
    /**
     * Adds a point to the points vector in the class.
     * @param index
     * @param point
     * @return returns true or false if the operation succeeded.
     */
    bool setPoint(unsigned short int index, Point<T> point) {
        if((this -> points).size() > index && (this -> points).size() >= 3)
            (this -> points).at(index) = point;
        return ((this -> points).size() > index && (this -> points).size() > 3);
    }

private:
    std::vector<Point<T>> points;
    /**
     * Checks if a polygon is valid.
     *  Checks:
     *      - If the polygon has at least 3 points.
     *      - If the points are not inline (the polygon has a shape and it isn't a straight line).
     * @param points
     * @return bool
     */
    bool isValidPolygon(std::vector<Point<T>> v) {
        if(v.size() < 3) return false;
        for(int i = 1; i < v.size(); i++) {
            if(v.at(0).getX() != v.at(i).getX() && v.at(0).getY() != v.at(i).getY()) return true;
        }
        return false;
    }
    /**
     * @return returns a square (1x1).
     */
    std::vector<Point<T>> getDefaultPolygon() { return {{0,0}, {0,1}, {1,1}, {1,0}}; }
    /**
     * Gets the distance between two points.
     * @param a
     * @param b
     * @return float
     */
    float getModule(Point<T> a, Point<T> b) {
        return sqrt(pow((b - a).getX(), 2) + pow((b - a).getY(), 2));
    }
};

#endif //TP3_POLYGON_H
