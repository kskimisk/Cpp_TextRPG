#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;



struct PotionRecipe
{
    string PotName;
    string PotIng1;
    string PotIng2;
    
    PotionRecipe(string _PotName, string _PotIng1, string _PotIng2)
    {
        PotName = _PotName;
        PotIng1 = _PotIng1;
        PotIng2 = _PotIng2;
        
    }
    
    void PrintPotionRecipe() const
    {
        cout << " ->" << PotName << " : " << PotIng1 << " x1, " << PotIng2 << " x1" ")\n";
    }

};


class AlchemyWorkshop
{
public:
    AlchemyWorkshop();
    void ShowAllRecipes();
    void SearchByName(string name);
    void SearchByIngredient(string ingredient);

    void EntShop(); 
    
protected:
    vector<PotionRecipe> recipes;
    
};

