#include "Weapon.h"

Wand::Wand() : Weapon("Wand"){

   repair_cost=40; // you need 40 xp to increase durability by 10
}


// A wand can be used to attack (1 enemy)
// A wand can be used to attack multiple enemies??
// A wand can defend the characters by freezing the enemies??


void Wand::double_attack(Enemy* enemy){}

string Wand::attack(Enemy* enemy){
    if(durability == 1){
        durability--;
                enemy->takeDamage(damage);
        return "Warning";
    }
    if (durability <= 0) {
        cout << name << " Broke!" << endl;
        return "Broken";
    }

    durability--;
    enemy->takeDamage(damage);
    return "Done";
}
