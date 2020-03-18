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


//  Entrence Left
Room createTreasureRoom_V2();



//--------------Rat King------------

//15 by 10 room 2 doors left and right 4 rodents
Room Create_ShortHall_V1();

//10 by 10  2 doors top and bottom 3 rodents
Room Create_SquareRoom_V1();

//10 by 10  3 doors top and bottom and Right 3 rodents
Room Create_SquareRoom_V2();

//15 by 10 room 2 doors left and right 3 rodents
Room Create_ShortHall_V2();

//10 by 10 2 doors right and down 2 Rodents
Room Create_UpperLeftCorner_V2();

//10 by 10 2 doors left and down 2 Rodents
Room Create_UpperRightCorner_V2();

//10 by 10 2 doors up and right 3 Rodents
Room Create_BottomLeftCorner_V2();

//10 by 1f.0 2 doors up and left 3 Rodents
Room Create_BottomRightCorner_V2();



