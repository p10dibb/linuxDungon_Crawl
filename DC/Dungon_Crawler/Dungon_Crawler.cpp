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

	Creature c;
	c.setName("tester");
	c.AddEffect(Burning, 10);

	c.AddEffect(Bleeding, 10);

	c.AddEffect(Swiftness, 10);
	c.DisplayAllEffects();
	c.DecrementAllEffects();
	cout << "ssssssssssssssssssssssss" << endl;
	c.DisplayAllEffects();

	c.runDamageEffects();
	cout << c.getHealth() << endl;





	system("pause");

	
}

Player createPlayer() {
	Player ret;

	string name;
	cout << "choose a name:" << endl;
	cin>> name;

	ret.setName(name);

	return ret;
}

