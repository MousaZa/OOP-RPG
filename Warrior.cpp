#include "Character.h"

Warrior::Warrior(string n) : Character(n, "Warrior"){
    hp = 10;
    full_hp = 10;
    power = 2;
    weapon = new Sword();
}