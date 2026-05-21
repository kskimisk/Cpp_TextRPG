// Warrior.cpp
#include <iostream>
#include "Warrior.h"

using namespace std;

// 전사 생성자 본문: 부모 생성자에게 재료를 넘겨주는 과정
Warrior::Warrior(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	this->job = "전사";
	this->defence += 30;
	cout << "* 전사로 전직하였습니다. (방어력 +30)\n";
	cout << "* 베기!\n";

}

// 전사 전용 공격 함수 본문
void Warrior::attack() {
	cout << "베기!\n";
}