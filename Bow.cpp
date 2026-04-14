#include "Weapon.h"

Bow::Bow() : Weapon("Bow"){
    damage = (rand() % 4) + 2;
    durability = (rand() % 6) + 2;
}


// A bow can be used to attack
// Arrows can be reloaded with xp?

// void Bow::reload(int amount){
//     arrows += amount;
//     if (arrows > max_arrows){
//         arrows = max_arrows;
//     }
//     cout << "Reloaded! Current Arrows: " << arrows << "/" << max_arrows ;
// }


string Bow::attack(Enemy* enemy){
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
