#include "Player.h"
#include <cstdio>

string toLower(string s) {
	string ret = "";
	for (int i = 0; i < s.length();i++) {
		ret = ret + char(tolower(s[i]));
	
	}
	return ret;
}

//Default constructor
Player::Player() {
	Biped();
	
	this->setDamage(1) ;
	this->setSpeed(1);
	this->setDefense(1);
	this->setStamina(1);
	this->setStrength(1);

	

	this->Right = new Weapon();
	this->Right->setName("Fist");
	this->Left = new Weapon();
	this->Left->setName("Fist");

	this->FreeSlots = 40;

	this->InventorySize = 40;

	
	this->LevelUp = 10;

	this->MaxWeight = 50;
	this->CurrentWeight = 0;
	this->OverWeighted = false;

	this->LevelUp = 10;
	this->Inventory;	
	
	for (int i = 0; i < this->InventorySize; i++) {
		this->Inventory[i].item = new Item();
	}
}


//Displays all data for character
void Player::DisplayDetails() {
	cout << "Name: \t" << this->getName() << endl;
	cout << "Level: \t" << this->getLevel() << endl;
	cout << "XP: \t" << this->getXP() << endl;
	cout << "Health: \t" << this->getHealth() << endl;
	cout << "Stamina: \t" << this->getStamina() << endl;
	cout << "Attack: \t" << this->getDamage() << endl;
	cout << "Defense: \t" << this->getDefense() << endl;
	cout << "Speed: \t" << this->getSpeed() << endl;
	cout << "Armor: \t" << endl;
	cout << "Head: \t" << this->getHead()->getName() << endl;
	cout << "Torso: \t" << this->getTorso()->getName() << endl;
	cout << "Hands: \t" << this->getHands()->getName() << endl;
	cout << "Legs: \t" << this->getLegs()->getName() << endl;
	cout << "Feet: \t" << this->getFeet()->getName() << endl;
	cout << "Weapon: " << endl;
	cout << "Right: \t" << this->getRight()->getName() << endl;
	cout << "Left: \t" << this->getLeft()->getName() << endl;
}


//calculates the players actual speed
int Player::ActualSpeed() {
	cout<<"player speed check"<<endl;
	int speed = 0;
	int ArmorWeight = this->getHead()->getWeight() + this->getTorso()->getWeight() + this->getHands()->getWeight() + this->getLegs()->getWeight() + this->getFeet()->getWeight();
	cout<<"player speed check"<<endl;
	//if onehanded else dual wielding
	if (this->Left->getType() == NULL_WeaponType) {
		
		speed = this->getSpeed() + this->Right->getSpeed() - (ArmorWeight / (1+(this->getStrength() / 2)));
	}
	else if(this->Right->getType() == NULL_WeaponType) {
	
		speed = this->getSpeed() + this->Left->getSpeed() - (ArmorWeight / (this->getStrength() / 2));
	}
	else {
		//two weapons being used 2/3 the speed of both weapons added together so dual wielding is slower but has higher attack and defense
		cout<<"Two handed"<<endl;
		speed = this->getSpeed() +( (this->Left->getSpeed()+this->Right->getSpeed())/3 )- (ArmorWeight / (this->getStrength() / 2));
	}
	cout<<"player speed check"<<endl;

	//if slwed effect is active then decrease speed by 25%
	if (this->ContainEffect(Slowed)) {
		speed = speed * .75;
	}
	if (this->ContainEffect(Dazed)) {
		speed = speed * .75;
	}
	//cuts speed in half if overweighted
	if (this->OverWeighted) {
		speed = speed * .5;
	}
	//minimum speed is 1
	if (speed < 1) {
		speed = 1;
	}
	cout<<"player speed check"<<endl;
	return speed;

}
//calculates players Actual attack

//calculates Players actual Defense
int Player::ActualDefense() {
	//total of all defensive items
	return this->getDefense() + this->getHead()->getDefense() + this->getTorso()->getDefense() + this->getHands()->getDefense() + this->getLegs()->getDefense() + this->getFeet()->getDefense() + this->Right->getDefense() + this->Left->getDefense();

}




//player recieves lootdrop from enemy
void Player::RecieveLootDrop(lootDrop loot) {

	cout << "You recieved: " << endl << "XP: " << loot.xp << endl;
	this->setXP(this->getXP() + loot.xp);

	if (loot.gold != 0) {
		cout << "Gold: " << loot.gold << endl;
		this->Money += loot.gold;
	}


	if (loot.weapon != NULL) {
		cout << "Weapon: " << loot.weapon->getName()<<endl;
		this->addToInventory(loot.weapon);
	}

	if (loot.armour != NULL) {
		cout << "Armor: " << loot.armour->getName();
		this->addToInventory(loot.armour);
	}

	if (loot.potion != NULL) {
		cout << "Potion: " << loot.potion->getName();
		this->addToInventory(loot.potion);
	}

	if (this->getXP() >= this->getLevelUp()) {
		this->NextLevel();
	}
	//system("pause");

}

