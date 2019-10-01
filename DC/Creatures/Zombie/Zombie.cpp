#include "Zombie.h"



Zombie::Zombie() {
	Biped();
	
	this->weapon = new Weapon();

}



Weapon* Zombie::getWeapon() {
	return this->weapon;
}
void Zombie::setWeapon(Weapon* w) {
	this->weapon = w;
}




int Zombie::TakeDamage(int attack) {
	int health = this->getHealth();
	int damageTaken = 0;
	if ((attack - (this->getDefense()+this->weapon->getDefense())) < 0) {
		health = health - 1;
		damageTaken = 1;
	}
	else {
		damageTaken = attack - (this->getDefense() + this->weapon->getDefense());
		health = health - damageTaken;
	}
	if (health < 0) {
		health = 0;
	}
	this->setHealth(health);
	return damageTaken;	
}


void Zombie:: DisplayDetails() {
	Display();
	cout << "Damage: " << this->getDamage() << endl;
	cout << "Speed: " << this->getSpeed() << endl;
	cout << "Defense: " << this->getDefense() << endl;
	cout << "Stamina: " << this->getStamina() << endl;
	cout << "Weapon: " << endl;
	this->weapon->DisplayDetails();
}	

int Zombie::ActualSpeed() {
	int speed = 0;
	int ArmorWeight = this->getHead()->getWeight() + this->getTorso()->getWeight() + this->getHands()->getWeight() + this->getLegs()->getWeight() + this->getFeet()->getWeight();

	
		speed = this->getSpeed() + this->weapon->getSpeed() - (ArmorWeight / (this->getStrength() / 2));


	if (this->ContainEffect(Slowed)) {
		speed = speed * .75;
	}
	if (this->ContainEffect(Dazed)) {
		speed = speed * .75;
	}

	return speed;

}

DoubleLinkedList<DamageTypes> Zombie::getAllDamageTypes(){
 DoubleLinkedList<DamageTypes> ret;
	ret.add(DamageTypes(this->getDamage()));
	int i=0;
	for(i=0;i<this->getWeapon()->getDamageTypes_Weapon().Size();i++){
		ret.add(this->getWeapon()->getDamageTypes_Weapon().getData(i));
	}
	
	return ret;
}

int Zombie::TakeDamage(DoubleLinkedList<DamageTypes> damageTypes){
int totalDamage=0;
		DamageTypes current;

	

		//itterates through all damage types
		for(int i=0;i<damageTypes.Size();i++){
			current=damageTypes.getData(i);
			if(rand()%100<=current.getProbability()){
				//checks if Effect needs to be added
				if (current.getType()==Fire_DamageType){
					cout<<"Burning"<<endl;
					this->AddEffect(Burning,5);
				}
				else if (current.getType()==Blunt_DamageType){
					cout<<"Dazed"<<endl;
					this->AddEffect(Dazed,5);
				}
				else if (current.getType()==Stabbing_DamageType){
					cout<<"Bleeding"<<endl;
					this->AddEffect(Bleeding,5);
				}

				totalDamage+=current.getDamage();

			}
		}

		int taken = totalDamage - this->getDefense();
		if (taken < 1) {
			taken = 1;
		}
		this->setHealth(this->getHealth() - taken);

		return taken;
}