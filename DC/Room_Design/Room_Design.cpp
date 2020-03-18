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

	ret.addSpawnPoints({3,3});
	ret.addSpawnPoints({6,8});
	ret.addSpawnPoints({1,4});
	ret.addSpawnPoints({4,1});
	ret.addSpawnPoints({8,8});

	ret.addSpawnPoints({7,2});
	ret.addSpawnPoints({6,5});







	ret.addEnemies(1,Zombie_Enemy);
	// ret.addEnemies(3,Rodent_Enemy);
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

	ret.addSpawnPoints({1,5});
	ret.addSpawnPoints({1,3});
	ret.addSpawnPoints({6,15});
	ret.addSpawnPoints({7,18});
	ret.addSpawnPoints({5,13});
	ret.addSpawnPoints({2,12});

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
	ret.addSpawnPoints({1,6});
	ret.addSpawnPoints({1,3});
	ret.addSpawnPoints({6,8});
	ret.addSpawnPoints({7,3});
	ret.addSpawnPoints({5,5});
	ret.addSpawnPoints({2,4});
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

	ret.addSpawnPoints({2,5});
	ret.addSpawnPoints({1,3});
	ret.addSpawnPoints({6,8});
	ret.addSpawnPoints({7,2});
	ret.addSpawnPoints({5,5});
	ret.addSpawnPoints({2,8});

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
		ret.addSpawnPoints({1,5});
	ret.addSpawnPoints({1,3});
	ret.addSpawnPoints({6,6});
	ret.addSpawnPoints({7,3});
	ret.addSpawnPoints({5,4});
	ret.addSpawnPoints({2,3});

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
		ret.addSpawnPoints({2,4});
	ret.addSpawnPoints({1,3});
	ret.addSpawnPoints({6,3});
	ret.addSpawnPoints({7,7});
	ret.addSpawnPoints({5,2});
	ret.addSpawnPoints({2,5});

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
		ret.addSpawnPoints({5,1});
	ret.addSpawnPoints({2,3});
	ret.addSpawnPoints({6,4});
	ret.addSpawnPoints({7,4});
	ret.addSpawnPoints({5,3});
	ret.addSpawnPoints({2,7});
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
	ret.addSpawnPoints({1,5});
	ret.addSpawnPoints({1,3});
	ret.addSpawnPoints({6,16});
	ret.addSpawnPoints({8,18});
	ret.addSpawnPoints({5,13});
	ret.addSpawnPoints({2,12});
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

	ret.addSpawnPoints({1,5});
	ret.addSpawnPoints({17,3});
	ret.addSpawnPoints({6,15});
	ret.addSpawnPoints({7,18});
	ret.addSpawnPoints({5,13});
	ret.addSpawnPoints({2,12});
	ret.addSpawnPoints({7,5});
	ret.addSpawnPoints({21,17});
	ret.addSpawnPoints({28,15});
	ret.addSpawnPoints({7,27});
	ret.addSpawnPoints({14,23});
	ret.addSpawnPoints({23,12});
	ret.addEnemies(8,Human_Enemy);
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
		ret.addSpawnPoints({1,5});
	ret.addSpawnPoints({1,3});
	ret.addSpawnPoints({6,15});
	ret.addSpawnPoints({7,18});
	ret.addSpawnPoints({5,13});
	ret.addSpawnPoints({2,12});

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

	ret.addSpawnPoints({15,15});
	ret.addSpawnPoints({15,4});
	ret.addSpawnPoints({17,15});
	ret.addSpawnPoints({16,19});
	ret.addSpawnPoints({19,15});
	ret.addSpawnPoints({5,12});

	// ret.setStartingEnemyAmount(5);
	ret.addEnemies(5,Human_Enemy);

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

		ret.addSpawnPoints({1,5});
	ret.addSpawnPoints({1,3});
	ret.addSpawnPoints({15,4});
	ret.addSpawnPoints({7,3});
	ret.addSpawnPoints({15,3});
	ret.addSpawnPoints({12,2});
	// ret.setStartingEnemyAmount(3);
	ret.addEnemies(3,Rodent_Enemy);

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


	ret.addSpawnPoints({1,5});
	ret.addSpawnPoints({1,3});
	ret.addSpawnPoints({6,15});
	ret.addSpawnPoints({7,18});
	ret.addSpawnPoints({5,13});
	ret.addSpawnPoints({2,12});

	// ret.setStartingEnemyAmount(3);
