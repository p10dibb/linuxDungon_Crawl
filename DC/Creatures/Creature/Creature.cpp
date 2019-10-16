//#pragma once

#include "Creature.h"

Creature::Creature() {
	//sets x=1
	this->position[0] = 1;
	//sets y=1
	this->position[1] = 1;

	this->Damage = 0;
	this->Speed = 0;
	this->Defense = 0;
	this->Stamina = 0;

	this->MaxHealth = 100;
	this->Health = 100;
	this->Level = 1;
	this->XP = 0;
	this->Name;


}
int Creature::getMaxHealth() {
	return this->MaxHealth;
}
void Creature::setMaxHealth(int m) {
	if (m < 1) {
		m = 0;
	}
	this->MaxHealth = m;
}


int Creature::getHealth() {
	return this->Health;
}
void Creature::setHealth(int h) {
	if (h < 0) {
		h = 0;
	}
	this->Health = h;
}

int Creature::getLevel() {
	return this->Level;
}

void Creature::setLevel(int l) {
	if (l < 1) {
		l = 1;
	}
	this->Level = l;
}


int Creature::getXP() {
	return this->XP;
}
void Creature::setXP(int x) {
	this->XP = x;
}
string Creature::getName() {
	return this->Name;
}
void  Creature::setName(string n) {
	this->Name = n;
}

void Creature::Display() {
	cout << "Name: \t" << this->Name << endl << "Level: \t" << Level << endl << "XP: \t" << this->XP << endl << "Health: \t" << this->Health << endl << "MaxHealth: \t" << this->MaxHealth << endl;

}


int Creature::getDamage() {
	return this->Damage;
}
void Creature::setDamage(int i) {
	if (i < 1) {
		i = 1;
	}
	this->Damage = i;
}
int Creature::getSpeed() {
	return this->Speed;
}
void  Creature::setSpeed(int s) {
	if (s < 1) {
		s = 1;
	}
	this->Speed = s;
}
int  Creature::getStamina() {
	return this->Stamina;
}
void  Creature::setStamina(int s) {

	if (s < 1) {
		s = 1;
	}
	this->Stamina = s;
}

int  Creature::getDefense() {
	return this->Defense;
}
void  Creature::setDefense(int d) {
	if (d < 0) {
		d=0;
	}
	this->Defense = d;
}


int  Creature::getStrength() {
	return this->Strength;
}
void  Creature::setStrength(int s) {
	this->Strength = s;
}



array<int, 2> Creature::getPosition() {
	return this->position;
}
bool Creature::setPosition(array<int, 2> pos) {
	this->position = pos;
	return true;
}
//0=left,1=up,2=right, 3=down
int Creature::move(char  map[][10],int direction) {
	
	return 0;

}




//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
int Creature::ContainDamageOverTimeEffect(Effects_enum effect){
	for (int i = 0; i < this->DamageOverTimeEffects.Size(); i++) {
		if (this->DamageOverTimeEffects.getNode(i)->getData().getEffect()== effect) {
			return i;
		}
	}
	return -1;
}
//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
int Creature::ContainCombatEffect(Effects_enum effect){
	for (int i = 0; i < this->CombatEffects.Size(); i++) {
		if (this->CombatEffects.getNode(i)->getData().getEffect()== effect) {
			return i;
		}
	}
	return -1;
}
//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
int Creature::ContainBuffEffect(Effects_enum effect){
	for (int i = 0; i < this->BuffEffects.Size(); i++) {
		if (this->BuffEffects.getNode(i)->getData().getEffect()== effect) {
			return i;
		}
	}
	return -1;
}
//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
int Creature::ContainDeBuffEffect(Effects_enum effect){
	for (int i = 0; i < this->DeBuffEffects.Size(); i++) {
		if (this->DeBuffEffects.getNode(i)->getData().getEffect()== effect) {
			return i;
		}
	}
	return -1;
}



