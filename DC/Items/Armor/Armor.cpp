#pragma once
#include "Armor.h"


Armor::Armor() {
	Item();
	this->Defense = 0;
	this->Level = 0;
	this->Type = Nill;
	this->Class = Light;
}
Armor::Armor(int def, int lvl, ArmorType type, ArmorClass c) {
	Item();
	this->Defense = def;
	this->Level = lvl;
	this->Type = type;
	this->Class = c;
}
int Armor::getDefense() {
	return this->Defense;
}
void Armor::setDefense(int d) {
	this->Defense = d;

}
int Armor::getLevel() {
	return this->Level;
}
void Armor::setLevel(int l) {
	if (l < 1) {
		l = 1;
	}
	this->Level = l;
}
ArmorType Armor::getType() {
	return this->Type;
}
void Armor::setType(ArmorType t) {
	this->Type = t;
}

ArmorClass Armor::getClass() {
	return this->Class;
}
void Armor::setClass(ArmorClass c) {
	this->Class = c;
}

void Armor::DisplayDetails() {
	cout << "Name: " << this->getName() << endl << "Value: " << this->getValue() << endl << "Weight: " << this->getWeight() << endl << "StackSize: " << this->getStackSize() << endl;

	cout << "Defense: " << this->Defense << endl << "Level: " << this->Level << endl << "Type: " << this->Type << endl;
	
}