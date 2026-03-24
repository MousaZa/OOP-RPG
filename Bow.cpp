#include "Weapon.h"

Bow::Bow() : Weapon("Bow"){
    // dmg 2-5 dur 2-8
    damage = (rand() % 4) + 2;
    durability = (rand() % 6) + 2;
}
