#include "PotShop.h"

using namespace std;


AlchemyWorkshop::AlchemyWorkshop()
{
    recipes.push_back(PotionRecipe("HPPotion", "Herb", "ClearWater")); 
    recipes.push_back(PotionRecipe("StaminaPotion", "Herb", "Berry"));
}

void AlchemyWorkshop::ShowAllRecipes()
{
    cout << "\n Found "<< recipes.size() << " recipes.\n";
    for (const PotionRecipe& recipe : recipes)
    {
        recipe.PrintPotionRecipe();
    }
}

void AlchemyWorkshop::SearchByName(string name)
{
    bool found = false;
    
    for (const PotionRecipe& recipe : recipes)
    {
        if (recipe.PotName == name)
        {
            recipe.PrintPotionRecipe();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "찾을 수 없습니다\n";
    }
}


void AlchemyWorkshop::SearchByIngredient(string ingre)
{
    int count = 0;
    
    for (const PotionRecipe& recipe : recipes)
    {
        if (recipe.PotIng1 == ingre || recipe.PotIng2 == ingre)
        {
            recipe.PrintPotionRecipe();
            count++;
        }
    }
    cout << "Found" << count << " recipes.\n";
}

void AlchemyWorkshop::EntShop()
{
    
	
    while (1)
    {
        cout << "\n=== Potion Shop ===\n";
        cout << "1. Show all recipes\n";
        cout << "2. Search by potion name\n";
        cout << "3. Search by ingredient\n";
        cout << "0. Go back\n";
	
        cout << "\nChoose:";
        
        int PotMake;
        cin >> PotMake;
		
        if (PotMake == 1)
        {
            ShowAllRecipes();
        }
        else if (PotMake == 2)
        {
            cout << "Serch potion name(No spacing): ";
            string serchName;
            
            cin.ignore();
            getline(cin, serchName);
            SearchByName(serchName);
        }
        else if (PotMake == 3)
        {
            cout << "Serch Ingredient(No spacing): ";
            string ingreName;
            
            cin >> ingreName;
            SearchByIngredient(ingreName);            
        }
        else if (PotMake == 0)
        {
			break;
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


