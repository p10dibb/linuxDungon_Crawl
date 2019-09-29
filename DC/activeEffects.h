#include <iostream>
#include <string>
//#include <conio.h>
using namespace::std;


enum EffectType {Blank,Burning, Bleeding,Slowed,Swiftness,Dazed};



class ActiveEffects {
private:	

	EffectType effect;
	int roundsActive;

	//damage delt by effect; Burning 3, bleeding 3
	int damage;



public:
	ActiveEffects();
	ActiveEffects(EffectType e, int r);

	EffectType getEffect();
	void setEffect(EffectType e);

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