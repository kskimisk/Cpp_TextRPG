// Thief.cpp
#include <iostream>
#include "Thief.h"

using namespace std;

Thief::Thief(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	this->job = "도적";
	this->hp += 30;
	cout << "* 도적으로 전직하였습니다. (HP +30)\n";
	cout << "* 기습!\n";

}

void Thief::attack() {
	cout << "기습!\n";
}