#include "Spawner.h"
//Dev gear------------
	Armor* Spawner::CreateDevHelmet( ArmorClass_enum c){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();

		ret->setType(Helmet_ArmorType);
		ret->setLevel(1);
		ret->setRarity(DEVELOPER_ItemRarity);


		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}

		ret->setName(classType+ " GOD HELM");

		
		ret->setWeight(1);
		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,100,15));
		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(0);

		return ret;
	}
	Armor* Spawner::CreateDevChest(ArmorClass_enum c){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();

		ret->setType(Chest_ArmorType);
		ret->setLevel(1);
		ret->setRarity(DEVELOPER_ItemRarity);


		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}

		ret->setName(classType+ " GOD BREASTPLATE");

		
		ret->setWeight(1);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,100,15));
		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(0);

		return ret;
	}
	Armor* Spawner::CreateDevGloves( ArmorClass_enum c){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();

		ret->setType(Gloves_ArmorType);
		ret->setLevel(1);
		ret->setRarity(DEVELOPER_ItemRarity);


		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}

		ret->setName(classType+ " GOD GAUNTLETS");

		
		ret->setWeight(1);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,100,15));
		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(0);

		return ret;
	}
	Armor* Spawner::CreateDevPants( ArmorClass_enum c){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();

		ret->setType(Pants_ArmorType);
		ret->setLevel(1);
		ret->setRarity(DEVELOPER_ItemRarity);


		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}



		ret->setName(classType+ " GOD LEGGINGS");

		
		ret->setWeight(1);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,100,15));
		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(0);

		return ret;





	}
	Armor* Spawner::CreateDevBoots ( ArmorClass_enum c){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();

		ret->setType(Boots_ArmorType);
		ret->setLevel(1);
		ret->setRarity(DEVELOPER_ItemRarity);


		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}



		ret->setName(classType+ " GOD BOOTS");

		
		ret->setWeight(1);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,100,15));
		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(0);

		return ret;





	}		
	Weapon* Spawner::CreateDevSword(){
			Weapon* ret = new Weapon();

			ret->setType(Sword_WeaponType);

			ret->setRarity(DEVELOPER_ItemRarity);
			//sets level to range between level-3 and level+3
		
			ret->setLevel(1);

			//random name generation
			ret->setName("THE GOD SWORD");

			

			//sets damage to medium, speed to medium, defense to extra medium
			ret->addDamageType(DamageTypes(100));
			//adds a critical damage chance
			ret->addDamageType(DamageTypes(200,80,Critical_DamageType));


			ret->setSpeed(50);
			ret->setDefense(100);
			ret->setRange(Medium);
			ret->setStackSize(1);
			ret->setTwoHanded(false);
			ret->setWeight(1);

			//adds random other effects Sword gets Fire(5%), stabing(10%),Blunt(10%)  //max of 25 Probability



			ret->setValue(0);
			return ret;

	}
//----------

