#include "Character.h"

Wizard::Wizard(string n) : Character(n, "Wizard"){
    hp = 5;
    full_hp = 5;
    power = 4;
    weapon = new Wand();
    
}
