#include "Creature.h"
#include <gtest/gtest.h>

//Tests the initial values of the constructor
TEST(CreatureTest,DefaultConstructor){
    Creature c;

    EXPECT_EQ(1,c.getDamage());
    EXPECT_EQ(0,c.getDefense());
    EXPECT_EQ(1,c.getSpeed());
    EXPECT_EQ(1,c.getStamina());
    EXPECT_EQ(0,c.getStrength());
    EXPECT_EQ(100,c.getHealth());
    EXPECT_EQ(100,c.getMaxHealth());
    EXPECT_EQ(1,c.getLevel());
    EXPECT_EQ(0,c.getXP());
    EXPECT_EQ("",c.getName());
    EXPECT_EQ(1,c.getPosition()[0]);
    EXPECT_EQ(1,c.getPosition()[1]);
}
//test the setter for XP
TEST(CreatureSetterTest,SetXP){
    Creature c;
   
    //Checks default value to be 0
    EXPECT_EQ(0,c.getXP());

    //tests successfull setting with an arbitrary value of 10
    c.setXP(10);
    EXPECT_EQ(10,c.getXP());

    //tests that if negative value is attempted then acual value is set to 0
    c.setXP(-10);
    EXPECT_EQ(0,c.getXP());

}
//Test the setter for Damage
TEST(CreatureSetterTest,SetDamage){
    Creature c;
   
    //Checks default value to be 1
    EXPECT_EQ(1,c.getDamage());

    //tests successfull setting with an arbitrary value of 10
    c.setDamage(10);
    EXPECT_EQ(10,c.getDamage());

    //tests that if  value below 1 is attempted then acual value is set to 1
    c.setDamage(-10);
    EXPECT_EQ(1,c.getDamage());

}
//Test the setter for Speed
TEST(CreatureSetterTest,SetSpeed){
    Creature c;
   
    //Checks default value to be 1
    EXPECT_EQ(1,c.getSpeed());

    //tests successfull setting with an arbitrary value of 10
    c.setSpeed(10);
    EXPECT_EQ(10,c.getSpeed());

    //tests that if  value below 1 is attempted then acual value is set to 1
    c.setSpeed(-10);
    EXPECT_EQ(1,c.getSpeed());

}
//Test the setter for Stamina
TEST(CreatureSetterTest,SetStamina){
    Creature c;
   
    //Checks default value to be 1
    EXPECT_EQ(1,c.getStamina());

    //tests successfull setting with an arbitrary value of 10
    c.setStamina(10);
    EXPECT_EQ(10,c.getStamina());

    //tests that if  value below 1 is attempted then acual value is set to 1
    c.setStamina(-10);
    EXPECT_EQ(1,c.getStamina());
}
//Test the setter for Strength
TEST(CreatureSetterTest,SetStrength){
    Creature c;
   
    //Checks default value to be 0
    EXPECT_EQ(0,c.getStrength());

    //tests successfull setting with an arbitrary value of 10
    c.setStrength(10);
    EXPECT_EQ(10,c.getStrength());

    //tests that if  value below 0 is attempted then acual value is set to 1
    c.setStrength(-10);
    EXPECT_EQ(0,c.getStrength());
}
//Test the setter for Defense
TEST(CreatureSetterTest,SetDefense){
    Creature c;
   
    //Checks default value to be 0
    EXPECT_EQ(0,c.getDefense());

    //tests successfull setting with an arbitrary value of 10
    c.setDefense(10);
    EXPECT_EQ(10,c.getDefense());

    //tests that if  value below 0 is attempted then acual value is set to 1
    c.setDefense(-10);
    EXPECT_EQ(0,c.getDefense());
}
//Test the setter for Health
TEST(CreatureSetterTest,SetHealth){
    Creature c;
   
    //Checks default value to be 100
    EXPECT_EQ(100,c.getHealth());

    //tests successfull setting with an arbitrary value of 10
    c.setHealth(10);
    EXPECT_EQ(10,c.getHealth());

    //tests that if  value below 0 is attempted then acual value is set to 0
    c.setHealth(-10);
    EXPECT_EQ(0,c.getHealth());

    //tests the health should not go over the Max health and if it is set above 
    EXPECT_EQ(100,c.getMaxHealth());
    c.setHealth(200);
    EXPECT_EQ(100,c.getHealth());
}
//Test the setter for MaxHealth
TEST(CreatureSetterTest,SetMaxHealth){
    Creature c;
   
    //Checks default value to be 100
    EXPECT_EQ(100,c.getMaxHealth());

    //tests successfull setting with an arbitrary value of 110
    c.setMaxHealth(110);
    EXPECT_EQ(110,c.getMaxHealth());

    //tests that if setting lower value works as well as if max value moves below health 
    //the health decreases as well so there is never an occurence where health is over max health
    EXPECT_EQ(100,c.getHealth());
    c.setMaxHealth(50);
    EXPECT_EQ(50,c.getMaxHealth());
    EXPECT_EQ(50,c.getHealth());

    //tests that if MaxHealth is below 1 it set to 1
    c.setMaxHealth(-10);
    EXPECT_EQ(1,c.getMaxHealth());
}
//Tests the Position setter
TEST(CreatureSetterTest,SetPosition){
    Creature c;
    //checks intial value
    EXPECT_EQ(1,c.getPosition()[0]);
    EXPECT_EQ(1,c.getPosition()[1]);

    //will take any array of 2 values
    c.setPosition({3,4});
    EXPECT_EQ(3,c.getPosition()[0]);
    EXPECT_EQ(4,c.getPosition()[1]);    
}

