#include <cstdio>
#include <cstdlib>
#include <fstream>
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

        system("clear");
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
        // --------

        ofstream File("save.txt");
        // Mousa,Wizard,5,200,The Dark Wand,100,100,2

        if(File.is_open()){
        File << myCharacter->name << ",";
        File << myCharacter->type << ",";
        File << myCharacter->hp << ",";
        File << myCharacter->xp << ",";
        File << myCharacter->weapon->name << ",";
        File << myCharacter->weapon->damage << ",";
        File << myCharacter->weapon->durability << ",";
        File << currentLevel << "\n";
        }

        File.close();

        // --------
        currentLevel++;

        Level newLevel = Level(currentLevel, myCharacter);
        won = newLevel.start();
    }
    system("rm save.txt");
    cout << "------- GAME OVER -------" << endl;
    cout << endl;
    cout << "Press Enter to return to main menu...";
}
