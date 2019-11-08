	#include "Dungon_Crawler.h"


void Run() {
	srand(time(NULL));
	 Spawner s;
	Player player = createPlayer();
	
	// player.addToInventory(s.CreateDevSword());
	
	// player.addToInventory(s.CreateDevSword());
	
	// player.addToInventory(s.CreateDevHelmet(Light_ArmorClass));

	// player.addToInventory(s.CreateDevChest(Light_ArmorClass));
	
	// player.addToInventory(s.CreateDevBoots(Light_ArmorClass));
	
	// player.addToInventory(s.CreateDevGloves(Light_ArmorClass));
	
	// player.addToInventory(s.CreateDevPants(Light_ArmorClass));
	player.addToInventory(s.CreateAxe(1,true));
	player.addToInventory(s.CreateDagger(1,true));
	Armor *a;
	a=s.CreateBoots(1,Light_ArmorClass,true);
	DoubleLinkedList<ActiveEffects> e;
	e.add(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,25,10));
	a->setResistanceTypes(e);
	player.addToInventory(a);

	player.addToInventory(s.CreatePants(1,Light_ArmorClass,true));	
	player.addToInventory(s.CreateChest(1,Light_ArmorClass,true));
	player.addToInventory(s.CreateGloves(1,Light_ArmorClass,true));
	player.addToInventory(s.CreateHelmet(1,Light_ArmorClass,true));
	
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

void TestArmorStuff(){
	  Spawner s;
	Armor *a;
	int avgC=0,avgU=0,avgR=0,avgL=0;
	//Light
		cout<<"Light"<<endl;
		//Boots
			cout<<"Boots"<<endl;
			cout<<"Common,Uncommon,Rare,Legendary"<<endl;
			
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(1,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(1,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(1,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(1,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 1: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(5,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}	for(int j=0; j<1000;j++){
				a=s.CreateBoots(5,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(5,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(5,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 5: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(10,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
				for(int j=0; j<1000;j++){
				a=s.CreateBoots(10,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(10,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(10,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 10: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(15,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}	
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(15,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(15,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(15,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 15: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(20,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}	
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(20,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(20,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateBoots(20,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 20: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
		//----------
		//Pants
			cout<<"Pants"<<endl;
			cout<<"Common,Uncommon,Rare,Legendary"<<endl;
			
			for(int j=0; j<1000;j++){
				a=s.CreatePants(1,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(1,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(1,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(1,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 1: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreatePants(5,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}	for(int j=0; j<1000;j++){
				a=s.CreatePants(5,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(5,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(5,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 5: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreatePants(10,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
				for(int j=0; j<1000;j++){
				a=s.CreatePants(10,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(10,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(10,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 10: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreatePants(15,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}	
			for(int j=0; j<1000;j++){
				a=s.CreatePants(15,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(15,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(15,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 15: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreatePants(20,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}	
			for(int j=0; j<1000;j++){
				a=s.CreatePants(20,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(20,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreatePants(20,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 20: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
		//----------
		//Chest
			cout<<"Chest"<<endl;
			cout<<"Common,Uncommon,Rare,Legendary"<<endl;
			
			for(int j=0; j<1000;j++){
				a=s.CreateChest(1,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(1,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(1,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(1,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 1: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreateChest(5,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}	for(int j=0; j<1000;j++){
				a=s.CreateChest(5,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(5,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(5,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 5: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreateChest(10,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
				for(int j=0; j<1000;j++){
				a=s.CreateChest(10,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(10,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(10,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 10: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreateChest(15,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}	
			for(int j=0; j<1000;j++){
				a=s.CreateChest(15,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(15,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(15,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 15: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
			for(int j=0; j<1000;j++){
				a=s.CreateChest(20,Light_ArmorClass,true,true);
				avgC+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}	
			for(int j=0; j<1000;j++){
				a=s.CreateChest(20,Light_ArmorClass,true,true,UnCommon_ItemRarity);
				avgU+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(20,Light_ArmorClass,true,true,Rare_ItemRarity);
				avgR+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			for(int j=0; j<1000;j++){
				a=s.CreateChest(20,Light_ArmorClass,true,true,Legendary_ItemRarity);
				avgL+=a->getTotalResistance();
				//cout<<a->getTotalResistance()<<endl;
			}
			cout<<"level 20: "<<avgC/1000<<", " <<avgU/1000<<", "<<avgR/1000<<", "<<avgL/1000<<endl;
			avgC=0;
			avgU=0;
			avgR=0;
			avgL=0;
		//----------
		
	//----------
}

void TestResistanceEffects(){
	Player p;
	Armor * a = new Armor(10,1,Chest_ArmorType,Light_ArmorClass);
	
	Armor * a1 = new Armor(10,1,Boots_ArmorType,Light_ArmorClass);
	p.setHealth(500);
	p.setDefense(0);
	p.setTorso(a);
	//p.setFeet(a1);
	p.AddCombatEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,1));
	
	
	DoubleLinkedList<DamageTypes> dam;
	dam.add(DamageTypes(100));
	p.DisplayAllResistanceEffects();
	cout<<"player takes" <<p.TakeDamage(dam)<<endl;

}