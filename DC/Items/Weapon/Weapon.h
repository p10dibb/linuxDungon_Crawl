#pragma once
#include "../Item/Item.h"
#include "../../DamageTypes/DamageTypes.h"


//None is basically nothing
//sword =med speed, attack, def
//shield = med speed, low attack, high defense
//dagger =high speed, med damage,low defense
//axe = low speed, high damage, med defense
//claws = daggers
class Weapon :public Item {
private:
	WeaponTypes_enum Type;
	
	map<DamageTypes_enum,DamageTypes> DamageTypes_Weapon;
	
	ActiveEffects Defense;
	bool TwoHanded;
	int Speed;
	int Level;
	int Range;
	ItemRarity_enum Rarity;
	ActiveEffects CombatEffect;

	
	//sum of all(damage*probability)*speed
	int WeaponRank;

public:
	Weapon();
	Weapon(int Def, bool TH, int Sp, int Lvl, int Rng, WeaponTypes_enum type, map<DamageTypes_enum,DamageTypes> damageTypes);

	ActiveEffects getDefense();
	void setDefense(int d);
	bool getTwoHanded();
	void setTwoHanded(bool t);
	int getSpeed();
	void setSpeed(int s);
	int getLevel();
	void setLevel(int l);
	int getRange();
	void setRange(int r);
	void setRarity(ItemRarity_enum rarity);
	ItemRarity_enum getRarity();

	WeaponTypes_enum getType();
	void setType(WeaponTypes_enum w);

	void DisplayDetails();

	vector<DamageTypes> getDamageTypes_Weapon();
	map<DamageTypes_enum,DamageTypes> getDamageTypes_Weapon_Map();
	void setDamageTypes_Weapon(map<DamageTypes_enum,DamageTypes> damagetypes);
	void addDamageType(DamageTypes type);

	//return the text equivilent of rarity
	string getRarity_text();

	ActiveEffects getCombatEffect();

	//used to see how "good" weapon is 
	int getWeaponRank();
	//calculates the DamageRank
	int calculateWeaponRank();
};