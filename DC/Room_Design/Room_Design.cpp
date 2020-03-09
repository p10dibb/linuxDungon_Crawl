#include "Room_Design.h"

Room createRoom0_0()
{

	Room ret;

	ret.PlacePlayer(1, 1);

	ret.setMaxX(20);

	ret.setMaxY(10);

	//Top Wall

	ret.addWalls(0, 0, 0, 9);

	//Left Wall

	ret.addWalls(1, 0, 19, 0);

	//Buttom Wall

	ret.addWalls(19, 1, 19, 5);

	ret.addDownDoor(19, 6);

	ret.addWalls(19, 7, 19, 9);

	//Right Wall

	ret.addWalls(1, 9, 4, 9);

	ret.addRightDoor(5, 9);

	ret.addWalls(6, 9, 18, 9);

	ret.PlaceShop(9,5);
	ret.setStartingEnemyAmount(6);
	ret.setRoomType("Room 0_0");
	return ret;
}

Room createRoom1_0()
{

	Room ret;

	ret.setMaxX(10);

	ret.setMaxY(20);

	ret.addUpDoor(0, 4);

	ret.addWalls(0, 0, 0, 3);

	ret.addWalls(0, 4, 0, 19);

	ret.addWalls(0, 0, 9, 0);

	ret.addWalls(9, 0, 9, 19);

	ret.addWalls(9, 0, 9, 19);
	ret.setRoomType("Room 1_0");
	return ret;
}

Room createRoom0_1()
{
}

Room createDefaultRoom_V1()
{
	Spawner s;
	Room ret;
	LootBox l;
	l.setMoney(12);
	l.addItem(s.CreateRandomWeapon(1));

	ret.setMaxX(10);

	ret.setMaxY(10);

	//Top Wall

	ret.addWalls(0, 0, 0, 4);

	ret.addUpDoor(0, 5);

	ret.addWalls(0, 6, 0, 9);

	//Left Wall

	ret.addWalls(0, 0, 4, 0);

	ret.addLeftDoor(5, 0);

	ret.addWalls(6, 0, 9, 0);

	//Bottom Wall

	ret.addWalls(9, 0, 9, 4);

	ret.addDownDoor(9, 5);

	ret.addWalls(9, 6, 9, 9);

	//Right Wall

	ret.addWalls(0, 9, 4, 9);

	ret.addRightDoor(5, 9);

	ret.addWalls(6, 9, 9, 9);

	ret.addEnemy(s.CreateZombie(1),4,4);
	ret.addLootBox(6,6, l);
	ret.setRoomType("Small square");
	

	return ret;
}

Room createLeftRoom()
{

	Room ret;

	ret.setMaxX(10);

	ret.setMaxY(10);

	//Top Wall

	ret.addWalls(0, 0, 0, 4);

	ret.addUpDoor(0, 5);

	ret.addWalls(0, 6, 0, 9);

	//Left Wall

	ret.addWalls(0, 0, 9, 0);

	//Bottom Wall

	ret.addWalls(9, 0, 9, 4);

	ret.addDownDoor(9, 5);

	ret.addWalls(9, 6, 9, 9);

	//Right Wall

	ret.addWalls(0, 9, 4, 9);

	ret.addRightDoor(5, 9);

	ret.addWalls(6, 9, 9, 9);


	ret.setRoomType("Left Room");

	return ret;
}

