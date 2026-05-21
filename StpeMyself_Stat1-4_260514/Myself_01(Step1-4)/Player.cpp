// Player.cpp

#include <iostream>
#include "Player.h"

void printStatus(string name, int stat[])
{
	cout << "\n\n====================================\n";
	cout << "     " << name << "의 현재 능력치\n";
	cout << "====================================\n";
	cout << "HP : " << stat[0] << "     MP : " << stat[1];
	cout << "\n공격력 : " << stat[2] << "     방어력 : " << stat[3];
	cout << "\n====================================\n";


}


//스탯업 부분
void StatUpStatus(string name, int stat[], int& HP_Potion, int& MP_Potion, int& att_inc, int& def_inc, bool& isGameStart)
{
	char choice; //choice의 변수 선언. case 받기 위해.

	cout << "\n\n* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다.\n";

	while (!isGameStart) // T일 때
	{
		cout << "\n============================================\n";
		cout << "       < 캐릭터 강화 >\n";
		cout << "1. HP UP    2. MP UP    3. 공격력 2배\n";
		cout << "4. 방어력 2배  5. 현재 능력치  0. 게임 시작\n";
		cout << "============================================\n";
		cout << "번호를 선택해주세요 : ";

		cin >> choice;

		switch (choice) //switch문으로 분기점 설정
		{
		case '1': //'1'을 입력한 case일 때 수행되는 것.
			if (HP_Potion >= 1) {
				stat[0] += 20;
				HP_Potion -= 1;
				cout << "* HP가 20 증가했습니다. (HP 포션 차감 : 남은 포션" << HP_Potion << "개)\n";
			}
			else {
				cout << "HP 포션이 부족합니다. (현재 잔고 : 0개)\n";
			}
			break;

		case '2':
			if (MP_Potion >= 1) {
				stat[1] += 20;
				MP_Potion -= 1;
				cout << "* MP가 20 증가했습니다. (MP 포션 차감 : 남은 포션" << MP_Potion << "개)\n";
			}
			else {
				cout << "MP 포션이 부족합니다. (현재 잔고 : 0개)\n";
			}
			break;


		case '3':
			if (att_inc >= 1) {
				stat[2] *= 2;
				att_inc -= 1;
				cout << "* 공격력이 2배 증가했습니다. (현재 공격력 : " << stat[2] << ")\n";
				cout << "남은 공격력 증가 횟수 : 0회";
			}
			else {
				cout << "공격력 증가 횟수가 부족합니다.\n";
			}
			break;


		case '4':
			if (def_inc >= 1) {
				stat[3] *= 2;
				def_inc -= 1;
				cout << "* 방어력이 2배 증가했습니다. (현재 방어력 : " << stat[3] << ")\n";
				cout << "남은 방어력 증가 횟수 : 0회";
			}
			else {
				cout << "방어력 증가 횟수가 부족합니다.\n";
			}
			break;

		case '5':
			printStatus(name, stat);
			break;

		case '0':
			cout << "게임을 시작합니다!";
			isGameStart = true; //while문을 F로 만들어서 종료
			break;

		default:
			cout << "잘못입력하셨습니다. 다시 입력해주세요. \n";
			break;
		}
	}

}

