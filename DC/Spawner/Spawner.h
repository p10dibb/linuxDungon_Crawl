
#pragma once
#include "../LootBox/LootBox.h"

typedef struct lootDrop {
	int gold = 0;
	int xp = 0;
	Armor *armour =NULL;
	Weapon *weapon=NULL;
	Potion *potion=NULL;
	//other


}LootDrop;


////NOTE: I have all the multipliers as seperate ints just in case they need adjustment for balancing later


class Spawner {
private:

	//Zombie names for random generation
	array<string, 8> ZombieNames = { "Zombie", "Ghoul", "Skeleton", "Corpse Eater", "Grave Walker", "Pale", "Rotter", "Resurected" };

	//Weapons++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Descriptor names for random name generation by levell		0-6							8-14												15-24											25-39													40+		
	array<string,5> WeaponDescriptors[5] = { {"Wooden","Weak","Plastic","Super Common","Pitiful"} ,{"Stone","Dull","Damaged","Rusted","Common"},{"Iron","Adaquate","Usable","Bronze", "Rare"},{"Steel","Good", "Strong","Vicious","Sharp"},{"Diamond","Amazing","Angelic","Legendary","God Like"} };
	//Sword names for random name generation
	array<string, 5> SwordNames = { "Sword","Cutlass","Foil","Rapier","Scimitar" };
	//Dagger names for random name generation
	array<string, 5> DaggerNames = { "Dagger", "Stilleto","Dirk","Bowie Knife","Cleaver" };
	

	
	//weak multiplier
	int Weak = 1;
	//avg multiplier
	int Medium = 2;
	//strong multiplier
	int Strong = 3;
	//+++++++++++++++++++++++++++++++++++++++++++++++++


	//Armor+++++++++++++++++++++++++++++++++++++++
	
	//Descriptor names for random name generation by levell		0-6							8-14												15-24											25-39													40+		
	array<string, 5> ArmorDescriptors[5] = { {"Cloth","Weak","Thread Bare","Super Common","Pitiful"} ,{"Leather","Shotty","Damaged","Warped","Common"},{"Iron","Adaquate","Usable","Bronze", "Rare"},{"Steel","Good", "Strong","Hardened","Resistant"},{"Diamond","Amazing","Angelic","Legendary","God Like"} };


	//multipliers for armour size
	int	small = 1; //Gloves,Helmet
	int Med = 2;//Pants,Boots
	int Large = 3;//Chest

	//multiplier for armour class
	//Heavy =3
	int H = 3;
	//Medium=2
	int M = 2;
	//Light=1
	int L = 1;


	//++++++++++++++++++++++++++++++++++++++++++++++

	

public:
	Spawner();
	Enemy CreateZombie(int level, bool forceLevel=false );
	LootDrop GenerateEnemyLootDrop(Enemy zed);

	//Weapons -----in SpawnerWeapons.cpp
		Weapon* CreateClaws(int level, bool forceLevel=false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);
		Weapon* CreateSword(int level, bool forceLevel = false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);
		Weapon* CreateDagger(int level, bool forceLevel = false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);
		Weapon* CreateAxe(int level, bool forceLevel = false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);
		Weapon* CreateShield(int level, bool forceLevel = false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);

		//Creates a random weapon
		Weapon* CreateRandomWeapon(int level,bool forceLevel=false, bool forceRarity=false,ItemRarity_enum rarity= Common_ItemRarity);
	//---------------------


	//Armor------------in SpawnerArmor.cpp
		//Creates Helmet
		Armor* CreateHelmet(int level, ArmorClass_enum c, bool forceLevel=false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);
		//Creates Chest
		Armor* CreateChest(int level, ArmorClass_enum c, bool forceLevel=false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);
		//Creates Gloves
		Armor* CreateGloves(int level, ArmorClass_enum c, bool forceLevel = false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);
		//Creates Pants
		Armor* CreatePants(int level, ArmorClass_enum c, bool forceLevel = false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);
		//Creates Boots
		Armor* CreateBoots (int level, ArmorClass_enum c, bool forceLevel = false,bool forceRarity=false,ItemRarity_enum rarity =Common_ItemRarity);
		//creates a random piece of armor
		Armor* CreateRandomArmor(int level, bool forceLevel=false, bool forceRarity=false,ItemRarity_enum rarity=Common_ItemRarity);
	
	//------------

	
	//Potions---------------- in SpawnerPotion.cpp

