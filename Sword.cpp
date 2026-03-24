#include "Weapon.h"

Sword::Sword() : Weapon("Sword"){
    // dmg 3-7 dur 4-10
    damage = (rand() % 5) + 3;
    durability = (rand() % 7) + 4;
}
