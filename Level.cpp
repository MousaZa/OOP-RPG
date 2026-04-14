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

    cout << "-------Enemies-------" << endl;

    int counter = 0;
    for(int i = 0 ; i < 3 ; i++){
        if (enemies[i].damage != 0){
        cout << i << " "; enemies[i].print();
        }else{
            counter++;
        }
    }

    if(counter == 3){
        cout << "\nLEVEL CLEARED! Press Enter To Continue.." << endl;
        cin.ignore();
        cin.get();
        return true;
        break;
    }

    int input = -1;
    while(input < 0 || input > 2){
       cout << "Choose an enemy to attack: "; cin >> input;
    }
        bool done = character->attack(&enemies[input]);
        if(!done){
            return false;  //if the weapon breaks and there's no repair
        }
        cout << "You attacked enemy " << input << endl;
        cout << "-------------------------" << endl;

        //THE ENEMY'S TURN
        int aliveCount =0; // counter for the number of alive enemies ( check how many enemies are still alive)
        for(int i=0; i<3; i++){
            if(enemies[i].hp >0)
            aliveCount++;   // increase the counter if the enemy's hp is more than 0 (alive)
        }

        // CHOOSING A RANDOM ENEMY TO ATTACK THE CHARACTER
        if(aliveCount > 0){
            int randomEnemy;
            do{
                randomEnemy = rand() % 3; 
            }while(enemies[randomEnemy].hp <=0 ); // choose an enemy randomly as long as they are alive
                
            // enemy can only attack if it is alive 
            cout << "\nEnemy " << randomEnemy << " is attacking you!" << " YOU LOST " << enemies[randomEnemy].damage << " HP!" << endl;
            cout << "Your HP now is:  " << (character->hp) - (enemies[randomEnemy].damage) << endl;
            character->takeDamage(enemies[randomEnemy].damage);  // character's hp gets decreased
            
            cout << "-------------------------" << endl;
            
            if(character->hp <= 0){
                return false;
                cout << "Press Enter to go to Main Menu" << endl;
                cin.ignore();
                cin.get();
            }
            cout << "Press Enter to attack again..";
            cin.ignore();
            cin.get();
        }
    }
    return false;
}
