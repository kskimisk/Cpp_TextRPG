// Main.c

#include<iostream>
#include<string>

using namespace std;

//void printStatus(string name, int stat[]); //숙제 : 선언 안 하고 할 수 있게 하는 방법 찾기
//선언 안 할 시, main 함수 안에 있는 printStatus 부분의 컴파일을 진행할 때, 선언이 안 되어있어서 에러 발생.
// main 아래에 있는 void 함수 부분을 main의 위로 옮기면 됨.

void printStatus(string name, int stat[])  // 처음엔 main의 아래에 놨던 부분.
{
	cout << "\n==================================== \n";
	cout << "    " << name << " 의 현재 능력치\n";
	cout << "==================================== \n";
	cout << " HP : " << stat[0] << "     " << "MP : " << stat[1];
	cout << "\n 공격력 : " << stat[2] << "     " << "방어력 : " << stat[3];
	cout << "\n==================================== \n";
}

class Player { //player 클래스 만들기.
protected: //protected 멤버 변수로 이것저것 선언. 건들면 안 되는 것들을 금고 속에 넣는 역할.
	// 나중에 불러와서 사용은 할 수 있지만, main함수에서 건들 수 없게 하기 위해서 protected로.
	string name;
	string job;
	int level;
	int hp;
	int mp;
	int power;
	int defence;

public: // protected의 대문 역할. 건들 수 있는 데이터들. main함수의 접근통로. 외부에서 사용 가능.

	//생성자 예시 부분
	Player(string name, int hp, int mp, int power, int defence) //Player 선언하고 (목차) 만들기.
		//: name(name), hp(hp), ..., defence(defence) 처럼 멤버 초기화 리스트 써도 됨.
		// 선언과 함께 초기화를 하는 것.
	{ // 생성자의 본문. 생성자란 클래스의 객체가 인스턴스화될 때 자동으로 호출되는 특수한 종류의 멤버 함수.
		// 클래스와 이름이 같아야함.
		this->name = name; // this->name = name; 으로 써도 됨. this가 '이것이 만들어뒀던 변수다'라는 의미.
		this->hp = hp;  // 우측은매개변수.(외부에서 들어온 거.)
		this->mp = mp;  // 매개변수는 stat[]을 통해서 자동으로 순서대로 매칭이 되는 거.
		this->power = power; // hp = _hp로 했다가 없는 매개변수라고 오류발생.
		this->defence = defence;
		this->job = "백수";
		this->level = 1;
	}

	

	//getter/setter, printPlayerStatus() 작성하기

	int getHp() {  // 1. HP Get 하는 거. 가져오기. protect로 보호되고 있기에, cout으로 바로 출력 불가능.
		return hp;  // getHp()라는 함수를 public에 열어서 return hp로 hp 항목을 뱉어냄
	}
	void setHp(int _hp) {  // setter, 세팅하는 거. 설정하기.
		hp = _hp; // hp는 매개변수 hp다.
	}

	int getMp() {  // 반복 
		return mp;
	}
	void setMp(int _mp) {
		mp = _mp;
	}

	int getPow() {  // 반복 
		return power;
	}
	void setPow(int _power) {
		power = _power;
	}

	int getDef() {  // 반복 
		return defence;
	}
	void setDef(int _defence) {
		defence = _defence;
	}


	void printPlayerStatus() {
		cout << "------------------------------------\n";
		cout << "닉네임: " << name << " | 직업: " << job << " | Lv." << level << "\n";
		cout << "HP: " << hp << " | MP: " << mp << " | 공격력: " << power << " | 방어력: " << defence << "\n";
		cout << "------------------------------------\n";
	}


	//Player에 virtual void attack() = 0 순수 가상함수 추가하기
	// 가상함수는 부모클래스에서 상속받은 다음 재정의할 것을 미리 가정해두고 정의해놓는 거.
	// 가상으로 함수 놔두는 거.
	virtual void attack() = 0; // 지금 attack 기능을 쓰진 않음.
						// 하지만 부모 클래스에서 먼저 작동 버튼이 있어야 자식 클래스에서 사용할 때 프로그램 구동 시 문제 없음.
								// 이전에 att_inc 변수들 바꿔야겠다. 변수명 때문에 헷갈릴듯.

	// 가상 소멸자 추가하기
	virtual ~Player() {} // ~로 시작되는 건 소멸자. 소멸되는 시점에서 호출되는 거.
						//객체의 소멸과정에서 모든 소멸자가 호출되어야 깔끔하게 지워짐. 메모리 누수 없음.
						// 그 해결방법.
						// 지금 쓰는 건 일종의 유언장. 나중에 delete player;를 대비해서 넣어두는 것.
						// 나중에 필요하다고 소멸자만 쓰면 남는 찌꺼기로 메모리 누수 생길 수 있음.


	



}; // class Player를 닫은 거.

