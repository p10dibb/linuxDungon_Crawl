#include "Combat.h"


class Room {

private:
	char EmptyMap[10][10] = { {'-','-','-','-','-','-','-','-','-','-' },{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'-','-','-','-','-','-','-','-','-','-' } };

	char BaseMap[10][10]{ {'-','-','-','-','-','-','-','-','-','-' },{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'-','-','-','-','-','-','-','-','-','-' } };
	
	Spawner spawner;
	Player* player;

	int enemyCount;
	DoubleLinkedList<Zombie> zeds;


	//0=left, 1=up, 2=right,3=down
	array<array<int,2>, 4> Exits;
	



public:
	Room();

	void setExits(array<array<int, 2>, 4> e);
	array<array<int, 2>, 4> getExits();

	Player* getPlayer();
	void setPlayer(Player* p);
	DoubleLinkedList<Zombie> getZeds();
	void setZeds(DoubleLinkedList<Zombie> z);
	



	void RenderRoom();
	void DisplayRoom();
	int RunRoom();

	//-1 player dies //0 nothing important  //1 exits left // 2 exits up  // 3 exits right// 4 exits down
	int playerCollisionCheck();
	void setEnemyAmt(int a);
	int getEnemyAmt();



};