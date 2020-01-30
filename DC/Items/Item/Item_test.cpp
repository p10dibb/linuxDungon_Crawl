#include "Item.h"
#include <gtest/gtest.h>

TEST(ItemTest,DefaultConstructor){
    Item i;

    //tests default constructor
    EXPECT_EQ("Empty",i.getName());
    EXPECT_EQ(0,i.getWeight());
    EXPECT_EQ(0,i.getValue());
    EXPECT_EQ(1,i.getStackSize());
    EXPECT_EQ("",i.getDescription());

    //tests the constructor where all inputs should be set as they are
    i=Item("NewItem",100,10,10,"this is new item");
   
    EXPECT_EQ("NewItem",i.getName());
    EXPECT_EQ(10,i.getWeight());
    EXPECT_EQ(100,i.getValue());
    EXPECT_EQ(10,i.getStackSize());
    EXPECT_EQ("this is new item",i.getDescription());
    
    //tests the constructor where weight, value. and stack size dont take and get set to thier defaults
    i=Item("NewItem2",-10,-10,-10,"this is new item 2");
   
    EXPECT_EQ("NewItem2",i.getName());
    EXPECT_EQ(0,i.getWeight());
    EXPECT_EQ(0,i.getValue());
    EXPECT_EQ(1,i.getStackSize());
    EXPECT_EQ("this is new item 2",i.getDescription());
}

TEST(ItemSetterTest,setValue){
    Item i;
    EXPECT_EQ(0,i.getValue());
    
    //should succeed value==100
    i.setValue(100);
    EXPECT_EQ(100,i.getValue());

    //should be set to 0 because value cannot be below 0
    i.setValue(-10);
    EXPECT_EQ(0,i.getValue());
}

TEST(ItemSetterTest,setWeight){
    Item i;
    EXPECT_EQ(0,i.getWeight());
    
    //should succeed weight==100
    i.setWeight(100);
    EXPECT_EQ(100,i.getWeight());

    //should be set to 0 because weight cannot be below 0
    i.setWeight(-10);
    EXPECT_EQ(0,i.getWeight());
}

TEST(ItemSetterTest,setStackSize){
    Item i;
    EXPECT_EQ(1,i.getStackSize());
    
    //should succeed StackSize==100
    i.setStackSize(100);
    EXPECT_EQ(100,i.getStackSize());

    //should be set to 1 because StackSize cannot be below 1
    i.setStackSize(-10);
    EXPECT_EQ(1,i.getStackSize());
}