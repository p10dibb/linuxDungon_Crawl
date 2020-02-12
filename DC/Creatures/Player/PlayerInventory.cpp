#include "Player.h"

//adds an Item to the players inventory;
bool Player::addToInventory(Item *i)
{

	//stats incrementer
	this->IncrementItemsRecieved();

	if (FreeSlots != 0)
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
	array<string, 5> functions = {"view", "equip", "use", "move", "exit"};
	int slot = -1;
	string func = "";
	int funcNum = -1;

	while (1)
	{
		cout << "Enter an option and a position" << endl;
		cout << "List of Options:[";
		for (int i = 0; i < functions.size(); i++)
		{
			cout << functions[i] << "| ";
		}
		cout << "]" << endl;

		cout << "Inventory Slots: " << endl;
		this->DisplayInventory();

		cout << endl
			 << "Input:";
		cin >> func;
		funcNum = getFuncInventory(func);
		if (funcNum == -1)
		{
			cout << endl
				 << "Not a valid option type" << endl;
		}
		else if (funcNum == 4)
		{
			cout << "Exiting inventory" << endl;
			return 0;
		}
		else
		{
			cin >> slot;
			if (slot > this->InventorySize || slot < 0)
			{
				cout << "Not a valid inventory slot" << endl;
			}
			else
			{

				switch (funcNum)
				{

				case 0:
					this->ViewInventory(slot);
					break;
				case 1:
					this->EquipInventory(slot);
					break;
				case 2:
					this->UseInventory(slot);
					break;
				case 3:
					this->MoveInventory(slot);
					break;
				}
			}
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

	if (typeid(*this->Inventory[pos].item) == typeid(Weapon))
	{
		this->DisplayEquiped();
		Weapon *w = dynamic_cast<Weapon *>(this->Inventory[pos].item);
		int input = 0;
		cout << "wold you like to equip right(1) left(2):";
		cin >> input;
		if (input == 1)
		{
			this->Inventory[pos].item = this->Right;
			if (!this->setRight(w))
			{
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = w;
			}
			return 0;
		}
		else if (input == 2)
		{
			this->Inventory[pos].item = this->Left;
			if (!this->setLeft(w))
			{
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = w;
			}
			return 0;
		}
		else
		{
			cout << "not valid input" << endl;
			return -1;
		}
	}
	else if ((typeid(*this->Inventory[pos].item) == typeid(Armor)))
	{

		Armor *a = dynamic_cast<Armor *>(this->Inventory[pos].item);
		cout << "armour type for equip: " << a->getType() << endl;

		if (a->getType() == Helmet_ArmorType)
		{
			this->Inventory[pos].item = this->getHead();
			if (!this->setHead(a))
			{
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Chest_ArmorType)
		{
			this->Inventory[pos].item = this->getTorso();
			if (!this->setTorso(a))
			{
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Gloves_ArmorType)
		{
			this->Inventory[pos].item = this->getHands();
			if (!this->setHands(a))
			{
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Pants_ArmorType)
		{
			this->Inventory[pos].item = this->getLegs();
			if (!this->setLegs(a))
			{
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Boots_ArmorType)
		{
			this->Inventory[pos].item = this->getFeet();
			if (!this->setFeet(a))
			{
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
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
	array<string, 8> commands = {"right", "left", "head", "torso", "hands", "legs", "feet", "exit"};
	string input = "";
	while (1)
	{
		//system("clear");
		this->DisplayEquiped();
		cout << "what would you like to see more info on |";
		for (int i = 0; i < commands.size(); i++)
		{
			cout << commands[i] << "| ";
		}
		cout << ":" << endl;

		cin >> input;
		input = toLower(input);

		if (input == commands[0])
		{
			this->Right->DisplayDetails();
		}
		else if (input == commands[1])
		{
			this->Left->DisplayDetails();
		}
		else if (input == commands[2])
		{
			this->getHead()->DisplayDetails();
		}
		else if (input == commands[3])
		{
			this->getTorso()->DisplayDetails();
		}
		else if (input == commands[4])
		{
			this->getHands()->DisplayDetails();
		}
		else if (input == commands[5])
		{
			this->getLegs()->DisplayDetails();
		}
		else if (input == commands[6])
		{
			this->getFeet()->DisplayDetails();
		}
		else if (input == commands[7])
		{
			return 0;
		}
		getchar();
		getchar();

		system("pause");
	}
}

//takes a loot box and prompts the user to interact
bool Player::InteractLootBox(LootBox *box)
{
	char choice = '9';
	int amt = 0;
	Item *temp;

	//player loot box dialogue
	while (choice != '0')
	{
		box->displayContents();
		cout << "would you like to: Exit(0), take Gold amt(1), take Gold All(2), take Item slot(3), Take Item All(4)" << endl;
		choice = getchar();

		//take gold amt
		if (choice == '1')
		{
			cout << "how much Gold?" << endl;
			cin >> amt;
			this->RecieveMoney(box->removeMoney(amt));
		}

		//take all gold
		else if (choice == '2')
		{
			this->RecieveMoney(box->removeMoney(box->getMoney()));
		}

		//take specifiv item
		else if (choice == '3')
		{
			cout << "which item would you like? (slot#)" << endl;
			cin >> amt;
			temp = box->removeItem(amt);
			//checks if remove Item fails
			if (temp->getName() != "Empty")
			{
				//checks if add to inventory fails
				if (!this->addToInventory(temp))
				{
					// if fails readd to box
					box->addItem(temp);
				}
			}
		}

		//take all Items
		else if (choice == '4')
		{
			while (box->getLoot().size() != 0)
			{
				cout << "a";
				temp = box->removeItem(box->getLoot().size() - 1);
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
		}
	}
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

bool operator== (Zombie lhs, Zombie rhs){
	
	if(lhs.getName()==rhs.getName()&&lhs.getSpeed()==rhs.getSpeed()&&lhs.getHealth()==rhs.getHealth()){{
		return true;
	}}

}
