#include "Character.h"

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
    cout << "----- Weapon ------" << endl;
    
    weapon->print();   //because we changed it to a pointer
}

void Character::takeDamage(int damage){
    if (hp - damage  <= 0) {
        cout << "YOU ARE DEAD!" << endl;
        exit(1);
    }
    hp -= damage;
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
    xp += 100;
    return weapon->attack(enemy);
    
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



