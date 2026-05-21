//Item.h

#pragma once
#include <string>
#include <iostream>


struct Item // 유사 클래스. 자유롭게 접근 가능. 그래서 헤더에서 선언.
{
    std::string name;
    int price; // 6-1 name, price 정의하기
    
    Item(std::string _name, int _price) //생성자 - 나중에 아이템 생성할 때.
    { // 아이템 정보를 가져올거니까 _ 사용.
        this->name = _name;
        this->price = _price;
    }
    
    void PrintInfo() const // 6-1 정보 출력 정의하기(함수)
                            // 함수 선언에 사용되는 const는 PrintInfo() 객체 내부 변수 수정하지 않음(변경 불가).
{
    std::cout << name << " ("<< price << "G)\n"; //아이템명(금액)
}
    
};

