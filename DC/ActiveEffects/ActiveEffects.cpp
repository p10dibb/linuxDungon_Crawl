#include "ActiveEffects.h"

ActiveEffects::ActiveEffects() {
	this->Effect = NULL_Effects;
	this->EffectType=NULL_EffectTypes;
	this->RoundsActive = 0;
	this->Modifier = 0;
}


ActiveEffects::ActiveEffects(EffectTypes_enum type,Effects_enum effect,int modifier,int rounds){

	this->EffectType=type;
	this->Effect=effect;	
	this->RoundsActive=rounds;


	switch(this->getEffectType()){
		case Buff_EffectTypes: this->setMultiplier(modifier);break;
		case Resistance_EffectTypes: this->setResistance(modifier);break;
		case DamageOverTime_EffectTypes: this->setDamage(modifier);break;
	    default: this->Modifier=modifier;break;
	}

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


int ActiveEffects::getDamage() {
	return this->Modifier;
}
//only useable for DamageOverTime_EffectTypeused to set damage>=0
void ActiveEffects::setDamage(int damage){
	if(this->EffectType=DamageOverTime_EffectTypes){
		if(damage<0){
			damage=0;
		}
		this->Modifier=damage;
	}else{
		this->Modifier=0;
	}
	
}
//only useable for Resistance_EffectType used to set a resistance between 0 and 100
void ActiveEffects::setResistance(int Resistance){
	if(this->EffectType==Resistance_EffectTypes){
		if(Resistance<0){
			this->Modifier=0;
		}else if(Resistance>100){
			this->Modifier=100;
		}
		this->Modifier=Resistance;
	}else{
		this->Modifier=0;
	}

}

int ActiveEffects::getResistance(){
	return this->Modifier;
}

//only useable for Buff_EffectTypeused to set multiplier>=0
void ActiveEffects::setMultiplier(int multiplier){
	if(this->EffectType==Buff_EffectTypes){
		if(multiplier<0){
			multiplier=0;
		}
		this->Modifier=multiplier;
	}else{
		this->Modifier=0;
	}
}
int ActiveEffects::getMultiplier(){
	return this->Modifier;
}

//used to set modifier
void ActiveEffects::setModifier(int modifier){

}
int ActiveEffects::getModifier(){
	return this->Modifier;
}