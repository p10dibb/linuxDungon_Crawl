#include "../Biped/Biped.h"



class Zombie : public  Biped {
private:
	

	Weapon* weapon;


public:
	
	Zombie();
	
	Weapon* getWeapon();
	void setWeapon(Weapon* w);

	int Attack();

	int TakeDamage(int attack);


	void DisplayDetails();
	
	int ActualSpeed();


};