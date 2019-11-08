#pragma once

#include "../../Spawner/Spawner.h"

typedef struct inventorySlot {
	Item* item;
	int amount = 0;
}InventorySlot;

class Player : public  Biped {


private:
	//weapon equipped in left hand
	Weapon* Left;
	//weapon equiped in right hand
	Weapon* Right;
	
	//The players inventory
	InventorySlot Inventory[40];
	//the amount of free slots of the inventory
	int FreeSlots;
	//the size of players inventory
	int InventorySize;

	//money player has
	int Money;

	//xp required for levelup
	int LevelUp;

	//the total weight of all items in the inventory
	int CurrentWeight;
	//the maximum weight the player can carry.
	int MaxWeight;
	//is max Weight<currentWeight
	bool OverWeighted;

	//levels up character prompts for skill upgrades
	void NextLevel();


	//Player Stats------
		//total numbers of enemies killed
		int CreaturesKilled;
		//total number of items picked up
		int ItemsRecieved;
		//total amount of gold recieved
		int GoldCollected;
		//total amount of gold used
		int GoldSpent;
		//total number of rooms been to(not unique rooms,increases when rooms are revisited)
		int RoomsBeenToo;
		//total amount of Damage recieved ever
		int DamageRecieved;
		//total amount of Damage Dealt ever
		int DamageDealt;
		//highest amount of Money Held at one time
		int MaxGoldHeld;
		//largest amount of Damage dealt at one time
		int MaxDamageDealt;
		//total amount of potions used 
		int PotionsDranked;
	//------------------
	


	

	//Private Inventory Functions+++++++++
		//displays info on specific item in inventory
		int ViewInventory(int pos);
		//equips the specied item in the inventory if equipable
		int EquipInventory(int pos);
		//uses the specified item if useable
		int UseInventory(int pos);
		// moves the item in specified position
		int MoveInventory(int pos);
		//takes in user string and returns an int
		int getFuncInventory(string s);
	//++++++++++++++++++++++++

public:

	//constructor
	Player();	

	Spawner spawner;

	int PauseMenue();


	//Combat related functions
		
		//Gets all the damage types from weapons and player
		DoubleLinkedList<DamageTypes> getAllDamageTypes();

		//Gets all Resistance types
		DoubleLinkedList<ActiveEffects> getAllResistanceTypes();

		//calculates the players actual speed
		int ActualSpeed();

		//calculates Players actual Defense
		int ActualDefense();

		int TakeDamage(DoubleLinkedList<DamageTypes> damageTypes);
		//takes in the enemies loot and adds to inventory
		void RecieveLootDrop(lootDrop loot);
	//-----------------------

	//Inventory Functions  PlayerInventory.cpp	

		bool addToInventory(Item *i);

		Item *RemoveItemFromInventory(int pos);

		//Displays Info on Player 
		void DisplayDetails();

		void DisplayInventory();

		int InventoryDialogue();
		
		int EquipedDialogue();

		void DisplayEquiped();

	//-----------------------------
	
	int move(char  map[][10], int direction);

	int Navigation(char map[][10]);

	void addSkillPoint();

	//checks if money is > amount and subtracts from there and returns amount;
	int GiveMoney(int amount);

	//adds amount to money;
	bool RecieveMoney(int amount);


	//Getter and setters   code in PlayerGetSet.cpp++++++++++++++++

		Weapon* getLeft();
		int setLeft(Weapon* l);
		Weapon* getRight();
		int setRight(Weapon* l);
		
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


	//Stats Related Functions  code in PlayerStats.cpp

		//displays all the players stats
		void DisplayStats();

		//returns the amount of creatures player has killed
		int getCreaturesKilled();
		//increases CreaturesKilled by 1
		void IncrementCreaturesKilled();
		//checks to see if the amount meets a reward requirment
		int RewardCheckCreaturesKilled();

		//returns the total amount of items recieved;
		int getItemsRecieved();
		//increments the ItemsRecieved by 1
		void IncrementItemsRecieved();
		//checks to see if the ItemsRecieved meets reward requirments
		int RewardCheckItemsRecieved();

		//returns total amount of gold Collected
		int getGoldCollected();
		//increases GoldCollected by amount
		void IncrementGoldCollected(int amount);
		//checks if the GoldCollected meets RewardRequirements
		int RewardCheckGoldCollected(int amount);

		//returns the total amount of Gold Spent
		int getGoldSpent();
		//increases GoldSpent by amount
		void IncrementGoldSpent(int amount);
		//checks if the GoldSpent meets reward Requirements
		int RewardCheckGoldSpent();

		//returns total amount of floors player has been too
		int getRoomsBeenToo();
		//increases RoomsBeenToo by 1
		void IncrementRoomsBeenToo();
		//checks if the RoomsBeenToo meets reward requirements
		int RewardCheckRoomsBeenToo();

		//returns total amount of damage recieved
		int getDamageRecieved();
		//increase DamageRecieved by amount;
		void IncrementDamageRecieved(int amount);
		//checks if the DamageRecieved meetsReward requirements
		int RewardCheckDamageRecieved();

		//returns total amount of Damage Dealt
		int getDamageDealt();
		//increases DamageDealt by amount
		void IncrementDamageDealt(int amount);
		// checks if DamageDealt meets reward requirements
		int RewardCheckDamageDealt();

		//returns largest amount of Money the player has had
		int getMaxGoldHeld();
		//checks to see if MaxGold meets reqard requirements
		int RewardCheckMaxGoldHeld();

		//returns the maxDamage Dealt
		int getMaxDamageDealt();
		//checks if MaxDamageDealt meets Reward Requirements
		int RewardCheckMaxDamageDealt(int damage);

		//returns total amount of potions the player has drunk
		int getPotionsDranked();
		//increases Potion Dranked by 1
		void IncrementPotionDranked();
		//checks if the PotionsDranked meets reward requirements
		int RewardCheckPotionDranked();
	

	//-------------------------
	

};

//converts string to all lowercase
string toLower(string s);

//takes in a string and a array of strings and shows the position that that function is located
int getFunc(string str, string options[], int size);



