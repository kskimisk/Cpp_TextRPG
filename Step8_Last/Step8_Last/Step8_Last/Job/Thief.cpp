#include<string>
#include<iostream>
#include "Thief.h"
#include "../Monster/Monster.h"

using namespace std;

Thief::Thief(string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence)
{
    this->job = "Thief";
    this->hp += 30;
    cout << "* You became a Thief. (HP +30)\n";
    cout << "* Stabs dagger!\n";

}

void Thief::attack(Monster* monster) {
    int damage = (this->power - monster->getMDef()) / 5;
    if (damage <= 0) damage = 1;
    
    for (int i = 0; i < 5; i++)
    {
        monster->setMHP(monster->getMHP() - damage);
    }
    
    cout << " -> " << damage << " damage to " << monster->getMname() << "! (x5)\n";
}
