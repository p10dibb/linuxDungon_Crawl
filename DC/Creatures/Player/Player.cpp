#include "Player.h"
#include <cstdio>

string toLower(string s) {
	string ret = "";
	for (int i = 0; i < s.length();i++) {
		ret = ret + char(tolower(s[i]));
	
	}
	return ret;
}

//takes in a string and a array of strings and shows the position that that function is located, -1 if not contained
int getFunc(string str, string options[], int size){
	
	for(int i=0;i<size;i++){
		if(options[i]==str){
			return i;
		}
	}
	//if not in options
	return -1;

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

int Player::PauseMenue(){
	string options[10]={"resume","inventory","stats","equiped","save","exit"};
	int func=-2;
	string choice;
	cout<<"-----PAUSED-------"<<endl;

	//while resume command not run
	while(func!=0){
		cout<<"Choices:"<<endl;
		for (int i=0;i<6;i++){
			cout<<options[i]<<endl;
		}
		cout<<"Enter Choice:"<<endl;
		cin>>choice;
		func=getFunc(toLower(choice),options,5);

		switch (func)
		{
		case -1:cout<<"Not a valid choice"<<endl;break;
		case 1:this->InventoryDialogue();break;
		case 2:this->DisplayStats();break;
		case 3:this->EquipedDialogue();break;
		case 4:cout<<"saving(doesnt do anyhing yet)"<<endl;break;
		case 5: cout<<"Exiting (doesnt do anything yet)"<<endl;
		
		default:
			break;
		}

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
	int speed = 0;
	int ArmorWeight = this->getHead()->getWeight() + this->getTorso()->getWeight() + this->getHands()->getWeight() + this->getLegs()->getWeight() + this->getFeet()->getWeight();

	//if onehanded else dual wielding
	if (this->Left->getType() == NULL_WeaponType) {
		
		speed = this->getSpeed() + this->Right->getSpeed() - (ArmorWeight / (1+(this->getStrength() / 2)));
	}
	else if(this->Right->getType() == NULL_WeaponType) {
	
		speed = this->getSpeed() + this->Left->getSpeed() - (ArmorWeight / (this->getStrength() / 2));
	}
	else {
		//two weapons being used 2/3 the speed of both weapons added together so dual wielding is slower but has higher attack and defense
		speed = this->getSpeed() +( (this->Left->getSpeed()+this->Right->getSpeed())/3 )- (ArmorWeight / (this->getStrength() / 2));
	}


	//if slwed effect is active then decrease speed by 25%
	if (this->ContainDeBuffEffect(Slowed_Effects)) {
		speed = speed * .75;
	}
	if (this->ContainDeBuffEffect(Dazed_Effects)) {
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
	return speed;

}

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
		//this->Money += loot.gold;
		this->RecieveMoney(loot.gold);
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
	cout<<endl;

}

void Player::addSkillPoint(){
	string options[10]={"1","2","3","4","5","6"};
				
	string input="";
	int exit=0;
	while(exit!=1){
		cout << "#\tstat\tcurrent level\tDescription" << endl;
		cout << "1\tMaxHealth\t" << this->getMaxHealth() <<"\tMaximum Health of the player"<< endl;
		cout << "2\tStrength\t" << this->getStrength() <<"\tIncreases Carrying capacity and lessens handicap of speed for heavy armour"<< endl;
		cout << "3\tSpeed\t" << this->getSpeed() << "\tIncreases speed in combat"<<endl;
		cout << "4\tBase Attack\t" << this->getDamage() <<"\tIncreases Base Damage"<< endl;
		cout << "5\tBase Defense\t" << this->getDefense() <<"\tIncreases Base Defense"<< endl;
		cout << "6\tStamina\t" << this->getStamina() << "\tCurrently Does nothing"<<endl;
		cout << "Choice: ";
		cin >> input;
		
		switch(getFunc(input,options,6)){
			case 0:this->setMaxHealth(this->getMaxHealth() + 10);
				this->setHealth(this->getMaxHealth());
				exit=1;
				break;
			case 1: this->setStrength(this->getStrength()+1);
				this->MaxWeight = this->getStrength() * 10;			
				this->setOverWeighted(this->MaxWeight < this->CurrentWeight);	
				exit=1;	
				break;
			case 2:this->setSpeed(this->getSpeed() + 1);exit=1;break;
			case 3:this->setDamage(this->getDamage()+1);exit=1;break;
			case 4:this->setDefense(this->getDefense()+1);exit=1;break;
			case 5:this->setStamina(this->getStamina()+1);exit=1;break;
			default: cout << "Not a valid choice:" << endl;break;
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
int Player::move(char map[][10], int direction) {

	   	 							
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
		cout << "enter [a,w,d,s] for movement or i for inventory or e to view equiped or p to pause fo more options" << endl;
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

		case 'p':this->PauseMenue();break;

		}

	}

}

//gets all damage types from variouse weapons
DoubleLinkedList<DamageTypes> Player::getAllDamageTypes(){
	DoubleLinkedList<DamageTypes> ret;
	//adds base Damage;
	ret.add(DamageTypes(this->getDamage()));
	int i=0;

	//gets all Damage types from right weapon
	for(i=0;i<this->getRight()->getDamageTypes_Weapon().Size();i++){
		ret.add(this->getRight()->getDamageTypes_Weapon().getData(i));
	}
	//gets all Damage types from left weapon
	for(i=0;i<this->getLeft()->getDamageTypes_Weapon().Size();i++){
		ret.add(this->getLeft()->getDamageTypes_Weapon().getData(i));
	}

	int location=-1;
	//if no damage booster
	if (location=this->ContainBuffEffect(DamageBoost_Effects)==-1){
		return ret;
	}else// if there is a damage booster;
	{
		//gets the multiplier
		int DamageMultiplier=this->getBuffEffect(location).getDamage();
		//new Linkedlist
		DoubleLinkedList<DamageTypes> ret2;
		DamageTypes cur;
		for (int i=0;i<ret.Size();i++){
			cur=ret.getData(i);
			ret2.add(DamageTypes(cur.getDamage(),cur.getProbability(),cur.getType(),cur.getIsDamageOverTime(),cur.getDamageOverTime_damage(),cur.getDamageOverTime_time()));
			
		}
		return ret2;
	}
	


	

}

//recieves a linked list of damage types and and runs through the damage taken
int Player::TakeDamage(DoubleLinkedList<DamageTypes> damageTypes){
		DamageTypes current;
		int location=1,totalDamage=0;;

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
				totalDamage+=current.getDamage();
			}
		}			

		// checks if there is a defense boost and suptracks total armor from damage
		if(location=ContainBuffEffect(DefenseBoost_Effects)==-1){
			totalDamage=totalDamage - this->ActualDefense();
		}else{			 
			totalDamage=totalDamage - this->ActualDefense()*this->getBuffEffect(location).getDamage();
		}
	
		if (totalDamage< 1) {
			totalDamage = 1;
		}
		this->setHealth(this->getHealth() - totalDamage);
		return totalDamage;

}

//checks if money is > amount and subtracts from there and returns amount;
int Player::GiveMoney(int amount){
		if(this->getMoney()>amount){
			this->setMoney(this->getMoney()-amount);
			this->IncrementGoldSpent(amount);
			return amount;
		}

		return 0;
}

//adds amount to money; can only be positive
bool Player::RecieveMoney(int amount){
		if (amount<0){
			return false;
		}
		this->IncrementGoldCollected(amount);
		this->setMoney(this->getMoney()+amount);
		
		this->RewardCheckMaxGoldHeld();
		return true;
}