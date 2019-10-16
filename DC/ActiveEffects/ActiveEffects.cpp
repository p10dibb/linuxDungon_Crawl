#include "ActiveEffects.h"

ActiveEffects::ActiveEffects() {
	this->Effect = NULL_Effects;
	this->EffectType=NULL_EffectTypes;
	this->RoundsActive = 0;
	this->Damage = 0;
}
// ActiveEffects::ActiveEffects(Effects_enum e, int rounds) {
// 	this->effect =e;
// 	this->roundsActive = rounds;
// 	switch (this->effect)
// 	{

// 	case Burning_Effects: this->damage = 3; break;
// 	case Bleeding_Effects: this->damage = 3; break;
// 	default:
// 		break;
// 	}
// 	//this->isDamage=true;
// }


// ActiveEffects::ActiveEffects(Effects_enum e, int rounds,int damage){
// 	this->effect=e;
// 	this->setRound(rounds);
// 	this->damage=damage;
// 	//this->isDamage=true;

// }

// ActiveEffects::ActiveEffects(Effects_enum e, int rounds,int damage,bool isdamage){
// 	this->effect=e;
// 	this->setRound(rounds);
// 	this->damage=damage;
// 	//this->isDamage=isdamage;
// }

ActiveEffects::ActiveEffects(EffectTypes_enum type,Effects_enum effect,int damage,int rounds){

	this->EffectType=type;
	this->Effect=effect;
	this->Damage=damage;
	this->RoundsActive=rounds;

}

EffectTypes_enum ActiveEffects::getEffectType(){
	return this->EffectType;
}


Effects_enum ActiveEffects::getEffect() {
	return this->Effect;
}


int ActiveEffects::getRound() {
	return this->RoundsActive;
}
void ActiveEffects::setRound(int r) {
	if (r < 0) {
		r = 0;
	}
	this->RoundsActive = r;
}

// increases effect time by r
void ActiveEffects::addRounds(int r) {
	this->RoundsActive += r;
}

//devreases Effect time by x
bool ActiveEffects::Decrement(int x) {
	if (this->RoundsActive == 0){
		return false;
	}

	this->RoundsActive -= x;
	return true;
	
}

//checks if effect time is finnished
bool ActiveEffects::isFinished() {
	if (RoundsActive == 0) {
		return true;
	}
}

bool ActiveEffects::DisplayDetails() {
	cout << "Type: "<<this->getEffectName();
	cout << endl;
	cout << "Rounds Left: " << this->RoundsActive<<endl;

	return true;
}

int ActiveEffects::getDamage() {
	return this->Damage;
}

//!!!!!!!Need to update!!!!!!
string ActiveEffects::getEffectName() {

	string ret;
	switch (this->Effect) {
	case Burning_Effects: ret="Burning"; break;
	case Bleeding_Effects: ret = "Bleeding"; break;
	case NULL_Effects: ret = "no effect"; break;
	case Slowed_Effects: ret = "Slowed"; break;
	case Dazed_Effects:ret = "Dazed"; break;
	case SpeedBoost_Effects:ret = "Swiftness"; break;
	case DamageBoost_Effects: ret="Increased Damage";break;
	case DefenseBoost_Effects: ret="Increased Defense";break;
	default:
		break;
	}
	return ret;
}


void ActiveEffects::setDamage(int damage){
	if(damage<0){
		damage=0;
	}
	this->Damage=damage;
}



