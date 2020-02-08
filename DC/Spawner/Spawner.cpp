#include"Spawner.h"

Spawner::Spawner() {
	
}

////creates a Zombie based on the level inputed. should be the players level
Zombie Spawner::CreateZombie(int level, bool forceLevel ) {
	Zombie ret;
	
	//ransdomly sets name
	ret.setName(this->ZombieNames[rand() % this->ZombieNames.size()]);

	//sets level to range between playerlevel-3 and playerlevel+3
	if (forceLevel) {
		ret.setLevel(level);
	}
	else {
		ret.setLevel((level - 3) + rand() % 6);
	}

	ret.setPosition({ 1 + rand() % 8, 1 + rand() % 8 });
	//sets health and max health to 10 times its level
	ret.setHealth(10 * ret.getLevel());
	ret.setMaxHealth(10 * ret.getLevel());
		
	//sets base damage, defense, speed and stamina based on its level
	ret.setDamage((ret.getLevel()+1 / 2) + rand() % ret.getLevel());
	ret.setDefense((ret.getLevel()+1 / 4) + rand() % (ret.getLevel()+1 / 2));
	ret.setSpeed((ret.getLevel()+1 / 2) + rand() % ret.getLevel());
	ret.setStamina(rand() % 5);

	//sets weapon
	ret.setWeapon(CreateClaws(ret.getLevel(), true));

	//sets xp drop
	ret.setXP(ret.getLevel() + (ret.getDamage() + ret.getDefense()+ ret.getSpeed())/3);

	
	return ret;


}


////creates the zombies lootdrop
LootDrop Spawner::GenerateZombieLootDrop(Zombie zed) {
	int chance = 0;
	LootDrop ret;
	//100% chance of xp drop
	ret.xp = zed.getXP();
	ret.gold = 0;
	//50% chance of gold drop
	if (rand() % 2 == 0) {
		//gold drop is minimum of 5 and can have upto 5+the amount calculated for xp
		ret.gold = (rand() % zed.getXP()) + 5;
	}
	//10% chance of weapon drop
	if (rand() % 10 == 0) {
		ret.weapon = zed.getWeapon();
	}

	// 10% chance to drop armour
	if (rand() % 10 == 0){
		chance = rand() % 5;
		int armorClass = (rand() % 3);

		//randomly picks armour piece
		if (chance == 0) {
			ret.armour = this->CreateHelmet(zed.getLevel(),(ArmorClass_enum)armorClass);
		}
		else if (chance == 1) {
			ret.armour = this->CreateChest(zed.getLevel(), (ArmorClass_enum)armorClass);
		}
		else if (chance == 2) {
			ret.armour = this->CreateGloves(zed.getLevel(), (ArmorClass_enum)armorClass);
		}
		else if (chance == 3) {
			ret.armour = this->CreatePants(zed.getLevel(), (ArmorClass_enum)armorClass);
		}
		else if (chance == 4) {
			ret.armour = this->CreateBoots(zed.getLevel(), (ArmorClass_enum)armorClass);
		}

	}

	//20% chance of potion
	if (rand() % 5 == 0) {
		ret.potion=this->CreateRandomPotion_MoreHealth();

	}
	//other drops when added
	return ret;
}

//spawner for treasure chest
LootBox Spawner::CreateLootBox(int level){
	
	LootBox ret;
	int chance=0;

	//amount of items in chest
	chance=rand()%100;

	int amount=0;
	//5% for 5
	if(chance<5){
		amount=5;
	}
	//10% for 4
	else if(chance<15){
		amount=4;
	}
	//15% chance for 3
	else if(chance<30){
		amount=3;
	}
	//30% chance for 2
	else if(chance<60){
		amount=2;
	}
	//30% chance for 1
	else if(chance<90){
		amount=1;
	}
	//10% chance for 0
	else if(chance<100){
		amount=0;
	}
	//adds the items
	for(int i=0;i<amount;i++){
		switch (rand()%3)
		{
		//add potion
		case 0: ret.addItem(this->CreateRandomPotion_MoreHealth());break;
		//add Weapon
		case 1: ret.addItem(this->CreateRandomWeapon(level));break;
		//add Armor
		case 2: ret.addItem(this->CreateRandomArmor(level));break;
		default:
			break;
		}
	}

	//adds money
	chance=rand()%(level*10);
	ret.addMoney(chance);
	
	if(ret.isEmpty()){
		ret.addMoney(level+1);
	}

	return ret;	
}

