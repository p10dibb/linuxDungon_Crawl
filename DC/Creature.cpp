//#pragma once

#include "Creature.h"

Creature::Creature() {
	//sets x=1
	this->position[0] = 1;
	//sets y=1
	this->position[1] = 1;

	this->Damage = 0;
	this->Speed = 0;
	this->Defense = 0;
	this->Stamina = 0;

	this->MaxHealth = 100;
	this->Health = 100;
	this->Level = 1;
	this->XP = 0;
	this->Name;


}
int Creature::getMaxHealth() {
	return this->MaxHealth;
}
void Creature::setMaxHealth(int m) {
	if (m < 1) {
		m = 0;
	}
	this->MaxHealth = m;
}


int Creature::getHealth() {
	return this->Health;
}
void Creature::setHealth(int h) {
	if (h < 0) {
		h = 0;
	}
	this->Health = h;
}

int Creature::getLevel() {
	return this->Level;
}

void Creature::setLevel(int l) {
	if (l < 1) {
		l = 1;
	}
	this->Level = l;
}


int Creature::getXP() {
	return this->XP;
}
void Creature::setXP(int x) {
	this->XP = x;
}
string Creature::getName() {
	return this->Name;
}
void  Creature::setName(string n) {
	this->Name = n;
}

void Creature::Display() {
	cout << "Name: \t" << this->Name << endl << "Level: \t" << Level << endl << "XP: \t" << this->XP << endl << "Health: \t" << this->Health << endl << "MaxHealth: \t" << this->MaxHealth << endl;

}


int Creature::getDamage() {
	return this->Damage;
}
void Creature::setDamage(int i) {
	if (i < 1) {
		i = 1;
	}
	this->Damage = i;
}
int Creature::getSpeed() {
	return this->Speed;
}
void  Creature::setSpeed(int s) {
	if (s < 1) {
		s = 1;
	}
	this->Speed = s;
}
int  Creature::getStamina() {
	return this->Stamina;
}
void  Creature::setStamina(int s) {

	if (s < 1) {
		s = 1;
	}
	this->Stamina = s;
}

int  Creature::getDefense() {
	return this->Defense;
}
void  Creature::setDefense(int d) {
	if (d < 0) {
		this->Defense = d;
	}
}


int  Creature::getStrength() {
	return this->Strength;
}
void  Creature::setStrength(int s) {
	this->Strength = s;
}



array<int, 2> Creature::getPosition() {
	return this->position;
}
bool Creature::setPosition(array<int, 2> pos) {
	this->position = pos;
	return true;
}
//0=left,1=up,2=right, 3=down
int Creature::move(char  map[][10],int direction) {
	
	return 0;

}


//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
int Creature::ContainEffect(EffectType e) {
	for (int i = 0; i < this->Effects.Size(); i++) {
		if (this->Effects.getNode(i)->getData().getEffect()== e) {
			return i;
		}
	}
	return -1;
}

//decrement the effect at the said position and removes effect if 0;
bool Creature::DecrementEffectTime(int pos) {
	return this->Effects.getNode(pos)->Data.Decrement();
	
}

//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddEffect(EffectType e, int time) {
	int pos = this->ContainEffect(e);
	if (pos!=-1) {
		this->Effects.getNode(pos)->Data.addRounds(time);
	}
	else {
		this->Effects.add(ActiveEffects(e, time));
	}
	
	return true;
}

//decrements all effect times by 1;
void Creature::DecrementAllEffects() {
	for (int i = 0; i < this->Effects.Size(); i++) {
		this->Effects.getNode(i)->Data.Decrement();
	}
}


void Creature::DisplayAllEffects() {
	for (int i = 0; i < this->Effects.Size(); i++) {
		 this->Effects.getData(i).DisplayDetails();
	}
}

//itterates through active effects and applies damage from damage effects returns -1 if dead
bool Creature::runDamageEffects() {
	int damage = 0;
	for (int i = 0; i < this->Effects.Size(); i++) {
		damage = this->Effects.getNode(i)->Data.getDamage();
		if ( damage> 0) {
			this->setHealth(this->getHealth() - damage);
			cout << this->getName() << " Took " << damage << " damage from " << this->Effects.getNode(i)->Data.getEffectName() << endl;
			if (this->getHealth() <= 0) {
				cout << this->getName() << " has died from " << this->Effects.getNode(i)->Data.getEffectName()<<endl;
				return -1;
			}
		}
	}
	return 0;
}