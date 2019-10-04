	#include "Dungon_Crawler.h"


void Run() {
	srand(time(NULL));
	 Spawner s;
	Player player = createPlayer();
	

	cout<<"defense:"<<player.getDefense()<<endl;
	cout<<"tot def: "<<player.ActualDefense()<<endl;;

	// Floor f;

	// for (int i = 0; i < 10; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		f.createRoom(i, j);
	// 	}
	// }
	// f.setPlayer(&player);
	// f.NavigateFloor();


	
}

Player createPlayer() {
	Player ret;

	string name;
	cout << "choose a name:" << endl;
	cin>> name;

	ret.setName(name);

	return ret;
}

