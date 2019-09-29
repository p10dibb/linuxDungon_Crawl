#include "Weapon.h"
#include "Armor.h"
#include "Zombie.h"

#include "Potion.h"


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
	Zombie CreateZombie(int level, bool forceLevel=false );
	LootDrop GenerateZombieLootDrop(Zombie zed);

	Weapon* CreateClaws(int level, bool forceLevel=false);
	Weapon* CreateSword(int level, bool forceLevel = false);
	Weapon* CreateDagger(int level, bool forceLevel = false);
	Weapon* CreateAxe(int level, bool forceLevel = false);
	Weapon* CreateShield(int level, bool forceLevel = false);

	Armor* CreateHelmet(int level, ArmorClass c, bool forceLevel=false);
	Armor* CreateChest(int level, ArmorClass c, bool forceLevel=false);
	Armor* CreateGloves(int level, ArmorClass c, bool forceLevel = false);
	Armor* CreatePants(int level, ArmorClass c, bool forceLevel = false);
	Armor* CreateBoots (int level, ArmorClass c, bool forceLevel = false);

	//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
	Potion* CreateHealthPotion(bool random = false, int level = 1, int Tier = 1);

	//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
	Potion* CreateSpeedPotion(bool random = false, int level = 1, int Tier = 1);

	//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
	Potion* CreateStrengthPotion(bool random = false, int level = 1, int Tier = 1);


};


