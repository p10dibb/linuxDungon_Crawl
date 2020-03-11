#include "Player.h"
#include <cstdio>

string toLower(string s)
{
	string ret = "";
	for (int i = 0; i < s.length(); i++)
	{
		ret = ret + char(tolower(s[i]));
	}
	return ret;
}

//takes in a string and a array of strings and shows the position that that function is located, -1 if not contained
int getFunc(string str, string options[], int size)
{

	for (int i = 0; i < size; i++)
	{
		if (options[i] == str)
		{
			return i;
		}
	}
	//if not in options
	return -1;
}

//inputs a damage amount , damage type, and resistances and reduces damage to the proper damage
int ReduceDamage(int damage, DamageTypes_enum damageTypes, vector<ActiveEffects> resistances)
{
	ActiveEffects temp;
	//cout<<"Entering reduceDamage"<<endl;
	//cout<<"Resistance Size: "<<resistances.Size()<<endl;
	for (int i = 0; i < resistances.size(); i++)
	{
		//cout<<"---------------"<<i<<"------------"<<endl;
		temp = resistances[i];
		//cout<<"i: "<<i<<temp.getEffectName()<<endl;
		if (temp.getEffect() == FireResistance_Effects && damageTypes == Fire_DamageType)
		{
			damage = (damage * (100 - temp.getResistance()) / 100);
		}
		else if (temp.getEffect() == StabbingResistance_Effects && damageTypes == Stabbing_DamageType)
		{
			damage = (damage * (100 - temp.getResistance()) / 100);
		}
		else if (temp.getEffect() == BluntResistance_Effects && damageTypes == Blunt_DamageType)
		{
			damage = (damage * (100 - temp.getResistance()) / 100);
		}
		else if (temp.getEffect() == StabbingResistance_Effects && damageTypes == Stabbing_DamageType)
		{
			damage = (damage * (100 - temp.getResistance()) / 100);
		}

		else if (temp.getEffect() == NormalResistance_Effects && damageTypes == Normal_DamageType)
		{

			damage = (damage * (100 - temp.getResistance()) / 100);
		}

		else if (temp.getEffect() == NormalResistance_Effects && damageTypes == Critical_DamageType)
		{
			damage = (damage * (100 - temp.getResistance()) / 100);
		}
		else if (temp.getEffect() == PoisonResistance_Effects && damageTypes == Poison_DamageType)
		{
			damage = (damage * (100 - temp.getResistance()) / 100);
		}
	}

	return damage;
}

//Default constructor
Player::Player()
{
	Biped();

	this->setDamage(3);
	this->setSpeed(3);
	this->setDefense(3);
	this->setStamina(3);
	this->setStrength(3);

	this->Right = new Weapon();
	this->Right->setName("Fist");
	this->Left = new Weapon();
	this->Left->setName("Fist");

	this->FreeSlots = 40;

	this->InventorySize = 40;

	this->LevelUp = 10;
	this->Money = 0;
	this->MaxWeight = 50;
	this->CurrentWeight = 0;
	this->OverWeighted = false;

	this->LevelUp = 10;
	this->Inventory;

	for (int i = 0; i < this->inventoryMax; i++)
	{
		this->Inventory[i].item = new Item();
	}
}

int Player::PauseMenue()
{

	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");

	sf::RenderWindow window(sf::VideoMode(800, 800), "Pause");

	sf::Text headerText("Pause Menu", font, 50);
	headerText.setPosition(sf::Vector2f(10, 10));

	sf::Text choiceText("[1]:Resume\n[2]:Inventory\n[3]:Stats\n[4]:Equipped\n[5]:Save\n[6]:Exit Game", font, 30);
	choiceText.setPosition(sf::Vector2f(10, 60));

	int choice = 0;

	int ret;

	bool release = false;

	int func = -2;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(headerText);
		window.draw(choiceText);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			choice = 1;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			choice = 2;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			choice = 3;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			choice = 4;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			choice = 5;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			choice = 6;
			release = true;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			choice = 1;
			release = true;
		}
		else if (release)
		{
			switch (choice)
			{

			case 1:
				ret = 0;
				window.close();
				break;

			case 2:
				this->InventoryDialogue();
				break;
			case 3:
				this->DisplayStats();
				break;
			case 4:
				this->EquipedDialogue();
				break;
			case 5:
				cout << "saving" << endl;
				window.close();
				ret = -4;
				break;
			case 6:
				cout << "Exiting" << endl;
				ret = -3;
				window.close();
			}
			release = false;
		}
	}
	return ret;
}

