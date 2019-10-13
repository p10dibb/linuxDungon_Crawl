#include "Potion.h"

Potion::Potion() {
	Item();
	this->Tier = 1;
	this->Type = NULL_PotionType;
	this->BaseBooster = 0;
	this->setStackSize(5);

}

//the use if it is a health potion
bool Potion::UseHealth(Creature *c){

	c->setHealth(c->getHealth() + this->Tier*this->BaseBooster);
	if (c->getHealth() > c->getMaxHealth()) {
		c->setHealth(c->getMaxHealth());
	}

	return true;
}

//the use if it is a speed potion
bool Potion::UseSpeedBooster(Creature *h) {
	h->setSpeed(h->getSpeed() + this->Tier*this->Type);
	return true;
}

//the use  if it is a strength potion
bool Potion::UseStrengthBooster(Creature *p) {
	p->setStrength(p->getStrength() + this->Tier*this->Type);
	return true;
}

//the general use detects which type of potion and runs the actual use function
bool Potion::Use(Creature *c) {

	switch (this->Type)
	{

	case NULL_PotionType: cout << "You drank water, it did nothing" << endl; break;
	case Health_PotionType: this->UseHealth(c); break;
	case Speed_PotionType:this->UseSpeedBooster(c); break;
	case Strength_PotionType: this->UseStrengthBooster(c); break;
	case IncreaseDamage_PotionType: this->UseIncreaseDamage(c);break;
	case IncreaseDefense_PotionType: this->UseIncreaseDefense(c);break;
	case CureActiveEffects_PotionType:this->UseCureActiveEffects(c);break;
	default:
		break;
	}
	return true;
}


//Displays relevent info for the potion
void Potion::DisplayDetails() {
	cout << this->getName() << endl;
	cout << "Value: " << this->getValue()<<endl;

	if (this->Type == Health_PotionType) {
		cout << "Restores "<<to_string(this->Tier*this->BaseBooster) << " Health" << endl;
	}
	else if (this->Type == Speed_PotionType) {
		cout << "increases base speed by " << to_string(this->Tier*this->BaseBooster) << endl;
	}
	else if (this->Type == Strength_PotionType) {
		cout << "increases base Strength by " << to_string(this->Tier*this->BaseBooster) << endl;
	}

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



bool Potion::UseIncreaseSpeed(Creature *p){
	p->AddEffect(SpeedBoost_EffectType,5,this->Tier,false);

}
//adds a damage multiplier of Tier active effect
bool Potion::UseIncreaseDamage(Creature *p){
	
	p->AddEffect(DamageBoost_EffectType,5,this->Tier,false);
	return true;

}
//adds a Damage reduction multiplier of Tier active effect
bool Potion::UseIncreaseDefense(Creature *p){
	p->AddEffect(DefenseBoost_EffectType,5,this->Tier,false);
	return true;
}
//removes all active effects both good and bad
bool Potion::UseCureActiveEffects(Creature *p){
	p->ClearAllEffects();
	cout<<"all Effects Removed"<<endl;
	return true;
}
	