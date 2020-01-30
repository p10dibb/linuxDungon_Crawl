#include "Player.h"
#include <gtest/gtest.h>

//default constructor
TEST(PlayerTest,DefaultConstructor){
    Player p;
    EXPECT_EQ(1,p.getDamage());
    EXPECT_EQ(1,p.getDefense());
    EXPECT_EQ(100,p.getHealth());
    EXPECT_EQ(100,p.getMaxHealth());
    EXPECT_EQ(1,p.getSpeed());
    EXPECT_EQ(1,p.getStrength());
    EXPECT_EQ(1,p.getStamina());
    EXPECT_EQ(40,p.getFreeSlots());
    EXPECT_EQ(40,p.getInventorySize());
    EXPECT_EQ(10,p.getLevelUp());
    EXPECT_EQ(50,p.getMaxWeight());   
    EXPECT_EQ(0,p.getMoney()) ;
    
}

//pause menue
TEST(PlayerTest,PauseMenue){
    EXPECT_EQ(1,1);
    //test using mock
}

//Display Details
TEST(PlayerTest,DisplayDetails){
    Player p;
    p.DisplayDetails();
    EXPECT_FALSE(false);
}

//actual speed
TEST(PlayerTest,ActualSpeed){
    Player p;
    Weapon *wL = new Weapon();
    Weapon *wR = new Weapon();
    Armor *head = new Armor();
    Armor *chest = new Armor();
    Armor *gloves = new Armor();
    Armor *pants = new Armor();
    Armor *boots = new Armor();

    head->setType(Helmet_ArmorType);
    head->setWeight(0);
    chest->setType(Chest_ArmorType);
    chest->setWeight(0);
    gloves->setType(Gloves_ArmorType);
    gloves->setWeight(0);
    pants->setType(Pants_ArmorType);
    pants->setWeight(0);
    boots->setType(Boots_ArmorType);
    boots->setWeight(0);
    wL->setType(NULL_WeaponType);
    wR->setType(NULL_WeaponType);


    //sets weapon types to null so that it trigures the first if statement with no armor
    p.setLeft(wL);
    p.setRight(wR);
    p.setHead(head);
    p.setTorso(chest);
    p.setHands(gloves);
    p.setLegs(pants);
    p.setFeet(boots);

    p.setSpeed(1);
    p.setStrength(1);
    EXPECT_EQ(1,p.ActualSpeed());

    //Null weapons but armor has weight but speed will drop below 0 so it is set to 1
    chest->setWeight(5);
    p.setTorso(chest);

    EXPECT_EQ(1,p.ActualSpeed());

    //above negative should lose 10 since 5 weight of chest plate and strength of 1
    p.setSpeed(20);

    EXPECT_EQ(10,p.ActualSpeed());

    //second if statement to do left only 
    wL->setSpeed(6);
    wL->setType(Axe_WeaponType);

    p.setLeft(wL);
    
    EXPECT_EQ(16,p.ActualSpeed());

    //now third if Only right weapon;
    wL->setType(NULL_WeaponType);

    wR->setSpeed(6);
    wR->setType(Sword_WeaponType);

    p.setRight(wR);
    p.setLeft(wL);
    
    EXPECT_EQ(16,p.ActualSpeed());

    //now 4th if both hands
    wL->setType(Axe_WeaponType);

    p.setLeft(wL);

    EXPECT_EQ(14,p.ActualSpeed());

    //test speed modifiers
    //sets speed to 100
    wL->setType(NULL_WeaponType);
    wR->setType(NULL_WeaponType);
    p.setSpeed(110);
    p.setLeft(wL);
    p.setRight(wR);

    EXPECT_EQ(100, p.ActualSpeed());

    //tests slowed effect
    p.AddEffect(ActiveEffects(DeBuff_EffectTypes,Slowed_Effects,1,1));

    EXPECT_EQ(75,p.ActualSpeed());
    p.DecrementAllEffects();

    //tests Dazed effect
    p.AddEffect(ActiveEffects(DeBuff_EffectTypes,Dazed_Effects,1,1));
    EXPECT_EQ(75,p.ActualSpeed());
    p.DecrementAllEffects();

    //tests quick strike effect
    p.AddCombatEffect(ActiveEffects(Combat_EffectTypes,QuickStrike_Effects,1,1));
    EXPECT_EQ(125,p.ActualSpeed());
    p.DecrementAllEffects();

    //tests Animal Fury 
    p.AddCombatEffect(ActiveEffects(Combat_EffectTypes,AnimalFury_Effects,1,1));
    EXPECT_EQ(125,p.ActualSpeed());
    p.DecrementAllEffects();

    //Defensive Stance
    p.AddCombatEffect(ActiveEffects(Combat_EffectTypes,DefensiveStance_Effects,1,1));
    EXPECT_EQ(75,p.ActualSpeed());
    p.DecrementAllEffects();

    //Swordsman 
    p.AddCombatEffect(ActiveEffects(Combat_EffectTypes,Swordsman_Effects,1,1));
    EXPECT_EQ(75,p.ActualSpeed());
    p.DecrementAllEffects();

    //overweighted
    p.setOverWeighted(true);
    EXPECT_EQ(50,p.ActualSpeed());

    //combos
    p.AddEffect(ActiveEffects(Combat_EffectTypes,AnimalFury_Effects,1,1));

    EXPECT_EQ(62,p.ActualSpeed());

}

