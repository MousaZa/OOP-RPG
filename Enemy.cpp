#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(int h, int d) : hp(h), damage(d){} // Constructor
Enemy::Enemy():hp(0), damage(0){} // Empty Constructor

void Enemy::print(){ // Really simple print
    cout << "HP:" << hp << "\t DMG:" << damage << endl;
}