Room createRightRoom()
{

	Room ret;

	ret.setMaxX(10);

	ret.setMaxY(10);

	//top Wall

	ret.addWalls(0, 0, 0, 4);

	ret.addUpDoor(0, 5);

	ret.addWalls(0, 6, 0, 9);

	//Left Wall

	ret.addWalls(0, 0, 4, 0);

	ret.addLeftDoor(5, 0);

	ret.addWalls(6, 0, 9, 0);

	//Bottom Wall

	ret.addWalls(9, 0, 9, 4);

	ret.addDownDoor(9, 5);

	ret.addWalls(9, 6, 9, 9);

	ret.addWalls(0, 9, 9, 9);

	ret.setRoomType("Right Room");

	return ret;
}	
Room createUpRoom()
{

	Room ret;

	ret.setMaxX(10);

	ret.setMaxY(10);

	//top wall

	ret.addWalls(0, 0, 0, 9);

	//Left Wall

	ret.addWalls(0, 0, 4, 0);

	ret.addLeftDoor(5, 0);

	ret.addWalls(6, 0, 9, 0);

	//Bottom Wall

	ret.addWalls(9, 0, 9, 4);

	ret.addDownDoor(9, 5);

	ret.addWalls(9, 6, 9, 9);

	//Right Wall

	ret.addWalls(0, 9, 4, 9);

	ret.addRightDoor(5, 9);

	ret.addWalls(6, 9, 9, 9);

	ret.setRoomType("Up Room");

	return ret;
}
//creates default Room 4 doors verticle hallway
Room createDownRoom()
{

	Room ret;

	ret.setMaxX(10);

	ret.setMaxY(10);

	//Top Wall

	ret.addWalls(0, 0, 0, 4);

	ret.addUpDoor(0, 5);

	ret.addWalls(0, 6, 0, 9);

	//Left Wall

	ret.addWalls(0, 0, 4, 0);

	ret.addLeftDoor(5, 0);

	ret.addWalls(6, 0, 9, 0);

	//Bottom Wall

	ret.addWalls(9, 0, 9, 9);

	//Right Wall

	ret.addWalls(0, 9, 4, 9);

	ret.addRightDoor(5, 9);

	ret.addWalls(6, 9, 9, 9);
	ret.setRoomType("Down Room");

	return ret;
}

//botton Left corner room
Room createRoom9_0()
{
	Spawner s;
	Room ret;

	ret.setMaxX(20);
	ret.setMaxY(20);

	//Left Wall
	ret.addWalls(0, 0, 19, 0);

	//Bottom Wall
	ret.addWalls(19, 0, 19, 19);

	//Top Wall
	ret.addWalls(0, 0, 0, 4);
	ret.addUpDoor(0, 5);
	ret.addWalls(0, 6, 0, 8);
	ret.addWalls(12, 8, 12, 19);

	//Right Wall
	ret.addWalls(0, 8, 12, 8);
	ret.addWalls(12, 19, 16, 19);
	ret.addRightDoor(17, 19);
	ret.addWalls(18, 19, 19, 19);

	Enemy z= s.CreateZombie(1);
	z.setStamina(2);

	ret.addEnemy(z,3,3);
	ret.setRoomType("Room 9_0");

	return ret;
}

//botton Right corner room
Room createRoom9_9()
{

	Room ret;

	ret.setMaxX(30);
	ret.setMaxY(30);

	//Top Wall
	ret.addWalls(0, 0, 0, 7);
	ret.addUpDoor(0, 8);
	ret.addWalls(0, 9, 0, 29);

	//Left Wall
	ret.addWalls(0, 0, 11, 0);
	ret.addLeftDoor(12, 0);
	ret.addWalls(13, 0, 29, 0);

	//Right Wall;
	ret.addWalls(29, 0, 29, 29);

	//Bottom Wall
	ret.addWalls(0, 29, 29, 29);

	ret.setRoomType("Room 9_9");

	return ret;
}

//top Right corner room
Room createRoom0_9()
{

	Room ret;

	ret.setMaxX(25);

	ret.setMaxY(25);

	//top Wall
	ret.addWalls(0, 0, 0, 24);
	ret.addWalls(18, 0, 18, 18);

	//right Wall
	ret.addWalls(0, 24, 24, 24);

	//Left Wall
	ret.addWalls(0, 0, 4, 0);
	ret.addLeftDoor(5, 0);
	ret.addWalls(6, 0, 7, 0);
	ret.addWalls(7, 18, 18, 18);
	ret.addWalls(18, 0, 24, 0);

	// Bottom Wall
	ret.addWalls(24, 0, 24, 3);
	ret.addDownDoor(24, 4);
	ret.addWalls(24, 5, 24, 24);
	ret.addWalls(7, 0, 7, 18);

	ret.setRoomType("Room 0_9");

	return ret;
}

