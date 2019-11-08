#include "Spawner.h"

//will create a random potion (true Random)
Potion* Spawner::CreateRandomPotion(){
    switch(rand()%17){
        case 0:return CreateSpeedStatPotion();
        case 1:return CreateStrengthStatPotion();
        case 2:return CreateMaxHealthStatPotion();
        case 3: return CreateDefenseStatPotion();
        case 4: return CreateDamageStatPotion();
        case 5: return CreateStaminaStatPotion();
        case 6: return CreateDamageBoostPotion();
        case 7: return CreateDefenseBoostPotion();
        case 8: return CreateSpeedBoostPotion();
        case 9: return CreateCureEffectsPotion();
        case 10: return CreateCureNegativeEffectsPotion();
        case 11:return CreateHealthPotion();
		case 12: return CreateBluntResistancePotion();
		case 13: return CreateNormalResistancePotion();
		case 14: return CreateFireResistancePotion();
		case 15: return CreateStabbingResistancePotion();
		case 16: return CreatePoisonResistancePotion();
        default:return CreateHealthPotion();

    }
}
//will create a random potion (leans more towards health potions) 55%chance
Potion* Spawner::CreateRandomPotion_MoreHealth(){
   switch(rand()%25){
        case 0:return CreateSpeedStatPotion();
        case 1:return CreateStrengthStatPotion();
        case 2:return CreateMaxHealthStatPotion();
        case 3: return CreateDefenseStatPotion();
        case 4: return CreateDamageStatPotion();
        case 5: return CreateStaminaStatPotion();
        case 6: return CreateDamageBoostPotion();
        case 7: return CreateDefenseBoostPotion();
        case 8: return CreateSpeedBoostPotion();
        case 9: return CreateCureEffectsPotion();
        case 10: return CreateCureNegativeEffectsPotion();
		case 12: return CreateBluntResistancePotion();
		case 13: return CreateNormalResistancePotion();
		case 14: return CreateFireResistancePotion();
		case 15: return CreateStabbingResistancePotion();
		case 16: return CreatePoisonResistancePotion();
        default:return CreateHealthPotion();

    }
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

	ret->setValue(5*ret->getTier());
    
    ret ->setDescription("Restors users health");


	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateSpeedStatPotion(bool random , int level , int Tier ) {
	Potion * ret = new Potion();
	ret->setType(SpeedStat_PotionType);
	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Speed Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users speed stat");

	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateStrengthStatPotion(bool random , int level , int Tier ) {
	Potion * ret = new Potion();
	ret->setType(StrengthStat_PotionType);

	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Strength Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users strength stat");

	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateMaxHealthStatPotion(bool random , int level , int Tier ){
    Potion * ret = new Potion();
	ret->setType(MaxHealthStat_PotionType);

	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Max Health Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users MaxHealth stat");

	return ret;
}
	
//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateDefenseStatPotion(bool random , int level , int Tier ){
    Potion * ret = new Potion();
	ret->setType(DefenseStat_PotionType);

	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Defense Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users Defense stat");

	return ret;
}
	
//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateDamageStatPotion(bool random , int level , int Tier ){
    Potion * ret = new Potion();
	ret->setType(DamageStat_PotionType);

	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Damage Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users Damage stat");

	return ret;
}
	
//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateStaminaStatPotion(bool random , int level , int Tier ){
    Potion * ret = new Potion();
	ret->setType(StaminaStat_PotionType);

	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Stamina Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users stamina stat");

	return ret;
}

Potion* Spawner::CreateDefenseBoostPotion(bool random , int level , int Tier ){
		Potion * ret=new Potion();

		ret->setType(IncreaseDefense_PotionType);
		ret->setTier(Tier);
		ret->setValue(10*ret->getTier());
		ret->setName("Tier "+ to_string(ret->getTier())+" Defense Boost");
        ret ->setDescription("Adds a Defense Multiplier to The user");
		return ret;

}

	//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateDamageBoostPotion(bool random , int level , int Tier ){
		Potion * ret=new Potion();

		ret->setType(IncreaseDamage_PotionType);
		ret->setTier(Tier);
		ret->setValue(10*ret->getTier());
		ret->setName("Tier "+ to_string(ret->getTier())+" Damage Boost");
        ret ->setDescription("Adds a Damage Multiplier to The user");
		return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateSpeedBoostPotion(bool random , int level , int Tier){
        Potion * ret=new Potion();

		ret->setType(IncreaseSpeed_PotionType);
		ret->setTier(Tier);
		ret->setValue(10*ret->getTier());
		ret->setName("Tier "+ to_string(ret->getTier())+" Speed Boost");
        ret ->setDescription("Adds a Speed Multiplier to The user");
		return ret;
}

	//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateCureEffectsPotion(bool random , int level , int Tier){
		Potion * ret=new Potion();

		ret->setType( CureActiveEffects_PotionType);
		ret->setTier(Tier);
		ret->setValue(20);
		ret->setName("Cure All Potion");
        ret->setDescription("Removes all Active Effects both good and bad ones");
		return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateCureNegativeEffectsPotion(bool random , int level , int Tier){
        Potion * ret=new Potion();

		ret->setType( CureActiveEffects_PotionType);
		ret->setTier(Tier);
		ret->setValue(40);
		ret->setName("Cure All Negative Effects Potion");
        ret->setDescription("Removes all Damage over Time and Debuff effects");
		return ret;
}


//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateNormalResistancePotion(bool random , int level , int Tier ){
    Potion * ret = new Potion();
	ret->setType(NormalResistance_PotionType);

	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Normal Resistance Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users stamina stat");

	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateFireResistancePotion(bool random , int level , int Tier ){
    Potion * ret = new Potion();
	ret->setType(FireResistance_PotionType);

	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Fire Resistance Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users stamina stat");

	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateBluntResistancePotion(bool random , int level , int Tier ){
    Potion * ret = new Potion();
	ret->setType(BluntResistance_PotionType);

	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Blunt Resistance Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users stamina stat");

	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateStabbingResistancePotion(bool random , int level , int Tier ){

}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreatePoisonResistancePotion(bool random , int level , int Tier ){
    Potion * ret = new Potion();
	ret->setType(PoisonResistance_PotonType);

	ret->setBaseBooster(1);
	if (random) {
		//change later based on level
		ret->setTier(rand() % 5);
	}
	else {
		ret->setTier(Tier);
	}
	ret->setName("Tier " + to_string(ret->getTier()) + "Poison Resistance Potion");
	ret->setValue(5*ret->getTier());
    ret ->setDescription("increases the users stamina stat");

	return ret;
}