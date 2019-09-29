#include "Room.h"

class Floor  {

private:
	array<array<Room,10>,10> FloorMap;
	Player *player;

	array<int, 2> currentRoom;
	Spawner spawner;


public:
	Floor();
	

	array<array<Room, 10>, 10> getFloorMap();
	void setFloormap(array<array<Room, 10>, 10> f);

	void setRoom(Room r, int x, int y);

	Room getRoom( int x, int y);

	void setPlayer(Player *p);
	Player* getPlayer();

	void setCurrentRoom(array<int, 2> c);
	array<int, 2> getCurrentRoom();

	//runner for the floor
	int NavigateFloor();

	//creates  room x,y with set amount of zombies if -1 then randomly select 1-5; will be initialized with initialize room
	bool createRoom( int x, int y, int zedamt = -1);

	//initializes the room[x][y] so it is at similer level to the input level(probably players level)
	bool initializeRoom(int level,int x,int y);

};