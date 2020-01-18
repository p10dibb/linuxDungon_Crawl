#pragma once
#include "../../ActiveEffects/ActiveEffects.h"

class Item {

private:
	string Name;
	int Value;
	int Weight;
	int StackSize;
	string Description;


public:
	virtual ~Item()=default;
	Item();
	Item(string name, int val, int weight, int stacksize, string description="");
	string getName();
	void setName(string n);
	int getValue();
	void setValue(int v);
	int getWeight();
	void setWeight(int w);
	int getStackSize();
	void setStackSize(int s);

	void DisplayDetails();

	string getDescription();
	void setDescription(string description);


};

//takes a rarity level and returns a string
string RarityToString(ItemRarity_enum rarity);