#include <iostream>
#include "Weapon.h"

using namespace std;

class Character{
    private:
    

    protected:
    int full_hp;

    public:
    string name;
    int hp;
    int power;
    string type;
    Weapon* weapon; 
    int xp;
    

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
    public: 
    
    void repair_weapon(int repair_cost, int repair_amount);// since the repair function needs to access the xp i wrote it in the charactrer class
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