//recieve loot drop
TEST(PlayerTest,RecieveLootDrop){
    Player p;
    LootDrop l;

    p.setFreeSlots(40);
    p.setXP(1);
    p.setMoney(0);
    p.setLevelUp(100);
    l.gold=10;
    l.xp=3;

    p.RecieveLootDrop(l);
    EXPECT_EQ(40,p.getFreeSlots());
    EXPECT_EQ(4,p.getXP());
    EXPECT_EQ(10,p.getMoney());

  
    l.armour=new Armor();
    l.armour->setName("testHelm");
    l.armour->setType(Helmet_ArmorType);

    l.weapon=new Weapon();
    l.weapon->setName("testWeapon");
    l.weapon->setType(Sword_WeaponType);
    
    l.potion=new Potion();
    l.potion->setName("testPotion");
    l.potion->setType(Health_PotionType);

    p.RecieveLootDrop(l);
    EXPECT_EQ(37,p.getFreeSlots());
    EXPECT_EQ(7,p.getXP());
    EXPECT_EQ(20,p.getMoney());
    EXPECT_EQ("testWeapon",p.RemoveItemFromInventory(0)->getName());
    EXPECT_EQ("testHelm",p.RemoveItemFromInventory(1)->getName());
    EXPECT_EQ("testPotion",p.RemoveItemFromInventory(2)->getName());

}

//add skill point
TEST(PlayerTest,addSkillPoint){
    //needs mocking
    EXPECT_TRUE(true);
}

//Next Level
TEST(PlayerTest,NextLevel){
    //needs mocking
    EXPECT_TRUE(true);
}

//Move
TEST(PlayerTest,Move){
   
   array<array<RoomPieces_enum, 50>, 50> EmptyMap;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			EmptyMap[i][j] = Empty_RoomPieces;
		}
	}
    for(int i=0; i<10;i++){
        EmptyMap[0][i]=Wall_RoomPieces;
        EmptyMap[9][i]=Wall_RoomPieces;
        EmptyMap[i][0]=Wall_RoomPieces;
        EmptyMap[i][9]=Wall_RoomPieces;        
    }
  
    Player p;
    p.setPosition({1,1});
    EXPECT_EQ(1,p.getPosition()[0]);
    EXPECT_EQ(1,p.getPosition()[1]);

    //check for hitting upper edge
    p.move(EmptyMap,1);
    EXPECT_EQ(1,p.getPosition()[0]);
    EXPECT_EQ(1,p.getPosition()[1]);
    //check for hitting Left edge
    p.move(EmptyMap,0);
    EXPECT_EQ(1,p.getPosition()[0]);
    EXPECT_EQ(1,p.getPosition()[1]);

    //checks for Right movement
    p.move(EmptyMap,2);
    EXPECT_EQ(1,p.getPosition()[0]);
    EXPECT_EQ(2,p.getPosition()[1]);

    //checks for downwards movement
    p.move(EmptyMap,3);
    EXPECT_EQ(2,p.getPosition()[0]);
    EXPECT_EQ(2,p.getPosition()[1]);

    //moving all the way right
    p.move(EmptyMap,2);
    p.move(EmptyMap,2);
    p.move(EmptyMap,2);
    p.move(EmptyMap,2);
    p.move(EmptyMap,2);
    p.move(EmptyMap,2);
    p.move(EmptyMap,2);
    EXPECT_EQ(2,p.getPosition()[0]);
    EXPECT_EQ(8,p.getPosition()[1]);

    //checks right collision
    p.move(EmptyMap,2);
    EXPECT_EQ(2,p.getPosition()[0]);
    EXPECT_EQ(8,p.getPosition()[1]);

    //moving all the way right
    p.move(EmptyMap,3);
    p.move(EmptyMap,3);
    p.move(EmptyMap,3);
    p.move(EmptyMap,3);
    p.move(EmptyMap,3);
    p.move(EmptyMap,3);
    p.move(EmptyMap,3);
    EXPECT_EQ(8,p.getPosition()[0]);
    EXPECT_EQ(8,p.getPosition()[1]);

    //checks for downward collision
    p.move(EmptyMap,3);
    EXPECT_EQ(8,p.getPosition()[0]);
    EXPECT_EQ(8,p.getPosition()[1]);

}

