#include "Player.h"


//All the getters and setter for player





Weapon* Player::getLeft() {
	return this->Left;
}
int Player::setLeft(Weapon* l) {
	if (l->getLevel() > this->getLevel()) {
		return 0;
	}
	this->Left = l;
	return 1;
}
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
	this->Money = m;

}


int Player::getLevelUp() {
	return this->LevelUp;
}

void Player::setLevelUp(int l) {
	if (l < 1) {
		l = 1;
	}
	this->LevelUp = l;
}



//InventorySlot* Player::getInventory() {
//	return this->Inventory;
//}

void Player::setInventory(InventorySlot i[40]) {
	//this->Inventory = i;
}
int Player::getFreeSlots() {
	return this->FreeSlots;
}
void Player::setFreeSlots(int f) {
	this->FreeSlots = f;
}


int Player::getMaxWeight() {
	return this->MaxWeight;
}
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


int Player::getInventorySize() {
	return this->InventorySize;
}
void Player::setInventorySize(int i) {
	this->InventorySize = i;
}