//extinctionist Gear -----Creatureskilled Rewards
	//all weapons have a garenteed 50% chance of bleeding

	Weapon* Spawner::CreateExtinctionistSword(int level){
		Weapon* ret = new Weapon();
		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;

		ret->setType(Sword_WeaponType);		
		
		ret->setRarity(Unique_ItemRarity);

		ret->setLevel(level);


		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);
		
		ret->setName("Extinctionist's Sword");

		//sets damage to medium, speed to medium, defense to extra medium
		ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Medium)));
		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Medium),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));


		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Medium));
		ret->setDefense(((RelativeLevel*Medium)/2) + rand() % (RelativeLevel*Medium)/2);
		ret->setRange(Medium);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		ret->setWeight((rand() % 3) + 2);

		//adds random other effects Sword gets Fire(5%), stabing(10%),Blunt(10%)  //max of 25 Probability

		//garenteed 50 % chance of bleeding
		ret->addDamageType(DamageTypes(RelativeLevel/2,50,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
	

		
		if (rand()%20==0){		
			ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		}
	
		
		if (rand()%10==0){
			ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
	
		}

		ret->setValue((RelativeLevel/ 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense().getResistance() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level );

		return ret;

	}
	Weapon* Spawner::CreateExtinctionistDagger(int level){
		Weapon* ret = new Weapon();
		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;

		ret->setType(Dagger_WeaponType);		
		
		ret->setRarity(Unique_ItemRarity);

		ret->setLevel(level);


		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);
		

		ret->setName("Extinctionist's Dagger");

		//sets damage to medium, speed to medium, defense to extra medium
		ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Weak)));
		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Weak),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));


		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Strong));
		ret->setDefense(((RelativeLevel*Weak)/2) + rand() % (RelativeLevel*Weak)/2);
		ret->setRange(Medium);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		ret->setWeight((rand() % 3) + 2);

		//adds random other effects Sword gets Fire(5%), stabing(10%),Blunt(10%)  //max of 25 Probability

		//garenteed 50 % chance of bleeding
		ret->addDamageType(DamageTypes(RelativeLevel/2,50,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
			

		if (rand()%20==0){		
			ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		}
			ret->addDamageType(DamageTypes(RelativeLevel/2,50,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
		

		ret->setValue((RelativeLevel/ 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense().getResistance() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level );

		return ret;

	}
	Weapon* Spawner::CreateExtinctionistAxe(int level){
		Weapon* ret = new Weapon();
		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;

		ret->setType(Axe_WeaponType);		
		
		ret->setRarity(Unique_ItemRarity);

		ret->setLevel(level);


		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setName("Extinctionist's Axe");

		//sets damage to medium, speed to medium, defense to extra medium
		ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Strong)));
		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Strong),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));


		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Weak));
		ret->setDefense((ret->getLevel() / 2) + rand() % (RelativeLevel * Medium));
		ret->setDefense(((RelativeLevel*Medium)/2) + rand() % (RelativeLevel*Medium)/2);
		ret->setRange(Medium);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		ret->setWeight((rand() % 3) + 2);

		//adds random other effects Sword gets Fire(5%), stabing(10%),Blunt(10%)  //max of 25 Probability

		//garenteed 50 % chance of bleeding
		ret->addDamageType(DamageTypes(RelativeLevel/2,50,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
	

		if (rand()%20==0){		
			ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		}		
	
		if (rand()%10==0){
			ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
	
		}


		ret->setValue((RelativeLevel/ 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense().getResistance() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level );

		return ret;

	}

	Armor* Spawner::CreateExtinctionistHelmet(int level){
		int classMultiplier = this->M;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		
		
		ret->setRarity(Unique_ItemRarity);
	
		
		
		ret->setLevel(level);
		
		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Normal_ArmorClass);
		
		ret->setType(Helmet_ArmorType);

		
	

		ret->setName("Extinctionist's Helmet");

		
		ret->setWeight(this->small*classMultiplier+rand()%classMultiplier);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		//garenteed stabbing resistance
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		ret->setResistanceTypes(Resistance);

		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + ret->getResistanceTypes().Size()+ ret->getWeight());

		return ret;

	}
	Armor* Spawner::CreateExtinctionistChest(int level){
		int classMultiplier = this->M;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		
		
		ret->setRarity(Unique_ItemRarity);
	
		
		
		ret->setLevel(level);
		
		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Normal_ArmorClass);
		
		ret->setType(Chest_ArmorType);

		
	

		ret->setName("Extinctionist's Chest Piece");

		
		ret->setWeight(this->Large*classMultiplier+rand()%classMultiplier);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		//garenteed stabbing resistance
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + (ret->getResistanceTypes().Size()+ ret->getWeight()));

		return ret;

	}
	Armor* Spawner::CreateExtinctionistGloves(int level){
		int classMultiplier = this->M;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		
		
		ret->setRarity(Unique_ItemRarity);
	
		
		
		ret->setLevel(level);
		
		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Normal_ArmorClass);
		
		ret->setType(Gloves_ArmorType);

		
	

		ret->setName("Extinctionist's Gloves");

		
		ret->setWeight(this->small*classMultiplier+rand()%classMultiplier);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		//garenteed stabbing resistance
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + (ret->getResistanceTypes().Size()+ ret->getWeight()));

		return ret;

	}
	Armor* Spawner::CreateExtinctionistPants(int level){
		int classMultiplier = this->M;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		
		
		ret->setRarity(Unique_ItemRarity);
	
		
		
		ret->setLevel(level);
		
		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Normal_ArmorClass);
		
		ret->setType(Pants_ArmorType);

		
	

		ret->setName("Extinctionist's Leggings");

		
		ret->setWeight(this->Med*classMultiplier+rand()%classMultiplier);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		//garenteed stabbing resistance
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + (ret->getResistanceTypes().Size()+ ret->getWeight()));

		return ret;

	}
	Armor* Spawner::CreateExtinctionistBoots (int level){
		int classMultiplier = this->M;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		
		
		ret->setRarity(Unique_ItemRarity);
	
		
		
		ret->setLevel(level);
		
		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Normal_ArmorClass);
		
		ret->setType(Boots_ArmorType);

		
	

		ret->setName("Extinctionist's Helmet");

		
		ret->setWeight(this->Med*classMultiplier+rand()%classMultiplier);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		//garenteed stabbing resistance
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + (ret->getResistanceTypes().Size()+ ret->getWeight()));
		return ret;

	}
	
	Item * Spawner::CreateRandomExtinctionistItem(int level){

		switch (rand()%8)
		{
		case 0:return this->CreateExtinctionistSword(level);break;
		case 1:return this->CreateExtinctionistAxe(level);break;
		case 2:return this->CreateExtinctionistDagger(level);break;
		case 3:return this->CreateExtinctionistHelmet(level);break;
		case 4:return this->CreateExtinctionistChest(level);break;
		case 5:return this->CreateExtinctionistGloves(level);break;
		case 6:return this->CreateExtinctionistPants(level);break;
		case 7:return this->CreateExtinctionistBoots(level);break;

		}
	}
