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
	this->MaxHp = hp; // 처음 입력할 적에 입력받은 hp가 MaxHp니까.
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
string Player::getJob() { return job; } //protected 안에 있는 job 꺼내서 전달.
int Player::getMaxHP() { return MaxHp; } // MaxHp 추가. Set은 나중에 MaxHp를 추가하게 되면.

void Player::printPlayerStatus()
{
	cout << "------------------------------------\n";
	cout << "Name: " << name << " | Job: " << job << " | Lv." << level << "\n";
	cout << "HP: " << hp << " | MP: " << mp << " | Attack: " << power << " | Defense: " << defence << "\n";
	cout << "------------------------------------\n";
}

//경험치 획득
void Player::gainExp(int amount) {
	this->exp += amount; //획득한 겸치를 이전 겸치와 합침.
	cout << "  -> " << amount << " EXP get! (Current EXP: " << exp << " / " << maxExp << ")\n";

	// 레벨업
	while (this->exp >= this->maxExp) { //현재 경험치가 최대 겸치 이상일 시,
		this->exp -= this->maxExp; // 현재 겸치 - 최대 겸치한 뒤, 지금 겸치에 대입.(레벨업 하고 남은 경험치)
		this->maxExp += 20;        // 다음 레벨의 필요 겸치 20 증가
		this->level++;	//레벨 증가.
		
		// 레벨업에 따른 스탯 추가
		this->MaxHp += 10;         // 최대 체력 증가
		this->hp += 10;    // 체력 증가량만큼 체력 회복
		this->mp += 5; // mp 20증가
		this->power += 5;         // 공격력 증가
		this->defence += 5; //방어 증가
		
		cout << "\n★★★ Level Up! ★★★\n";
		cout << "Lv." << level - 1 << " -> Lv." << level << " Up!\n";
		cout << "Stat Up!(hp+10 mp+5 pow-def+5)\n\n";
	}
}
