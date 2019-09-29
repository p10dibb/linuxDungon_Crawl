#include "activeEffects.h"

ActiveEffects::ActiveEffects() {
	this->effect = Blank;
	this->roundsActive = 0;
	this->damage = 0;
}
ActiveEffects::ActiveEffects(EffectType e, int r) {
	this->effect =e;
	this->roundsActive = r;
	switch (this->effect)
	{

	case Burning: this->damage = 3; break;
	case Bleeding: this->damage = 3; break;
	default:
		break;
	}
}

EffectType ActiveEffects::getEffect() {
	return this->effect;
}
void ActiveEffects::setEffect(EffectType e) {
	this->effect = e;
	switch (this->effect)
	{

	case Burning: this->damage = 3; break;
	case Bleeding: this->damage = 3; break;
	default:
		break;
	}
}

int ActiveEffects::getRound() {
	return this->roundsActive;
}
void ActiveEffects::setRound(int r) {
	if (r < 0) {
		r = 0;
	}
	this->roundsActive = r;
}

// increases effect time by r
void ActiveEffects::addRounds(int r) {
	this->roundsActive += r;
}

//devreases Effect time by x
bool ActiveEffects::Decrement(int x) {
	if (this->roundsActive == 0){
		return false;
	}

	this->roundsActive -= x;
	return true;
	
}

//checks if effect time is finnished
bool ActiveEffects::isFinished() {
	if (roundsActive == 0) {
		return true;
	}
}

bool ActiveEffects::DisplayDetails() {
	cout << "Type: ";
	switch (this->effect){
	case Burning: cout << "Burning"; break;
	case Bleeding: cout << "Bleeding"; break;
	case Blank: cout << "no effect"; break;
	case Slowed: cout << "Slowed"; break;
	case Dazed: cout << "Dazed"; break;
	case Swiftness: cout << "Swiftness"; break;
	default:
		break;
	}
	cout << endl;
	cout << "Rounds Left: " << this->roundsActive<<endl;

	return true;
}

int ActiveEffects::getDamage() {
	return this->damage;
}

string ActiveEffects::getEffectName() {

	string ret;
	switch (this->effect) {
	case Burning: ret="Burning"; break;
	case Bleeding: ret = "Bleeding"; break;
	case Blank: ret = "no effect"; break;
	case Slowed: ret = "Slowed"; break;
	case Dazed:ret = "Dazed"; break;
	case Swiftness:ret = "Swiftness"; break;
	default:
		break;
	}
	return ret;
}