//Displays all data for character
void Player::DisplayDetails()
{
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
int Player::ActualSpeed()
{
	int speed = 0;
	int ArmorWeight = this->getHead()->getWeight() + this->getTorso()->getWeight() + this->getHands()->getWeight() + this->getLegs()->getWeight() + this->getFeet()->getWeight();

	//if onehanded else dual wielding
	if (this->Left->getType() == NULL_WeaponType && this->Right->getType() == NULL_WeaponType)
	{
		speed = (int)(this->getSpeed() - (ArmorWeight / (double)(this->getStrength() / (double)2)));
	}
	else if (this->Left->getType() == NULL_WeaponType)
	{

		speed = (int)(this->getSpeed() + this->Right->getSpeed() - (ArmorWeight / (double)(this->getStrength() / (double)2)));
	}
	else if (this->Right->getType() == NULL_WeaponType)
	{

		speed = (int)(this->getSpeed() + this->Left->getSpeed() - (ArmorWeight / (double)(this->getStrength() / (double)2)));
	}
	else
	{
		//two weapons being used 2/3 the speed of both weapons added together so dual wielding is slower but has higher attack and defense
		speed = (this->getSpeed() + ((this->Left->getSpeed() + this->Right->getSpeed()) / 3) - (ArmorWeight / (double)(this->getStrength() / (double)2)));
	}

	//if slwed effect is active then decrease speed by 25%
	if (this->ContainDeBuffEffect(Slowed_Effects))
	{
		speed = speed * .75;
	}
	if (this->ContainDeBuffEffect(Dazed_Effects))
	{
		speed = speed * .75;
	}
	if (this->ContainCombatEffect(QuickStrike_Effects))
	{
		speed = speed * 1.25;
	}
	if (this->ContainCombatEffect(AnimalFury_Effects))
	{
		speed = speed * 1.25;
	}
	if (this->ContainCombatEffect(DefensiveStance_Effects))
	{
		speed = speed * .75;
	}
	if (this->ContainCombatEffect(Swordsman_Effects))
	{
		speed = speed * .75;
	}
	//cuts speed in half if overweighted
	if (this->OverWeighted)
	{
		speed = speed * .5;
	}
	//minimum speed is 1
	if (speed < 1)
	{
		speed = 1;
	}
	return speed;
}

//player recieves lootdrop from enemy
void Player::RecieveLootDrop(lootDrop loot)
{
	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");
	sf::RenderWindow window(sf::VideoMode(500, 500), "Recieve Loot Drop");

	sf::Text RecieveText("", font, 30);
	RecieveText.setPosition(sf::Vector2f(10, 10));

	sf::Text CommandText("[Esc]: Exit", font, 30);
	CommandText.setPosition(10, 250);

	string recieve = "You Recieved:\nXP: " + to_string(loot.xp) + "\n";
	this->setXP(this->getXP() + loot.xp);

	bool release = false;

	if (loot.gold != 0)
	{
		recieve += "Gold: " + to_string(loot.gold) + "\n";
		this->RecieveMoney(loot.gold);
	}

	if (loot.weapon != NULL)
	{
		recieve += "Weapon: " + loot.weapon->getName() + "\n";
		this->addToInventory(loot.weapon);
	}

	if (loot.armour != NULL)
	{
		recieve += "Armor: " + loot.armour->getName() + "\n";
		this->addToInventory(loot.armour);
	}

	if (loot.potion != NULL)
	{
		recieve += "Potion: " + loot.potion->getName();
		this->addToInventory(loot.potion);
	}

	RecieveText.setString(recieve);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(RecieveText);
		window.draw(CommandText);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			release = true;
		}
		else if (release)
		{
			window.close();
		}
	}

	if (this->getXP() >= this->getLevelUp())
	{
		this->NextLevel();
	}
}

