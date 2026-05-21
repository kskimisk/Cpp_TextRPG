//Main.cpp

#include <iostream>
#include <string>
#include "Player.h"

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
		int att_inc = 1;
		int def_inc = 1;

		bool isGameStart = false;

		StatUpStatus(name, stat, HP_Potion, MP_Potion, att_inc, def_inc, isGameStart);



	return 0;
}
