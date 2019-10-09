
#pragma once
#include "Dungon_Crawler/Dungon_Crawler.h"



int main() {
	srand(time(NULL));
	//Run();
	Spawner s;
	Shop shop(5,500);
	Player p;
	p.setLevel(6);
	p.RecieveMoney(500);
	p.addToInventory(s.CreateDagger(5,true));
	
	p.addToInventory(s.CreateDagger(5,true));
	p.addToInventory(s.CreateSword(5,true));

	shop.ShopDialogue(&p);

	cout<<"Success\nYay\nYay"<<endl;
	


	
}