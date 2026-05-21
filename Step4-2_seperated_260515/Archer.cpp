// Archer.cpp
#include <iostream>
#include "Archer.h"

using namespace std;

Archer::Archer(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	this->job = "궁수";
	this->power += 30;
	cout << "* 궁수로 전직하였습니다. (공격력 +30)\n";
	cout << "* 사격!\n";
}

void Archer::attack() {
	cout << "사격!\n";
}