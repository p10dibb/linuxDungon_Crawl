#pragma once
#include "../Shop/Shop.h"

int PlayerVsEnemyCombat(Player* player, Enemy *zed);

int PlayersChoices(Player* player);

//Applys a bezerk effect to the creature
bool ApplyBezerk(Creature * creature);

//Adds a Deffensive stance effect to the creature
bool ApplyDefensiveStance(Creature *creature);

//Applys QuickStrike effect to the creature
bool ApplyQuickStrike(Creature *creature);

//Adds a Swordsman effect to the creature
bool ApplySwordsman(Creature *creature);

//Adds an Animal Fury effect to creature
bool ApplyAnimalFury(Creature *creature);


