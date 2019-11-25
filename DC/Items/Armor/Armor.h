#pragma once
#include "../Item/Item.h"


enum ArmorClass_enum {  NULL_ArmorClass,Light_ArmorClass, Normal_ArmorClass, Heavy_ArmorClass };
enum ArmorType_enum {NULL_ArmorType, Helmet_ArmorType, Chest_ArmorType, Gloves_ArmorType, Pants_ArmorType, Boots_ArmorType};

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
	//DoubleLinkedList<ActiveEffects> ResistanceTypes;


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