// Magician.cpp
#include <iostream>
#include "Magician.h"

using namespace std;

Magician::Magician(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	this->job = "마법사";
	this->mp += 30;
	cout << "* 마법사로 전직하였습니다. (MP +30)\n";
	cout << "* 파이어볼!\n";

}

void Magician::attack() {
	cout << "파이어볼!\n";
}