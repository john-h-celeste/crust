#include <iostream>
#include <string>

class Human {
public:
    std::string name;
    
    Human() {
        std::cout << "human constructed" << std::endl;
    }
    
    Human(std::string name_) {
        name = name_;
        std::cout << "human constructed " << name << std::endl;
    }
    
    ~Human() {
        std::cout << "human destroy " << name << std::endl;
    }
};

class Student : public Human {
public:
    std::string name;
    int studentid;
    
    Student() {
        std::cout << "student constructed" << std::endl;
    }
    
    Student(std::string name1, std::string name2) : Human(name1) {
        name = name2;
        std::cout << "student constructed " << name1 << " " << name2 << std::endl;
    }
    
    ~Student() {
        std::cout << "student destroy " << name << " " << Human::name << " " << studentid << std::endl;
    }

    void study(std::string subject) {
        std::cout << name << " is studying " << subject << " (probably)" << std::endl;
    }
};

class Employee : public Human {
public:
    double salary;
};

class Fruit {
public:
    Fruit() {}
    Fruit(int id) {}
};

class Apple : Fruit {
public:
    Apple() {}
};

int main() {
    Human h;
    h.name = "jonathan";
    Human h2("weezer");

    Student s;
    s.name = "andrew";
    ((Human&)s).name = "and"; // we do a little trolling ;)
    s.studentid = 4031;

    Student s2("buddy chum pal", "sans");
    s2.studentid = 92437;

    std::cout << "now watch this" << std::endl;

    std::cout << h.name << std::endl;
    std::cout << s.name << " " << ((Human)s).name << " " << s.studentid << std::endl;

    s2.study("the meaning of life, the universe, and everything");

    std::cout << "jonathan was more prepared for life" << std::endl;
    std::cout << "watch he dies last" << std::endl;

    return 0;
}