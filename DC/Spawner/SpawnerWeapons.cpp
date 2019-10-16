#include "Spawner.h"

////creates a Claws based on the level inputed. should be the creatures level
Weapon* Spawner::CreateClaws(int level , bool forceLevel,bool forceRarity,ItemRarity_enum rarity  ) {
	Weapon* ret= new Weapon();
	//the actual weapon level multipied by its rarity used for random generation;
	int RelativeLevel=1;

	ret->setName("Claws");
	ret->setType(Claw_WeaponType);

	if(forceRarity){
		ret->setRarity(rarity);
	}else
	{
		int chance=rand()%20;

		//5%chance
		if(chance>=19){
			ret->setRarity(Legendary_ItemRarity);
		}else if(chance >=15){//20%chance
			ret->setRarity(Rare_ItemRarity);
		}else if(chance>=8){//35%chance
			ret->setRarity(UnCommon_ItemRarity);
		}else{//4% chance
			ret->setRarity(Common_ItemRarity);
		}
	}
	
	

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}
		
	RelativeLevel= ret->getLevel()*((int)ret->getRarity()+1);
		
	
	//adds default Normal damage type;sets damage to medium, speed to strong, sets defense to extra weak
	ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Medium)));
	//adds a critical damage chance
	ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Weak),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));
		


	ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Strong));
	ret->setDefense((ret->getLevel()/2) + rand() % RelativeLevel*Weak);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);

	//adding other Damage Types Claws have Stabbing(~15%), Blunt(~15%) max Probability 25

	if(rand()%7 ==0){
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
	}
	if(rand()%7 ==0){
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
	}

	ret->setValue((RelativeLevel / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);


		return ret;
}

//creates a sword based on the level inputed. should be the creatures level
Weapon* Spawner::CreateSword(int level, bool forceLevel,bool forceRarity,ItemRarity_enum rarity  ) {
	Weapon* ret = new Weapon();
	//the actual weapon level multipied by its rarity used for random generation;
	int RelativeLevel=1;

	ret->setType(Sword_WeaponType);
	
	if(forceRarity){
		ret->setRarity(rarity);
	}else
	{
		int chance=rand()%20;

		//5%chance
		if(chance>=19){
			ret->setRarity(Legendary_ItemRarity);
		}else if(chance >=15){//20%chance
			ret->setRarity(Rare_ItemRarity);
		}else if(chance>=8){//35%chance
			ret->setRarity(UnCommon_ItemRarity);
		}else{//4% chance
			ret->setRarity(Common_ItemRarity);
		}
	}


	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}

	RelativeLevel=ret->getLevel()*((int)ret->getRarity()+1);

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
	ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Medium)));
	//adds a critical damage chance
	ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Medium),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));


	ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Medium));
	ret->setDefense((ret->getLevel() / 2) + rand() % (RelativeLevel * Medium));
	ret->setRange(Medium);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 2);

	//adds random other effects Sword gets Fire(5%), stabing(10%),Blunt(10%)  //max of 25 Probability

	if (rand()%20==0){		
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
	}
	if (rand()%10==0){
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
	
	}
	if (rand()%10==0){
	ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
	
	}

	ret->setValue((RelativeLevel/ 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level );

	return ret;

}

//creates a Dagger based on the level inputed. should be the creatures level
Weapon* Spawner::CreateDagger(int level, bool forceLevel ,bool forceRarity,ItemRarity_enum rarity) {
	Weapon* ret=new Weapon();

	//the actual weapon level multipied by its rarity used for random generation;
	int RelativeLevel=1;

	if(forceRarity){
		ret->setRarity(rarity);
	}else
	{
		int chance=rand()%20;

		//5%chance
		if(chance>=19){
			ret->setRarity(Legendary_ItemRarity);
		}else if(chance >=15){//20%chance
			ret->setRarity(Rare_ItemRarity);
		}else if(chance>=8){//35%chance
			ret->setRarity(UnCommon_ItemRarity);
		}else{//4% chance
			ret->setRarity(Common_ItemRarity);
		}
	}

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}	
	ret->setType(Dagger_WeaponType);

	RelativeLevel=ret->getLevel()*(ret->getRarity()+1);


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
	ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel) * Medium));

	//adds a critical damage chance
	ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Medium),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));

	ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Strong));
	ret->setDefense((ret->getLevel() / 2) + rand() % RelativeLevel*Weak);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);


	//adds random other effects Dagger gets Fire(5%), stabing(25%)  //max of 25 Probability



	if (rand()%20==0){		
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
	}
	if (rand()%4==0){
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
	
	}
	



	ret->setValue((RelativeLevel / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);


	return ret;
}

