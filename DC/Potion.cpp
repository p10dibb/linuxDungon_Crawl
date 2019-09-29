#include "Potion.h"

Potion::Potion() {
	Item();
	this->Tier = 1;
	this->Type = Water;
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

	case Water: cout << "You drank water it did nothing" << endl; break;
	case Health: this->UseHealth(c); break;
	case Speed:this->UseSpeedBooster(c); break;
	case Strength: this->UseStrengthBooster(c); break;
	default:
		break;
	}
	return true;
}


//Displays relevent info for the potion
void Potion::DisplayDetails() {
	cout << this->getName() << endl;
	cout << "Value: " << this->getValue()<<endl;

	if (this->Type == Health) {
		cout << "Restores "<<to_string(this->Tier*this->BaseBooster) << " Health" << endl;
	}
	else if (this->Type == Speed) {
		cout << "increases base speed by " << to_string(this->Tier*this->BaseBooster) << endl;
	}
	else if (this->Type == Strength) {
		cout << "increases base Strength by " << to_string(this->Tier*this->BaseBooster) << endl;
	}

}


PotionTypes Potion::getType() {
	return this->Type;
}
void Potion::setType(PotionTypes t) {
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