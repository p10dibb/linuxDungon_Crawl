#include "Player.h"

//adds an Item to the players inventory;
bool Player::addToInventory(Item *i)
{

	//stats incrementer

	cout<<"Free slots: "<<this->FreeSlots<<endl;
	cout<<"item name: "<<i->getName()<<endl;
	this->IncrementItemsRecieved();
	if (FreeSlots > 0)
	{

		//checks if there is already a stack of said item and if there is room in the stack for another one
		for (int j = 0; j < this->getInventorySize(); j++)
		{

			//checks if names are same then if max stack size is reached
			if ((*this->Inventory[j].item).getName() == i->getName() && (*this->Inventory[j].item).getStackSize() > this->Inventory[j].amount)
			{
				this->Inventory[j].amount += 1;

				this->setCurrentWeight(this->getCurrentWeight() + i->getWeight());

				this->setOverWeighted(this->getMaxWeight() < this->getCurrentWeight());

				return true;
			}
		}
		//if not already a stack find next empty slot and add new stack
		for (int k = 0; k < this->getInventorySize(); k++)
		{
			// cout<<"slot "<<k<<" amount: "<<this->Inventory[k].amount<<endl;
			//checks if inventory slot is empty
			if (this->Inventory[k].amount == 0)
			{
				this->Inventory[k].amount = 1;
				this->Inventory[k].item = i;
				this->setCurrentWeight(this->getCurrentWeight() + i->getWeight());
				this->setOverWeighted(this->getMaxWeight() < this->getCurrentWeight());
				this->setFreeSlots(this->getFreeSlots() - 1);
				return true;
			}
		}
	}
	else
	{
		cout << "inventory Full" << endl;
		return false;
	}

	return false;
}

//Removes an item from specified position
Item *Player::RemoveItemFromInventory(int pos)
{
	if (pos > this->InventorySize || pos < 0)
	{
		Item *fail = new Item();
		return fail;
	}
	Item *temp = this->Inventory[pos].item;
	this->Inventory[pos].amount--;
	if (this->Inventory[pos].amount <= 0)
	{
		this->Inventory[pos].item = new Item();
		this->Inventory[pos].amount = 0;
	this->FreeSlots++;

	}
	this->setCurrentWeight(this->getCurrentWeight() - temp->getWeight());
	this->setOverWeighted(this->getMaxWeight() < this->getCurrentWeight());

	return temp;
}

//Displays whole inventory
void Player::DisplayInventory()
{
	cout << "#\tItemName\tamount\t" << endl;
	for (int i = 0; i < this->InventorySize; i++)
	{
		cout << i << "\t" << this->Inventory[i].item->getName() << "\t" << this->Inventory[i].amount << "" << endl;
	}
}

