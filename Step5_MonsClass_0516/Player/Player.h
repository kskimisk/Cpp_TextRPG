//Player.h

#pragma once
#include<string>


void printStatus(std::string name, int stat[]);
void setPotion(int count, int* p_HPPotion, int* p_MPPotion); //도전 1;
void setPowDef(int count, int* p_PowInc, int* p_DefInc); // St3 / 도전 1 응용;
void printStatUp(std::string name, int* stat, int& HPPotion, int& MPPotion, int& PowInc, int& DefInc, bool& isGameStart);

class Monster;//함수처럼 선언.

class Player {

public:
	Player(std::string name, int hp, int mp, int power, int defence);

	int getHP();
	void setHP(int _hp);
	int getMaxHP();
	//void setMaxHP(int _maxHP); // MaxHp를 추가하게 된다면 사용.
	int getMP();
	void setMP(int _mp);
	int getPow();
	void setPow(int _power);
	int getDef();
	void setDef(int _defence);
	std::string getJob(); //+ job 알려주기. Main()에서 직업 출력할 때.
	void gainExp(int amount);

	virtual void attack(Monster* monster) = 0; // 도전 2-2
	virtual ~Player();

	void printPlayerStatus();
	
	

protected:
	std::string name;
	std::string job;
	int level;
	int hp;
	int MaxHp; // 최대 체력 추가.
	int mp;
	int power;
	int defence;
	int exp;
	int maxExp;

};




