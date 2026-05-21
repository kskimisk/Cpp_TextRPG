// Main.c
#include<iostream>
#include<string>

using namespace std;

void printStatus(string name, int stat[]);

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
	
	//2-1. HP/MP 입력 블록을 while(true)로 감싸기
	while(true) // while(true)는 "조건이 항상 참이니 계속 반복해라!"라는 의미.
	{
		cout << "HP와 MP를 입력해주세요 : ";
		cin >> stat[0] >> stat[1];

		//2-2. HP와 MP가 모두 50보다 클 때만 break로 입력 루프 탈출하기
		if (stat[0] > 50 && stat[1] > 50) //stat[0](HP)이 50보다 클 때, 그리고(&&) stat[1](MP)이 50보다 클 때.
		{
			break; // 멈춘다 -> while 루프 종료 후 다음 단계로 나가기.
		} // if문 종료.

		//break에서 빠져나오면 50보다 작은 경우이므로 루프.
		cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
		 //while문이므로 멈추지 않는 이상 다시 처음으로 돌아가게 됨.
			// cin과 ==로 입력한 것은 기존 확보한 상자를 입력한 값으로 채우는 형태로, 쌓아두는 게 아니라 덮어쓰기하는 형태.
	} // 첫 번째 while문 끝.

	while(true) //혹은 true를 1로 대체 가능.
	{
		cout << "공격력과 방어력을 입력해주세요 : ";
		cin >> stat[2] >> stat[3];
		if (stat[2] > 50 && stat[3] > 50)
		{
			break;
		} // if문 종료.

		cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n";
	} // 두 번째 while문 끝.

	printStatus(name, stat);

	return 0;
} //main함수의 끝

void printStatus(string name, int stat[])
{
	cout << "\n==================================== \n";
	cout << "    " << name << " 의 현재 능력치\n";
	cout << "==================================== \n";
	cout << " HP : " << stat[0] << "     " << "MP : " << stat[1];
	cout << "\n 공격력 : " << stat[2] << "     " << "방어력 : " << stat[3];
	cout << "\n==================================== \n";
}

