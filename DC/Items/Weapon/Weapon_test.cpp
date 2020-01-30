#include <gtest/gtest.h>
#include "Weapon.h"

//Tests the default constructor
TEST(WeaponTest,Constructor){
    Weapon w;

    //checks default constructor
    EXPECT_EQ(NULL_WeaponType,w.getType());
    EXPECT_EQ(1,w.getDamageTypes_Weapon().size());
    EXPECT_EQ(0,w.getDefense().getResistance());
    EXPECT_EQ(NormalResistance_Effects,w.getDefense().getEffect());
    EXPECT_FALSE(w.getTwoHanded());
    EXPECT_EQ(1,w.getSpeed());
    EXPECT_EQ(1,w.getLevel());
    EXPECT_EQ(1,w.getRange());
    EXPECT_EQ(0,w.getWeaponRank());

    //checks other constructor
    map<DamageTypes_enum,DamageTypes> t;
    t[Normal_DamageType]=DamageTypes(10,100,Normal_DamageType,false);
    w=Weapon(11,false,6,15,9,Axe_WeaponType,t);

    EXPECT_EQ(Axe_WeaponType,w.getType());
    EXPECT_EQ(1,w.getDamageTypes_Weapon().size());
    EXPECT_EQ(11,w.getDefense().getResistance());
    EXPECT_EQ(NormalResistance_Effects,w.getDefense().getEffect());
    EXPECT_FALSE(w.getTwoHanded());
    EXPECT_EQ(6,w.getSpeed());
    EXPECT_EQ(15,w.getLevel());
    EXPECT_EQ(9,w.getRange());
    EXPECT_EQ(60,w.getWeaponRank());
}

//Tests the DefenseSetter
TEST(WeaponSetterTest,Defense){
    Weapon w;
    
    //should succeed
    w.setDefense(25);
    EXPECT_EQ(25,w.getDefense().getResistance());
    EXPECT_EQ(NormalResistance_Effects,w.getDefense().getEffect());

    //should set to 0
    w.setDefense(-1);
    EXPECT_EQ(0,w.getDefense().getResistance());
    EXPECT_EQ(NormalResistance_Effects,w.getDefense().getEffect());

    //should set to 100
    w.setDefense(110);
    EXPECT_EQ(100,w.getDefense().getResistance());
    EXPECT_EQ(NormalResistance_Effects,w.getDefense().getEffect());
}

//Tests the TwoHandedSetter
TEST(WeaponSetterTest,TwoHanded){
    Weapon w;
    EXPECT_FALSE(w.getTwoHanded());
    w.setTwoHanded(true);
    EXPECT_TRUE(w.getTwoHanded());
    w.setTwoHanded(false);
    EXPECT_FALSE(w.getTwoHanded());    
}

//Tests the Speed setter
TEST(WeaponSetterTest,Speed){
    Weapon w;
    //CHECKS default
    EXPECT_EQ(1,w.getSpeed());

    //should succeed
    w.setSpeed(15);
    EXPECT_EQ(15,w.getSpeed());

    //should equal 1
    w.setSpeed(0);
    EXPECT_EQ(1,w.getSpeed());
    
}

//Tests the Level setter
TEST(WeaponSetterTest,Level){
    Weapon w;
    
    //checks default val
    EXPECT_EQ(1,w.getLevel());

    //checks for arbitrary success val
    w.setLevel(15);
    EXPECT_EQ(15,w.getLevel());

    //checks min value
    w.setLevel(0);
    EXPECT_EQ(1,w.getLevel());
}

//Tests the Range setter
TEST(WeaponSetterTest,Range){
    Weapon w;
    //checks default
    EXPECT_EQ(1,w.getRange());

    //should equal 6 arbitrary value
    w.setRange(6);
    EXPECT_EQ(6,w.getRange());
    //checks min should be set to 1
    w.setRange(-1);
    EXPECT_EQ(1,w.getRange());
}

//checks the rarity setter
TEST(WeaponSetterTest,Rarity){
    Weapon w;

    w.setRarity(Rare_ItemRarity);
    EXPECT_EQ(Rare_ItemRarity,w.getRarity());
}

//checks type setter
TEST(WeaponSetterTest, Type){
    Weapon w;

    w.setType(Axe_WeaponType);
    EXPECT_EQ(Axe_WeaponType,w.getType());
}

//checks DamageTypes setter
TEST(WeaponSetterTest,DamageTypes_Weapon){
    Weapon w;
    map<DamageTypes_enum,DamageTypes> d;
    d[Normal_DamageType]=DamageTypes(10);
    d[Fire_DamageType]=DamageTypes(6,50,Fire_DamageType);

    w.setDamageTypes_Weapon(d);

    EXPECT_EQ(2,w.getDamageTypes_Weapon().size());
}

//checks add Damage Type
TEST(WeaponTest,AddDamageType){
    Weapon w;

    //add normal damage of 10
    w.addDamageType(DamageTypes(10));
    EXPECT_EQ(1,w.getDamageTypes_Weapon().size());
    EXPECT_EQ(100,w.getDamageTypes_Weapon_Map()[Normal_DamageType].getProbability());
    EXPECT_EQ(10,w.getDamageTypes_Weapon_Map()[Normal_DamageType].getDamage());
    EXPECT_EQ(10,w.getWeaponRank());

    //checks adding a new effect
    //add fire damage of 6 probability 50
    w.addDamageType(DamageTypes(6,50,Fire_DamageType));
    EXPECT_EQ(2,w.getDamageTypes_Weapon().size());
    EXPECT_EQ(50,w.getDamageTypes_Weapon_Map()[Fire_DamageType].getProbability());
    EXPECT_EQ(6,w.getDamageTypes_Weapon_Map()[Fire_DamageType].getDamage());
    EXPECT_EQ(13,w.getWeaponRank());

    //checks increasing the damagemwith same probability
    //add normal damage of 10
    w.addDamageType(DamageTypes(10));
    EXPECT_EQ(2,w.getDamageTypes_Weapon().size());
    EXPECT_EQ(100,w.getDamageTypes_Weapon_Map()[Normal_DamageType].getProbability());
    EXPECT_EQ(20,w.getDamageTypes_Weapon_Map()[Normal_DamageType].getDamage());
    EXPECT_EQ(23,w.getWeaponRank());

    //checks  increase damage and different p
    //add fire damage of 10 probability 30
    w.addDamageType(DamageTypes(10,30,Fire_DamageType));
    EXPECT_EQ(2,w.getDamageTypes_Weapon().size());
    EXPECT_EQ(40,w.getDamageTypes_Weapon_Map()[Fire_DamageType].getProbability());
    EXPECT_EQ(16,w.getDamageTypes_Weapon_Map()[Fire_DamageType].getDamage());
    EXPECT_EQ(26,w.getWeaponRank());
    

}

