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

}

Monster::~Monster()
{
    if (Mhp <= 0)
    {
        cout<<" "<<Mname<<" was dead.";
    }
    
}

void Monster::Mattack(Player* player)
{
    int damage = this-> Mpower - player->getDef();
    
    if (damage < 0)
    {
        damage = 1;
    }
    
    int currentHP = player->getHP();
    player->setHP(currentHP - damage);
    
    cout << this->Mname << "'s Attack!\n" << damage << "Damage!\n";
}


int Monster::getMHP() {return Mhp;}
void Monster::setMHP(int _hp) {Mhp = _hp;}
int Monster::getMPow() {return Mpower;}
void Monster::setMPow(int _Mpower) {Mpower = _Mpower;}
int Monster::getMDef() {return Mdefence;}
void Monster::setMDef(int _Mdefence) {Mdefence = _Mdefence;}
std::string Monster::getMname() {return Mname;}
int Monster::getMexp() {return expReward;}//겸치
std::string Monster::getdropItemName() {return dropItemName;}
int Monster::getdropItemPrice(){ return dropItemPrice; } //아이템 가격에 연결