//Navigation
TEST(PlayerTest,Navigation){
    //needs mocking
    EXPECT_FALSE(false);
}

//getAllDamageTypes
TEST(PlayerTest,getAllDamageTypes){
    Player p;
    Weapon *wL = new Weapon();
    Weapon *wR = new Weapon();
    vector<DamageTypes> results;

    //checks if weapons are empty
    p.setDamage(10);
    
    results=p.getAllDamageTypes();
    EXPECT_EQ(3,results.size());
    EXPECT_EQ(10,results[0].getDamage());
    EXPECT_EQ(Normal_DamageType,results[0].getType());
    EXPECT_EQ(0,results[1].getDamage());
    EXPECT_EQ(Normal_DamageType,results[1].getType());
    EXPECT_EQ(0,results[2].getDamage());
    EXPECT_EQ(Normal_DamageType,results[2].getType());
       

   
    
    //checks if weapons are not empty
    wL->addDamageType(DamageTypes(5));
    wR->addDamageType(DamageTypes(6));
    p.setRight(wR);
    p.setLeft(wL);

    results=p.getAllDamageTypes();
    EXPECT_EQ(3,results.size());
    EXPECT_EQ(10,results[0].getDamage());
    EXPECT_EQ(Normal_DamageType,results[0].getType());
    EXPECT_EQ(6,results[1].getDamage());
    EXPECT_EQ(Normal_DamageType,results[1].getType());
    EXPECT_EQ(5,results[2].getDamage());
    EXPECT_EQ(Normal_DamageType,results[2].getType());

    //checks extra weapon effects
    p.setDamage(100);
    wL=new Weapon();
    wR=new Weapon();

    wR->addDamageType(DamageTypes(100));
    wR->addDamageType(DamageTypes(100,100,Blunt_DamageType));
    wR->addDamageType(DamageTypes(100,100,Stabbing_DamageType));

    wL->addDamageType(DamageTypes(100));
    wL->addDamageType(DamageTypes(100,100,Fire_DamageType));
    wL->addDamageType(DamageTypes(100,100,Poison_DamageType));
    
    p.setRight(wR);
    p.setLeft(wL);

    results=p.getAllDamageTypes();
    EXPECT_EQ(7,results.size());
    EXPECT_EQ(100,results[0].getDamage());
    EXPECT_EQ(Normal_DamageType,results[0].getType());
    EXPECT_EQ(100,results[1].getDamage());
    EXPECT_EQ(Normal_DamageType,results[1].getType());
    EXPECT_EQ(100,results[2].getDamage());
    EXPECT_EQ(Stabbing_DamageType,results[2].getType());
    EXPECT_EQ(100,results[3].getDamage());
    EXPECT_EQ(Blunt_DamageType,results[3].getType());
    EXPECT_EQ(100,results[4].getDamage());
    EXPECT_EQ(Normal_DamageType,results[4].getType());
    EXPECT_EQ(100,results[5].getDamage());
    EXPECT_EQ(Fire_DamageType,results[5].getType());
    EXPECT_EQ(100,results[6].getDamage());
    EXPECT_EQ(Poison_DamageType,results[6].getType());
    
    //check for buffs and debuffs

    //Damage Boost x2
    p.AddBuffEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,2,1));
    
    results=p.getAllDamageTypes();
    EXPECT_EQ(7,results.size());
    EXPECT_EQ(200,results[0].getDamage());
    EXPECT_EQ(Normal_DamageType,results[0].getType());
    EXPECT_EQ(200,results[1].getDamage());
    EXPECT_EQ(Normal_DamageType,results[1].getType());
    EXPECT_EQ(200,results[2].getDamage());
    EXPECT_EQ(Stabbing_DamageType,results[2].getType());
    EXPECT_EQ(200,results[3].getDamage());
    EXPECT_EQ(Blunt_DamageType,results[3].getType());
    EXPECT_EQ(200,results[4].getDamage());
    EXPECT_EQ(Normal_DamageType,results[4].getType());
    EXPECT_EQ(200,results[5].getDamage());
    EXPECT_EQ(Fire_DamageType,results[5].getType());
    EXPECT_EQ(200,results[6].getDamage());
    EXPECT_EQ(Poison_DamageType,results[6].getType());
    p.DecrementAllEffects();

    //Bezerk Effect
    p.AddBuffEffect(ActiveEffects(Buff_EffectTypes,Bezerk_Effects,2,1));
    
    results=p.getAllDamageTypes();
    EXPECT_EQ(7,results.size());
    EXPECT_EQ(125,results[0].getDamage());
    EXPECT_EQ(Normal_DamageType,results[0].getType());
    EXPECT_EQ(125,results[1].getDamage());
    EXPECT_EQ(Normal_DamageType,results[1].getType());
    EXPECT_EQ(125,results[2].getDamage());
    EXPECT_EQ(Stabbing_DamageType,results[2].getType());
    EXPECT_EQ(125,results[3].getDamage());
    EXPECT_EQ(Blunt_DamageType,results[3].getType());
    EXPECT_EQ(125,results[4].getDamage());
    EXPECT_EQ(Normal_DamageType,results[4].getType());
    EXPECT_EQ(125,results[5].getDamage());
    EXPECT_EQ(Fire_DamageType,results[5].getType());
    EXPECT_EQ(125,results[6].getDamage());
    EXPECT_EQ(Poison_DamageType,results[6].getType());
    p.DecrementAllEffects();

    //swordsman effect
    p.AddBuffEffect(ActiveEffects(Buff_EffectTypes,Swordsman_Effects,2,1));
    
    results=p.getAllDamageTypes();
    EXPECT_EQ(7,results.size());
    EXPECT_EQ(114,results[0].getDamage());
    EXPECT_EQ(Normal_DamageType,results[0].getType());
    EXPECT_EQ(114,results[1].getDamage());
    EXPECT_EQ(Normal_DamageType,results[1].getType());
    EXPECT_EQ(114,results[2].getDamage());
    EXPECT_EQ(Stabbing_DamageType,results[2].getType());
    EXPECT_EQ(114,results[3].getDamage());
    EXPECT_EQ(Blunt_DamageType,results[3].getType());
    EXPECT_EQ(114,results[4].getDamage());
    EXPECT_EQ(Normal_DamageType,results[4].getType());
    EXPECT_EQ(114,results[5].getDamage());
    EXPECT_EQ(Fire_DamageType,results[5].getType());
    EXPECT_EQ(114,results[6].getDamage());
    EXPECT_EQ(Poison_DamageType,results[6].getType());
    p.DecrementAllEffects();

    //Combo swordsman effect + damage Boost
    p.AddBuffEffect(ActiveEffects(Buff_EffectTypes,Swordsman_Effects,2,1));
    p.AddBuffEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,2,1));
    
    results=p.getAllDamageTypes();
    EXPECT_EQ(7,results.size());
    EXPECT_EQ(229,results[0].getDamage());
    EXPECT_EQ(Normal_DamageType,results[0].getType());
    EXPECT_EQ(229,results[1].getDamage());
    EXPECT_EQ(Normal_DamageType,results[1].getType());
    EXPECT_EQ(229,results[2].getDamage());
    EXPECT_EQ(Stabbing_DamageType,results[2].getType());
    EXPECT_EQ(229,results[3].getDamage());
    EXPECT_EQ(Blunt_DamageType,results[3].getType());
    EXPECT_EQ(229,results[4].getDamage());
    EXPECT_EQ(Normal_DamageType,results[4].getType());
    EXPECT_EQ(229,results[5].getDamage());
    EXPECT_EQ(Fire_DamageType,results[5].getType());
    EXPECT_EQ(229,results[6].getDamage());
    EXPECT_EQ(Poison_DamageType,results[6].getType());
    p.DecrementAllEffects();    
}

