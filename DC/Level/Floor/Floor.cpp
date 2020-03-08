#include "Floor.h"

Floor::Floor()
{
	this->currentRoom = {0, 0};
	this->player = new Player();
}

array<array<Room, 10>, 10> Floor::getFloorMap()
{
	return this->FloorMap;
}
void Floor::setFloormap(array<array<Room, 10>, 10> f)
{
	this->FloorMap = f;
}

void Floor::setRoom(Room r, int x, int y)
{
	this->FloorMap[x][y] = r;
}

Room Floor::getRoom(int x, int y)
{
	return this->FloorMap[y][x];
}

void Floor::setPlayer(Player *p)
{
	this->player = p;
}
Player *Floor::getPlayer()
{
	return this->player;
}
//returns -1 if player died
int Floor::NavigateFloor()
{
	int value = 0;
	while (1)
	{

		cout << endl
			 << endl
			 << "Room:" << currentRoom[0] << "," << currentRoom[1] << endl
			 << endl;
		cout << this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getRoomType() << endl;

		this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].setPlayer(this->getPlayer());

		if (!this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getVisited())
		{
			cout << "initializing" << endl;
			this->initializeRoom(this->player->getLevel(), currentRoom[0], currentRoom[1]);
		}
		this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].setVisited(true);

		value = this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].RunRoom();

		if (value == -1)
		{
			return -1;
		}
		else if (value == -3)
		{
			return -3;
		}
		else
		{
			//going left a room
			if (value == 1)
			{

				if (this->currentRoom[1] - 1 >= 0)
				{
					this->currentRoom[1] -= 1;

					this->player->setPosition({1, 1});
					this->player->setPosition({this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getRightDoorPosition()[0], this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getRightDoorPosition()[1] - 1});

					this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].PlacePlayer(this->player->getPosition()[0], this->player->getPosition()[1]);
					//stats incrementer
					player->IncrementRoomsBeenToo();
				}
			} //going  up a room
			else if (value == 2)
			{
				if (this->currentRoom[0] - 1 >= 0)
				{
					this->currentRoom[0] -= 1;
					this->player->setPosition({1, 1});
					this->player->setPosition({this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getDownDoorPosition()[0] - 1, this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getDownDoorPosition()[1]});
					this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].PlacePlayer(this->player->getPosition()[0], this->player->getPosition()[1]);
					//stats incrementer
					player->IncrementRoomsBeenToo();
				}
			} //going right a room
			else if (value == 3)
			{
				if (this->currentRoom[1] + 1 <= 9)
				{
					this->currentRoom[1] += 1;
					this->player->setPosition({1, 1});
					this->player->setPosition({this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getLeftDoorPosition()[0], this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getLeftDoorPosition()[1] + 1});
					this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].PlacePlayer(this->player->getPosition()[0], this->player->getPosition()[1]);
					//stats incrementer
					player->IncrementRoomsBeenToo();
				}
			} //going down a room
			else if (value == 4)
			{
				if (this->currentRoom[0] + 1 <= 9)
				{
					this->currentRoom[0] += 1;
					this->player->setPosition({this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getUpDoorPosition()[0] + 1, this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getUpDoorPosition()[1]});
					this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].PlacePlayer(this->player->getPosition()[0], this->player->getPosition()[1]);
					//stats incrementer
					player->IncrementRoomsBeenToo();
				}
			}
		}
	}
}

void Floor::setCurrentRoom(array<int, 2> c)
{
	this->currentRoom = c;
}
array<int, 2> Floor::getCurrentRoom()
{
	return this->currentRoom;
}

bool Floor::initializeRoom(int level, int x, int y)
{
	Spawner s;
	Zombie z;

	cout << "create "<<this->FloorMap[x][y].getStartingEnemyAmount()<< " enemies" << endl;
	for (int i = 0; i < this->FloorMap[x][y].getStartingEnemyAmount(); i++)
	{
		cout<<"creaing enemy "<<i+1<<endl;

		z = spawner.CreateZombie(level);
		while (!this->FloorMap[x][y].addEnemy(z, rand() % this->FloorMap[x][y].getMaxX(), rand() % this->FloorMap[x][y].getMaxY()))
			;
	}

	if (this->FloorMap[x][y].getEnemies().size() != 0)
	{
		cout << "placing enemies" << endl;
		int i=1;
		map<array<int, 2>, Zombie>::const_iterator it = this->FloorMap[x][y].Enemies.begin();
		while (it != this->FloorMap[x][y].Enemies.end())
		{
			z = it->second;
			this->FloorMap[x][y].PlaceEnemy(z.getPosition()[0], z.getPosition()[1]);
			it++;
			i++;
		}
	}

	//innitialize lootboxes
	if (this->FloorMap[x][y].getLootBoxes().size() != 0)
	{
		cout << "placing Lootboxes" << endl;

		map<array<int, 2>, LootBox> temp = this->FloorMap[x][y].getLootBoxes();

		map<array<int, 2>, LootBox>::const_iterator Loot_it = temp.begin();

		map<array<int, 2>, LootBox> tempLootMap;
		LootBox tempLoot;
		array<int, 2> tempPos;
		while (Loot_it != temp.end())
		{
			//for(int j=0;j<this->FloorMap[x][y].getLootBoxes().size();j++){
			tempLoot = Loot_it->second;
			tempPos = Loot_it->first;
			//if box doesnt have forced inventory
			if (!tempLoot.getForceInventory())
			{
				tempLoot = s.CreateLootBox(this->player->getLevel());
				tempLoot.setPosition(tempPos);
				tempLootMap[tempPos] = tempLoot;
			}
			else
			{
				tempLootMap[tempPos] = tempLoot;
			}
			Loot_it++;
		}
		this->FloorMap[x][y].setLootBoxes(tempLootMap);
	}

	//if there is a shop it sets it to appropriate level

	if (this->FloorMap[x][y].getIsShop())
	{
		cout<<"placing shop"<<endl;

		this->FloorMap[x][y].setShopLevel(this->getPlayer()->getLevel());
	}

	cout << "building Room" << endl;
	sf::RectangleShape temp(sf::Vector2f(20, 20));
	for (int i = 0; i < this->FloorMap[x][y].getMaxY(); i++)
	{

		this->FloorMap[x][y].RoomMap_Sfml.push_back(vector<sf::RectangleShape>());
		for (int j = 0; j < this->FloorMap[x][y].getMaxX(); j++)
		{
			temp.setPosition(10 + 21 * i, 80 + 21 * j);
			this->FloorMap[x][y].RoomMap_Sfml[i].push_back(temp);
		}
	}

	//create the other stuff like shops and lootchests (not added yet)
	return true;
}