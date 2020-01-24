#include "Room.h"

Room::Room()
{
	this->player = new Player;

	this->isShop = false;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			this->RoomMap[i][j] = Empty_RoomPieces;
		}
	}
}

//checks if position is in the bounds of the map
bool inBounds(array<int, 2> pos)
{
	if (pos[0] < 0 || pos[0] > 9 || pos[1] < 0 || pos[1] > 9)
	{
		return false;
	}
	return true;
}

//gets the amount of enemies at the start of the level
int Room::getStartingEnemyAmount()
{
	return this->startingEnemyAmount;
}

//sets the amount of enemies at the start of the level 0<amount<roomX*roomY
bool Room::setStartingEnemyAmount(int amount)
{
	if (amount < 0)
	{
		this->startingEnemyAmount = 0;
		return false;
	}
	else if (amount > this->maxX * this->maxY)
	{
		this->startingEnemyAmount = this->maxX * this->maxY;
		return false;
	}

	this->startingEnemyAmount = amount;
	return true;
}

//sets a new map of enemies and checks to make sure they are all valid
bool Room::setEnemies(map<array<int, 2>, Zombie> enemies)
{
	array<int, 2> tempPos;
	Zombie tempEnemy;

	map<array<int, 2>, Zombie>::const_iterator it = enemies.begin();
	while (it != enemies.end())
	{
		tempPos = it->first;
		tempEnemy = it->second;

		//checks if the positions match the key
		if (tempPos != tempEnemy.getPosition())
		{
			return false;
		}
		if (tempPos[0] < 0 || tempPos[0] >= this->maxX)
		{
			return false;
		}
		if (tempPos[1] < 0 || tempPos[1] >= this->maxY)
		{
			return false;
		}
		it++;
	}
	this->Enemies = enemies;
	return true;
}

//returns the map of enemies
map<array<int, 2>, Zombie> Room::getEnemies()
{
	return this->Enemies;
}

//adds an enemy to a given cordinate
bool Room::addEnemy(Zombie enemy, int x, int y)
{

	enemy.setPosition({x, y});

	if (Enemies.count({x, y}))
	{
		return false;
	}

	Enemies[{x, y}] = enemy;
	return true;
}

//draws a line between 2 given points can only be strait lines. it will only place on empty spaces
bool Room::addWalls(int x1, int y1, int x2, int y2)
{

	//checks if points are within bounds
	if (x1 < 0 || x1 >= maxX)
	{
		return false;
	}
	if (x2 < 0 || x2 >= maxX)
	{
		return false;
	}
	if (y1 < 0 || y1 >= maxY)
	{
		return false;
	}
	if (y2 < 0 || y2 >= maxY)
	{
		return false;
	}
	int currentPoint = 0;
	int direction = 1;
	//checks if being placed on X axis
	if (x1 == x2)
	{

		//gets the itteration direction
		if (y1 > y2)
		{
			direction = -1;
		}

		currentPoint = y1;
		//checks to make sure nothing is in the way of building the walls
		while (currentPoint != y2+direction)
		{
			if (this->RoomMap[x1][currentPoint] != Empty_RoomPieces&&this->RoomMap[x1][currentPoint]!=Wall_RoomPieces)
			{
				return false;
			}
			currentPoint += direction;
		}

		currentPoint = y1;
		//places walls down
		while (currentPoint != y2+direction)
		{
			this->RoomMap[x1][currentPoint] = Wall_RoomPieces;
			currentPoint += direction;
		}
		return true;
	}
	//checks if being placed on the Y axis
	else if (y1 == y2)
	{

		//gets the itteration direction
		if (x1 > x2)
		{
			direction = -1;
		}

		currentPoint = x1;

		//checks to make sure nothing is in the way of building the walls
		while (currentPoint != x2+direction)
		{
			if (this->RoomMap[currentPoint][y1] != Empty_RoomPieces&&this->RoomMap[currentPoint][y1] != Wall_RoomPieces)
			{
				return false;
			}
			currentPoint += direction;
		}

		currentPoint = x1;
		//places walls down
		while (currentPoint != x2+direction)
		{
			this->RoomMap[currentPoint][y1] = Wall_RoomPieces;
			currentPoint += direction;
		}
		return true;
	}
	//No staight line
	else
	{
		return false;
	}
}

