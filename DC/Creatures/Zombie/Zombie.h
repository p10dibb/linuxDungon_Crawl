#pragma once
#include "../Biped/Biped.h"



class Zombie : public  Biped {
private:
	

	Weapon* weapon;

	//the current movement direction 0:left 1:up 2:right 3:down 4:stationary
	int direction;
	int moveAmt;


public:
	
	Zombie();
	
	Weapon* getWeapon();
	void setWeapon(Weapon* w);

	DoubleLinkedList<DamageTypes> getAllDamageTypes();

	int TakeDamage(int attack);
	int TakeDamage(DoubleLinkedList<DamageTypes> damageTypes);


	void DisplayDetails();
	
	int ActualSpeed();

	void move(char  map[][10]);


};