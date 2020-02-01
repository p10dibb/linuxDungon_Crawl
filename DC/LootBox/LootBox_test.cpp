#include "LootBox.h"
#include <gtest/gtest.h>

//Default constructor
TEST(LootBoxTest, DefaultConstructor)
{

    LootBox l;

    EXPECT_EQ(0, l.getMoney());

    EXPECT_EQ("LootBox", l.getName());

    EXPECT_EQ(0, l.getLoot().size());

    EXPECT_EQ(0, l.getPosition()[0]);

    EXPECT_EQ(0, l.getPosition()[1]);
}

//set Name
TEST(LootBoxSetterTest, Name)
{
    LootBox l;

    EXPECT_EQ("LootBox", l.getName());

    EXPECT_TRUE(l.setName("woot"));

    EXPECT_EQ("woot", l.getName());
}

//set money
TEST(LootBoxSetterTest, Money)
{
    LootBox l;

    EXPECT_EQ(0, l.getMoney());

    EXPECT_TRUE(l.setMoney(100));

    EXPECT_EQ(100, l.getMoney());

    EXPECT_FALSE(l.setMoney(-10));

    EXPECT_EQ(100, l.getMoney());
}

//setLoot
TEST(LootBoxSetterTest, Loot)
{
    LootBox l;
    vector<inventorySlot> i;
    inventorySlot s;

    EXPECT_EQ(0, l.getLoot().size());

    s.amount = 1;
    s.item = new Armor();
    i.push_back(s);

    s.amount = 2;
    s.item = new Potion();
    i.push_back(s);

    EXPECT_TRUE(l.setLoot(i));

    EXPECT_EQ(2, l.getLoot().size());
}

//setPosition
TEST(LootBoxSetterTest, Position)
{

    LootBox l;

    EXPECT_EQ(0, l.getPosition()[0]);
    EXPECT_EQ(0, l.getPosition()[1]);

    EXPECT_TRUE(l.setPosition({1, 1}));

    EXPECT_EQ(1, l.getPosition()[0]);
    EXPECT_EQ(1, l.getPosition()[1]);

    EXPECT_FALSE(l.setPosition({-1, 1}));

    EXPECT_EQ(1, l.getPosition()[0]);
    EXPECT_EQ(1, l.getPosition()[1]);

    EXPECT_FALSE(l.setPosition({-1, -1}));
    EXPECT_EQ(1, l.getPosition()[0]);
    EXPECT_EQ(1, l.getPosition()[1]);

    EXPECT_FALSE(l.setPosition({1, -1}));
    EXPECT_EQ(1, l.getPosition()[0]);
    EXPECT_EQ(1, l.getPosition()[1]);
}

//Merge
TEST(LootBoxTest,Merge){
    LootBox l1,l2;
    Item *i;
    inventorySlot is;
    vector<inventorySlot> v;

    //setting the vector for l2

    //adding 1 armor in spot 0
    i = new Armor();
    i->setName("A1");
    is.item = i;
    is.amount = 1;
    v.push_back(is);

    //adds 3 potions in spot 1
    i = new Potion();
    i->setName("P1");
    i->setStackSize(3);
    is.amount = 3;
    is.item = i;
    v.push_back(is);

    //adds 1 weapon to spot 2
    i = new Weapon();
    i->setName("W1");
    i->setStackSize(1);
    is.amount = 1;
    is.item = i;
    v.push_back(is);

    //adds 1 potions in spot 3
    i = new Potion();
    i->setName("P2");
    i->setStackSize(3);
    is.amount = 1;
    is.item = i;
    v.push_back(is);

    l2.setLoot(v);
    l2.setMoney(20);

    //tests l1 is empty and merges with l2
    EXPECT_TRUE(l1.isEmpty());

    EXPECT_TRUE(l1.Merge(&l2));
    EXPECT_TRUE(l2.isEmpty());

    EXPECT_EQ(4,l1.getLoot().size());

    EXPECT_EQ("A1",l1.getLoot()[3].item->getName());
    EXPECT_EQ(1,l1.getLoot()[3].amount);
    EXPECT_EQ("P1",l1.getLoot()[2].item->getName());
    EXPECT_EQ(3,l1.getLoot()[2].amount);
    EXPECT_EQ("W1",l1.getLoot()[1].item->getName());
    EXPECT_EQ(1,l1.getLoot()[1].amount);
    EXPECT_EQ("P2",l1.getLoot()[0].item->getName());
    EXPECT_EQ(1,l1.getLoot()[0].amount);
    EXPECT_EQ(20,l1.getMoney());


}

