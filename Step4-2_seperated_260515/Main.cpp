//Main.cpp

#include <iostream>
#include <string>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"

using namespace std;

int main()
{

	cout << "===========================================\n";
	cout << "       [던전 탈출 텍스트 RPG]                \n";
	cout << "===========================================\n";
	string name;

	cout << "용사의 이름을 입력해주세요 :";
	getline(cin, name);

	const int SIZE = 4;
	int stat[SIZE] = { 0 };

	while (true) {
		cout << "\nHP와 MP를 입력해주세요 :";
		cin >> stat[0] >> stat[1];

		if (stat[0] >= 50 && stat[1] >= 50) {
			break;
		}

		cout << "\nHP와 MP의 값이 너무 작습니다. 다시 입력하여 주십시오.\n";
	}

	while (true) { // 공격력과 방어력 입력;
		cout << "\n공격력과 방어를 입력해주세요 :";
		cin >> stat[2] >> stat[3];

		if (stat[2] >= 50 && stat[3] >= 50) {
			break;
		}

		cout << "\n공격력과 방어력의 값이 너무 작습니다. 다시 입력하여 주십시오.\n";
	}

	printStatus(name, stat);


	int HP_Potion = 5;
	int MP_Potion = 5;
	int pow_inc = 1;
	int def_inc = 1;

	bool isGameStart = false;

	StatUpStatus(name, stat, HP_Potion, MP_Potion, pow_inc, def_inc, isGameStart);

	//Step4. 직업 추가.
	// 아, 이거 전에 .h파일들 연결해야.
	Player* player = nullptr; //Player를 직업 클래스와 연결할 컨트롤러 준비.

	cout << "\n\n< 전직 시스템 >\n";
	cout << name << "님, 직업을 선택해주세요!\n"; // 입력받은 진짜 이름 출력.
	cout << "1. 전사   2. 마법사  3. 도적   4. 궁수\n";
	cout << "선택: ";

	while (true) {
		//직업 선택에 입력.
		int jobChoice;
		cin >> jobChoice;

		if (jobChoice == 1) {
			player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
			break;
		}
		else if (jobChoice == 2) {
			player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
			break;
		}
		else if (jobChoice == 3) {
			player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
			break;
		}
		else if (jobChoice == 4) {
			player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
			break;
		}
		else {
			cout << "잘못된 선택입니다. 직업을 다시 선택해주세요.\n";

		}
		//선택할 때까지 무한반복이 되도록, break; 없음.
	}


	cout << "\n\n------[전직 완료]------\n";
	player->printPlayerStatus();

	delete player; // 프로그램 종료 전 delete player 호출.

	return 0;
}
