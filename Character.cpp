#include "Character.h"

Character::Character(string n, string t) : name(n), type(t){
    if (t == "Wizard"){
        hp = 5;
        full_hp = 5;
        power = 4;
        weapon = Weapon("Wand");
    }else if (t == "Archer"){
        hp = 7;
        full_hp = 7;
        power = 3;
        weapon = Weapon("Bow");
    }else if(t == "Warrior"){
        hp = 10;
        full_hp = 10;
        power = 2;
        weapon = Weapon("Sword");
    }else{
        cout << "Wrong type" << endl;
        exit(1);
    }
}

Character::Character(): name("Empty"), hp(0), power(0), type("Empty"){}

void Character::print_hp(){
    for(int i = 0; i < full_hp ; i++){
        if( i < hp ){
            cout << "♥ " ;
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
    cout << "NAME: " << name << endl;
    cout << "HP  : "; print_hp(); cout << endl;
    cout << "PWR : " << power << endl;
    cout << "----- Weapon ------" << endl;
    weapon.print();
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
