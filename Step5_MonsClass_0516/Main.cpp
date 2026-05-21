//Main. cpp

#include <string>
#include <iostream>
#include "Player/Player.h"
#include "Player/Job.h"
#include "Monster/Monster.h"
#include "Monster/Slime.h"
#include <algorithm>


using namespace std;

int main()
{

	string name;

	cout << "========================================== =\n";
	cout << "	[Dungeon Escape Text RPG]\n";
	cout << "========================================== =\n";
	cout << "\nEnter your hero's name: ";
	getline(cin, name);

	

	const int SIZE = 4;
	int stat[SIZE] = { 0 };

	while (true) {
		cout << "\nEnter HP and MP (min : 50) : ";
		cin >> stat[0] >> stat[1];
		if (stat[0] >= 50 && stat[1] >= 50)
		{
			break;
		}
		cout << "HP or MP is too low. Try again.\n";
		
	}
		
	while (true) {
		cout << "\nEnter Attack and Defense (min : 50) : ";
		cin >> stat[2] >> stat[3];
		if (stat[2] >= 50 && stat[3] >= 50)
		{
			break;
		}
		cout << "Attack or Defense is too low. Try again.\n";

	}		

	printStatus(name, stat);


	int HPPotion = 0;
	int MPPotion = 0;
	int PowInc = 0;
	int DefInc = 0;

	bool isGameStart = false;


	setPotion(5, &HPPotion, &MPPotion);// 도전1;
	setPowDef(1, &PowInc, &DefInc);
		
	printStatUp(name, stat, HPPotion, MPPotion, PowInc, DefInc, isGameStart);

	Player*	player = nullptr;
	
	cout << "	< Job Selection >\n";
	cout << " " << name << ", choose your job!\n";
	cout << " 1. Warrior   2. Mage   3. Thief   4. Archer\n";
	cout << "Choice : ";

	while (1) {
		int jobChoice;
		cin >> jobChoice;
		
		if (jobChoice == 1)
		{
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
			cout << "Error. Choise Your Job Again.\n";

		}

	} //job select
	
	cout << "\n\n------[Job Selected Complete]------\n";
	player->printPlayerStatus();

	
	//Step5 - Monster class + 1:1 battle
	
	Monster* currentMonster = new Slime();//Monster 주소 소환, 지금 몹은 슬라임.

	cout << "\n[ Battle Start! ]" << name <<"("<< player->getJob() <<")  vs  " << currentMonster->getMname() <<"\n";

	
	while (player->getHP() > 0 && currentMonster->getMHP() > 0)// 5-8 구현항목
	{// Player Turn부터 계속 나와야 하니까
		cout << "\n- - - Player Turn - - -\n";
		cout << "1. Attack\n";
		cout << "2. Use Item\n";
		cout << "--------------------\n";
		cout << "choose : ";	
	
		int battleChoice;
		cin >> battleChoice;
		
		if (battleChoice == 1)
		{
			player->attack(currentMonster);
			
			if (currentMonster->getMHP() <= 0) break;
			
		}
		else if (battleChoice == 2)
		{
			cout << "[ Inventory ]";
			cout << "1. HP Potion (50G) ("<<HPPotion<<"ea)\n";
			cout << "2. MP Potion (50G) ("<<MPPotion<<"ea)\n";
			
			int itemChoice;
			cin >> itemChoice;
			
			if (itemChoice == 1)
			{
				if (HPPotion>=1)
				{
					HPPotion--;
					//만약 HP가 최대치 제한이 없다면.
					// player->setHP(player->getHP() + 50);
					player->setHP(min(player->getHP() +50, player->getMaxHP())); //도전과제 4-3
					// MaxHP도 설정해야할 듯.
					cout<<" * HP Potion used! HP restored by 50 (Current HP : "<<player->getHP()<<")\n";
					//최대 체력 필요함. 최대체력은 Player.h에 MaxHP 세팅.
				}
				
				else
				{
					cout << "No Potion\n";
				}
				
			}
			
			else if (itemChoice == 2)
			{
				if (MPPotion>=1)
				{
					MPPotion--;
					player->setMP(min(player->getMP() +50, player->getMP()));
					cout<<" * MP Potion used! MP restored by 50 (Current MP : "<<player->getMP()<<")\n";
				}
				else
				{
					cout << "No Potion\n";
				}
			}
			
			
			else
			{
				cout << "No Potion or Incorrected Selected. Retry.\n";
				continue; //다시 포션 선택하게.
			}			
		}
		else
		{
			cout << "Error. Again.\n";
		}
		
		cout<< "\n "<<currentMonster->getMname() << "'s Attack!\n";
		currentMonster->Mattack(player);
		
		
		
	}
	
	//while문에서 체력 조건 설정했으니까,
	if (currentMonster->getMHP() <= 0) // 슬라임 피가 0보다 작거나 같으면,
	{
		cout << "\n★ Victory!\n";
		cout << "  -> Got : " << currentMonster->getdropItemName() << " \n"; //get은 함수이기에 가져오기 위해선 뒤에 ()
		player->gainExp(currentMonster->getMexp()); //Player.cpp에 세팅해둔 겸치 부분.
		
	}
	else if (player->getHP() <=0)
	{
		cout << "\nYou Died.";
	}	
	
	// battle Select	
	
	delete currentMonster;
	delete player; // 프로그램 종료 전 delete player 호출.

	return 0;


	
}



