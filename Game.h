
#include <iostream>
#include "Level.h"

using namespace std;

class Game{
    public:
    Character* characters[5];
    int characterCount;
    Character* myCharacter;
    int currentLevel;
    Level levels[5]; // Added the levels, (5) for now

    Game();

    void NextLevel();
    void MainMenu();
    void Start();
    void Pause();
    void Resume();
};
