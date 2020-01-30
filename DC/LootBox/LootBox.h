#pragma once

#include "../Spawner/Spawner.h"

typedef struct inventorySlot
{
    Item *item;
    int amount = 0;
} InventorySlot;

class LootBox
{

private:
    //name of Lootbox
    string name;

    //amount of money in the loot box
    int money;

    //a vector of loot
    vector<inventorySlot> loot;


    array<int, 2> position;

public:

    //default constructor
    LootBox();

    //setter for name
    bool setName(string name);
    //getter for name
    string getName();

    //setter for money
    bool setMoney(int money);
    //getter for money
    int getMoney();

    //setter for Loot
    bool setLoot(vector<inventorySlot> loot);
    //getter for Loot
    vector<inventorySlot> getLoot();

    //setter for Position
    bool setPosition(array<int,2> pos);
    //getter for Position
    array<int,2> getPosition();

    //takes another loot box and adds it to itself
    bool Merge(LootBox *newLoot);

    //adds a new item to the Loot box
    bool addItem(Item *newItem);

    //adds money to the Loot box
    bool addMoney(int newMoney);

    //returns the amount of money to be removed
    int removeMoney(int amount);

    //returns the item from the specified position
    Item* removeItem(int position);

    //checks if the loot box is empty
    bool isEmpty();

};