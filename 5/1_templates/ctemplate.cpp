#include <iostream>

template<typename T>
class Tree {
    bool haschildren;
    Tree<T> *c1 = nullptr, *c2 = nullptr;
    T value;

public:
    Tree(T value_) {
        std::cout << "no " << value_ << std::endl;
        haschildren = false;
        value = value_;
    }

    Tree(const Tree<T>& other) {
        std::cout << "copy " << other.value << std::endl;
        haschildren = other.haschildren;
        if (haschildren) {
            c1 = new Tree<T>(T());
            c2 = new Tree<T>(T());
            *c1 = *other.c1;
            *c2 = *other.c2;
        }
        value = other.value;
    }

    Tree(T value_, const Tree<T>& t1, const Tree<T>& t2) {
        std::cout << "yes " << value_ << std::endl;
        haschildren = true;
        c1 = new Tree<T>(T());
        c2 = new Tree<T>(T());
        *c1 = t1;
        *c2 = t2;
        value = value_;
    }

    ~Tree() {
        std::cout << "ow " << value << std::endl;
        delete c1;
        delete c2;
    }

    Tree *getchild1() {
        if (haschildren) {
            return c1;
        } else {
            return nullptr;
        }
    }

    Tree *getchild2() {
        if (haschildren) {
            return c2;
        } else {
            return nullptr;
        }
    }

    void setchild1(Tree c) {
        if (haschildren) {
            *c1 = c;
        }
    }

    void setchild2(Tree c) {
        if (haschildren) {
            *c2 = c;
        }
    }

    void print(int indent = 0) {
        for (int i = 0; i < indent; i++) {
            std::cout << "  ";
        }
        std::cout << value << std::endl;
        if (haschildren) {
            std::cout << c1 << std::endl;
            std::cout << c2 << std::endl;
            c1->print(indent + 1);
            c2->print(indent + 1);
        }
    }
};

int main() {
    //Tree<int> t = Tree<int>(1, Tree<int>(3), Tree<int>(6, Tree<int>(8), Tree<int>(4)));
    Tree<int> t = Tree<int>(1, Tree<int>(6, Tree<int>(4), Tree<int>(8)), Tree<int>(3));

    //Tree<int>(1, Tree<int>(6, Tree<int>(4), Tree<int>(8)), Tree<int>(3)).print();

    //t.print();

    std::cout << "wee" << std::endl;

    return 0;
}