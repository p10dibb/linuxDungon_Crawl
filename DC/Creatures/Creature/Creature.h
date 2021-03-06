#pragma once

#include <array>
#include "../../ActiveEffects/ActiveEffects.h"
#include <vector>
#include <map>

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
		

		array<int, 2> position; 
		std::map<Effects_enum,ActiveEffects>  DeBuffEffects;
		std::map<Effects_enum,ActiveEffects>  BuffEffects;		
		std::map<Effects_enum,ActiveEffects>  CombatEffects;
		std::map<Effects_enum,ActiveEffects> DamageOverTimeEffects;
		std::map<Effects_enum,ActiveEffects>  ResistanceEffects;


	public:
	
	Creature();

	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	bool ContainDamageOverTimeEffect(Effects_enum effect);
	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	bool ContainCombatEffect(Effects_enum effect);
	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	bool ContainBuffEffect(Effects_enum effect);
	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	bool ContainDeBuffEffect(Effects_enum effect);
	//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
	bool ContainResistanceEffect(Effects_enum effect);
	
	

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
	ActiveEffects getDeBuffEffect(Effects_enum effect);
	//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
	ActiveEffects getBuffEffect(Effects_enum effect);
	//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
	ActiveEffects getCombatEffect(Effects_enum effect);
	//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
	ActiveEffects getDamageOverTimeEffect(Effects_enum effect);
	//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
	ActiveEffects getResistanceEffect(Effects_enum effect);


	//the Double linked list Resistance Effects
	map<Effects_enum,ActiveEffects> getResistanceEffects();
	//the Double linked list DeBuff Effects
	map<Effects_enum,ActiveEffects> getDeBuffEffects();
	//the Double linked list Buff Effects
	map<Effects_enum,ActiveEffects> getBuffEffects();
	//the Double linked list Combat Effects
	map<Effects_enum,ActiveEffects> getCombatEffects();
	//the Double linked list DamageOverTime Effects
	map<Effects_enum,ActiveEffects> getDamageOverTimeEffects();

	




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
