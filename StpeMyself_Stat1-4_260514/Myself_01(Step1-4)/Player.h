#pragma once
#include <string>

using namespace std;

void printStatus(string name, int stat[]);
void StatUpStatus(string name, int stat[], int& HP_Potion, int& MP_Potion, int& att_inc, int& def_inc, bool& inGameStart);
//포션 편경되는 걸 반영하기 위해 &참조자를 넣기.
// 복사본이 아니라, main함수의 내용을 참조 하는 역할.