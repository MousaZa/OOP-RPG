#include "Weapon.h"

Bow::Bow() : Weapon("Bow"){
    repair_cost = 50;   // you need 50 xp to increase durability by 10
    arrows = 10;
    //durability is already set in the weapon.h
}


// A bow can be used to attack
// Arrows can be reloaded with xp?

void Bow::reload(int amount){
    arrows += amount;
    if (arrows > max_arrows){
        arrows = max_arrows;
    }
    cout << "Reloaded! Current Arrows: " << arrows << "/" << max_arrows ;
}


bool Bow::attack(Enemy* enemy){

    if (arrows <=0){ 
        cout << "You Have NO Arrows Left!" << endl;
        return false;
    }
    bool success = Weapon::attack(enemy); 

    if(arrows ==1){
        cout << "ARROW RELOAD!" << endl;
        cout << "Do you want to reload your arrows?(y/n): ";
        char choice;
        cin >> choice;
        if(choice =='y'){
        Bow::reload(5);      
        }
    }
    // 3. If the attack was successful, decrease arrows
    if (success) {
        arrows--;
    }

    return success;
}
