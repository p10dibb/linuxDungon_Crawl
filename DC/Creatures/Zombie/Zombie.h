#pragma once
#include "../Biped/Biped.h"



class Zombie : public  Biped {
private:
	

	Weapon* weapon;

	//the direction that the zombie is moving
	Direction_enum direction;

	//the distance that the zombie moves
	int moveAmt;


public:
	
	Zombie();
	
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


};
//inputs a damage amount , damage type, and resistances and reduces damage to the proper damage
int ReduceDamage(int damage,DamageTypes_enum damageTypes,vector<ActiveEffects> resistances);