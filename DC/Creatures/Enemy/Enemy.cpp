#include "Enemy.h"

Enemy::Enemy()
{
	Biped();

	this->moveAmt = 0;
	this->direction = No_Direction;

	// this->weapon = new Weapon();

	this->type = NULL_Enemy;
}

Direction_enum Enemy::getDirection()
{
	return this->direction;
}

int Enemy::getMoveAmt()
{
	return this->moveAmt;
}

// Weapon *Enemy::getWeapon()
// {
// 	return this->weapon;
// }

// void Enemy::setWeapon(Weapon *w)
// {
// 	this->weapon = w;
// }

vector<ActiveEffects> Enemy::getAllResistanceTypes()
{
	vector<ActiveEffects> ret;
	vector<ActiveEffects> temp;
	//DoubleLinkedList<ActiveEffects> ret=this->getResistanceEffects();
	if (!this->getResistanceEffects().empty())
	{
		map<Effects_enum, ActiveEffects>::const_iterator it = this->getResistanceEffects().begin();
		ActiveEffects t;

		while (it != this->getResistanceEffects().end())
		{
			t = it->second;
			ret.push_back(t);
			it++;
		}
	}

	//takes current damage stat and converts to an active effect
	ret.push_back(ActiveEffects(Resistance_EffectTypes, NormalResistance_Effects, this->getDefense(), 10));

	//adds Enemy default defense
	for(int i=0;i<this->weapons.size();i++){
ret.push_back(this->weapons[i]->getDefense());
	}
	

	//gets helmet resistance
	temp = this->getHead()->getResistanceTypes();
	for (int i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}

	//gets chestpiece resistance
	temp = this->getTorso()->getResistanceTypes();
	for (int i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}

	//gets glove resistance
	temp = this->getHands()->getResistanceTypes();
	for (int i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}

	//gets Pant resistance
	temp = this->getLegs()->getResistanceTypes();
	for (int i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}

	//gets boots resistance
	temp = this->getFeet()->getResistanceTypes();
	for (int i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}

	if (this->ContainBuffEffect(DefenseBoost_Effects))
	{
		int DefenseBoost = this->getBuffEffect(DefenseBoost_Effects).getMultiplier();
		for (int i = 0; i < ret.size(); i++)
		{
			ret[i].setResistance(ret[i].getResistance() * DefenseBoost);
		}
	}

	return ret;
}

//recieves a linked list of damage types and and runs through the damage taken
int Enemy::TakeDamage(vector<DamageTypes> damageTypes)
{
	DamageTypes current;
	int location = 1, totalDamage = 0;
	;

	vector<ActiveEffects> resistances = this->getAllResistanceTypes();
	//itterates through all damage types
	for (int i = 0; i < damageTypes.size(); i++)
	{
		current = damageTypes[i];

		//checks to see if damage type happens
		if (rand() % 100 <= current.getProbability())
		{
			//checks if Effect needs to be added
			switch (current.getType())
			{
			case Fire_DamageType:
				cout << "Burning" << endl;
				this->AddEffect(ActiveEffects(DamageOverTime_EffectTypes, Burning_Effects, current.getDamageOverTime_damage(), current.getDamageOverTime_time()));
				break;
			case Blunt_DamageType:
				cout << "Dazed" << endl;
				this->AddEffect(ActiveEffects(DamageOverTime_EffectTypes, Dazed_Effects, current.getDamageOverTime_damage(), current.getDamageOverTime_time()));
				break;
			case Stabbing_DamageType:
				cout << "Bleeding" << endl;
				this->AddEffect(ActiveEffects(DamageOverTime_EffectTypes, Bleeding_Effects, current.getDamageOverTime_damage(), current.getDamageOverTime_time()));
				break;
			case Critical_DamageType:
				cout << "Critical hit" << endl;
				break;
			default:
				break;
			}
			totalDamage += ReduceDamage(current.getDamage(), current.getType(), resistances);
		}
	}

	// checks if there is a defense boost and suptracks total armor from damage
	if (location = ContainBuffEffect(DefenseBoost_Effects))
	{
		totalDamage = totalDamage / this->getBuffEffect(DefenseBoost_Effects).getMultiplier();
	}

	if (totalDamage < 1)
	{
		totalDamage = 1;
	}
	this->setHealth(this->getHealth() - totalDamage);
	return totalDamage;
}

void Enemy::DisplayDetails()
{
	Display();
	cout << "Damage: " << this->getDamage() << endl;
	cout << "Speed: " << this->getSpeed() << endl;
	//cout << "Defense: " << this->getDefense() << endl;
	cout << "Stamina: " << this->getStamina() << endl;
	cout << "Weapon: " << endl;
	// this->weapon->DisplayDetails();
}

