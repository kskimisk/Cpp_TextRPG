#pragma once
#include"../Player/Player.h"

class Thief : public Player {
public:
    Thief(std::string name, int hp, int mp, int power, int defence); //계승.

    void attack(Monster* monster) override;
};
