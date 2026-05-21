
#pragma once
#include "../Player/Player.h" 

class Warrior : public Player {
public:
    Warrior(std::string name, int hp, int mp, int power, int defence); //계승.

    void attack(Monster* monster) override;
};