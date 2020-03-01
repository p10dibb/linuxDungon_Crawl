#include "ActiveEffects.h"

ActiveEffects::ActiveEffects()
{
	this->Effect = NULL_Effects;
	this->EffectType = NULL_EffectTypes;
	this->setRound(0);
	this->Modifier = 0;
}

ActiveEffects::ActiveEffects(EffectTypes_enum type, Effects_enum effect, int modifier, int rounds)
{

	this->EffectType = type;
	this->Effect = effect;
	this->setRound(rounds);

	switch (this->getEffectType())
	{
	case Buff_EffectTypes:
		this->setMultiplier(modifier);
		break;
	case Resistance_EffectTypes:
		this->setResistance(modifier);
		break;
	case DamageOverTime_EffectTypes:
		this->setDamage(modifier);
		break;
	default:
		this->Modifier = modifier;
		break;
	}
}

EffectTypes_enum ActiveEffects::getEffectType()
{
	return this->EffectType;
}

Effects_enum ActiveEffects::getEffect()
{
	return this->Effect;
}

int ActiveEffects::getRound()
{
	return this->RoundsActive;
}
void ActiveEffects::setRound(int r)
{
	if (r < 0)
	{
		r = 0;
	}
	this->RoundsActive = r;
}

// increases effect time by r
bool ActiveEffects::addRounds(int r)
{
	if (r < 1)
	{
		return false;
	}
	this->RoundsActive += r;
	return true;
}

//decreases Effect time by x
bool ActiveEffects::Decrement(int x)
{
	//so it doesnt go negative
	if (this->RoundsActive == 0)
	{
		return false;
	}
	//so it doesnt go negative
	if (this->RoundsActive < x)
	{
		return false;
	}

	this->RoundsActive -= x;
	return true;
}

//checks if effect time is finnished
bool ActiveEffects::isFinished()
{
	if (RoundsActive == 0)
	{
		return true;
	}
	return false;
}

bool ActiveEffects::DisplayDetails()
{
	cout << "Type: " << this->getEffectName();
	cout << endl;
	cout << "Rounds Left: " << this->RoundsActive << endl;

	return true;
}

// Returns the Effects name in string form
string ActiveEffects::getEffectName()
{

	switch (this->Effect)
	{
	case NULL_Effects:
		return "no effect";
	//Damage Over Time
	case Burning_Effects:
		return "Burning";
	case Bleeding_Effects:
		return "Bleeding";
	case Poison_Effects:
		return "Poison";
	//DeBuff
	case Slowed_Effects:
		return "Slowed";
	case Dazed_Effects:
		return "Dazed";
	case Weakness_Effects:
		return "Weakness";
	case BattleFatigue_Effects:
		return "Battle Fatigue";
	//Buff
	case SpeedBoost_Effects:
		return "Swiftness";
	case DamageBoost_Effects:
		return "Increased Damage";
	case DefenseBoost_Effects:
		return "Increased Defense";
	//Combat Effects
	case Bezerk_Effects:
		return "Bezerk";
	case DefensiveStance_Effects:
		return "Defensive Stance";
	case QuickStrike_Effects:
		return "Quick Strike";
	case Swordsman_Effects:
		return "Swordsman";
	case AnimalFury_Effects:
		return "Animal Fury";
	//Resistances
	case NormalResistance_Effects:
		return "Normal";
	case FireResistance_Effects:
		return "Fire";
	case PoisonResistance_Effects:
		return "Poison";
	case StabbingResistance_Effects:
		return "Stabbing";
	case BluntResistance_Effects:
		return "Blunt";

	default:
		return "";
	}
}

int ActiveEffects::getDamage()
{
	return this->Modifier;
}
//only useable for DamageOverTime_EffectTypeused to set damage>=0
void ActiveEffects::setDamage(int damage)
{
	if (this->EffectType = DamageOverTime_EffectTypes)
	{
		if (damage < 0)
		{
			damage = 0;
		}
		this->Modifier = damage;
	}
	else
	{
		this->Modifier = 0;
	}
}
//only useable for Resistance_EffectType used to set a resistance between 0 and 100
void ActiveEffects::setResistance(int Resist)
{
	if (this->EffectType == Resistance_EffectTypes)
	{
		if (Resist > 100)
		{
			Resist = 100;
		}
		this->Modifier = Resist;
	}
	else
	{
		this->Modifier = 0;
	}
}

int ActiveEffects::getResistance()
{
	return this->Modifier;
}

//only useable for Buff_EffectTypeused to set multiplier>=0
void ActiveEffects::setMultiplier(int multiplier)
{
	if (this->EffectType == Buff_EffectTypes)
	{
		if (multiplier < 0)
		{
			multiplier = 0;
		}
		this->Modifier = multiplier;
	}
	else
	{
		this->Modifier = 0;
	}
}
int ActiveEffects::getMultiplier()
{
	return this->Modifier;
}

//used to set modifier
void ActiveEffects::setModifier(int modifier)
{
	this->Modifier = modifier;
}
int ActiveEffects::getModifier()
{
	return this->Modifier;
}

// sf::RenderWindow window, sf::Text text, string input_text
//uses SFML to get a string and display it on a window
string getStringSFML(sf::RenderWindow *window, vector<sf::Text> otherTexts, sf::Text text, string input_text)
{
	string ret = "";

	//checks for key release
	bool release = 0;
	string current_Char;
	while (1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
		{
			release = 1;
			release = 1;

			current_Char = "0";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			release = 1;

			release = 1;

			current_Char = "1";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			release = 1;

			release = 1;

			current_Char = "2";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			release = 1;

			current_Char = "3";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			release = 1;

			current_Char = "4";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			release = 1;

			current_Char = "5";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			release = 1;

			current_Char = "6";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			release = 1;

			current_Char = "7";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		{
			release = 1;

			current_Char = "8";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
		{
			release = 1;

			current_Char = "9";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			release = 1;

			current_Char = "q";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			release = 1;

			current_Char = "w";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			release = 1;

			current_Char = "e";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			release = 1;

			current_Char = "r";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			release = 1;

			current_Char = "t";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			release = 1;

			current_Char = "y";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			release = 1;

			current_Char = "u";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			release = 1;

			current_Char = "i";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			release = 1;

			current_Char = "o";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			release = 1;

			current_Char = "p";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			release = 1;

			current_Char = "a";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			release = 1;

			current_Char = "s";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			release = 1;

			current_Char = "d";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			release = 1;

			current_Char = "f";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			release = 1;

			current_Char = "g";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			release = 1;

			current_Char = "h";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			release = 1;

			current_Char = "j";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			release = 1;

			current_Char = "k";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{

			release = 1;

			current_Char = "l";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			release = 1;

			current_Char = "z";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			release = 1;

			current_Char = "x";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			release = 1;

			current_Char = "c";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			release = 1;

			current_Char = "v";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			release = 1;

			current_Char = "b";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			release = 1;

			current_Char = "n";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			release = 1;

			current_Char = "m";
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{	
			//cannot be empty
			if(ret!=""){
			return ret;
				
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
			release =1;
			current_Char="delete";
		}
		else if (release )
		{
			//if deleting a character
			if(current_Char=="delete"){
				ret=ret.substr(0,ret.length()-1);
			}
			//else add. the character
			else{
			ret += current_Char;

			}
			//updates text
			text.setString(input_text + ret);

			//renders updated window
			window->clear();
			for (int i = 0; i < otherTexts.size(); i++)
			{
				window->draw(otherTexts[i]);
			}
			window->draw(text);
			window->display();

			release = 0;
		}
		else
		{
			// cout<<"loop"<<endl;
		}
	}
}