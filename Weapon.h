
#include <iostream>

using namespace std;


class Weapon{
    public:
    string name;
    string type;
    int damage;
    int durability;

    Weapon();
    Weapon(string);

    void print();
};
