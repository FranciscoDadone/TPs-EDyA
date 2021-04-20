#ifndef TP3_POLYGON_H
#define TP3_POLYGON_H

#include "vector"
#include "point.h"

using namespace std;

class Polygon {

public:
    // Constructors
    Polygon() { /*this -> points = getDefaultPolygon();*/ }
    Polygon(vector<Point> points) {
        if(isValidPolygon(points)) this -> points = points;
        else this -> points = getDefaultPolygon(); // Si el poligono es inválido se debería de tirar
    }                                              // una excepción, pero como no está contemplado en
                                                   // el curso, generé un poligono por defecto.
    // Operators
    Polygon operator+ (Polygon polygon) {
        if(this->points.size() != polygon.points.size()) return polygon;
        Polygon ret;
        for(unsigned int i = 0; i < this->points.size(); i++) {
            ret.addPoint({
                ((this->points).at(i).getX() + polygon.points.at(i).getX()),
                ((this->points).at(i).getY() + polygon.points.at(i).getY())
            });
        }
        return ret;
    }
    Polygon operator- (Polygon polygon) {
        if(this->points.size() != polygon.points.size()) return polygon;
        Polygon ret;
        for(unsigned int i = 0; i < this->points.size(); i++) {
            ret.addPoint({
                ((this->points).at(i).getX() - polygon.points.at(i).getX()),
                ((this->points).at(i).getY() - polygon.points.at(i).getY())
            });
        }
        return ret;
    }

    // Methods implementation
    void addPoint(Point point);
    vector<Point> getPoints();
    Point getPoint(unsigned short int index);
    bool setPoint(unsigned short int index, Point point);
    bool removePoint(unsigned short int index);
    int getNumberOfPoints();

private:
    vector<Point> points;

    // Methods implementation
    bool isValidPolygon(vector<Point> points);
    vector<Point> getDefaultPolygon();
};

// ## Methods ## //
// Getters
vector<Point> Polygon::getPoints() { return (this -> points); }
Point Polygon::getPoint(unsigned short int index) { return (this -> points).at(index); }
int Polygon::getNumberOfPoints() { return (this -> points).size(); }

// Setters
void Polygon::addPoint(Point point) { points.push_back(point); }
bool Polygon::setPoint(unsigned short int index, Point point) {
    if((this -> points).size() > index && (this -> points).size() > 3) {
        (this -> points).at(index) = point;
    }
    return ((this -> points).size() > index && (this -> points).size() > 3); // returns true or false if the operation succeeded
}



bool Polygon::removePoint(unsigned short int index) {
    if((this -> points).size() > index && (this -> points).size() > 3) {
        (this -> points).erase((this -> points).begin() + index);
    }
    return ((this -> points).size() > index && (this -> points).size() > 3); // returns true or false if the operation succeeded
}

bool Polygon::isValidPolygon(vector<Point> points) { return (points.size() >= 3); }
vector<Point> Polygon::getDefaultPolygon() { return {{0,0}, {0,1}, {1,0}, {1,1}}; }




#endif //TP3_POLYGON_H
