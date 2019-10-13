#include "ActiveEffects.h"

ActiveEffects::ActiveEffects() {
	this->effect = NULL_EffectType;
	this->roundsActive = 0;
	this->damage = 0;
	this->isDamage=true;
}
ActiveEffects::ActiveEffects(EffectType_enum e, int rounds) {
	this->effect =e;
	this->roundsActive = rounds;
	switch (this->effect)
	{

	case Burning_EffectType: this->damage = 3; break;
	case Bleeding_EffectType: this->damage = 3; break;
	default:
		break;
	}
	this->isDamage=true;
}


ActiveEffects::ActiveEffects(EffectType_enum e, int rounds,int damage){
	this->effect=e;
	this->setRound(rounds);
	this->damage=damage;
	this->isDamage=true;

}

ActiveEffects::ActiveEffects(EffectType_enum e, int rounds,int damage,bool isdamage){
	this->effect=e;
	this->setRound(rounds);
	this->damage=damage;
	this->isDamage=isdamage;
}

EffectType_enum ActiveEffects::getEffect() {
	return this->effect;
}
void ActiveEffects::setEffect(EffectType_enum e) {
	this->effect = e;
	switch (this->effect)
	{

	case Burning_EffectType: this->damage = 3; break;
	case Bleeding_EffectType: this->damage = 3; break;
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
	cout << "Type: "<<this->getEffectName();
	// switch (this->effect){
	// case Burning_EffectType: cout << "Burning"; break;
	// case Bleeding_EffectType: cout << "Bleeding"; break;
	// case NULL_EffectType: cout << "no effect"; break;
	// case Slowed_EffectType: cout << "Slowed"; break;
	// case Dazed_EffectType: cout << "Dazed"; break;
	// case SpeedBoost_EffectType: cout << "Swiftness"; break;
	// default:
	// 	break;
	// }
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
	case Burning_EffectType: ret="Burning"; break;
	case Bleeding_EffectType: ret = "Bleeding"; break;
	case NULL_EffectType: ret = "no effect"; break;
	case Slowed_EffectType: ret = "Slowed"; break;
	case Dazed_EffectType:ret = "Dazed"; break;
	case SpeedBoost_EffectType:ret = "Swiftness"; break;
	case DamageBoost_EffectType: ret="Increased Damage";break;
	case DefenseBoost_EffectType: ret="Increased Defense";break;
	default:
		break;
	}
	return ret;
}

void ActiveEffects::setEffect(EffectType_enum e, int damage){
	this->effect=e;
	this->damage=damage;
}


bool ActiveEffects::getIsDamage(){
	return this->isDamage;
}

void ActiveEffects::setIsDamage(bool damaging){
	this->isDamage=damaging;
}