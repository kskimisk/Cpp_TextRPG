//Monster.cpp

#include "Monster.h"
#include<iostream>
#include<string>

using namespace std;

Monster::Monster(std::string Mname, int Mhp, int Mpower, int Mdefence, std::string dropItemName, int dropItemPrice, int expReward)
{
    this->Mname = Mname;
    this->Mhp = Mhp;
    this->Mpower = Mpower;
    this->Mdefence = Mdefence;
    this->dropItemName = dropItemName;
    this->dropItemPrice = dropItemPrice;
    this->expReward = expReward;
    //변수 주는대로 받아쓰기.
}

Monster::~Monster() //Monster 사망 시 소멸.
{
    if (Mhp <= 0)
    {
        cout<<" "<<Mname<<" was dead.";
    }
    
}

void Monster::Mattack(Player* player) // 몬스터가 플레이어를 공격하는 함수
{
    int damage = this-> Mpower - player->getDef();
    
    if (damage < 0)
    {
        damage = 1;
    }
    
    int currentHP = player->getHP(); //현재 HP도 구분하면 좋을듯.
    player->setHP(currentHP - damage);
    
    cout << this->Mname << "'s Attack!\n" << damage << "Damage!\n";
    //몹의 공격! x 피해!
}


int Monster::getMHP() {return Mhp;}
void Monster::setMHP(int _hp) {Mhp = _hp;}
int Monster::getMPow() {return Mpower;}
void Monster::setMPow(int _Mpower) {Mpower = _Mpower;}
int Monster::getMDef() {return Mdefence;}
void Monster::setMDef(int _Mdefence) {Mdefence = _Mdefence;}
std::string Monster::getMname() {return Mname;}
int Monster::getMexp() {return expReward;}//겸치
std::string Monster::getdropItemName() {return dropItemName;} //드랍템


