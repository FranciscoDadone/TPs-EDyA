#ifndef TP3_POLYGON_H
#define TP3_POLYGON_H

#include "vector"
#include "point.h"

using namespace std;

class Polygon {
public:
    // Constructors
    Polygon() { this -> points = getDefaultPolygon(); }
    Polygon(const vector<Point>& points) {
        if(isValidPolygon(points)) this -> points = points;
        else this -> points = getDefaultPolygon(); // Si el poligono es inválido se debería de tirar
    }                                              // una excepción, pero como no está contemplado en
                                                   // el curso, generé un poligono por defecto.
    // Operators
    Polygon operator + (Polygon polygon) {
        if(this -> points.size() != polygon.points.size()) return polygon;
        vector<Point> points;
        for(unsigned short int i = 0; i < this -> points.size(); i++) {
            points.push_back({
                ((this -> points).at(i).getX() + polygon.points.at(i).getX()),
                ((this -> points).at(i).getY() + polygon.points.at(i).getY())
            });
        }
        return { points };
    }
    Polygon operator - (Polygon polygon) {
        if(this -> points.size() != polygon.points.size()) return polygon;
        vector<Point> points;
        for(unsigned short int i = 0; i < this -> points.size(); i++) {
            points.push_back({
                ((this -> points).at(i).getX() - polygon.points.at(i).getX()),
                ((this -> points).at(i).getY() - polygon.points.at(i).getY())
            });
        }
        return { points };
    }
    Polygon operator * (int multiplier) {
        vector<Point> points;
        for(auto & point : this -> points) {
            points.push_back({
                (point.getX() * multiplier),
                (point.getY() * multiplier)
            });
        }
        return { points };
    }
    Polygon operator / (int divisor) {
        vector<Point> points;
        for(auto & point : this -> points) {
            points.push_back({
                (point.getX() / divisor),
                (point.getY() / divisor)
            });
        }
        return { points };
    }
    bool operator == (Polygon polygon) {
        if(this -> points.size() != polygon.getPoints().size()) return false;
        for(unsigned short int i = 0; i < this -> points.size(); i++) {
            if(this -> points.at(i).getX() != polygon.getPoints().at(i).getX() ||
               this -> points.at(i).getX() != polygon.getPoints().at(i).getX()) return false;
        }
        return true;
    }
    bool operator != (Polygon polygon) {
        if(this -> points.size() != polygon.getPoints().size()) return true;
        for(unsigned short int i = 0; i < this -> points.size(); i++) {
            if(this -> points.at(i).getX() == polygon.getPoints().at(i).getX() &&
               this -> points.at(i).getX() == polygon.getPoints().at(i).getX()) return false;
        }
        return true;
    }
    friend std::ostream& operator << (std::ostream& out, Polygon p) {
        out << "{";
        for(unsigned short int i = 0; i < p.getPoints().size(); i++) {
            out << p.getPoints().at(i);
            if(i < p.getPoints().size() - 1) out << ", ";
        }
        out << "}";
        return out;
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
    if((this -> points).size() > index && (this -> points).size() >= 3) {
        (this -> points).at(index) = point;
    }
    return ((this -> points).size() > index && (this -> points).size() > 3); // returns true or false if the operation succeeded
}


bool Polygon::removePoint(unsigned short int index) {
    if((this -> points).size() > index && (this -> points).size() > 3) { // El programador no puede remover un punto para que el polígino quede como inválido
        (this -> points).erase((this -> points).begin() + index);
    }
    return ((this -> points).size() > index && (this -> points).size() > 3); // returns true or false if the operation succeeded
}

bool Polygon::isValidPolygon(vector<Point> points) {
    if(points.size() < 3) return false;
    for(int i = 1; i < points.size(); i++) {
        if(points.at(0).getX() != points.at(i).getX() && points.at(0).getY() != points.at(i).getY()) return true;
    }
    return false;
}
vector<Point> Polygon::getDefaultPolygon() { return {{0,0}, {0,1}, {1,0}, {1,1}}; }




#endif //TP3_POLYGON_H
