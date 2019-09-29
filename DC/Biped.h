#include "Creature.h"
#include "Armor.h"
#include "Weapon.h"


//Base Class for all humanoid creatures like Player,Zombie,...
class Biped : public Creature {

private:


	Armor* Head;
	Armor* Torso;
	Armor* Hands;
	Armor* Legs;
	Armor* Feet;



public:

	Biped();


	Armor* getHead();
	int setHead(Armor* h);
	Armor* getTorso();
	int setTorso(Armor* t);
	Armor* getHands();
	int setHands(Armor* h);
	Armor* getLegs();
	int setLegs(Armor* l);
	Armor* getFeet();
	int setFeet(Armor* f);




	int Attack();

	int TakeDamage(int attack);







};
