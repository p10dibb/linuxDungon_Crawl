#include "Spawner.h"

//Creates a helmet
Armor* Spawner::CreateHelmet(int level, ArmorClass_enum c,bool forceLevel ,bool forceRarity,ItemRarity_enum rarity) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret= new Armor();
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
	
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}

	RelativeLevel=ret->getLevel()*(ret->getRarity()+1);


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

	DoubleLinkedList<ActiveEffects> Resistance;
	Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));

	//10% chance for each resistance
	//Fire Resistance
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
	}

	ret->setResistanceTypes(Resistance);


	ret->setStackSize(1);
	ret->setValue(RelativeLevel+ret->getResistanceTypes().Size() + ret->getWeight());

	return ret;





}

//Creates a chestplate
Armor* Spawner::CreateChest(int level, ArmorClass_enum c, bool forceLevel ,bool forceRarity,ItemRarity_enum rarity) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor;

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

	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}

	RelativeLevel=ret->getLevel()*(ret->getRarity()+1);

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
	DoubleLinkedList<ActiveEffects> Resistance;
	Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));

	//10% chance for each resistance
	//Fire Resistance
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
	}

	ret->setResistanceTypes(Resistance);

	ret->setStackSize(1);
	ret->setValue(RelativeLevel + ret->getResistanceTypes().Size() + ret->getWeight());

	return ret;
}

//Creates a Gloves
Armor* Spawner::CreateGloves(int level, ArmorClass_enum c, bool forceLevel ,bool forceRarity,ItemRarity_enum rarity) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor();
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

	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}

	RelativeLevel=ret->getLevel()*(ret->getRarity()+1);


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

	DoubleLinkedList<ActiveEffects> Resistance;
	Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));

	//10% chance for each resistance
	//Fire Resistance
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
	}

	ret->setResistanceTypes(Resistance);

	ret->setStackSize(1);
	ret->setValue(RelativeLevel + ret->getResistanceTypes().Size() + ret->getWeight());

	return ret;


}

//Creates Pants
Armor* Spawner::CreatePants(int level, ArmorClass_enum c, bool forceLevel ,bool forceRarity,ItemRarity_enum rarity) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor();
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

	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}

	RelativeLevel=ret->getLevel()*(ret->getRarity()+1);


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

	DoubleLinkedList<ActiveEffects> Resistance;
	Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));

	//10% chance for each resistance
	//Fire Resistance
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
	}
	//StabbingResistance
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
	}
	//Poison Resistance
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
	}
	//Blunt Resistance
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
	}

	ret->setResistanceTypes(Resistance);

	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + ret->getResistanceTypes().Size() + ret->getWeight());

	return ret;


}

//Creates Boots
Armor* Spawner::CreateBoots(int level, ArmorClass_enum c, bool forceLevel ,bool forceRarity,ItemRarity_enum rarity) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor();

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

	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}

	RelativeLevel=ret->getLevel()*(ret->getRarity()+1);

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

	DoubleLinkedList<ActiveEffects> Resistance;
	Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));

	//10% chance for each resistance
	//Fire Resistance
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
	}
	if(rand()%10==0){
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
	}

	ret->setResistanceTypes(Resistance);
	ret->setStackSize(1);
	ret->setValue(RelativeLevel + ret->getResistanceTypes().Size() +ret->getWeight());

	return ret;

}

//creates a random piece of armor
Armor* Spawner::CreateRandomArmor(int level, bool forceLevel, bool forceRarity,ItemRarity_enum rarity){
	//get random selection of ligh, normal, or heavy
	ArmorClass_enum randClass=(ArmorClass_enum)((rand()%3)+1);

	//randomly pics an armor type to create and return
	switch (rand()%5)
	{
	case 0:return this->CreateHelmet(level,randClass,forceLevel,forceRarity,rarity);break;
	case 1:return this->CreateChest(level,randClass,forceLevel,forceRarity,rarity);break;
	case 2:return this->CreateGloves(level,randClass,forceLevel,forceRarity,rarity);break;
	case 3:return this->CreatePants(level,randClass,forceLevel,forceRarity,rarity);break;
	case 4:return this->CreateBoots(level,randClass,forceLevel,forceRarity,rarity);break;
	
	default:
		break;
	}


}