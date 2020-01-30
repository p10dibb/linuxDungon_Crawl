
#include <gtest/gtest.h>
#include "ActiveEffects.h"

//TESts the consteructors
TEST(ActiveEffectsTest,Constructor){
    ActiveEffects a;
    
    //Checks Default constructor
    EXPECT_EQ(NULL_Effects,a.getEffect());
    EXPECT_EQ(NULL_EffectTypes,a.getEffectType());
    EXPECT_EQ(0,a.getRound());
    EXPECT_EQ(0,a.getModifier());

    //checks for Buff_effecttype setter all should succeed
    a= ActiveEffects(Buff_EffectTypes,SpeedBoost_Effects,10,10);
    EXPECT_EQ(Buff_EffectTypes,a.getEffectType());
    EXPECT_EQ(SpeedBoost_Effects,a.getEffect());
    EXPECT_EQ(10,a.getModifier());
    EXPECT_EQ(10,a.getRound());

    //checks for bufftype where multiplier and rounds gets set to 0
    a= ActiveEffects(Buff_EffectTypes,SpeedBoost_Effects,-1,-1);
    EXPECT_EQ(Buff_EffectTypes,a.getEffectType());
    EXPECT_EQ(SpeedBoost_Effects,a.getEffect());
    EXPECT_EQ(0,a.getModifier());
    EXPECT_EQ(0,a.getRound());
    

    //checks for Resistance_effecttype setter all should succeed
    a= ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,10,10);
    EXPECT_EQ(Resistance_EffectTypes,a.getEffectType());
    EXPECT_EQ(FireResistance_Effects,a.getEffect());
    EXPECT_EQ(10,a.getModifier());
    EXPECT_EQ(10,a.getRound());

    //checks for Resistancetype where resistance and rounds gets set to 0
    a= ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,-1,-1);
    EXPECT_EQ(Resistance_EffectTypes,a.getEffectType());
    EXPECT_EQ(FireResistance_Effects,a.getEffect());
    EXPECT_EQ(-1,a.getModifier());
    EXPECT_EQ(0,a.getRound());

    //checks for Resistancetype where resistance and rounds gets set to 100,0
    a= ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,110,-1);
    EXPECT_EQ(Resistance_EffectTypes,a.getEffectType());
    EXPECT_EQ(FireResistance_Effects,a.getEffect());
    EXPECT_EQ(100,a.getModifier());
    EXPECT_EQ(0,a.getRound());

     //checks for DamageOverTime_effecttype setter all should succeed
    a= ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,10,10);
    EXPECT_EQ(DamageOverTime_EffectTypes,a.getEffectType());
    EXPECT_EQ(Burning_Effects,a.getEffect());
    EXPECT_EQ(10,a.getModifier());
    EXPECT_EQ(10,a.getRound());

    //checks for DamageOverTimetype where resistance and rounds gets set to 0
    a= ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,-1,-1);
    EXPECT_EQ(DamageOverTime_EffectTypes,a.getEffectType());
    EXPECT_EQ(Burning_Effects,a.getEffect());
    EXPECT_EQ(0,a.getModifier());
    EXPECT_EQ(0,a.getRound());
}   

//Tests SetRound
TEST(ActiveEffectsSetterTest,Rounds){
    ActiveEffects a;

    EXPECT_EQ(0,a.getRound());

    //should succeed
    a.setRound(100);
    EXPECT_EQ(100,a.getRound());

    //should set rounds to 0
    a.setRound(-100);
    EXPECT_EQ(0,a.getRound());
}

//Tests SetModifier
TEST(ActiveEffectsSetterTest,Modifier){
    ActiveEffects a;

    EXPECT_EQ(0,a.getModifier());

    //should succeed
    a.setModifier(100);
    EXPECT_EQ(100,a.getModifier());

    //should set Modifier to -100
    a.setModifier(-100);
    EXPECT_EQ(-100,a.getModifier());
}

//Tests SetDamage
TEST(ActiveEffectsSetterTest,Damage){
    ActiveEffects a =ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,0,0);
    
    EXPECT_EQ(0,a.getDamage());

    //should succeed
    a.setDamage(100);
    EXPECT_EQ(100,a.getDamage());

    //should set rounds to 0
    a.setDamage(-100);
    EXPECT_EQ(0,a.getDamage());
}

//Tests SetResistance
TEST(ActiveEffectsSetterTest,Resistance){
    ActiveEffects a=ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,0,0);

    EXPECT_EQ(0,a.getResistance());

    //should succeed
    a.setResistance(50);
    EXPECT_EQ(50,a.getResistance());

    //should succeed 
    a.setResistance(-100);
    EXPECT_EQ(-100,a.getResistance());

    //should set Resistance to 100
    a.setResistance(110);
    EXPECT_EQ(100,a.getResistance());
}

//Tests Decrement
TEST(ActiveEffectTest,Decrement){
    ActiveEffects a;

    EXPECT_EQ(0,a.getRound());

    //should fail
    EXPECT_FALSE(a.Decrement());
    EXPECT_EQ(0,a.getRound());

    //should fail
    EXPECT_FALSE(a.Decrement(10));
    EXPECT_EQ(0,a.getRound());

    //sets 10 rounds
    a.setRound(10);
    EXPECT_EQ(10,a.getRound());

      //should Succeed
    EXPECT_TRUE(a.Decrement());
    EXPECT_EQ(9,a.getRound());

      //should fail since only 9 rounds left so cant decrement by 10
    EXPECT_FALSE(a.Decrement(10));
    EXPECT_EQ(9,a.getRound());

      //should Succeed
    EXPECT_TRUE(a.Decrement(4));
    EXPECT_EQ(5,a.getRound());
}

//Test IsFinished
TEST(ActiveEffectsTest,isFinished){
    ActiveEffects a;

    EXPECT_EQ(0,a.getRound());
    EXPECT_TRUE(a.isFinished());

    a.setRound(3);
    EXPECT_EQ(3,a.getRound());

    EXPECT_FALSE(a.isFinished());
    a.Decrement(3);
    EXPECT_TRUE(a.isFinished());

}

//Test addRounds
TEST(ActiveEffectsTest,addRounds){
    ActiveEffects a;
    EXPECT_EQ(0,a.getRound());
    
    //SHOULD SUcceed
    EXPECT_TRUE(a.addRounds(10));
    EXPECT_EQ(10,a.getRound());

    EXPECT_FALSE(a.addRounds(-10));
    EXPECT_EQ(10,a.getRound());
}