#include"Spawner.h"

Spawner::Spawner() {
	
}
//
////creates a Zombie based on the level inputed. should be the players level
Zombie Spawner::CreateZombie(int level, bool forceLevel ) {
	Zombie ret;
	
	//ransdomly sets name
	ret.setName(this->ZombieNames[rand() % this->ZombieNames.size()]);

	//sets level to range between playerlevel-3 and playerlevel+3
	if (forceLevel) {
		ret.setLevel(level);
	}
	else {
		ret.setLevel((level - 3) + rand() % 6);
	}

	ret.setPosition({ 1 + rand() % 8, 1 + rand() % 8 });
	//sets health and max health to 10 times its level
	ret.setHealth(10 * ret.getLevel());
	ret.setMaxHealth(10 * ret.getLevel());
		
	//sets base damage, defense, speed and stamina based on its level
	ret.setDamage((ret.getLevel()+1 / 2) + rand() % ret.getLevel());
	ret.setDefense((ret.getLevel()+1 / 4) + rand() % (ret.getLevel()+1 / 2));
	ret.setSpeed((ret.getLevel()+1 / 2) + rand() % ret.getLevel());
	ret.setStamina(rand() % 5);

	//sets weapon
	ret.setWeapon(CreateClaws(ret.getLevel(), true));

	//sets xp drop
	ret.setXP(ret.getLevel() + (ret.getDamage() + ret.getDefense()+ ret.getSpeed())/3);

	
	return ret;


}


////creates the zombies lootdrop
LootDrop Spawner::GenerateZombieLootDrop(Zombie zed) {
	int chance = 0;
	LootDrop ret;
	//100% chance of xp drop
	ret.xp = zed.getXP();
	ret.gold = 0;
	//50% chance of gold drop
	if (rand() % 2 == 0) {
		//gold drop is minimum of 5 and can have upto 5+the amount calculated for xp
		ret.gold = (rand() % zed.getXP()) + 5;
	}
	//10% chance of weapon drop
	if (rand() % 10 == 0) {
		ret.weapon = zed.getWeapon();
	}

	// 10% chance to drop armour
	if (rand() % 10 == 0){
		chance = rand() % 5;
		int armorClass = (rand() % 3);

		//randomly picks armour piece
		if (chance == 0) {
			ret.armour = this->CreateHelmet(zed.getLevel(),(ArmorClass_enum)armorClass);
		}
		else if (chance == 1) {
			ret.armour = this->CreateChest(zed.getLevel(), (ArmorClass_enum)armorClass);
		}
		else if (chance == 2) {
			ret.armour = this->CreateGloves(zed.getLevel(), (ArmorClass_enum)armorClass);
		}
		else if (chance == 3) {
			ret.armour = this->CreatePants(zed.getLevel(), (ArmorClass_enum)armorClass);
		}
		else if (chance == 4) {
			ret.armour = this->CreateBoots(zed.getLevel(), (ArmorClass_enum)armorClass);
		}

	}

	//20% chance of potion
	if (rand() % 5 == 0) {
		chance = rand() % 10;

		//80% chance of health potion
		if (chance < 8) {
			ret.potion = this->CreateHealthPotion();
		}//10% chance of speed booster
		else if (chance == 8) {
			ret.potion = this->CreateSpeedPotion();
		}
		else if (chance == 9) {
			ret.potion = this->CreateStrengthPotion();
		}

	}
	//other drops when added
	return ret;
}

////creates a Claws based on the level inputed. should be the creatures level
Weapon* Spawner::CreateClaws(int level , bool forceLevel ) {
	Weapon* ret= new Weapon();
	ret->setName("Claws");
	ret->setType(Claw_WeaponType);

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}
	
	

	
	
	//adds default Normal damage type;sets damage to medium, speed to strong, sets defense to extra weak
	ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (ret->getLevel() * Medium)));
	//adds a critical damage chance
	ret->addDamageType(DamageTypes(Critical_DamageType,rand()%25,ret->getLevel()/2 + rand() % (ret->getLevel() * Weak)));


	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Strong));
	ret->setDefense((ret->getLevel()/2) + rand() % ret->getLevel()*Weak);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);

	//adding other Damage Types Claws have Stabbing(~15%), Blunt(~15%) max Probability 25

	if(rand()%7 ==0){
		ret->addDamageType(DamageTypes(Stabbing_DamageType,(rand()%24)+1,ret->getLevel()/2));
	}
	if(rand()%7 ==0){
		ret->addDamageType(DamageTypes(Blunt_DamageType,(rand()%24)+1,ret->getLevel()/2));
	}

	ret->setValue((ret->getLevel() / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);


		return ret;
}


