#pragma once
#include "../Enumerations.h"

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
//Bezerk: // will increase damage but decrease defense gotten from using an axe
//DefensiveStance: // will increase defense but decrease Speed  gotten from using a shield
//QuickStrike: // will increase speed but decrease defense gotten from using a dagger
//Swordsman: // will increase defense and damage slightly but decreases speed gotten from using sword
//AnimalFury://will increase speed but decrease defense gotten from using claws
//
//-----Damage Resistance
//Normal:  reduces the amount of normal damage that is taken
//Fire:	reduces the amount of fire damage that is taken
//Stabbing: reduces the amount of stabbing damage that is taken
//Blunt:	reduces the amount of Blunt damage that is taken
//Poison:	reduces the amount of poison damage that is taken
//-----------------

class ActiveEffects
{
private:
	Effects_enum Effect;
	EffectTypes_enum EffectType;
	int RoundsActive;

	//Damagefor damage types, multiplier for buffs, percent resistance for damageresister
	int Modifier;

public:
	ActiveEffects();

	ActiveEffects(EffectTypes_enum type, Effects_enum effect, int modifier, int rounds);

	Effects_enum getEffect();

	EffectTypes_enum getEffectType();

	int getRound();
	void setRound(int r);

	// increases effect time by r
	bool addRounds(int r);

	//devreases Effect time by x
	bool Decrement(int x = 1);

	//checks if effect time is finnished
	bool isFinished();

	bool DisplayDetails();

	//------get/set resistance,Damage, multiplier,and modifier all change Modifier

	void setResistance(int Resist);
	int getResistance();

	void setMultiplier(int multiplier);
	int getMultiplier();

	void setModifier(int modifier);
	int getModifier();

	void setDamage(int damage);
	int getDamage();

	string getEffectName();
};

//uses SFML to get a string and display it on a window
string getStringSFML(sf::RenderWindow *window,sf::Text text, string input_text);
// /sf::RenderWindow window, sf::Text text, string input_text