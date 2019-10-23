#pragma once

#include <array>
#include "../../ActiveEffects/ActiveEffects.h"
#include "../../DataStructures/DoubleLinkedList.h"






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
	//DoubleLinkedList<ActiveEffects> Effects;

	DoubleLinkedList<ActiveEffects> DeBuffEffects;
	DoubleLinkedList<ActiveEffects> BuffEffects;
	DoubleLinkedList<ActiveEffects> CombatEffects;
	DoubleLinkedList<ActiveEffects> DamageOverTimeEffects;
	DoubleLinkedList<ActiveEffects> ResistanceEffects;

public:



	Creature();

	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	int ContainDamageOverTimeEffect(Effects_enum effect);
	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	int ContainCombatEffect(Effects_enum effect);
	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	int ContainBuffEffect(Effects_enum effect);
	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	int ContainDeBuffEffect(Effects_enum effect);
	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	int ContainResistanceEffect(Effects_enum effect);
	
	

	//decrement the effect at the said position and removes effect if 0;
	bool DecrementEffectTime(int pos);

	
	//checks if effect is in list and if it is then increase time else add new effect.
	bool AddEffect(ActiveEffects effect);
		//checks if effect is in list and if it is then increase time else add new effect.
	bool AddDamageOverTimeEffect(ActiveEffects effect);
		//checks if effect is in list and if it is then increase time else add new effect.
	bool AddCombatEffect(ActiveEffects effect);
		//checks if effect is in list and if it is then increase time else add new effect.
	bool AddBuffEffect(ActiveEffects effect);
		//checks if effect is in list and if it is then increase time else add new effect.
	bool AddDeBuffEffect(ActiveEffects effect);
		//checks if effect is in list and if it is then increase time else add new effect.
	bool AddResistanceEffect(ActiveEffects effect);




	//decrements all effect times by 1;
	void DecrementAllEffects();
	//decrements all effect times by 1;
	void DecrementAllDeBuffEffects();
	//decrements all effect times by 1;
	void DecrementAllBuffEffects();
	//decrements all effect times by 1;
	void DecrementAllCombatEffects();
	//decrements all effect times by 1;
	void DecrementAllDamageOverTimeEffects();
	//decrements all effect times by 1;
	void DecrementAllResistanceEffects();


	//Displays Effects
	void DisplayAllDeBuffEffects();
	//Displays Effects
	void DisplayAllBuffEffects();
	//Displays Effects
	void DisplayAllCombatEffects();
	//Displays Effects
	void DisplayAllDamageOverTimeEffects();
	//Displays Effects
	void DisplayAllResistanceEffects();
	//Displays Effects
	void DisplayAllEffects();

	//removes all effects
	bool ClearAllDeBuffEffects();
	//removes all effects
	bool ClearAllBuffEffects();
	//removes all effects
	bool ClearAllCombatEffects();
	//removes all effects
	bool ClearAllResistanceEffects();
	//removes all effects
	bool ClearAllDamageOverTimeEffects();
	//removes all effects
	bool ClearAllEffects();

	//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
	ActiveEffects getDeBuffEffect(int pos);
	//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
	ActiveEffects getBuffEffect(int pos);
	//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
	ActiveEffects getCombatEffect(int pos);
	//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
	ActiveEffects getDamageOverTimeEffect(int pos);
	//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
	ActiveEffects getResistanceEffect(int pos);

	//the Double linked list Resistance Effects
	DoubleLinkedList<ActiveEffects> getResistanceEffects();




	//itterates through active effects and applies damage from damage effects
	int runDamageOverTimeEffects();

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
