#include "Biped.h"

Biped::Biped() {
	Creature();


	this->Head = new  Armor(0, 0, Helmet, Light);
	this->Head->setName("Hat");
	this->Torso = new Armor(0, 0, Chest, Light);
	this->Torso->setName("Shirt");
	this->Legs = new Armor(0, 0, Pants, Light);
	this->Legs->setName("Pants");
	this->Hands = new  Armor(0, 0, Gloves, Light);
	this->Hands->setName("Basic");
	this->Feet = new Armor(0, 0, Boots, Light);
	this->Feet->setName("sandals");
}


int  Biped::Attack() {
	return this->getDamage();
}


int  Biped::TakeDamage(int attack) {
	int health = this->getHealth();
	int damageTaken = 0;
	if ((attack - (this->getDefense())) < 0) {
		health = health - 1;
		damageTaken = 1;
	}
	else {
		damageTaken = attack - (this->getDefense());
		health = health - damageTaken;
	}
	if (health < 0) {
		health = 0;
	}
	this->setHealth(health);
	return damageTaken;
}


Armor*  Biped::getHead() {
	return this->Head;
}
int  Biped::setHead(Armor* h) {
	if (h->getType() == Helmet && h->getLevel() <= this->getLevel()) {
		this->Head = h;
		return 1;
	}
	return 0;
}
Armor*  Biped::getTorso() {
	return this->Torso;
}
int  Biped::setTorso(Armor* c) {
	if (c->getType() == Chest && c->getLevel() <= this->getLevel()) {
		this->Head = c;
		return 1;
	}
	return 0;
}

Armor*  Biped::getHands() {
	return this->Hands;
}
int  Biped::setHands(Armor* h) {
	if (h->getType() == Gloves && h->getLevel() <= this->getLevel()) {
		this->Head = h;
		return 1;
	}
	return 0;

}
Armor*  Biped::getLegs() {
	return this->Legs;
}
int  Biped::setLegs(Armor* p) {
	if (p->getType() == Pants && p->getLevel() <= this->getLevel()) {
		this->Head = p;
		return 1;
	}
	return 0;
}
Armor*  Biped::getFeet() {
	return this->Feet;
}
int  Biped::setFeet(Armor* b) {
	if (b->getType() == Boots && b->getLevel() <= this->getLevel()) {
		this->Head = b;
		return 1;
	}
	return 0;
}