//Tests the ContainsDamageOverTime v2
TEST(CreatureContainsEffectTest,DamageOverTime_EffectTypes){
    Creature c;
    //tests to see if Double list is empty
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());

    //the double link list is empty so thier should be no effects of any kind in thier
    EXPECT_FALSE( c.ContainDamageOverTimeEffect(Burning_Effects));

    //adding a burning effect 
    c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,10,10));
    //adding a Poison effect 
    c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Poison_Effects,10,10));

    //Effect should be there and return 0 because its position is 0
    EXPECT_TRUE(c.ContainDamageOverTimeEffect(Burning_Effects));

    //Bleeding is still not in there so it should return False
    EXPECT_FALSE(c.ContainDamageOverTimeEffect(Bleeding_Effects));   

    //adding a bleeding affect at pos 2
    c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Bleeding_Effects,10,10));  
    //Bleeding is now in there so it should return 2
    EXPECT_TRUE(c.ContainDamageOverTimeEffect(Bleeding_Effects));   
    
}

//Tests the ContainsCombatEffects v2
TEST(CreatureContainsEffectTest,CombatTypes){
    Creature c;
    //tests to see if Double list is empty
    EXPECT_EQ(0,c.getCombatEffects().size());

    //the double link list is empty so thier should be no effects of any kind in thier
    EXPECT_FALSE( c.ContainCombatEffect(Bezerk_Effects));

    //adding a Bezerk affect at pos 0
    c.AddEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,10,10));
    //adding a AnimalFury affect at pos 1
    c.AddEffect(ActiveEffects(Combat_EffectTypes,AnimalFury_Effects,10,10));

    //Effect should be there and return 0 because its position is true
    EXPECT_TRUE(c.ContainCombatEffect(Bezerk_Effects));

    //Swordsman is still not in there so it should return false
    EXPECT_FALSE(c.ContainCombatEffect(Swordsman_Effects));   

    //adding a Swordsman affect at pos 2
    c.AddEffect(ActiveEffects(Combat_EffectTypes,Swordsman_Effects,10,10));  
    //Swordsman is now in there so it should return true
    EXPECT_TRUE(c.ContainCombatEffect(Swordsman_Effects));     
}

//Tests the ContainsBuffEffects v2
TEST(CreatureContainsEffectTest,BuffTypes){
    Creature c;
    //tests to see if Double list is empty
    EXPECT_EQ(0,c.getBuffEffects().size());

    //the double link list is empty so thier should be no effects of any kind in thier
    EXPECT_FALSE( c.ContainBuffEffect(SpeedBoost_Effects));

    //adding a Bezerk affect at pos 0
    c.AddEffect(ActiveEffects(Buff_EffectTypes,SpeedBoost_Effects,10,10));
    //adding a AnimalFury affect at pos 1
    c.AddEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,10,10));

    //Effect should be there and return 0 because its position is 0
    EXPECT_TRUE(c.ContainBuffEffect(SpeedBoost_Effects));

    //Swordsman is still not in there so it should return -1
    EXPECT_FALSE(c.ContainBuffEffect(DefenseBoost_Effects));   

    //adding a Swordsman affect at pos 2
    c.AddEffect(ActiveEffects(Buff_EffectTypes,DefenseBoost_Effects,10,10));  
    //Swordsman is now in there so it should return 2
    EXPECT_TRUE(c.ContainBuffEffect(DefenseBoost_Effects));     
}

