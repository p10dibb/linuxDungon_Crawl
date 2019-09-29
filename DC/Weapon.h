#pragma once
#include "Item.h"

enum WeaponTypes{None,Sword, Shield, Dagger, Axe, Claw};
//None is basically nothing
//sword =med speed, attack, def
//shield = med speed, low attack, high defense
//dagger =high speed, med damage,low defense
//axe = low speed, high damage, med defense
//claws = daggers
class Weapon :public Item {
private:
	WeaponTypes Type;
	int Damage;
	int Defense;
	bool TwoHanded;
	int Speed;
	int Level;
	int Range;
public:
	Weapon();
	Weapon(int Dam, int Def, bool TH, int Sp, int Lvl, int Rng, WeaponTypes type);
	int getDamage();
	void setDamage(int d);
	int getDefense();
	void setDefense(int d);
	bool getTwoHanded();
	void setTwoHanded(bool t);
	int getSpeed();
	void setSpeed(int s);
	int getLevel();
	void setLevel(int l);
	int getRange();
	void setRange(int r);

	WeaponTypes getType();
	void setType(WeaponTypes w);

	void DisplayDetails();

};