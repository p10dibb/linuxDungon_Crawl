#include "Enemy.h"
#include <gtest/gtest.h>


//Tests Constructor
TEST(EnemyTest,Constructor){
    Enemy z;

    EXPECT_EQ(No_Direction,z.getDirection());
    EXPECT_EQ(0,z.getMoveAmt());
    EXPECT_EQ(NULL_WeaponType,z.getWeapon()->getType());
}

//tests set Weapon
TEST(EnemySetterTest,Weapon){
    Weapon *w=new Weapon();
    Enemy z;
    w->setType(Axe_WeaponType);
    z.setWeapon(w);

    EXPECT_EQ(Axe_WeaponType,z.getWeapon()->getType());
}

//Test getAllDamageTypes
TEST(EnemyTest,getAllDamageTypes){
    Enemy z;
    Weapon *w=new Weapon();
    vector<DamageTypes> ret;

    //setting damage types for weapon
    map<DamageTypes_enum,DamageTypes> d;
    d[Normal_DamageType]=DamageTypes(10);
    d[Fire_DamageType]=DamageTypes(5,50,Fire_DamageType,true,1,1);
    w->setType(Axe_WeaponType);
    w->setDamageTypes_Weapon(d);

    //setting Enemy items
    z.setDamage(5);
    z.setWeapon(w);

    //should be Null,Normal,Fire,Normal
    ret=z.getAllDamageTypes();
    EXPECT_EQ(3,ret.size());
    EXPECT_EQ(Normal_DamageType,ret[0].getType());
    EXPECT_EQ(10,ret[0].getDamage());
    EXPECT_EQ(Fire_DamageType,ret[1].getType());
    EXPECT_EQ(5,ret[1].getDamage());
    EXPECT_EQ(Normal_DamageType,ret[2].getType());
    EXPECT_EQ(5,ret[2].getDamage());

    //Adding a damage Boost to Enemy
    z.AddBuffEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,3,5));

    //should be Normal,Fire,Normal with tripple damage
    ret=z.getAllDamageTypes();
    EXPECT_EQ(3,ret.size());
    EXPECT_EQ(Normal_DamageType,ret[0].getType());
    EXPECT_EQ(30,ret[0].getDamage());
    EXPECT_EQ(Fire_DamageType,ret[1].getType());
    EXPECT_EQ(15,ret[1].getDamage());
    EXPECT_EQ(Normal_DamageType,ret[2].getType());
    EXPECT_EQ(15,ret[2].getDamage());


}

//Tests getAllResistanceTypes  
TEST(EnemyTest,GetAllResistance){
    Enemy z;
    Weapon *w=new Weapon();
    vector<ActiveEffects> r;
    z.setDefense(6);
    w->setDefense(5);
    z.setWeapon(w);


    //no arrmour added ,no resistance effects added
    r=z.getAllResistanceTypes();
    EXPECT_EQ(7,r.size());
    EXPECT_EQ(NormalResistance_Effects,r[0].getEffect());
    EXPECT_EQ(6,r[0].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[1].getEffect());
    EXPECT_EQ(5,r[1].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[2].getEffect());
    EXPECT_EQ(0,r[2].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[3].getEffect());
    EXPECT_EQ(0,r[3].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[4].getEffect());
    EXPECT_EQ(0,r[4].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[5].getEffect());
    EXPECT_EQ(0,r[5].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[6].getEffect());
    EXPECT_EQ(0,r[6].getResistance());

    //adding armour
    Armor * head= new Armor(0,1,Helmet_ArmorType,Light_ArmorClass);
    Armor * chest= new Armor(0,1,Chest_ArmorType,Light_ArmorClass);;
    Armor * gloves= new Armor(0,1,Gloves_ArmorType,Light_ArmorClass);;
    Armor * pants= new Armor(0,1,Pants_ArmorType,Light_ArmorClass);;
    Armor * boots= new Armor(0,1,Boots_ArmorType,Light_ArmorClass);;

    head->addResistanceType(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,5,5));
    head->addResistanceType(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,7,3));

    chest->addResistanceType(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,70,9));

    gloves->addResistanceType(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,25,10));
    gloves->addResistanceType(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,15,9));

    pants->addResistanceType(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,32,5));

    boots->addResistanceType(ActiveEffects(Resistance_EffectTypes, BluntResistance_Effects,13,4));

    z.setHead(head);
    z.setTorso(chest);
    z.setHands(gloves);
    z.setLegs(pants);
    z.setFeet(boots);

    //testing with armor
    r=z.getAllResistanceTypes();
    EXPECT_EQ(10,r.size());
    EXPECT_EQ(NormalResistance_Effects,r[0].getEffect());
    EXPECT_EQ(6,r[0].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[1].getEffect());
    EXPECT_EQ(5,r[1].getResistance());
    EXPECT_EQ(FireResistance_Effects,r[2].getEffect());
    EXPECT_EQ(5,r[2].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[3].getEffect());
    EXPECT_EQ(7,r[3].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[4].getEffect());
    EXPECT_EQ(70,r[4].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[5].getEffect());
    EXPECT_EQ(25,r[5].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,r[6].getEffect());
    EXPECT_EQ(15,r[6].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[7].getEffect());
    EXPECT_EQ(32,r[7].getResistance());
    EXPECT_EQ(BluntResistance_Effects,r[8].getEffect());
    EXPECT_EQ(13,r[8].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[9].getEffect());
    EXPECT_EQ(0,r[9].getResistance());

    //with defense boost
    z.AddBuffEffect(ActiveEffects(Buff_EffectTypes,DefenseBoost_Effects,2,6));
    r=z.getAllResistanceTypes();
    EXPECT_EQ(10,r.size());
    EXPECT_EQ(NormalResistance_Effects,r[0].getEffect());
    EXPECT_EQ(12,r[0].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[1].getEffect());
    EXPECT_EQ(10,r[1].getResistance());
    EXPECT_EQ(FireResistance_Effects,r[2].getEffect());
    EXPECT_EQ(10,r[2].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[3].getEffect());
    EXPECT_EQ(14,r[3].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[4].getEffect());
    EXPECT_EQ(100,r[4].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[5].getEffect());
    EXPECT_EQ(50,r[5].getResistance());
    EXPECT_EQ(PoisonResistance_Effects,r[6].getEffect());
    EXPECT_EQ(30,r[6].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[7].getEffect());
    EXPECT_EQ(64,r[7].getResistance());
    EXPECT_EQ(BluntResistance_Effects,r[8].getEffect());
    EXPECT_EQ(26,r[8].getResistance());
    EXPECT_EQ(NormalResistance_Effects,r[9].getEffect());
    EXPECT_EQ(0,r[9].getResistance());
}