//Tests the ContainsDeBuffEffects v2
TEST(CreatureContainsEffectTest,DeBuffTypes){
    Creature c;
    //tests to see if Double list is empty
    EXPECT_EQ(0,c.getDeBuffEffects().size());

    //the double link list is empty so thier should be no effects of any kind in thier
    EXPECT_FALSE( c.ContainDeBuffEffect(Slowed_Effects));

    //adding a Bezerk affect at pos 0
    c.AddEffect(ActiveEffects(DeBuff_EffectTypes,Slowed_Effects,10,10));
    //adding a AnimalFury affect at pos 1
    c.AddEffect(ActiveEffects(DeBuff_EffectTypes,Dazed_Effects,10,10));

    //Effect should be there and return 0 because its position is 0
    EXPECT_TRUE(c.ContainDeBuffEffect(Slowed_Effects));

    //Swordsman is still not in there so it should return -1
    EXPECT_FALSE(c.ContainDeBuffEffect(Weakness_Effects));   

    //adding a Swordsman affect at pos 2
    c.AddEffect(ActiveEffects(DeBuff_EffectTypes,Weakness_Effects,10,10));  
    //Swordsman is now in there so it should return 2
    EXPECT_TRUE(c.ContainDeBuffEffect(Weakness_Effects));     
}

//Tests the ContainsResistanceEffects v2
TEST(CreatureContainsEffectTest,ResistanceTypes){
    Creature c;
    //tests to see if Double list is empty
    EXPECT_EQ(0,c.getResistanceEffects().size());

    //the double link list is empty so thier should be no effects of any kind in thier
    EXPECT_FALSE( c.ContainResistanceEffect(FireResistance_Effects));

    //adding a Bezerk affect at pos 0
    c.AddEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,10,10));
    //adding a AnimalFury affect at pos 1
    c.AddEffect(ActiveEffects(Resistance_EffectTypes,NormalResistance_Effects,10,10));

    //Effect should be there and return 0 because its position is 0
    EXPECT_TRUE(c.ContainResistanceEffect(FireResistance_Effects));

    //Swordsman is still not in there so it should return -1
    EXPECT_FALSE(c.ContainResistanceEffect(StabbingResistance_Effects));   

    //adding a Swordsman affect at pos 2
    c.AddEffect(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,10,10));  
    //Swordsman is now in there so it should return 2
    EXPECT_TRUE(c.ContainResistanceEffect(StabbingResistance_Effects));     
}

//Tests the run DamageEffectsTest
TEST(CreatureTests,runDamageOverTimeEffects){
    Creature c;
    //checking innitial stats
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());
    EXPECT_EQ(100,c.getHealth());

    //-------------Zero effect---------
        //since it is empty there should be no damage dealt and return 0
        EXPECT_EQ(0,c.runDamageOverTimeEffects());
        c.DecrementAllEffects();
        //checks relavent stats post run
        EXPECT_EQ(0,c.getDamageOverTimeEffects().size());
        EXPECT_EQ(100,c.getHealth());
    //-----------------------------------

    //-------SINGle effect------------------------
        //adds a burning effect that deals 10 damage and lasts 1 round
        c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,10,1));
        //checks size of Active effects
        EXPECT_EQ(1,c.getDamageOverTimeEffects().size());
        //since the 1 fire deals 10 damage it should return 10
        EXPECT_EQ(10,c.runDamageOverTimeEffects());
        c.DecrementAllEffects();
        //size should now be 0 because rounds ran out
        EXPECT_EQ(0,c.getDamageOverTimeEffects().size());
        //health should now be 10 lower
        EXPECT_EQ(90,c.getHealth());
    //---------------------------------------------

    //-------------Multiple Effects----------
        //adds a burning effect that deals 10 damage and lasts 1 round
        c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,10,1));
        //adds a burning effect that deals 10 damage and lasts 1 round
        c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Poison_Effects,10,2));
        //adds a bleeding effect that deals 10 damage and lasts 1 round
        c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Bleeding_Effects,10,1));
        
        //checks size of Active effects
        EXPECT_EQ(3,c.getDamageOverTimeEffects().size());
        //since the 3 effectsdeal 10 damage it should return 30
        EXPECT_EQ(30,c.runDamageOverTimeEffects());
        c.DecrementAllEffects();
        //size should now be 1 because rounds ran out for 2
        EXPECT_EQ(1,c.getDamageOverTimeEffects().size());
        //health should now be 30 lower
        EXPECT_EQ(60,c.getHealth());
    //---------------------------------------

    //-----------Fatal Effect----------------
        //adds a burning effect that deals 100 damage and lasts 1 round
        c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,100,1));
        EXPECT_EQ(-1,c.runDamageOverTimeEffects());
        c.DecrementAllEffects();

    //------------------------------


}