//creates a sword based on the level inputed. should be the creatures level
Weapon* Spawner::CreateSword(int level, bool forceLevel ) {
	Weapon* ret = new Weapon();

	ret->setType(Sword_WeaponType);

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}

	//random name generation
	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0].size()] + " " + this->SwordNames[rand() % SwordNames.size()];
	}
	else if (ret->getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1].size()] + " " + this->SwordNames[rand() % SwordNames.size()];
	}
	else if (ret->getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2].size()] + " " + this->SwordNames[rand() % SwordNames.size()];
	}
	else if (ret->getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3].size()] + " " + this->SwordNames[rand() % SwordNames.size()];
	}
	else if (ret->getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4].size()] +" "+ this->SwordNames[rand() % SwordNames.size()];
	}

	ret->setName(name);

	//sets damage to medium, speed to medium, defense to extra medium
	ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (ret->getLevel() * Medium)));
	//adds a critical damage chance
	ret->addDamageType(DamageTypes(Critical_DamageType,rand()%25,ret->getLevel()/2 + rand() % (ret->getLevel() * Weak)));


	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Medium));
	ret->setDefense((ret->getLevel() / 2) + rand() % (ret->getLevel() * Medium));
	ret->setRange(Medium);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 2);

	//adds random other effects Sword gets Fire(5%), stabing(10%),Blunt(10%)  //max of 25 Probability

	if (rand()%20==0){		
		ret->addDamageType(DamageTypes(Fire_DamageType,(rand()%24)+1,ret->getLevel()/2));
	}
	if (rand()%10==0){
		ret->addDamageType(DamageTypes(Stabbing_DamageType,(rand()%24)+1,ret->getLevel()/2));
	
	}
	if (rand()%10==0){
		ret->addDamageType(DamageTypes(Blunt_DamageType,(rand()%24)+1,ret->getLevel()/2));
	
	}

	ret->setValue((ret->getLevel() / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);

	return ret;

}

//creates a Dagger based on the level inputed. should be the creatures level
Weapon* Spawner::CreateDagger(int level, bool forceLevel ) {
	Weapon* ret=new Weapon();

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}

	
	ret->setType(Dagger_WeaponType);
	//random name generation
	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % (WeaponDescriptors[0].size() )]+ " " + this->DaggerNames[rand() % (DaggerNames.size()-1)];
	}
	else if (ret->getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1].size()] + " " + this->DaggerNames[rand() % DaggerNames.size()];
	}
	else if (ret->getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2].size()] + " " + this->DaggerNames[rand() % DaggerNames.size()];
	}
	else if (ret->getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3].size()] + " " + this->DaggerNames[rand() % DaggerNames.size()];
	}
	else if (ret->getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4].size()] + " " + this->DaggerNames[rand() % DaggerNames.size()];
	}



	ret->setName(name);

	//sets damage to med, speed to strong, defense to extra weak adds default Normal damage type;
	ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (ret->getLevel() * Medium)));

	//adds a critical damage chance
	ret->addDamageType(DamageTypes(Critical_DamageType,rand()%25,ret->getLevel()/2 + rand() % (ret->getLevel() * Weak)));

	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Strong));
	ret->setDefense((ret->getLevel() / 2) + rand() % ret->getLevel()*Weak);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);


	//adds random other effects Dagger gets Fire(5%), stabing(25%)  //max of 25 Probability

	if (rand()%20==0){		
		ret->addDamageType(DamageTypes(Fire_DamageType,(rand()%24)+1,ret->getLevel()/2));
	}
	if (rand()%4==0){
		ret->addDamageType(DamageTypes(Stabbing_DamageType,(rand()%24)+1,ret->getLevel()/2));
	
	}



	ret->setValue((ret->getLevel() / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);


	return ret;
}

//creates a Axe based on the level inputed. should be the creatures level
Weapon* Spawner::CreateAxe(int level, bool forceLevel) {
	Weapon* ret = new Weapon();

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}


	ret->setType(Axe_WeaponType);

	//random generation 
	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0].size()] + " Axe";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1].size()] + " Axe";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2].size()] + " Axe";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3].size()] + " Axe";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4].size()] + " Axe";
	}

	ret->setName(name);

	//sets damage to strong, speed to weak, defense to extra medium adds default Normal damage type;
	ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (ret->getLevel() * Strong)));
	//adds a critical damage chance
	ret->addDamageType(DamageTypes(Critical_DamageType,rand()%25,ret->getLevel()/2 + rand() % (ret->getLevel() * Weak)));


	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Weak));
	ret->setDefense((ret->getLevel() / 2) + rand() % ret->getLevel()*Medium);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);


	//adding other Damage Types axe gets Fire(10%), Blunt(10%) max Probability 25
	if (rand()%10==0){
		ret->addDamageType(DamageTypes(Blunt_DamageType,(rand()%24)+1,ret->getLevel()/2));
	}
	if (rand()%10==0){
		ret->addDamageType(DamageTypes(Fire_DamageType,(rand()%24)+1,ret->getLevel()/2));
	}


	ret->setValue((ret->getLevel() / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage()/ 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);


	return ret;


}