//Warrior, Magician, Thief, Archer 클래스가 Player를 상속하도록 만들기
// 새 클래스니까 class Player 다음으로.
class Warrior : public Player {
public:
	// Warrior 생성자. 한글 버전이니까, 전사 생성자.
	Warrior(string name, int hp, int mp, int power, int defence)
		: Player(name, hp, mp, power, defence) // 멤버 초기화 리스트. 아까는 _hp 식으로 언더바를 썼지만.
	{
		//직업별 특화 스탯 하나를 +30하기.
		this->job = "전사"; //직업 변경;
		this->defence += 30; // 전사니까 방어. Player에서 가져온 defence에 30을 더하는 거.
						// hp는 도적해야지. 강심 카타.
		cout << "* 전사로 전직하였습니다. (HP +30)\n"; // 전직문구.
		cout << "*공격 : 베기!\n";
	}

	//직업별 attack() 메시지를 다르게 오버라이딩하기.
	// 아까 가상함수로 적어뒀던 attack()을 실질적으로 쓰는 거.
	void attack() override { //덮어쓰기처럼 보이는데, 왜 write가 아니라 ride일까. 덮어쓰는 게 아니라, 엎혀가는 느낌인가?
		cout << "베기!\n";
	}
};

//직업별 반복
class Magician : public Player {
public:
	Magician(string name, int hp, int mp, int power, int defence)
		: Player(name, hp, mp, power, defence)
	{
		this->job = "마법사";
		this->mp += 30; //법사는 역시 mp.
		cout << "* 마법사로 전직하였습니다. (MP +30)\n";
		cout << "*공격 : 파이어볼!\n";
	}

	void attack() override {
		cout << "파이어볼!\n";
	}
};

class Thief : public Player {
public:
	Thief(string name, int hp, int mp, int power, int defence)
		: Player(name, hp, mp, power, defence)
	{
		this->defence += 30; //강심 카타.
		this->job = "도적";
		cout << "* 도적으로 전직하였습니다. (defence +30)\n";
		cout << "* 공격 : 기습!\n";
	}

	void attack() override {
		cout << "기습!\n";
	}
};

class Archer : public Player {
public:
	Archer(string name, int hp, int mp, int power, int defence)
		: Player(name, hp, mp, power, defence)
	{
		this->job = "궁수";
		this->power += 30; //궁수가 힘이 쎄지.
		cout << "* 궁수로 전직하였습니다. (Power +30)\n";
		cout << "* 공격 : 사격!\n";
	}

	void attack() override {
		cout << "사격!\n";
	}
};

