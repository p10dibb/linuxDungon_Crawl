#include "Room.h"

Room::Room() {
	this->player = new Player;
	enemyCount = 0;
	player->setPosition({ 1,1 });
	this->Exits[0] = { 5,0 };
	this->Exits[1] = { 0,5 };
	this->Exits[2] = { 5,9 };
	this->Exits[3] = { 9,5 };
	this->BaseMap[this->Exits[0][0]][this->Exits[0][1]] = 'E';
	this->BaseMap[this->Exits[1][0]][this->Exits[1][1]] = 'E';
	this->BaseMap[this->Exits[2][0]][this->Exits[2][1]] = 'E';
	this->BaseMap[this->Exits[3][0]][this->Exits[3][1]] = 'E';
	this->isShop=false;

}

//checks if position is in the bounds of the map
bool inBounds(array<int,2> pos) {
	if (pos[0] < 0 || pos[0]>9 || pos[1] < 0 || pos[1]>9) {
		return false;
	}
	return true;
}

void Room::setExits(array<array<int, 2>, 4> e) {
	if(inBounds(this->Exits[0])){
		this->BaseMap[this->Exits[0][0]][this->Exits[0][1]] = '|';
	}
	
	if (inBounds(this->Exits[1])) {
		this->BaseMap[this->Exits[1][0]][this->Exits[1][1]] = '-';
	}
	if (inBounds(this->Exits[2])) {
		this->BaseMap[this->Exits[2][0]][this->Exits[2][1]] = '|';
	}
	if (inBounds(this->Exits[3])) {
		this->BaseMap[this->Exits[3][0]][this->Exits[3][1]] = '-';
	}
	this->Exits[0] = e[0];
	this->Exits[1] = e[1];
	this->Exits[2] = e[2];
	this->Exits[3] = e[3];

	for (int i = 0; i < 4; i++) {
		if (inBounds(Exits[i])) {
			this->BaseMap[this->Exits[i][0]][this->Exits[i][1]] = 'E';
		}
	}





}

array<array<int, 2>, 4> Room::getExits() {
	return this->Exits;
}



Player* Room::getPlayer() {
	return this->player;
}
void Room::setPlayer(Player* p) {
	this->player = p;
}
DoubleLinkedList<Zombie> Room::getZeds() {
	return this->zeds;
}
void Room::setZeds(DoubleLinkedList<Zombie> z) {
	this->zeds = z;
}


//sets all the items in the room to stuff
void Room::RenderRoom() {
	int i = 0;
	//wipes the room
	for ( i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			this->BaseMap[i][j] = ' ';
		}
	}
	//sets the player
	this->BaseMap[this->player->getPosition()[0]][this->player->getPosition()[1]]='P';

	if(this->getIsShop()){
		this->BaseMap[this->shop.getPosition()[0]][this->shop.getPosition()[1]]='S';
	}

	//sets zeds
	for ( i = 0; i < this->zeds.Size(); i++) {
		this->BaseMap[this->getZeds().getNode(i)->getData().getPosition()[0]][this->getZeds().getNode(i)->getData().getPosition()[1]] = 'Z';
	}

	


	
}

//prints out the map
void Room::DisplayRoom() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << this->BaseMap[i][j]<<" ";
		}
		cout << endl;
	}
}

int Room::RunRoom() {
	int results = 0;

	this->RenderRoom();
	this->DisplayRoom();
	while (1) {
		
		this->player->Navigation(this->BaseMap);
		for(int i=0;i<this->zeds.Size();i++){
			this->zeds.getNode(i)->Data.move(this->BaseMap);
		}

		results=this->playerCollisionCheck();
		//if hit exit
		if (results == -1) {
			return -1;
		}
		else if (results > 0 && results<= 4) {
			return results;
		}
		this->RenderRoom();
		//system("clear");
		this->DisplayRoom();

	}
	
	return 0;
}


//-1 player dies //0 nothing important  //1 exits left // 2 exits up  // 3 exits right// 4 exits down
int Room::playerCollisionCheck() {
	int result = -2;
	int i = 0;

	//checks for exit collision
	for (i = 0; i < 4; i++) {
		if (Exits[i] == player->getPosition()) {
			return i + 1;
		}
	}

		//checks for zed collision
	for ( i = 0; i < this->getZeds().Size(); i++) {
		
		
		if (this->getPlayer()->getPosition() == this->getZeds().getNode(i)->getData().getPosition()) {

			result = PlayerVsZombieCombat(this->player, &this->getZeds().getNode(i)->Data);
			if (result == 0) {
				this->player->RecieveLootDrop(this->spawner.GenerateZombieLootDrop(this->getZeds().getNode(i)->getData()));
				this->zeds.removeNode(i+1);
				this->setEnemyAmt(this->getEnemyAmt() - 1);
			}
			else if(result ==-2){
				return -2;
			}

		}
	}

	//checks for shop collision
	if(this->getIsShop()){
		if(player->getPosition()==this->shop.getPosition()){
			this->shop.ShopDialogue(this->player);
		}
	}

	


	return result;
}

void Room::setEnemyAmt(int a) {
	if (a < 0) {
		a = 0;
	}
	this->enemyCount = a;
}
int Room::getEnemyAmt() {
	return this->enemyCount;
}


void Room::setIsShop(bool shop){
	this->isShop=shop;
}
	
bool Room::getIsShop(){
	return this->isShop;
}

void Room::setShopPosition(array<int,2>pos){
	this->shop.setPosition(pos);
}

void Room::setShopLevel(int level){
	this->shop.setLevel(level);
}