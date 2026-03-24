#include <iostream>

#include "Game.h"

Game::Game(){
    characterCount = 1;

    characters[0] = new Wizard("Mousa");
    currentLevel = 0;
}

void Game::Start(){
    MainMenu();
}

void Game::MainMenu(){
    while(true){

        system("cls");
        int i = 0;
        for(; i < characterCount; i++){
            cout << i << " ";
            characters[i]->print();
        }
        cout << i << " Create a new character" << endl;

        int input = -1;
        while (input > i || input < 0) {
            cout << "Please choose a character: "; cin >> input;
        }

        if(input == i){
            string name;
            int selectedType = -1;
            string types[3] = {"Warrior", "Archer", "Wizard"};

            cout << "Enter the name: "; cin >>name;
            for(int i = 0; i < 3; i++){
                cout << i << " " << types[i] << endl;
            }

            while(selectedType > 2 || selectedType < 0){
                cout << "Enter the type: "; cin >>selectedType;
            }
        
            switch (selectedType) {
                case 0:
                    characters[characterCount] = new Warrior(name);
                    break;
                case 1:
                    characters[characterCount] = new Archer(name);
                    break;
                case 2:
                    characters[characterCount] = new Wizard(name);
                    break;
                default:
                    break;
            }
            characterCount++;


        }else{
            //my character is now a pointer pointing to the selected characetr
            myCharacter = characters[input];
            cout << "You are playing as "<<  characters[input]->name << endl;
            
            NextLevel();
            break;
        }
    }
}

void Game::NextLevel(){
    bool won = true;
    while(won){
        currentLevel++;

        Level newLevel = Level(currentLevel, myCharacter);
        won = newLevel.start();
    }
    cout << "Game Over!" << endl;
}
