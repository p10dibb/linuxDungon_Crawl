#pragma once
#include "Item.h"

enum ArmorClass {  Light, Normal, Heavy };
enum ArmorType {Nill,Helmet,Chest,Gloves, Pants, Boots};

class Armor :public Item {
friend class Item;
private:
	int Defense;
	int Level;
	ArmorType Type;
	ArmorClass Class;


public:
	Armor();
	Armor(int def, int lvl, ArmorType type, ArmorClass c);
	int getDefense();
	void setDefense(int d);
	int getLevel();
	void setLevel(int l);
	ArmorType getType();
	void setType(ArmorType t);
	ArmorClass getClass();
	void setClass(ArmorClass c);


	void DisplayDetails();
};