//Player.h

#pragma once
#include<string>


void printStatus(std::string name, int stat[]);
void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
void setPowDef(int count, int* p_PowInc, int* p_DefInc);
void printStatUp(std::string name, int* stat, int& HPPotion, int& MPPotion, int& PowInc, int& DefInc, bool& isGameStart);

class Monster;

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
    std::string getJob();
    void gainExp(int amount);

    virtual void attack(Monster* monster) = 0;
    virtual ~Player();

    void printPlayerStatus();
	
	

protected:
    std::string name;
    std::string job;
    int level;
    int hp;
    int MaxHp;
    int mp;
    int power;
    int defence;
    int exp;
    int maxExp;

};