ret.addEnemies(3,Zombie_Enemy);

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

//15 by 10 room 2 doors left and right 4 rodents
Room Create_ShortHall_V1(){

	Room ret;

	ret.setMaxX(10);
	ret.setMaxY(15);

	//LeftWall
	ret.addWalls(0,0,4,0);
	ret.addLeftDoor(5,0);
	ret.addWalls(6,0,9,0);

	//Right Wall
	ret.addWalls(0,14,4,14);
	ret.addRightDoor(5,14);
	ret.addWalls(6,14,9,14);

	//Top Wall
	ret.addWalls(0,0,0,14);
	
	//Bottom Wall
	ret.addWalls(9,0,9,14);


	ret.addSpawnPoints({5,5});
	ret.addSpawnPoints({6,6});
	ret.addSpawnPoints({3,13});
	ret.addSpawnPoints({8,8});
	ret.addSpawnPoints({2,5});
	ret.addSpawnPoints({3,7});
	ret.addSpawnPoints({7,4});
	ret.addSpawnPoints({4,2});


	ret.addEnemies(4,Rodent_Enemy);


	return ret;


}

//10 by 10  2 doors top and bottom 3 rodents
Room Create_SquareRoom_V1(){
	Room ret;
	ret.setMaxX(10);
	ret.setMaxY(10);

	//left wall
	ret.addWalls(0,0,9,0);
	//right Wall
	ret.addWalls(0,9,9,9);
	//top wall
	ret.addWalls(0,0,0,4);
	ret.addUpDoor(0,5);
	ret.addWalls(0,6,0,9);

	//bottom wall
	ret.addWalls(9,0,9,4);
	ret.addDownDoor(9,5);
	ret.addWalls(9,6,9,9);

	ret.addSpawnPoints({2,2});
	ret.addSpawnPoints({4,4});
	ret.addSpawnPoints({5,5});
	ret.addSpawnPoints({4,5});
	ret.addSpawnPoints({4,7});
	ret.addSpawnPoints({3,7});

	ret.addEnemies(3,Rodent_Enemy);

	return ret;
}

//10 by 10  3 doors top and bottom and Right 3 rodents
Room Create_SquareRoom_V2(){
Room ret;
	ret.setMaxX(10);
	ret.setMaxY(10);

	//left wall
	ret.addWalls(0,0,9,0);
	//right Wall
	ret.addWalls(0,9,9,9);
	//top wall
	ret.addWalls(0,0,0,4);
	ret.addUpDoor(0,5);
	ret.addWalls(0,6,0,9);

	//bottom wall
	ret.addWalls(9,0,9,4);
	ret.addDownDoor(9,5);
	ret.addWalls(9,6,9,9);

	ret.addSpawnPoints({2,2});
	ret.addSpawnPoints({4,4});
	ret.addSpawnPoints({5,5});
	ret.addSpawnPoints({4,5});
	ret.addSpawnPoints({4,7});
	ret.addSpawnPoints({3,7});

	ret.addEnemies(3,Rodent_Enemy);

	return ret;
}

//15 by 10 room 2 doors left and right 3 rodents
Room Create_ShortHall_V2(){

	Room ret;

	ret.setMaxX(10);
	ret.setMaxY(15);

	//LeftWall
	ret.addWalls(0,0,4,0);
	ret.addLeftDoor(5,0);
	ret.addWalls(6,0,9,0);

	//Right Wall
	ret.addWalls(0,14,4,14);
	ret.addRightDoor(5,14);
	ret.addWalls(6,14,9,14);

	//Top Wall
	ret.addWalls(0,0,0,14);
	
	//Bottom Wall
	ret.addWalls(9,0,9,14);


	ret.addSpawnPoints({5,5});
	ret.addSpawnPoints({6,6});
	ret.addSpawnPoints({3,13});
	ret.addSpawnPoints({8,8});
	ret.addSpawnPoints({2,5});
	ret.addSpawnPoints({3,7});
	ret.addSpawnPoints({7,4});
	ret.addSpawnPoints({4,2});


	ret.addEnemies(3,Rodent_Enemy);


	return ret;


}





