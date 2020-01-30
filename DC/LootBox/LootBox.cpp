#include "LootBox.h"

//default constructor
LootBox::LootBox()
{
    this->money = 0;
    this->name = "LootBox";
}

//setter for name
bool LootBox::setName(string name)
{
    this->name = name;
    return true;
}
//getter for name
string LootBox::getName()
{
    return this->name;
}

//setter for money
bool LootBox::setMoney(int money)
{
    if (money < 0)
    {
        return false;
    }
    this->money = money;
    return true;
}
//getter for money
int LootBox::getMoney()
{
    return this->money;
}

//setter for Loot
bool LootBox::setLoot(vector<inventorySlot> loot)
{
    this->loot = loot;
    return true;
}
//getter for Loot
vector<inventorySlot> LootBox::getLoot()
{
    return this->loot;
}

//setter for Position
bool LootBox::setPosition(array<int, 2> pos)
{
    if (pos[0] < 0 || pos[1] < 0)
    {
        return false;
    }
    this->position = pos;
    return true;
}
//getter for Position
array<int, 2> LootBox::getPosition()
{
    return this->position;
}

//takes another loot box and adds it to itself
bool LootBox::Merge(LootBox *newLoot)
{
    this->addMoney(newLoot->getMoney());
    newLoot->removeMoney(newLoot->getMoney());

    for(int i=newLoot->loot.size()-1;i>=0;i--){
        for(int j=0; j<newLoot->loot[i].amount;j++){
            this->addItem(*newLoot->removeItem(i));

        }
    }
    return true;

}

//adds a new item to the Loot box
bool LootBox::addItem(Item newItem)
{
    InventorySlot newIS;

    if (newItem.getStackSize() < 2)
    {
        newIS.amount = 1;
        newIS.item = &newItem;
        this->loot.push_back(newIS);
        return true;
    }
    int i = 0;
    for (i; i < this->loot.size(); i++)
    {
        if (this->loot[i].item->getName() == newItem.getName() && this->loot[i].amount < newItem.getStackSize())
        {
            this->loot[i].amount++;
            return true;
        }
    }
    newIS.amount = 1;
    newIS.item = &newItem;
    this->loot.push_back(newIS);
    return true;
}

//adds money to the Loot box
bool LootBox::addMoney(int newMoney)
{
    if (newMoney < 0)
    {
        return false;
    }
    this->money += newMoney;
    return true;
}

//returns the amount of money to be removed
int LootBox::removeMoney(int amount)
{
    if (amount < 0)
    {
        return 0;
    }
    if (amount > this->money)
    {
        amount = this->money;
        this->money = 0;
        return amount;
    }
    else
    {
        this->money -= amount;
        return amount;
    }
}

//returns the item from the specified position
Item *LootBox::removeItem(int position)
{
    Item *item = new Item();

    if (position < 0 || position >= this->loot.size())
    {
        return item;
    }

    item = this->loot[position].item;
    this->loot[position].amount--;

    if (this->loot[position].amount == 0)
    {
         this->loot.erase(this->loot.begin() + position - 1);
    }
    return item;
}

//checks if the loot box is empty
bool LootBox::isEmpty()
{
    if (this->loot.size() == 0 && this->money == 0)
    {
        return true;
    }
    return false;
}
