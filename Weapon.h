#include <iostream>
#include "Enemy.h"

using namespace std;


class Weapon{
    public:
    string name;
    string type;
    int damage;
    int durability;

    Weapon();
    Weapon(string);

    bool attack(Enemy*);
    void print();
};

class Bow : public Weapon{
    public:
    Bow();
};

class Sword : public Weapon{
    public:
    Sword();
};

class Wand : public Weapon{
    public:
    Wand();
};
