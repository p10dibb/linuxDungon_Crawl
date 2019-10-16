#pragma once
#include <iostream>
#include <string>
#include "../../DataStructures/DoubleLinkedList.h"

using namespace::std;

enum ItemRarity_enum{Common_ItemRarity, UnCommon_ItemRarity, Rare_ItemRarity,Legendary_ItemRarity,Unique_ItemRarity,DEVELOPER_ItemRarity};

class Item {

private:
	string Name;
	int Value;
	int Weight;
	int StackSize;


public:
	virtual ~Item()=default;
	Item();
	Item(string name, int val, int weight, int stacksize);
	string getName();
	void setName(string n);
	int getValue();
	void setValue(int v);
	int getWeight();
	void setWeight(int w);
	int getStackSize();
	void setStackSize(int s);

	void DisplayDetails();


};