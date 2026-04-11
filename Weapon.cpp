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
}

void Weapon::print(){
    cout << "NAME : " << name << endl;
    cout << "STATS: " << "DMG " << damage << " | " << "DUR " << durability << endl;
}

 //weapon repairing function
/*void Weapon::repair(int amount){
    durability += amount
    cout << name << " repaired! New Durability: " << durability << endl;
// Returns true if attacked and false if broken!
bool Weapon::attack(Enemy* enemy){
    if (durability <= 1){
        durability--;
        enemy->takeDamage(damage);
        cout << "Broken" << endl;
        return false;
    }else{
        durability--;
        enemy->takeDamage(damage);
        return true;
    }
}
    */
