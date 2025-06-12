#include "Point3D.h"

// im tired for this
// next time, just implement point3d as a copy of point2d
// don't inherit x and y

Point3D::Point3D(int x, int y, int z_) : Point(x, y) {
    z = z_;
}

std::string Point3D::toString() const {
    return "(" + std::to_string((*this)[0]) + ", " + std::to_string((*this)[1]) + ")";
}

bool Point3D::operator==(const Point3D& other) const {
    return Point::operator==(other) && z == other.z;
}

bool Point3D::operator!=(const Point3D& other) const {
    return !(*this == other);
}

int& Point3D::operator[](int i) {
    if (i == 0 || i == 1) {
        return Point::operator[](i);
    } else {
        return z;
    }
}

const int& Point3D::operator[](int i) const {
    if (i == 0 || i == 1) {
        return Point::operator[](i);
    } else {
        return z;
    }
}

Point3D Point3D::operator+(const Point3D& other) const {
    Point p = Point::operator+(other);
    return Point3D(p[0], p[1], z + other.z);
}

Point3D Point3D::operator*(const Point3D& other) const {
    Point p = Point::operator+(other);
    return Point3D(p[0], p[1], z * other.z);
}

Point3D Point3D::operator+=(const Point3D& other) {
    x += other.x;
    y += other.y;

    return *this;
}

Point3D Point3D::operator*=(const Point3D& other) {
    x *= other.x;
    y *= other.y;

    return *this;
}

Point3D Point3D::operator++() {
    x++;
    y++;

    return *this;
}

Point3D Point3D::operator++(int) {
    x++;
    y++;

    return *this;
}

Point3D Point3D::operator--() {
    x--;
    y--;

    return *this;
}

Point3D Point3D::operator--(int) {
    x--;
    y--;

    return *this;
}

Point3D& Point3D::operator=(const Point3D& other) {
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