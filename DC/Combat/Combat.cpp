#include "Combat.h"



//player fighting zombie  return 0=zombie died -1=player died
int PlayerVsZombieCombat(Player* player, Zombie *zed) {
	//speed totals who ever has the higher number gets to attack
	int playerSpeedTot = player->ActualSpeed();
	int ZombieSpeedTot = zed->getSpeed();
	
	int Damage = 0;
	int round = 1;
	int playerChoice=-1;
	while (1) {
		cout << "round: " << round <<",Level "<<zed->getLevel()<<" "<< zed->getName()<<" health:" << zed->getHealth() << " Player health:" << player->getHealth() << endl;
		// zed.DisplayDetails();
		 round++;
		 
		if (ZombieSpeedTot > playerSpeedTot) {//zombie attacking
			cout << zed->getName() << "'s turn" << endl;
			cout << zed->getName() << " is attacking" << endl;
			
			//incriment player speed to see if player gets a turn
			playerSpeedTot += player->ActualSpeed();

			Damage = player->TakeDamage(zed->getAllDamageTypes());
			cout << player->getName() << " takes " << Damage << "damage" << endl<<endl;
		}
		else {//player is attacking
			cout << player->getName() << " Turn" << endl;

			//incriment the zombie speed to see if they get thier turn
			ZombieSpeedTot += zed->getSpeed();

			playerChoice=PlayersChoices(player);

			if (playerChoice==0){
				cout << player->getName() << " is Attacking" << endl;
				Damage = zed->TakeDamage(player->getAllDamageTypes());
				
				//stats incrementer
				player->IncrementDamageDealt(Damage);
				player->RewardCheckMaxDamageDealt(Damage);

				cout << zed->getName() << " takes " << Damage << " damage" << endl<<endl;
			
		
			}else if(playerChoice==1){//runaway
				cout << player->getName() << " is Running away" << endl;

				cout << zed->getName() << " attacks as you flee" << endl;

				Damage = player->TakeDamage(zed->getAllDamageTypes());

				//stats incrementer
				player->IncrementDamageRecieved(Damage);

				cout << player->getName() << " takes " << Damage << "damage while trying to escape" << endl<<endl;
				if (player->getHealth() <= 0) {
					cout << player->getName()<<" Died while running away" << endl;
					return -1; //died in escape
				}else{
					return -2; //successfull escape
				}

			}

			
			
		}
		player->IncrementDamageRecieved(player->runDamageOverTimeEffects());
		player->DecrementAllEffects();
		zed->runDamageOverTimeEffects();
		zed->DecrementAllEffects();
		cout<<"press enter to continue"<<endl;
		
		getchar();
		getchar();
		if (player->getHealth() <= 0) {
			cout << "Player Died" << endl;
			return -1; // player died
		}
		else if (zed->getHealth() <= 0) {
			cout << zed->getName() << "Died. Player wins" << endl;

			//stats incrementer
			player->IncrementCreaturesKilled();

			return 0; //zed died
		}

	}


}

// prompsts player for options  returns 0 for attack and 1 for run
int PlayersChoices(Player* player){
	
	string input="-1";
	//int i=0;

	while(1){
	cout<<"would you like to [attack:1| "<<player->getRight()->getCombatEffect().getEffectName()<<":2| "<<player->getLeft()->getCombatEffect().getEffectName()<<":3| ";
	cout<<"Run:4|View inventory:5]: ";
	cin>>input ;

	if (input=="1"){// attack
		return 0;
	}
	else if(input=="2"){
		player->AddCombatEffect(player->getRight()->getCombatEffect());
		cout<<player->getName()<<" used "<<player->getRight()->getCombatEffect().getEffectName()<<endl;
		return 2;
	}
	else if(input=="3"){
		player->AddCombatEffect(player->getLeft()->getCombatEffect());
		cout<<player->getName()<<" used "<<player->getLeft()->getCombatEffect().getEffectName()<<endl;
		return 3;

	}
	else if(input=="4"){// run away
		return 1;
	}
	else if(input=="5"){
		player->InventoryDialogue();
	}else{
		cout<<"not valid choice"<<endl;
	}
	}

}




// //Applys a bezerk effect to the creature
// bool ApplyBezerk(Creature * creature){
// 	creature->AddCombatEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,0,5));
// 	cout<<creature->getName()<<" Used Bezerk which boosts thier Damage but Decreases Defense"<<endl;
// 	return true;
// }

// //Adds a Deffensive stance effect to the creature
// bool ApplyDefensiveStance(Creature *creature){
// 	creature->AddCombatEffect(ActiveEffects(Combat_EffectTypes,DefensiveStance_Effects,0,5));
// 	cout<<creature->getName()<<" Used Defensive Stance which boosts thier Defense but Decreases Speed"<<endl;
// 	return true;
// }

// //Applys QuickStrike effect to the creature
// bool ApplyQuickStrike(Creature *creature){
// 	creature->AddCombatEffect(ActiveEffects(Combat_EffectTypes,QuickStrike_Effects,0,5));
// 	cout<<creature->getName()<<" Used Quick Strike which boosts thier Speed but Decreases Defense"<<endl;
// 	return true;
// }

// //Adds a Swordsman effect to the creature
// bool ApplySwordsman(Creature *creature){
// 	creature->AddCombatEffect(ActiveEffects(Combat_EffectTypes,Swordsman_Effects,0,5));
// 	cout<<creature->getName()<<" Used Defensive Stance which boosts thier Defense and Damage but Decreases Speed"<<endl;
// 	return true;
// }

// //Adds an Animal Fury effect to creature
// bool ApplyAnimalFury(Creature *creature){
// 	creature->AddCombatEffect(ActiveEffects(Combat_EffectTypes,AnimalFury_Effects,0,5));
// 	cout<<creature->getName()<<" Used Animal Fury which boosts thier Speed but Decreases Defense"<<endl;
// 	return true;
// }