//10 by 10 2 doors right and down 2 Rodents
Room Create_UpperLeftCorner_V2(){
	Room ret;
	ret.setMaxX(10);
	ret.setMaxY(10);

	//LeftWall
	ret.addWalls(0,0,1,0);
	ret.addLeftDoor(2,0);
	ret.addWalls(3,0,4,0);
	ret.addWalls(4,3,9,3);

	//Right Wall
	ret.addWalls(0,9,9,9);
	
	//Top Wall
	ret.addWalls(0,0,0,9);

	//bottom Wall
	ret.addWalls(4,0,4,3);
	ret.addWalls(9,3,9,5);
	ret.addDownDoor(9,6);
	ret.addWalls(9,7,9,9);

	ret.addSpawnPoints({6,6});
	ret.addSpawnPoints({7,7});
	ret.addSpawnPoints({1,7});
	ret.addSpawnPoints({8,8});
	ret.addSpawnPoints({2,2});

	ret.addEnemies(2,Rodent_Enemy);
	
	return ret;
	
}


//10 by 10 2 doors left and down 2 Rodents
Room Create_UpperRightCorner_V2(){
	Room ret;
	ret.setMaxX(10);
	ret.setMaxY(10);

	//LeftWall
	ret.addWalls(0,0,1,0);
	ret.addLeftDoor(2,0);
	ret.addWalls(3,0,4,0);
	ret.addWalls(4,3,9,3);

	//Right Wall
	ret.addWalls(0,9,9,9);
	
	//Top Wall
	ret.addWalls(0,0,0,9);

	//bottom Wall
	ret.addWalls(4,0,4,3);
	ret.addWalls(9,3,9,5);
	ret.addDownDoor(9,6);
	ret.addWalls(9,7,9,9);

	ret.addSpawnPoints({6,6});
	ret.addSpawnPoints({7,7});
	ret.addSpawnPoints({1,7});
	ret.addSpawnPoints({8,8});
	ret.addSpawnPoints({2,2});

	ret.addEnemies(2,Rodent_Enemy);
	
	return ret;
}

//10 by 10 2 doors up and right 3 Rodents
Room Create_BottomLeftCorner_V2(){
	Room ret;


	//Left Wall
	ret.addWalls(0,0,9,0);

	//rightWall
	ret.addWalls(0,4,5,4);
	ret.addWalls(5,9,6,9);
	ret.addRightDoor(7,9);
	ret.addWalls(8,9,9,9);

	//top walls
	ret.addWalls(0,0,0,1);
	ret.addUpDoor(0,2);
	ret.addWalls(0,3,0,4);
	ret.addWalls(5,4,5,9);

	//bottom Wall
	ret.addWalls(9,0,9,9);

	ret.addSpawnPoints({4,2});
	ret.addSpawnPoints({6,6});
	ret.addEnemies(1,Rodent_Enemy);

	return ret;

}

//10 by 10 2 doors up and left 3 Rodents
Room Create_BottomRightCorner_V2(){
	Room ret;

	//Right wall
	ret.addWalls(0,9,9,9);

	//top wall
	ret.addWalls(4,0,4,5);
	ret.addWalls(0,5,0,6);
	ret.addUpDoor(0,7);
	ret.addWalls(0,8,0,9);

	//LeftWall
	ret.addWalls(4,0,6,0);
	ret.addLeftDoor(7,0);
	ret.addWalls(8,0,9,0);
	ret.addWalls(0,5,4,5);


	//bottom Wall
	ret.addWalls(9,0,9,9);

	return ret;
}