//getAllResistance
TEST(PlayerTest,getAllResistanceTypes){
    Player p;
    Weapon *wL=new Weapon();
    Weapon *wR=new Weapon();
    Armor *head=new Armor();
    head->setType(Helmet_ArmorType);
    Armor *chest=new Armor();
    chest->setType(Chest_ArmorType);
    Armor *gloves=new Armor();
    gloves->setType(Gloves_ArmorType);
    Armor *pants=new Armor();
    pants->setType(Pants_ArmorType);
    Armor *boots=new Armor();
    boots->setType(Boots_ArmorType);

    vector<ActiveEffects> results;
    p.setDefense(80);

    //default
    results=p.getAllResistanceTypes();

    //5 NULL for armor, 2 NULL for weapon, 1 NormalResistance for playerResistance, 1 Normal resistance for Defense stat
    EXPECT_EQ(8,results.size());
    //resistance is empty
    //Defense stat
    EXPECT_EQ(NormalResistance_Effects,results[0].getEffect());
    EXPECT_EQ(80,results[0].getModifier());
    //Right Weapon
    EXPECT_EQ(NormalResistance_Effects,results[1].getEffect());
    EXPECT_EQ(0,results[1].getResistance());    
    //Left Weapon
    EXPECT_EQ(NormalResistance_Effects,results[2].getEffect());
    EXPECT_EQ(0,results[2].getResistance());        
    //Head
    EXPECT_EQ(NormalResistance_Effects,results[3].getEffect());
    EXPECT_EQ(0,results[3].getResistance());
    //Torso
    EXPECT_EQ(NormalResistance_Effects,results[4].getEffect());
    EXPECT_EQ(0,results[4].getResistance());
    //Feet
    EXPECT_EQ(NormalResistance_Effects,results[5].getEffect());
    EXPECT_EQ(0,results[5].getResistance());
    //Legs
    EXPECT_EQ(NormalResistance_Effects,results[6].getEffect());
    EXPECT_EQ(0,results[6].getResistance());
    //Hands
    EXPECT_EQ(NormalResistance_Effects,results[7].getEffect());
    EXPECT_EQ(0,results[7].getResistance());


    //adds player resistance effects
    p.AddEffect(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,80,15));

    results=p.getAllResistanceTypes();

    EXPECT_EQ(9,results.size());
    //resistance 
    EXPECT_EQ(PoisonResistance_Effects,results[0].getEffect());
    EXPECT_EQ(80,results[0].getModifier());
    //Defense stat
    EXPECT_EQ(NormalResistance_Effects,results[1].getEffect());
    EXPECT_EQ(80,results[1].getModifier());
    //Right Weapon
    EXPECT_EQ(NormalResistance_Effects,results[2].getEffect());
    EXPECT_EQ(0,results[2].getResistance());    
    //Left Weapon
    EXPECT_EQ(NormalResistance_Effects,results[3].getEffect());
    EXPECT_EQ(0,results[3].getResistance());        
    //Head
    EXPECT_EQ(NormalResistance_Effects,results[4].getEffect());
    EXPECT_EQ(0,results[4].getResistance());
    //Torso
    EXPECT_EQ(NormalResistance_Effects,results[5].getEffect());
    EXPECT_EQ(0,results[5].getResistance());
    //Feet
    EXPECT_EQ(NormalResistance_Effects,results[6].getEffect());
    EXPECT_EQ(0,results[6].getResistance());
    //Legs
    EXPECT_EQ(NormalResistance_Effects,results[7].getEffect());
    EXPECT_EQ(0,results[7].getResistance());
    //Hands
    EXPECT_EQ(NormalResistance_Effects,results[8].getEffect());
    EXPECT_EQ(0,results[8].getResistance());

    //Test with all the resistance effects

    //adding resistance to weapons
    wL->setDefense(80);
    wR->setDefense(80);

    //adding resistances to armor
    head->addResistanceType(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,80,1));
    chest->addResistanceType(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,80,1));
    gloves->addResistanceType(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,80,1));
    pants->addResistanceType(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,80,1));
    boots->addResistanceType(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,80,1));

    p.setLeft(wL);
    p.setRight(wR);
    p.setHead(head);
    p.setTorso(chest);
    p.setHands(gloves);
    p.setLegs(pants);
    p.setFeet(boots);

    results=p.getAllResistanceTypes();

    EXPECT_EQ(14,results.size());
    //Player Resistance
    EXPECT_EQ(80,results[0].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[0].getEffect());
    //Defense Stat
    EXPECT_EQ(80,results[1].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[1].getEffect());
    //Right Weapon
    EXPECT_EQ(80,results[2].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[2].getEffect());
    //Left Weapon
    EXPECT_EQ(80,results[3].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[3].getEffect());
    //Head
    EXPECT_EQ(0,results[5].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[5].getEffect());
    EXPECT_EQ(80,results[4].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[4].getEffect());
    //Torso
    EXPECT_EQ(0,results[7].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[7].getEffect());
    EXPECT_EQ(80,results[6].getResistance());
    EXPECT_EQ(BluntResistance_Effects,results[6].getEffect());
    //Feet
    EXPECT_EQ(0,results[9].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[9].getEffect());
    EXPECT_EQ(80,results[8].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[8].getEffect());
    //Legs
    EXPECT_EQ(0,results[11].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[11].getEffect());
    EXPECT_EQ(80,results[10].getResistance());
    EXPECT_EQ(StabbingResistance_Effects,results[10].getEffect());
    //Hands
    EXPECT_EQ(0,results[12].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[12].getEffect());
    EXPECT_EQ(80,results[13].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[13].getEffect());
    
    //testing modifiers

    //Defensive stance
    p.AddEffect(ActiveEffects(Combat_EffectTypes,DefensiveStance_Effects,1,1));

    results=p.getAllResistanceTypes();

    EXPECT_EQ(14,results.size());
    //Player Resistance
    EXPECT_EQ(100,results[0].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[0].getEffect());
    //Defense Stat
    EXPECT_EQ(100,results[1].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[1].getEffect());
    //Right Weapon
    EXPECT_EQ(100,results[2].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[2].getEffect());
    //Left Weapon
    EXPECT_EQ(100,results[3].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[3].getEffect());
    //Head
    EXPECT_EQ(0,results[5].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[5].getEffect());
    EXPECT_EQ(100,results[4].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[4].getEffect());
    //Torso
    EXPECT_EQ(0,results[7].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[7].getEffect());
    EXPECT_EQ(100,results[6].getResistance());
    EXPECT_EQ(BluntResistance_Effects,results[6].getEffect());
    //Feet
    EXPECT_EQ(0,results[9].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[9].getEffect());
    EXPECT_EQ(100,results[8].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[8].getEffect());
    //Legs
    EXPECT_EQ(0,results[11].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[11].getEffect());
    EXPECT_EQ(100,results[10].getResistance());
    EXPECT_EQ(StabbingResistance_Effects,results[10].getEffect());
    //Hands
    EXPECT_EQ(0,results[12].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[12].getEffect());
    EXPECT_EQ(100,results[13].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[13].getEffect());
    p.DecrementAllEffects();

    //Animal Fury stance
    p.AddEffect(ActiveEffects(Combat_EffectTypes,AnimalFury_Effects,1,1));

    results=p.getAllResistanceTypes();

    EXPECT_EQ(14,results.size());
    //Player Resistance
    EXPECT_EQ(60,results[0].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[0].getEffect());
    //Defense Stat
    EXPECT_EQ(60,results[1].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[1].getEffect());
    //Right Weapon
    EXPECT_EQ(60,results[2].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[2].getEffect());
    //Left Weapon
    EXPECT_EQ(60,results[3].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[3].getEffect());
    //Head
    EXPECT_EQ(0,results[5].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[5].getEffect());
    EXPECT_EQ(60,results[4].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[4].getEffect());
    //Torso
    EXPECT_EQ(0,results[7].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[7].getEffect());
    EXPECT_EQ(60,results[6].getResistance());
    EXPECT_EQ(BluntResistance_Effects,results[6].getEffect());
    //Feet
    EXPECT_EQ(0,results[9].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[9].getEffect());
    EXPECT_EQ(60,results[8].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[8].getEffect());
    //Legs
    EXPECT_EQ(0,results[11].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[11].getEffect());
    EXPECT_EQ(60,results[10].getResistance());
    EXPECT_EQ(StabbingResistance_Effects,results[10].getEffect());
    //Hands
    EXPECT_EQ(0,results[12].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[12].getEffect());
    EXPECT_EQ(60,results[13].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[13].getEffect());
    p.DecrementAllEffects();
    
    //Bezerk
    p.AddEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,1));

    results=p.getAllResistanceTypes();

    EXPECT_EQ(14,results.size());
    //Player Resistance
    EXPECT_EQ(60,results[0].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[0].getEffect());
    //Defense Stat
    EXPECT_EQ(60,results[1].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[1].getEffect());
    //Right Weapon
    EXPECT_EQ(60,results[2].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[2].getEffect());
    //Left Weapon
    EXPECT_EQ(60,results[3].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[3].getEffect());
    //Head
    EXPECT_EQ(0,results[5].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[5].getEffect());
    EXPECT_EQ(60,results[4].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[4].getEffect());
    //Torso
    EXPECT_EQ(0,results[7].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[7].getEffect());
    EXPECT_EQ(60,results[6].getResistance());
    EXPECT_EQ(BluntResistance_Effects,results[6].getEffect());
    //Feet
    EXPECT_EQ(0,results[9].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[9].getEffect());
    EXPECT_EQ(60,results[8].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[8].getEffect());
    //Legs
    EXPECT_EQ(0,results[11].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[11].getEffect());
    EXPECT_EQ(60,results[10].getResistance());
    EXPECT_EQ(StabbingResistance_Effects,results[10].getEffect());
    //Hands
    EXPECT_EQ(0,results[12].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[12].getEffect());
    EXPECT_EQ(60,results[13].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[13].getEffect());
    p.DecrementAllEffects();
    
    //swordsman stance
    p.AddEffect(ActiveEffects(Combat_EffectTypes,Swordsman_Effects,1,1));

    results=p.getAllResistanceTypes();

    EXPECT_EQ(14,results.size());
    //Player Resistance
    EXPECT_EQ(92,results[0].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[0].getEffect());
    //Defense Stat
    EXPECT_EQ(92,results[1].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[1].getEffect());
    //Right Weapon
    EXPECT_EQ(92,results[2].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[2].getEffect());
    //Left Weapon
    EXPECT_EQ(92,results[3].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[3].getEffect());
    //Head
    EXPECT_EQ(0,results[5].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[5].getEffect());
    EXPECT_EQ(92,results[4].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[4].getEffect());
    //Torso
    EXPECT_EQ(0,results[7].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[7].getEffect());
    EXPECT_EQ(92,results[6].getResistance());
    EXPECT_EQ(BluntResistance_Effects,results[6].getEffect());
    //Feet
    EXPECT_EQ(0,results[9].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[9].getEffect());
    EXPECT_EQ(92,results[8].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[8].getEffect());
    //Legs
    EXPECT_EQ(0,results[11].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[11].getEffect());
    EXPECT_EQ(92,results[10].getResistance());
    EXPECT_EQ(StabbingResistance_Effects,results[10].getEffect());
    //Hands
    EXPECT_EQ(0,results[12].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[12].getEffect());
    EXPECT_EQ(92,results[13].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[13].getEffect());
    p.DecrementAllEffects();
    
    //Mixed Animal Fury and DefensiveStance
    p.AddEffect(ActiveEffects(Combat_EffectTypes,AnimalFury_Effects,1,1));
    p.AddEffect(ActiveEffects(Combat_EffectTypes,DefensiveStance_Effects,1,1));
    results=p.getAllResistanceTypes();

    EXPECT_EQ(14,results.size());
    //Player Resistance
    EXPECT_EQ(75,results[0].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[0].getEffect());
    //Defense Stat
    EXPECT_EQ(75,results[1].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[1].getEffect());
    //Right Weapon
    EXPECT_EQ(75,results[2].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[2].getEffect());
    //Left Weapon
    EXPECT_EQ(75,results[3].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[3].getEffect());
    //Head
    EXPECT_EQ(0,results[5].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[5].getEffect());
    EXPECT_EQ(75,results[4].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[4].getEffect());
    //Torso
    EXPECT_EQ(0,results[7].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[7].getEffect());
    EXPECT_EQ(75,results[6].getResistance());
    EXPECT_EQ(BluntResistance_Effects,results[6].getEffect());
    //Feet
    EXPECT_EQ(0,results[9].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[9].getEffect());
    EXPECT_EQ(75,results[8].getResistance());
    EXPECT_EQ(FireResistance_Effects,results[8].getEffect());
    //Legs
    EXPECT_EQ(0,results[11].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[11].getEffect());
    EXPECT_EQ(75,results[10].getResistance());
    EXPECT_EQ(StabbingResistance_Effects,results[10].getEffect());
    //Hands
    EXPECT_EQ(0,results[12].getResistance());
    EXPECT_EQ(NormalResistance_Effects,results[12].getEffect());
    EXPECT_EQ(75,results[13].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,results[13].getEffect());
    p.DecrementAllEffects();
    

    //adding more resistance types
    p.AddEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,15,15));
    //p.AddEffect(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,15,15));
    p.AddEffect(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,15,15));
    
    results=p.getAllResistanceTypes();

     EXPECT_EQ(16,results.size());
    // //Player Resistance
    // EXPECT_EQ(75,results[0].getResistance());
    // EXPECT_EQ(PoisonResistance_Effects,results[0].getEffect());
    // //Defense Stat
    // EXPECT_EQ(75,results[1].getResistance());
    // EXPECT_EQ(NormalResistance_Effects,results[1].getEffect());
    // //Right Weapon
    // EXPECT_EQ(75,results[2].getResistance());
    // EXPECT_EQ(NormalResistance_Effects,results[2].getEffect());
    // //Left Weapon
    // EXPECT_EQ(75,results[3].getResistance());
    // EXPECT_EQ(NormalResistance_Effects,results[3].getEffect());
    // //Head
    // EXPECT_EQ(0,results[5].getResistance());
    // EXPECT_EQ(NormalResistance_Effects,results[5].getEffect());
    // EXPECT_EQ(75,results[4].getResistance());
    // EXPECT_EQ(FireResistance_Effects,results[4].getEffect());
    // //Torso
    // EXPECT_EQ(0,results[7].getResistance());
    // EXPECT_EQ(NormalResistance_Effects,results[7].getEffect());
    // EXPECT_EQ(75,results[6].getResistance());
    // EXPECT_EQ(BluntResistance_Effects,results[6].getEffect());
    // //Feet
    // EXPECT_EQ(0,results[9].getResistance());
    // EXPECT_EQ(NormalResistance_Effects,results[9].getEffect());
    // EXPECT_EQ(75,results[8].getResistance());
    // EXPECT_EQ(FireResistance_Effects,results[8].getEffect());
    // //Legs
    // EXPECT_EQ(0,results[11].getResistance());
    // EXPECT_EQ(NormalResistance_Effects,results[11].getEffect());
    // EXPECT_EQ(75,results[10].getResistance());
    // EXPECT_EQ(StabbingResistance_Effects,results[10].getEffect());
    // //Hands
    // EXPECT_EQ(0,results[12].getResistance());
    // EXPECT_EQ(NormalResistance_Effects,results[12].getEffect());
    // EXPECT_EQ(75,results[13].getResistance());
    // EXPECT_EQ(PoisonResistance_Effects,results[13].getEffect());
    p.DecrementAllEffects();
    

}

