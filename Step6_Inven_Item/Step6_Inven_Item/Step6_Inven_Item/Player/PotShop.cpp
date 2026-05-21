#include "PotShop.h"

using namespace std;


AlchemyWorkshop::AlchemyWorkshop() //생성자 - AlchemyWorkshop 생성 시, 내부에 레시피 2개를 넣어서 초기화.
{
    recipes.push_back(PotionRecipe("HPPotion", "Herb", "ClearWater")); // 레시피에 넣는다.(포션레싶(이름, 재료1, 재료2));
    recipes.push_back(PotionRecipe("StaminaPotion", "Herb", "Berry"));
}////7-2.vector<PotionRecipe>에 recipes 저장하기. recipe에. push_back한다.(레시피)를.

void AlchemyWorkshop::ShowAllRecipes() //7-3. 모든 레시피 출력
{
    cout << "\n Found "<< recipes.size() << " recipes.\n"; // 찾았습니다. (레시피 갯수) 개의 레시피를.
    for (const PotionRecipe& recipe : recipes) //range-for : 레시피 출력용.
    {
        recipe.PrintPotionRecipe();
    }
}

//7-4 / 7-5. 포션 이름으로 찾기
void AlchemyWorkshop::SearchByName(string name)
{
    bool found = false; // 찾았다는 것이 거짓. 찾았는지 못 찾았는지 체크. bool 초기화. 기본값 '없음'.
    
    for (const PotionRecipe& recipe : recipes)
    {
        if (recipe.PotName == name) // 이름이 완벽하게 일치하면
        {
            recipe.PrintPotionRecipe(); // 레시피 출력.
            found = true; // 찾은 것이 트루.
            break;
        }
    }
    if (!found)
    {
        cout << "찾을 수 없습니다\n";//7-5. 검색결과 없으면 찾을 수 없습니다 출력하기.
    }
}


void AlchemyWorkshop::SearchByIngredient(string ingre)
{
    int count = 0; // 숫자를 세줄 count 의 초기화.
    
    for (const PotionRecipe& recipe : recipes)
    {
        if (recipe.PotIng1 == ingre || recipe.PotIng2 == ingre) // 입력한 값이 재료 1이나 2랑 같으면.
        {
            recipe.PrintPotionRecipe(); // 레시피 출력
            count++; // count 수 증가.
        }
    }
    cout << "Found" << count << " recipes.\n";
}

void AlchemyWorkshop::EntShop()    // AlchemyWorkshop에 있는 EntShop.
{
    
	
    while (1) // 7-1 결과화면 참고해서 PotionRecipe / AlchemyWorkshop 코드구조 만들기.
    {
        cout << "\n=== Potion Shop ===\n";
        cout << "1. Show all recipes\n";
        cout << "2. Search by potion name\n";
        cout << "3. Search by ingredient\n";
        cout << "0. Go back\n";
	
        cout << "\nChoose:";
	
        //vetor<PotionRecipe> 잘못 넣은 흔적. 헤더에 들어가있음.
        
        int PotMake;
        cin >> PotMake;
		
        if (PotMake == 1)
        {
            ShowAllRecipes();
        }
        else if (PotMake == 2)
        {
            cout << "Serch potion name(No spacing): ";
            string serchName; //serchName 초기화.
            
            cin.ignore(); // 엔터키 삭제.
            getline(cin, serchName);// 입력. 띄어쓰기 인식.
            SearchByName(serchName); // 입력한 serchName에 맞는 레시피 출력.
        }
        else if (PotMake == 3)
        {
            cout << "Serch Ingredient(No spacing): ";
            string ingreName;
            
            cin >> ingreName;
//            cin.ignore();
//            getline(cin, ingreName);
            SearchByIngredient(ingreName);            
        }
        else if (PotMake == 0)
        {
			break; // 0 누르면 while문 밖으로 빠져나감.
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Error. Choise Again.\n";
            continue;
        }
    }
}


