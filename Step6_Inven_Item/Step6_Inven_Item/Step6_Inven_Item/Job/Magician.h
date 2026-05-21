//Job.h
#pragma once
#include"../Player/Player.h"

class Magician : public Player {
public:
    Magician(std::string name, int hp, int mp, int power, int defence); //계승.

    void attack(Monster* monster) override;
};