//Tests Clear All EffectTest
TEST(CreatureTests,ClearAllEffects){
    Creature c;

    //checking initial values
    EXPECT_EQ(0,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());

    //test all lists empty
    EXPECT_TRUE(c.ClearAllEffects());
    EXPECT_EQ(0,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());

    //tests all list have items
    c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,1,1));
    c.AddEffect(ActiveEffects(Buff_EffectTypes,SpeedBoost_Effects,1,1));
    c.AddEffect(ActiveEffects(DeBuff_EffectTypes,Dazed_Effects,1,1));
    c.AddEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,1));
    c.AddEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,1,1));
    EXPECT_EQ(1,c.getBuffEffects().size());
    EXPECT_EQ(1,c.getDeBuffEffects().size());
    EXPECT_EQ(1,c.getCombatEffects().size());
    EXPECT_EQ(1,c.getResistanceEffects().size());
    EXPECT_EQ(1,c.getDamageOverTimeEffects().size());
    
    EXPECT_TRUE(c.ClearAllEffects());
    EXPECT_EQ(0,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());

    //tests some lists are empty and some are not
    c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,1,1));
    c.AddEffect(ActiveEffects(Buff_EffectTypes,SpeedBoost_Effects,1,1));
    c.AddEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,1,1));
    EXPECT_EQ(1,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(1,c.getResistanceEffects().size());
    EXPECT_EQ(1,c.getDamageOverTimeEffects().size());
    
    EXPECT_TRUE(c.ClearAllEffects());
    EXPECT_EQ(0,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());
}