//addItem
TEST(LootBoxTest, AddItem)
{
    LootBox l;
    vector<inventorySlot> v;
    Item *i;

    //checks if empty
    EXPECT_EQ(0, l.getLoot().size());

    //adds 1 item;
    i = new Armor();
    i->setName("A1");
    EXPECT_TRUE(l.addItem(i));
    EXPECT_EQ(1, l.getLoot().size());

    //adding an identicle number should not add to stack should take new slot
    EXPECT_TRUE(l.addItem(i));
    EXPECT_EQ(2, l.getLoot().size());

    //checking the vector;
    v = l.getLoot();
    EXPECT_EQ(1, v[0].amount);
    EXPECT_EQ("A1", v[0].item->getName());
    EXPECT_EQ(1, v[1].amount);
    EXPECT_EQ("A1", v[1].item->getName());

    //adds an item that is stackable 4 items in stack size 3 so 2 new slots should be taken
    i = new Potion();
    i->setStackSize(3);
    i->setName("P1");

    for (int j = 0; j < 4; j++)
    {
        EXPECT_TRUE(l.addItem(i));
    }

    //checking the vector
    v = l.getLoot();
    EXPECT_EQ(1, v[0].amount);
    EXPECT_EQ("A1", v[0].item->getName());
    EXPECT_EQ(1, v[1].amount);
    EXPECT_EQ("A1", v[1].item->getName());
    EXPECT_EQ(3, v[2].amount);
    EXPECT_EQ("P1", v[2].item->getName());
    EXPECT_EQ(1, v[3].amount);
    EXPECT_EQ("P1", v[3].item->getName());
}

//addMoney
TEST(LootBoxTest, AddMoney)
{
    LootBox l;

    EXPECT_EQ(0, l.getMoney());

    EXPECT_TRUE(l.addMoney(123));

    EXPECT_EQ(123, l.getMoney());

    EXPECT_TRUE(l.addMoney(12));

    EXPECT_EQ(135, l.getMoney());

    EXPECT_FALSE(l.addMoney(-10));

    EXPECT_EQ(135, l.getMoney());
}

//remove Money
TEST(LootBoxTest, RemoveMoney)
{
    LootBox l;

    //checks if money is 0
    EXPECT_EQ(0, l.getMoney());

    //takes 0 from 0 works
    EXPECT_EQ(0, l.removeMoney(0));
    //takes 10 from zero fails returns 0
    EXPECT_EQ(0, l.removeMoney(10));

    //sets money to 100
    EXPECT_TRUE(l.setMoney(100));
    EXPECT_EQ(100, l.getMoney());

    //takes 10 from 100 works
    EXPECT_EQ(10, l.removeMoney(10));
    EXPECT_EQ(90, l.getMoney());

    //removes 100 from 90 fails. returns 90
    EXPECT_EQ(90, l.removeMoney(100));
    EXPECT_EQ(0, l.getMoney());
}

