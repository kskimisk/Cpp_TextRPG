//Item.cpp

#include<iostream>
#include"Player.h"
#include "Item.h"
#include <vector>


void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}

void setPowDef(int count, int* p_PowInc, int* p_DefInc)
{
    *p_PowInc = count;
    *p_DefInc = count;
}
