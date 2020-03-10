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
	//	this->LootBoxes[{999,999}]=LootBox();
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
vector<array<int,2>> Room::getStartingEnemyAmount()
{
	return this->starting_Enemy_Amount;
}

bool Room::setStartingEnemyAmount(vector<array<int,2>> enemies)
{
	this->starting_Enemy_Amount=enemies;
	return true;
}

//sets the amount of enemies at the start of the level 0<amount<roomX*roomY/2
bool Room::addEnemies(int amt, Enemy_enum type){
	int tot=0;
	array<int,2> temp;

	for(int i=0; i<this->starting_Enemy_Amount.size();i++){
		tot+=this->starting_Enemy_Amount[i][0];
	}

	if(tot+amt<(this->maxX*maxY)/2){
	temp[0]=amt;
	temp[1]=type;
	this->starting_Enemy_Amount.push_back(temp);
	return true;
	}else{
		return false;
	}

}

//sets a new map of enemies and checks to make sure they are all valid
bool Room::setEnemies(map<array<int, 2>, Enemy> enemies)
{
	array<int, 2> tempPos;
	Enemy tempEnemy;

	map<array<int, 2>, Enemy>::const_iterator it = enemies.begin();
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
map<array<int, 2>, Enemy> Room::getEnemies()
{
	return this->Enemies;
}

//adds an enemy to a given cordinate
bool Room::addEnemy(Enemy enemy, int x, int y)
{
	
	enemy.setPosition({x, y});

	if (Enemies.count({x, y}))
	{
		return false;
	}

	this->Enemies[{x, y}] = enemy;
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
		while (currentPoint != y2 + direction)
		{
			if (this->RoomMap[x1][currentPoint] != Empty_RoomPieces && this->RoomMap[x1][currentPoint] != Wall_RoomPieces)
			{
				return false;
			}
			currentPoint += direction;
		}

		currentPoint = y1;
		//places walls down
		while (currentPoint != y2 + direction)
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
		while (currentPoint != x2 + direction)
		{
			if (this->RoomMap[currentPoint][y1] != Empty_RoomPieces && this->RoomMap[currentPoint][y1] != Wall_RoomPieces)
			{
				return false;
			}
			currentPoint += direction;
		}

		currentPoint = x1;
		//places walls down
		while (currentPoint != x2 + direction)
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

	this->isShop=true;
	this->shop.setPosition({x,y});
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
	this->UpDoorPosition = {x, y};
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
	this->DownDoorPosition = {x, y};
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
	this->LeftDoorPosition = {x, y};
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
	this->RightDoorPosition = {x, y};
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
void Room::DisplayRoom(sf::RenderWindow *window)
{

	for (int i = 0; i < this->maxY; i++)
	{
		for (int j = 0; j < this->maxX; j++)
		{

			switch (this->RoomMap[j][i])
			{
			case Empty_RoomPieces:
				break;
			case Wall_RoomPieces:
				this->RoomMap_Sfml[i][j].setFillColor(sf::Color::Red);
				window->draw(this->RoomMap_Sfml[i][j]);
				break;
			case Player_RoomPieces:
				this->RoomMap_Sfml[i][j].setFillColor(sf::Color::Blue);
				window->draw(this->RoomMap_Sfml[i][j]);
				break;
			case Enemy_RoomPieces:
				this->RoomMap_Sfml[i][j].setFillColor(sf::Color::Green);
				window->draw(this->RoomMap_Sfml[i][j]);
				break;
			case Shop_RoomPieces:
				this->RoomMap_Sfml[i][j].setFillColor(sf::Color::White);
				window->draw(this->RoomMap_Sfml[i][j]);
				break;
			case DownDoor_RoomPieces:
				this->RoomMap_Sfml[i][j].setFillColor(sf::Color::Magenta);
				window->draw(this->RoomMap_Sfml[i][j]);
				break;
			case UpDoor_RoomPieces:
				this->RoomMap_Sfml[i][j].setFillColor(sf::Color::Magenta);
				window->draw(this->RoomMap_Sfml[i][j]);
				break;
			case LeftDoor_RoomPieces:
				this->RoomMap_Sfml[i][j].setFillColor(sf::Color::Magenta);
				window->draw(this->RoomMap_Sfml[i][j]);
				break;
			case RightDoor_RoomPieces:
				this->RoomMap_Sfml[i][j].setFillColor(sf::Color::Magenta);
				window->draw(this->RoomMap_Sfml[i][j]);
				break;
			case Loot_RoomPieces:
				this->RoomMap_Sfml[i][j].setFillColor(sf::Color::Yellow);
				window->draw(this->RoomMap_Sfml[i][j]);
				break;
			}
	
		}
	}
}

//main loop that runs while in this room
int Room::RunRoom()
{
		sf::Font font;
	font.loadFromFile("../Fonts/Montserrat-Regular.ttf");
	int results = 0;
	array<int, 2> tempPos;
	bool playersTurn = true;

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Run Room");

	sf::Text whosTurn("Players Turn",font,30);
	whosTurn.setPosition(sf::Vector2f(10,10));

	// vector<sf::Text> otherText;

	// this->DisplayRoom();
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
		window.draw(whosTurn);
		this->DisplayRoom(&window);

		window.display();
		//runs Player
		int steps = 0;

		//lets player take as many steps as thier stamina allows
		while (steps < player->getStamina())
		{
			this->ClearSpot(player->getPosition()[0], player->getPosition()[1]);
			//checks if shop needs to be replaced
			if (this->isShop)
			{
				if (this->shop.getPosition() == player->getPosition())
				{
					this->PlaceShop(this->shop.getPosition()[0], this->shop.getPosition()[1]);
				}
			}

			//Places all loot boxes
			map<array<int, 2>, LootBox>::iterator it = this->LootBoxes.begin();
			while (it != this->LootBoxes.end())
			{
				this->RoomMap[it->first[0]][it->first[1]] = Loot_RoomPieces;
				it++;
			}

			tempPos = player->getPosition();
			int navChoice = 1;
			while ((navChoice = this->player->Navigation(this->RoomMap)) == -4)
			{
				Saver(*player);
			}
			if (navChoice == -3)
			{
				return -3;
			}
			results = this->playerCollisionCheck();

			//if hit exit
			if (results == -1)
			{
				return -1;
			}
			else if (results > 0 && results <= 4)
			{
				player->setPosition(tempPos);
				return results;
			}

			window.clear();
			window.draw(whosTurn);

			this->PlacePlayer(player->getPosition()[0], player->getPosition()[1]);
			
			this->DisplayRoom(&window);

			window.display();
			steps++;
		}
		//run Enemys
		map<array<int, 2>, Enemy> temp;
		map<array<int, 2>, Enemy>::const_iterator it = this->Enemies.begin();
		// cout<<"zed amt: "<<this->Enemies.size()<<endl;
		int k=1;
		while (it != this->Enemies.end())
		{
			// cout<<"Enemy "<<k<<" is moving"<<endl;
			Enemy z = it->second;
	
			
			steps = 0;
			while (steps < z.getStamina())
			{
				this->ClearSpot(z.getPosition()[0], z.getPosition()[1]);

				tempPos = z.getPosition();
				z.move(this->RoomMap);
				results = this->EnemyCollisionCheck(&z);
				//player dies
				if (results == -1)
				{
					return -1;
				}
				else if (results < 0)
				{
					if (results == -2)
					{
						z.setPosition(tempPos);
					}

					whosTurn.setString("Enemies Turn");
					window.clear();
					window.draw(whosTurn);

					this->PlaceEnemy(z.getPosition()[0], z.getPosition()[1]);

					this->DisplayRoom(&window);

					window.display();
					whosTurn.setString("Players Turn");

					//should replace with something else later
					for(int delay=0;delay<50000000;delay++);
				}
				else if (results == 0)
				{
					break;
				}
				steps++;
				//	this->DisplayRoom();
			}

			if (results != 0)
			{
				temp[z.getPosition()] = z;
			}
			it++;
		}
		Enemies = temp;
		window.display();
	}

	return 0;
}

//-1 player dies //0 nothing important  //1 exits left // 2 exits up  // 3 exits right// 4 exits down
int Room::playerCollisionCheck()
{
	int result = 0;
	//checks for Enemy Collision
	if (RoomMap[player->getPosition()[0]][player->getPosition()[1]] == Enemy_RoomPieces)
	{

		cout<<"p col Enemy Level: "<<this->Enemies[player->getPosition()].getLevel()<<"Health: "<<this->Enemies[player->getPosition()].getHealth()<<" Position: "<<player->getPosition()[0]<<","<<player->getPosition()[1]<<endl;
		result = PlayerVsEnemyCombat(this->player, &this->Enemies[player->getPosition()]);
		//if Enemy dies
		if (result == 0)
		{
			//recieves the loot drop
			this->player->RecieveLootDrop(this->spawner.GenerateEnemyLootDrop(this->Enemies[player->getPosition()]));
			//clears the Enemy from the map
			this->ClearSpot(this->player->getPosition()[0], this->player->getPosition()[1]);
			//removes the Enemy from the array
			this->Enemies.erase(player->getPosition());
		}
		//if the player escapes the Enemy
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
	//checks for loot box collision
	else if (RoomMap[player->getPosition()[0]][player->getPosition()[1]] == Loot_RoomPieces)
	{
		this->player->InteractLootBox(&this->LootBoxes[this->player->getPosition()]);
		if (this->LootBoxes[this->player->getPosition()].isEmpty())
		{
			this->LootBoxes.erase(this->player->getPosition());
		}
	}

	return result;
}

int Room::EnemyCollisionCheck(Enemy *zed)
{
	int result = -3;
	if (RoomMap[zed->getPosition()[0]][zed->getPosition()[1]] == Player_RoomPieces)
	{
		cout<<"z col Enemy Level: "<<zed->getLevel()<<"Health: "<<zed->getHealth()<<" Position: "<<player->getPosition()[0]<<","<<player->getPosition()[1]<<endl;

		result = PlayerVsEnemyCombat(this->player, zed);
		//if Enemy dies
		if (result == 0)
		{
			//recieves the loot drop
			this->player->RecieveLootDrop(this->spawner.GenerateEnemyLootDrop(*zed));
			//clears the Enemy from the map
			this->ClearSpot(this->player->getPosition()[0], this->player->getPosition()[1]);
			//removes the Enemy from the array
			this->Enemies.erase(player->getPosition());
		}
	}
	// -3 if not-2 if the player escapes the Enemy -1 if player dies 0 if Enemy dies
	return result;
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
void Room::setVisited(bool v)
{
	this->visited = v;
}

//gets if the room has been visited
bool Room::getVisited()
{
	return this->visited;
}

//returns the map of lootBoxes
map<array<int, 2>, LootBox> Room::getLootBoxes()
{
	return this->LootBoxes;
}

//sets the map of LootBoxes only adds the ones in valid positions
bool Room::setLootBoxes(map<array<int, 2>, LootBox> loot)
{
	map<array<int, 2>, LootBox> temp;
	map<array<int, 2>, LootBox>::iterator it = loot.begin();
	LootBox t;
	while (it != loot.end())
	{
		t = it->second;

		//checks if in the boundry
		if (t.getPosition()[0] < this->maxX && t.getPosition()[0] > 0 && t.getPosition()[1] > 0 && t.getPosition()[1] < this->maxY)
		{
			temp[t.getPosition()] = t;
			this->RoomMap[t.getPosition()[0]][t.getPosition()[1]] = Loot_RoomPieces;
		}
		it++;
	}
	this->LootBoxes = temp;
	return true;
}

//adds a lootbox at a location
bool Room::addLootBox(int x, int y, LootBox loot)
{
	array<int, 2> pos;
	pos[0] = x;
	pos[1] = y;
	loot.setPosition(pos);

	if (this->LootBoxes.count(loot.getPosition()))
	{
		loot.Merge(&this->LootBoxes[loot.getPosition()]);
		this->LootBoxes[loot.getPosition()] = loot;
	}
	else
	{

		if (this->RoomMap[x][y] == Empty_RoomPieces || this->RoomMap[x][y] == Player_RoomPieces || this->RoomMap[x][y] == Enemy_RoomPieces)
		{

			this->LootBoxes[loot.getPosition()] = loot;
			this->RoomMap[x][y] = Loot_RoomPieces;
		}
		else
		{

			return false;
		}
	}
	return true;
}


	string Room::getRoomType(){
		return this->roomType;
	}
	bool Room::setRoomType(string type){
		this->roomType=type;
	}