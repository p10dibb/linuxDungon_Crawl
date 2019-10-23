
#pragma once
#include "Dungon_Crawler/Dungon_Crawler.h"



int main() {
	srand(time(NULL));
	//Run();
	 Spawner s;
	Weapon* w;
	w=s.CreateClaws(100,true,true,Common_ItemRarity);
	cout<<"---------------"<<endl;
	w->DisplayDetails();
	w=s.CreateClaws(100,true,true,UnCommon_ItemRarity);
	cout<<"---------------"<<endl;
	w->DisplayDetails();
	w=s.CreateClaws(100,true,true,Rare_ItemRarity);
	cout<<"---------------"<<endl;
	w->DisplayDetails();
	w=s.CreateClaws(100,true,true,Legendary_ItemRarity);
	cout<<"---------------"<<endl;
	w->DisplayDetails();


	// Shop shop(5,500);
	// Player p;
	// p.setLevel(6);
	// p.RecieveMoney(500);
	// p.addToInventory(s.CreateDagger(5,true));
	
	// p.addToInventory(s.CreateDagger(5,true));
	// p.addToInventory(s.CreateSword(5,true));

	// shop.ShopDialogue(&p);

	// cout<<"Success\nYay\nYay"<<endl;

	// p.AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,10,3));
	// p.AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,Bleeding_Effects,10,2));

	// p.DisplayAllDamageOverTimeEffects();
	// cout<<"--------------------"<<endl;
	// p.DecrementAllDamageOverTimeEffects();
	// p.DisplayAllDamageOverTimeEffects();
	// cout<<"--------------------"<<endl;
	// p.DecrementAllDamageOverTimeEffects();
	// p.DisplayAllDamageOverTimeEffects();
	// cout<<"--------------------"<<endl;
	// p.DecrementAllDamageOverTimeEffects();
	
	// p.DisplayAllDamageOverTimeEffects();
	


	
	


	
}