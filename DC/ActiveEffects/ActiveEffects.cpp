#include "ActiveEffects.h"

ActiveEffects::ActiveEffects() {
	this->Effect = NULL_Effects;
	this->EffectType=NULL_EffectTypes;
	this->setRound(0);
	this->Modifier = 0;
}


ActiveEffects::ActiveEffects(EffectTypes_enum type,Effects_enum effect,int modifier,int rounds){

	this->EffectType=type;
	this->Effect=effect;
	this->setRound(rounds);


	switch(this->getEffectType()){
		case Buff_EffectTypes: this->setMultiplier(modifier);break;
		case Resistance_EffectTypes: this->setResistance(modifier);break;
		case DamageOverTime_EffectTypes: this->setDamage(modifier);break;
	    default: this->Modifier=modifier;break;
	}

}

EffectTypes_enum ActiveEffects::getEffectType(){
	return this->EffectType;
}


Effects_enum ActiveEffects::getEffect() {
	return this->Effect;
}


int ActiveEffects::getRound() {
	return this->RoundsActive;
}
void ActiveEffects::setRound(int r) {
	if (r < 0) {
		r = 0;
	}
	this->RoundsActive = r;
}

// increases effect time by r
bool ActiveEffects::addRounds(int r) {
	if(r<1){
		return false;
	}
	this->RoundsActive += r;
	return true;
}

//decreases Effect time by x
bool ActiveEffects::Decrement(int x) {
	//so it doesnt go negative
	if (this->RoundsActive == 0){
		return false;
	}
	//so it doesnt go negative
	if(this->RoundsActive<x){
		return false;
	}

	this->RoundsActive -= x;
	return true;

}

//checks if effect time is finnished
bool ActiveEffects::isFinished() {
	if (RoundsActive == 0) {
		return true;
	}
	return false;
}

bool ActiveEffects::DisplayDetails() {
	cout << "Type: "<<this->getEffectName();
	cout << endl;
	cout << "Rounds Left: " << this->RoundsActive<<endl;

	return true;
}



// Returns the Effects name in string form
string ActiveEffects::getEffectName() {


	switch (this->Effect) {
	case NULL_Effects:return "no effect";
	//Damage Over Time
	case Burning_Effects: return"Burning";
	case Bleeding_Effects: return "Bleeding";
	case Poison_Effects: return "Poison";
	//DeBuff
	case Slowed_Effects: return"Slowed";
	case Dazed_Effects:return"Dazed";
	case Weakness_Effects: return "Weakness";
	case BattleFatigue_Effects:return "Battle Fatigue";
	//Buff
	case SpeedBoost_Effects:return "Swiftness";
	case DamageBoost_Effects: return"Increased Damage";
	case DefenseBoost_Effects: return"Increased Defense";
	//Combat Effects
	case Bezerk_Effects: return "Bezerk";
	case DefensiveStance_Effects: return "Defensive Stance";
	case QuickStrike_Effects: return "Quick Strike";
	case Swordsman_Effects: return "Swordsman";
	case AnimalFury_Effects: return "Animal Fury";
	//Resistances
	case NormalResistance_Effects:return "Normal";
	case FireResistance_Effects:return "Fire";
	case PoisonResistance_Effects: return "Poison";
	case StabbingResistance_Effects: return "Stabbing";
	case BluntResistance_Effects: return "Blunt";

	default:return "";
	}
}


int ActiveEffects::getDamage() {
	return this->Modifier;
}
//only useable for DamageOverTime_EffectTypeused to set damage>=0
void ActiveEffects::setDamage(int damage){
	if(this->EffectType=DamageOverTime_EffectTypes){
		if(damage<0){
			damage=0;
		}
		this->Modifier=damage;
	}else{
		this->Modifier=0;
	}

}
//only useable for Resistance_EffectType used to set a resistance between 0 and 100
void ActiveEffects::setResistance(int Resist){
	if(this->EffectType==Resistance_EffectTypes){
		if(Resist>100){
			Resist=100;
		}
		this->Modifier=Resist;
	}else{
		this->Modifier=0;
	}

}

int ActiveEffects::getResistance(){
	return this->Modifier;
}

//only useable for Buff_EffectTypeused to set multiplier>=0
void ActiveEffects::setMultiplier(int multiplier){
	if(this->EffectType==Buff_EffectTypes){
		if(multiplier<0){
			multiplier=0;
		}
		this->Modifier=multiplier;
	}else{
		this->Modifier=0;
	}
}
int ActiveEffects::getMultiplier(){
	return this->Modifier;
}

//used to set modifier
void ActiveEffects::setModifier(int modifier){
	this->Modifier=modifier;
}
int ActiveEffects::getModifier(){
	return this->Modifier;
}

// sf::RenderWindow window, sf::Text text, string input_text
//uses SFML to get a string and display it on a window
string getStringSFML(sf::RenderWindow *window,sf::Text text, string input_text)
{
	string ret = "";
	int add=0;
	string current_Char;
	while (1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
		{
			add=1;
			ret += "0";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			add=1;

			ret += "1";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			add=1;

			ret += "2";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			ret += "3";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			ret += "4";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			ret += "5";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			ret += "6";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			ret += "7";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		{
			ret += "8";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
		{
			ret += "9";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			ret += "q";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			ret += "w";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			ret += "e";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			ret += "r";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			ret += "t";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			ret += "y";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
		cout<<"char U"<<endl;
			add=1;


			current_Char = "u";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			ret += "i";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			ret += "o";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
		cout<<"char P"<<endl;
			add=1;


			current_Char = "p";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
		cout<<"char A"<<endl;
			add=1;


			current_Char = "a";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			ret += "s";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			ret += "d";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			ret += "f";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			ret += "g";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			ret += "h";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			ret += "j";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			ret += "k";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
		cout<<"char L"<<endl;
			add=1;


			current_Char= "l";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			ret += "z";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			ret += "x";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			ret += "c";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			ret += "v";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			ret += "b";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			ret += "n";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			ret += "m";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			cout<<"ret: "<<ret<<endl;
			return ret;
		}else if(add==1){
			
			cout<<"in add";
			ret+=current_Char;
			text.setString(input_text+ret);
			window->clear();
			window->draw(text);
			add=0;
			window->display();
		}
		else{
		// cout<<"loop"<<endl;

		}
	}
}