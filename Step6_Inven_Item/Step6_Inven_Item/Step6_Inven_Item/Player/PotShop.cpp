#include "PotShop.h"

using namespace std;


cout << "\n=== Potion Shop ===\n";
cout << "1. Show all recipes\n";
cout << "2. Search by potion name\n";
cout << "3. Search by ingredient\n";
cout << "0. Go back\n";
	
cout << "\nChoose:";
	
vetor<PotionRecipe>
	
while (1) // 7-1 결과화면 참고해서 PotionRecipe / AlchemyWorkshop 코드구조 만들기.
{
    int PotMake;
    cin >> PotMake;
		
    if (PotMake == 1)
    {
        ShowAllRecipes()
    }
    else if (PotMake == 2)
    {
        SerchByName(string name)
    }
    else if (PotMake == 3)
    {
        SearchByIngredient(string ingre)
    }
    else if (PotMake == 0)
    {
			
    }
    else
    {
        cout << "Error. Choise Again.\n";
    }
}
	


void PotionRecipe()
{
    vector<PotionRecipe>    
    
}

