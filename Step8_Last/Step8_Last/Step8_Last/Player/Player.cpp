//Player.cpp

#include<iostream>
#include<string>
#include"Player.h"

using namespace std;

void printStatus(string name, int stat[])
{


	cout << "====================================\n";
	cout << "	" << name << "'s Stats\n";
	cout << "====================================\n";
	cout << "  HP: " << stat[0] << "		MP : " << stat[1];
	cout << "\n  Attack : " << stat[2] << "		Defense : " << stat[3];
	cout << "\n====================================\n";
}

void printStatUp(string name, int* stat, int& HPPotion, int& MPPotion, int& PowInc, int& DefInc, bool& isGameStart)
{

	char choice = ' ' ;


	cout << "\nYou received 5 HP Potions and 5 MP Potions.";

	while (!isGameStart)
	{
		cout << "\n============================================\n";
		cout << "	< Character Upgrade >\n";
		cout << "1. HP UP (" << HPPotion << "ea)    2. MP UP (" << MPPotion << "ea)    3. 2X Attack (" << PowInc << "/1)\n";
		cout << "4. 2X Defense (" << DefInc << "/1)  5. Show Stats  0. Start Game\n";
		cout << "============================================\n";
		cout << "choose no. : ";

		cin >> choice;

		switch (choice)
		{
		case '1':
			if (HPPotion > 0) {
				stat[0] += 20;
				HPPotion -= 1;
				cout << "* HP increased by 20. (HP Potion used: " << HPPotion << " left)\n";
			}
			else {
				cout << "Not enough items.\n";
			}
			break;
		case '2':
			if (MPPotion > 0) {
				stat[1] += 20;
				MPPotion -= 1;
				cout << "* MP increased by 20. (MP Potion used: " << MPPotion << " left)\n";
			}
			else {
				cout << "Not enough items.\n";
			}
			break;
		case '3':
			if (PowInc > 0) {
				stat[2] *= 2;
				PowInc -= 1;
				cout << "* Attact X2. ( 0 left)\n";
			}
			else {
				cout << "Not enough counts.\n";
			}
			break;
		case '4':
			if (DefInc > 0) {
				stat[3] *= 2;
				DefInc -= 1;
				cout << "* Defense 2X. ( 0 left)\n";
			}
			else {
				cout << "Not enough counts.\n";
			}
			break;
		case '5':
			printStatus(name, stat);
			break;

		case '0':
			cout << "Game Start!";
			isGameStart = true;
			break;

		default:
			cout << "Error! Input Again.";
			break;
		}


	}
}

Player::Player(std::string name, int hp, int mp, int power, int defence)
{
	this->name = name;
	this->hp = hp;
	this->MaxHp = hp;
	this->mp = mp;
	this->power = power;
	this->defence = defence;
	this->job = "Junior";
	this->level = 1;
	
	this->exp = 0;
	this -> maxExp = 100;
}

Player::~Player() {
}

int Player::getHP() {return hp;}
void Player::setHP(int _hp) {hp = _hp;}
int Player::getMP() { return mp; }
void Player::setMP(int _hp) { mp = _hp; }
int Player::getPow() { return power; }
void Player::setPow(int _power) { power = _power; }
int Player::getDef() { return defence; }
void Player::setDef(int _defence) { defence = _defence; }
string Player::getJob() { return job; }
int Player::getMaxHP() { return MaxHp; }

void Player::printPlayerStatus()
{
	cout << "------------------------------------\n";
	cout << "Name: " << name << " | Job: " << job << " | Lv." << level << "\n";
	cout << "HP: " << hp << " | MP: " << mp << " | Attack: " << power << " | Defense: " << defence << "\n";
	cout << "------------------------------------\n";
}

void Player::gainExp(int amount) {
	this->exp += amount;
	cout << "  -> " << amount << " EXP get! (Current EXP: " << exp << " / " << maxExp << ")\n";

	while (this->exp >= this->maxExp) {
		this->exp -= this->maxExp;
		this->maxExp += 20;
		this->level++;
		

		this->MaxHp += 10; 
		this->hp += 10; 
		this->mp += 5;
		this->power += 5; 
		this->defence += 5;
		
		cout << "\n★★★ Level Up! ★★★\n";
		cout << "Lv." << level - 1 << " -> Lv." << level << " Up!\n";
		cout << "Stat Up!(hp+10 mp+5 pow-def+5)\n\n";
	}
}
