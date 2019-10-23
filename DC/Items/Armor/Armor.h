#pragma once
#include "../Item/Item.h"

enum ArmorClass_enum {  NULL_ArmorClass,Light_ArmorClass, Normal_ArmorClass, Heavy_ArmorClass };
enum ArmorType_enum {NULL_ArmorType, Helmet_ArmorType, Chest_ArmorType, Gloves_ArmorType, Pants_ArmorType, Boots_ArmorType};

class Armor :public Item {
friend class Item;
private:

	int Level;
	ArmorType_enum Type;
	ArmorClass_enum Class;
	ItemRarity_enum Rarity;
	DoubleLinkedList<ActiveEffects> ResistanceTypes;


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

	DoubleLinkedList<ActiveEffects> getResistanceTypes();
	void setResistanceTypes(DoubleLinkedList<ActiveEffects> types);

	//return the string equivilent of rarity
	string getRarity_text();
	//returns the string equivilent of Type (Armor Type)	
	string getType_text();
	//returns the string equivilent of Class (Armor Class)
	string getClass_text();

	//Displays all relevent Armor details
	void DisplayDetails();


};