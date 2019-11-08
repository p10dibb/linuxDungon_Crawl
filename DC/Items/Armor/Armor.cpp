#pragma once
#include "Armor.h"


Armor::Armor() {
	Item();
	this->Level = 0;
	this->Type = NULL_ArmorType;
	this->Class = NULL_ArmorClass;
	this->ResistanceTypes.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,5,15));
	this->TotalResistance=5;
}
Armor::Armor(int def, int lvl, ArmorType_enum type, ArmorClass_enum c) {
	Item();

	this->Level = lvl;
	this->Type = type;
	this->Class = c;	
	this->ResistanceTypes.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,def,15));
	this->TotalResistance=def;
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
	cout << "Name: " << this->getName() << endl;
	cout << "Value: " << this->getValue() << endl;
	cout << "Weight: " << this->getWeight() << endl;
	cout << "StackSize: " << this->getStackSize() << endl;	
	cout << "Level: " << this->Level << endl ;
	cout <<"Rarity: "<<RarityToString(this->Rarity)<<endl;
	cout<<"Total Defense: "<<getTotalResistance()<<endl;
	cout << "Type: " << this->getType_text()<<endl;
	cout <<"Class: "<< this->getClass_text()<<endl;
	cout << "Resistances: "; //<< //this->Defense << endl; 
	ActiveEffects temp;
	for(int i=0; i<this->getResistanceTypes().Size();i++){
		temp=this->getResistanceTypes().getData(i);
		cout<<"\t-----"<<i+1<<"---- "<<endl;
		cout<<"\tResistance Type: "<<temp.getEffectName()<<endl; 
		cout<<"\t Resistance percent"<<temp.getResistance()<<endl;
		
	}
	
}

ItemRarity_enum Armor::getRarity(){
	return this->Rarity;
}
void Armor::setRarity(ItemRarity_enum rarity){
	this->Rarity=rarity;
}


DoubleLinkedList<ActiveEffects> Armor::getResistanceTypes(){
	return this->ResistanceTypes;
}
void Armor::setResistanceTypes(DoubleLinkedList<ActiveEffects> types){
	this->TotalResistance=0;
	//adds up all of the resistances for armor
	for(int i=0;i<types.Size();i++){
		this->TotalResistance+=types.getData(i).getResistance();
	}
	this->ResistanceTypes=types;
}

//return the text equivilent of rarity
string Armor::getRarity_text(){
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
//returns the string equivilent of Type (Armor Type)	
string Armor::getType_text(){
	switch(this->getType()){
		case Boots_ArmorType:return "Boots";
		case Pants_ArmorType:return "Leggings";
		case Chest_ArmorType:return "Chest Piece";
		case Gloves_ArmorType:return "Gloves";
		case Helmet_ArmorType:return "Helmet";
		default: return "NULL";
	}
}
//returns the string equivilent of Class (Armor Class)
string Armor::getClass_text(){
	switch(this->getClass()){
		case Heavy_ArmorClass: return "Heavy Armor";
		case Normal_ArmorClass:return "Medium Armor";
		case Light_ArmorClass:return "Light Armor";
		default:return "NULL";
	}
}

int Armor::getTotalResistance(){
	return this->TotalResistance;
}