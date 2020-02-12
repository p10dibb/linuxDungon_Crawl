#pragma once
#include "../Room_Design/Room_Design.h"
#include <time.h>

void Run();

Player createPlayer();

//randomly generates a floor
Floor createFloor();

//the first thing the player sees chooses between new Character, Load Character,exit, other?
int StartScreen();