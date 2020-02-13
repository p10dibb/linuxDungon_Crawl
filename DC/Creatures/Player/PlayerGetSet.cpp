#include "Player.h"


//All the getters and setter for player

//gets the weapon in the players Left hand
Weapon* Player::getLeft() {
	return this->Left;
}

//sets the weapon in the players Left hand
int Player::setLeft(Weapon* l) {
	if (l->getLevel() > this->getLevel()) {
		return 0;
	}
	this->Left = l;
	return 1;
}

//gets the weapon in the players right hand
Weapon* Player::getRight() {
	return this->Right;
}

int Player::setRight(Weapon* l) {
	if (l->getLevel() > this->getLevel()) {
		return 0;
	}
	this->Right = l;
	return 1;
}

int Player::getMoney() {
	return this->Money;

}

void Player::setMoney(int m) {
	if (m<0){
		m=0;
	}
	this->Money = m;

}

//gets the amount of XP needed to level up
int Player::getLevelUp() {
	return this->LevelUp;
}

//sets the amount of XP needed to level up
void Player::setLevelUp(int l) {
	if (l < 1) {
		l = 1;
	}
	this->LevelUp = l;
}


array<InventorySlot,100> Player::getInventory(){
	return this->Inventory;
}


void Player::setInventory(array<InventorySlot,100> i){
	this->Inventory=i;
}

//returns the total amount of free slots left
int Player::getFreeSlots() {
	return this->FreeSlots;
}

//sets the amount of free slots left
void Player::setFreeSlots(int f) {

	if(f>this->InventorySize){
		f=this->InventorySize;
	}else if(f<0){
		f=0;
	}

	this->FreeSlots = f;
}

//gets the current inventory size
int Player::getInventorySize() {
	return this->InventorySize;
}

//sets the current inventory size 0< X<100
void Player::setInventorySize(int i) {
	
	if(i >=this->inventoryMax){
		i=this->inventoryMax-1;
	}else if(i<1){
		i=1;
	}
	this->InventorySize = i;
}

//gets max weight player can carry
int Player::getMaxWeight() {
	return this->MaxWeight;
}

//sets max weight player can carry
void Player::setMaxWeight(int w) {
	if (w < 1) {
		w = 1;
	}
	this->MaxWeight = w;
}

int Player::getCurrentWeight() {
	return this->CurrentWeight;
}

void Player::setCurrentWeight(int w) {
	if (w < 0) {
		w = 0;
	}
	this->CurrentWeight = w;
}

bool Player::getOverWeighted() {
	return this->OverWeighted;
}

void Player::setOverWeighted(bool w) {
	this->OverWeighted = w;
}


