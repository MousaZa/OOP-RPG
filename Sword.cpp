#include "Weapon.h"

Sword::Sword() : Weapon("Sword"){
    repair_cost =70;  // you need 70 xp to increase durability by 10
}


// A sword can be used to attack
// A sword can be used to defend

void Sword::defence(Enemy* enemy){}


string Sword::attack(Enemy* enemy){
    if(durability == 1){
        durability--;
                enemy->takeDamage(damage);
        return "Warning";
    }
    if (durability <= 0) {
        cout << name << " Broke!" << endl;
        return "Broken";
    }

    // |\
    // | \
    // |--+--->
    // | /
    // |/
    // ====<o>
    // =|======>
    //
    //

    durability--;
    enemy->takeDamage(damage);
    return "Done";
}
