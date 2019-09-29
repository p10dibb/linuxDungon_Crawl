#include "Combat.h"



//player fighting zombie  return 0=zombie died -1=player died
int PlayerVsZombieCombat(Player* player, Zombie zed) {

	//speed totals who ever has the higher number gets to attack
	int playerSpeedTot = player->ActualSpeed();
	int ZombieSpeedTot = zed.getSpeed();


	int Damage = 0;
	int round = 1;
	while (1) {
		cout << "round: " << round <<",Level "<<zed.getLevel()<<" "<< zed.getName()<<" health:" << zed.getHealth() << " Player health:" << player->getHealth() << endl;
		// zed.DisplayDetails();
		 round++;
		 cout << "zombie speed tot: " << ZombieSpeedTot << " player speed tot: " << playerSpeedTot<<endl<<endl;
		if (ZombieSpeedTot > playerSpeedTot) {
			cout << zed.getName() << " is attacking" << endl;
			
			//incriment player speed to see if player gets a turn
			playerSpeedTot += player->ActualSpeed();

			Damage = player->TakeDamage(zed.Attack());
			cout << player->getName() << " takes " << Damage << "damage" << endl<<endl;
		}
		else {
			cout << player->getName() << " is attacking" << endl;

			//incriment the zombie speed to see if they get thier turn
			ZombieSpeedTot += zed.getSpeed();

			Damage = zed.TakeDamage(zed.Attack());
			cout << zed.getName() << " takes " << Damage << " damage" << endl<<endl;
			system("pause");
		}

		if (player->getHealth() <= 0) {
			cout << "Player Died" << endl;
			return -1;
		}
		else if (zed.getHealth() <= 0) {
			cout << zed.getName() << "Died. Player wins" << endl;
			return 0;
		}




	}


}