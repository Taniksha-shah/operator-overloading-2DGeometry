// Create a small C++ application that handles 2D geometry operations like:
// Point-to-point distance
// Line equation from two points
// Midpoint of a line
// Operator overloading for geometric calculations (like adding two points or comparing them)
// Pretty-printed results using << overloading
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include<iostream>
#include<cmath>
using namespace std;

class Point {
    protected :
    float x;
    float y;

    public :
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Point operator+(const Point& P) {
        return Point(x + P.x, y + P.y);
    }

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
    
    float getX() const { return x; }
    float getY() const { return y; }

    friend ostream& operator<< (ostream& COUT, const Point& P);

};

ostream& operator<< (ostream& COUT, const Point& P) {
    COUT << "(" << P.getX() << ", " << P.getY() << ")";
    return COUT; 
}

class Line {
    Point P1, P2;

    public :
    Line(Point p1, Point p2) : P1(p1), P2(p2) {}

    //point to point distance
    float length() const {
        return sqrt( pow(P1.getX() - P2.getX(), 2) + pow(P1.getY() - P2.getY(), 2));
    }
    //midpoint of a line joining two points
    void midpoint() const {
        Point mid((P1.getX() + P2.getX())/2 , (P1.getY() + P2.getY())/2 );
        cout << "Midpoint : " << mid << endl;
    }
    //slope of the line passing through two points
    float slope() const {
        return ((P2.getY() - P1.getY())/(P2.getX() - P1.getX()));
    }
    //equation of line passing through two points
    void eqnOfLine() const {
        // y - P1.getY() = slope() * (x - P1.getX())
        // y - (slope()*x) = - (slope() * P1.getX()) + P1.getY()
        cout << "Equation : y -" << slope() << "x" << " = " << P1.getY() - (slope() * P1.getX()) << endl; 
    }

};


#endif