//replaces anything at set spot with Empty_roomPiece
bool Room::ClearSpot(int x, int y)
{

	//checks to see if valid point
	if (x < 0 || x >= maxX)
	{
		return false;
	}
	if (y < 0 || y >= maxY)
	{
		return false;
	}
	//Checks if Removing a door and sets the door to false
	if (this->RoomMap[x][y] == UpDoor_RoomPieces)
	{
		isUpDoor = false;
	}
	else if (this->RoomMap[x][y] == DownDoor_RoomPieces)
	{
		isDownDoor = false;
	}
	else if (this->RoomMap[x][y] == LeftDoor_RoomPieces)
	{
		isLeftDoor = false;
	}
	else if (this->RoomMap[x][y] == RightDoor_RoomPieces)
	{
		isRightDoor = false;
	}
	//removing the shop
	else if (this->RoomMap[x][y] == Shop_RoomPieces)
	{
		isShop = false;
	}

	this->RoomMap[x][y] = Empty_RoomPieces;
	return true;
}

//places Enemy RoomPiece
int Room::PlaceEnemy(int x, int y)
{

	//checks if valid cordinates
	if (x < 0 || x >= maxX)
	{
		return false;
	}
	if (y < 0 || y >= maxY)
	{
		return false;
	}

	this->RoomMap[x][y] = Enemy_RoomPieces;
	return true;
}

//places Player Piece
int Room::PlacePlayer(int x, int y)
{

	//checks if valid cordinates
	if (x < 0 || x >= maxX)
	{
		return -2;
	}
	if (y < 0 || y >= maxY)
	{
		return -2;
	}

	this->RoomMap[x][y] = Player_RoomPieces;
	return true;
}

//puts a shop at a position
bool Room::PlaceShop(int x, int y)
{
	if (x < 0 || x >= this->maxX)
	{
		return false;
	}
	if (y < 0 || y >= this->maxY)
	{
		return false;
	}

	this->RoomMap[x][y] = Shop_RoomPieces;
	return true;
}

//adds an Upwards Exit
bool Room::addUpDoor(int x, int y)
{
	if (isUpDoor)
	{
		return false;
	}

	//checks for bounds
	if (x < 0 || x >= this->maxX)
	{
		return false;
	}
	if (y < 0 || y >= maxY)
	{
		return false;
	}

	this->RoomMap[x][y] = UpDoor_RoomPieces;
	this->UpDoorPosition={x,y};
	this->isUpDoor = true;
	return true;
}

//adds a downwards Exit
bool Room::addDownDoor(int x, int y)
{
	if (isDownDoor)
	{
		return false;
	}

	//checks for bounds
	if (x < 0 || x >= this->maxX)
	{
		return false;
	}
	if (y < 0 || y >= maxY)
	{
		return false;
	}

	this->RoomMap[x][y] = DownDoor_RoomPieces;
	this->DownDoorPosition={x,y};
	this->isDownDoor = true;
	return true;
}

//adds a Leftword Exit
bool Room::addLeftDoor(int x, int y)
{
	if (isLeftDoor)
	{
		return false;
	}

	//checks for bounds
	if (x < 0 || x >= this->maxX)
	{
		return false;
	}
	if (y < 0 || y >= maxY)
	{
		return false;
	}

	this->RoomMap[x][y] = LeftDoor_RoomPieces;
	this->LeftDoorPosition={x,y};
	this->isLeftDoor = true;
	return true;
}

