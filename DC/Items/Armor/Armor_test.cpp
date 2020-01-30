#include "Armor.h"
#include <gtest/gtest.h>


//Tests the Constructor
TEST(ArmorTest,Constructor){
    Armor a;
    //Checks Default constructor
    EXPECT_EQ(1,a.getLevel());
    EXPECT_EQ(NULL_ArmorType,a.getType());
    EXPECT_EQ(NULL_ArmorClass,a.getClass());
    EXPECT_EQ(1,a.getResistanceTypes().size());
    EXPECT_EQ(0,a.getTotalResistance());

    //Checks constructor with input
    a=Armor(10,5,Chest_ArmorType,Light_ArmorClass);
    EXPECT_EQ(5,a.getLevel());
    EXPECT_EQ(Chest_ArmorType,a.getType());
    EXPECT_EQ(Light_ArmorClass,a.getClass());
    EXPECT_EQ(1,a.getResistanceTypes().size());
    EXPECT_EQ(10,a.getTotalResistance());
}

//tests setter for level
TEST(ArmorSetterTest,Level){
    Armor a;
    //checks default
    EXPECT_EQ(1,a.getLevel());

    //Should succeed
    a.setLevel(15);
    EXPECT_EQ(15,a.getLevel());


    //Should set level to 1
    a.setLevel(-14);
    EXPECT_EQ(1,a.getLevel());
}

//tests for Resistance
TEST(ArmorSetterTest,ResistanceTypes){
    Armor a;
    map<Effects_enum,ActiveEffects> t;

    t[FireResistance_Effects]=ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,1,1);
    t[PoisonResistance_Effects]=ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,1,1);
    a.setResistanceTypes(t);

    EXPECT_EQ(2,a.getResistanceTypes().size());
 
}

TEST(ArmorTest,TotalResistance){
    Armor a;
    map<Effects_enum,ActiveEffects> d;
    EXPECT_EQ(0,a.getTotalResistance());

    d[NormalResistance_Effects]=(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,15,10));
    d[FireResistance_Effects]=(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,10,10));
    d[Bleeding_Effects]=(ActiveEffects(Resistance_EffectTypes,Bleeding_Effects,10,10));
  
    EXPECT_EQ(3,d.size());
    a.setResistanceTypes(d);

    EXPECT_EQ(35,a.getTotalResistance());

    a.addResistanceType(ActiveEffects(Resistance_EffectTypes,BluntResistance_Effects,5,10));
    EXPECT_EQ(40,a.getTotalResistance());
}

TEST(ArmorTest,AddResistance){
    Armor a;
   
    EXPECT_EQ(0,a.getTotalResistance());
    EXPECT_EQ(1,a.getResistanceTypes().size());

    //should fail because not a resistance type;
    EXPECT_FALSE(a.addResistanceType(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,10,10)));
    EXPECT_EQ(0,a.getTotalResistance());
    EXPECT_EQ(1,a.getResistanceTypes().size());

    //checks for dublicate should increase the resistance but not add a new type
    EXPECT_TRUE(a.addResistanceType(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,1,1)));
    EXPECT_EQ(1,a.getTotalResistance());
    EXPECT_EQ(2,a.getResistanceTypes().size());
    EXPECT_TRUE(a.addResistanceType(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,5,1)));
    EXPECT_EQ(6,a.getTotalResistance());
    EXPECT_EQ(2,a.getResistanceTypes().size());

    EXPECT_TRUE(a.addResistanceType(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,5,1)));
    EXPECT_EQ(11,a.getTotalResistance());
    EXPECT_EQ(3,a.getResistanceTypes().size());


}