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


DoubleLinkedList<ActiveEffects> Zombie::getAllResistanceTypes(){
	DoubleLinkedList<ActiveEffects> ret=this->getResistanceEffects();
	
	//takes current damage stat and converts to an active effect
	ret.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,this->getDefense(),10));
	
	ret.add(this->weapon->getDefense());
	return ret;
}

//recieves a linked list of damage types and and runs through the damage taken
int Zombie::TakeDamage(DoubleLinkedList<DamageTypes> damageTypes){
		DamageTypes current;
		int location=1,totalDamage=0;;

		DoubleLinkedList<ActiveEffects> resistances =this->getAllResistanceTypes();
		//itterates through all damage types
		for(int i=0;i<damageTypes.Size();i++){
			current=damageTypes.getData(i);

			//checks to see if damage type happens
			if(rand()%100<=current.getProbability()){
				//checks if Effect needs to be added
				switch (current.getType())
				{
					case Fire_DamageType:cout<<"Burning"<<endl;	this->AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,current.getDamageOverTime_damage(),current.getDamageOverTime_time()));	break;
					case Blunt_DamageType:cout<<"Dazed"<<endl;this->AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Dazed_Effects,current.getDamageOverTime_damage(),current.getDamageOverTime_time()));break;
					case Stabbing_DamageType:cout<<"Bleeding"<<endl;this->AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Bleeding_Effects,current.getDamageOverTime_damage(),current.getDamageOverTime_time()));break;
					case Critical_DamageType:cout<<"Critical hit"<<endl;break;
					default:break;
				}
				totalDamage+= ReduceDamage(current.getDamage(),current.getType(),resistances) ;
			}
		}			

		// checks if there is a defense boost and suptracks total armor from damage
		if(location=ContainBuffEffect(DefenseBoost_Effects)!=-1){
			totalDamage=totalDamage /this->getBuffEffect(location).getMultiplier();
		}
	
		if (totalDamage< 1) {
			totalDamage = 1;
		}
		this->setHealth(this->getHealth() - totalDamage);
		return totalDamage;

}


void Zombie:: DisplayDetails() {
	Display();
	cout << "Damage: " << this->getDamage() << endl;
	cout << "Speed: " << this->getSpeed() << endl;
	//cout << "Defense: " << this->getDefense() << endl;
	cout << "Stamina: " << this->getStamina() << endl;
	cout << "Weapon: " << endl;
	this->weapon->DisplayDetails();
}	

int Zombie::ActualSpeed() {
	int speed = 0;
	int ArmorWeight = this->getHead()->getWeight() + this->getTorso()->getWeight() + this->getHands()->getWeight() + this->getLegs()->getWeight() + this->getFeet()->getWeight();

	
		speed = this->getSpeed() + this->weapon->getSpeed() - (ArmorWeight / (this->getStrength() / 2));


	if (this->ContainDeBuffEffect(Slowed_Effects)) {
		speed = speed * .75;
	}
	if (this->ContainDeBuffEffect(Dazed_Effects)) {
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
	if (location=this->ContainBuffEffect(DamageBoost_Effects)==-1){
		return ret;
	}else// if there is a damage booster;
	{
		//gets the multiplier
		int DamageMultiplier=this->getBuffEffect(location).getMultiplier();
		//new Linkedlist
		DoubleLinkedList<DamageTypes> ret2;
		DamageTypes cur;
		for (int i=0;i<ret.Size();i++){
			cur=ret.getData(i);
			ret2.add(DamageTypes(cur.getDamage()*DamageMultiplier,cur.getProbability(),cur.getType(),cur.getIsDamageOverTime(),cur.getDamageOverTime_damage(),cur.getDamageOverTime_time()));
			
		}
		return ret2;
	}

	return ret;
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