//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddEffect(ActiveEffects effect){
	switch(effect.getEffectType()){
		case DamageOverTime_EffectTypes: this->AddDamageOverTimeEffect(effect);break;
		case Combat_EffectTypes: this->AddCombatEffect(effect);break;
		case Buff_EffectTypes: this->AddBuffEffect(effect);break;
		case DeBuff_EffectTypes:this->AddDeBuffEffect(effect);break;
	}
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddDamageOverTimeEffect(ActiveEffects effect){
	int pos = this->ContainDamageOverTimeEffect(effect.getEffect());
	if(pos==-1){
		this->DamageOverTimeEffects.add(effect);
	}else {
		ActiveEffects temp=this->DamageOverTimeEffects.getData(pos);
		//if it is damage over time or Buff it compares the damage and adds the higher of the 2 plus half the lower ones rounds
			if (temp.getDamage()<effect.getDamage()){
				this->DamageOverTimeEffects.getNode(pos)->Data.setDamage(effect.getDamage());
				this->DamageOverTimeEffects.getNode(pos)->Data.setRound((temp.getRound()/2)+effect.getRound());
			}else if (temp.getDamage()>effect.getDamage()){
				this->DamageOverTimeEffects.getNode(pos)->Data.setRound((effect.getRound()/2)+temp.getRound());
			}
			else{
				this->DamageOverTimeEffects.getNode(pos)->Data.addRounds(effect.getRound());
			}
	}
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddCombatEffect(ActiveEffects effect){
	int pos = this->ContainCombatEffect(effect.getEffect());
	if(pos==-1){
		this->CombatEffects.add(effect);
	}else {		
		this->CombatEffects.getNode(pos)->Data.addRounds(effect.getRound());			
	}
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddBuffEffect(ActiveEffects effect){
	int pos = this->ContainBuffEffect(effect.getEffect());
	if(pos==-1){
		this->BuffEffects.add(effect);
	}else {
		ActiveEffects temp=this->DamageOverTimeEffects.getData(pos);
		//if it is damage over time or Buff it compares the damage and adds the higher of the 2 plus half the lower ones rounds
			if (temp.getDamage()<effect.getDamage()){
				this->BuffEffects.getNode(pos)->Data.setDamage(effect.getDamage());
				this->BuffEffects.getNode(pos)->Data.setRound((temp.getRound()/2)+effect.getRound());
			}else if (temp.getDamage()>effect.getDamage()){
				this->BuffEffects.getNode(pos)->Data.setRound((effect.getRound()/2)+temp.getRound());
			}
			else{
				this->BuffEffects.getNode(pos)->Data.addRounds(effect.getRound());
			}
	}
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddDeBuffEffect(ActiveEffects effect){
	int pos = this->ContainDeBuffEffect(effect.getEffect());
	if(pos==-1){
		this->CombatEffects.add(effect);
	}else {		
		this->CombatEffects.getNode(pos)->Data.addRounds(effect.getRound());			
	}
}



//decrements all effect times by 1;
void Creature::DecrementAllEffects(){
	this->DecrementAllCombatEffects();
	this->DecrementAllBuffEffects();
	this->DecrementAllDamageOverTimeEffects();
	this->DecrementAllDeBuffEffects();
}
//decrements all effect times by 1;
void Creature::DecrementAllDeBuffEffects(){
	for (int i = 0; i < this->DeBuffEffects.Size(); i++) {
		this->DeBuffEffects.getNode(i)->Data.Decrement();
	}
}
//decrements all effect times by 1;
void Creature::DecrementAllBuffEffects(){
	for (int i = 0; i < this->BuffEffects.Size(); i++) {
		this->BuffEffects.getNode(i)->Data.Decrement();
	}
}
//decrements all effect times by 1;
void Creature::DecrementAllCombatEffects(){
	for (int i = 0; i < this->CombatEffects.Size(); i++) {
		this->CombatEffects.getNode(i)->Data.Decrement();
	}
}
//decrements all effect times by 1;
void Creature::DecrementAllDamageOverTimeEffects(){
	for (int i = 0; i < this->DamageOverTimeEffects.Size(); i++) {
		this->DamageOverTimeEffects.getNode(i)->Data.Decrement();
	}
}



	//Displays Effects
	void Creature::DisplayAllDeBuffEffects(){
		if(this->DeBuffEffects.Size()==0){
			cout<<"No Active DeBuffeffects"<<endl;
		}
		for (int i = 0; i < this->DeBuffEffects.Size(); i++) {
		 	this->DeBuffEffects.getData(i).DisplayDetails();
		}
	}
	//Displays Effects
	void Creature::DisplayAllBuffEffects(){
		if(this->BuffEffects.Size()==0){
			cout<<"No Active Buffeffects"<<endl;
		}
		for (int i = 0; i < this->DeBuffEffects.Size(); i++) {
		 	this->BuffEffects.getData(i).DisplayDetails();
		}
	}
	//Displays Effects
	void Creature::DisplayAllCombatEffects(){
		if(this->CombatEffects.Size()==0){
			cout<<"No Active CombatBuffeffects"<<endl;
		}
		for (int i = 0; i < this->CombatEffects.Size(); i++) {
		 	this->CombatEffects.getData(i).DisplayDetails();
		}
	}
	//Displays Effects
	void Creature::DisplayAllDamageOverTimeEffects(){
		if(this->DamageOverTimeEffects.Size()==0){
			cout<<"No Active DamageOverTimeeffects"<<endl;
		}
		for (int i = 0; i < this->DamageOverTimeEffects.Size(); i++) {
		 	this->DamageOverTimeEffects.getData(i).DisplayDetails();
		}
	}
	//Displays Effects
void Creature::DisplayAllEffects(){
		cout<<"ACTIVE EFFECTS"<<endl;
		cout<<endl<<"DeBuffs:"<<endl;
		this->DisplayAllDeBuffEffects();
		cout<<endl<<"Buffs:"<<endl;
		this->DisplayAllBuffEffects();
		cout<<endl<<"Combat:"<<endl;
		this->DisplayAllCombatEffects();
		cout<<endl<<"Damage Over Time:"<<endl;
		this->DisplayAllDamageOverTimeEffects();	
}

//itterates through active effects and applies damage from damage effects returns -1 if dead
int Creature::runDamageOverTimeEffects() {
	int damage = 0;
	int total=0;
	ActiveEffects current;
	for (int i = 0; i < this->DamageOverTimeEffects.Size(); i++) {
		current=this->DamageOverTimeEffects.getData(i);
		if ( current.getEffectType()==DamageOverTime_EffectTypes) {
			total+=current.getDamage();
			this->setHealth(this->getHealth() - current.getDamage());
			cout << this->getName() << " Took " << current.getDamage() << " damage from " << current.getEffectName() << endl;
			if (this->getHealth() <= 0) {
				cout << this->getName() << " has died from " << current.getEffectName()<<endl;
				return -1;
			}
		}
	}
	this->DecrementAllEffects();
	return 0;
}


//removes all effects
bool Creature::ClearAllDeBuffEffects(){
	while(this->DeBuffEffects.Size()!=0){

		this->DeBuffEffects.pop();
	}
	return true;
}
//removes all effects
bool Creature::ClearAllBuffEffects(){
	while(this->BuffEffects.Size()!=0){

		this->BuffEffects.pop();
	}
	return true;
}
//removes all effects
bool Creature::ClearAllCombatEffects(){
	while(this->CombatEffects.Size()!=0){

		this->CombatEffects.pop();
	}
	return true;
}
//removes all effects
bool Creature::ClearAllDamageOverTimeEffects(){
	while(this->DamageOverTimeEffects.Size()!=0){

		this->DamageOverTimeEffects.pop();
	}
	return true;
}
//removes all effects
bool Creature::ClearAllEffects(){
	this->ClearAllBuffEffects();
	this->ClearAllCombatEffects();
	this->ClearAllDamageOverTimeEffects();
	this->ClearAllDeBuffEffects();
	return true;
}


//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
ActiveEffects Creature::getDeBuffEffect(int pos){
	if (this->DeBuffEffects.Size()>pos&& pos>=0){
		return this->DeBuffEffects.getData(pos);
	}
	return ActiveEffects();
}
//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
ActiveEffects Creature::getBuffEffect(int pos){
	if (this->BuffEffects.Size()>pos&& pos>=0){
		return this->BuffEffects.getData(pos);
	}
	return ActiveEffects();
}
//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
ActiveEffects Creature::getCombatEffect(int pos){
	if (this->CombatEffects.Size()>pos&& pos>=0){
		return this->CombatEffects.getData(pos);
	}
	return ActiveEffects();
}
//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
ActiveEffects Creature::getDamageOverTimeEffect(int pos){
	if (this->DamageOverTimeEffects.Size()>pos&& pos>=0){
		return this->DamageOverTimeEffects.getData(pos);
	}
	return ActiveEffects();
}