		//will create a random potion (true Random)
		Potion* CreateRandomPotion();
		//will create a random potion (leans more towards health potions)
		Potion* CreateRandomPotion_MoreHealth();

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateHealthPotion(bool random = false, int level = 1, int Tier = 1);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateSpeedStatPotion(bool random = false, int level = 1, int Tier = 1);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateStrengthStatPotion(bool random = false, int level = 1, int Tier = 1);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateMaxHealthStatPotion(bool random = false, int level = 1, int Tier = 1);
		
		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateDefenseStatPotion(bool random = false, int level = 1, int Tier = 1);
		
		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateDamageStatPotion(bool random = false, int level = 1, int Tier = 1);
		
		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateStaminaStatPotion(bool random = false, int level = 1, int Tier = 1);
		

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateDefenseBoostPotion(bool random = false, int level = 1, int Tier = 2);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateDamageBoostPotion(bool random = false, int level = 1, int Tier = 2);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateSpeedBoostPotion(bool random = false, int level = 1, int Tier = 2);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateCureEffectsPotion(bool random = false, int level = 1, int Tier = 1);
		
		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateCureNegativeEffectsPotion(bool random = false, int level = 1, int Tier = 1);

	
		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateNormalResistancePotion(bool random = false, int level = 1, int Tier = 1);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateFireResistancePotion(bool random = false, int level = 1, int Tier = 1);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateBluntResistancePotion(bool random = false, int level = 1, int Tier = 1);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreateStabbingResistancePotion(bool random = false, int level = 1, int Tier = 1);

		//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
		Potion* CreatePoisonResistancePotion(bool random = false, int level = 1, int Tier = 1);
		


	//------------------
	
	//Dev Items------- all items are level 1  but are very very good
		Armor* CreateDevHelmet( ArmorClass_enum c);
		Armor* CreateDevChest(ArmorClass_enum c);
		Armor* CreateDevGloves( ArmorClass_enum c);
		Armor* CreateDevPants( ArmorClass_enum c);
		Armor* CreateDevBoots ( ArmorClass_enum c);
		
		Weapon* CreateDevSword();
	//-------------------

	//Extinctionist gear------- creature kill Rewards Unique item Rewards,  has a garenteed chance to have stabbing damage
		Item * CreateRandomExtinctionistItem(int level);

		Weapon* CreateExtinctionistSword(int level);
		Weapon* CreateExtinctionistDagger(int level);
		Weapon* CreateExtinctionistAxe(int level);
		
		Armor* CreateExtinctionistHelmet(int level);
		Armor* CreateExtinctionistChest(int level);
		Armor* CreateExtinctionistGloves(int level);
		Armor* CreateExtinctionistPants(int level);
		Armor* CreateExtinctionistBoots (int level);

	//---------------------

	//a Unique Dagger that has increase stabbing Damage  Reward for getting 69 related stats
	Weapon* CreateNICE(int level);

	//a unique Shield with garenteed blunt damage and high  42% chance of burning
	Weapon* CreateTheMarly(int level);


	//Goldmonger gear --------   Reward for Total Gold Collected  Rewards is extra heavy and extra valuable
		//spawns a random Goldmanger Item
		Item * CreateRandomGoldMongerItem(int level);

		//Reward for GoldCollected 
		Weapon* CreateGoldMongerAxe(int level);
		//Reward for GoldCollected
		Weapon* CreateGoldMongerShield(int level);
		
		//Reward for GoldCollected
		Armor* CreateGoldMongerHelmet(int level);
		//Reward for GoldCollected
		Armor* CreateGoldMongerChest(int level);
		//Reward for GoldCollected
		Armor* CreateGoldMongerGloves(int level);
		//Reward for GoldCollected
		Armor* CreateGoldMongerPants(int level);
		//Reward for GoldCollected
		Armor* CreateGoldMongerBoots (int level);
	//---------------------------------------
	
	//Collector gear ------ Reward  for Items collected
		Item * CreateRandomCollectorItem(int level);

		Weapon* CreateCollectorSword(int level);
		Weapon* CreateCollectorDagger(int level);
		Weapon* CreateCollectorAxe(int level);
		Weapon* CreateCollectorShield(int level);
		Weapon* CreateCollectorClaws(int level);
		
		Armor* CreateCollectorHelmet(int level);
		Armor* CreateCollectorChest(int level);
		Armor* CreateCollectorGloves(int level);
		Armor* CreateCollectorPants(int level);
		Armor* CreateCollectorBoots (int level);

	//-------------------

	//LootBox-------
		//creates a lootbox
		LootBox CreateLootBox(int level);

	//

};


