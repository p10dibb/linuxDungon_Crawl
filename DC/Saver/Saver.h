#include "SaveFile/SaveFile.h"
#include <fstream>
#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"
using namespace rapidjson;

//converts an active effect to json
string convertActiveEffect2Json(ActiveEffects effect);

//converts damage Type to json
string convertDamageType2Json(DamageTypes damage);

//conver Item type to json
string convertItem2Json(Item i);

//converts potion to json
string convertPotion2Json(Potion p);

//converts weapons to json
string convertWeapon2Json(Weapon w);

//converts Armor to json
string convertArmor2Json(Armor a);

//converts inventory slot to json
string convertInventorySlot2Json(InventorySlot i);

//converts Player to Json
string convertPlayer2Json(Player p);

//loads active effect from json
ActiveEffects ConvertJson2ActiveEffect(Value& effect);

//loads Damage Type from json
DamageTypes ConvertJson2DamageTypes(Value& types);

//loads Item from json
Item* ConvertJson2Item(Value& item);

//loads Weapon from json
Weapon* ConvertJson2Weapon(Value& item);

//loads potion from json
Potion* ConvertJson2Potion(Value& item);

//loads Armor from Json
Armor* ConvertJson2Armor(Value& item);


//loads InventorySlot from Json
InventorySlot ConvertJson2InventorySlot(Value& slot);


//loads player from Json
Player ConvertJson2Player(Value& player);

//converts saveFile to json
string ConvertSaveFile2Json(SaveFile file);

//prompts user for dialogue to save the file
bool Saver(Player p);

//prompts user for loading file
Player Loader();