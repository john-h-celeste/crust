#include <iostream>

class Elf {
public:
    Elf() {
        std::cout << "elf" << std::endl;
    }

    virtual void think() const {
        std::cout << "hmm...... i think i am therefore i am" << std::endl;
    }
};

class Warrior {
public:
    Warrior() {
        std::cout << "warrior!! roar or something idk" << std::endl;
    }

    virtual void fight() const {
        std::cout << "yeet" << std::endl;
    }
};

class ElfWarrior : public Elf, public Warrior {
public:
    void think() const {
        std::cout << "what" << std::endl;
    }

    void fight() const {
        std::cout << "fight but g r a c e f u l l" << std::endl;
    }
};

int main() {
    ElfWarrior him;

    him.think();
    him.fight();

    return 0;
}