//Slime.cpp

#include "Slime.h"
#include<iostream>
#include "Monster.h"

using namespace std;

//단순하게 생성하는 거니까, 매개변수 없이 고정 스탯으로 생성해서 전달.
Slime::Slime()
    :Monster("SLime", 30, 20, 10, "Slime Jelly", 10, 10)
{
    /* this->Mname = "Slime";
    this->Mpower = 10;
    this->Mdefence = 10;
    this->Mhp = 10;    
    고정 스탯을 넣어서 필요없어짐.*/
}