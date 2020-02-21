#pragma once
#include "../Level/Floor/Floor.h"

#include <time.h>
Room createRoom0_0();
Room createRoom1_0();
Room createRoom0_1();


Room createLeftRoom();
Room createRightRoom();
Room createUpRoom();
Room createDownRoom();

//botton Left corner room
Room createRoom9_0();

//botton Right corner room
Room createRoom9_9();

//top Right corner room
Room createRoom0_9();


//Default room 4 doors 10 by 10
Room createDefaultRoom_V1();

//create Default room 4 door + shape
Room createDefaultRoom_V2();

//creates default Room 4 doors verticle hallway
Room createDefaultRoom_V3();

//creates default Room 4 doors horizontal hallway
Room createDefaultRoom_V4();

//create a treasure room 4 doors 7x7 square
Room createTreasureRoom_V1();