#include <iostream>
#include "functions.h"

using namespace std;



int main(){
    string character_name = "Mousa";
    int character_hp = 5;
    int character_power = 2;
    string character_type = "Wizard";


    print_character(character_name, character_hp, character_power);

    int i;

    cin >> i;

    if (i == 0) {
        character_hp = 3;
    }

    print_character(character_name, character_hp, character_power);
    return 0;
}
