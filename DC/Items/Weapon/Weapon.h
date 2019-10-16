#pragma once
#include "../Item/Item.h"
#include "../../DamageTypes/DamageTypes.h"

enum WeaponTypes_enum{NULL_WeaponType,Sword_WeaponType, Shield_WeaponType, Dagger_WeaponType, Axe_WeaponType, Claw_WeaponType};
//None is basically nothing
//sword =med speed, attack, def
//shield = med speed, low attack, high defense
//dagger =high speed, med damage,low defense
//axe = low speed, high damage, med defense
//claws = daggers
class Weapon :public Item {
private:
	WeaponTypes_enum Type;
	
	DoubleLinkedList<DamageTypes> DamageTypes_Weapon;
	int Defense;
	bool TwoHanded;
	int Speed;
	int Level;
	int Range;

	ItemRarity_enum Rarity;
public:
	Weapon();
	Weapon(int Dam, int Def, bool TH, int Sp, int Lvl, int Rng, WeaponTypes_enum type, DoubleLinkedList<DamageTypes> damageTypes);

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

	ItemRarity_enum getRarity();
	void setRarity(ItemRarity_enum rarity);

	WeaponTypes_enum getType();
	void setType(WeaponTypes_enum w);

	void DisplayDetails();

	DoubleLinkedList<DamageTypes> getDamageTypes_Weapon();
	void setDamageTypes_Weapon(DoubleLinkedList<DamageTypes> damagetypes);
	void addDamageType(DamageTypes type);





};