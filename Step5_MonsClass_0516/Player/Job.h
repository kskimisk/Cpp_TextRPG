//Job.h
#pragma once
#include"Player.h"

class Warrior : public Player {
public:
	Warrior(std::string name, int hp, int mp, int power, int defence); //°è½Â.

	void attack(Monster* monster) override;
};

class Magician : public Player {
public:
	Magician(std::string name, int hp, int mp, int power, int defence); //°è½Â.

	void attack(Monster* monster) override;
};

class Thief : public Player {
public:
	Thief(std::string name, int hp, int mp, int power, int defence); //°è½Â.

	void attack(Monster* monster) override;
};

class Archer : public Player {
public:
	Archer(std::string name, int hp, int mp, int power, int defence); //°è½Â.

	void attack(Monster* monster) override;
};

