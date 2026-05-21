#include<string>
#include<iostream>
#include "Archer.h"
#include "../Monster/Monster.h"

using namespace std;

Archer::Archer(string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence)
{
    this->job = "Archer";
    this->power += 30;
    cout << "* You became a Archer. (Attack +30)\n";
    cout << "* Shoots arrow!\n";
}

void Archer::attack(Monster* monster) {
    cout << "Shoots arrow!\n";
	
    int damage = (this->power - monster->getMDef()) / 3;
    if (damage <= 0) damage = 1;
	
    for (int i = 0; i < 3; i++)
    {
        monster->setMHP(monster->getMHP() - damage);
    }
    cout << " -> " << damage << "damage to" <<monster->getMname() << "(x3)\n";

}