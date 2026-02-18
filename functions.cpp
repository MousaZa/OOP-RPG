
#include <iostream>

using namespace std;


void print_hp(int hp){
    for(int i = 0; i < hp ; i++)
        cout << "♥ " ;
}

void print_character(string name, int hp, int power) {
    cout << name << "\t hp: " ;
    print_hp(hp);
    cout << "\t power:" << power << endl ;
}
