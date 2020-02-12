#include "../Level/Floor/Floor.h"
#include <fstream>


//converts an active effect to json
string convertActiveEffect2Json(ActiveEffects effect);

//converts damage Type to json
string converDamageType2Json(DamageTypes damage);

//conver Item type to json
string converItem2Json(Item i);

//converts potion to json
string convertPotion2Json(Potion p);