#pragma once
#include "Weapon.h"

Weapon::Weapon() {
	Item();
	this->Type = NULL_WeaponType;
	this->DamageTypes_Weapon.add(DamageTypes());

	this->Defense = this->Defense= ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,15);;
	this->TwoHanded = false;
	this->Speed = 0;
	this->Level = 0;
	this->Range = 0;
}
Weapon::Weapon(int Dam, int Def, bool TH, int Sp, int Lvl, int Rng,WeaponTypes_enum type, DoubleLinkedList<DamageTypes> damageTypes) {
	Item();
	this->Type = type;
	this->Defense= ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,Def,15);
	this->TwoHanded = TH;
	this->Speed = Sp;
	this->Level = Lvl;
	this->Range = Rng;
	this->DamageTypes_Weapon=damageTypes;
}

ActiveEffects Weapon::getDefense() {
	return this->Defense;

}
void Weapon::setDefense(int d) {
	if (d < 0) {
		d = 0;
	}
	else if(d>100){
		d=100;
	}
	this->Defense= ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,d,15);

}
bool Weapon::getTwoHanded() {
	return this->TwoHanded;
}
void Weapon::setTwoHanded(bool t) {
	this->TwoHanded = t;
}
int Weapon::getSpeed() {
	return this->Speed;
}
void Weapon::setSpeed(int s) {
	if (s < 1) {
		s = 1;
	}
	this->Speed = s;
}
int Weapon::getLevel() {
	return this->Level;
}
void Weapon::setLevel(int l) {
	if (l < 1) {
		l = 1;
	}
	this->Level = l;
}
int Weapon::getRange() {
	return this->Range;
}
void Weapon::setRange(int r) {
	if (r < 1) {
		r = 1;
	}
	this->Range = r;
};


WeaponTypes_enum Weapon:: getType() {
	return this->Type;
}
void Weapon::setType(WeaponTypes_enum w) {
	this->Type = w;
}

void Weapon::DisplayDetails() {
	cout << "Name: \t" << this->getName() << endl << "Value: \t" << this->getValue() << endl << "Weight: \t" << this->getWeight() << endl << "StackSize: \t" << this->getStackSize() << endl;
	cout << "Level: \t" << this->Level << endl;
	cout << "Damage Resistance: \t" << this->Defense.getResistance()<<endl;
	cout << "Speed: \t" << this->Speed << endl;
	cout << "Is TwoHanded:\t" << this->TwoHanded << endl;
	cout << "Range: \t" << this->Range << endl;
	cout << "Rarity:\t"<<this->getRarity_text()<<endl;
	cout<<"Damage Types:"<<endl;
	for(int i=0;i<this->DamageTypes_Weapon.Size();i++){
		this->DamageTypes_Weapon.getData(i).DisplayDetails();
	}

}

DoubleLinkedList<DamageTypes> Weapon::getDamageTypes_Weapon(){
		return this->DamageTypes_Weapon;
}
void Weapon::setDamageTypes_Weapon(DoubleLinkedList<DamageTypes> damagetypes){
		this->DamageTypes_Weapon=damagetypes;
}
void Weapon::addDamageType(DamageTypes type){
		this->DamageTypes_Weapon.add(type);
}


ItemRarity_enum Weapon::getRarity(){
	return this->Rarity;
}
void Weapon::setRarity(ItemRarity_enum rarity){
	this->Rarity=rarity;
}


//return the text equivilent of rarity
string Weapon::getRarity_text(){
	switch (this->getRarity())
	{
	case Common_ItemRarity:return "Common";
	case UnCommon_ItemRarity: return "UnCommon";
	case Rare_ItemRarity: return "Rare";
	case Legendary_ItemRarity: return "Legendary";
	case Unique_ItemRarity: return "Unique";
	case DEVELOPER_ItemRarity: "DEVELOPER";
	default:return "Null";
	}

}