//Displays inventory and all of the options
int Player::InventoryDialogue()
{
	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");

	sf::RenderWindow window(sf::VideoMode(800, 800), "Inventory");

	sf::Text headerText("Inventory", font, 30);
	headerText.setPosition(sf::Vector2f(10, 10));

	//inventory slots shapes
	array<sf::RectangleShape, 100> slots;

	//marks which item is selected
	sf::RectangleShape highlighter;

	//box holding Items details
	sf::RectangleShape DisplayBox;
	DisplayBox.setSize(sf::Vector2f(300, 500));
	DisplayBox.setPosition(sf::Vector2f(450, 50));
	DisplayBox.setFillColor(sf::Color::Blue);

	//name of the item
	sf::Text itemNameText("Name: ", font, 30);
	itemNameText.setPosition(sf::Vector2f(460, 60));

	//info tags of each item
	sf::Text itemInfo("", font, 20);
	itemInfo.setPosition(sf::Vector2f(460, 100));

	//values corolating to each tag
	sf::Text itemValues("", font, 20);
	itemValues.setPosition(sf::Vector2f(590, 100));

	//the description of the item
	sf::Text itemDescription("", font, 20);

	//the text for extra info
	sf::Text otherInfoText("", font, 20);

	//Shows availible commands
	sf::Text commandsText("[1]:Use\t\t[2]:exit", font, 20);
	commandsText.setPosition(sf::Vector2f(450, 570));

	//current slot selected
	int cur = 0;

	//choice for commands
	int choice = -1;

	//checks for key release
	bool release = true;

	//if item is equipable
	bool equipable = false;

	//if item is useable
	bool useable = false;

	//direction for selector to use
	Direction_enum direct = No_Direction;

	//sets all of the item slots
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			slots[(i * 10) + j].setSize(sf::Vector2f(30, 30));
			slots[(i * 10) + j].setFillColor(sf::Color::Blue);
			slots[(i * 10) + j].setPosition(sf::Vector2f(10 + (42 * j), 50 + (42 * i)));
		}
	}

	highlighter.setFillColor(sf::Color::Cyan);
	highlighter.setSize(sf::Vector2f(40, 40));
	highlighter.setPosition(sf::Vector2f(slots[cur].getPosition().x - 5, slots[cur].getPosition().y - 5));

	//main loop
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
		window.draw(highlighter);
		window.draw(DisplayBox);
		window.draw(itemNameText);
		window.draw(itemInfo);
		window.draw(itemValues);
		window.draw(itemDescription);
		window.draw(commandsText);
		window.draw(otherInfoText);
		for (int k = 0; k < this->InventorySize; k++)
		{
			window.draw(slots[k]);
		}
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			release = true;
			direct = Up_Direction;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			release = true;
			direct = Down_Direction;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			release = true;
			direct = Right_Direction;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			release = true;
			direct = Left_Direction;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			choice = 1;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			choice = 2;
			release = true;
		}
		else if (release)
		{

			//if try to equip or use item
			if (choice == 1)
			{

				choice = -1;

				if (equipable)
				{
					this->EquipInventory(cur);
				}
				else if (useable)
				{
					this->UseInventory(cur);
				}
				else
				{
					//normal item
				}
			}
			//if exit the inventory
			else if (choice == 2)
			{

				choice = -1;
				window.close();
			}

			//checks for moving through inventory
			if (direct == Up_Direction && cur >= 10)
			{
				cur -= 10;
			}
			else if (direct == Down_Direction && cur <= this->InventorySize - 11)
			{
				cur += 10;
			}
			else if (direct == Left_Direction && cur != 0)
			{
				cur--;
			}
			else if (direct == Right_Direction && cur < InventorySize - 1)
			{
				cur++;
			}
			itemNameText.setString(this->Inventory[cur].item->getName());

			//displays correct data depending item type
			if ((typeid(*this->Inventory[cur].item) == typeid(Armor)))
			{
				Armor *a = dynamic_cast<Armor *>(this->Inventory[cur].item);
				equipable = true;
				useable = false;
				itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nClass:\nType:\n");
				itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getTotalResistance()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + armorClass_toString(a->getClass()) + "\n" + armorType_toString(a->getType()));
				itemDescription.setPosition(sf::Vector2f(460, 250));
				itemDescription.setString(a->getDescription());
				commandsText.setString("[1]:Equip\t\t[2]:Exit");

				string resistances = "Resistances:\n";
				vector<ActiveEffects> temp = a->getResistanceTypes();

				for (int g = 0; g < temp.size(); g++)
				{

					if (temp[g].getResistance() > 0)
					{
						resistances += temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
					}
				}

				otherInfoText.setString(resistances);

				otherInfoText.setPosition(sf::Vector2f(460, 280));
			}
			else if ((typeid(*this->Inventory[cur].item) == typeid(Weapon)))
			{
				Weapon *a = dynamic_cast<Weapon *>(this->Inventory[cur].item);

				equipable = true;
				useable = false;

				itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nDefense:\nSpeed:\nRarity:\nEffect:\n");
				itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getWeaponRank()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + to_string(a->getDefense().getResistance()) + "\n" + to_string(a->getSpeed()) + "\n" + a->getRarity_text() + "\n" + a->getCombatEffect().getEffectName());

				itemDescription.setPosition(sf::Vector2f(460, 300));
				itemDescription.setString(a->getDescription());
				commandsText.setString("[1]:Equip\t\t[2]:Exit");

				string damages = "Damage Types:\n";
				vector<DamageTypes> temp = a->getDamageTypes_Weapon();

				for (int g = 0; g < temp.size(); g++)
				{

					if (temp[g].getDamage() > 0)
					{
						damages += temp[g].getName() + "\t" + to_string(temp[g].getDamage()) + "\n";
					}
				}

				otherInfoText.setString(damages);

				otherInfoText.setPosition(sf::Vector2f(460, 330));
			}
			else if ((typeid(*this->Inventory[cur].item) == typeid(Potion)))
			{
				Potion *a = dynamic_cast<Potion *>(this->Inventory[cur].item);

				equipable = false;
				useable = true;

				itemInfo.setString("Amount:\nValue:\nTier:\nType:");
				itemValues.setString(to_string(this->Inventory[cur].amount) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getTier()) + "\n" + a->getTypeName());
				itemDescription.setPosition(sf::Vector2f(460, 200));
				itemDescription.setString(a->getDescription());
				otherInfoText.setString("");

				commandsText.setString("[1]:Use\t\t[2]:Exit");
			}
			else if (this->Inventory[cur].item->getName() == "Empty")
			{
				equipable = false;
				useable = false;

				itemInfo.setString("");
				itemValues.setString("");
				itemDescription.setString("");
				otherInfoText.setString("");
				commandsText.setString("\t\t[2]:Exit");
			}
			else
			{
				equipable = false;
				useable = false;
				itemNameText.setString(Inventory[cur].item->getName());
				itemInfo.setString("");
				itemValues.setString("");
				itemDescription.setString("");
				otherInfoText.setString("");
				commandsText.setString("\t\t[2]:Exit");
				//normal item
			}

			release = false;
			direct = No_Direction;
			highlighter.setPosition(sf::Vector2f(slots[cur].getPosition().x - 5, slots[cur].getPosition().y - 5));
		}
	}
}

//takes a string and returns a number corelating to the functions name
int Player::getFuncInventory(string s)
{
	array<string, 5> functions = {"view", "equip", "use", "move", "exit"};

	for (int i = 0; i < functions.size(); i++)
	{
		if (functions[i] == s)
		{
			return i;
		}
	}
	return -1;
}