//adds a Rightword Exit
bool Room::addRightDoor(int x, int y)
{
	if (isRightDoor)
	{
		return false;
	}

	//checks for bounds
	if (x < 0 || x >= this->maxX)
	{
		return false;
	}
	if (y < 0 || y >= maxY)
	{
		return false;
	}

	this->RoomMap[x][y] = RightDoor_RoomPieces;
	this->RightDoorPosition={x,y};
	this->isRightDoor = true;
	return true;
}

Player *Room::getPlayer()
{
	return this->player;
}

void Room::setPlayer(Player *p)
{
	this->player = p;
}

//prints out the map
void Room::DisplayRoom()
{

	for (int i = 0; i < this->maxX; i++)
	{
		for (int j = 0; j < this->maxY; j++)
		{
			switch (this->RoomMap[i][j])
			{
			case Empty_RoomPieces:
				cout << " ";
				break;
			case Wall_RoomPieces:
				cout << "|";
				break;
			case Player_RoomPieces:
				cout << "P";
				break;
			case Enemy_RoomPieces:
				cout << "E";
				break;
			case Shop_RoomPieces:
				cout << "S";
				break;
			case DownDoor_RoomPieces:
				cout << "D";
				break;
			case UpDoor_RoomPieces:
				cout << "U";
				break;
			case LeftDoor_RoomPieces:
				cout << "L";
				break;
			case RightDoor_RoomPieces:
				cout << "R";
				break;
			case Loot_RoomPieces:
				cout << "T";
				break;
			}
		}
		cout << endl;
	}
}

int Room::RunRoom()
{
	int results = 0;

	this->DisplayRoom();
	while (1)
	{
		//runs Player
		this->ClearSpot(player->getPosition()[0], player->getPosition()[1]);
		//checks if shop needs to be replaced
		if (this->isShop)
		{
			if (this->shop.getPosition() == player->getPosition())
			{
				this->PlaceShop(this->shop.getPosition()[0], this->shop.getPosition()[1]);
			}
		}
		this->player->Navigation(this->RoomMap);
		results = this->playerCollisionCheck();
		this->PlacePlayer(player->getPosition()[0], player->getPosition()[1]);

		//if hit exit
		if (results == -1)
		{
			return -1;
		}
		else if (results > 0 && results <= 4)
		{
			return results;
		}

		//run Zombies
		map<array<int, 2>, Zombie> temp;
		map<array<int, 2>, Zombie>::const_iterator it = this->Enemies.begin();
		while (it != this->Enemies.end())
		{
			Zombie z = it->second;

			this->ClearSpot(z.getPosition()[0], z.getPosition()[1]);

			z.move(this->RoomMap);
			results = this->zombieCollisionCheck(&z);
			//player dies
			if (results == -1)
			{
				return -1;
			}
			else if (results == -2)
			{
				temp[z.getPosition()] = z;
			}
		}
		Enemies = temp;

		this->DisplayRoom();
	}

	return 0;
}

//-1 player dies //0 nothing important  //1 exits left // 2 exits up  // 3 exits right// 4 exits down
int Room::playerCollisionCheck()
{
	int result = 0;
	//checks for Zombie Collision
	if (RoomMap[player->getPosition()[0]][player->getPosition()[1]] == Enemy_RoomPieces)
	{

		result = PlayerVsZombieCombat(this->player, &this->Enemies[player->getPosition()]);
		//if zombie dies
		if (result == 0)
		{
			//recieves the loot drop
			this->player->RecieveLootDrop(this->spawner.GenerateZombieLootDrop(this->Enemies[player->getPosition()]));
			//clears the Enemy from the map
			this->ClearSpot(this->player->getPosition()[0], this->player->getPosition()[1]);
			//removes the zombie from the array
			this->Enemies.erase(player->getPosition());
		}
		//if the player escapes the zombie
		else if (result == -2)
		{
			return -2;
		}
	}
	//check for shop collision
	else if (RoomMap[player->getPosition()[0]][player->getPosition()[1]] == Shop_RoomPieces)
	{
		this->shop.ShopDialogue(this->player);
	}
	//checks for Door collisions
	else if (RoomMap[player->getPosition()[0]][player->getPosition()[1]] == UpDoor_RoomPieces)
	{
		return 2;
	}
	else if (RoomMap[player->getPosition()[0]][player->getPosition()[1]] == DownDoor_RoomPieces)
	{
		return 4;
	}
	else if (RoomMap[player->getPosition()[0]][player->getPosition()[1]] == LeftDoor_RoomPieces)
	{
		return 1;
	}
	else if (RoomMap[player->getPosition()[0]][player->getPosition()[1]] == RightDoor_RoomPieces)
	{
		return 3;
	}

	return result;
}