//Tests TakeDamage  !!needs to more thoroughly test!!
TEST(EnemyTest,TakeDamage){
    Enemy z;
    z.setMaxHealth(200);
    z.setHealth(200);

    vector<DamageTypes> d;

    d.push_back(DamageTypes(100));

    //takes damage no defense
    EXPECT_EQ(100,z.TakeDamage(d));
    EXPECT_EQ(100,z.getHealth());


    //takes damage with stats at 10, no resistance effects,armor, or weapon;
    z.setDefense(10);
    z.setHealth(200);

    EXPECT_EQ(90,z.TakeDamage(d));
    EXPECT_EQ(110,z.getHealth());


    //checking with weapon defense
    z.getWeapon()->setDefense(10);
    z.setHealth(200);

    EXPECT_EQ(81,z.TakeDamage(d));
    EXPECT_EQ(119,z.getHealth());

    //adding resistance effects
    z.AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,10,3));
    z.setHealth(200);
    EXPECT_EQ(72,z.TakeDamage(d));

    //adding Armor
    z.getHead()->addResistanceType(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,5,2));
    z.getTorso()->addResistanceType(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,5,2));
    z.getHands()->addResistanceType(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,5,2));
    z.getLegs()->addResistanceType(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,5,2));
    z.getFeet()->addResistanceType(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,5,2));
    z.setHealth(200);
    EXPECT_EQ(54,z.TakeDamage(d));
    EXPECT_EQ(146,z.getHealth());

    //adding Burning damage type
    d.push_back(DamageTypes(20,100,Fire_DamageType));
    z.setHealth(200);

    EXPECT_EQ(74,z.TakeDamage(d));
    EXPECT_EQ(126,z.getHealth());

    //adding Fire resistance

    z.getTorso()->addResistanceType(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,10,4));
    z.AddEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,10,4));
    z.AddEffect(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,3,3));
    z.setHealth(200);

    EXPECT_EQ(70,z.TakeDamage(d));
    EXPECT_EQ(130,z.getHealth());

}


//Test Actual Speed 
TEST(EnemyTest,ActualSpeed){
    Enemy z;

    //weight =10
    z.getHead()->setWeight(2);
    z.getTorso()->setWeight(2);
    z.getHands()->setWeight(2);
    z.getLegs()->setWeight(2);
    z.getFeet()->setWeight(2);

    z.getWeapon()->setSpeed(20);
    z.setSpeed(25);
    z.setStrength(4);


    EXPECT_EQ(40,z.ActualSpeed());

    //adds a slowed effect
    z.AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,Slowed_Effects,1,1));
    EXPECT_EQ(30,z.ActualSpeed());
    z.DecrementAllDeBuffEffects();

    EXPECT_EQ(40,z.ActualSpeed());
    z.AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,Dazed_Effects,1,1));
    EXPECT_EQ(30,z.ActualSpeed());

    //boths
    z.AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,Slowed_Effects,1,1));
    EXPECT_EQ(22,z.ActualSpeed());

}

//Test move  !!needs to test more!! how though since based on rng;
TEST(EnemyTest,Move){
    Enemy z;
    array<array<RoomPieces_enum, 50>, 50> BaseMap;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			BaseMap[i][j] = Empty_RoomPieces;
		}
	}
    z.move(BaseMap);
    EXPECT_TRUE(true);
}

