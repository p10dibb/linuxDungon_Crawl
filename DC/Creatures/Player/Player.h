#pragma once

#include "../../Spawner/Spawner.h"


class Player : public  Biped {


private:
	//weapon equipped in left hand
	Weapon* Left;
	//weapon equiped in right hand
	Weapon* Right;
	
	//the max possible size of inventory
	int inventoryMax=100;

	//The players inventory
	// InventorySlot Inventory[100];
	array<InventorySlot,100> Inventory;

	//the amount of free slots of the inventory
	int FreeSlots;

	//the size of players inventory currently
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
	


	



public:
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

	//constructor
	Player();	

	Spawner spawner;

	int PauseMenue();


	//Combat related functions
		
		//Gets all the damage types from weapons and player
		vector<DamageTypes> getAllDamageTypes();

		//Gets all Resistance types
		vector<ActiveEffects> getAllResistanceTypes();

		//calculates the players actual speed
		int ActualSpeed();

		//calculates Players actual Defense
		int ActualDefense();

		int TakeDamage(vector<DamageTypes> damageTypes);
		//takes in the enemies loot and adds to inventory
		void RecieveLootDrop(lootDrop loot);
	//-----------------------

	//Inventory Functions  PlayerInventory.cpp	

		bool addToInventory(Item *i);

		Item *RemoveItemFromInventory(int pos);
		//drops an item from the lootBox
		void DisplayInventory();

		int InventoryDialogue();
		
		int EquipedDialogue();

		void DisplayEquiped();

		//takes a loot box and prompts the user to interact
		bool InteractLootBox(LootBox *box);

		//removes item from specified Location and turns it into a lootBox if fails return empty box
		LootBox DropItem(int pos);

	//-----------------------------
	
	int move(array<array<RoomPieces_enum, 50>,50> map, int direction);

	int Navigation(array<array<RoomPieces_enum, 50>,50> map);

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
		array<InventorySlot,100> getInventory();
		void setInventory(array<InventorySlot,100> i);
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

		//sets amount of creatures killed
		bool setCreaturesKilled(int amt);

		//increases CreaturesKilled by 1
		void IncrementCreaturesKilled();

		//checks to see if the amount meets a reward requirment
		int RewardCheckCreaturesKilled();

		//sets the amount of items recieved
		bool setItemsRecieved(int amt);

		//returns the total amount of items recieved;
		int getItemsRecieved();

		//increments the ItemsRecieved by 1
		void IncrementItemsRecieved();

		//checks to see if the ItemsRecieved meets reward requirments
		int RewardCheckItemsRecieved();

		//sets the Gold Collected
		bool setGoldCollected(int amt);

		//returns total amount of gold Collected
		int getGoldCollected();

		//increases GoldCollected by amount
		void IncrementGoldCollected(int amount);

		//checks if the GoldCollected meets RewardRequirements
		int RewardCheckGoldCollected(int amount);

		//sets the Gold spent
		bool setGoldSpent(int amt);

		//returns the total amount of Gold Spent
		int getGoldSpent();

		//increases GoldSpent by amount
		void IncrementGoldSpent(int amount);

		//checks if the GoldSpent meets reward Requirements
		int RewardCheckGoldSpent();

		//sets Rooms been too
		bool setRoomsBeenToo(int amt);

		//returns total amount of floors player has been too
		int getRoomsBeenToo();

		//increases RoomsBeenToo by 1
		void IncrementRoomsBeenToo();

		//checks if the RoomsBeenToo meets reward requirements
		int RewardCheckRoomsBeenToo();

		//sets Damage Recieved
		bool setDamageRecieved(int amt);
			
		//returns total amount of damage recieved
		int getDamageRecieved();

		//increase DamageRecieved by amount;
		void IncrementDamageRecieved(int amount);

		//checks if the DamageRecieved meetsReward requirements
		int RewardCheckDamageRecieved();

		//sets Damage Dealt
		bool setDamageDealt(int amt);

		//returns total amount of Damage Dealt
		int getDamageDealt();

		//increases DamageDealt by amount
		void IncrementDamageDealt(int amount);

		// checks if DamageDealt meets reward requirements
		int RewardCheckDamageDealt();

		//sets Max Gold Held
		bool setMaxGoldHeld(int amt);

		//returns largest amount of Money the player has had
		int getMaxGoldHeld();

		//checks to see if MaxGold meets reqard requirements
		int RewardCheckMaxGoldHeld();

		//sets MaxDamage Dealt
		bool setMaxDamageDealt(int amt);

		//returns the maxDamage Dealt
		int getMaxDamageDealt();

		//checks if MaxDamageDealt meets Reward Requirements
		int RewardCheckMaxDamageDealt(int damage);

		//sets Potion Dranked
		bool setPotionDranked(int amt);

		//returns total amount of potions the player has drunk
		int getPotionsDranked();

		//increases Potion Dranked by 1
		void IncrementPotionDranked();

		//checks if the PotionsDranked meets reward requirements
		int RewardCheckPotionDranked();
	

	//-------------------------
	
//Displays all data for character
	void DisplayDetails();

};

//converts string to all lowercase
string toLower(string s);

//takes in a string and a array of strings and shows the position that that function is located
int getFunc(string str, string options[], int size);



