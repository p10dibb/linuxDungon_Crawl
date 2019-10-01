#pragma once
#include "../Item/Item.h"

enum ArmorClass_enum {  NULL_ArmorClass,Light_ArmorClass, Normal_ArmorClass, Heavy_ArmorClass };
enum ArmorType_enum {NULL_ArmorType, Helmet_ArmorType, Chest_ArmorType, Gloves_ArmorType, Pants_ArmorType, Boots_ArmorType};

class Armor :public Item {
friend class Item;
private:
	int Defense;
	int Level;
	ArmorType_enum Type;
	ArmorClass_enum Class;


public:
	Armor();
	Armor(int def, int lvl, ArmorType_enum type, ArmorClass_enum c);
	int getDefense();
	void setDefense(int d);
	int getLevel();
	void setLevel(int l);
	ArmorType_enum getType();
	void setType(ArmorType_enum t);
	ArmorClass_enum getClass();
	void setClass(ArmorClass_enum c);


	void DisplayDetails();
};