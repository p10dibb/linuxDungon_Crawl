#include "Combat.h"



//player fighting zombie  return 0=zombie died -1=player died
int PlayerVsZombieCombat(Player* player, Zombie zed) {

	//speed totals who ever has the higher number gets to attack
	int playerSpeedTot = player->ActualSpeed();
	int ZombieSpeedTot = zed.getSpeed();


	int Damage = 0;
	int round = 1;
	int playerChoice=-1;
	while (1) {
		cout << "round: " << round <<",Level "<<zed.getLevel()<<" "<< zed.getName()<<" health:" << zed.getHealth() << " Player health:" << player->getHealth() << endl;
		// zed.DisplayDetails();
		 round++;
		 cout << "zombie speed tot: " << ZombieSpeedTot << " player speed tot: " << playerSpeedTot<<endl<<endl;

		if (ZombieSpeedTot > playerSpeedTot) {//zombie attacking
			cout << zed.getName() << "'s turn" << endl;
			cout << zed.getName() << " is attacking" << endl;
			
			//incriment player speed to see if player gets a turn
			playerSpeedTot += player->ActualSpeed();

			Damage = player->TakeDamage(zed.getAllDamageTypes());
			cout << player->getName() << " takes " << Damage << "damage" << endl<<endl;
		}
		else {//player is attacking
			cout << player->getName() << " Turn" << endl;

			//incriment the zombie speed to see if they get thier turn
			ZombieSpeedTot += zed.getSpeed();

			playerChoice=PlayersChoices(player);

			if (playerChoice==0){
				cout << player->getName() << " is Attacking" << endl;
				Damage = zed.TakeDamage(player->getAllDamageTypes());
				
			cout << zed.getName() << " takes " << Damage << " damage" << endl<<endl;
			getchar();
			getchar();
			}else if(playerChoice==1){//runaway
				cout << player->getName() << " is Running away" << endl;

				cout << zed.getName() << " attacks as you flee" << endl;

				Damage = player->TakeDamage(zed.getAllDamageTypes());
				cout << player->getName() << " takes " << Damage << "damage while trying to escape" << endl<<endl;
				if (player->getHealth() <= 0) {
				cout << player->getName()<<" Died while running away" << endl;
				return -1; //died in escape
				}else{
					return -2; //successfull escape
				}

			}

			
			
		}
		player->runDamageEffects();
		zed.runDamageEffects();
		if (player->getHealth() <= 0) {
			cout << "Player Died" << endl;
			return -1; // player died
		}
		else if (zed.getHealth() <= 0) {
			cout << zed.getName() << "Died. Player wins" << endl;
			return 0; //zed died
		}




	}


}

// prompsts player for options  returns 0 for attack and 1 for run
int PlayersChoices(Player* player){
	
	char input='\0';
	

	while(1){
	cout<<"would you like to [attack:1|Run:2|View inventory:3]: ";
	input = getchar();

	if (input=='1'){// attack
		return 0;
	}else if(input=='2'){// run away
		return 1;
	}
	else if(input=='3'){
		player->InventoryDialogue();
	}else{
		cout<<"not valid choice"<<endl;
	}
	}

}