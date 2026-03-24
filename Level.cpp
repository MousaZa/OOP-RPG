#include "Level.h"
#include <cstdlib>

Level::Level(){}

Level::Level(int number, Character* c): levelNumber(number), character(c){
    srand(time(0));

    for(int i = 0; i < 3; i++){
        int hp = rand() % (levelNumber * 3) + 1;
        int damage = rand() % (levelNumber * 3) + 1;
        enemies[i] = Enemy(hp, damage);
    }
} // Constructor

bool Level::start(){ // Starting the level here
    while(true){
    system("cls");
    character->print_with_weapon();

    cout << "------Enemies-------" << endl;

    int counter = 0;
    for(int i = 0 ; i < 3 ; i++){
        if (enemies[i].damage != 0){
        cout << i << " "; enemies[i].print();
        }else{
            counter++;
        }
    }

    if(counter == 3){
        return true;
        break;
    }

    int input = -1;
    while(input < 0 || input > 2){
       cout << "Choose an enemy to attack: "; cin >> input;
    }
        bool done = character->attack(&enemies[input]);
        if(!done){
            return false;
        }
    }
    return false;
}
