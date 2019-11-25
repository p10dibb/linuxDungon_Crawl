
#pragma once
#include "Dungon_Crawler/Dungon_Crawler.h"
#include<map>

int main() {
	srand(time(NULL));
	//Run();
	//TestArmorStuff();
	// TestResistanceEffects();	

	Creature c;


	c.AddEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,10));
    //c.AddEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,3));
	//c.AddEffect(ActiveEffects(Combat_EffectTypes,Swordsman_Effects,5,5));
    c.AddEffect(ActiveEffects(Combat_EffectTypes,Swordsman_Effects,2,1));


	c.DecrementAllCombatEffects();
	c.DecrementAllCombatEffects();
}
