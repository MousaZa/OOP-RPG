
#include <iostream>
#include "Character.h"

using namespace std;

class Game{
    public:
    Character characters[5];
    int characterCount;
    // Weapon weapons[5];
    Character myCharacter;
    int currentLevel;

    Game();

    void NextLevel();
    void MainMenu();
    void Start();
    void Pause();
    void Resume();
};
