	#include "Dungon_Crawler.h"


void Run() {
	srand(time(NULL));
	 Spawner s;
	Player player = createPlayer();
	

	
	Floor f;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			f.createRoom(i, j);
		}
	}
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

