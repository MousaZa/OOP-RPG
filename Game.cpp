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
        cout << "Please choose a character: "; cin >> input;
            while (input > i || input < 0) {
                cout << "Invalid.. Please choose a character: "; cin >> input;
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
            Character *newChar;
            switch (selectedType) {
                case 0:
                newChar = new Warrior(name);
                break;
                case 1:
                newChar = new Archer(name);
                break;
                case 2:
                newChar = new Wizard(name);
                break;
                default:
                    break;
            }
            characterCount++;


        }else{
            //my character is now a pointer pointing to the selected characetr
            myCharacter = characters[input];
            cout << "You are playing as "<<  characters[input]->name << endl;
            cout << "Press Enter to start the game!";
            cin.ignore();
            cin.get();
            
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
    cout << "------- GAME OVER -------" << endl;
    cout << endl;
    cout << "Press Enter to return to main menu...";
}