void Player::addSkillPoint()
{

	int release = 0;
	int currentChoice = -1;

	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");
	sf::RenderWindow window(sf::VideoMode(600, 400), "create Character");
	sf::Text headerText("#\tstat\tcurrent level\tDescription", font, 20);
	headerText.setPosition(sf::Vector2f(10, 10));
	sf::Text MaxHealthText("1\tMaxHealth\t" + to_string(this->getMaxHealth()) + "\tMaximum Health of the player", font, 20);
	MaxHealthText.setPosition(sf::Vector2f(10, 40));
	sf::Text StrengthText("2\tStrength\t" + to_string(this->getStrength()) + "\tIncreases Carrying capacity and lessens handicap of speed for heavy armour", font, 20);
	StrengthText.setPosition(sf::Vector2f(10, 70));
	sf::Text SpeedText("3\tSpeed\t" + to_string(this->getSpeed()) + "\tIncreases speed in combat", font, 20);
	SpeedText.setPosition(sf::Vector2f(10, 100));
	sf::Text AttackText("4\tBase Attack\t" + to_string(this->getDamage()) + "\tIncreases Base Damage", font, 20);
	AttackText.setPosition(sf::Vector2f(10, 130));
	sf::Text DefenseText("5\tBase Defense\t" + to_string(this->getDefense()) + "\tIncreases Base Defense", font, 20);
	DefenseText.setPosition(sf::Vector2f(10, 160));
	sf::Text StaminaText("6\tStamina\t" + to_string(this->getStamina()) + "\thow many steps per move cycle", font, 20);
	StaminaText.setPosition(sf::Vector2f(10, 190));

	// string options[10]={"1","2","3","4","5","6"};

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(headerText);
		window.draw(MaxHealthText);
		window.draw(StrengthText);
		window.draw(SpeedText);
		window.draw(AttackText);
		window.draw(DefenseText);
		window.draw(StaminaText);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			currentChoice = 1;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			currentChoice = 2;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			currentChoice = 3;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			currentChoice = 4;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			currentChoice = 5;
			release = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			currentChoice = 6;
			release = 1;
		}
		else if (release == 1)
		{

			switch (currentChoice)
			{
			case 1:
				this->setMaxHealth(this->getMaxHealth() + 10);
				this->setHealth(this->getMaxHealth());
				break;
			case 2:
				this->setStrength(this->getStrength() + 1);
				this->MaxWeight = this->getStrength() * 10;
				this->setOverWeighted(this->MaxWeight < this->CurrentWeight);
				break;
			case 3:
				this->setSpeed(this->getSpeed() + 1);
				break;
			case 4:
				this->setDamage(this->getDamage() + 1);
				break;
			case 5:
				this->setDefense(this->getDefense() + 1);
				break;
			case 6:
				this->setStamina(this->getStamina() + 1);
				break;
			}
			release = 0;

			window.close();
		}
	}
}

//level up dialogue for player
void Player::NextLevel()
{
	int points = 3;
	int input = 0;

	this->setLevel(this->getLevel() + 1);
	this->setMaxHealth(this->getMaxHealth() + 10);
	this->setHealth(this->getMaxHealth());

	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");

	sf::RenderWindow window(sf::VideoMode(800, 800), "Level Up");

	sf::Text headerText("Congrats you leveled up!!", font, 50);
	headerText.setPosition(sf::Vector2f(10, 10));

	sf::Text maxHealthText("Max Health is now: " + to_string(this->getMaxHealth()), font, 30);
	maxHealthText.setPosition(sf::Vector2f(10, 60));

	sf::Text pointsRemainingText("you have " + to_string(points) + " remaining", font, 30);
	pointsRemainingText.setPosition(sf::Vector2f(10, 90));

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(headerText);
		window.draw(maxHealthText);
		window.draw(pointsRemainingText);
		window.display();

		if (points <= 0)
		{
			window.close();
		}
		else
		{
			this->addSkillPoint();
			points--;
			pointsRemainingText.setString("you have " + to_string(points) + " remaining");
		}
	}

	this->setLevelUp(this->getLevelUp() * 2);
}