// main에서 Player* player = nullptr 선언 후 직업 선택에 따라 동적 할당하기는 main()에서
// 제일 아래에서.



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

	int HP_Potion = 5;
	int MP_Potion = 5;
	int IncAtt = 1;
	int IncDef = 1;
	bool isGameStart = false;
	char choice;



	while (!isGameStart)
	{
		cout << "\n\n* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다.";
		cout << "\n============================================\n";
		cout << "               < 캐릭터 강화 >\n";
		cout << "1. HP UP" << "    2. MP UP" << "    3. 공격력 2배\n";
		cout << "4. 방어력 2배" << "  5. 현재 능력치" << "  0. 게임 시작";
		cout << "\n============================================\n";
		cout << "번호를 선택해주세요 : ";

		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			if (HP_Potion >= 1)
			{
				stat[0] += 20;
				HP_Potion -= 1;
				cout << "* HP가 20 증가했습니다. (HP포션 차감 : 남은 포션 " << HP_Potion << "개)\n";
			}
			else if (HP_Potion <= 0)
			{
				cout << "HP 포션 부족\n";
			}
			else
			{
				cout << "오류입니다.\n";
			}
			break;

		}

		case '2':
		{
			if (MP_Potion >= 1)
			{
				stat[1] += 20;
				MP_Potion -= 1;
				cout << "* MP가 20 증가했습니다. (MP포션 차감 : 남은 포션 " << MP_Potion << "개)\n";
			}
			else if (MP_Potion <= 0)
			{
				cout << "MP 포션 부족\n";
			}
			else
			{
				cout << "오류입니다.\n";
			}
			break;

		}

		case '3':
		{
			if (IncAtt >= 1)
			{
				stat[2] *= 2;
				IncAtt -= 1;
				cout << "* 공격력이 2배 증가하였습니다. (현재 공격력 : " << stat[2] << ")\n";
				cout << "(공격력 증가는 1회만 가능합니다.)\n";
			}
			else if (IncAtt <= 0)
			{
				cout << "공격력 증가 횟수 부족\n";
			}
			else
			{
				cout << "오류입니다.\n";
			}
			break;
		}

		case '4':
		{
			if (IncDef >= 1)
			{
				stat[3] *= 2;
				IncDef -= 1;
				cout << "* 방어력이 2배 증가하였습니다. (현재 방어력 : " << stat[3] << ")\n";
				cout << "(방어력 증가는 1회만 가능합니다.)\n";
			}
			else if (IncDef <= 0)
			{
				cout << "방어력 증가 횟수 부족\n";
			}
			else
			{
				cout << "오류입니다.\n";
			}
			break;
		}

		case '5':
		{
			printStatus(name, stat);
			break;
		}

		case '0':
		{
			cout << "게임을 시작합니다!";
			isGameStart = true;
			break;
		}

		default:
			cout << "잘못 입력하셨습니다. 다시 선택해주세요.\n";
			break;
		}
	}

	/*Step4 : Class 선언
	 선언이 없다면 데이터 변경 시, 
	 그리고 노출 될 필요가 없는 데이터가 노출되어야 함.
	 -> int로 입력한 데이터들이 main 함수에 의해 변경될 수 있다.
	 => 세부 사항을 피하고 사용자가 필요한 정보만 알려주면 된다!
	   - 내부 제어권까지 주면 복잡도만 올라감.
	 */

	//여기서 시작하는 거 맞겠지? 가 아니었음. main이랑 별개로.

	// 11번 구현항목.
	//main에서 Player* player = nullptr 선언 후 직업 선택에 따라 동적 할당하기.

	Player* player = nullptr;
		// null : 널.
		// null pointer value를 나타내는 포인터 리터럴(널을 표현한 값).
		// 간단하게 말해서 초기화한 것. 0만 쓰면 int 값인지, 포인터 값인지 헷갈리지만, 얘는 아님.

		/* Player : 아까 class Player에서 만들어낸 Player 자료형(타입).
		Player* : 포인터 변수. Player의 주소만을 담는 전용 타입.
		player : Player 타입에서 만들어낸 변수.
		만약 *player였다면 역참조 연산자로, player가 가리키는 진짜 본체(메모리 주소 안의 값)을 찾아가게 됨.
		근데 지금은 ->로 역참조 표현중.
		즉, Player* player는 Player의 주소만을 담은 전용 타입에 속하는 변수.
		nullptr : 초기화.*/

		// 즉, 이 게임에서 player가 직업이라는 인형이랑 연결되기 전에 비어둔 상태로 놔둔 컨트롤러.


		//직업 선택에 따라 동적 할당하기.

		//직업 선택하는 문구를 출력.
	cout << "\n\n< 전직 시스템 >\n";
	cout << name << "님, 직업을 선택해주세요!\n"; // 입력받은 진짜 이름 출력.
	cout << "1. 전사   2. 마법사  3. 도적   4. 궁수\n";
	cout << "선택: ";

	
	//선택하는 숫자에 맞춰서 직업이 선택되도록.
	// 안 고르거나 잘못 고를 시 while문으로 되돌리기.
	//직업 선택 부분. 조건문 if문으로 선택하게.

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
	// new : 동적할당.
	// 직업을 선택하면 그 직업에 대한 공간을 마련하게 됨.
	// 동적할당이 되고나면 {} 중괄호가 사라지더라도, main함수내에서는 유지됨.


	cout << "\n\n------[전직 완료]------\n";
	player->printPlayerStatus();

	delete player; // 프로그램 종료 전 delete player 호출.

	



	return 0;
}

/*STEP4 Class 선언
 void 아래에 선언했는데
 위치 여기 맞겠지?
 도 아님, main 위에 해야 선언 없이 할 수 있음.*/ 





//- []  `Player` 클래스 만들기
//- []  `protected` 멤버 변수로 `name`, `job`, `level`, `hp`, `mp`, `power`, `defence` 선언하기
//- []  이전 STEP의 `name`, `stat[]` 값을 `Player` 생성자로 넘기기
//- []  생성자 예시 : `Player(string name, int hp, int mp, int power, int defence)`
//- []  getter / setter, `printPlayerStatus()` 작성하기
//- []  `Player`에 `virtual void attack() = 0` 순수 가상함수 추가하기
//- []  `Player`에 `virtual ~Player() {}` 가상 소멸자 추가하기
//- []  `Warrior`, `Magician`, `Thief`, `Archer` 클래스가 `Player`를 상속하도록 만들기
//- []  직업별 특화 스탯 하나를 + 30 하기
//- []  직업별 `attack()` 메시지를 다르게 오버라이딩하기
//- []  `main`에서 `Player* player = nullptr` 선언 후 직업 선택에 따라 동적 할당하기
//- []  프로그램 종료 전 `delete player` 호출하기
//- []  가능하다면 `Player.h`, `Player.cpp`, `Warrior.h`, `Warrior.cpp`처럼 헤더 / 소스 파일을 나누어보기