//TakeDamage
TEST(PlayerTest,TakeDamage){
    Player p;
    p.setMaxHealth(400);
    p.setHealth(400);
    p.setDefense(0);

    vector<DamageTypes> damage;
    //sets default health
    EXPECT_EQ(400,p.getHealth());

    //adds 1 damage
    damage.push_back(DamageTypes(15,100,Normal_DamageType));

    EXPECT_EQ(15,p.TakeDamage(damage));
    EXPECT_EQ(385,p.getHealth());

    //checks if defense is 1 and damage is 1
    damage.clear();
    damage.push_back(DamageTypes(1));
    p.setDefense(1);
    EXPECT_EQ(1,p.TakeDamage(damage));
    EXPECT_EQ(384,p.getHealth());

    //tests multiple damages
    damage.clear();
    damage.push_back(DamageTypes(100));
    damage.push_back(DamageTypes(100));
    p.setHealth(400);
    p.setDefense(20);
    EXPECT_EQ(160,p.TakeDamage(damage));
    EXPECT_EQ(240,p.getHealth());

    //adds a resistance type
    p.AddEffect(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,10,5));
    p.setHealth(400);

    EXPECT_EQ(144,p.TakeDamage(damage));
    EXPECT_EQ(256,p.getHealth());

    //adds a non "Normal" Damage type
    p.setHealth(400);

    damage.push_back(DamageTypes(20,100,Fire_DamageType));
    EXPECT_EQ(164,p.TakeDamage(damage));
    EXPECT_EQ(236,p.getHealth());
  
    //adds resistance to fire Damage
    EXPECT_TRUE(p.AddEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,50,1)));
    EXPECT_TRUE(p.AddEffect(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,50,1)));
    
    p.setHealth(400);

    EXPECT_EQ(154,p.TakeDamage(damage));
    // EXPECT_EQ(246,p.getHealth());

    //could add tons of more test. add them as needed

}   

