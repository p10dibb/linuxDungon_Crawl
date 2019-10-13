#include <iostream>
#include <string>
//#include <conio.h>
using namespace::std;


enum EffectType_enum {NULL_EffectType,Burning_EffectType, Bleeding_EffectType,Slowed_EffectType,
SpeedBoost_EffectType,Dazed_EffectType,DamageBoost_EffectType,DefenseBoost_EffectType};



class ActiveEffects {
private:	

	EffectType_enum effect;
	int roundsActive;

	//damage delt by effect; Burning 3, bleeding 3
	int damage;

	bool isDamage;



public:
	ActiveEffects();
	ActiveEffects(EffectType_enum e, int rounds);
	ActiveEffects(EffectType_enum e, int rounds,int damage);
	ActiveEffects(EffectType_enum e, int rounds,int damage,bool isdamage);

	bool getIsDamage();
	void setIsDamage(bool damaging);

	EffectType_enum getEffect();
	void setEffect(EffectType_enum e);
	
	void setEffect(EffectType_enum e, int damage);

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

	string getEffectName();

};