int Room::zombieCollisionCheck(Zombie *zed)
{
	int result = 0;
	if (RoomMap[zed->getPosition()[0]][zed->getPosition()[1]] == Player_RoomPieces)
	{

		result = PlayerVsZombieCombat(this->player, &this->Enemies[player->getPosition()]);
		//if zombie dies
		if (result == 0)
		{
			//recieves the loot drop
			this->player->RecieveLootDrop(this->spawner.GenerateZombieLootDrop(*zed));
			//clears the Enemy from the map
			this->ClearSpot(this->player->getPosition()[0], this->player->getPosition()[1]);
			//removes the zombie from the array
			this->Enemies.erase(player->getPosition());
		}
		//if the player escapes the zombie
		else if (result == -2)
		{
			return -2;
		}
		//player dies
		return result;
	}
}

void Room::setIsShop(bool shop)
{
	this->isShop = shop;
}

bool Room::getIsShop()
{
	return this->isShop;
}

void Room::setShopPosition(array<int, 2> pos)
{
	this->shop.setPosition(pos);
}

void Room::setShopLevel(int level)
{
	this->shop.setLevel(level);
}

//sets the boundries of the room x direction 3<x<50
bool Room::setMaxX(int x)
{
	if (x < 3)
	{
		this->maxX = 3;
		return false;
	}
	else if (x > 50)
	{
		this->maxX = 50;
		return false;
	}
	this->maxX = x;
	return true;
}

//gets the boundries in the x direction
int Room::getMaxX()
{
	return this->maxX;
}

//sets the boundries of the room y direction 3<y<50
bool Room::setMaxY(int y)
{
	if (y < 3)
	{
		this->maxY = 3;
		return false;
	}
	else if (y > 50)
	{
		this->maxY = 50;
		return false;
	}
	this->maxY = y;
	return true;
}

//gets the boundries in the y direction
int Room::getMaxY()
{
	return this->maxY;
}

//returns the position of the UpDoor will return -1,-1 if door is false
array<int, 2> Room::getUpDoorPosition()
{
	if (isUpDoor)
	{
		return this->UpDoorPosition;
	}
	else
	{
		return {-1, -1};
	}
}

//returns the position of the DownDoor will return -1,-1 if door is false
array<int, 2> Room::getDownDoorPosition()
{
	if (isDownDoor)
	{
		return this->DownDoorPosition;
	}
	else
	{
		return {-1, -1};
	}
}

//returns the position of the LeftDoor will return -1,-1 if door is false
array<int, 2> Room::getLeftDoorPosition()
{
	if (isLeftDoor)
	{
		return this->LeftDoorPosition;
	}
	else
	{
		return {-1, -1};
	}
}

//returns the position of the UpDoor will return -1,-1 if door is false
array<int, 2> Room::getRightDoorPosition()
{
	if (isRightDoor)
	{
		return this->RightDoorPosition;
	}
	else
	{
		return {-1, -1};
	}
}

	//sets if the room has been visited
	void Room::setVisited(bool v){
		this->visited=v;
	}

	//gets if the room has been visited
	bool Room::getVisited(){
		return this->visited;
	}