#pragma once
#include "../Level/Floor/Floor.h"

#include <time.h>
void Run();

Player createPlayer();

//visually see some of the armor details
void TestArmorStuff();

//visually see the effects of the Combat effects in a controlled enviornment;
void TestResistanceEffects();

Room createRoom0_0();
Room createRoom1_0();
Room createRoom0_1();

Room createDefaultRoom();
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