#pragma once
#include "Armor.h"

Armor::Armor()
{
	Item();
	this->Level = 1;
	this->Type = NULL_ArmorType;
	this->Class = NULL_ArmorClass;
	this->ResistanceTypes[NormalResistance_Effects] = ActiveEffects(Resistance_EffectTypes, NormalResistance_Effects, 0, 15);
	this->TotalResistance = 0;
}
Armor::Armor(int def, int lvl, ArmorType_enum type, ArmorClass_enum c)
{
	Item();

	this->setLevel(lvl);
	this->Type = type;
	this->Class = c;
	this->ResistanceTypes[NormalResistance_Effects] = ActiveEffects(Resistance_EffectTypes, NormalResistance_Effects, def, 15);
	this->TotalResistance = this->ResistanceTypes[NormalResistance_Effects].getResistance();
}

int Armor::getLevel()
{
	return this->Level;
}
void Armor::setLevel(int l)
{
	if (l < 1)
	{
		l = 1;
	}
	this->Level = l;
}
ArmorType_enum Armor::getType()
{
	return this->Type;
}
void Armor::setType(ArmorType_enum t)
{
	this->Type = t;
}

ArmorClass_enum Armor::getClass()
{
	return this->Class;
}
void Armor::setClass(ArmorClass_enum c)
{
	this->Class = c;
}

void Armor::DisplayDetails()
{
	cout << "Name: " << this->getName() << endl;
	cout << "Value: " << this->getValue() << endl;
	cout << "Weight: " << this->getWeight() << endl;
	cout << "StackSize: " << this->getStackSize() << endl;
	cout << "Level: " << this->Level << endl;
	cout << "Rarity: " << RarityToString(this->getRarity()) << endl;
	cout << "Total Defense: " << getTotalResistance() << endl;
	cout << "Type: " << this->getType_text() << endl;
	cout << "Class: " << this->getClass_text() << endl;
	cout << "Resistances: "; //<< //this->Defense << endl;
	map<Effects_enum, ActiveEffects>::const_iterator it = this->ResistanceTypes.begin();
	ActiveEffects temp;
	while (it != this->ResistanceTypes.end())
	{
		temp = it->second;

		cout << "\t--------- " << endl;
		cout << "\tResistance Type: " << temp.getEffectName() << endl;
		cout << "\t Resistance percent" << temp.getResistance() << endl;

		it++;
	}
}



vector<ActiveEffects> Armor::getResistanceTypes()
{
	vector<ActiveEffects> ret;
	map<Effects_enum, ActiveEffects>::const_iterator it = this->ResistanceTypes.begin();
	ActiveEffects temp;
	while (it != this->ResistanceTypes.end())
	{
		temp = it->second;
		ret.push_back(temp);
		it++;
	}

	return ret;
}
void Armor::setResistanceTypes(map<Effects_enum, ActiveEffects> types)
{
	this->TotalResistance = 0;
	this->ResistanceTypes = types;
	//adds up all of the resistances for armor
	map<Effects_enum, ActiveEffects>::const_iterator it = this->ResistanceTypes.begin();
	ActiveEffects temp;
	while (it != this->ResistanceTypes.end())
	{
		temp = it->second;
		this->TotalResistance += temp.getResistance();

		it++;
	}
}

//return the text equivilent of rarity
string Armor::getRarity_text()
{
	switch (this->getRarity())
	{
	case Common_ItemRarity:
		return "Common";
	case UnCommon_ItemRarity:
		return "UnCommon";
	case Rare_ItemRarity:
		return "Rare";
	case Legendary_ItemRarity:
		return "Legendary";
	case Unique_ItemRarity:
		return "Unique";
	case DEVELOPER_ItemRarity:
		"DEVELOPER";
	default:
		return "Null";
	}
}
//returns the string equivilent of Type (Armor Type)
string Armor::getType_text()
{
	switch (this->getType())
	{
	case Boots_ArmorType:
		return "Boots";
	case Pants_ArmorType:
		return "Leggings";
	case Chest_ArmorType:
		return "Chest Piece";
	case Gloves_ArmorType:
		return "Gloves";
	case Helmet_ArmorType:
		return "Helmet";
	default:
		return "NULL";
	}
}
//returns the string equivilent of Class (Armor Class)
string Armor::getClass_text()
{
	switch (this->getClass())
	{
	case Heavy_ArmorClass:
		return "Heavy Armor";
	case Normal_ArmorClass:
		return "Medium Armor";
	case Light_ArmorClass:
		return "Light Armor";
	default:
		return "NULL";
	}
}

int Armor::getTotalResistance()
{
	return this->TotalResistance;
}

bool Armor::addResistanceType(ActiveEffects resistance)
{
	if (resistance.getEffectType() != Resistance_EffectTypes)
	{
		return false;
	}

	if (this->ResistanceTypes.count(resistance.getEffect()) == 0)
	{
		this->ResistanceTypes[resistance.getEffect()] = resistance;
	}
	else
	{
		this->ResistanceTypes[resistance.getEffect()].setResistance(resistance.getResistance() + ResistanceTypes[resistance.getEffect()].getResistance());
	}
	this->TotalResistance += resistance.getResistance();
	return true;
}

//returns a string for armor type
string armorType_toString(ArmorType_enum a)
{

	switch (a)
	{
	case Helmet_ArmorType:
		return "Helmet";
	case Chest_ArmorType:
		return "Chest Piece";
	case Gloves_ArmorType:
		return "Gloves";
	case Pants_ArmorType:
		return "Leggings";
	case Boots_ArmorType:
		return "Boots";
	default:
		break;
	}
	return "";
}

//returns a string for armor class
string armorClass_toString(ArmorClass_enum a)
{
	switch (a)
	{
	case Heavy_ArmorClass: return "Heavy";
	case Normal_ArmorClass: return "Medium";
	case Light_ArmorClass: return "Light";
	default:
		break;
	}
	return "";
}