//remove Item
TEST(LootBoxTest, RemoveItem)
{
    LootBox l;
    InventorySlot is;
    Item *i;
    vector<inventorySlot> v;

    //setting the vector

    //adding 1 armor in spot 0
    i = new Armor();
    i->setName("A1");
    is.item = i;
    is.amount = 1;
    v.push_back(is);

    //adds 3 potions in spot 1
    i = new Potion();
    i->setName("P1");
    i->setStackSize(3);
    is.amount = 3;
    is.item = i;
    v.push_back(is);

    //adds 1 weapon to spot 2
    i = new Weapon();
    i->setName("W1");
    i->setStackSize(1);
    is.amount = 1;
    is.item = i;
    v.push_back(is);

    //adds 1 potions in spot 3
    i = new Potion();
    i->setName("P2");
    i->setStackSize(3);
    is.amount = 1;
    is.item = i;
    v.push_back(is);

    EXPECT_TRUE(l.setLoot(v));
    EXPECT_EQ(4, l.getLoot().size());

    //removes item from end of vector
    EXPECT_EQ("P2", l.removeItem(3)->getName());
    EXPECT_EQ(3, l.getLoot().size());

    //removes item from start of vector
    EXPECT_EQ("A1", l.removeItem(0)->getName());
    EXPECT_EQ(2, l.getLoot().size());


    //all items are shifted to left
    EXPECT_EQ("P1", l.getLoot()[0].item->getName());
    EXPECT_EQ(3, l.getLoot()[0].amount);
    EXPECT_EQ("W1", l.getLoot()[1].item->getName());
    EXPECT_EQ(1, l.getLoot()[1].amount);

    //reseting the loot
    EXPECT_TRUE(l.setLoot(v));
    EXPECT_EQ(4, l.getLoot().size());

    //remove item from the middle
    EXPECT_EQ("W1", l.removeItem(2)->getName());
    EXPECT_EQ(3, l.getLoot().size());

    //remove from item with amount>1
    EXPECT_EQ("P1", l.removeItem(1)->getName());
    EXPECT_EQ(3, l.getLoot().size());
    EXPECT_EQ("P1", l.removeItem(1)->getName());
    EXPECT_EQ(3, l.getLoot().size());
    EXPECT_EQ("P1", l.removeItem(1)->getName());
    EXPECT_EQ(2, l.getLoot().size());

    //emptying the list
    EXPECT_EQ("A1", l.removeItem(0)->getName());
    EXPECT_EQ(1, l.getLoot().size());
    EXPECT_EQ("P2", l.removeItem(0)->getName());
    EXPECT_EQ(0, l.getLoot().size());
}

//is Empty
TEST(LootBoxTest, IsEmpty)
{
    LootBox l;

    //checks that it is initially empty
    EXPECT_TRUE(l.isEmpty());

    //puts money in Box but no loot
    EXPECT_TRUE(l.setMoney(10));
    EXPECT_FALSE(l.isEmpty());

    //adds loot so loot and money are in chest
    EXPECT_TRUE(l.addItem(new Armor()));
    EXPECT_FALSE(l.isEmpty());

    //removes money so now only Loot in chest
    EXPECT_TRUE(l.setMoney(0));
    EXPECT_FALSE(l.isEmpty());

    //removes item so box is empty again
    l.removeItem(0)->getName();
    EXPECT_TRUE(l.isEmpty());
}
 


//Display contents
TEST(LootBoxTest,DisplayContents){
    LootBox l;
   InventorySlot is;
    Item *i;
    vector<inventorySlot> v;

    //setting the vector

    //adding 1 armor in spot 0
    i = new Armor();
    i->setName("A1");
    is.item = i;
    is.amount = 1;
    v.push_back(is);

    //adds 3 potions in spot 1
    i = new Potion();
    i->setName("P1");
    i->setStackSize(3);
    is.amount = 3;
    is.item = i;
    v.push_back(is);

    //adds 1 weapon to spot 2
    i = new Weapon();
    i->setName("W1");
    i->setStackSize(1);
    is.amount = 1;
    is.item = i;
    v.push_back(is);

    //adds 1 potions in spot 3
    i = new Potion();
    i->setName("P2");
    i->setStackSize(3);
    is.amount = 1;
    is.item = i;
    v.push_back(is);

    EXPECT_TRUE(l.setLoot(v));
    EXPECT_TRUE(l.setMoney(54));

    EXPECT_TRUE(l.displayContents());
}