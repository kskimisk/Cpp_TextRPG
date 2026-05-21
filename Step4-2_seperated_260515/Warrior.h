// Warrior.h
#pragma once
#include "Player.h" // 부모 클래스 Player.h의 설계도 불러오기.

class Warrior : public Player { // Player.h 불러와야 연결 가능.
public:
	// 전사 생성자 선언
	Warrior(string name, int hp, int mp, int power, int defence);

	// 공격 함수 오버라이딩 선언
	void attack() override;
};