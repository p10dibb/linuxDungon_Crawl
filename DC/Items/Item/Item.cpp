#pragma once
#include "Item.h"



Item::Item() {
	this->Name = "Empty";
	this->Value = 0;
	this->Weight = 0;
	this->StackSize = 1;
	this->Description="";
}


Item::Item(string name, int val, int weight, int stacksize,string description) {
	this->Name = name;
	this->Value = val;
	this->Weight = weight;
	this->StackSize = stacksize;
	this->Description=description;
}

string Item::getName() {
	return this->Name;
}

void Item::setName(string n) {
	this->Name = n;
}
int Item::getValue() {
	return this->Value;
}

void Item::setValue(int v) {
	if (v < 1) {
		v = 1;
	}
	this->Value = v;
}

int Item::getWeight() {
	return this->Weight;
}

void Item::setWeight(int w) {
	if (w < 0) {
		w = 0;
	}
	this->Weight = w;
}

int Item::getStackSize() {
	return this->StackSize;
}

void Item::setStackSize(int s) {
	if (s < 1) {
		s = 1;
	}
	this->StackSize = s;
}


void Item::DisplayDetails() {
	cout << "Name: \t" << this->Name << endl << "Value: \t" << this->Value << endl << "Weight: \t" << this->Weight << endl << "StackSize: \t" << this->StackSize << endl;
}

string Item::getDescription(){
	return this->Description;
}
void Item::setDescription(string description){
	this->Description=description;
}