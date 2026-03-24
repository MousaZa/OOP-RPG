#include "Character.h"

Archer::Archer(string n) : Character(n, "Archer"){
    hp = 7;
    full_hp = 7;
    power = 3;
    //weapon = Weapon("Bow");
    weapon = new Bow();    // or should i use weapon = &Bow();
}
