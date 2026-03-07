#include "Level.h"

Level::Level(){}

Level::Level(int number, Character c): levelNumber(number), character(c){} // Constructor

void Level::start(){ // Starting the level here

    character.print_with_weapon();

    for(int i = 0 ; i < 3 ; i++){
        enemies[i].print();
    }
}