//GiveMoney
TEST(PlayerTest,GiveMoney){
    Player p;

    //should give 0 since player has no money
    EXPECT_EQ(0,p.getMoney());
    EXPECT_EQ(0,p.GiveMoney(100));

    //sets players money to 1000
    p.setMoney(1000);
    EXPECT_EQ(1000,p.getMoney());

    //checks if give money actually returns the correct value and changes the money
    EXPECT_EQ(100,p.GiveMoney(100));
    EXPECT_EQ(900,p.getMoney());

    //amount is negtive so it should return 0 and not change the internal amount
    EXPECT_EQ(0,p.GiveMoney(-19));
    EXPECT_EQ(900,p.getMoney());
}

//test the recieve money function
TEST(PlayerTest,RecieveMoney){
    Player p;

    //checks that initial money is 0
    EXPECT_EQ(0,p.getMoney());

    //checks if recieve money succeeds
    EXPECT_TRUE(p.RecieveMoney(100));
    EXPECT_EQ(100,p.getMoney());

    //recieve money should fail since it is a negative amount
    EXPECT_FALSE(p.RecieveMoney(-10));
}

TEST(SideFunctionTest,ReduceDamage){
    vector<ActiveEffects> resistances;
    resistances.push_back(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,1));
    resistances.push_back(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,1));
    resistances.push_back(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,1));
    resistances.push_back(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,1));
    resistances.push_back(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,1));
    resistances.push_back(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,1));
    resistances.push_back(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,1));
    resistances.push_back(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,0,1));

    EXPECT_EQ(15,ReduceDamage(15,Normal_DamageType,resistances));

}
