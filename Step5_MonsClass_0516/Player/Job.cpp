//Job.cpp

#include<string>
#include<iostream>
#include "Player.h"
#include "Job.h"
#include "../Monster/Monster.h"

using namespace std;

//Àü»ç
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



//¸¶¹ý»ç
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



//µµµÏ
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



//±Ã¼ö
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