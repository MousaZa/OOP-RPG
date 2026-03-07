#include <iostream>
#include "Character.h"

using namespace std;

class Enemy{
    public:
    int hp, damage;

    Enemy(int, int);
    Enemy();

    void print();
};