//creates a shield based on the level inputed. should be the creatures level
Weapon* Spawner::CreateShield(int level, bool forceLevel ) {
	Weapon* ret=new Weapon();

	//random
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}

	ret->setType(Shield_WeaponType);

	//random name generation
	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0].size()] + " Shield";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1].size()] + " Shield";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2].size()] + " Shield";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3].size()] + " Shield";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4].size()] + " Shield";
	}


	ret->setName(name);

	//sets damage to extra weak ,speed to medium and defense to extra strong //adds default Normal damage type;
	ret->addDamageType(DamageTypes(ret->getLevel()/2 + rand() % (ret->getLevel() * Weak)));
	
	//adds a critical damage chance
	ret->addDamageType(DamageTypes(Critical_DamageType,rand()%25,ret->getLevel()/2 + rand() % (ret->getLevel() * Weak)));

	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Medium));
	ret->setDefense((ret->getLevel() ) + rand() % ret->getLevel()*Strong);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);


	//adding Damage types Shield gets Blunt(50%) max Probability 25
	if (rand()%2==0){
		ret->addDamageType(DamageTypes(Fire_DamageType,(rand()%24)+1,ret->getLevel()/2));
	}

	ret->setValue((ret->getLevel() / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-2)*level+(ret->getDamageTypes_Weapon().Size()-3)*level);


	return ret;
}


//Creates a helmet
Armor* Spawner::CreateHelmet(int level, ArmorClass_enum c,bool forceLevel ) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret= new Armor();

	
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

		break;
	case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Helmet_ArmorType);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] +classType +" Helmet";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Helmet";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Helmet";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Helmet";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Helmet";
	}

	ret->setName(name);

	
	ret->setWeight(this->small*classMultiplier+rand()%classMultiplier);

	ret->setDefense(ret->getLevel()*(classMultiplier*this->small) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;





}

//Creates a chestplate
Armor* Spawner::CreateChest(int level, ArmorClass_enum c, bool forceLevel ) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor;


	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

		break;
	case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Chest_ArmorType);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] + classType + " Chest";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Chest";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Chest";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Chest";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Chest";
	}

	ret->setName(name);



	ret->setWeight(this->Large*classMultiplier + rand() % (classMultiplier));

	ret->setDefense(ret->getLevel()*(classMultiplier*this->Large) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;
}

//Creates a Gloves
Armor* Spawner::CreateGloves(int level, ArmorClass_enum c, bool forceLevel ) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor();


	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

		break;
	case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Gloves_ArmorType);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] + classType + " Gloves";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Gloves";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Gloves";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Gloves";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Gloves";
	}

	ret->setName(name);


	ret->setWeight(this->small*classMultiplier + rand() % classMultiplier);

	ret->setDefense(ret->getLevel()*(classMultiplier*this->small) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;


}

//Creates Pants
Armor* Spawner::CreatePants(int level, ArmorClass_enum c, bool forceLevel ) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor();


	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

		break;
	case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Pants_ArmorType);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] + classType + " Pants";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Pants";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Pants";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Pants";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Pants";
	}

	ret->setName(name);


	ret->setWeight(this->Med*classMultiplier + rand() % classMultiplier);

	ret->setDefense(ret->getLevel()*(classMultiplier*this->Med) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;


}

//Creates Boots
Armor* Spawner::CreateBoots(int level, ArmorClass_enum c, bool forceLevel ) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor();


	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

		break;
	case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Boots_ArmorType);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] + classType + " Boots";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Boots";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Boots";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Boots";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Boots";
	}
	ret->setName(name);



	ret->setWeight(this->Med*classMultiplier + rand() % classMultiplier);

	ret->setDefense(ret->getLevel()*(classMultiplier*this->Med) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;

}



//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateHealthPotion(bool random , int level, int Tier) {
	Potion * ret = new Potion();
	ret->setType(Health_PotionType);
	ret->setBaseBooster(20);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Health Potion");




	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateSpeedPotion(bool random , int level , int Tier ) {
	Potion * ret = new Potion();
	ret->setType(Speed_PotionType);
	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Speed Potion");

	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateStrengthPotion(bool random , int level , int Tier ) {
	Potion * ret = new Potion();
	ret->setType(Strength_PotionType);
	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Strength Potion");

	return ret;
}




