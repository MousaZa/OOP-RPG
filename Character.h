#include <iostream>
#include "Weapon.h"

using namespace std;

class Character{
    private:
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

    void takeDamage(int);
    void heal(int);

    void print_hp();

    void print();
    void print_with_weapon();

};
