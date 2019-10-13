#include "Zombie.h"



Zombie::Zombie() {
	Biped();
	this->direction=0;
	this->moveAmt=0;

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


	if (this->ContainEffect(Slowed_EffectType)) {
		speed = speed * .75;
	}
	if (this->ContainEffect(Dazed_EffectType)) {
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
	
	int location=-1;
	if (location=this->ContainEffect(DamageBoost_EffectType)==-1){
		return ret;
	}else// if there is a damage booster;
	{
		//gets the multiplier
		int DamageMultiplier=this->getEffect(location).getDamage();
		//new Linkedlist
		DoubleLinkedList<DamageTypes> ret2;
		DamageTypes cur;
		for (int i=0;i<ret.Size();i++){
			cur=ret.getData(i);
			ret2.add(DamageTypes(cur.getType(),cur.getProbability(),cur.getDamage()*DamageMultiplier));
			
		}
		return ret2;
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
					this->AddEffect(Burning_EffectType,5);
				}
				else if (current.getType()==Blunt_DamageType){
					cout<<"Dazed"<<endl;
					this->AddEffect(Dazed_EffectType,5);
				}
				else if (current.getType()==Stabbing_DamageType){
					cout<<"Bleeding"<<endl;
					this->AddEffect(Bleeding_EffectType,5);
				}else if (current.getType()==Critical_DamageType){
					cout<<"Critical hit"<<endl;
				}

				totalDamage+=current.getDamage();

			}
		}

		int taken = 0;
		int location=1;
	
		

		if(location=ContainEffect(DefenseBoost_EffectType)==-1){
			taken=taken=totalDamage - this->getDefense();
		}else{
			 
			taken=totalDamage - this->getDefense()*this->getEffect(location).getDamage();
		}
		if (taken < 1) {
			taken = 1;
		}
		this->setHealth(this->getHealth() - taken);

		return taken;
}

void Zombie::move(char  map[][10]){

	//if not moving in a set direction then pick new direction and distance
	if (moveAmt==0){
		moveAmt=rand()%5+1;
		direction=rand()%5;
	}

	//move left
	if(direction==0){
		//check for wall
		if (map[this->getPosition()[0]][this->getPosition()[1]-1]!='|' &&map[this->getPosition()[0]][this->getPosition()[1]-1]!='E'){
			this->setPosition({this->getPosition()[0],this->getPosition()[1]-1});
		}
	}// move right
	else if(direction==2){
		//check for wall
		if (map[this->getPosition()[0]][this->getPosition()[1]+1]!='|' &&map[this->getPosition()[0]][this->getPosition()[1]+1]!='E'){
			this->setPosition({this->getPosition()[0],this->getPosition()[1]+1});
		}
	}
	//move up
	else if(direction==1){
		//check for wall
		if (map[this->getPosition()[0]-1][this->getPosition()[1]]!='-' &&map[this->getPosition()[0]-1][this->getPosition()[1]]!='E'){
			this->setPosition({this->getPosition()[0]-1,this->getPosition()[1]});
		}
	}// move down
	else if(direction==3){
		//check for wall
		if (map[this->getPosition()[0]+1][this->getPosition()[1]]!='-' &&map[this->getPosition()[0]+1][this->getPosition()[1]]!='E'){
			this->setPosition({this->getPosition()[0]+1,this->getPosition()[1]});
		}
	} 

	
	this->moveAmt--;



}