// Create a small C++ application that handles 2D geometry operations like:
// Point-to-point distance
// Line equation from two points
// Midpoint of a line
// Operator overloading for geometric calculations (like adding two points or comparing them)
// Pretty-printed results using << overloading

#include<iostream>
#include<cmath>
#include"geometry.h"
using namespace std;

int main() {
    Point P1(2, 3);
    Point P2(3, 4);
    Line L(P1, P2);
    cout << "Length: " << L.length() << endl;
    L.midpoint();
    cout << "Slope of the line passing through "<< P1 << " and " << P2 << " : " << L.slope() << endl;
    L.eqnOfLine();
    return 0;
}
