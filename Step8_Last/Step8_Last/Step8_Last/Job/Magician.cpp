//Job.cpp

#include<string>
#include<iostream>
#include "Magician.h"
#include "../Monster/Monster.h"

using namespace std;

Magician::Magician(string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence)
{
    this->job = "Magician";
    this->mp += 30;
    cout << "* You became a Mage (MP +30)\n";
    cout << "* Fire Fireball!\n";
}

void Magician::attack(Monster* monster) {
    int damage = this->power - monster->getMDef();
    if (damage <= 0) damage = 1;
    
    monster->setMHP(monster->getMHP() - damage);
    
    cout << " -> " << damage << " damage to " << monster->getMname() << "!\n";
}
