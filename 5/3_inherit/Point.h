#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
    int x, y;

public:
    Point(int x_ = 0, int y_ = 0);

    std::string toString() const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    int& operator[](int i);
    const int& operator[](int i) const;
    Point operator+(const Point& other) const;
    Point operator*(const Point& other) const;
    Point operator+=(const Point& other);
    Point operator*=(const Point& other);
    Point operator++();
    Point operator++(int);
    Point operator--();
    Point operator--(int);
    Point& operator=(const Point& other);
};

#endif