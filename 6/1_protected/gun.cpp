#include <iostream>

class Weapon {
public:
    // pure virtual
    //virtual void use() const = 0;
    // but i wanted the joke
    virtual void use() const {
        std::cout << "swoosh" << std::endl;
        std::cout << "(distant ow!)" << std::endl;
    }
};

class Gun : public Weapon {
    void use() const override {
        shoot();
    }
public:
    // virtual lets you use child class methods on a pointer to the base class
    virtual void shoot() const {
        std::cout << "bang" << std::endl;
    }
};

class MachineGun : public Gun {
public:
    // override is optional
    void shoot() const override {
        std::cout << "bang bang bang" << std::endl;
        Gun::shoot();
        std::cout << "bang" << std::endl;
        std::cout << "explosioin" << std::endl;
    }
};

class Bazooka : public Gun {
public:
    void shoot() const override {
        std::cout << "uh..." << std::endl;
        std::cout << "boooooooooooom" << std::endl;
        std::cout << "(its really big explode)" << std::endl;
    }
};

class Knife : public Weapon {
public:
    bool is_stainless = false;

    void use() const override {
        std::cout << "stab" << std::endl;
    }
};

class Player {
public:
    // gun reference can polymorphism
    // pointer too
    // but not object
    void attack(const Weapon& w) const {
        std::cout << "no fun" << std::endl;
        w.use();
        std::cout << "only death" << std::endl; // technoblade reference
        const Knife* knife = dynamic_cast<const Knife*>(&w);
        if (knife != nullptr) {
            if (knife->is_stainless) {
                std::cout << "oh wow i got a shiny one" << std::endl;
            }
        }
    }
};

int main() {
    Gun g;
    MachineGun m;

    g.shoot();
    m.shoot();

    Gun *gp = new Gun();
    Gun *mp = new MachineGun();

    gp->shoot();
    mp->shoot();

    delete gp, mp;

    Player p;

    Bazooka b;

    p.attack(g);
    p.attack(m);
    p.attack(b);

    Knife k;
    p.attack(k);

    Knife k2;
    k2.is_stainless = true;
    p.attack(k2);

    return 0;
}