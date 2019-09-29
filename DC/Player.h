#pragma once

#include "Spawner.h"

typedef struct inventorySlot {
	Item* item;
	int amount = 0;
}InventorySlot;

class Player : public  Biped {


private:

	


	Weapon* Left;
	Weapon* Right;

	

	
	InventorySlot Inventory[40];
	int FreeSlots;
	int InventorySize;

	//money player has
	int Money;

	//xp required for levelup
	int LevelUp;

	int CurrentWeight;
	int MaxWeight;
	//is max Weight<currentWeight
	bool OverWeighted;

	//levels up character prompts for skill upgrades
	void NextLevel();

	//adds an Item to Inventory
	//bool addToInventory(Item *i);

	//Inventory Functions+++++++++

	int ViewInventory(int pos);
	int EquipInventory(int pos);
	int UseInventory(int pos);
	int MoveInventory(int pos);
	int getFuncInventory(string s);
	//++++++++++++++++++++++++

public:
	bool addToInventory(Item *i);



	//constructor
	Player();
	
	//Displays Info on Player 
	void DisplayDetails();

	//calculates the players actual speed
	int ActualSpeed();

	//calculates players Actual attack
	int ActualDamage();

	//calculates Players actual Defense
	int ActualDefense();

	//players attack
	int Attack();

	//damage recieved
	int TakeDamage(int damage);

	//takes in the enemies loot and adds to inventory
	void RecieveLootDrop(lootDrop loot);

	void DisplayInventory();

	int InventoryDialogue();
	
	int EquipedDialogue();

	void DisplayEquiped();
	int move(char  map[][10], int direction);

	int Navigation(char map[][10]);




	//Getter and setters   code in PlayerGetSet.cpp++++++++++++++++

	Weapon* getLeft();
	int setLeft(Weapon* l);
	Weapon* getRight();
	int setRight(Weapon* l);
	
	//InventorySlot* getInventory();
	void setInventory(InventorySlot i[40]);
	int getFreeSlots();
	void setFreeSlots(int f);
	int getMoney();
	void setMoney(int m);
	int getLevelUp();
	void setLevelUp(int l);
	int getMaxWeight();
	void setMaxWeight(int w);
	int getCurrentWeight();
	void setCurrentWeight(int w);
	bool getOverWeighted();
	void setOverWeighted(bool w);
	int getInventorySize();
	void setInventorySize(int i);

	//+++++++++++++++++++++++++++=++
	

};

//converts string to all lowercase
string toLower(string s);
