#pragma once
#include "../../Combat/Combat.h"

class Room
{

private:
	//Room Design
	array<array<RoomPieces_enum, 50>, 50> RoomMap;

	//size of the room
	int maxX = 50;
	int maxY = 50;
	

	Spawner spawner;
	Player *player;

	Shop shop;
	//is the shop accisable
	bool isShop = false;

	//amount of enemies at the initialization of the room
	int startingEnemyAmount = 0;

	map<array<int, 2>, Zombie> Enemies;

	//if the room contains a door
	bool isUpDoor = false;
	bool isDownDoor = false;
	bool isLeftDoor = false;
	bool isRightDoor = false;

	//position for each Door
	array<int,2> UpDoorPosition;
	array<int,2> DownDoorPosition;
	array<int,2> RightDoorPosition;
	array<int,2> LeftDoorPosition;

	//if the room has been visited by the player
	bool visited=false;

public:
	Room();

	//gets the amount of enemies at the start of the level
	int getStartingEnemyAmount();

	//sets the amount of enemies at the start of the level 0<amount<roomX*roomY
	bool setStartingEnemyAmount(int amount);

	Player *getPlayer();

	void setPlayer(Player *p);

	//sets a new map of enemies and checks to make sure they are all valid
	bool setEnemies(map<array<int, 2>, Zombie> enemies);

	//returns the map of enemies
	map<array<int, 2>, Zombie> getEnemies();

	//adds an enemy to a given cordinate
	bool addEnemy(Zombie enemy, int x, int y);

	//draws a line between 2 given points can only be strait lines
	bool addWalls(int x1, int y1, int x2, int y2);

	//replaces anything at set spot with Empty_roomPiece
	bool ClearSpot(int x, int y);

	//places Enemy RoomPiece
	int PlaceEnemy(int x, int y);

	//places Player Piece//-1 not valid bounds //-1 player dies //0 nothing important //1 exits left // 2 exits up  // 3 exits right// 4 exits down
	int PlacePlayer(int x, int y);

	//puts a shop at a position
	bool PlaceShop(int x, int y);

	//adds an Upwards Exit
	bool addUpDoor(int x, int y);

	//adds a downwards Exit
	bool addDownDoor(int x, int y);

	//adds a Leftword Exit
	bool addLeftDoor(int x, int y);

	//adds a Rightword Exit
	bool addRightDoor(int x, int y);

	//-1 player dies //0 nothing important  //1 exits left // 2 exits up  // 3 exits right// 4 exits down
	int playerCollisionCheck();

	int zombieCollisionCheck(Zombie *zed);

	void DisplayRoom();
	int RunRoom();

	void setIsShop(bool shop);

	bool getIsShop();

	void setShopPosition(array<int, 2> pos);
	void setShopLevel(int level);


	//sets the boundries of the room x direction 3<x<50
	bool setMaxX(int x);

	//gets the boundries in the x direction
	int getMaxX();

	//sets the boundries of the room y direction 3<y<50
	bool setMaxY(int y);

	//gets the boundries in the y direction
	int getMaxY();

	//returns the position of the UpDoor will return -1,-1 if door is false
	array<int,2> getUpDoorPosition();

	//returns the position of the DownDoor will return -1,-1 if door is false
	array<int,2> getDownDoorPosition();

	//returns the position of the LeftDoor will return -1,-1 if door is false
	array<int,2> getLeftDoorPosition();

	//returns the position of the UpDoor will return -1,-1 if door is false
	array<int,2> getRightDoorPosition();


	//sets if the room has been visited
	void setVisited(bool v);

	//gets if the room has been visited
	bool getVisited();
};