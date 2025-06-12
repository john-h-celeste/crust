#include "Point.h"

Point::Point(int x_ = 0, int y_ = 0) {
    x = x_;
    y = y_;
}

std::string Point::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

int& Point::operator[](int i) {
    if (i == 0) {
        return x;
    } else {
        return y;
    }
}

const int& Point::operator[](int i) const {
    if (i == 0) {
        return x;
    } else {
        return y;
    }
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator*(const Point& other) const {
    return Point(x * other.x, y * other.y);
}

Point Point::operator+=(const Point& other) {
    x += other.x;
    y += other.y;

    return *this;
}

Point Point::operator*=(const Point& other) {
    x *= other.x;
    y *= other.y;

    return *this;
}

Point Point::operator++() {
    x++;
    y++;

    return *this;
}

Point Point::operator++(int) {
    x++;
    y++;

    return *this;
}

Point Point::operator--() {
    x--;
    y--;

    return *this;
}

Point Point::operator--(int) {
    x--;
    y--;

    return *this;
}

Point& Point::operator=(const Point& other) {
    // copy assign destroy are big three or rule of three
    // this is another part of the
    // r u l e  o f  f i v e
    // there was a string char array tag but
    // i don't want to
    x = other.x;
    y = other.y;

    // so you can p1 = p2 = p3
    return *this;
}