#include "../Creatures/Player/Player.h"

class Shop{
private:

//Store inventory.
Item* Inventory[20];
int InventorySize=20;

//the amount of Items that the store will have to buy stuff from you
int Money;

//the Level of the store so Spawning items is at a set Level range
int Level;

Spawner spawner;


public:
Shop();
Shop(int level);
Shop(int level, int money);

//checks if money is > amount and subtracts from there and returns amount;
int GiveMoney(int amount);

//adds amount to money;
bool RecieveMoney(int amount);

//getter for money
int getMoney();
//setter for money;
void setMoney(int amount);

//checks if room in store and adds item
bool AddItemToInventory(Item *item);

//removes the Item from the inventory. and returns it.
Item* RemoveItemFromInventory(int position);

//shows the inventory
void DisplayInventory();

//Displays all Shopping options.
void ShopDialogue(Player *player);

//the shop purchases item from the player
bool PurchaseItem(Player *player);

//sells item to the player
bool SellItem(Player *player);

//gets the specific item from the inventory;
Item* getItem(int position);

//getter for Level
int getLevel();
//setter for Level
void setLevel(int level);

//will generate 10 items at "random"
void GenerateNewInventory();

void ViewItem();









};