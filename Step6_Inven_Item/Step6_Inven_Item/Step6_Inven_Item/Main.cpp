//Main. cpp

#include <string>
#include <iostream>
#include "Player/Player.h"
#include "Job/Job.h"
#include "Monster/AllMons.h"
#include <algorithm>
#include "Player/Item.h"
#include <vector>


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
	
	vector<Item> inventory; // 유저가 보관하고 있는 아이템이니까, 메인에 선언.
						// 밖에 선언해야 계속 사용 가능.
		
	Monster* currentMonster = new Slime();

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
			cout << "Error. Again.\n";
		}
		
		cout<< "\n "<<currentMonster->getMname() << "'s Attack!\n";
		currentMonster->Mattack(player);
		
		
		
	}
	
	if (currentMonster->getMHP() <= 0)
	{
		cout << "\n★ Victory!\n";
		cout << "  -> Got : " << currentMonster->getdropItemName() << " \n"; 
		player->gainExp(currentMonster->getMexp()); 
		cout << "  -> Saved to inventory."; // step6
		
		//이름이 길어서 줄이기
		string DrName = currentMonster->getdropItemName(); //템 이름
		int DrPrice = currentMonster->getdropItemPrice(); // 템 가격
		
		//넣을 구조체 만들고, 아이템 넣기.
		Item droppedItem(DrName, DrPrice);
		inventory.push_back(droppedItem); //6-4 전투 후 드롭 아이템을 inventory에 넣기

		
	}
	else if (player->getHP() <=0)
	{
		cout << "\nYou Died.";
	}	
	
	cout << "\n === Main Menu ===\n";
	cout << " 1. Enter Dungeon\n";
	cout << " 2. Check Inventory\n";
	cout << " 3. Potion Shop\n"; //Step7-7. 메인메뉴에 "3. 포션 제작소" 추가하기
	cout << " 0. Quit\n";
	cout << "\n Choose : ";

	while (1)
	{
		int MenuSelect;
		cin >> MenuSelect;
		
		if (MenuSelect == 1)
		{
			break; // 아직 구현 안 됨.
		}
		else if( MenuSelect == 2)
		{
			cout<< "\n [ Inventory (" << inventory.size()  <<"/10)   ] \n";
			if (inventory.empty())
			{
				cout<< "Empty...\n";
			}
			else
			{
				int itemIndex = 1; // 아이템 보관 공간의 갯수 초기화(1), 없을 시에는 이미 Empty 출력.
				for (const Item& item : inventory)  //inventory 속의 원본(Item&)을 꺼내서 item이라고 부를건데, 내용물을 바꾸진 않을게요(const).
				{
					// 6-6 range-for문 -> for(자료형 변수 : 벡터), 반복문.
					cout << itemIndex++ << ". "; //범위기반 for문의 순회. 반복문의 반복 횟수만큼 아이템 수도 늘기에 ++.
					item.PrintInfo(); // 
				}
			}
			
		}
		else if (MenuSelect == 3)
		{
			
		}
		else
		{
			cout<< "byebye!";
			break;
		}
	}
	
	delete currentMonster;
	
	
	//원래 Step7의 Potion Shop 놨던 자리. 근데 7-7에서 메인에 끼워넣으라니까, 따로 헤드 만들어서.
	
	
	
	delete player;

	return 0;


	
}



