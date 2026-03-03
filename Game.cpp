#include <iostream>

#include "Game.h"

Game::Game(){
    characterCount = 1;

    characters[0] = Character("Mousa", "Warrior");
    currentLevel = 0;
}

void Game::Start(){
    MainMenu();
}

void Game::MainMenu(){

    while(true){

        system("clear");
        int i = 0;
        for(; i < characterCount; i++){
            cout << i << " ";
            characters[i].print();
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
            Character newChar = Character(name, types[selectedType]);

            characters[characterCount] = newChar;
            characterCount++;



        }else{
            cout << "You are playing as "<<  characters[input].name << endl;
            myCharacter = characters[input];

            NextLevel();
            break;
        }

    }
}

void Game::NextLevel(){
    currentLevel++;

    cout << "You are in level " << currentLevel << " Playing as: " << endl;

    myCharacter.print_with_weapon();
}
