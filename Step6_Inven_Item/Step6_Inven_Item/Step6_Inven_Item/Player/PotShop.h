#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std:



struct PotionRecipe  // 7-2 vector<PotionRecipe>에 레시피 저장하기로 접근이 용이해야해서 struct.
{
    string PotName; //포션 이름.
    string PotIng1; // 재료 2가지 중 1번째.
    string PotIng2; // 재료 2가지 중 2번째.
    
    PotionRecipe(string PotName, string PotIng1, string PotIng2){} // 선언
    
    //Item 따라서 만들었던 흔적인데, 단순히 이름, 가격만 나오는 아이템과 차이가 있기 때문에 다른 형식으로 제작.
    // std::string Potname;
    // int PotEA;
    // Pot(std::string _Potname, int _PotEA) {
    //     this->Potname = _Potname;
    //     this->PotEA = _PotEA;     }    
    
    void PrintPotionRecipe() const
    {
        cout << PotName << " : " PotIng1 << "x1, " << PotIng2 << "x1" ")\n";
    }

};


//struct보다 앞에 있었는데, 내부의 PotionRecipe이 인식 못해서.
class AlchemyWorkshop // 포션을 제작하는 게 연금술사니까, 연금술사 작업장이면 여기 전부 관리하는 클래스를 요구한 게 아닐까?
{
public:
    AlchemyWorkshop(); // 생성자.  - 소멸자는 필요 없음. 가만히 둘거니까.
                // 접근 가능하게 할 부분 : 읽는 용도이므로, 입장과 레시피 읽기, 검색 등.
    void ShowAllRecipes(); // 7-3. 전체 레시피 출력하기.
    void SearchByName(string name); // 7-4. 이름이 일치하는 레시피 출력하기.
    void SearchByIngredient(string ingredient); //7-6. 해당 재료를 포함한 레시피 전부 출력.

    void EntShop(); // 입장. 7-7. 메인메뉴에서 3번 누르고 입장할 수 있게.
    
protected: // 읽을 수는 있어야하니까.
    vector<PotionRecipe> recipes; //7-2. vector<PotionRecipe>에 레시피 저장하기. Potion Recipe 선언해야함.
    
};

