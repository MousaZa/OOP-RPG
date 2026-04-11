#include <iostream>
#include "Enemy.h"


using namespace std;


class Weapon{
    public:
    string name;
    string type;
    int damage;
    int durability;
    int repair_cost;
    int repair_amount;

    Weapon();
    Weapon(string);

    virtual ~Weapon() = default;

    virtual string attack(Enemy*) = 0;
    void print();
    void repair(int);

};

class Bow : public Weapon{
public:
    int arrows; // something that only bows have
    int max_arrows = 15;

    Bow();
    string attack(Enemy* enemy) override; // the bow has a different way of attacking (boolean because you either can attack or cannot attack)
    void reload(int amount);
};

class Wand : public Weapon{
    public:
    Wand();
    string attack(Enemy* enemy) override;    // damage just 1 enemy
    void double_attack(Enemy* enemy);      // damage more than 1 enemy at the same time
};

class Sword: public Weapon{
    public:
    //int cool_down = 1;    // the time gap between each sword hit??

    Sword();
    string attack(Enemy* enemy) override;
    void defence(Enemy* enemy);
};
