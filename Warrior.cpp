#include "Character.h"

Warrior::Warrior(string n) : Character(n, "Warrior"){
    hp = 10;
    full_hp = 10;
    power = 2;
    weapon = Sword();
}

void Warrior::generate_weapon(){
    weapon = Sword();
}
