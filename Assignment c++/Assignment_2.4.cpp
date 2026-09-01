//============================================================================
// Name        : 4.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================}
#include <iostream>
#include <string>
using namespace std;

class Entity
{
private:
    string name;
    int health;
    int level;
    string type;

public:


    Entity& setName(const string& newName)
    {
        this->name = newName;

        return *this;
    }



    Entity& setHealth(int newHealth)
    {
        this->health = newHealth;

        return *this;
    }





    Entity& setLevel(int newLevel)
    {
        this->level = newLevel;

        return *this;
    }


    Entity& setType(const string& newType)
    {
        this->type = newType;

        return *this;
    }


        string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    int getLevel() const
    {
        return level;
    }

    string getType() const
    {
        return type;
    }



    void displayInfo() const
    {
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "Type   : " << type << endl;
    }
};


int main()
{
    Entity player;
    Entity enemy;
    Entity item;

    player.setName("Aragorn")
          .setHealth(100)
          .setLevel(10)
          .setType("Player");


    enemy.setName("Orc")
         .setHealth(60)
         .setLevel(5)
         .setType("Enemy");


    item.setName("HealthPotion")
        .setHealth(0)
        .setLevel(1)
        .setType("Item");



    cout << "===== PLAYER =====" << endl;
    player.displayInfo();

    cout << "\n===== ENEMY =====" << endl;
    enemy.displayInfo();

    cout << "\n===== ITEM =====" << endl;
    item.displayInfo();


    return 0;
}
