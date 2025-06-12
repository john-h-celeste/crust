#ifndef POINT3D_H
#define POINT3D_H

#include "Point.h"

#include <string>

class Point3D : Point {
    int z;

public:
    Point3D(int x_ = 0, int y_ = 0, int z_ = 0);

    std::string toString() const;

    bool operator==(const Point3D& other) const;
    bool operator!=(const Point3D& other) const;
    int& operator[](int i);
    const int& operator[](int i) const;
    Point3D operator+(const Point3D& other) const;
    Point3D operator*(const Point3D& other) const;
    Point3D operator+=(const Point3D& other);
    Point3D operator*=(const Point3D& other);
    Point3D operator++();
    Point3D operator++(int);
    Point3D operator--();
    Point3D operator--(int);
    Point3D& operator=(const Point3D& other);
};

#endif