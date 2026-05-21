//Item.h

#pragma once
#include <string>
#include <iostream>


struct Item 
{
    std::string name;
    int price;
    
    Item(std::string _name, int _price)
    {
        this->name = _name;
        this->price = _price;
    }
    
    void PrintInfo() const
{
        std::cout << name << " ("<< price << "G)\n";
}
    
};

