#include <iostream>
#include <string>

class Point {
    int x, y;

public:
    Point(int x_ = 0, int y_ = 0) {
        x = x_;
        y = y_;
    }

    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    bool operator==(const Point& other) {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) {
        return !(*this == other);
    }

    int& operator[](int i) {
        if (i == 0) {
            return x;
        } else {
            return y;
        }
    }

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    Point operator*(const Point& other) {
        return Point(x * other.x, y * other.y);
    }

    Point operator+=(const Point& other) {
        x += other.x;
        y += other.y;

        return *this;
    }

    Point operator*=(const Point& other) {
        x *= other.x;
        y *= other.y;

        return *this;
    }

    Point operator++() {
        x++;
        y++;

        return *this;
    }

    Point operator++(int) {
        x++;
        y++;

        return *this;
    }

    Point operator--() {
        x--;
        y--;

        return *this;
    }

    Point operator--(int) {
        x--;
        y--;

        return *this;
    }

    Point& operator=(const Point& other) {
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
};

int main() {
    Point p1(3, 4);
    Point p2(5, 4);
    Point p3(89, 55);

    std::cout << p1.toString() << std::endl;
    std::cout << (p1 == p1) << std::endl;
    std::cout << p1.operator==(p1) << std::endl;

    if (p1 != p2) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    std::cout << p3[0] << std::endl;

    std::cout << (char) p3[0] << std::endl;

    p3[0] = 34;

    std::cout << p3[0] << std::endl;

    std::cout << (p1 + p2).toString() << std::endl;

    std::cout << (p1 * p2).toString() << std::endl;

    p1[0] = 77;
    std::cout << (char) p1[0] << std::endl;

    p1[0] = p1[0] - 59;
    p2[0] = p2[0] + 3;
    Point p4 = p1 * p2;
    std::cout << (char) (p4[0] - 56) << std::endl;

    Point p5(60, 74);
    p5 += p1;
    std::cout << (char) (p5[1] - 4) << std::endl;

    p5 *= p1;
    for (int i = 0; i < 119; i++) {
        p5--;
        --p5;
    }
    std::cout << (char) p5[1] << std::endl;


    // it's ymxjj

    return 0;
}

// no zodiac signs
// when [|], do you
// press right arrow ->
// or
// press close bracket ]
// ?

// 6maw4 is tomorrow's code ;)
// wonk