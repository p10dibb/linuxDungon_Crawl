#pragma once
#include "../Item/Item.h"



class Armor :public Item {
friend class Item;
private:
	//Armor's Level
	int Level;
	//the total resistance percentage
	int TotalResistance;
	//the armor type of this piece
	ArmorType_enum Type;
	//class (light, normal, or heavy)
	ArmorClass_enum Class;
	//items rarity
	ItemRarity_enum Rarity;
	//all of the resistances
	map<Effects_enum,ActiveEffects> ResistanceTypes;


public:
	Armor();
	Armor(int def, int lvl, ArmorType_enum type, ArmorClass_enum c);
	
	int getLevel();
	void setLevel(int l);
	ItemRarity_enum getRarity();
	void setRarity(ItemRarity_enum rarity);
	ArmorType_enum getType();
	void setType(ArmorType_enum t);
	ArmorClass_enum getClass();
	void setClass(ArmorClass_enum c);

	
	vector<ActiveEffects> getResistanceTypes();
	void setResistanceTypes(map<Effects_enum,ActiveEffects> types);
	bool addResistanceType(ActiveEffects resistance);

	//return the string equivilent of rarity
	string getRarity_text();
	//returns the string equivilent of Type (Armor Type)	
	string getType_text();
	//returns the string equivilent of Class (Armor Class)
	string getClass_text();

	//Displays all relevent Armor details
	void DisplayDetails();

	int getTotalResistance();


};

//returns a string for armor type
string armorType_toString(ArmorType_enum a);

//returns a string for armor class
string armorClass_toString(ArmorClass_enum a);
