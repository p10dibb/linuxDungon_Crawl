#include "Biped.h"
#include <gtest/gtest.h>

//tests SetHead function
TEST(BipedArmorSetterTest,SetHead){
    Biped p;
    Armor *a=new Armor(1,1,Helmet_ArmorType,Light_ArmorClass);

    //successfull
    EXPECT_EQ(1,p.setHead(a));

    //should return 0 because helmet is to high
    a->setLevel(5);
    EXPECT_EQ(0,p.setHead(a));

    //should fail because not helmet and to high of a level
    a->setType(Chest_ArmorType);
    EXPECT_EQ(0,p.setHead(a));

    //should fail because not helmet 
    a->setLevel(1);
    EXPECT_EQ(0,p.setHead(a));
}

//tests set Torso
TEST(BipedArmorSetterTest,SetTorso){
    Biped b;
    Armor *a=new Armor(1,1,Chest_ArmorType,Light_ArmorClass);

    //successfull
    EXPECT_EQ(1,b.setTorso(a));

    //should return 0 because helmet is to high
    a->setLevel(5);
    EXPECT_EQ(0,b.setTorso(a));

    //should fail because not helmet and to high of a level
    a->setType(Boots_ArmorType);
    EXPECT_EQ(0,b.setTorso(a));

    //should fail because not helmet 
    a->setLevel(1);
    EXPECT_EQ(0,b.setTorso(a));
}

//tests set feet
TEST(BipedArmorSetterTest,SetFeet){
    Biped b;
    Armor *a=new Armor(1,1,Boots_ArmorType,Light_ArmorClass);

    //successfull
    EXPECT_EQ(1,b.setFeet(a));

    //should return 0 because helmet is to high
    a->setLevel(5);
    EXPECT_EQ(0,b.setFeet(a));

    //should fail because not helmet and to high of a level
    a->setType(Chest_ArmorType);
    EXPECT_EQ(0,b.setFeet(a));

    //should fail because not helmet 
    a->setLevel(1);
    EXPECT_EQ(0,b.setFeet(a));
}

//tests set Hands
TEST(BipedArmorSetterTest,SetHands){
    Biped b;
    Armor *a=new Armor(1,1,Gloves_ArmorType,Light_ArmorClass);

    //successfull
    EXPECT_EQ(1,b.setHands(a));

    //should return 0 because helmet is to high
    a->setLevel(5);
    EXPECT_EQ(0,b.setHands(a));

    //should fail because not helmet and to high of a level
    a->setType(Chest_ArmorType);
    EXPECT_EQ(0,b.setHands(a));

    //should fail because not helmet 
    a->setLevel(1);
    EXPECT_EQ(0,b.setHands(a));
}

//tests set Legs
TEST(BipedArmorSetterTest,SetLegs){
    Biped b;
    Armor *a=new Armor(1,1,Pants_ArmorType,Light_ArmorClass);

    //successfull
    EXPECT_EQ(1,b.setLegs(a));

    //should return 0 because helmet is to high
    a->setLevel(5);
    EXPECT_EQ(0,b.setLegs(a));

    //should fail because not helmet and to high of a level
    a->setType(Chest_ArmorType);
    EXPECT_EQ(0,b.setLegs(a));

    //should fail because not helmet 
    a->setLevel(1);
    EXPECT_EQ(0,b.setLegs(a));
}