//0=left,1=up,2=right, 3=down
int Player::move(array<array<RoomPieces_enum, 50>, 50> map, int direction)
{

	//Left
	if (direction == 0 && map[this->getPosition()[0]][this->getPosition()[1] - 1] != Wall_RoomPieces)
	{

		this->setPosition({this->getPosition()[0], this->getPosition()[1] - 1});
	}
	//Right
	else if (direction == 2 && map[this->getPosition()[0]][this->getPosition()[1] + 1] != Wall_RoomPieces)
	{

		this->setPosition({this->getPosition()[0], this->getPosition()[1] + 1});
	}
	//Down
	else if (direction == 3 && map[this->getPosition()[0] + 1][this->getPosition()[1]] != Wall_RoomPieces)
	{

		this->setPosition({this->getPosition()[0] + 1, this->getPosition()[1]});
	}
	//Up
	else if (direction == 1 && map[this->getPosition()[0] - 1][this->getPosition()[1]] != Wall_RoomPieces)
	{

		this->setPosition({this->getPosition()[0] - 1, this->getPosition()[1]});
	}
	return 0;
}

int Player::Navigation(array<array<RoomPieces_enum, 50>, 50> map)
{

	int choice = -1;

	bool release = false;
	while (1)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			choice = 0;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			choice = 1;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			choice = 2;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			choice = 3;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			choice = 4;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			choice = 5;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			choice = 6;
			release = true;
		}
		else if (release)
		{
			switch (choice)
			{
			case 0:
				this->move(map, 0);
				return 0;
			case 1:
				this->move(map, 1);
				return 0;
			case 2:
				this->move(map, 2);
				return 0;
			case 3:
				this->move(map, 3);
				return 0;
			case 4:
				this->InventoryDialogue();
				break;
			case 5:
				this->EquipedDialogue();
				break;
			case 6:
				return this->PauseMenue();

			default:
				break;
			}
			release = false;
		}
	}
}

//gets all damage types from variouse weapons
vector<DamageTypes> Player::getAllDamageTypes()
{
	vector<DamageTypes> ret, ret2, temp;
	//adds base Damage;
	ret.push_back(DamageTypes(this->getDamage()));
	int i = 0;

	//gets all Damage types from right weapon
	temp = this->getRight()->getDamageTypes_Weapon();
	for (i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}
	//gets all Damage types from left weapon
	temp = this->getLeft()->getDamageTypes_Weapon();
	for (i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}

	int location = -1;
	//if no damage booster
	if (location = this->ContainBuffEffect(DamageBoost_Effects))
	{

		//gets the multiplier
		int DamageMultiplier = this->getBuffEffect(DamageBoost_Effects).getMultiplier();
		//new Linkedlist

		DamageTypes cur;
		for (int i = 0; i < ret.size(); i++)
		{
			cur = ret[i];
			ret2.push_back(DamageTypes(cur.getDamage() * DamageMultiplier, cur.getProbability(), cur.getType(), cur.getIsDamageOverTime(), cur.getDamageOverTime_damage(), cur.getDamageOverTime_time()));
		}
		ret = ret2;
		ret2.clear();
	}
	//if bezerk effect is active
	if (location = this->ContainBuffEffect(Bezerk_Effects))
	{

		//gets the multiplier
		int DamageMultiplier = this->getBuffEffect(Bezerk_Effects).getMultiplier();
		//new Linkedlist

		DamageTypes cur;
		for (int i = 0; i < ret.size(); i++)
		{
			cur = ret[i];
			ret2.push_back(DamageTypes(cur.getDamage() * 1.25, cur.getProbability(), cur.getType(), cur.getIsDamageOverTime(), cur.getDamageOverTime_damage(), cur.getDamageOverTime_time()));
		}
		ret = ret2;
		ret2.clear();
	}
	//if swordsman effect is active
	if (location = this->ContainBuffEffect(Swordsman_Effects))
	{

		//gets the multiplier
		int DamageMultiplier = this->getBuffEffect(Swordsman_Effects).getMultiplier();
		//new Linkedlist

		DamageTypes cur;
		for (int i = 0; i < ret.size(); i++)
		{
			cur = ret[i];
			ret2.push_back(DamageTypes(cur.getDamage() * 1.15, cur.getProbability(), cur.getType(), cur.getIsDamageOverTime(), cur.getDamageOverTime_damage(), cur.getDamageOverTime_time()));
		}
		ret = ret2;
		ret2.clear();
	}

	return ret;
}