//------------------

//Goldmonger gear --------   Reward for Total Gold Collected  Rewards	
	//spawns a random Goldmanger Item
	Item * Spawner::CreateRandomGoldMongerItem(int level){
		switch(rand()%7){
			case 0:return this->CreateGoldMongerAxe(level);
			case 1:return this->CreateGoldMongerShield(level);
			case 2:return this->CreateGoldMongerBoots(level);
			case 3:return this->CreateGoldMongerChest(level);
			case 4:return this->CreateGoldMongerGloves(level);
			case 5:return this->CreateGoldMongerHelmet(level);
			case 6:return this->CreateGoldMongerPants(level);
		}
	}

	//Reward for GoldCollected 
	Weapon* Spawner::CreateGoldMongerAxe(int level){
		Weapon* ret = new Weapon();
		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;

		ret->setType(Axe_WeaponType);		
		
		ret->setRarity(Unique_ItemRarity);

		ret->setLevel(level);


		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setName("Goldmonger's Axe");

		//sets damage to medium, speed to medium, defense to extra medium
		ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Strong)));
		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Strong),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));


		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Weak));
		ret->setDefense(((RelativeLevel*Medium)/2) + rand() % (RelativeLevel*Medium)/2);
		ret->setRange(Medium);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		//tripple weight
		ret->setWeight(((rand() % 3) + 2)*3);

		
		
		//has increase effect chance compared to normal Axe
		if (rand()%30==0){		
			ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		}		
	
		if (rand()%30==0){
			ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
	
		}
		if (rand()%30==0){
			ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
	
		}
		ret->setValue(ret->getLevel()*10);
		ret->setDescription("Solid Gold so extra heavy and extra valuable");

		return ret;

	}
	//Reward for GoldCollected
	Weapon* Spawner::CreateGoldMongerShield(int level){
		Weapon* ret=new Weapon();
		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;

		ret->setRarity(Unique_ItemRarity);
		
		ret->setLevel(level);

		ret->setType(Shield_WeaponType);

		RelativeLevel=ret->getLevel()*(ret->getRarity()+1);

		ret->setName("Goldmonger's Shield");

		//sets damage to extra weak ,speed to medium and defense to extra strong //adds default Normal damage type;
		ret->addDamageType(DamageTypes(ret->getLevel()/2 + rand() % (RelativeLevel * Weak)));
		
		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Weak),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));

		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Medium));
		ret->setDefense((ret->getLevel() ) + rand() % RelativeLevel*Strong);
		ret->setDefense(((RelativeLevel*Strong)/2) + rand() % (RelativeLevel*Strong)/2);
		ret->setRange(Weak);
		ret->setStackSize(1);
		ret->setTwoHanded(false);

		//tripple standard weight
		ret->setWeight(((rand() % 3) + 1)*3);		

		//has chance of the other effects not just blunt
		if (rand()%2==0){
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
		}
		if (rand()%10==0){
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
		}
		if (rand()%10==0){
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		}

		ret->setValue(ret->getLevel()*10);
		ret->setDescription("Solid Gold so extra heavy and extra valuable");

		return ret;
	}
		
	//Reward for GoldCollected
	Armor* Spawner::CreateGoldMongerHelmet(int level){
		int classMultiplier = this->H;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;		
		
		ret->setRarity(Unique_ItemRarity);		
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Heavy_ArmorClass);
		
		ret->setType(Helmet_ArmorType);		

		ret->setName("Goldmonger's Helmet");
		
		ret->setWeight((this->small*classMultiplier+rand()%classMultiplier)*3);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));

		//10% chance for each resistance
		//Fire Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		}
		//StabbingResistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		}
		//Poison Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		}
		//Blunt Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		}

		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel()*10);
		ret->setDescription("Solid Gold so extra heavy and extra valuable");

		return ret;

	}
	//Reward for GoldCollected
	Armor* Spawner::CreateGoldMongerChest(int level){
		int classMultiplier = this->H;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;	
		
		ret->setRarity(Unique_ItemRarity);		
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Heavy_ArmorClass);
		
		ret->setType(Chest_ArmorType);	

		ret->setName("Goldmonger's Chest Piece");
		
		//extra heavy
		ret->setWeight((this->Large*classMultiplier+rand()%classMultiplier)*3);

		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));

		//10% chance for each resistance
		//Fire Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		}
		//StabbingResistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		}
		//Poison Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		}
		//Blunt Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		}

		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel()*10);
		ret->setDescription("Solid Gold so extra heavy and extra valuable");

		return ret;

	}
	//Reward for GoldCollected
	Armor* Spawner::CreateGoldMongerGloves(int level){
		int classMultiplier = this->H;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;		
		
		ret->setRarity(Unique_ItemRarity);		
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Heavy_ArmorClass);
		
		ret->setType(Gloves_ArmorType);	

		ret->setName("Goldmonger's Gloves");
		
		ret->setWeight((this->small*classMultiplier+rand()%classMultiplier)*10);
		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));

		//10% chance for each resistance
		//Fire Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		}
		//StabbingResistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		}
		//Poison Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		}
		//Blunt Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		}

		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() *10);
		ret->setDescription("Solid Gold so extra heavy and extra valuable");

		return ret;

	}
	//Reward for GoldCollected
	Armor* Spawner::CreateGoldMongerPants(int level){
		int classMultiplier = this->H;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;		
		
		ret->setRarity(Unique_ItemRarity);	
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Heavy_ArmorClass);
		
		ret->setType(Pants_ArmorType);	

		ret->setName("Goldmonger's Leggings");
		
		ret->setWeight((this->Med*classMultiplier+rand()%classMultiplier)*3);
		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));

		//10% chance for each resistance
		//Fire Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		}
		//StabbingResistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		}
		//Poison Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		}
		//Blunt Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		}

		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel()*10);
		ret->setDescription("Solid Gold so extra heavy and extra valuable");

		return ret;

	}
	//Reward for GoldCollected
	Armor* Spawner::CreateGoldMongerBoots (int level){
		int classMultiplier = this->H;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;		
		
		ret->setRarity(Unique_ItemRarity);		
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Rare_ItemRarity+1);

		ret->setClass(Heavy_ArmorClass);
		
		ret->setType(Boots_ArmorType);	

		ret->setName("Goldmonger's Helmet");
		
		ret->setWeight((this->Med*classMultiplier+rand()%classMultiplier)*3);
		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));

		//10% chance for each resistance
		//Fire Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		}
		//StabbingResistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		}
		//Poison Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		}
		//Blunt Resistance
		if(rand()%10==0){
			Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		}

		ret->setResistanceTypes(Resistance);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel()*10);

		return ret;

	}