void Player::addSkillPoint(){
		int input;
		while(1){
		cout << "#\tstat\tcurrent level\tDescription" << endl;
		cout << "1\tMaxHealth\t" << this->getMaxHealth() <<"\tMaximum Health of the player"<< endl;
		cout << "2\tStrength\t" << this->getStrength() <<"\tIncreases Carrying capacity and lessens handicap of speed for heavy armour"<< endl;
		cout << "3\tSpeed\t" << this->getSpeed() << "\tIncreases speed in combat"<<endl;
		cout << "4\tBase Attack\t" << this->getDamage() <<"\tIncreases Base Damage"<< endl;
		cout << "5\tBase Defense\t" << this->getDefense() <<"\tIncreases Base Defense"<< endl;
		cout << "6\tStamina\t" << this->getStamina() << "\tCurrently Does nothing"<<endl;
		cout << "Choice: ";
		cin >> input;
		if (input == 1) {

			this->setMaxHealth(this->getMaxHealth() + 10);
			this->setHealth(this->getMaxHealth());
			break;

		}
		else if (input == 2) {
			this->setStrength(this->getStrength()+1);
			this->MaxWeight = this->getStrength() * 10;
			
			this->setOverWeighted(this->MaxWeight < this->CurrentWeight);		
			break;	
		}
		else if (input == 3) {
			this->setSpeed(this->getSpeed() + 1);
			break;
		}
		else if (input == 4) {
			this->setDamage(this->getDamage()+1);
			break;
		}
		else if (input == 5) {
			this->setDefense(this->getDefense()+1);
			break;
		}
		else {
			cout << "Not a valid choice:" << endl;
			
			
		}
		}
}

//level up dialogue for player
void Player::NextLevel() {
	//get 3 upgrade points when you level up
	int points = 3;
	int input = 0;
	this->setLevel(this->getLevel() + 1);
	this->setMaxHealth(this->getMaxHealth() + 10);
	this->setHealth(this->getMaxHealth());
	cout << "Congrats you leveled up!! \nMax Health is now: " << this->getMaxHealth() << endl;

	while (points != 0)
	{
		
	cout << "you have " << points << " remaining what would you like to upgrade?" << endl;	
		this->addSkillPoint();


		points--;

	}

	this->setLevelUp(this->getLevelUp() * 2);
}

//0=left,1=up,2=right, 3=down
int Player::move(char  map[][10], int direction) {

	   	 							
	if (direction == 0&& map[this->getPosition()[0]][this->getPosition()[1]-1]!= '|') {
		
		
		this->setPosition({ this->getPosition()[0],this->getPosition()[1] - 1 });
	}
	else if (direction == 2&& map[this->getPosition()[0]][this->getPosition()[1] + 1] != '|') {
		
		this->setPosition({ this->getPosition()[0],this->getPosition()[1] + 1 });
	}
	else if (direction == 3&& map[this->getPosition()[0]+1][this->getPosition()[1] ] != '-') {
	
		this->setPosition({this->getPosition()[0]+1,this->getPosition()[1]});
	}
	else if (direction == 1&& map[this->getPosition()[0]-1][this->getPosition()[1]] != '-') {
		
		this->setPosition({this->getPosition()[0]-1,this->getPosition()[1]});
	}
	return 0;

}


int Player::Navigation(char map[][10]) {

	while (1) { 
		char input = '\0';
		cout << "enter [a,w,d,s] for movement or i for inventory or e to view stats" << endl;
		input = getchar();
		//cin>>input;
		//cout<<endl<<"input: "<<input<<endl;
		switch (input) {
		case 'a': this->move(map, 0); return 0;

		case 'w': this->move(map, 1); return 0;

		case 'd': this->move(map, 2); return 0;

		case 's': this->move(map, 3); return 0;

		case 'i':this->InventoryDialogue(); break;

		case 'e':this->EquipedDialogue(); break;

		}

	}

}

DoubleLinkedList<DamageTypes> Player::getAllDamageTypes(){
	DoubleLinkedList<DamageTypes> ret;
	ret.add(DamageTypes(this->getDamage()));
	int i=0;
	for(i=0;i<this->getRight()->getDamageTypes_Weapon().Size();i++){
		ret.add(this->getRight()->getDamageTypes_Weapon().getData(i));
	}
	for(i=0;i<this->getLeft()->getDamageTypes_Weapon().Size();i++){
		ret.add(this->getLeft()->getDamageTypes_Weapon().getData(i));
	}

	return ret;

}


int Player::TakeDamage(DoubleLinkedList<DamageTypes> damageTypes){
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
				else if (current.getType()==Critical_DamageType){
					cout<<"Critical hit"<<endl;
				}

				totalDamage+=current.getDamage();

			}
		}

		int taken = totalDamage - this->ActualDefense();
		if (taken < 1) {
			taken = 1;
		}
		this->setHealth(this->getHealth() - taken);
		return taken;

}

	//checks if money is > amount and subtracts from there and returns amount;
int Player::GiveMoney(int amount){
		if(this->getMoney()>amount){
			this->setMoney(this->getMoney()-amount);
			return amount;
		}

		return 0;
}

	//adds amount to money; can only be positive
bool Player::RecieveMoney(int amount){
		if (amount<0){
			return false;
		}
		this->setMoney(this->getMoney()+amount);
		return true;
}