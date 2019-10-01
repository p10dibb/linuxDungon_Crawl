#pragma once
#include "Armor.h"


Armor::Armor() {
	Item();
	this->Defense = 0;
	this->Level = 0;
	this->Type = NULL_ArmorType;
	this->Class = NULL_ArmorClass;
}
Armor::Armor(int def, int lvl, ArmorType_enum type, ArmorClass_enum c) {
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
ArmorType_enum Armor::getType() {
	return this->Type;
}
void Armor::setType(ArmorType_enum t) {
	this->Type = t;
}

ArmorClass_enum Armor::getClass() {
	return this->Class;
}
void Armor::setClass(ArmorClass_enum c) {
	this->Class = c;
}

void Armor::DisplayDetails() {
	cout << "Name: " << this->getName() << endl << "Value: " << this->getValue() << endl << "Weight: " << this->getWeight() << endl << "StackSize: " << this->getStackSize() << endl;

	cout << "Defense: " << this->Defense << endl << "Level: " << this->Level << endl << "Type: " << this->Type << endl;
	
}