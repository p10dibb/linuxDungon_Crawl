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
bool Creature::ContainDamageOverTimeEffect(Effects_enum effect){

	if(this->DamageOverTimeEffects.count(effect)==1){
		return true;
	}
	return false;
}
//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
bool Creature::ContainCombatEffect(Effects_enum effect){
	if(this->CombatEffects.count(effect)==1){
		return true;
	}
	return false;
}
//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
bool Creature::ContainBuffEffect(Effects_enum effect){
	if(this->BuffEffects.count(effect)==1){
		return true;
	}
	return false;
}
//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
bool Creature::ContainDeBuffEffect(Effects_enum effect){
	if(this->DeBuffEffects.count(effect)==1){
		return true;
	}
	return false;
}
//check if it contains effect and returns that effects location in list and -1 if it doesnt exist;
bool Creature::ContainResistanceEffect(Effects_enum effect){
	if(this->ResistanceEffects.count(effect)==1){
		return true;
	}
	return false;
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
	if(!this->ContainDamageOverTimeEffect(effect.getEffect())){
		this->DamageOverTimeEffects[effect.getEffect()]=effect;
	}else {
		ActiveEffects temp=this->DamageOverTimeEffects[effect.getEffect()];
		//if it is damage over time or Buff it compares the damage and adds the higher of the 2 plus half the lower ones rounds
			if (temp.getDamage()<effect.getDamage()){
				this->DamageOverTimeEffects[effect.getEffect()].setDamage(effect.getDamage());
				this->DamageOverTimeEffects[effect.getEffect()].setRound((temp.getRound()/2)+effect.getRound());
			
			}else if (temp.getDamage()>effect.getDamage()){
				this->DamageOverTimeEffects[effect.getEffect()].setRound((effect.getRound()/2)+temp.getRound());
			}
			else{
				this->DamageOverTimeEffects[effect.getEffect()].addRounds(effect.getRound());
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
	if(!this->ContainCombatEffect(effect.getEffect())){
		this->CombatEffects[effect.getEffect()]=effect;
	}else {		
		this->CombatEffects[effect.getEffect()].addRounds(effect.getRound());			
	}
	return true;
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddBuffEffect(ActiveEffects effect){
	if (effect.getEffectType()!=Buff_EffectTypes){
		return false;
	}

	if(!this->ContainBuffEffect(effect.getEffect())){
		this->BuffEffects[effect.getEffect()]=effect;
	}else {
		ActiveEffects temp=this->BuffEffects[effect.getEffect()];
		//if it is damage over time or Buff it compares the damage and adds the higher of the 2 plus half the lower ones rounds
			if (temp.getDamage()<effect.getDamage()){
				this->BuffEffects[effect.getEffect()].setDamage(effect.getDamage());
				this->BuffEffects[effect.getEffect()].setRound((temp.getRound()/2)+effect.getRound());
			}else if (temp.getDamage()>effect.getDamage()){
				this->BuffEffects[effect.getEffect()].setRound((effect.getRound()/2)+temp.getRound());
			}
			else{
				this->BuffEffects[effect.getEffect()].addRounds(effect.getRound());
			}
	}
	return true;
}
//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddDeBuffEffect(ActiveEffects effect){
	if (effect.getEffectType()!=DeBuff_EffectTypes){
		return false;
	}
	if(!this->ContainDeBuffEffect(effect.getEffect())){
		this->DeBuffEffects[effect.getEffect()]=effect;
	}
	else {
		ActiveEffects temp=this->DeBuffEffects[effect.getEffect()];
		//if it is damage over time or Buff it compares the damage and adds the higher of the 2 plus half the lower ones rounds
			if (temp.getModifier()<effect.getModifier()){

				this->DeBuffEffects[effect.getEffect()].setModifier(effect.getModifier());
				this->DeBuffEffects[effect.getEffect()].setRound((temp.getRound()/2)+effect.getRound());
			}else if (temp.getModifier()>effect.getModifier()){
			
				this->DeBuffEffects[effect.getEffect()].setRound((effect.getRound()/2)+temp.getRound());
			}
			else{
				this->DeBuffEffects[effect.getEffect()].addRounds(effect.getRound());
			}
	}
	return true;
}

//checks if effect is in list and if it is then increase time else add new effect.
bool Creature::AddResistanceEffect(ActiveEffects effect){
	if (effect.getEffectType()!=Resistance_EffectTypes){
		return false;
	}
	if(!this->ContainResistanceEffect(effect.getEffect())){
		this->ResistanceEffects[effect.getEffect()]=effect;
	}else {
		ActiveEffects temp=this->ResistanceEffects[effect.getEffect()];
		//if it is damage over time or Buff it compares the damage and adds the higher of the 2 plus half the lower ones rounds
			if (temp.getResistance()<effect.getResistance()){
				this->ResistanceEffects[effect.getEffect()].setResistance(effect.getResistance());
				this->ResistanceEffects[effect.getEffect()].setRound((temp.getRound()/2)+effect.getRound());
			}else if (temp.getResistance()>effect.getResistance()){
				
				this->ResistanceEffects[effect.getEffect()].setRound((effect.getRound()/2)+temp.getRound());
			}
			else{
				
				this->ResistanceEffects[effect.getEffect()].addRounds(effect.getRound());
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

	map<Effects_enum, ActiveEffects >::const_iterator it = this->DeBuffEffects.begin();
	while (it!=this->DeBuffEffects.end()){
		ActiveEffects a=it->second;
		a.Decrement();
		
		this->DeBuffEffects[a.getEffect()]=a;
		
		it++;
	}	
	it = this->DeBuffEffects.begin();
	while (it!=this->DeBuffEffects.end()){
		ActiveEffects a=it->second;
	
		if(a.isFinished()){
			this->DeBuffEffects.erase(a.getEffect());
		}
		it++;
	}
}
//decrements all effect times by 1;
void Creature::DecrementAllBuffEffects(){

	map<Effects_enum, ActiveEffects >::const_iterator it = this->BuffEffects.begin();
	while (it!=this->BuffEffects.end()){
		ActiveEffects a=it->second;
		a.Decrement();
		this->BuffEffects[a.getEffect()]=a;
		
		it++;
	}	
	it = this->BuffEffects.begin();
	while (it!=this->BuffEffects.end()){
		ActiveEffects a=it->second;
	
		if(a.isFinished()){
			this->BuffEffects.erase(a.getEffect());
		}
		it++;
	}
}
//decrements all effect times by 1;
void Creature::DecrementAllCombatEffects(){
	map<Effects_enum, ActiveEffects >::const_iterator it = this->CombatEffects.begin();
	while (it!=this->CombatEffects.end()){
		ActiveEffects a=it->second;
		a.Decrement();
		this->CombatEffects[a.getEffect()]=a;
		
		it++;
	}	

	it = this->CombatEffects.begin();
	while (it!=this->CombatEffects.end()){
		ActiveEffects a=it->second;
	
		if(a.isFinished()){
			this->CombatEffects.erase(a.getEffect());
		}
		it++;
	}		
}
//decrements all effect times by 1;
void Creature::DecrementAllDamageOverTimeEffects(){
	map<Effects_enum, ActiveEffects >::const_iterator it = this->DamageOverTimeEffects.begin();
	while (it!=this->DamageOverTimeEffects.end()){
		ActiveEffects a=it->second;
		a.Decrement();
		this->DamageOverTimeEffects[a.getEffect()]=a;
		it++;
	}

	
	it = this->DamageOverTimeEffects.begin();
	while (it!=this->DamageOverTimeEffects.end()){
		ActiveEffects a=it->second;
	
		if(a.isFinished()){
			this->DamageOverTimeEffects.erase(a.getEffect());
		}
		it++;
	}	
}
//decrements all effect times by 1;
void Creature::DecrementAllResistanceEffects(){
	map<Effects_enum, ActiveEffects >::const_iterator it = this->ResistanceEffects.begin();
	while (it!=this->ResistanceEffects.end()){
		ActiveEffects a=it->second;
		a.Decrement();
		this->ResistanceEffects[a.getEffect()]=a;
		
		it++;
	}

	it = this->ResistanceEffects.begin();
	while (it!=this->ResistanceEffects.end()){
		ActiveEffects a=it->second;
	
		if(a.isFinished()){
			this->ResistanceEffects.erase(a.getEffect());
		}
		it++;
	}	
}

//Displays Effects
void Creature::DisplayAllDeBuffEffects(){
	
	map<Effects_enum, ActiveEffects >::const_iterator it = this->DeBuffEffects.begin();
	ActiveEffects a;
	while (it!=this->DeBuffEffects.end()){
	a=it->second;
	a.DisplayDetails();
	it++;
	}
	
}
	//Displays Effects
void Creature::DisplayAllBuffEffects(){

	map<Effects_enum, ActiveEffects >::const_iterator it = this->BuffEffects.begin();
	ActiveEffects a;
	while (it!=this->BuffEffects.end()){
	a=it->second;
	a.DisplayDetails();
	it++;
	}
	
}
	//Displays Effects
void Creature::DisplayAllCombatEffects(){
	map<Effects_enum, ActiveEffects >::const_iterator it = this->CombatEffects.begin();
	ActiveEffects a;
	while (it!=this->CombatEffects.end()){
		a=it->second;
		a.DisplayDetails();
		it++;
	}
}
	//Displays Effects
void Creature::DisplayAllDamageOverTimeEffects(){
	map<Effects_enum, ActiveEffects >::const_iterator it = this->DamageOverTimeEffects.begin();
	ActiveEffects a;
	while (it!=this->DamageOverTimeEffects.end()){
		a=it->second;
		a.DisplayDetails();
		it++;
	}
}
	//Displays Effects
void Creature::DisplayAllResistanceEffects(){
	map<Effects_enum, ActiveEffects >::const_iterator it = this->ResistanceEffects.begin();
	ActiveEffects a;
	while (it!=this->ResistanceEffects.end()){
		a=it->second;
		a.DisplayDetails();
		it++;
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

	map<Effects_enum,ActiveEffects>::const_iterator it =this->DamageOverTimeEffects.begin();
	while(it!=this->DamageOverTimeEffects.end()){
		current=it->second;
		if ( current.getEffectType()==DamageOverTime_EffectTypes) {
			total+=current.getDamage();
			this->setHealth(this->getHealth() - current.getDamage());
			cout << this->getName() << " Took " << current.getDamage() << " damage from " << current.getEffectName() << endl;
			if (this->getHealth() <= 0) {
				cout << this->getName() << " has died from " << current.getEffectName()<<endl;
				return -1;
			}
		}
		it++;
	}
	
	//this->DecrementAllEffects();
	return total;
}


//removes all effects
bool Creature::ClearAllDeBuffEffects(){
	map<Effects_enum,ActiveEffects>::const_iterator it=this->DeBuffEffects.begin();
	while(it!=this->DeBuffEffects.end()){
		this->DeBuffEffects.erase(it->first);
		it++;
	}
	return true;
//	this->DeBuffEffects.empty();
	
}
//removes all effects
bool Creature::ClearAllBuffEffects(){
	map<Effects_enum,ActiveEffects>::const_iterator it=this->BuffEffects.begin();
	while(it!=this->BuffEffects.end()){
		this->BuffEffects.erase(it->first);
		it++;
	}
	return true;
	//this->BuffEffects.empty();
}
//removes all effects
bool Creature::ClearAllCombatEffects(){
	map<Effects_enum,ActiveEffects>::const_iterator it=this->CombatEffects.begin();
	while(it!=this->CombatEffects.end()){
		this->CombatEffects.erase(it->first);
		it++;
	}
	//this->CombatEffects.empty();
	return true;
}
//removes all effects
bool Creature::ClearAllResistanceEffects(){
	map<Effects_enum,ActiveEffects>::const_iterator it=this->ResistanceEffects.begin();
	while(it!=this->ResistanceEffects.end()){
		this->ResistanceEffects.erase(it->first);
		it++;
	}
	//this->ResistanceEffects.empty();
	return true;
}
//removes all effects
bool Creature::ClearAllDamageOverTimeEffects(){
	map<Effects_enum,ActiveEffects>::const_iterator it=this->DamageOverTimeEffects.begin();
	while(it!=this->DamageOverTimeEffects.end()){
		this->DamageOverTimeEffects.erase(it->first);
		it++;
	}
	//this->DamageOverTimeEffects.empty();
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
ActiveEffects Creature::getDeBuffEffect(Effects_enum effect){
	if(this->ContainDeBuffEffect(effect)){
		return this->DeBuffEffects[effect];
	}
	return ActiveEffects();
}
//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
ActiveEffects Creature::getBuffEffect(Effects_enum effect){
	if(this->ContainDeBuffEffect(effect)){
		return this->DeBuffEffects[effect];
	}
	return ActiveEffects();
}
//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
ActiveEffects Creature::getCombatEffect(Effects_enum effect){
	if(this->ContainCombatEffect(effect)){
		return this->CombatEffects[effect];
	}
	return ActiveEffects();
}
//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
ActiveEffects Creature::getDamageOverTimeEffect(Effects_enum effect){
	if(this->ContainDamageOverTimeEffect(effect)){
		return this->DamageOverTimeEffects[effect];
	}
	return ActiveEffects();
}
//returns the Acctive effect at specified position. if no Acctive effect there then it returns default active effect
ActiveEffects Creature::getResistanceEffect(Effects_enum effect){
	if (this->ContainResistanceEffect(effect)){
		return this->ResistanceEffects[effect];
	}
	return ActiveEffects();
}

//the Double linked list Resistance Effects
map<Effects_enum,ActiveEffects> Creature::getResistanceEffects(){
	return this->ResistanceEffects;
}


//the Double linked list DeBuff Effects
map<Effects_enum,ActiveEffects> Creature::getDeBuffEffects(){
	return this->DeBuffEffects;
}
//the Double linked list Buff Effects
map<Effects_enum,ActiveEffects> Creature::getBuffEffects(){
	return this->BuffEffects;
}
//the Double linked list Combat Effects
map<Effects_enum,ActiveEffects> Creature::getCombatEffects(){
	return this->CombatEffects;
}
//the Double linked list DamageOverTime Effects
map<Effects_enum,ActiveEffects> Creature::getDamageOverTimeEffects(){
	return this->DamageOverTimeEffects;
}

