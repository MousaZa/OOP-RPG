#include "Character.h"

Archer::Archer(string n) : Character(n, "Archer"){
    hp = 7;
    full_hp = 7;
    power = 3;
    weapon = Bow();
}

void Archer::generate_weapon(){
    weapon = Bow();
}
