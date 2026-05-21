//Main. cpp

#include <string>
#include <iostream>
#include "Player/Player.h"
#include "Job/Job.h"
#include "Monster/AllMons.h"
#include <algorithm>
#include "Player/Item.h"
#include <vector>
#include "Player/PotShop.h"


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


	setPotion(5, &HPPotion, &MPPotion);
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

	}
	
	cout << "\n\n------[Job Selected Complete]------\n";
	player->printPlayerStatus();
	
	vector<Item> inventory;
	AlchemyWorkshop PotShop;
	
	srand(static_cast<unsigned int>(time(nullptr))); //난수생성
//	Monster* currentMonster = new Slime(); 몬스터가 추가 되었으니 랜덤 생성.

	//위치 변경
	// 기존 : 직업선택 > 배틀 시작 > 메인 메뉴 - 인벤...
	// => 현재 : 직업선택 > 메인메뉴 - 던전>전투... - 인벤 -...
	
	while (1)
	{		
		cout << "\n === Main Menu ===\n";
		cout << " 1. Enter Dungeon\n";
		cout << " 2. Check Inventory\n";
		cout << " 3. Potion Shop\n";
		cout << " 0. Quit\n";
		cout << "\n Choose : ";		
		
		int MenuSelect;
		cin >> MenuSelect;
		
		if (cin.fail()) // 메인메뉴 이후 숫자 외 문자 입력 시 처리.
		{
			cin.clear();
			cin.ignore();
			cout << "\n Error. Please Input No. \n ";
			continue;
		}
		
		// 1: 던전 입장
		if (MenuSelect == 1)
		{
			 Monster* currentMonster = nullptr; //등장 몬스터 미정.
			
			//랜덤으로 몬스터 등장(동전뽑기)
			int randMon = rand() % 2;
			if (randMon == 0)
			{
				currentMonster = new Slime();
			}
			else
			{
				currentMonster = new Orc();
			} // 세 마리부터는 다른 함수로.
			cout << "\n[ Battle Start! ]" << name <<"("<< player->getJob() <<")  vs  " << currentMonster->getMname() <<"\n";

			while (player->getHP() > 0 && currentMonster->getMHP() > 0)
			{
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
					cout << "\n[ Inventory ]\n";
					cout << "1. HP Potion (50G) ("<<HPPotion<<"ea)\n";
					cout << "2. MP Potion (50G) ("<<MPPotion<<"ea)\n";
			
					int itemChoice;
					cin >> itemChoice;
			
					if (itemChoice == 1)
					{
						if (HPPotion>=1)
						{
							HPPotion--;
							player->setHP(min(player->getHP() +50, player->getMaxHP())); 
							cout<<" * HP Potion used! HP restored by 50 (Current HP : "<<player->getHP()<<")\n";
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
						continue;
					}			
				}
				else
				{
					cout << "Error. Again Input.\n";
				}
		
				cout<< "\n "<<currentMonster->getMname() << "'s Attack!\n";
				currentMonster->Mattack(player);
			}
	
			if (currentMonster->getMHP() <= 0)
			{				
				string DrName = currentMonster->getdropItemName();
				int DrPrice = currentMonster->getdropItemPrice(); //이름 줄이기.
				
				cout << "\n ★ Victory!\n";
				cout << "  -> Got : " << DrName << " \n"; 
				player->gainExp(currentMonster->getMexp());  //경험치 획득 ->Player.cpp 연결.
				cout << "  -> Saved to inventory.\n"; // step6
				
				Item droppedItem(DrName, DrPrice);
				inventory.push_back(droppedItem);
			}
			else if (player->getHP() <=0)
			{
				cout << "\nYou Died.\n";
			}	
			
			delete currentMonster; // 던전 나올 때 몬스터 파괴.
			
			if (player->getHP() <= 0) break; // 플레이어 피가 0 이하일 시 메인루프 종료.
		}				
		
		
		// 2: 인벤토리
		else if( MenuSelect == 2)
		{
			cout<< "\n [ Inventory (" << inventory.size()  <<"/10)   ] \n";
			if (inventory.empty())
			{
				cout<< "Empty...\n";
			}
			else
			{
				int itemIndex = 1;
				for (const Item& item : inventory)
				{
					cout << itemIndex++ << ". ";
					item.PrintInfo();
				}
			}			
		}
		
		// 3: 포션샵
		else if (MenuSelect == 3)
		{
			PotShop.EntShop();
		}
		else
		{
			cout<< "Bye-Bye!\n";
			break;
		}
	}	
	
			
	delete player; //메모리 해제!

	return 0;


	
}



