#include <iostream>

template<typename T>
class myvector {
    int capacity, size;
    T* data;

    void reallocate(int newcapacity) {
        capacity = newcapacity;
        T* olddata = data;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = olddata[i];
        }
        delete[] olddata;
    }

public:
    myvector(int capacity_) {
        capacity = capacity_;
        data = new T[capacity];
        size = 0;
    }

    myvector(const myvector<T>& other) {
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~myvector() {
        delete[] data;
    }

    void push_back(const T& o) {
        add(o, size);
    }

    void push_front(const T& o) {
        add(o, 0);
    }

    void pop_back() {
        remove(size);
    }

    void pop_front() {
        remove(0);
    }

    void clear() {
        size = 0;
        reallocate(10);
    }

    void remove(int index) {
        if (index >= size || index < 0) {
            return;
        }
        size--;
        for (int i = index; i < size; i++) {
            data[i] = data[i + 1];
        }
        if (size < capacity / 2) {
            reallocate(size + 5);
        }
    }

    void add(const T& o, int index) {
        if (size >= capacity) {
            reallocate(capacity * 2 + 1);
        }
        for (int i = size++; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = o;
    }

    void print() const {
        std::cout << "[ ";
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    myvector<int> v(10);

    v.push_back(1);
    v.push_back(2);
    v.push_front(17);
    v.push_back(3);
    v.remove(2);
    v.add(-3, 2);
    v.remove(-1);
    v.remove(4);

    v.print();

    return 0;
}