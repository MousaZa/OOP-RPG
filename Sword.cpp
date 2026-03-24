#include "Weapon.h"

Sword::Sword() : Weapon("Sword"){
    repair_cost =70;  // you need 70 xp to increase durability by 10
}


// A sword can be used to attack
// A sword can be used to defend

void Sword::defence(Enemy* enemy){}


bool Sword::attack(Enemy* enemy){
    return Weapon::attack(enemy);
}


