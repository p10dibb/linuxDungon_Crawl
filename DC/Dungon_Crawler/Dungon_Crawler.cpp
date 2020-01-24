	#include "Dungon_Crawler.h"


void Run() {
	srand(time(NULL));
	 Spawner s;
	Player player;
	// = createPlayer();

	// player.addToInventory(s.CreateDevSword());

	// player.addToInventory(s.CreateDevSword());

	// player.addToInventory(s.CreateDevHelmet(Light_ArmorClass));

	// player.addToInventory(s.CreateDevChest(Light_ArmorClass));

	// player.addToInventory(s.CreateDevBoots(Light_ArmorClass));

	// player.addToInventory(s.CreateDevGloves(Light_ArmorClass));

	// player.addToInventory(s.CreateDevPants(Light_ArmorClass));
	player.addToInventory(s.CreateAxe(1,true));
	player.addToInventory(s.CreateDagger(1,true));
	Armor *a;
	a=s.CreateBoots(1,Light_ArmorClass,true);
	map<Effects_enum ,ActiveEffects> e;
	e[NormalResistance_Effects]=(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,25,10));
	a->setResistanceTypes(e);
	player.addToInventory(a);

	player.addToInventory(s.CreatePants(1,Light_ArmorClass,true));
	player.addToInventory(s.CreateChest(1,Light_ArmorClass,true));
	player.addToInventory(s.CreateGloves(1,Light_ArmorClass,true));
	player.addToInventory(s.CreateHelmet(1,Light_ArmorClass,true));

	Floor f;


	f.setRoom(createRoom0_0(),0,0);
	f.setRoom(createRoom1_0(),1,0);
	f.setPlayer(&player);
	f.NavigateFloor();



}

Player createPlayer() {
	Player ret;

	string name;
	cout << "choose a name:" << endl;
	cin>> name;

	ret.setName(name);


	int points = 10;
	int input = 0;
	while (points != 0)
	{

	cout << "you have " << points << " remaining what would you like to upgrade?" << endl;
		ret.addSkillPoint();


		points--;
	}

	return ret;
}


Room createRoom0_0(){
	Room ret;

	ret.setMaxX(20);
	ret.setMaxY(10);

	ret.addWalls(0,0,0,9);

	ret.addWalls(1,0,19,0);
	ret.addWalls(19,1,19,5);
	ret.addDownDoor(2,2);
	ret.addWalls(19,7,19,9);
	ret.addWalls(1,9,4,9);
	ret.addRightDoor(5,9);
	ret.addWalls(6,9,18,9);

	return ret;

}

Room createRoom1_0(){

	Room ret;
	ret.setMaxX(10);
	ret.setMaxY(20);
	ret.addUpDoor(0,4);
	ret.addWalls(0,0,0,3);
	ret.addWalls(0,4,0,19);
	ret.addWalls(0,0,9,0);
	ret.addWalls(9,0,9,19);
	ret.addWalls(9,0,9,19);


}
Room createRoom0_1(){

}