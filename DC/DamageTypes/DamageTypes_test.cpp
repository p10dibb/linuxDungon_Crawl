#include "DamageTypes.h"
#include <gtest/gtest.h>

//Default constructor
TEST(DamageTypesTest,constructor){
    DamageTypes d;
    
    //Default constructor
    EXPECT_EQ(0,d.getDamage());
    EXPECT_EQ(100,d.getProbability());
    EXPECT_EQ(Normal_DamageType,d.getType());
    EXPECT_FALSE(d.getIsDamageOverTime());
    EXPECT_EQ(0,d.getDamageOverTime_damage());
    EXPECT_EQ(0,d.getDamageOverTime_time());


    //tests if it succeeds
    d=DamageTypes(10,50,Fire_DamageType,true,5,5);
    EXPECT_EQ(10,d.getDamage());
    EXPECT_EQ(50,d.getProbability());
    EXPECT_EQ(Fire_DamageType,d.getType());
    EXPECT_TRUE(d.getIsDamageOverTime());
    EXPECT_EQ(5,d.getDamageOverTime_damage());
    EXPECT_EQ(5,d.getDamageOverTime_time());

}

//tests setter for is damage over time
TEST(DamageTypesSetterTest,IsDamageOverTime){
    DamageTypes d;
    
    //checks initial values
    EXPECT_FALSE(d.getIsDamageOverTime());
    EXPECT_EQ(0,d.getDamageOverTime_damage());
    EXPECT_EQ(0,d.getDamageOverTime_time());

    //checks that set true works and it changes damageovertime_damage,time
    d.setIsDamageOverTime(true);
    EXPECT_TRUE(d.getIsDamageOverTime());
    EXPECT_EQ(1,d.getDamageOverTime_damage());
    EXPECT_EQ(1,d.getDamageOverTime_time());


    //checks if pre initialized values stay the same when set to true
    d.setDamageOverTime_damage(10);
    d.setDamageOverTime_time(10);

    d.setIsDamageOverTime(true);
    EXPECT_TRUE(d.getIsDamageOverTime());
    EXPECT_EQ(10,d.getDamageOverTime_damage());
    EXPECT_EQ(10,d.getDamageOverTime_time());
}

//tests setters for damageovertime_damage
TEST(DamageTypesSetterTest,DamageOverTime_damage){
    DamageTypes d;

    //checks initial value
    EXPECT_EQ(0,d.getDamageOverTime_damage());

    //should succeed
    d.setDamageOverTime_damage(100);
    EXPECT_EQ(100,d.getDamageOverTime_damage());

    //should set damage to 0;
    d.setDamageOverTime_damage(-10);
    EXPECT_EQ(0,d.getDamageOverTime_damage());
}

//tests setters for damageovertime_time
TEST(DamageTypesSetterTest,DamageOverTime_time){
    DamageTypes d;

    //checks initial value
    EXPECT_EQ(0,d.getDamageOverTime_time());

    //should succeed
    d.setDamageOverTime_time(100);
    EXPECT_EQ(100,d.getDamageOverTime_time());

    //should set time to 0;
    d.setDamageOverTime_time(-10);
    EXPECT_EQ(0,d.getDamageOverTime_time());
}

//tests setters for damage
TEST(DamageTypesSetterTest,Damage){
    DamageTypes d;

    //checks initial value
    EXPECT_EQ(0,d.getDamage());

    //should succeed
    d.setDamage(100);
    EXPECT_EQ(100,d.getDamage());

    //should set damage to 0;
    d.setDamage(-10);
    EXPECT_EQ(0,d.getDamage());
}

//tests setters for probability
TEST(DamageTypesSetterTest,Probability){
    DamageTypes d;

    //checks initial value
    EXPECT_EQ(100,d.getProbability());

    //should succeed
    d.setProbability(100);
    EXPECT_EQ(100,d.getProbability());

    //should set probability to 0;
    d.setProbability(-10);
    EXPECT_EQ(0,d.getProbability());

    //should set probability to 100
    d.setProbability(110);
    EXPECT_EQ(100,d.getProbability());
}