int Enemy::ActualSpeed()
{
	int speed = 0;
	int ArmorWeight = this->getHead()->getWeight() + this->getTorso()->getWeight() + this->getHands()->getWeight() + this->getLegs()->getWeight() + this->getFeet()->getWeight();

	for(int i=0;i<this->weapons.size();i++){
		speed+=this->weapons[i]->getSpeed();
	}

	speed=speed/(weapons.size()+1);

	speed+=this->getSpeed();
	speed -= (ArmorWeight / (this->getStrength() / 2));

	if (this->ContainDeBuffEffect(Slowed_Effects))
	{
		speed = speed * .75;
	}
	if (this->ContainDeBuffEffect(Dazed_Effects))
	{
		speed = speed * .75;
	}

	return speed;
}

vector<DamageTypes> Enemy::getAllDamageTypes()
{
	vector<DamageTypes> ret;
	vector<DamageTypes> temp;


	ret.push_back(DamageTypes(this->getDamage()));
	

	// ret = this->getWeapon()->getDamageTypes_Weapon(); 	 	

	for(int i=0; i<this->weapons.size();i++){
		temp=this->weapons[i]->getDamageTypes_Weapon();
		for (int j=0; j<temp.size();j++){
			ret.push_back(temp[j]);
		}
	}

	if (!this->ContainBuffEffect(DamageBoost_Effects))
	{
		return ret;
	}
	else // if there is a damage booster;
	{
		//gets the multiplier
		int DamageMultiplier = this->getBuffEffect(DamageBoost_Effects).getMultiplier();

		//new Linkedlist
		vector<DamageTypes> ret2;
		DamageTypes cur;
		for (int i = 0; i < ret.size(); i++)
		{
			cur = ret[i];
			ret2.push_back(DamageTypes(cur.getDamage() * DamageMultiplier, cur.getProbability(), cur.getType(), cur.getIsDamageOverTime(), cur.getDamageOverTime_damage(), cur.getDamageOverTime_time()));
		}
		return ret2;
	}

	return ret;
}

void Enemy::move(array<array<RoomPieces_enum, 50>, 50> map)
{

	//if not moving in a set direction then pick new direction and distance
	if (this->moveAmt == 0)
	{

		this->moveAmt = rand() % 5 + 1;
		int d = rand() % 5;
		switch (d)
		{
		case 0:
			this->direction = Left_Direction;
			break;
		case 1:
			this->direction = Up_Direction;
			break;
		case 2:
			this->direction = Right_Direction;
			break;
		case 3:
			this->direction = Down_Direction;
			break;
		default:
			this->direction = No_Direction;
			break;
		}
	}

	//move left
	if (direction == Left_Direction)
	{
		//check for wall
		if (map[this->getPosition()[0]][this->getPosition()[1] - 1] == Empty_RoomPieces || map[this->getPosition()[0]][this->getPosition()[1] - 1] == Player_RoomPieces)
		{
			this->setPosition({this->getPosition()[0], this->getPosition()[1] - 1});
		}
	} // move right
	else if (direction == Right_Direction)
	{
		//check for wall
		if (map[this->getPosition()[0]][this->getPosition()[1] + 1] == Empty_RoomPieces || map[this->getPosition()[0]][this->getPosition()[1] + 1] == Player_RoomPieces)
		{
			this->setPosition({this->getPosition()[0], this->getPosition()[1] + 1});
		}
	}
	//move up
	else if (direction == Up_Direction)
	{
		//check for wall
		if (map[this->getPosition()[0] - 1][this->getPosition()[1]] == Empty_RoomPieces || map[this->getPosition()[0] - 1][this->getPosition()[1]] == Player_RoomPieces)
		{
			this->setPosition({this->getPosition()[0] - 1, this->getPosition()[1]});
		}
	} // move down
	else if (direction == Down_Direction)
	{
		//check for wall
		if (map[this->getPosition()[0] + 1][this->getPosition()[1]] == Empty_RoomPieces || map[this->getPosition()[0] + 1][this->getPosition()[1]] == Player_RoomPieces)
		{
			this->setPosition({this->getPosition()[0] + 1, this->getPosition()[1]});
		}
	}

	this->moveAmt--;
}

Enemy_enum Enemy::getType()
{
	return this->type;
}
bool Enemy::setType(Enemy_enum type)
{
	this->type = type;
	return true;
}

bool Enemy::setWeapons(vector<Weapon *> weapons)
{
	this->weapons = weapons;
	return true;
}
bool Enemy::addWeapon(Weapon *weapon)
{
	this->weapons.push_back(weapon);
	return true;
}
vector<Weapon *> Enemy::getWeapons()
{
	return this->weapons;
}