#include "Floor.h"

Floor::Floor() {
	this->currentRoom = { 0,0 };
	this->player = new Player();

}

array<array<Room, 10>, 10> Floor::getFloorMap() {
	return this->FloorMap;
}
void Floor::setFloormap(array<array<Room, 10>, 10> f) {
	this->FloorMap = f;
}

void Floor::setRoom(Room r, int x, int y) {
	this->FloorMap[x][y] = r;
}

Room Floor::getRoom(int x, int y) {
	return this->FloorMap[y][x];
}

void Floor::setPlayer(Player *p) {
	this->player = p;
}
Player* Floor::getPlayer() {
	return this->player;
}
//returns -1 if player died
int Floor::NavigateFloor() {
	int value = 0;
	while (1) {
		cout << endl << endl << "Room:" << currentRoom[0] << "," << currentRoom[1] << endl << endl;
		this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].setPlayer(this->getPlayer());
		value = this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].RunRoom();
		cout << "value" << value << endl;
		if (value == -1) {
			return -1;
		}//going left a room
		else {
			 if (value == 1) {

			if (this->currentRoom[1] - 1 >= 0) {
				this->currentRoom[1] -= 1;

				this->player->setPosition({ 1,1 });
				this->player->setPosition({ this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getExits()[2][0]  ,this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getExits()[2][1] - 1 });


			}
		}//going  up a room
			else if (value == 2) {
				if (this->currentRoom[0] - 1 >= 0) {
					this->currentRoom[0] -= 1;
					this->player->setPosition({ 1,1 });
					this->player->setPosition({ this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getExits()[3][0] - 1 ,this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getExits()[3][1] });

				}
		}//going right a room
			else if (value == 3) {
				if (this->currentRoom[1] + 1 <= 9) {
					this->currentRoom[1] += 1;
					this->player->setPosition({ 1,1 });
					this->player->setPosition({ this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getExits()[0][0]  ,this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getExits()[0][1] + 1 });

				}
		}//going down a room
			else if (value == 4) {
				if (this->currentRoom[0] + 1 <= 9) {
					this->currentRoom[0] += 1;
					this->player->setPosition({ this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getExits()[1][0] + 1 ,this->FloorMap[this->currentRoom[0]][this->currentRoom[1]].getExits()[1][1] });
				}
		}
			 cout << "woootdss " << this->FloorMap[this->getCurrentRoom()[0]][this->getCurrentRoom()[1]].getZeds().Size()<<"  :  "<< this->FloorMap[this->getCurrentRoom()[0]][this->getCurrentRoom()[1]].getEnemyAmt()<< endl;
			 if (this->FloorMap[this->getCurrentRoom()[0]][this->getCurrentRoom()[1]].getZeds().Size() !=this->FloorMap[this->getCurrentRoom()[0]][this->getCurrentRoom()[1]].getEnemyAmt()) {
				
				 cout << "made it" << endl;
				 this->initializeRoom(this->player->getLevel(),currentRoom[0],currentRoom[1]);
			 }

		}
		
	}
}

void  Floor::setCurrentRoom(array<int, 2> c) {
	this->currentRoom = c;
}
array<int, 2>  Floor::getCurrentRoom() {
	return this->currentRoom;
}

bool Floor::createRoom( int x, int y, int zedamt ) {
	int actual = zedamt;
	if (zedamt == -1) {
		actual = rand() % 5 + 1;
	}

	this->FloorMap[x][y].setEnemyAmt(actual);

	return true;

}

bool Floor::initializeRoom(int level, int x, int y) {
	
	DoubleLinkedList<Zombie> z;
	for (int i = 0; i < this->FloorMap[x][y].getEnemyAmt();i++) {
		z.add(spawner.CreateZombie(level));
	}
	this->FloorMap[x][y].setZeds(z);
	//create the other stuff like shops and lootchests (not added yet)
	return true;
}