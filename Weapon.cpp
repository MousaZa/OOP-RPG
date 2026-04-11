#include "Weapon.h"
#include <cstdlib>

Weapon::Weapon(){}

Weapon::Weapon(string type){
    srand(time(0));
    // type "Sword" "Wand" "Bow"
    // The Diamond Bow
    string names[10] = {"Poison", "Diamond", "Netherite", "Iron", "Fire", "Aqua", "Ice", "Forest", "Dark", "Magic"};
    int randomIndex = rand() % 10;
    name = "The " + names[randomIndex] + " " + type;

    if(type == "Sword"){
        // dmg 3-7 dur 4-10
        damage = (rand() % 5) + 3;
        durability = (rand() % 7) + 4;
    }else if(type == "Wand"){
        // dmg 1-3 dur 2-8
        damage = (rand() % 3) + 1;
        durability = (rand() % 6) + 2;
    }else if (type == "Bow"){
        // dmg 2-5 dur 2-8
        damage = (rand() % 4) + 2;
        durability = (rand() % 6) + 2;
    }

}

void Weapon::print(){
    cout << "NAME : " << name << endl;
    cout << "STATS: " << "DMG " << damage << " | " << "DUR " << durability << endl;
}

 //weapon repairing function
/*void Weapon::repair(int amount){
    durability += amount
    cout << name << " repaired! New Durability: " << durability << endl;
}
    */
