	#include "Dungon_Crawler.h"


void Run() {
	srand(time(NULL));
	 Spawner s;
	Player player = createPlayer();
	
	player.addToInventory(s.CreateDevSword());
	
	player.addToInventory(s.CreateDevSword());
	
	player.addToInventory(s.CreateDevHelmet(Light_ArmorClass));

	player.addToInventory(s.CreateDevChest(Light_ArmorClass));
	
	player.addToInventory(s.CreateDevBoots(Light_ArmorClass));
	
	player.addToInventory(s.CreateDevGloves(Light_ArmorClass));
	
	player.addToInventory(s.CreateDevPants(Light_ArmorClass));
	
	Floor f;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			f.createRoom(i, j);
		}
	}

	f.createRoom(2,2,3,true);
	
	f.createRoom(1,0,3,true);
	
	f.createRoom(5,5,3,true);
	
	f.createRoom(6,4,3,true);
	
	f.createRoom(7,9,3,true);

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

