#include "Weapon.h"

Wand::Wand() : Weapon("Wand"){
    // dmg 1-3 dur 2-8
    damage = (rand() % 3) + 1;
    durability = (rand() % 6) + 2;
}
