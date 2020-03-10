#pragma once
#include "../Biped/Biped.h"



class Enemy : public  Biped {
private:
	

	Weapon* weapon;

	//the direction that the zombie is moving
	Direction_enum direction;

	//the distance that the zombie moves
	int moveAmt;

	Enemy_enum type;


public:
	
	Enemy();
	
	Weapon* getWeapon();
	void setWeapon(Weapon* w);

	//gets all the attack types as Damage types
	vector<DamageTypes> getAllDamageTypes();
	
	vector<ActiveEffects> getAllResistanceTypes();

	//int TakeDamage(int attack);
	int TakeDamage(vector<DamageTypes> damageTypes);

	Direction_enum getDirection();

	int getMoveAmt();

	void DisplayDetails();
	
	int ActualSpeed();

	void move(array<array<RoomPieces_enum, 50>,50> map);

	Enemy_enum getType();
	bool setType(Enemy_enum type);


};
//inputs a damage amount , damage type, and resistances and reduces damage to the proper damage
int ReduceDamage(int damage,DamageTypes_enum damageTypes,vector<ActiveEffects> resistances);

// bool operator== (Zombie lhs, Zombie rhs);



//Enemy_enum Descriptions
	//Rodent:
	//Zombie:
	//Human:
	//Boss: