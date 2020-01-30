#include "Potion.h"
#include <gtest/gtest.h>

//tests Constructors
TEST(PotionTest,Constructor){
    Potion p;

    //Default
    EXPECT_EQ(1,p.getTier());
    EXPECT_EQ(NULL_PotionType,p.getType());
    EXPECT_EQ(0,p.getBaseBooster());
    EXPECT_EQ(5,p.getStackSize());
}

//tests setType
TEST(PotionSetterTest,Type){
    Potion p;

    EXPECT_EQ(NULL_PotionType,p.getType());

    p.setType(Health_PotionType);
    EXPECT_EQ(Health_PotionType,p.getType());
}

//Tests setTier
TEST(PotionSetterTest,Tier){
    Potion p;

    //default value
    EXPECT_EQ(1,p.getTier());

    //sets it to an arbitrary value >=1
    p.setTier(4);
    EXPECT_EQ(4,p.getTier());

    //checks min value
    p.setTier(-1);
    EXPECT_EQ(1,p.getTier()); 
}

//Tests setBaseBooster
TEST(PotionSetterTest,BaseBooster){
    Potion p;

    EXPECT_EQ(0,p.getBaseBooster());

    p.setBaseBooster(5);
    EXPECT_EQ(5,p.getBaseBooster());

}

//Tests Use Health Potion
TEST(PotionUseTest,Health){
    Potion p;
    Creature *c=new Creature();

    //sets health potion that will restore 30 health
    p.setType(Health_PotionType);
    p.setBaseBooster(10);
    p.setTier(3);
    //Use Health Potion
    c->setMaxHealth(150);
    c->setHealth(110);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(140,c->getHealth());
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(150,c->getHealth());

}

TEST(PotionUseTest,SpeedStat){
    Potion p;
    Creature *c=new Creature();
    //Use SpeedStat potion
    p.setType(SpeedStat_PotionType);
    p.setBaseBooster(1);
    p.setTier(1);
    c->setSpeed(0);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(2,c->getSpeed());
}

TEST(PotionUseTest,StrengthStat){
    Potion p;
    Creature *c=new Creature();
    //StrengthStat potion
    p.setType(StrengthStat_PotionType);
    p.setBaseBooster(1);
    p.setTier(1);
    c->setStrength(0);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(1,c->getStrength());
}

  
    


    //MaxHealthStat potion
TEST(PotionUseTest, MaxHealthStat){
       Potion p;
    Creature *c=new Creature();
    p.setType(MaxHealthStat_PotionType);
    p.setBaseBooster(1);
    p.setTier(1);
    c->setHealth(90);
    c->setMaxHealth(100);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(100,c->getHealth());
    EXPECT_EQ(110,c->getMaxHealth());
}

    //Defense Stat potion
TEST(PotionUseTest,DefenseStat){
    Potion p;
    Creature *c=new Creature();
    p.setType(DefenseStat_PotionType);
    p.setBaseBooster(1);
    p.setTier(1);
    c->setDefense(0);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(1,c->getDefense());
} 

    //Damage stat potion
TEST(PotionUseTest,DamageStat){
    Potion p;
    Creature *c=new Creature();
    p.setType(DamageStat_PotionType);
    p.setBaseBooster(1);
    p.setTier(1);
    c->setDamage(0);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(2,c->getDamage());
} 
    //Stamina stat potion
TEST(PotionUseTest,StaminaStat){
    Potion p;
    Creature *c=new Creature();
    p.setType(StaminaStat_PotionType);
    p.setBaseBooster(1);
    p.setTier(1);
    c->setStamina(0);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(2,c->getStamina());
} 
    //Increase Damage potion
TEST(PotionUseTest,IncreaseDamage){
    Potion p;
    Creature *c =new Creature();

    EXPECT_EQ(0,c->getBuffEffects().size());
    p.setType(IncreaseDamage_PotionType);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(1,c->getBuffEffects().size());
    EXPECT_TRUE(c->ContainBuffEffect(DamageBoost_Effects));
}

    //Increase Deffense  potion
TEST(PotionUseTest,IncreaseDefense){
    Potion p;
    Creature *c =new Creature();

    EXPECT_EQ(0,c->getBuffEffects().size());
    p.setType(IncreaseDefense_PotionType);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(1,c->getBuffEffects().size());
    EXPECT_TRUE(c->ContainBuffEffect(DefenseBoost_Effects));
}
    //Increase Speed  potion
TEST(PotionUseTest,IncreaseSpeed){
    Potion p;
    Creature *c =new Creature();

    EXPECT_EQ(0,c->getBuffEffects().size());
    p.setType(IncreaseSpeed_PotionType);
    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(1,c->getBuffEffects().size());
    EXPECT_TRUE(c->ContainBuffEffect(SpeedBoost_Effects));
}
    //Cure Active Effects
TEST(PotionsUseTest,CureActiveEffects){
    Potion p;
    Creature *c=new Creature();
    p.setType(CureActiveEffects_PotionType);

    c->AddBuffEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,10,10));
    c->AddBuffEffect(ActiveEffects(Buff_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,Burning_Effects,10,10));
    c->AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,DamageBoost_Effects,10,10));
    c->AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddCombatEffect(ActiveEffects(Combat_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddCombatEffect(ActiveEffects(Combat_EffectTypes,Burning_Effects,10,10));
    c->AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,Burning_Effects,10,10));
  
    EXPECT_EQ(2,c->getBuffEffects().size());
    EXPECT_EQ(2,c->getDeBuffEffects().size());
    EXPECT_EQ(2,c->getCombatEffects().size());
    EXPECT_EQ(2,c->getDamageOverTimeEffects().size());
    EXPECT_EQ(2,c->getResistanceEffects().size());

    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(0,c->getBuffEffects().size());
    EXPECT_EQ(0,c->getDeBuffEffects().size());
    EXPECT_EQ(0,c->getCombatEffects().size());
    EXPECT_EQ(0,c->getDamageOverTimeEffects().size());
    EXPECT_EQ(0,c->getResistanceEffects().size());

}

    //Cure Negative Effects
TEST(PotionsUseTest,CureNegativeEffects){
    Potion p;
    Creature *c=new Creature();
    p.setType(CureNegativeEffects_PotionType);

    c->AddBuffEffect(ActiveEffects(Buff_EffectTypes,DamageBoost_Effects,10,10));
    c->AddBuffEffect(ActiveEffects(Buff_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddDeBuffEffect(ActiveEffects(DeBuff_EffectTypes,Burning_Effects,10,10));
    c->AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,DamageBoost_Effects,10,10));
    c->AddDamageOverTimeEffect(ActiveEffects(DamageOverTime_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddCombatEffect(ActiveEffects(Combat_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddCombatEffect(ActiveEffects(Combat_EffectTypes,Burning_Effects,10,10));
    c->AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,DefenseBoost_Effects,10,10));
    c->AddResistanceEffect(ActiveEffects(Resistance_EffectTypes,Burning_Effects,10,10));
  
    EXPECT_EQ(2,c->getBuffEffects().size());
    EXPECT_EQ(2,c->getDeBuffEffects().size());
    EXPECT_EQ(2,c->getCombatEffects().size());
    EXPECT_EQ(2,c->getDamageOverTimeEffects().size());
    EXPECT_EQ(2,c->getResistanceEffects().size());

    EXPECT_TRUE(p.Use(c));
    EXPECT_EQ(2,c->getBuffEffects().size());
    EXPECT_EQ(0,c->getDeBuffEffects().size());
    EXPECT_EQ(2,c->getCombatEffects().size());
    EXPECT_EQ(0,c->getDamageOverTimeEffects().size());
    EXPECT_EQ(2,c->getResistanceEffects().size());

}
    //Normal Resistance Potion
TEST(PotionUseTest,NormalResistance){
    Potion p;
    Creature *c=new Creature();

    p.setTier(3);
    p.setType(NormalResistance_PotionType);

    EXPECT_EQ(0,c->getResistanceEffects().size());
    EXPECT_TRUE(p.Use(c));
    
    EXPECT_EQ(1,c->getResistanceEffects().size());
    EXPECT_EQ(15,c->getResistanceEffect(NormalResistance_Effects).getResistance());
}
    //Poison Resistance Potion
TEST(PotionUseTest,PoisonResistance){
    Potion p;
    Creature *c=new Creature();

    p.setTier(3);
    p.setType(PoisonResistance_PotonType);

    EXPECT_EQ(0,c->getResistanceEffects().size());
    EXPECT_TRUE(p.Use(c));
    
    EXPECT_EQ(1,c->getResistanceEffects().size());
    EXPECT_EQ(15,c->getResistanceEffect(PoisonResistance_Effects).getResistance());
}
    //Fire Resistance Potion
TEST(PotionUseTest,FireResistance){
    Potion p;
    Creature *c=new Creature();

    p.setTier(3);
    p.setType(FireResistance_PotionType);

    EXPECT_EQ(0,c->getResistanceEffects().size());
    EXPECT_TRUE(p.Use(c));
    
    EXPECT_EQ(1,c->getResistanceEffects().size());
    EXPECT_EQ(15,c->getResistanceEffect(FireResistance_Effects).getResistance());
}
    //Blunt Resistance Potion
TEST(PotionUseTest,BluntResistance){
    Potion p;
    Creature *c=new Creature();

    p.setTier(3);
    p.setType(BluntResistance_PotionType);

    EXPECT_EQ(0,c->getResistanceEffects().size());
    EXPECT_TRUE(p.Use(c));
    
    EXPECT_EQ(1,c->getResistanceEffects().size());
    EXPECT_EQ(15,c->getResistanceEffect(BluntResistance_Effects).getResistance());
}
    //Stabbing Resistance potion
TEST(PotionUseTest,StabbingResistance){
    Potion p;
    Creature *c=new Creature();

    p.setTier(3);
    p.setType(StabbingResistance_PotionType);

    EXPECT_EQ(0,c->getResistanceEffects().size());
    EXPECT_TRUE(p.Use(c));
    
    EXPECT_EQ(1,c->getResistanceEffects().size());
    EXPECT_EQ(15,c->getResistanceEffect(StabbingResistance_Effects).getResistance());
}