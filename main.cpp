#include "Game.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
 * Task to do before next week:
 * 1. Make Seperate Bow, Wand, Sword classes and make them children of the Weapon class
 * 2. Develop a mechanism to recover when the Weapon's durability becomes 0
 */

int main(){
    ifstream File("save.txt");

    if(File.is_open()){
        string choice;
        cout << "You have a saved game, do you want to continue? (Y,n)" ; cin >> choice;
        if (choice == "n"){
            Game game = Game();

            game.Start();
        }else{
            string field = "";
            string fields[8];
            int counter = 0;
            while(true){
                char ch = File.get();

                if(ch == '\n'){
                    fields[counter] = field;
                    field = "";
                    counter++;
                    break;
                }
                if(ch == ','){
                    fields[counter] = field;
                    field = "";
                    counter++;
                    continue;
                }

                field += ch;
                // cout << ch << endl;
            }
            // Mousa,Wizard,5,200,The Dark Wand,1,6,2
            Game game = Game();

            if(fields[1] == "Warrior"){
                game.myCharacter = new Warrior(fields[0]);
            }else if(fields[1] == "Archer"){
                game.myCharacter = new Archer(fields[0]);
            }else if(fields[1] == "Wizard"){
                game.myCharacter = new Wizard(fields[0]);
            }

            game.myCharacter->hp = stoi(fields[2]);
            game.myCharacter->xp = stoi(fields[3]);
            game.myCharacter->weapon->name = fields[4];
            game.myCharacter->weapon->damage = stoi(fields[5]);
            game.myCharacter->weapon->durability = stoi(fields[6]);
            game.currentLevel = stoi(fields[7]);

            File.close();

            game.NextLevel();


        }
    }else{
        Game game = Game();

        game.Start();
    }

    return 0;
}
