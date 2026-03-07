#include <iostream>
#include "Enemy.h"

using namespace std;

class Level{
    public:
    Character character; // To store my character and it status
    Enemy enemies[3]; // Every level will have 3 enemies
    int levelNumber; // What is the curret level (We will use this later to control difficulty)

    Level(int, Character);
    Level();

    void start();
};
