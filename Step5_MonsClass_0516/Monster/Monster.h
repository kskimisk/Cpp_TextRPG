#pragma once
#include <string>
#include "../Player/Player.h"



//Player class 따라하기
class Monster
{
public:
    Monster(std::string Mname, int Mhp, int Mpower, int Mdefence, std::string dropItemName, int dropItemPrice, int expReward);
    // 도전 2-3
    
    int getMHP();
    void setMHP(int _Mhp);
    int getMPow();
    void setMPow(int _Mpower);
    int getMDef();
    void setMDef(int _Mdefence);
    int getMexp();
    void setMexp(int _expReward); // Ch.2-3 / Monster EXP
    std::string getMname();
    std::string getdropItemName();
    
    
    virtual void Mattack(Player*player); //몬스터가 플레이어 공격
    virtual ~Monster();
    
protected:
    std::string Mname;
    std::string Mtype;
    std::string dropItemName;
    int dropItemPrice;
    int Mhp;
    int Mpower;
    int Mdefence;
    int expReward;
        
    
};
