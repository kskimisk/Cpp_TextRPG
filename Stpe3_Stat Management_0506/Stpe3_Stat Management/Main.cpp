// Main.c
#include<iostream>
#include<string>

using namespace std;

void printStatus(string name, int stat[]); //숙제 : 선언 안 하고 할 수 있게 하는 방법 찾기

int main()
{
	cout << "========================================== = \n";
	cout << "	[던전 탈출 텍스트 RPG]\n";
	cout << "========================================== = \n";
	string name;

	cout << "용사의 이름을 입력해주세요 : ";
	getline(cin, name);

	const int SIZE = 4;
	int stat[SIZE] = { 0 };

	while (true)
	{
		cout << "HP와 MP를 입력해주세요 : ";
		cin >> stat[0] >> stat[1];

		if (stat[0] > 50 && stat[1] > 50)
		{
			break; 
		}
		cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
	
		
	}

	while (true)
	{
		cout << "공격력과 방어력을 입력해주세요 : ";
		cin >> stat[2] >> stat[3];
		if (stat[2] > 50 && stat[3] > 50)
		{
			break;
		}

		cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n";
	}

	printStatus(name, stat);

	//3-1. HP / MP 포션 각 5개를 변수로 선언하기.;
		//스탯 관리 메뉴는 게임 시작 전 1회성으로 보이는 메뉴라서, 함수 설정 없이 int main 안에서.;


	int HP_Potion = 5;
	int MP_Potion = 5; //초기화(5개를 변수로 선언).;

	//7번과 8번, 능력치 증가 변수

	int IncAtt = 1; // 공격 증가
	int IncDef = 1; // 방어 증가

	//bool isGameStart = false; 같은 종료 플래그 만들기.;
	bool isGameStart = false;  // bool로 인해 참(true)와 거짓(false)만 존재하며, !isGameStart는 !false, 즉 true가 됨.

	// choice의 변수 선언.;
	char choice;	// stat[]과 달리 배열 없이 case의 숫자 입력을 받기 위해서 필요.;
					// 사용자가 숫자가 아닌 문자를 입력할 것을 대비하여 int 대신 char.;

	

	//while(!isGameStart) + switch(choice)로 메뉴 루프 구현하기

	while (!isGameStart) // !로 인하여 0번을 누를 시 !true는 false가 되고, while문에서 나가게 됨.
	{
		// while문 안에서 출력이 되어야, 선택문을 선택 시에도 메뉴가 반복해서 등장.
		cout << "\n\n* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다.";
		cout << "\n============================================\n";
		cout << "               < 캐릭터 강화 >\n";
		cout << "1. HP UP" << "    2. MP UP" << "    3. 공격력 2배\n";
		cout << "4. 방어력 2배" << "  5. 현재 능력치" << "  0. 게임 시작";
		cout << "\n============================================\n";
		cout << "번호를 선택해주세요 : ";
		
		// choice가 입력을 받아야 switch문이 동작.
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			if (HP_Potion >= 1) // 포션이 1개 이상 있을 시.
			{
				stat[0] += 20;
				HP_Potion -= 1;
				cout << "* HP가 20 증가했습니다. (HP포션 차감 : 남은 포션 " << HP_Potion << "개)\n";
			}
			else if (HP_Potion <= 0) // 포션이 없을 때.
			{
				cout << "HP 포션 부족\n";
			}
			else //만약 두 경우가 아닌 상황이 발생 시 진짜 오류.
			{
				cout << "오류입니다.\n";
			}
			break; // case '1'이 종료 후 switch문 빠져나오기.

		}

		case '2': // HP_Potion 코드 복사
		{
			if (MP_Potion >= 1) // 포션이 1개 이상 있을 시.
			{
				stat[1] += 20;
				MP_Potion -= 1;
				cout << "* MP가 20 증가했습니다. (MP포션 차감 : 남은 포션 " << MP_Potion << "개)\n";
			}
			else if (MP_Potion <= 0) // 포션이 없을 때.
			{
				cout << "MP 포션 부족\n";
			}
			else //만약 두 경우가 아닌 상황이 발생 시 진짜 오류.
			{
				cout << "오류입니다.\n";
			}
			break; // case '2'이 종료 후 switch문 빠져나오기.

		}

		case '3': //능력치 증가 포션이 아니라, 처음 능력치를 조정하는 부분이라고 판단.
					// 하지만 횟수를 무제한으로 늘릴 시 2배씩 계속 증가하여 오류 생길 수도 있기에 횟수 제한.
					// 횟수를 제한할 경우 능력치 증가 옵션으로 사용가능할 것으로 보임.
		{
			if (IncAtt >= 1) // 공격 증가 1회 가능할 시.
			{
				stat[2] *= 2;
				IncAtt -= 1;
				cout << "* 공격력이 2배 증가하였습니다. (현재 공격력 : " << stat[2] << ")\n";
				cout << "(공격력 증가는 1회만 가능합니다.)\n";
			}
			else if (IncAtt <= 0) // 공격력 증가 횟수가 없을 때.
			{
				cout << "공격력 증가 횟수 부족\n";
			}
			else //만약 두 경우가 아닌 상황이 발생 시 진짜 오류.
			{
				cout << "오류입니다.\n";
			}
			break; // case '3'이 종료 후 switch문 빠져나오기.

		}

		case '4': //공격력 증가와 동일.
		{
			if (IncDef >= 1) // 방어력 증가 1회 가능할 시.
			{
				stat[3] *= 2;
				IncDef -= 1;
				cout << "* 방어력이 2배 증가하였습니다. (현재 방어력 : " << stat[3] << ")\n";
				cout << "(방어력 증가는 1회만 가능합니다.)\n";
			}
			else if (IncDef <= 0) // 방어력 증가 횟수가 없을 때.
			{
				cout << "방어력 증가 횟수 부족\n";
			}
			else //만약 두 경우가 아닌 상황이 발생 시 진짜 오류.
			{
				cout << "오류입니다.\n";
			}
			break; // case '4'이 종료 후 switch문 빠져나오기.

		}


		case '5': // 능력치 소환.
		{
			printStatus(name, stat); // 함수 호출
			break;
		}


		case '0':
		{
			cout << "게임을 시작합니다!";
			isGameStart = true; // switch를 true로 변경하여 break 후 루프 빠져나옴.
			break;
		}

		default: // 0~5 숫자 외의 문자를 입력했을 시.
			cout << "잘못 입력하셨습니다. 다시 선택해주세요.\n";
			break;
		}
	}


	return 0;
}

void printStatus(string name, int stat[])
{
	cout << "\n==================================== \n";
	cout << "    " << name << " 의 현재 능력치\n";
	cout << "==================================== \n";
	cout << " HP : " << stat[0] << "     " << "MP : " << stat[1];
	cout << "\n 공격력 : " << stat[2] << "     " << "방어력 : " << stat[3];
	cout << "\n==================================== \n";
}





//- []  HP / MP 포션 각 5개를 변수로 선언하기
//- []  `bool isGameStart = false; ` 같은 종료 플래그 만들기
//- []  `while(!isGameStart)` + `switch(choice)`로 메뉴 루프 구현하기
//- []  1번: HP + 20, HP 포션 차감
//- []  2번 : MP + 20, MP 포션 차감
//- []  HP / MP 포션이 0개면 "포션 부족" 출력하기
//- []  3번 : 공격력 2배
//- []  4번 : 방어력 2배
//- []  5번 : 현재 능력치 출력
//- []  0번 : "게임을 시작합니다!" 출력 후 `isGameStart = true`