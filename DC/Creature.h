#pragma once

#include <array>
#include "activeEffects.h"
#include "DoublelinkedList.h"






class Creature {

private:
	int Damage;
	int Defense;
	int Speed;
	int Stamina;
	int Strength;

	int MaxHealth;
	int Health;
	int Level;
	int XP;
	string Name;

	

	//x,y position
	array<int, 2> position; 
	DoubleLinkedList<ActiveEffects> Effects;

public:



	Creature();

	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	int ContainEffect(EffectType e);

	//decrement the effect at the said position and removes effect if 0;
	bool DecrementEffectTime(int pos);

	//checks if effect is in list and if it is then increase time else add new effect.
	bool AddEffect(EffectType e, int time);

	//decrements all effect times by 1;
	void DecrementAllEffects();

	void DisplayAllEffects();

	//itterates through active effects and applies damage from damage effects
	bool runDamageEffects();

	int getDamage();
	void setDamage(int i);
	int getDefense();
	void setDefense(int d);
	int getSpeed();
	void setSpeed(int s);
	int getStamina();
	void setStamina(int s);
	int getStrength();
	void setStrength(int s);

	int getMaxHealth();
	void setMaxHealth(int m);
	int getHealth();
	void setHealth(int h);
	int getLevel();
	void setLevel(int l);
	int getXP();
	void setXP(int x);
	string getName();
	void setName(string n);
	void Display();

	array<int, 2> getPosition();
	bool setPosition(array<int,2> pos);

	int move(char map[][10], int direction);







};