//Test DecrementAllEffects
TEST(CreatureTest,DecrementAllEffects){
    Creature c;

    //checking initial values
    EXPECT_EQ(0,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());

    c.DecrementAllEffects();
    EXPECT_EQ(0,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());


    //tests all list have items
    c.AddEffect(ActiveEffects(Buff_EffectTypes,SpeedBoost_Effects,1,1));
    c.AddEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,2,2));
    c.AddEffect(ActiveEffects(Buff_EffectTypes,DefenseBoost_Effects,3,3));
    c.AddEffect(ActiveEffects(DeBuff_EffectTypes,Dazed_Effects,1,1));
    c.AddEffect(ActiveEffects(DeBuff_EffectTypes,Slowed_Effects,1,1));
    c.AddEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,2));
    c.AddEffect(ActiveEffects(Combat_EffectTypes,Swordsman_Effects,2,1));
    c.AddEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,1,1));
    c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,1,1));
    c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Poison_Effects,1,3));
    c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Bleeding_Effects,1,3));

    EXPECT_EQ(3,c.getBuffEffects().size());
    EXPECT_EQ(2,c.getDeBuffEffects().size());
    EXPECT_EQ(2,c.getCombatEffects().size());
    EXPECT_EQ(1,c.getResistanceEffects().size());
    EXPECT_EQ(3,c.getDamageOverTimeEffects().size());

    c.DecrementAllEffects();

    EXPECT_EQ(2,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(1,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(2,c.getDamageOverTimeEffects().size());

   c.DecrementAllEffects();

   EXPECT_EQ(1,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(2,c.getDamageOverTimeEffects().size());

     c.DecrementAllEffects();

    EXPECT_EQ(0,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());

}

//Tests Add Buff effect v2
TEST(CreatureAddEffect,BuffTypes){
    Creature c;
    map<Effects_enum,ActiveEffects> d;


    //Tests for default success
    EXPECT_TRUE(c.AddBuffEffect(ActiveEffects(Buff_EffectTypes,SpeedBoost_Effects,1,1)));
    d=c.getBuffEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(SpeedBoost_Effects,d[SpeedBoost_Effects].getEffect());
    EXPECT_EQ(1,d[SpeedBoost_Effects].getRound());
    EXPECT_EQ(1,d[SpeedBoost_Effects].getModifier());

    //Checks for fail since not a Buff type
    EXPECT_FALSE(c.AddBuffEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,1)));

    
    //Checks for if it already contains buff effect it adds rounds
    EXPECT_TRUE(c.AddBuffEffect(ActiveEffects(Buff_EffectTypes,SpeedBoost_Effects,1,10)));
    d=c.getBuffEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(SpeedBoost_Effects,d[SpeedBoost_Effects].getEffect());
    EXPECT_EQ(11,d[SpeedBoost_Effects].getRound());
    EXPECT_EQ(1,d[SpeedBoost_Effects].getModifier());

    //Checks that when the sum of rounds is 12 and that the modifier is 5
    EXPECT_TRUE(c.AddBuffEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,1,5)));
    EXPECT_TRUE(c.AddBuffEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,5,10)));
    d=c.getBuffEffects();
    EXPECT_EQ(2,d.size());
    EXPECT_EQ(DamageBoost_Effects,d[DamageBoost_Effects].getEffect());
    EXPECT_EQ(12,d[DamageBoost_Effects].getRound());
    EXPECT_EQ(5,d[DamageBoost_Effects].getModifier());

    //Checks that when the sum of rounds is 11 and that the modifier is 7
    EXPECT_TRUE(c.AddBuffEffect(ActiveEffects(Buff_EffectTypes,DefenseBoost_Effects,7,6)));
    EXPECT_TRUE(c.AddBuffEffect(ActiveEffects(Buff_EffectTypes,DefenseBoost_Effects,5,10)));
    d=c.getBuffEffects();
    EXPECT_EQ(3,d.size());
    EXPECT_EQ(DefenseBoost_Effects,d[DefenseBoost_Effects].getEffect());
    EXPECT_EQ(11,d[DefenseBoost_Effects].getRound());
    EXPECT_EQ(7,d[DefenseBoost_Effects].getModifier());
}

//Tests Add DeBuff effect v2
TEST(CreatureAddEffect,DeBuffTypes){
    Creature c;
    map<Effects_enum,ActiveEffects> d;


    //Tests for default success
    EXPECT_TRUE(c.AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,Dazed_Effects,1,1)));
    d=c.getDeBuffEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(Dazed_Effects,d[Dazed_Effects].getEffect());
    EXPECT_EQ(1,d[Dazed_Effects].getRound());
    EXPECT_EQ(1,d[Dazed_Effects].getModifier());

    //Checks for fail since not a Buff type
    EXPECT_FALSE(c.AddDeBuffEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,1)));

    
    //Checks for if it already contains buff effect it adds rounds
    EXPECT_TRUE(c.AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,Dazed_Effects,1,10)));
    d=c.getDeBuffEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(Dazed_Effects,d[Dazed_Effects].getEffect());
    EXPECT_EQ(11,d[Dazed_Effects].getRound());
    EXPECT_EQ(1,d[Dazed_Effects].getModifier());

    //Checks that when the sum of rounds is 12 and that the modifier is 5
    EXPECT_TRUE(c.AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,Slowed_Effects,1,5)));
    EXPECT_TRUE(c.AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,Slowed_Effects,5,10)));
    d=c.getDeBuffEffects();
    EXPECT_EQ(2,d.size());
    EXPECT_EQ(Slowed_Effects,d[Slowed_Effects].getEffect());
    EXPECT_EQ(12,d[Slowed_Effects].getRound());
    EXPECT_EQ(5,d[Slowed_Effects].getModifier());
    
   
    //Checks that when the sum of rounds is 11 and that the modifier is 7
    EXPECT_TRUE(c.AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,BattleFatigue_Effects,7,6)));
    EXPECT_TRUE(c.AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,BattleFatigue_Effects,5,10)));
    d=c.getDeBuffEffects();
    EXPECT_EQ(3,d.size());
    EXPECT_EQ(BattleFatigue_Effects,d[BattleFatigue_Effects].getEffect());
    EXPECT_EQ(11,d[BattleFatigue_Effects].getRound());
    EXPECT_EQ(7,d[BattleFatigue_Effects].getModifier());
}

