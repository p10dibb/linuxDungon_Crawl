#pragma once
#include "../Biped/Biped.h"



class Zombie : public  Biped {
private:
	

	Weapon* weapon;


public:
	
	Zombie();
	
	Weapon* getWeapon();
	void setWeapon(Weapon* w);

	DoubleLinkedList<DamageTypes> getAllDamageTypes();

	int TakeDamage(int attack);
	int TakeDamage(DoubleLinkedList<DamageTypes> damageTypes);


	void DisplayDetails();
	
	int ActualSpeed();


};