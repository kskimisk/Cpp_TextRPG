#pragma once
#include <string>

using namespace std;

void printStatus(string name, int stat[]);
void StatUpStatus(string name, int stat[], int& HP_Potion, int& MP_Potion, int& pow_inc, int& def_inc, bool& inGameStart);
//포션 편경되는 걸 반영하기 위해 &참조자를 넣기.
// 복사본이 아니라, main함수의 내용을 참조 하는 역할.


//Step4- Player 클래스

class Player {
protected:
	string name;
	string job;
	int level;
	int hp;
	int mp;
	int power;
	int defence;

public:
	// 생성자 및 가상 소멸자 선언 (세미콜론으로 끝냄!)
	Player(string name, int hp, int mp, int power, int defence); //생성.
	virtual ~Player(); //죽음.

	// 순수 가상함수
	virtual void attack() = 0; // 행동.

	// Getter / Setter 및 상태창 출력 함수 선언
	//얘들도 함수라서 헤드에 선언은 해둬야함.
	int getHp();
	void setHp(int _hp);
	int getMp();
	void setMp(int _mp);
	int getPow();
	void setPow(int _power);
	int getDef();
	void setDef(int _defence);

	void printPlayerStatus();
};

// 객체지향의 의존성을 낮추기 위해 각 직업의 헤드파일은 따로.