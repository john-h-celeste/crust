#include <iostream>

class Counter {
    int value;

public:
    Counter(int value);
    void log();
    Counter increment();
};

void logCounter(const Counter& c);

Counter::Counter(int value) {
    this->value = value;
}

void Counter::log() {
    logCounter(*this);
}

Counter Counter::increment() {
    value++;
    return *this;
}

void logCounter(const Counter& c) {
    // we do a lttle trolling
    std::cout << *(int*)(&c) << std::endl; // evil pointer aliasing trick
}

int main() {
    Counter c(15);

    c.log();

    Counter c2 = c.increment();

    c.log();
    c2.log();

    return 0;
}