//Tests Add DamageOverTime effect v2
TEST(CreatureAddEffect,DamageOverTimeTypes){
    Creature c;
    map<Effects_enum,ActiveEffects> d;


    //Tests for default success
    EXPECT_TRUE(c.AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,1,1)));
    d=c.getDamageOverTimeEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(Burning_Effects,d[Burning_Effects].getEffect());
    EXPECT_EQ(1,d[Burning_Effects].getRound());
    EXPECT_EQ(1,d[Burning_Effects].getModifier());

    //Checks for fail since not a Buff type
    EXPECT_FALSE(c.AddDamageOverTimeEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,1)));

    
    //Checks for if it already contains buff effect it adds rounds
    EXPECT_TRUE(c.AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,1,10)));
    d=c.getDamageOverTimeEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(Burning_Effects,d[Burning_Effects].getEffect());
    EXPECT_EQ(11,d[Burning_Effects].getRound());
    EXPECT_EQ(1,d[Burning_Effects].getModifier());
    
    //Checks that when the sum of rounds is 12 and that the modifier is 5
    EXPECT_TRUE(c.AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,Poison_Effects,1,5)));
    EXPECT_TRUE(c.AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,Poison_Effects,5,10)));
    d=c.getDamageOverTimeEffects();
    EXPECT_EQ(2,d.size());
    EXPECT_EQ(Poison_Effects,d[Poison_Effects].getEffect());
    EXPECT_EQ(12,d[Poison_Effects].getRound());
    EXPECT_EQ(5,d[Poison_Effects].getModifier());
    
   
    //Checks that when the sum of rounds is 11 and that the modifier is 7
    EXPECT_TRUE(c.AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,Bleeding_Effects,7,6)));
    EXPECT_TRUE(c.AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,Bleeding_Effects,5,10)));
    d=c.getDamageOverTimeEffects();
    EXPECT_EQ(3,d.size());
    EXPECT_EQ(Bleeding_Effects,d[Bleeding_Effects].getEffect());
    EXPECT_EQ(11,d[Bleeding_Effects].getRound());
    EXPECT_EQ(7,d[Bleeding_Effects].getModifier());
}

//Test add CombatEffects
TEST(CreatureAddEffect,CombatTypes){
    Creature c;
    map<Effects_enum,ActiveEffects> d;


    //Tests for default success
    EXPECT_TRUE(c.AddCombatEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,1)));
    d=c.getCombatEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(Bezerk_Effects,d[Bezerk_Effects].getEffect());
    EXPECT_EQ(1,d[Bezerk_Effects].getRound());

    //Checks for fail since not a Buff type
    EXPECT_FALSE(c.AddCombatEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,1,1)));

    
    //Checks for if it already contains buff effect it adds rounds
    EXPECT_TRUE(c.AddCombatEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,10)));
    d=c.getCombatEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(Bezerk_Effects,d[Bezerk_Effects].getEffect());
    EXPECT_EQ(11,d[Bezerk_Effects].getRound());
    
    //Checks that when the sum of rounds is 15 
    EXPECT_TRUE(c.AddCombatEffect(ActiveEffects(Combat_EffectTypes,Swordsman_Effects,1,5)));
    EXPECT_TRUE(c.AddCombatEffect(ActiveEffects(Combat_EffectTypes,Swordsman_Effects,5,10)));
    d=c.getCombatEffects();
    EXPECT_EQ(2,d.size());
    EXPECT_EQ(Swordsman_Effects,d[Swordsman_Effects].getEffect());
    EXPECT_EQ(15,d[Swordsman_Effects].getRound());
    
}

