#include "Potion.h"

Potion::Potion() {
	Item();
	this->Tier = 1;
	this->Type = NULL_PotionType;
	this->BaseBooster = 0;
	this->setStackSize(5);

}

//the use if it is a health potion
bool Potion::UseHealth(Creature *creature){

	creature->setHealth(creature->getHealth() + this->Tier*this->BaseBooster);
	if (creature->getHealth() > creature->getMaxHealth()) {
		creature->setHealth(creature->getMaxHealth());
	}

	return true;
}

//the use if it is a speed potion
bool Potion::UseSpeedStat(Creature *creature) {
	creature->setSpeed(creature->getSpeed() + this->Tier);
	return true;
}

//the use  if it is a strength potion
bool Potion::UseStrengthStat(Creature *creature) {
	creature->setStrength(creature->getStrength() + this->Tier);
	return true;
}

//increases strength skill point by Tier
bool Potion::UseMaxHealthStat(Creature *creature){
	creature->setMaxHealth(creature->getMaxHealth() + this->Tier*10);
	creature->setHealth(creature->getHealth() + this->Tier*10);
	return true;
}
//increases strength skill point by Tier
bool Potion::UseDefenseStat(Creature *creature){
	creature->setDefense(creature->getDefense() + this->Tier);
	return true;
}
//increases strength skill point by Tier
bool Potion::UseDamageStat(Creature *creature){
	creature->setDamage(creature->getDamage() + this->Tier);
	return true;
}
//increases strength skill point by Tier
bool Potion::UseStaminaStat(Creature *creature){
	creature->setStamina(creature->getStamina() + this->Tier);
	return true;
}

//the general use detects which type of potion and runs the actual use function
bool Potion::Use(Creature *creature) {

	switch (this->Type)
	{

	case NULL_PotionType: cout << "You drank water, it did nothing" << endl; break;
	case Health_PotionType: this->UseHealth(creature); break;
	case SpeedStat_PotionType:this->UseSpeedStat(creature); break;
	case StrengthStat_PotionType: this->UseStrengthStat(creature); break;
	case MaxHealthStat_PotionType: this->UseMaxHealthStat(creature);break;
	case DefenseStat_PotionType: this->UseDefenseStat(creature);break;
	case DamageStat_PotionType: this->UseDamageStat(creature); break;
	case StaminaStat_PotionType: this->UseStaminaStat(creature);break;
	case IncreaseDamage_PotionType: this->UseIncreaseDamage(creature);break;
	case IncreaseDefense_PotionType: this->UseIncreaseDefense(creature);break;
	case IncreaseSpeed_PotionType: this->UseIncreaseSpeed(creature);break;
	case CureActiveEffects_PotionType:this->UseCureActiveEffects(creature);break;
	case CureNegativeEffects_PotionType: this->UseCureNegativeEffects(creature);break;
	default: return false;
		break;
	}
	return true;
}


//Displays relevent info for the potion
void Potion::DisplayDetails() {
	cout << this->getName() << endl;
	cout << "Value: " << this->getValue()<<endl;
	cout<< "Tier: "<<this->getTier()<<endl;
	cout<< "Type: "<< this->getTypeName()<<endl;
	cout<< "Base: "<< this->getBaseBooster()<<endl;
	cout<< "Description: "<<this->getDescription();


}


PotionTypes_enum Potion::getType() {
	return this->Type;
}
void Potion::setType(PotionTypes_enum t) {
	this->Type = t;
}
int Potion::getTier() {
	return this->Tier;
}
void Potion::setTier(int t) {
	if (t < 1) {
		t = 1;
	}
	this->Tier = t;
}
int Potion::getBaseBooster() {
	return this->BaseBooster;
}
void Potion::setBaseBooster(int b) {
	this->BaseBooster = b;

}



bool Potion::UseIncreaseSpeed(Creature *creature){
	creature->AddEffect(ActiveEffects(Buff_EffectTypes,SpeedBoost_Effects,this->Tier,5));

}
//adds a damage multiplier of Tier active effect
bool Potion::UseIncreaseDamage(Creature *creature){
	
	creature->AddEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,this->Tier,5));
	return true;

}
//adds a Damage reduction multiplier of Tier active effect
bool Potion::UseIncreaseDefense(Creature *creature){
	creature->AddEffect(ActiveEffects(Buff_EffectTypes,DefenseBoost_Effects,this->Tier,5));

	return true;
}
//removes all active effects both good and bad
bool Potion::UseCureActiveEffects(Creature *creature){
	creature->ClearAllEffects();
	cout<<"all Effects Removed"<<endl;
	return true;
}


//removes all DOT and DeBuff effects from creature
bool Potion::UseCureNegativeEffects(Creature *creature){
	creature->ClearAllDeBuffEffects();
	creature->ClearAllDamageOverTimeEffects();
	cout<<"All Damage Over Time effects and all De Buff Effects removed"<<endl;
}
	
//returns the potions name based on its type
string Potion::getTypeName(){
	switch (this->Type)
	{

	case NULL_PotionType: return "NULL";
	case Health_PotionType: return "Restore Health";
	case SpeedStat_PotionType:return "Speed Stat Boost";
	case StrengthStat_PotionType: return "Strength Stat Boost";
	case MaxHealthStat_PotionType: return "MaxHealth Stat Boost";
	case DefenseStat_PotionType: return "Defense Stat Boost";
	case DamageStat_PotionType: return "Damage Stat Boost";
	case StaminaStat_PotionType: return "Stamina Stat Boost";
	case IncreaseDamage_PotionType: return "Damage Boost Effect";
	case IncreaseDefense_PotionType: return "Defense Boost Effect";
	case IncreaseSpeed_PotionType: return "Speed Boost Effect";
	case CureActiveEffects_PotionType:return "Cure All Effects";
	case CureNegativeEffects_PotionType: return "Cure All Negativve Effects";
	default:
		break;
	}
	return "";
}