//Gets all Resistance types
vector<ActiveEffects> Player::getAllResistanceTypes()
{
	vector<ActiveEffects> ret;
	vector<ActiveEffects> temp;
	ActiveEffects tempEffect;
	int tempResistance;
	int i;

	//Resistance effects Map

	int x = 0;
	if (!this->getResistanceEffects().empty())
	{
		map<Effects_enum, ActiveEffects>::const_iterator it = this->getResistanceEffects().begin();
		while (it != this->getResistanceEffects().end())
		{

			ActiveEffects a = it->second;

			ret.push_back(a);
			it++;
		}
	}

	//takes current defense stat and converts to an active effect
	ret.push_back(ActiveEffects(Resistance_EffectTypes, NormalResistance_Effects, this->getDefense(), 10));

	//Weapons
	ret.push_back(this->Right->getDefense());
	ret.push_back(this->Left->getDefense());

	//Armor pieces
	//Head
	temp = this->getHead()->getResistanceTypes();
	for (i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}
	//Torso
	temp = this->getTorso()->getResistanceTypes();
	for (i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}
	//Feet
	temp = this->getFeet()->getResistanceTypes();
	for (i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}
	//Legs
	temp = this->getLegs()->getResistanceTypes();
	for (i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}
	//Hands
	temp = this->getHands()->getResistanceTypes();
	for (i = 0; i < temp.size(); i++)
	{
		ret.push_back(temp[i]);
	}

	//multipliers

	//defensive stance
	if (this->ContainCombatEffect(DefensiveStance_Effects))
	{
		temp.clear();
		for (i = 0; i < ret.size(); i++)
		{

			tempEffect = ret[i];
			tempResistance = tempEffect.getResistance() * 1.25;
			temp.push_back(ActiveEffects(tempEffect.getEffectType(), tempEffect.getEffect(), tempResistance, tempEffect.getRound()));
		}
		ret = temp;
	}

	//quick strike
	if (this->ContainCombatEffect(QuickStrike_Effects))
	{
		temp.clear();
		for (i = 0; i < ret.size(); i++)
		{
			tempEffect = ret[i];
			tempResistance = tempEffect.getResistance() * .75;
			temp.push_back(ActiveEffects(tempEffect.getEffectType(), tempEffect.getEffect(), tempResistance, tempEffect.getRound()));
		}
		ret = temp;
	}

	//Animal Fury
	if (this->ContainCombatEffect(AnimalFury_Effects))
	{
		temp.clear();
		for (i = 0; i < ret.size(); i++)
		{
			tempEffect = ret[i];

			tempResistance = tempEffect.getResistance() * .75;
			temp.push_back(ActiveEffects(tempEffect.getEffectType(), tempEffect.getEffect(), tempResistance, tempEffect.getRound()));
		}
		ret = temp;
	}

	//Bezerk Effect
	if (this->ContainCombatEffect(Bezerk_Effects))
	{
		temp.clear();
		for (i = 0; i < ret.size(); i++)
		{
			tempEffect = ret[i];
			tempResistance = tempEffect.getResistance() * .75;

			temp.push_back(ActiveEffects(tempEffect.getEffectType(), tempEffect.getEffect(), tempResistance, tempEffect.getRound()));
		}
		ret = temp;
	}
	//Swordsman effect
	if (this->ContainCombatEffect(Swordsman_Effects))
	{
		temp.clear();
		for (i = 0; i < ret.size(); i++)
		{
			tempEffect = ret[i];
			tempResistance = tempEffect.getResistance() * 1.15;
			temp.push_back(ActiveEffects(tempEffect.getEffectType(), tempEffect.getEffect(), tempResistance, tempEffect.getRound()));
		}
		ret = temp;
	}
	return ret;
}

//recieves a linked list of damage types and and runs through the damage taken
int Player::TakeDamage(vector<DamageTypes> damageTypes)
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

//checks if money is > amount and subtracts from there and returns amount;
int Player::GiveMoney(int amount)
{
	if (amount < 0)
	{
		return 0;
	}
	else if (this->getMoney() > amount)
	{
		this->setMoney(this->getMoney() - amount);
		this->IncrementGoldSpent(amount);
		return amount;
	}

	return 0;
}

//adds amount to money; can only be positive
bool Player::RecieveMoney(int amount)
{
	if (amount < 0)
	{
		return false;
	}
	this->IncrementGoldCollected(amount);
	this->setMoney(this->getMoney() + amount);

	this->RewardCheckMaxGoldHeld();
	return true;
}