//#pragma once

#include "Creature.h"

Creature::Creature() {
	//sets x=1
	this->position[0] = 1;
	//sets y=1
	this->position[1] = 1;

	this->Damage = 1;
	this->Speed = 1;
	this->Defense = 0;
	this->Stamina = 1;
	this->Strength=0;

	this->MaxHealth = 100;
	this->Health = 100;
	this->Level = 1;
	this->XP = 0;
	this->Name="";

	//this->ResistanceEffects.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,15));


}
int Creature::getMaxHealth() {
	return this->MaxHealth;
}
void Creature::setMaxHealth(int m) {
	if (m < 1) {
		m = 1;
	}
	if(m<this->getHealth()){
		this->setHealth(m);
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
	if(h>this->getMaxHealth()){
		h=this->getMaxHealth();
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
	if(x<0){
		x=0;
	}
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
	if (s < 0) {
		s=0;
	}
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
//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
int Creature::ContainResistanceEffect(Effects_enum effect){
	for (int i = 0; i < this->ResistanceEffects.Size(); i++) {
		if (this->ResistanceEffects.getNode(i)->getData().getEffect()== effect) {
			return i;
		}
	}
	return -1;
}





//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddEffect(ActiveEffects effect){
	switch(effect.getEffectType()){
		case DamageOverTime_EffectTypes: return this->AddDamageOverTimeEffect(effect);
		case Combat_EffectTypes: return this->AddCombatEffect(effect);
		case Buff_EffectTypes: return this->AddBuffEffect(effect);
		case DeBuff_EffectTypes:return this->AddDeBuffEffect(effect);
		case Resistance_EffectTypes:return this->AddResistanceEffect(effect);
		default: return false;
	}
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddDamageOverTimeEffect(ActiveEffects effect){
	if (effect.getEffectType()!=DamageOverTime_EffectTypes){
		return false;
	}
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
	return true;
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddCombatEffect(ActiveEffects effect){
	if (effect.getEffectType()!=Combat_EffectTypes){
		return false;
	}
	int pos = this->ContainCombatEffect(effect.getEffect());
	if(pos==-1){
		this->CombatEffects.add(effect);
	}else {		
		this->CombatEffects.getNode(pos)->Data.addRounds(effect.getRound());			
	}
	return true;
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddBuffEffect(ActiveEffects effect){
	if (effect.getEffectType()!=Buff_EffectTypes){
		return false;
	}
	int pos = this->ContainBuffEffect(effect.getEffect());
	if(pos==-1){
		this->BuffEffects.add(effect);
	}else {
		ActiveEffects temp=this->BuffEffects.getData(pos);
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
	return true;
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddDeBuffEffect(ActiveEffects effect){
	if (effect.getEffectType()!=DeBuff_EffectTypes){
		return false;
	}
	int pos = this->ContainDeBuffEffect(effect.getEffect());
	if(pos==-1){
		this->DeBuffEffects.add(effect);
	}else {
		ActiveEffects temp=this->DeBuffEffects.getData(pos);
		//if it is damage over time or Buff it compares the damage and adds the higher of the 2 plus half the lower ones rounds
			if (temp.getModifier()<effect.getModifier()){
				this->DeBuffEffects.getNode(pos)->Data.setModifier(effect.getModifier());
				this->DeBuffEffects.getNode(pos)->Data.setRound((temp.getRound()/2)+effect.getRound());
			}else if (temp.getModifier()>effect.getModifier()){
				
				this->DeBuffEffects.getNode(pos)->Data.setRound((effect.getRound()/2)+temp.getRound());
			}
			else{
				
				this->DeBuffEffects.getNode(pos)->Data.addRounds(effect.getRound());
			}
	}
	return true;
}

//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddResistanceEffect(ActiveEffects effect){
	if (effect.getEffectType()!=Resistance_EffectTypes){
		return false;
	}
	int pos = this->ContainResistanceEffect(effect.getEffect());
	if(pos==-1){
		this->ResistanceEffects.add(effect);
	}else {
		ActiveEffects temp=this->ResistanceEffects.getData(pos);
		//if it is damage over time or Buff it compares the damage and adds the higher of the 2 plus half the lower ones rounds
			if (temp.getResistance()<effect.getResistance()){
				this->ResistanceEffects.getNode(pos)->Data.setResistance(effect.getResistance());
				this->ResistanceEffects.getNode(pos)->Data.setRound((temp.getRound()/2)+effect.getRound());
			}else if (temp.getResistance()>effect.getResistance()){
				
				this->ResistanceEffects.getNode(pos)->Data.setRound((effect.getRound()/2)+temp.getRound());
			}
			else{
				
				this->ResistanceEffects.getNode(pos)->Data.addRounds(effect.getRound());
			}
	}
	return true;
}



//decrements all effect times by 1;
void Creature::DecrementAllEffects(){
	this->DecrementAllCombatEffects();
	this->DecrementAllBuffEffects();
	this->DecrementAllDamageOverTimeEffects();
	this->DecrementAllDeBuffEffects();
	this->DecrementAllResistanceEffects();
}
//decrements all effect times by 1;
void Creature::DecrementAllDeBuffEffects(){
	for (int i = 0; i < this->DeBuffEffects.Size(); i++) {
		this->DeBuffEffects.getNode(i)->Data.Decrement();
	}
	for(int i=this->DeBuffEffects.Size()-1;i>=0;i--){
		if (this->DeBuffEffects.getData(i).getRound()==0){
			cout<<"removing "<<this->BuffEffects.getData(i).getEffectName()<<endl;
			//i+1 because remove Node goes from 1 ->Size instead of 0->Size-1			
			this->DeBuffEffects.removeNode(i+1);
		}
	}
	
}
//decrements all effect times by 1;
void Creature::DecrementAllBuffEffects(){
	for (int i = 0; i < this->BuffEffects.Size(); i++) {
		this->BuffEffects.getNode(i)->Data.Decrement();
	}
	for(int i=this->BuffEffects.Size()-1;i>=0;i--){
		if (this->BuffEffects.getData(i).getRound()==0){
			cout<<"removing "<<this->BuffEffects.getData(i).getEffectName()<<endl;
			//i+1 because remove Node goes from 1 ->Size instead of 0->Size-1			
			this->BuffEffects.removeNode(i+1);
		}
	}
}
//decrements all effect times by 1;
void Creature::DecrementAllCombatEffects(){
	for (int i = 0; i < this->CombatEffects.Size(); i++) {
		this->CombatEffects.getNode(i)->Data.Decrement();
	}
	for(int i=this->CombatEffects.Size()-1;i>=0;i--){
		if (this->CombatEffects.getData(i).getRound()==0){
			cout<<"removing "<<this->CombatEffects.getData(i).getEffectName()<<endl;
			//i+1 because remove Node goes from 1 ->Size instead of 0->Size-1			
			this->CombatEffects.removeNode(i+1);
		}
	}
}
//decrements all effect times by 1;
void Creature::DecrementAllDamageOverTimeEffects(){
	for (int i = 0; i < this->DamageOverTimeEffects.Size(); i++) {
		this->DamageOverTimeEffects.getNode(i)->Data.Decrement();
	}
	for(int i=this->DamageOverTimeEffects.Size()-1;i>=0;i--){
		if (this->DamageOverTimeEffects.getData(i).getRound()==0){
			cout<<"removing "<<this->DamageOverTimeEffects.getData(i).getEffectName()<<endl;
			//i+1 because remove Node goes from 1 ->Size instead of 0->Size-1			
			this->DamageOverTimeEffects.removeNode(i+1);
		}
	}
}
//decrements all effect times by 1;
void Creature::DecrementAllResistanceEffects(){
	for (int i = 0; i < this->ResistanceEffects.Size(); i++) {
		this->ResistanceEffects.getNode(i)->Data.Decrement();
	}
	for(int i=this->ResistanceEffects.Size()-1;i>=0;i--){
		if (this->ResistanceEffects.getData(i).getRound()==0){
			cout<<"removing "<<this->ResistanceEffects.getData(i).getEffectName()<<endl;
			//i+1 because remove Node goes from 1 ->Size instead of 0->Size-1			
			this->ResistanceEffects.removeNode(i+1);
		}
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
void Creature::DisplayAllResistanceEffects(){
		if(this->CombatEffects.Size()==0){
			cout<<"No ActiveResistanceBuffeffects"<<endl;
		}
		for (int i = 0; i < this->ResistanceEffects.Size(); i++) {
		 	this->ResistanceEffects.getData(i).DisplayDetails();
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
		this->DisplayAllResistanceEffects();
		cout<<endl<<"Resistance:"<<endl;
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
	return total;
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
bool Creature::ClearAllResistanceEffects(){
	while(this->ResistanceEffects.Size()!=0){

		this->ResistanceEffects.pop();
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
	this->ClearAllResistanceEffects();
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
//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
ActiveEffects Creature::getResistanceEffect(int pos){
	if (this->ResistanceEffects.Size()>pos&& pos>=0){
		return this->ResistanceEffects.getData(pos);
	}
	return ActiveEffects();
}

//the Double linked list Resistance Effects
DoubleLinkedList<ActiveEffects> Creature::getResistanceEffects(){
	return this->ResistanceEffects;
}


//the Double linked list DeBuff Effects
DoubleLinkedList<ActiveEffects> Creature::getDeBuffEffects(){
	return this->DeBuffEffects;
}
//the Double linked list Buff Effects
DoubleLinkedList<ActiveEffects> Creature::getBuffEffects(){
	return this->BuffEffects;
}
//the Double linked list Combat Effects
DoubleLinkedList<ActiveEffects> Creature::getCombatEffects(){
	return this->CombatEffects;
}
//the Double linked list DamageOverTime Effects
DoubleLinkedList<ActiveEffects> Creature::getDamageOverTimeEffects(){
	return this->DamageOverTimeEffects;
}

