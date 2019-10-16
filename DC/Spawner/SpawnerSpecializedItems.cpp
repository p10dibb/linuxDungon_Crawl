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

		ret->setDefense(100);
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

		ret->setDefense(300);
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

		ret->setDefense(100);
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

		ret->setDefense(200);
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

		ret->setDefense(200);
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
		ret->setDefense((ret->getLevel() / 2) + rand() % (RelativeLevel * Medium));
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

		ret->setValue((RelativeLevel/ 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level );

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
		ret->setDefense((ret->getLevel() / 2) + rand() % (RelativeLevel * Medium));
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
		

		ret->setValue((RelativeLevel/ 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level );

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


		ret->setValue((RelativeLevel/ 2) + (ret->getDamageTypes_Weapon().getData(1).getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4)+(ret->getDamageTypes_Weapon().Size()-3)*level );

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

		ret->setDefense(ret->getLevel()*(classMultiplier*this->small) + rand() % RelativeLevel);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

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

		ret->setDefense(ret->getLevel()*(classMultiplier*this->Large) + rand() % RelativeLevel);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

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

		ret->setDefense(ret->getLevel()*(classMultiplier*this->small) + rand() % RelativeLevel);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

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

		ret->setDefense(ret->getLevel()*(classMultiplier*this->Med) + rand() % RelativeLevel);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

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

		ret->setDefense(ret->getLevel()*(classMultiplier*this->Med) + rand() % RelativeLevel);
		ret->setStackSize(1);
		ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

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