//Job.cpp

#include<string>
#include<iostream>
#include "Warrior.h"
#include "../Monster/Monster.h"

using namespace std;

Warrior::Warrior(string name, int hp, int mp, int power, int defence)
    :Player(name, hp, mp, power, defence)
{
    this->job = "Warrior";
    this->level = 1;
    this->defence += 30;
    cout << "* You became a Warrior! (Defence +30)\n";
    cout << "* Swings sword!\n";

}

void Warrior::attack(Monster* monster) {
    int damage = this->power - monster->getMDef();
    if (damage <= 0) damage = 1;
    
    monster->setMHP(monster->getMHP() - damage);
    
    cout << " -> " << damage << " damage to " << monster->getMname() << "!\n";}

