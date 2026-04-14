#include "Character.h"
#include <iomanip>
#define XP_COST 150

Character::Character(string n, string t) : name(n), type(t), xp(0){}

Character::Character(): name("Empty"), hp(0), power(0), type("Empty"), full_hp(0){}

void Character::print_hp(){
    for(int i = 0; i < full_hp ; i++){
        if( i < hp ){
            cout << "<3 ";
        }else {
            cout << ". " ;
        }
    }
}

void Character::print() {
    cout << name << "\t hp: " ;
    print_hp();
    cout << "\t power:" << power << "\t Type:" << type << endl ;
}

void Character::print_with_weapon(){
    cout << "LEVEL: " << get_level() << endl;
    cout << "NAME: " << name << endl;
    cout << "HP  : "; print_hp(); cout << endl;
    cout << "PWR : " << power << endl;
    cout<< "XP: " << xp << endl;
    cout << "------ Weapon -------" << endl;

    weapon->print();   //because we changed it to a pointer
}

void Character::takeDamage(int damage){
    hp -= damage;
    if (hp <= 0) {
        hp =0;
        cout << "\n------YOU ARE DEAD!-------" << endl;
        //exit(1);
    }
}

void Character::heal(int heal){
    if (hp + heal  >= full_hp) {
        hp = full_hp;

    }else{
        hp += heal;
    }
}

// Returns true if able to attack, else return flase
bool Character::attack(Enemy* enemy){

    string feedback =  weapon->attack(enemy);
    if (feedback == "Done"){
        xp += 100;
        return true;
    }else if(feedback == "Broken"){
        return false;
    }else if (feedback == "Warning"){
        cout << "WARNING: " << weapon->name << " is about to break!" << endl;
        cout << "Do you want to repair " << weapon->name << "(y/n)? : ";

        char choice;
        cin >> choice;
        if (choice == 'y') {

            int max_repairs = xp / XP_COST;

            cout << "How much do you want to repair it? (max:"<< max_repairs << "): " ;
            int amount;
            cin >> amount;
            if(xp - XP_COST * amount < 0){
                return true;
            }
            weapon->durability += amount;
            xp -= XP_COST * amount;
            cout << "-------------------------" << endl;
            cout << weapon->name << " is repaired! Durability is now: " << weapon->durability << endl;
        }

        xp += 100;
    }
    return true;

}

int Character::get_level(){
    return xp / 200;
}

/*
void Character::repair_weapon(int repair_cost, int repair_amount){
    if (xp >= repair_cost){    // if the player's xp is more than the cost you can repair your weapon
        xp -= repair_cost;     // by decreasing the player's xp by the amount of the repairing cost

        //weapon->repair(repair_amount);     // increase the
        weapon->durability += repair_amount;
        cout << "You spent " << repair_cost << " XP to repair your weapon!";
    }else {
        //if the character doesn't have enough xp:
        cout << "Not enough XP! You need " << repair_cost << " to repair your weapon!" ;
    }
}
*/