//---------------------------------------

//a Unique Dagger that has increase stabbing Damage  Reward for getting 69 related stats
Weapon* Spawner::CreateNICE(int level){
	Weapon* ret = new Weapon();
		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;

		ret->setType(Dagger_WeaponType);		
		
		ret->setRarity(Unique_ItemRarity);

		ret->setLevel(level);


		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);
		

		ret->setName("NICE");

		//sets damage to medium, speed to medium, defense to extra medium
		ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Weak)));
		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Weak),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));


		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Strong));
		ret->setDefense((ret->getLevel() / 2) + rand() % (RelativeLevel * Medium));
		ret->setRange(Medium);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		ret->setWeight((rand() % 3) + 2);

		//adds random other effects Sword gets Fire(5%), stabing(10%),Blunt(10%)  //max of 25 Probability

		//garenteed 50 % chance of bleeding
		ret->addDamageType(DamageTypes(RelativeLevel/2,100,Stabbing_DamageType,true,RelativeLevel/8,rand()%8));
			

		if (rand()%20==0){		
			ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		}
			ret->addDamageType(DamageTypes(RelativeLevel/2,50,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
		
		ret->setDescription("Great at penetrating the enemy");

		if(ret->getLevel()<25){
			ret->setValue(69);
		}else{
			ret->setValue(420);
		}
		
		return ret;
}

//a unique Shield with garenteed blunt damage and high  42% chance of burning
Weapon* Spawner::CreateTheMarly(int level) {
	Weapon* ret=new Weapon();
	//the actual weapon level multipied by its rarity used for random generation;
	int RelativeLevel=1;

		int chance=rand()%20;

	
		ret->setRarity(Unique_ItemRarity);

	
		ret->setLevel(level);
	
	

	ret->setType(Shield_WeaponType);

	RelativeLevel=ret->getLevel()*(ret->getRarity()+1);



	ret->setName("The Marley");

	//sets damage to extra weak ,speed to medium and defense to extra strong //adds default Normal damage type;
	ret->addDamageType(DamageTypes(ret->getLevel()/2 + rand() % (RelativeLevel * Weak)));
	
	//adds a critical damage chance
	ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Weak),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));

	ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Medium));
	ret->setDefense((ret->getLevel() ) + rand() % RelativeLevel*Strong);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);


	

	
	
	ret->addDamageType(DamageTypes(RelativeLevel/2,100,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
	ret->addDamageType(DamageTypes(RelativeLevel/2,42,Fire_DamageType,true,RelativeLevel/4,rand()%8));
	ret->setDescription("Great at Doing Blunt Damage and Blazing Enemies");
	

	ret->setValue(420);

	return ret;
}


//Collector's Gear----------Reward for collecting Items
	Item * Spawner::CreateRandomCollectorItem(int level){
		switch(rand()%10){
			case 0:return this->CreateCollectorSword(level);
			case 1:return this->CreateCollectorAxe(level);
			case 2: return this->CreateCollectorDagger(level);
			case 3: return this->CreateClaws(level);
			case 4: return this->CreateCollectorShield(level);
			case 5: return this->CreateCollectorHelmet(level);
			case 6: return this->CreateCollectorChest(level);
			case 7: return this->CreateCollectorBoots(level);
			case 8: return this->CreateCollectorPants(level);
			case 9: return this->CreateCollectorGloves(level);
		}
	}

	Weapon* Spawner::CreateCollectorSword(int level){
		Weapon* ret=new Weapon();

		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;

		ret->setRarity(Unique_ItemRarity);			
		
		ret->setLevel(level);		
			
		ret->setType(Sword_WeaponType);

		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setName("Collector's Sword");

		//sets damage to med, speed to strong, defense to extra weak adds default Normal damage type;
		ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel) * Medium));

		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Medium),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));

		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Medium));
		//sets Resistance effect to weapon
		ret->setDefense(((RelativeLevel*Medium)/2) + rand() % (RelativeLevel*Medium)/2);
		ret->setRange(Medium);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		ret->setWeight((rand() % 3) + 1);

		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);

		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Poison_DamageType,true,RelativeLevel/4,rand()%8));
				
		ret->setValue((RelativeLevel / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense().getResistance() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);

		ret->setDescription("Gotta have it All");
		return ret;
	}
	Weapon* Spawner::CreateCollectorDagger(int level){
		Weapon* ret=new Weapon();

		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;

		ret->setRarity(Unique_ItemRarity);			
		
		ret->setLevel(level);		
			
		ret->setType(Dagger_WeaponType);

		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setName("Collector's Daggers");

		//sets damage to med, speed to strong, defense to extra weak adds default Normal damage type;
		ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel) * Medium));

		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Medium),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));

		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Strong));
		//sets Resistance effect to weapon
		ret->setDefense(((RelativeLevel*Medium)/2) + rand() % (RelativeLevel*Weak)/2);
		ret->setRange(Medium);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		ret->setWeight((rand() % 3) + 1);

		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);

		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Poison_DamageType,true,RelativeLevel/4,rand()%8));
				
		ret->setValue((RelativeLevel / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense().getResistance() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);

		ret->setDescription("Gotta have it All");
		return ret;
	}	
	Weapon* Spawner::CreateCollectorAxe(int level){
		Weapon* ret = new Weapon();
		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;
		
		ret->setRarity(Unique_ItemRarity);
		

		
		ret->setLevel(level);
		
		

		ret->setType(Axe_WeaponType);

		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setName("Collector's Axe");

		//sets damage to strong, speed to weak, defense to extra medium adds default Normal damage type;
		ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Strong)));
		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Strong),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));


		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Weak));
		ret->setDefense(((RelativeLevel*Medium)/2) + rand() % (RelativeLevel*Medium)/2);

		ret->setRange(Weak);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		ret->setWeight((rand() % 3) + 1);


		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);

		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Poison_DamageType,true,RelativeLevel/4,rand()%8));
					
		ret->setDescription("Gotta have it All");
		ret->setValue((RelativeLevel / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage()/ 4) + (ret->getDefense().getResistance() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);


		return ret;


	}	
	Weapon* Spawner::CreateCollectorShield(int level){
		Weapon* ret=new Weapon();
		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;
		ret->setRarity(Unique_ItemRarity);
	
		ret->setLevel(level);
		

		ret->setType(Shield_WeaponType);

		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setName("Collector's Shield");

		//sets damage to extra weak ,speed to medium and defense to extra strong //adds default Normal damage type;
		ret->addDamageType(DamageTypes(ret->getLevel()/2 + rand() % (RelativeLevel * Weak)));
		
		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Weak),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));

		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Medium));
		ret->setDefense(((RelativeLevel*Strong)/2) + rand() % (RelativeLevel*Strong)/2);
		
		ret->setRange(Weak);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		ret->setWeight((rand() % 3) + 1);

		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);

		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Poison_DamageType,true,RelativeLevel/4,rand()%8));				


		ret->setValue((RelativeLevel / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense().getResistance() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-2)*level+(ret->getDamageTypes_Weapon().Size()-3)*level);
		ret->setDescription("Gotta have it All");

		return ret;
	}
	Weapon* Spawner::CreateCollectorClaws(int level){
		Weapon* ret= new Weapon();
		//the actual weapon level multipied by its rarity used for random generation;
		int RelativeLevel=1;

		ret->setName("Claws");
		ret->setType(Claw_WeaponType);

		ret->setRarity(Unique_ItemRarity);
		
		ret->setLevel(level);
		
			
		RelativeLevel= ret->getLevel()*((int)ret->getRarity()+1);
			
		
		//adds default Normal damage type;sets damage to medium, speed to strong, sets defense to extra weak
		ret->addDamageType(DamageTypes(ret->getLevel() + rand() % (RelativeLevel * Medium)));
		//adds a critical damage chance
		ret->addDamageType(DamageTypes(RelativeLevel/2 + rand() % (RelativeLevel * Weak),rand()%(10*(ret->getRarity()+1)),Critical_DamageType));
			


		ret->setSpeed(ret->getLevel() + rand() % (RelativeLevel * Strong));
		ret->setDefense(((RelativeLevel*Weak)/2) + rand() % (RelativeLevel*Weak)/2);
		ret->setRange(Weak);
		ret->setStackSize(1);
		ret->setTwoHanded(false);
		ret->setWeight((rand() % 3) + 1);

		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);

		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Fire_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Stabbing_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%10*(ret->getRarity()+1))+1,Blunt_DamageType,true,RelativeLevel/4,rand()%8));
		//garenteed chance of each damage type
		ret->addDamageType(DamageTypes(RelativeLevel/2,(rand()%(10*(ret->getRarity()+1)))+1,Poison_DamageType,true,RelativeLevel/4,rand()%8));				

		ret->setDescription("Gotta have it All");

		ret->setValue((RelativeLevel / 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense().getResistance() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level);


			return ret;
	}
		
	Armor* Spawner::CreateCollectorHelmet(int level){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		ArmorClass_enum c;
		c=(ArmorClass_enum)((rand()%3) +1);
		
		ret->setRarity(Unique_ItemRarity);	
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setClass(c);
		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}
		ret->setType(Helmet_ArmorType);

		ret->setName("Collector's "+classType+ " Helmet");

		
		ret->setWeight(this->small*classMultiplier+rand()%classMultiplier);

		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);
		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		

		ret->setResistanceTypes(Resistance);


		ret->setStackSize(1);
		ret->setValue(RelativeLevel+ret->getResistanceTypes().Size() + ret->getWeight());

		return ret;

	}
	Armor* Spawner::CreateCollectorChest(int level){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		ArmorClass_enum c;
		c=(ArmorClass_enum)((rand()%3) +1);
		
		ret->setRarity(Unique_ItemRarity);	
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setClass(c);
		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";
			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}
		ret->setType(Chest_ArmorType);

		ret->setName("Collector's "+classType+ " Chest");

		
		ret->setWeight(this->Large*classMultiplier+rand()%classMultiplier);

		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);
		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Large),15));
		

		ret->setResistanceTypes(Resistance);


		ret->setStackSize(1);
		ret->setValue(RelativeLevel+ret->getResistanceTypes().Size() + ret->getWeight());

		return ret;

	}
	Armor* Spawner::CreateCollectorGloves(int level){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		ArmorClass_enum c;
		c=(ArmorClass_enum)((rand()%3) +1);
		
		ret->setRarity(Unique_ItemRarity);	
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setClass(c);
		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}
		ret->setType(Gloves_ArmorType);

		ret->setName("Collector's "+classType+ " Gloves");

		
		ret->setWeight(this->small*classMultiplier+rand()%classMultiplier);

		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);
		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->small),15));
		

		ret->setResistanceTypes(Resistance);


		ret->setStackSize(1);
		ret->setValue(RelativeLevel+ret->getResistanceTypes().Size() + ret->getWeight());

		return ret;

	}
	Armor* Spawner::CreateCollectorPants(int level){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		ArmorClass_enum c;
		c=(ArmorClass_enum)((rand()%3) +1);
		
		ret->setRarity(Unique_ItemRarity);	
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setClass(c);
		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}
		ret->setType(Pants_ArmorType);

		ret->setName("Collector's "+classType+ " Pants");

		
		ret->setWeight(this->Med*classMultiplier+rand()%classMultiplier);

		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);
		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		

		ret->setResistanceTypes(Resistance);


		ret->setStackSize(1);
		ret->setValue(RelativeLevel+ret->getResistanceTypes().Size() + ret->getWeight());

		return ret;

	}
	Armor* Spawner::CreateCollectorBoots (int level){
		int classMultiplier = 1;
		string classType = "";
		Armor* ret= new Armor();
		int RelativeLevel=1;
		ArmorClass_enum c;
		c=(ArmorClass_enum)((rand()%3) +1);
		
		ret->setRarity(Unique_ItemRarity);	
		
		ret->setLevel(level);		

		RelativeLevel=ret->getLevel()*(Legendary_ItemRarity+1);

		ret->setClass(c);
		switch (c)
		{
		case Light_ArmorClass: classMultiplier = this->L; classType = " Light";

			break;
		case Normal_ArmorClass: classMultiplier = this->M; classType = " Normal";
			break;
		case Heavy_ArmorClass: classMultiplier = this->H; classType = " Heavy";
			break;
		default:
			break;
		}
		ret->setType(Boots_ArmorType);

		ret->setName("Collector's "+classType+ " Boots");

		
		ret->setWeight(this->Med*classMultiplier+rand()%classMultiplier);

		RelativeLevel=ret->getLevel()*(Common_ItemRarity+1);
		DoubleLinkedList<ActiveEffects> Resistance;
		Resistance.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		
		Resistance.add(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,((rand() % RelativeLevel)*classMultiplier*this->Med),15));
		

		ret->setResistanceTypes(Resistance);


		ret->setStackSize(1);
		ret->setValue(RelativeLevel+ret->getResistanceTypes().Size() + ret->getWeight());

		return ret;

	}

//-------