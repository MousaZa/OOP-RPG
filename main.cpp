#include <iostream>

using namespace std;

// Make the user create a new character

class Character{
    public:
    string name;
    int hp;
    int power;
    string type;

    // constructor
    Character(string n, string t) : name(n), type(t){
            if (t == "Wizard"){
                    hp = 5;
                    power = 4;
                }else if (t == "Archer"){
                    hp = 7;
                    power = 3;
                }else if(t == "Warrior"){
                    hp = 10;
                    power = 2;
                }else{
                    cout << "Wrong type" << endl;
                    exit(1);
                }
    }
    Character(): name("Empty"), hp(0), power(0), type("Empty"){}

    void print_hp(){
        for(int i = 0; i < hp ; i++)
            cout << "♥ " ;
    }

    void print() {
        cout << name << "\t hp: " ;
        print_hp();
        cout << "\t power:" << power << "\t Type:" << type << endl ;
    }

};


int main(){
    int counter = 1;

    Character characters[5];

    characters[0] = Character("Mousa", "Warrior");

    bool isInMainmenu = true;

    while(isInMainmenu){

    system("clear");

    for(int i = 0; i < 5; i++){
        cout << i << " ";
        characters[i].print();
    }

    cout << "5 Create a new character" << endl;

    int input = -1;

    while (input > 5 || input < 0) {
        cout << "Please choose a character: "; cin >> input;
    }

    if(input == 5){
        string name, type;

        cout << "Enter the name: "; cin >>name;
        cout << "Enter the type: "; cin >>type;

        Character newChar = Character(name, type);

        characters[counter] = newChar;
        counter++;



    }else{
        cout << "You are playing as "<<  characters[input].name << endl;
        isInMainmenu = false;
    }

}



    // string names[5] = {"Mousa", "Ahmet"};
    // int hps[5] = {5, 7};
    // int powers[5] = {2, 1};
    // string types[5] = {"Wizard", "Archer"};

    // // Character charachters[5];

    // for(int i = 0; i < 5; i++){
    //     cout << i << " " ;
    //     print_character(names[i], hps[i], powers[i], types[i]);
    // }

    // cout << "5 Create a new character" << endl;

    // int input;

    // cout << "Please choose a character: " ; cin >> input;

    // if (input == 5){
    //     string name;
    //     int hp;
    //     int power;
    //     string type;

    //     cout << "Enter the name: "; cin >> name;
    //     cout << "Enter the type: "; cin >> type;

    //     if (type == "Wizard"){
    //         hp = 5;
    //         power = 4;
    //     }else if (type == "Archer"){
    //         hp = 7;
    //         power = 3;
    //     }else if(type == "Warrior"){
    //         hp = 10;
    //         power = 2;
    //     }else{
    //         cout << "Wrong type" << endl;
    //         exit(1);
    //     }


    //     names[counter] = name;
    //     hps[counter] = hp;
    //     powers[counter] = power;
    //     types[counter] = type;
    //     counter++;

    // }else{
    //     cout << "You are playing as " << names[input] << endl;
    // }

    // for(int i = 0; i < 5; i++){
    //         cout << i << " " ;
    //         print_character(names[i], hps[i], powers[i], types[i]);
    //     }
    return 0;
}
