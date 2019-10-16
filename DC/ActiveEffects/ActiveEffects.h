#include <iostream>
#include <string>
//#include <conio.h>
using namespace::std;


enum EffectTypes_enum {NULL_EffectTypes,DamageOverTime_EffectTypes,DeBuff_EffectTypes,Buff_EffectTypes,Combat_EffectTypes};

enum Effects_enum {NULL_Effects,		//NULL
Burning_Effects, Bleeding_Effects, Poison_Effects,    //Damage over Time
Slowed_Effects,Dazed_Effects,Weakness_Effects,BattleFatigue_Effects,		//De-Bebuff
SpeedBoost_Effects,DamageBoost_Effects,DefenseBoost_Effects,	//Buffs
Bezerk_Effects, DefensiveStance_Effects, QuickStrike_Effects,Swordsman_Effects,AnimalFury_Effects}; //Combat effects

//Effects Descriptions---
	//Null: default does nothing
	//-----Damage over time----
		//Burning: adds a Burning effect to creature comes from Fire attack type
		//Bleeding: adds a Bleeding effect to creature comes from stabbing type
		//Poison:  //Not implemented yet
	//--------------
	//-----De-Buff-------
		//slowed: causes speed to be decreased
		//Dazed: causes speed to be decrease  comes from a blunt weapon
		//Weakness: //(not yet implimented) will cause a decrease in strength
		//BattleFatigue: //(not yet implimented) will cause decreased damage
	//-----------
	//-----Buffs----
		//SpeedBoost: increases player speed gotten from speed boost potion
		//DamageBoost: increases player damage gotten from damage boost potion
		//DefenseBoost: increases player defense gotten from Defense boost potion
	//----------
	//------Combat effects--
		//Bezerk: //(not yet implemented) will increase damage but decrease defense gotten from using an axe
		//DefensiveStance: //(not yet implemented) will increase defense but decrease damage  gotten from using a shield
		//QuickStrike: //(not yet implemented) will increase speed but decrease defense gotten from using a dagger
		//Swordsman: //(not yet implemented) will increase defense and damage slightly but decreases damage gotten from using sword
		//AnimalFury://(not yet implemented)will increase speed but decrease defense gotten from using claws
	//
//-----------------



class ActiveEffects {
private:	

	Effects_enum Effect;
	EffectTypes_enum EffectType;
	int RoundsActive;

	int Damage;




public:
	 ActiveEffects();
	// ActiveEffects(Effects_enum e, int rounds);
	// ActiveEffects(Effects_enum e, int rounds,int damage);
	// ActiveEffects(Effects_enum e, int rounds,int damage,bool isdamage);

	ActiveEffects(EffectTypes_enum type,Effects_enum effect,int damage,int rounds);

	
	Effects_enum getEffect();
	
	EffectTypes_enum getEffectType();

	int getRound();
	void setRound(int r);

	// increases effect time by r
	void addRounds(int r);

	//devreases Effect time by x
	bool Decrement(int x = 1);

	//checks if effect time is finnished
	bool isFinished();

	bool DisplayDetails();

	int getDamage();

	void setDamage(int damage);

	string getEffectName();

};