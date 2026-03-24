#include <iostream>
#include "Weapon.h"

using namespace std;

class Character{
    private:
    int xp;

    protected:
    int full_hp;

    public:
    string name;
    int hp;
    int power;
    string type;
    Weapon weapon;

    // constructor
    Character(string , string );

    Character();

    virtual ~Character() = default;

    void takeDamage(int);
    void heal(int);
    bool attack(Enemy*);

    void print_hp();

    virtual void generate_weapon() = 0;

    void print();
    void print_with_weapon();

    int get_level();
};

class Wizard : public Character{
    public:
    Wizard(string);
    void generate_weapon() override;
};

class Archer : public Character{
    public:
    Archer(string);
    void generate_weapon() override;
};

class Warrior : public Character{
    public:
    Warrior(string);
    void generate_weapon() override;
};