//Tests Add Resistance effect
TEST(CreatureAddEffect,ResistanceTypes){
    Creature c;
    map<Effects_enum,ActiveEffects> d;


    //Tests for default success
    EXPECT_TRUE(c.AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,1,1)));
    d=c.getResistanceEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(FireResistance_Effects,d[FireResistance_Effects].getEffect());
    EXPECT_EQ(1,d[FireResistance_Effects].getRound());
    EXPECT_EQ(1,d[FireResistance_Effects].getResistance());

    //Checks for fail since not a Buff type
    EXPECT_FALSE(c.AddResistanceEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,1)));

    
    //Checks for if it already contains buff effect it adds rounds
    EXPECT_TRUE(c.AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,1,10)));
    d=c.getResistanceEffects();
    EXPECT_EQ(1,d.size());
    EXPECT_EQ(FireResistance_Effects,d[FireResistance_Effects].getEffect());
    EXPECT_EQ(11,d[FireResistance_Effects].getRound());
    EXPECT_EQ(1,d[FireResistance_Effects].getResistance());
    
    //Checks that when the sum of rounds is 12 and that the modifier is 5
    EXPECT_TRUE(c.AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,1,5)));
    EXPECT_TRUE(c.AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,PoisonResistance_Effects,5,10)));
    d=c.getResistanceEffects();
    EXPECT_EQ(2,d.size());
    EXPECT_EQ(PoisonResistance_Effects,d[PoisonResistance_Effects].getEffect());
    EXPECT_EQ(12,d[PoisonResistance_Effects].getRound());
    EXPECT_EQ(5,d[PoisonResistance_Effects].getResistance());
    
   
    //Checks that when the sum of rounds is 11 and that the modifier is 7
    EXPECT_TRUE(c.AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,7,6)));
    EXPECT_TRUE(c.AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,StabbingResistance_Effects,5,10)));
    d=c.getResistanceEffects();
    EXPECT_EQ(3,d.size());
    EXPECT_EQ(StabbingResistance_Effects,d[StabbingResistance_Effects].getEffect());
    EXPECT_EQ(11,d[StabbingResistance_Effects].getRound());
    EXPECT_EQ(7,d[StabbingResistance_Effects].getResistance());
}

// test Add Effect
TEST(CreatureAddEffect,General){
    Creature c;

    EXPECT_FALSE(c.AddEffect(ActiveEffects(NULL_EffectTypes,NULL_Effects,1,1)));
    EXPECT_EQ(0,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(0,c.getDamageOverTimeEffects().size());

    EXPECT_TRUE(c.AddEffect(ActiveEffects(DamageOverTime_EffectTypes,Burning_Effects,1,1)));
    EXPECT_EQ(0,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(1,c.getDamageOverTimeEffects().size());

    EXPECT_TRUE(c.AddEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,1,1)));
    EXPECT_EQ(1,c.getBuffEffects().size());
    EXPECT_EQ(0,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(1,c.getDamageOverTimeEffects().size());

    EXPECT_TRUE(c.AddEffect(ActiveEffects(DeBuff_EffectTypes,Dazed_Effects,1,1)));
    EXPECT_EQ(1,c.getBuffEffects().size());
    EXPECT_EQ(1,c.getDeBuffEffects().size());
    EXPECT_EQ(0,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(1,c.getDamageOverTimeEffects().size());
    
    EXPECT_TRUE(c.AddEffect(ActiveEffects(Combat_EffectTypes,Bezerk_Effects,1,1)));
    EXPECT_EQ(1,c.getBuffEffects().size());
    EXPECT_EQ(1,c.getDeBuffEffects().size());
    EXPECT_EQ(1,c.getCombatEffects().size());
    EXPECT_EQ(0,c.getResistanceEffects().size());
    EXPECT_EQ(1,c.getDamageOverTimeEffects().size());

    EXPECT_TRUE(c.AddEffect(ActiveEffects(Resistance_EffectTypes,FireResistance_Effects,1,1)));
    EXPECT_EQ(1,c.getBuffEffects().size());
    EXPECT_EQ(1,c.getDeBuffEffects().size());
    EXPECT_EQ(1,c.getCombatEffects().size());
    EXPECT_EQ(1 ,c.getResistanceEffects().size());
    EXPECT_EQ(1,c.getDamageOverTimeEffects().size());
}
//Tests Move
TEST(CreatureTest,move){
    Creature c;
    char BaseMap[10][10]{ {'-','-','-','-','-','-','-','-','-','-' },{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'-','-','-','-','-','-','-','-','-','-' } };
	EXPECT_EQ(0,c.move(BaseMap,1));

}