#include "Player.h"
#include <gtest/gtest.h>




//checks to see if player becomes overwighted
TEST(PlayerTest,CheckIsOverWeight){
    Player p;
    
    //Creating item with weight of 100 (above p.maxweight)
    Item *i =new Item();
    i->setName("name");
    i->setWeight(100);

    //initial weight=0 Max weight =50
    EXPECT_EQ(50,p.getMaxWeight());
    EXPECT_FALSE(p.getOverWeighted());

    //adds item to inventory which should increase current weight by 100 an set Overweighted to true
    p.addToInventory(i);
    EXPECT_TRUE(p.getOverWeighted());

    //removes the item which should decrease current weight by 100 which sets Overweighted to false
    p.RemoveItemFromInventory(0);   
    EXPECT_FALSE(p.getOverWeighted());
}

//set Left
TEST(PlayerSetterTest,Left){
    Player p;
    Weapon *w= new Weapon();

    //test for success
    w->setLevel(1);
    p.setLevel(1);
    EXPECT_EQ(1,p.setLeft(w));

    //tests for fail  weapon level to high
    w->setLevel(3);
    p.setLevel(1);
    EXPECT_EQ(0,p.setLeft(w));
}

//set Right
TEST(PlayerSetterTest,Right){
    Player p;
    Weapon *w= new Weapon();

    //test for success
    w->setLevel(1);
    p.setLevel(1);
    EXPECT_EQ(1,p.setRight(w));

    //tests for fail  weapon level to high
    w->setLevel(3);
    p.setLevel(1);
    EXPECT_EQ(0,p.setRight(w));
}

//set Money
TEST(PlayerSetterTest,Money){
    Player p;

    //checking default amount
    EXPECT_EQ(0,p.getMoney());

    //sets money to arbitrary value
    p.setMoney(24);
    EXPECT_EQ(24,p.getMoney());

    //checks that negative set equals 0
    p.setMoney(-4);
    EXPECT_EQ(0,p.getMoney());
}

//set Level Up (amount of xp till next level up)
TEST(PlayerSetterTest,LevelUp){
    Player p;
    //checks default
    EXPECT_EQ(10,p.getLevelUp());

    //sets to an arbitrary amount
    p.setLevelUp(54);
    EXPECT_EQ(54,p.getLevelUp());

    //checks for val <1 should set to 1
    p.setLevelUp(0);
    EXPECT_EQ(1,p.getLevelUp());
}

//set Inventory
TEST(PlayerSetterTest,Inventory){
    //doesnt do anything
    EXPECT_EQ(0,0);
}

//set Free Slots
TEST(PlayerSetterTest,FreeSlots){
    Player p;

    //checks defaults
    EXPECT_EQ(40,p.getFreeSlots());
    p.setInventorySize(80);
    
    //checks valid value
    p.setFreeSlots(60);
    EXPECT_EQ(60,p.getFreeSlots());

    //checks value <0
    p.setFreeSlots(-1);
    EXPECT_EQ(0,p.getFreeSlots());

    //checks value > inventorySize
    p.setFreeSlots(90);
    EXPECT_EQ(80,p.getInventorySize());
       
}
//setInventorySize
TEST(PlayerSetterTest,InventorySize){
    Player p;

    //checks initial
    EXPECT_EQ(40,p.getInventorySize());

    //valid amount
    p.setInventorySize(80);
    EXPECT_EQ(80,p.getInventorySize());

    //set val below 1;
    p.setInventorySize(0);
    EXPECT_EQ(1,p.getInventorySize());

    //set val above 100 (above max)
    p.setInventorySize(110);
    EXPECT_EQ(99,p.getInventorySize());

}

//set Max Weight
TEST(PlayerSetterTest,MaxWeight){
    Player p;

    p.setMaxWeight(111);
    EXPECT_EQ(111,p.getMaxWeight());

    //below 0;

    p.setMaxWeight(-1);
    EXPECT_EQ(1,p.getMaxWeight());
}

//setCurrentWeight
TEST(PlayerSetterTest,CurrentWeight){
    Player p;

    p.setCurrentWeight(10);
    EXPECT_EQ(10,p.getCurrentWeight());

    //checks set val below 0
    p.setCurrentWeight(-1);
    EXPECT_EQ(0,p.getCurrentWeight());
}

//setOverweighted
TEST(PlayerSetterTest,OverWeighted){
    Player p;

    p.setOverWeighted(true);
    EXPECT_TRUE(p.getOverWeighted());

     p.setOverWeighted(false);
    EXPECT_FALSE(p.getOverWeighted());

}