//create Default room 4 door + shape
Room createDefaultRoom_V2(){
	Room ret;
	LootBox l;

	//sets maxX and Y
	ret.setMaxX(30);
	ret.setMaxY(30);

	//Left walls
	ret.addWalls(0,9,9,9);
	ret.addWalls(9,0,14,0);
	ret.addLeftDoor(15,0);
	ret.addWalls(16,0,19,0);
	ret.addWalls(19,9,29,9);

	//right walls
	ret.addWalls(0,19,9,19);
	ret.addWalls(9,29,14,29);
	ret.addRightDoor(15,29);
	ret.addWalls(16,29,19,29);
	ret.addWalls(19,19,29,19);

	//top walls
	ret.addWalls(9,0,9,9);
	ret.addWalls(0,9,0,14);
	ret.addUpDoor(0,15);
	ret.addWalls(0,16,0,19);
	ret.addWalls(9,19,9,29);

	//bottomWalls
	ret.addWalls(19,0,19,9);
	ret.addWalls(29,9,29,14);
	ret.addDownDoor(29,15);
	ret.addWalls(29,16,29,19);
	ret.addWalls(19,19,19,29);

	ret.setStartingEnemyAmount(5);

	ret.addLootBox((rand()%7)+10,(rand()%7)+10,LootBox());

	ret.setRoomType("Plus room");

	return ret;
}

//creates default Room 4 doors verticle hallway
Room createDefaultRoom_V3(){
	Room ret;

	ret.setMaxX(30);
	ret.setMaxY(10);

	//Left Wall
	ret.addWalls(0,0,10,0);
	ret.addLeftDoor(11,0);
	ret.addWalls(12,0,29,0);

	//Right Wall
	ret.addWalls(0,9,21,9);
	ret.addRightDoor(22,9);
	ret.addWalls(23,9,29,9);

	//Top Wall
	ret.addWalls(0,0,0,5);
	ret.addUpDoor(0,6);
	ret.addWalls(0,7,0,9);

	//Down Wall
	ret.addWalls(29,0,29,2);
	ret.addDownDoor(29,3);
	ret.addWalls(29,4,29,9);

	ret.setStartingEnemyAmount(3);

	ret.setRoomType("Verticle hall");

	return ret;
}

//creates default Room 4 doors horizontal hallway
Room createDefaultRoom_V4(){
	Room ret;

	ret.setMaxX(10);
	ret.setMaxY(30);

	//Left Wall
	ret.addWalls(0,0,5,0);
	ret.addLeftDoor(6,0);
	ret.addWalls(7,0,9,0);

	//Right Wall
	ret.addWalls(0,29,4,29);
	ret.addRightDoor(5,29);
	ret.addWalls(6,29,9,29);

	//Top Wall
	ret.addWalls(0,0,0,8);
	ret.addUpDoor(0,9);
	ret.addWalls(0,10,0,29);

	//Down Wall
	ret.addWalls(9,0,9,18);
	ret.addDownDoor(9,19);
	ret.addWalls(9,20,9,29);

	ret.setStartingEnemyAmount(3);

	ret.setRoomType("Horizontal Hall");
	return ret;
}

Room createTreasureRoom_V1(){
	Room ret;
	LootBox l;

	ret.setMaxX(7);
	ret.setMaxY(7);

	//Top Wall
	ret.addWalls(0,0,0,2);
	ret.addUpDoor(0,3);
	ret.addWalls(0,4,0,6);

	//Bottom Wall
	ret.addWalls(6,0,6,2);
	ret.addDownDoor(6,3);
	ret.addWalls(6,4,6,6);

	//Left Wall
	ret.addWalls(0,0,2,0);
	ret.addLeftDoor(3,0);
	ret.addWalls(4,0,6,0);

	//Right Wall
	ret.addWalls(0,6,2,6);
	ret.addRightDoor(3,6);
	ret.addWalls(4,6,6,6);


	l.setMoney(10);
	ret.addLootBox(3,3,l);
	ret.addLootBox(2,2,l);
	ret.addLootBox(4,4,l);
	ret.addLootBox(2,4,l);
	ret.addLootBox(4,2,l);

	ret.setRoomType("Treasure Room");


	

	return ret;

}