//Item.cpp

#include<iostream>
#include"Player/Player.h"


void setPotion(int count, int* p_HPPotion, int* p_MPPotion) //도전 1-1) 함수 작성하기
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void setPowDef(int count, int* p_PowInc, int* p_DefInc)
{
	*p_PowInc = count;
	*p_DefInc = count;
}