//creates a Axe based on the level inputed. should be the creatures level
Weapon* Spawner::CreateAxe(int level, bool forceLevel,bool forceRarity,ItemRarity_enum rarity) {
	Weapon* ret = new Weapon();
	//the actual weapon level multipied by its rarity used for random generation;
	int RelativeLevel=1;
	if(forceRarity){
		ret->setRarity(rarity);
	}else
	{
		int chance=rand()%20;

		//5%chance
		if(chance>=19){
			ret->setRarity(Legendary_ItemRarity);
		}else if(chance >=15){//20%chance
			ret->setRarity(Rare_ItemRarity);
		}else if(chance>=8){//35%chance
			ret->setRarity(UnCommon_ItemRarity);
		}else{//4% chance
			ret->setRarity(Common_ItemRarity);
		}
	}
	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}

	ret->setType(Axe_WeaponType);

	RelativeLevel=ret->getLevel()*(ret->getRarity()+1);

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
	ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Strong)));
	//adds a critical damage chance
	ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Strong),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));


	ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Weak));
	ret->setDefense((ret->getLevel() / 2) + rand() % RelativeLevel*Medium);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);


	//adding other Damage Types axe gets Fire(10%), Blunt(10%) max Probability 25


	if (rand()%10==0){		
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
	}
	
	if (rand()%10==0){
	ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
	
	}

	ret->setValue((RelativeLevel / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage()/ 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);


	return ret;


}

//creates a shield based on the level inputed. should be the creatures level
Weapon* Spawner::CreateShield(int level, bool forceLevel ,bool forceRarity,ItemRarity_enum rarity) {
	Weapon* ret=new Weapon();
	//the actual weapon level multipied by its rarity used for random generation;
	int RelativeLevel=1;
	if(forceRarity){
		ret->setRarity(rarity);
	}else
	{
		int chance=rand()%20;

		//5%chance
		if(chance>=19){
			ret->setRarity(Legendary_ItemRarity);
		}else if(chance >=15){//20%chance
			ret->setRarity(Rare_ItemRarity);
		}else if(chance>=8){//35%chance
			ret->setRarity(UnCommon_ItemRarity);
		}else{//4% chance
			ret->setRarity(Common_ItemRarity);
		}
	}
	//random
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}

	ret->setType(Shield_WeaponType);

	RelativeLevel=ret->getLevel()*(ret->getRarity()+1);

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
	ret->addDamageType(DamageTypes(ret->getLevel()/2 + rand() % (RelativeLevel * Weak)));
	
	//adds a critical damage chance
	ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Weak),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));

	ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Medium));
	ret->setDefense((ret->getLevel() ) + rand() % RelativeLevel*Strong);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);


	//adding Damage types Shield gets Blunt(50%)

	
	if (rand()%2==0){
	ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
	
	}

	ret->setValue((RelativeLevel / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-2)*level+(ret->getDamageTypes_Weapon().Size()-3)*level);


	return ret;
}


//Creates a random weapon not claws
Weapon* Spawner::CreateRandomWeapon(int level,bool forceLevel, bool forceRarity,ItemRarity_enum rarity){

	switch (rand()%4)
	{
	case 0:return this->CreateShield(level,forceLevel,forceRarity,rarity);break;
	case 1:return this->CreateSword(level,forceLevel,forceRarity,rarity);break;
	case 2:return this->CreateDagger(level,forceLevel,forceRarity,rarity);break;
	case 3:return this->CreateAxe(level,forceLevel,forceRarity,rarity);break;
	
	default:
		break;
	}

}