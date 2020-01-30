#include "Player.h"
#include <gtest/gtest.h>


//add To Inventory
TEST(PlayerInventoryTest,AddToInventory){
    Player p;
    Item *i=new Item();
    i->setName("item1");
    i->setStackSize(1);
    i->setWeight(10);


    //failure test
    p.setInventorySize(40);
    p.setFreeSlots(0);
    EXPECT_FALSE(p.addToInventory(i));

    //success non stakable new item;
    p.setFreeSlots(40);
    EXPECT_TRUE(p.addToInventory(i));
    EXPECT_EQ(39,p.getFreeSlots());
    EXPECT_FALSE(p.getOverWeighted());

    //adding stackable items
    Item *i1= new Item;
    i1->setName("item2");
    i1->setStackSize(5);
    i1->setWeight(50);
    p.setMaxWeight(90);

    EXPECT_TRUE(p.addToInventory(i1));
    EXPECT_EQ(38,p.getFreeSlots());
    EXPECT_FALSE(p.getOverWeighted());

    EXPECT_TRUE(p.addToInventory(i1));
    EXPECT_EQ(38,p.getFreeSlots());
    EXPECT_TRUE(p.getOverWeighted());
}

//Remove Item from inventory
TEST(PlayerInventoryTest,RemoveItemFromInventory){
    Player p;
    //setting inventory slots with items
    Item *s0= new Item();
    s0->setName("slot 0");
    Item *s1 = new Item();
    s1->setName("slot 1");
    Item *s2= new Item();
    s2->setName("slot 2");
    s2->setStackSize(3);
    Item *s3 =new Item();
    s3->setName("slot 3");

    //adding items to inventory
    p.addToInventory(s0);
    p.addToInventory(s1);
    p.addToInventory(s2);
    p.addToInventory(s2);
    p.addToInventory(s3);

    // //checks below min
    EXPECT_EQ("Empty",p.RemoveItemFromInventory(-5)->getName());
    
    //checks above max  
    EXPECT_EQ("Empty",p.RemoveItemFromInventory(110)->getName());

    //checks removing the first item
    EXPECT_EQ("slot 1",p.RemoveItemFromInventory(1)->getName());
    EXPECT_EQ("Empty",p.RemoveItemFromInventory(1)->getName());

    //checks removing item in a stack
    EXPECT_EQ("slot 2",p.RemoveItemFromInventory(2)->getName());
    EXPECT_EQ("slot 2",p.RemoveItemFromInventory(2)->getName());
    EXPECT_EQ("Empty",p.RemoveItemFromInventory(1)->getName());
}

//Display inventory
TEST(PlayerInventoryTest,DisplayInventory){
    EXPECT_FALSE(false);
}

//Inventory Dialogue
TEST(PlayerInventoryTest,InventoryDialogue){
    //add test Mocking?
    EXPECT_FALSE(false);
}

//get Func Inventory
TEST(PlayerInventoryTest,getFuncInventory){
    Player p;

    //view
    EXPECT_EQ(0,p.getFuncInventory("view"));

    //Equip
    EXPECT_EQ(1,p.getFuncInventory("equip"));

    //Use
    EXPECT_EQ(2,p.getFuncInventory("use"));

    //Move
    EXPECT_EQ(3,p.getFuncInventory("move"));

    //Exit
    EXPECT_EQ(4,p.getFuncInventory("exit"));

    //Failure
    EXPECT_EQ(-1,p.getFuncInventory("woot"));
}

//view inventory
TEST(PlayerInventoryTest,ViewInventory){
    Player p;
    Armor *i0=new Armor();
    Weapon *i1 =new Weapon();
    Potion *i2 =new Potion();

    p.addToInventory(i0);
    p.addToInventory(i1);
    p.addToInventory(i2);

    EXPECT_EQ(0,p.ViewInventory(0));
    EXPECT_EQ(0,p.ViewInventory(1));
    EXPECT_EQ(0,p.ViewInventory(2));
    EXPECT_EQ(-1,p.ViewInventory(3));

}

//equip inventory
TEST(PlayerInventoryTest,EquipInventory){
    EXPECT_TRUE(true);
    //write test that mock input;
}

//use inventory
TEST(PlayerInventoryTest,UseInventory){
    EXPECT_TRUE(true);
    //write test that mock input;
}
//move inventory
TEST(PlayerInventoryTest,MoveInventory){
    EXPECT_TRUE(true);
    //write test that mock input;
}

//Display equiped
TEST(PlayerInventoryTest,DisplayEquipped){
    EXPECT_TRUE(true);
    //write test that mock input;
}

//equiped dialogue
TEST(PlayerInventoryTest,EquipedDialogue){
    EXPECT_TRUE(true);
    //write test that mock input;
}