//gets item from inventory slot checks its type and displays info
int Player::ViewInventory(int pos)
{

	if (this->Inventory[pos].amount == 0)
	{
		cout << "Slot " << pos << " is empty" << endl;
		return -1;
	}
	else
	{
		if (typeid(*this->Inventory[pos].item) == typeid(Weapon))
		{

			Weapon *w = dynamic_cast<Weapon *>(this->Inventory[pos].item);
			w->DisplayDetails();
		}
		else if ((typeid(*this->Inventory[pos].item) == typeid(Armor)))
		{
			Armor *a = dynamic_cast<Armor *>(this->Inventory[pos].item);
			a->DisplayDetails();
		}
		else if ((typeid(*this->Inventory[pos].item) == typeid(Potion)))
		{
			Potion *a = dynamic_cast<Potion *>(this->Inventory[pos].item);
			a->DisplayDetails();
		}
		getchar();
		getchar();

		return 0;
	}
}

// equips an item from inventory
int Player::EquipInventory(int pos)
{
	bool error = false;

	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");

	if (typeid(*this->Inventory[pos].item) == typeid(Weapon))
	{
		// this->DisplayEquiped();
		Weapon *w = dynamic_cast<Weapon *>(this->Inventory[pos].item);
		int input = 0;

		bool release = false;

		sf::RenderWindow weaponWindow(sf::VideoMode(800, 800), "Weapon Equip");

		sf::Text options("Would you like to Equip in\n[1]:Left\t[2]:Right", font, 30);
		options.setPosition(sf::Vector2f(10, 10));

		while (weaponWindow.isOpen())
		{

			sf::Event event1;
			while (weaponWindow.pollEvent(event1))
			{
				if (event1.type == sf::Event::Closed)
				{
					weaponWindow.close();
				}
			}
			weaponWindow.clear();

			weaponWindow.draw(options);
			weaponWindow.display();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				input = 1;

				release = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				input = 2;

				release = true;
			}
			else if (release)
			{
				switch (input)
				{
				case 1:
					this->Inventory[pos].item = this->Right;
					if (!this->setRight(w))
					{
						error = true;
						this->Inventory[pos].item = w;
					}
					weaponWindow.close();
					break;

				case 2:

					this->Inventory[pos].item = this->Left;
					if (!this->setLeft(w))
					{
						error = true;
						this->Inventory[pos].item = w;
					}
					weaponWindow.close();
					break;

				default:
					break;
				}
			}
		}
	}
	else if ((typeid(*this->Inventory[pos].item) == typeid(Armor)))
	{

		Armor *a = dynamic_cast<Armor *>(this->Inventory[pos].item);
		// cout << "armour type for equip: " << a->getType() << endl;

		if (a->getType() == Helmet_ArmorType)
		{
			this->Inventory[pos].item = this->getHead();
			if (!this->setHead(a))
			{
				error = true;
				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Chest_ArmorType)
		{
			this->Inventory[pos].item = this->getTorso();
			if (!this->setTorso(a))
			{
				error = true;

				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Gloves_ArmorType)
		{
			this->Inventory[pos].item = this->getHands();
			if (!this->setHands(a))
			{
				error = true;

				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Pants_ArmorType)
		{
			this->Inventory[pos].item = this->getLegs();
			if (!this->setLegs(a))
			{
				error = true;

				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Boots_ArmorType)
		{
			this->Inventory[pos].item = this->getFeet();
			if (!this->setFeet(a))
			{
				error = true;

				this->Inventory[pos].item = a;
			}
		}
	}

	if (error)
	{
		sf::RenderWindow errorWindow(sf::VideoMode(200, 200), "Failed To Equip");
		sf::Text errorText("Failed To Equip", font, 30);
		errorText.setPosition(sf::Vector2f(10, 10));

		while (errorWindow.isOpen())
		{

			sf::Event event2;
			while (errorWindow.pollEvent(event2))
			{
				if (event2.type == sf::Event::Closed)
				{
					errorWindow.close();
				}
			}
			errorWindow.clear();
			errorWindow.draw(errorText);
			errorWindow.display();
		}
	}

	return 0;
}

//use item in slot pos
int Player::UseInventory(int pos)
{
	//checker for if an item was used
	bool used = false;
	if (this->Inventory[pos].amount == 0)
	{
		cout << "slot " << to_string(pos) << "is empty" << endl;
		return -1;
	}
	if ((typeid(*this->Inventory[pos].item) == typeid(Potion)))
	{
		Potion *a = dynamic_cast<Potion *>(this->Inventory[pos].item);
		a->Use(this);
		this->IncrementPotionDranked();
		used = true;
	}
	else
	{
		cout << "not a useable item" << endl;
	}

	//decrements inventory
	if (used)
	{
		this->Inventory[pos].amount--;
		if (this->Inventory[pos].amount == 0)
		{
			this->Inventory[pos].item = new Item();
			this->FreeSlots++;
		}
	}

	return 0;
}

//Moves an item from one slot to another.
int Player::MoveInventory(int pos)
{
	if (this->Inventory[pos].amount == 0)
	{
		cout << "slot " << pos << "is empty" << endl;
		return -1;
	}
	int newPos = -1;
	InventorySlot temp = this->Inventory[pos];

	cout << "which slot would you like to move it to? :" << endl;
	cin >> newPos;
	cout << endl;

	if (newPos < 0 || newPos > this->InventorySize)
	{
		cout << newPos << " is not a valid position." << endl;
		return -1;
	}
	this->Inventory[pos] = this->Inventory[newPos];
	this->Inventory[newPos] = temp;

	return 0;
}

void Player::DisplayEquiped()
{

	cout << "\t" << this->getName() << endl;
	cout << "Health: " << this->getHealth() << "/" << this->getMaxHealth() << endl;
	cout << "Level: " << this->getLevel() << endl;
	cout << "XP: " << this->getXP() << "/" << this->getLevelUp() << endl;
	cout << "Gold: " << this->getMoney() << endl;

	cout << "Armor:" << endl;
	cout << "Head:\t" << this->getHead()->getName() << "\t"
		 << "Level: " << this->getHead()->getLevel() << endl;
	cout << "Torso:\t" << this->getTorso()->getName() << "\t"
		 << "Level: " << this->getTorso()->getLevel() << endl;
	cout << "Hands:\t" << this->getHands()->getName() << "\t"
		 << "Level: " << this->getHands()->getLevel() << endl;
	cout << "Legs:\t" << this->getLegs()->getName() << "\t"
		 << "Level: " << this->getLegs()->getLevel() << endl;
	cout << "Boots:\t" << this->getFeet()->getName() << "\t"
		 << "Level: " << this->getFeet()->getLevel() << endl;
	cout << endl
		 << "Weapons: " << endl;
	cout << "Right Hand:\t" << this->getRight()->getName() << "\tLevel: " << this->getRight()->getLevel() << endl;
	cout << "Left Hand:\t" << this->getLeft()->getName() << "\tLevel: " << this->getLeft()->getLevel() << endl;
}

int Player::EquipedDialogue()
{
	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");
	sf::RenderWindow window(sf::VideoMode(800, 800), "Equipped");

	sf::Text mainText(this->getName() + "\nHealth:" + to_string(this->getHealth()) + "/" + to_string(this->getMaxHealth()) + "\nLevel:" + to_string(this->getLevel()) + "\nXP:" + to_string(this->getXP()) + "/" + to_string(this->getLevelUp()) + "\nGold:" + to_string(this->getMoney()), font, 30);
	mainText.setPosition(200, 10);

	sf::RectangleShape HelmetPic(sf::Vector2f(30, 30));
	HelmetPic.setFillColor(sf::Color::Red);
	HelmetPic.setPosition(80, 110);

	sf::RectangleShape ChestPic(sf::Vector2f(90, 120));
	ChestPic.setFillColor(sf::Color::Blue);
	ChestPic.setPosition(50, 143);

	sf::RectangleShape GlovePicLeft(sf::Vector2f(20, 20));
	GlovePicLeft.setFillColor(sf::Color::Magenta);
	GlovePicLeft.setPosition(sf::Vector2f(27, 200));

	sf::RectangleShape GlovePicRight(sf::Vector2f(20, 20));
	GlovePicRight.setFillColor(sf::Color::Magenta);
	GlovePicRight.setPosition(sf::Vector2f(143, 200));

	sf::RectangleShape LegPic(sf::Vector2f(70, 110));
	LegPic.setFillColor(sf::Color::Cyan);
	LegPic.setPosition(sf::Vector2f(60, 276));

	sf::RectangleShape BootPic(sf::Vector2f(70, 50));
	BootPic.setFillColor(sf::Color::Green);
	BootPic.setPosition(sf::Vector2f(60, 389));

	sf::RectangleShape LeftWeaponPic(sf::Vector2f(40, 90));
	LeftWeaponPic.setFillColor(sf::Color::White);
	LeftWeaponPic.setPosition(sf::Vector2f(20, 10));

	sf::RectangleShape RightWeaponPic(sf::Vector2f(40, 90));
	RightWeaponPic.setFillColor(sf::Color::White);
	RightWeaponPic.setPosition(sf::Vector2f(130, 10));

	sf::RectangleShape highlighter(sf::Vector2f(200, 20));
	highlighter.setFillColor(sf::Color::Red);
	highlighter.setPosition(195, 195);

	sf::Text ChoiceText("[1]:Helmet\n[2]:Chest\n[3]:Gloves\n[4]:Pants\n[5]:Boots\n[6]:Left Weapon\n[7]:Right Weapon\n[8]:Exit", font, 20);
	ChoiceText.setPosition(sf::Vector2f(200, 190));

	sf::RectangleShape infoWindow(sf::Vector2f(300, 500));
	infoWindow.setFillColor(sf::Color::Blue);
	infoWindow.setPosition(sf::Vector2f(450, 30));

	//name of the item
	sf::Text itemNameText("Name: ", font, 30);
	itemNameText.setPosition(sf::Vector2f(460, 60));

	//info tags of each item
	sf::Text itemInfo("", font, 20);
	itemInfo.setPosition(sf::Vector2f(460, 100));

	//values corolating to each tag
	sf::Text itemValues("", font, 20);
	itemValues.setPosition(sf::Vector2f(590, 100));

	//the description of the item
	sf::Text itemDescription("", font, 20);

	//the text for extra info
	sf::Text otherInfoText("", font, 20);

	int choice = 1;

	Direction_enum direct = No_Direction;

	bool release = true;

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

		window.draw(mainText);
		window.draw(HelmetPic);
		window.draw(ChestPic);
		window.draw(LegPic);
		window.draw(BootPic);
		window.draw(GlovePicRight);
		window.draw(GlovePicLeft);
		window.draw(RightWeaponPic);
		window.draw(LeftWeaponPic);
		window.draw(highlighter);
		window.draw(ChoiceText);
		window.draw(infoWindow);
		window.draw(itemNameText);
		window.draw(itemValues);
		window.draw(itemInfo);
		window.draw(itemDescription);
		window.draw(otherInfoText);
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
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			choice = 7;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		{
			window.close();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			direct = Up_Direction;
			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			direct = Down_Direction;
			release = true;
		}
		else if (release)
		{
			vector<ActiveEffects> temp;
			vector<DamageTypes> temp2;

			string resistances = "Resistances:\n";

			if (direct == Up_Direction)
			{
				if (choice == 1)
				{
					choice = 7;
				}
				else
				{
					choice--;
				}
			}
			else if (direct == Down_Direction)
			{
				if (choice == 7)
				{
					choice = 1;
				}
				else
				{
					choice++;
				}
			}

			switch (choice)
			{
			case 1:
				temp = this->getHead()->getResistanceTypes();
				itemNameText.setString("Name: " + this->getHead()->getName());

				itemValues.setString(to_string(this->getHead()->getLevel()) + "\n" + to_string(this->getHead()->getTotalResistance()) + "\n" + to_string(this->getHead()->getValue()) + "\n" + to_string(this->getHead()->getWeight()) + "\n" + armorClass_toString(this->getHead()->getClass()) + "\n" + armorType_toString(this->getHead()->getType()));
				itemDescription.setPosition(sf::Vector2f(460, 250));
				itemDescription.setString(this->getHead()->getDescription());
				for (int g = 0; g < temp.size(); g++)
				{
					if (temp[g].getResistance() > 0)
					{
						resistances += "Resistances:\n" + temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
					}
				}

				otherInfoText.setString(resistances);

				otherInfoText.setPosition(sf::Vector2f(460, 280));

				break;
			case 2:
				temp = this->getTorso()->getResistanceTypes();
				itemNameText.setString("Name: " + this->getTorso()->getName());

				itemValues.setString(to_string(this->getTorso()->getLevel()) + "\n" + to_string(this->getTorso()->getTotalResistance()) + "\n" + to_string(this->getTorso()->getValue()) + "\n" + to_string(this->getTorso()->getWeight()) + "\n" + armorClass_toString(this->getTorso()->getClass()) + "\n" + armorType_toString(this->getTorso()->getType()));
				itemDescription.setPosition(sf::Vector2f(460, 250));
				itemDescription.setString(this->getTorso()->getDescription());
				for (int g = 0; g < temp.size(); g++)
				{
					if (temp[g].getResistance() > 0)
					{
						resistances += "Resistances:\n" + temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
					}
				}

				otherInfoText.setString(resistances);

				otherInfoText.setPosition(sf::Vector2f(460, 280));

				break;
			case 3:
				temp = this->getHands()->getResistanceTypes();
				itemNameText.setString("Name: " + this->getHands()->getName());

				itemValues.setString(to_string(this->getHands()->getLevel()) + "\n" + to_string(this->getHands()->getTotalResistance()) + "\n" + to_string(this->getHands()->getValue()) + "\n" + to_string(this->getHands()->getWeight()) + "\n" + armorClass_toString(this->getHands()->getClass()) + "\n" + armorType_toString(this->getHands()->getType()));
				itemDescription.setPosition(sf::Vector2f(460, 250));
				itemDescription.setString(this->getHands()->getDescription());
				for (int g = 0; g < temp.size(); g++)
				{
					if (temp[g].getResistance() > 0)
					{
						resistances += "Resistances:\n" + temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
					}
				}

				otherInfoText.setString(resistances);

				otherInfoText.setPosition(sf::Vector2f(460, 280));

				break;
			case 4:
				temp = this->getLegs()->getResistanceTypes();
				itemNameText.setString("Name: " + this->getLegs()->getName());

				itemValues.setString(to_string(this->getLegs()->getLevel()) + "\n" + to_string(this->getLegs()->getTotalResistance()) + "\n" + to_string(this->getLegs()->getValue()) + "\n" + to_string(this->getLegs()->getWeight()) + "\n" + armorClass_toString(this->getLegs()->getClass()) + "\n" + armorType_toString(this->getLegs()->getType()));
				itemDescription.setPosition(sf::Vector2f(460, 250));
				itemDescription.setString(this->getLegs()->getDescription());
				for (int g = 0; g < temp.size(); g++)
				{
					if (temp[g].getResistance() > 0)
					{
						resistances += "Resistances:\n" + temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
					}
				}

				otherInfoText.setString(resistances);

				otherInfoText.setPosition(sf::Vector2f(460, 280));

				break;
			case 5:
				temp = this->getFeet()->getResistanceTypes();
				itemNameText.setString("Name: " + this->getFeet()->getName());

				itemValues.setString(to_string(this->getFeet()->getLevel()) + "\n" + to_string(this->getFeet()->getTotalResistance()) + "\n" + to_string(this->getFeet()->getValue()) + "\n" + to_string(this->getFeet()->getWeight()) + "\n" + armorClass_toString(this->getFeet()->getClass()) + "\n" + armorType_toString(this->getFeet()->getType()));
				itemDescription.setPosition(sf::Vector2f(460, 250));
				itemDescription.setString(this->getFeet()->getDescription());
				for (int g = 0; g < temp.size(); g++)
				{
					if (temp[g].getResistance() > 0)
					{
						resistances += "Resistances:\n" + temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
					}
				}

				otherInfoText.setString(resistances);

				otherInfoText.setPosition(sf::Vector2f(460, 280));

				break;

			case 6:
				temp2 = this->getLeft()->getDamageTypes_Weapon();
				itemNameText.setString("Name: " + this->getLeft()->getName());
				itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nDefense:\nSpeed:\nRarity:\nEffect:\n");
				itemValues.setString(to_string(getLeft()->getLevel()) + "\n" + to_string(getLeft()->getWeaponRank()) + "\n" + to_string(getLeft()->getValue()) + "\n" + to_string(getLeft()->getWeight()) + "\n" + to_string(getLeft()->getDefense().getResistance()) + "\n" + to_string(getLeft()->getSpeed()) + "\n" + getLeft()->getRarity_text() + "\n" + getLeft()->getCombatEffect().getEffectName());

				itemDescription.setPosition(sf::Vector2f(460, 300));
				itemDescription.setString(getLeft()->getDescription());

				resistances = "Damage Types:\n";

				for (int g = 0; g < temp2.size(); g++)
				{

					if (temp2[g].getDamage() > 0)
					{
						resistances += temp2[g].getName() + "\t" + to_string(temp2[g].getDamage()) + "\n";
					}
				}

				otherInfoText.setString(resistances);

				otherInfoText.setPosition(sf::Vector2f(460, 330));
				break;

			case 7:
				temp2 = this->getRight()->getDamageTypes_Weapon();
				itemNameText.setString("Name: " + this->getRight()->getName());

				itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nDefense:\nSpeed:\nRarity:\nEffect:\n");
				itemValues.setString(to_string(getRight()->getLevel()) + "\n" + to_string(getRight()->getWeaponRank()) + "\n" + to_string(getRight()->getValue()) + "\n" + to_string(getRight()->getWeight()) + "\n" + to_string(getRight()->getDefense().getResistance()) + "\n" + to_string(getRight()->getSpeed()) + "\n" + getRight()->getRarity_text() + "\n" + getRight()->getCombatEffect().getEffectName());

				itemDescription.setPosition(sf::Vector2f(460, 300));
				itemDescription.setString(getRight()->getDescription());

				resistances = "Damage Types:\n";

				for (int g = 0; g < temp2.size(); g++)
				{

					if (temp2[g].getDamage() > 0)
					{
						resistances += temp2[g].getName() + "\t" + to_string(temp2[g].getDamage()) + "\n";
					}
				}

				otherInfoText.setString(resistances);

				otherInfoText.setPosition(sf::Vector2f(460, 330));
				break;

			default:
				break;
			}
			highlighter.setPosition(sf::Vector2f(195, 190 + 25 * (choice - 1)));
			release = false;
		}
	}
}

//takes a loot box and prompts the user to interact
bool Player::InteractLootBox(LootBox *box)
{
	sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");

	sf::RenderWindow window(sf::VideoMode(800, 800), "Loot Box");

	sf::RectangleShape infoWindow(sf::Vector2f(300, 500));
	infoWindow.setFillColor(sf::Color::Blue);
	infoWindow.setPosition(sf::Vector2f(450, 30));

	//name of the item
	sf::Text itemNameText("Name: ", font, 30);
	itemNameText.setPosition(sf::Vector2f(460, 60));

	//info tags of each item
	sf::Text itemInfo("", font, 20);
	itemInfo.setPosition(sf::Vector2f(460, 100));

	//values corolating to each tag
	sf::Text itemValues("", font, 20);
	itemValues.setPosition(sf::Vector2f(590, 100));

	//the description of the item
	sf::Text itemDescription("", font, 20);

	//the text for extra info
	sf::Text otherInfoText("", font, 20);

	sf::Text commands("[Space]:take selected [1]:Take All  [2]:Exit", font, 30);
	commands.setPosition(10, 400);

	sf::Text boxNameText("", font, 30);
	boxNameText.setPosition(sf::Vector2f(10, 10));
	boxNameText.setString(box->getName());

	sf::Text boxContents("", font, 30);
	boxContents.setPosition(sf::Vector2f(10, 40));

	sf::RectangleShape highlighter(sf::Vector2f(200, 30));
	highlighter.setFillColor(sf::Color::Red);
	highlighter.setPosition(sf::Vector2f(10, 40));

	string contentsString = "";

	int amount = 0;

	int current = 0;

	int choice = 0;

	bool release = true;

	Item *temp;

	Direction_enum direct = No_Direction;

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
		window.draw(infoWindow);
		window.draw(itemNameText);
		window.draw(itemValues);
		window.draw(itemInfo);
		window.draw(itemDescription);
		window.draw(otherInfoText);

		if (!box->isEmpty())
		{
			window.draw(highlighter);
		}
		window.draw(boxNameText);
		window.draw(boxContents);

		window.draw(commands);

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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{

			choice = 3;

			release = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			direct = Up_Direction;

			release = true;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			direct = Down_Direction;

			release = true;
		}
		else if (release)
		{

			switch (choice)
			{
			case 1:
				this->RecieveMoney(box->removeMoney(box->getMoney()));
				while (box->getLoot().size() > 0)
				{
					temp = box->removeItem(box->getLoot().size() -1 );
					//checks if remove Item fails
					if (temp->getName() != "Empty")
					{
						//checks if add to inventory fails
						if (!this->addToInventory(temp))
						{
							// if fails readd to box
							box->addItem(temp);
							break;
						}
					}
				}
				cout<<"exiting: "<<box->isEmpty() <<endl;
				break;
			case 2:
				window.close();
				break;
			case 3:
				if (box->getMoney() > 0 && current == 0)
				{
					this->RecieveMoney(box->removeMoney(box->getMoney()));
				}
				else if (box->getMoney() > 0)
				{
					temp = box->removeItem(current - 1);
					//checks if remove Item fails
					if (temp->getName() != "Empty")
					{
						//checks if add to inventory fails
						if (!this->addToInventory(temp))
						{
							// if fails readd to box
							box->addItem(temp);
							break;
						}
					}
					current--;
				}
				else
				{
					temp = box->removeItem(current);
					//checks if remove Item fails
					if (temp->getName() != "Empty")
					{
						//checks if add to inventory fails
						if (!this->addToInventory(temp))
						{
							// if fails readd to box
							box->addItem(temp);
							break;
						}
					}
					current--;
				}
				break;
			default:
				break;
			}
			if (box->getMoney() > 0 || box->getLoot().size() > 0)
			{
				switch (direct)
				{
				case Up_Direction:
					if (current > 0)
					{
						current--;
					}
					else
					{
						current = amount - 1;
					}
					break;
				case Down_Direction:
					if (current < amount - 1)
					{
						current++;
					}
					else
					{
						current = 0;
					}
					break;

				default:
					break;
				}
			}
			amount = 0;
			highlighter.setPosition(10, 45 + (37 * current));

			contentsString = "";
			if (box->getMoney() != 0)
			{
				contentsString += to_string(box->getMoney()) + " Gold\n";
				amount++;
			}
			if (box->getLoot().size() > 0)
			{
				for (int i = 0; i < box->getLoot().size(); i++)
				{
					amount++;
					contentsString += to_string(box->getLoot()[i].amount) + " " + box->getLoot()[i].item->getName() + "\n";
				}
			}

			boxContents.setString(contentsString);

			if (box->getMoney() > 0)
			{
				//displays correct data depending item type
				if(current==0){
						itemInfo.setString("Gold: "+to_string(box->getMoney()));
					itemValues.setString("");
					itemDescription.setString("");
					otherInfoText.setString("");
				
				}else if ((typeid(*box->getLoot()[current-1].item) == typeid(Armor)))
				{
					Armor *a = dynamic_cast<Armor *>(box->getLoot()[current-1].item);
					itemNameText.setString(a->getName());
					itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nClass:\nType:\n");
					itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getTotalResistance()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + armorClass_toString(a->getClass()) + "\n" + armorType_toString(a->getType()));
					itemDescription.setPosition(sf::Vector2f(460, 250));
					itemDescription.setString(a->getDescription());

					string resistances = "Resistances:\n";
					vector<ActiveEffects> temp = a->getResistanceTypes();

					for (int g = 0; g < temp.size(); g++)
					{

						if (temp[g].getResistance() > 0)
						{
							resistances += temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
						}
					}

					otherInfoText.setString(resistances);

					otherInfoText.setPosition(sf::Vector2f(460, 280));
				}
				else if ((typeid(*box->getLoot()[current-1].item) == typeid(Weapon)))
				{
					Weapon *a = dynamic_cast<Weapon *>(box->getLoot()[current-1].item);
					itemNameText.setString(a->getName());

				

					itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nDefense:\nSpeed:\nRarity:\nEffect:\n");
					itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getWeaponRank()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + to_string(a->getDefense().getResistance()) + "\n" + to_string(a->getSpeed()) + "\n" + a->getRarity_text() + "\n" + a->getCombatEffect().getEffectName());

					itemDescription.setPosition(sf::Vector2f(460, 300));
					itemDescription.setString(a->getDescription());

					string damages = "Damage Types:\n";
					vector<DamageTypes> temp = a->getDamageTypes_Weapon();

					for (int g = 0; g < temp.size(); g++)
					{

						if (temp[g].getDamage() > 0)
						{
							damages += temp[g].getName() + "\t" + to_string(temp[g].getDamage()) + "\n";
						}
					}

					otherInfoText.setString(damages);

					otherInfoText.setPosition(sf::Vector2f(460, 330));
				}
				else if ((typeid(*box->getLoot()[current-1].item) == typeid(Potion)))
				{
					Potion *a = dynamic_cast<Potion *>(box->getLoot()[current-1].item);
					itemNameText.setString(a->getName());


					itemInfo.setString("Amount:\nValue:\nTier:\nType:");
					itemValues.setString(to_string(box->getLoot()[current-1].amount) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getTier()) + "\n" + a->getTypeName());
					itemDescription.setPosition(sf::Vector2f(460, 200));
					itemDescription.setString(a->getDescription());
				}
				else if (box->getLoot()[current-1].item->getName() == "Empty")
				{
					itemNameText.setString("Name:");
				

					itemInfo.setString("");
					itemValues.setString("");
					itemDescription.setString("");
					otherInfoText.setString("");
				}
				else
				{
				
					itemNameText.setString(box->getLoot()[current-1].item->getName());
					itemInfo.setString("");
					itemValues.setString("");
					itemDescription.setString("");
					otherInfoText.setString("");
				}
			}
			else if(box->getLoot().size()>0)
			{
				if ((typeid(*box->getLoot()[current].item) == typeid(Armor)))
				{
					Armor *a = dynamic_cast<Armor *>(box->getLoot()[current].item);
				
					itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nClass:\nType:\n");
					itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getTotalResistance()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + armorClass_toString(a->getClass()) + "\n" + armorType_toString(a->getType()));
					itemDescription.setPosition(sf::Vector2f(460, 250));
					itemDescription.setString(a->getDescription());

					string resistances = "Resistances:\n";
					vector<ActiveEffects> temp = a->getResistanceTypes();

					for (int g = 0; g < temp.size(); g++)
					{

						if (temp[g].getResistance() > 0)
						{
							resistances += temp[g].getEffectName() + "\t" + to_string(temp[g].getResistance()) + "\n";
						}
					}

					otherInfoText.setString(resistances);

					otherInfoText.setPosition(sf::Vector2f(460, 280));
				}
				else if ((typeid(*box->getLoot()[current].item) == typeid(Weapon)))
				{
					Weapon *a = dynamic_cast<Weapon *>(box->getLoot()[current].item);

				

					itemInfo.setString("Level:\nScore:\nValue:\nWeight:\nDefense:\nSpeed:\nRarity:\nEffect:\n");
					itemValues.setString(to_string(a->getLevel()) + "\n" + to_string(a->getWeaponRank()) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getWeight()) + "\n" + to_string(a->getDefense().getResistance()) + "\n" + to_string(a->getSpeed()) + "\n" + a->getRarity_text() + "\n" + a->getCombatEffect().getEffectName());

					itemDescription.setPosition(sf::Vector2f(460, 300));
					itemDescription.setString(a->getDescription());

					string damages = "Damage Types:\n";
					vector<DamageTypes> temp = a->getDamageTypes_Weapon();

					for (int g = 0; g < temp.size(); g++)
					{

						if (temp[g].getDamage() > 0)
						{
							damages += temp[g].getName() + "\t" + to_string(temp[g].getDamage()) + "\n";
						}
					}

					otherInfoText.setString(damages);

					otherInfoText.setPosition(sf::Vector2f(460, 330));
				}
				else if ((typeid(*box->getLoot()[current].item) == typeid(Potion)))
				{
					Potion *a = dynamic_cast<Potion *>(box->getLoot()[current].item);


					itemInfo.setString("Amount:\nValue:\nTier:\nType:");
					itemValues.setString(to_string(box->getLoot()[current].amount) + "\n" + to_string(a->getValue()) + "\n" + to_string(a->getTier()) + "\n" + a->getTypeName());
					itemDescription.setPosition(sf::Vector2f(460, 200));
					itemDescription.setString(a->getDescription());
				}
				else if (box->getLoot()[current].item->getName() == "Empty")
				{
				

					itemInfo.setString("");
					itemValues.setString("");
					itemDescription.setString("");
					otherInfoText.setString("");
				}
				else
				{
				
					itemNameText.setString(box->getLoot()[current].item->getName());
					itemInfo.setString("");
					itemValues.setString("");
					itemDescription.setString("");
					otherInfoText.setString("");
				}
			}

			release = false;
			direct = No_Direction;
			choice = 0;
		}
	}

	// char choice = '9';
	int amt = 0;

	return true;
}

//removes item from specified Location and turns it into a lootBox if fails return empty box
LootBox Player::DropItem(int pos)
{
	LootBox ret;

	//checks if position is valid
	if (pos < 0 || pos > this->InventorySize)
	{
		return ret;
	}
	//if position is empty
	else if (this->Inventory[pos].amount == 0)
	{
		return ret;
	}
	//if valid
	else
	{
		ret.addItem(this->RemoveItemFromInventory(pos));
	}

	ret.setPosition(this->getPosition());

	return ret;
}

