#include "Saver.h"

//converts an active effect to json
string convertActiveEffect2Json(ActiveEffects effect)
{

    string effectStr = "{";

    //adds Effect
    effectStr += "\"Effect\":" + to_string(effect.getEffect()) + ",";
    effectStr += "\"EffectType\":" + to_string(effect.getEffectType()) + ",";
    effectStr += "\"RoundsActive\":" + to_string(effect.getRound()) + ",";
    effectStr += "\"Modifier\":" + to_string(effect.getModifier()) + "}";

    return effectStr;
}

//converts damage Type to json
string convertDamageType2Json(DamageTypes damage)
{

    string damageStr = "{";

    damageStr += "\"Type\":" + to_string(damage.getType()) + ",";
    damageStr += "\"Probability\":" + to_string(damage.getProbability()) + ",";
    damageStr += "\"Damage\":" + to_string(damage.getDamage()) + ",";
    damageStr += "\"isDamageOverTime\":" + to_string(damage.getIsDamageOverTime()) + ",";
    damageStr += "\"DamageOverTime_damage\":" + to_string(damage.getDamageOverTime_damage()) + ",";
    damageStr += "\"DamageOverTime_time\":" + to_string(damage.getDamageOverTime_time()) + "}";

    return damageStr;
}

//conver Item type to json
string convertItem2Json(Item i)
{
    string itemStr = "{";
    itemStr += "\"ItemType\":\"item\",";
    itemStr += "\"Name\":\"" + i.getName() + "\",";
    itemStr += "\"Value\":" + to_string(i.getValue()) + ",";
    itemStr += "\"Weight\":" + to_string(i.getWeight()) + ",";
    itemStr += "\"StackSize\":" + to_string(i.getStackSize()) + ",";
    itemStr += "\"Description\":\"" + i.getDescription() + "\"}";

    return itemStr;
}

//converts potion to json
string convertPotion2Json(Potion p)
{
    string itemStr = "{";
    itemStr += "\"ItemType\":\"potion\",";
    itemStr += "\"Name\":\"" + p.getName() + "\",";
    itemStr += "\"Value\":" + to_string(p.getValue()) + ",";
    itemStr += "\"Weight\":" + to_string(p.getWeight()) + ",";
    itemStr += "\"StackSize\":" + to_string(p.getStackSize()) + ",";
    itemStr += "\"Description\":\"" + p.getDescription() + "\",";
    itemStr += "\"Type\":" + to_string(p.getType()) + ",";
    itemStr += "\"Tier\":" + to_string(p.getTier()) + ",";
    itemStr += "\"BaseBooster\":" + to_string(p.getBaseBooster()) + "}";
    return itemStr;
}

//convers weapon to json
string convertWeapon2Json(Weapon w)
{
    string itemStr = "{";
    itemStr += "\"ItemType\":\"weapon\",";
    itemStr += "\"Name\":\"" + w.getName() + "\",";
    itemStr += "\"Value\":" + to_string(w.getValue()) + ",";
    itemStr += "\"Weight\":" + to_string(w.getWeight()) + ",";
    itemStr += "\"StackSize\":" + to_string(w.getStackSize()) + ",";
    itemStr += "\"Description\":\"" + w.getDescription() + "\",";
    itemStr += "\"WeaponType\":" + to_string(w.getType()) + ",";
    itemStr += "\"DamageTypes\": [";
    vector<DamageTypes> damage = w.getDamageTypes_Weapon();
    for (int i = 0; i < damage.size(); i++)
    {
        itemStr += convertDamageType2Json(damage[i]);
        if (i < damage.size() - 1)
        {
            itemStr += ",";
        }
        else
        {
            itemStr += "],";
        }
    }
    itemStr += "\"Defense\":" + to_string(w.getDefense().getDamage()) + ",";
    itemStr += "\"TwoHanded\":" + to_string(w.getTwoHanded()) + ",";
    itemStr += "\"Speed\":" + to_string(w.getSpeed()) + ",";
    itemStr += "\"Level\":" + to_string(w.getLevel()) + ",";
    itemStr += "\"Range\":" + to_string(w.getRange()) + ",";
    itemStr += "\"Rarity\":" + to_string(w.getRarity()) + ",";
    itemStr += "\"CombatEffect\":" + convertActiveEffect2Json(w.getCombatEffect()) + ",";
    itemStr += "\"WeaponRank\":" + to_string(w.getWeaponRank()) + '}';

    return itemStr;
}
//converts Armor to json
string convertArmor2Json(Armor a)
{
    string itemStr = "{";
    itemStr += "\"ItemType\":\"armor\",";
    itemStr += "\"Name\":\"" + a.getName() + "\",";
    itemStr += "\"Value\":" + to_string(a.getValue()) + ",";
    itemStr += "\"Weight\":" + to_string(a.getWeight()) + ",";
    itemStr += "\"StackSize\":" + to_string(a.getStackSize()) + ",";
    itemStr += "\"Description\":\"" + a.getDescription() + "\",";
    itemStr += "\"Level\":" + to_string(a.getLevel()) + ",";
    itemStr += "\"TotalResistance\":" + to_string(a.getTotalResistance()) + ",";
    itemStr += "\"ArmorType\":" + to_string(a.getType()) + ",";
    itemStr += "\"Class\":" + to_string(a.getClass()) + ",";
    itemStr += "\"Rarity\":" + to_string(a.getRarity()) + ",";
    itemStr += "\"ResistanceTypes\":[";
    vector<ActiveEffects> effects = a.getResistanceTypes();
    for (int i = 0; i < effects.size(); i++)
    {
        itemStr += convertActiveEffect2Json(effects[i]);
        if (i < effects.size() - 1)
        {
            itemStr += ",";
        }
        else
        {
            itemStr += "]}";
        }
    }

    return itemStr;
}

//conver inventory slot to json
string convertInventorySlot2Json(InventorySlot i)
{

    string itemStr = "{";

    itemStr += "\"Amount\":" + to_string(i.amount) + ",";
    itemStr += "\"Item\":";

    if (typeid(*i.item) == typeid(Weapon))
    {

        Weapon *w = dynamic_cast<Weapon *>(i.item);
        itemStr += convertWeapon2Json(*w);
    }
    else if ((typeid(*i.item) == typeid(Armor)))
    {
        Armor *a = dynamic_cast<Armor *>(i.item);
        itemStr += convertArmor2Json(*a);
    }
    else if ((typeid(*i.item) == typeid(Potion)))
    {
        Potion *p = dynamic_cast<Potion *>(i.item);
        itemStr += convertPotion2Json(*p);
    }
    else
    {
        itemStr += convertItem2Json(*i.item);
    }
    itemStr += "}";

    return itemStr;
}

//converts Player to Json
string convertPlayer2Json(Player p)
{
    string itemStr = "{";

    itemStr += "\"Damage\":" + to_string(p.getDamage()) + ",";
    itemStr += "\"Defense\":" + to_string(p.getDefense()) + ",";
    itemStr += "\"Speed\":" + to_string(p.getSpeed()) + ",";
    itemStr += "\"Strength\":" + to_string(p.getStamina()) + ",";
    itemStr += "\"MaxHealth\":" + to_string(p.getMaxHealth()) + ",";
    itemStr += "\"Health\":" + to_string(p.getHealth()) + ",";
    itemStr += "\"Level\":" + to_string(p.getLevel()) + ",";
    itemStr += "\"XP\":" + to_string(p.getXP()) + ",";
    itemStr += "\"Name\":\"" + p.getName() + "\",";
    itemStr += "\"Position\":[" + to_string(p.getPosition()[0]) + "," + to_string(p.getPosition()[1]) + "],";
    itemStr += "\"DebuffEffects\":[";
    map<Effects_enum, ActiveEffects>::iterator it = p.getDeBuffEffects().begin();
    ActiveEffects a;
    if (p.getDeBuffEffects().size() > 0)
    {
        while (it != p.getDeBuffEffects().end())
        {
            a = it->second;
            itemStr += convertActiveEffect2Json(a);
            it++;

            if (it != p.getDeBuffEffects().end())
            {
                itemStr += ",";
            }
        }
    }
    itemStr += "],";
    itemStr += "\"BuffEffects\":[";
    it = p.getBuffEffects().begin();
    if (p.getBuffEffects().size() > 0)
    {

        while (it != p.getBuffEffects().end())
        {
            a = it->second;
            itemStr += convertActiveEffect2Json(a);
            it++;

            if (it != p.getBuffEffects().end())
            {
                itemStr += ",";
            }
        }
    }
    itemStr += "],";

    itemStr += "\"CombatEffects\":[";
    it = p.getCombatEffects().begin();

    if (p.getCombatEffects().size() > 0)
    {

        while (it != p.getCombatEffects().end())
        {
            a = it->second;
            itemStr += convertActiveEffect2Json(a);
            it++;

            if (it != p.getCombatEffects().end())
            {
                itemStr += ",";
            }
        }
    }
    itemStr += "],";

    itemStr += "\"DamageOverTimeEffects\":[";
    if (p.getDamageOverTimeEffects().size() > 0)
    {

        it = p.getDamageOverTimeEffects().begin();
        while (it != p.getDamageOverTimeEffects().end())
        {
            a = it->second;
            itemStr += convertActiveEffect2Json(a);
            it++;

            if (it != p.getDamageOverTimeEffects().end())
            {
                itemStr += ",";
            }
        }
    }
    itemStr += "],";

    itemStr += "\"ResistanceEffects\":[";
    it = p.getResistanceEffects().begin();
    if (p.getResistanceEffects().size() > 0)
    {

        while (it != p.getResistanceEffects().end())
        {
            a = it->second;
            itemStr += convertActiveEffect2Json(a);
            it++;

            if (it != p.getResistanceEffects().end())
            {
                itemStr += ",";
            }
        }
    }
    itemStr += "],";

    itemStr += "\"Head\":" + convertArmor2Json(*p.getHead()) + ",";
    itemStr += "\"Torso\":" + convertArmor2Json(*p.getTorso()) + ",";
    itemStr += "\"Hands\":" + convertArmor2Json(*p.getHands()) + ",";
    itemStr += "\"Legs\":" + convertArmor2Json(*p.getLegs()) + ",";
    itemStr += "\"Feet\":" + convertArmor2Json(*p.getFeet()) + ",";

    itemStr += "\"LeftWeapon\":" + convertWeapon2Json(*p.getLeft()) + ",";
    itemStr += "\"RightWeapon\":" + convertWeapon2Json(*p.getRight()) + ",";
    itemStr += "\"Inventory\":[";

    array<InventorySlot, 100> arr = p.getInventory();
    for (int i = 0; i < 100; i++)
    {
        if (arr[i].item == 0x0)
        {
            break;
        }
        itemStr += convertInventorySlot2Json(arr[i]);

        if (i < 99)
        {
            itemStr += ",";
        }
    }
    itemStr += "],";
    itemStr += "\"FreeSlots\":" + to_string(p.getFreeSlots()) + ",";
    itemStr += "\"InventorySize\":" + to_string(p.getInventorySize()) + ",";
    itemStr += "\"Money\":" + to_string(p.getMoney()) + ",";
    itemStr += "\"LevelUp\":" + to_string(p.getLevelUp()) + ",";
    itemStr += "\"CurrentWeight\":" + to_string(p.getCurrentWeight()) + ",";
    itemStr += "\"MaxWeight\":" + to_string(p.getMaxWeight()) + ",";
    itemStr += "\"OverWeighted\":" + to_string(p.getOverWeighted()) + ",";

    itemStr += "\"CreaturesKilled\":" + to_string(p.getCreaturesKilled()) + ",";
    itemStr += "\"ItemsRecieved\":" + to_string(p.getItemsRecieved()) + ",";
    itemStr += "\"GoldCollected\":" + to_string(p.getGoldCollected()) + ",";
    itemStr += "\"GoldSpent\":" + to_string(p.getGoldSpent()) + ",";
    itemStr += "\"RoomsBeenToo\":" + to_string(p.getRoomsBeenToo()) + ",";
    itemStr += "\"DamageRecieved\":" + to_string(p.getDamageRecieved()) + ",";
    itemStr += "\"DamageDealt\":" + to_string(p.getDamageDealt()) + ",";
    itemStr += "\"MaxGoldHeld\":" + to_string(p.getMaxGoldHeld()) + ",";
    itemStr += "\"MaxDamageDealt\":" + to_string(p.getMaxDamageDealt()) + ",";
    itemStr += "\"PotionsDranked\":" + to_string(p.getPotionsDranked()) + "}";

    return itemStr;
}

//loads active effect from json
ActiveEffects ConvertJson2ActiveEffect(Value &effect)
{

    ActiveEffects ret;
    int mod = effect["Modifier"].GetInt();
    int round = effect["RoundsActive"].GetInt();
    Effects_enum eff = (Effects_enum)effect["Effect"].GetInt();
    EffectTypes_enum type = (EffectTypes_enum)effect["EffectType"].GetInt();

    ret = ActiveEffects(type, eff, mod, round);

    return ret;
}

//loads Damage Type from json
DamageTypes ConvertJson2DamageTypes(Value &types)
{
    DamageTypes ret;

    ret.setDamage(types["Damage"].GetInt());
    ret.setType((DamageTypes_enum)types["Type"].GetInt());
    ret.setProbability(types["Probability"].GetInt());
    ret.setIsDamageOverTime(types["isDamageOverTime"].GetInt());
    ret.setDamageOverTime_damage(types["DamageOverTime_damage"].GetInt());
    ret.setDamageOverTime_time(types["DamageOverTime_time"].GetInt());
    return ret;
}

//loads Item from json
Item *ConvertJson2Item(Value &item)
{

    Item *i = new Item();
    i->setName(item["Name"].GetString());
    i->setValue(item["Value"].GetInt());
    i->setWeight(item["Weight"].GetInt());
    i->setStackSize(item["StackSize"].GetInt());
    i->setDescription(item["Description"].GetString());

    return i;
}

//loads Weapon from json
Weapon *ConvertJson2Weapon(Value &item)
{
    DamageTypes t;

    Weapon *i = new Weapon;
    i->setName(item["Name"].GetString());
    i->setValue(item["Value"].GetInt());
    i->setWeight(item["Weight"].GetInt());
    i->setStackSize(item["StackSize"].GetInt());
    i->setDescription(item["Description"].GetString());
    i->setType((WeaponTypes_enum)item["WeaponType"].GetInt());
    GenericArray<false, Value> damage = item["DamageTypes"].GetArray();
    for (int j = 0; j < damage.Size(); j++)
    {
        t = ConvertJson2DamageTypes(damage[j]);
        i->addDamageType(t);
    }
    i->setDefense(item["Defense"].GetInt());
    i->setTwoHanded(item["TwoHanded"].GetInt());
    i->setSpeed(item["Speed"].GetInt());
    i->setLevel(item["Level"].GetInt());
    i->setRange(item["Range"].GetInt());
    i->setRarity((ItemRarity_enum)item["Rarity"].GetInt());
    i->setCombatEffect(ConvertJson2ActiveEffect(item["CombatEffect"]));
    i->calculateWeaponRank();

    return i;
}

//loads potion from json
Potion *ConvertJson2Potion(Value &item)
{

    Potion *i = new Potion();
    i->setName(item["Name"].GetString());
    i->setValue(item["Value"].GetInt());
    i->setWeight(item["Weight"].GetInt());
    i->setStackSize(item["StackSize"].GetInt());
    i->setDescription(item["Description"].GetString());
    i->setType((PotionTypes_enum)item["Type"].GetInt());
    i->setTier(item["Tier"].GetInt());
    i->setBaseBooster(item["BaseBooster"].GetInt());

    return i;
}

//loads Armor from Json
Armor *ConvertJson2Armor(Value &item)
{
    ActiveEffects t;
    Armor *i = new Armor();

    i->setName(item["Name"].GetString());
    i->setValue(item["Value"].GetInt());
    i->setWeight(item["Weight"].GetInt());
    i->setStackSize(item["StackSize"].GetInt());
    i->setDescription(item["Description"].GetString());
    i->setLevel(item["Level"].GetInt());
    i->setType((ArmorType_enum)item["ArmorType"].GetInt());
    i->setClass((ArmorClass_enum)item["Class"].GetInt());
    i->setRarity((ItemRarity_enum)item["Rarity"].GetInt());

    GenericArray<false, Value> defense = item["ResistanceTypes"].GetArray();
    for (int j = 0; j < defense.Size(); j++)
    {
        t = ConvertJson2ActiveEffect(defense[j]);
        i->addResistanceType(t);
    }

    return i;
}

//loads InventorySlot from Json
InventorySlot ConvertJson2InventorySlot(Value &slot)
{
    InventorySlot i;

    i.item = new Item();
    i.amount = slot["Amount"].GetInt();

    Value &temp = slot["Item"];
    // cout<<"Item:"<<temp["ItemType"].GetString()<<endl;
    string s = temp["ItemType"].GetString();
    if (s == "armor")
    {
        i.item = ConvertJson2Armor(temp);
    }
    else if (s == "weapon")
    {
        i.item = ConvertJson2Weapon(temp);
    }
    else if (s == "potion")
    {
        i.item = ConvertJson2Potion(temp);
    }
    else
    {
        i.item = ConvertJson2Item(temp);
    }
    return i;
}

//loads player from Json
Player ConvertJson2Player(Value &player)
{
    Player ret;

    ret.setDamage(player["Damage"].GetInt());
    ret.setDefense(player["Defense"].GetInt());
    ret.setSpeed(player["Speed"].GetInt());
    ret.setStrength(player["Strength"].GetInt());
    ret.setMaxHealth(player["MaxHealth"].GetInt());
    ret.setHealth(player["Health"].GetInt());
    ret.setLevel(player["Level"].GetInt());
    ret.setXP(player["XP"].GetInt());
    ret.setName(player["Name"].GetString());
    ret.setPosition({player["Position"].GetArray()[0].GetInt(), player["Position"].GetArray()[1].GetInt()});

    GenericArray<false, Value> effect = player["DebuffEffects"].GetArray();

    for (int i = 0; i < effect.Size(); i++)
    {
        ret.AddDeBuffEffect(ConvertJson2ActiveEffect(effect[i]));
    }

    effect = player["BuffEffects"].GetArray();
    for (int i = 0; i < effect.Size(); i++)
    {
        ret.AddBuffEffect(ConvertJson2ActiveEffect(effect[i]));
    }

    effect = player["CombatEffects"].GetArray();
    for (int i = 0; i < effect.Size(); i++)
    {
        ret.AddCombatEffect(ConvertJson2ActiveEffect(effect[i]));
    }
    effect = player["DamageOverTimeEffects"].GetArray();
    for (int i = 0; i < effect.Size(); i++)
    {
        ret.AddDamageOverTimeEffect(ConvertJson2ActiveEffect(effect[i]));
    }
    effect = player["ResistanceEffects"].GetArray();
    for (int i = 0; i < effect.Size(); i++)
    {
        ret.AddResistanceEffect(ConvertJson2ActiveEffect(effect[i]));
    }

    ret.setHead(ConvertJson2Armor( player["Head"]));

    ret.setTorso(ConvertJson2Armor(player["Torso"]));

    ret.setHands(ConvertJson2Armor(player["Hands"]));

    ret.setLegs(ConvertJson2Armor(player["Legs"]));

    ret.setFeet(ConvertJson2Armor(player["Feet"]));

    ret.setLeft(ConvertJson2Weapon(player["LeftWeapon"]));
    
    ret.setRight(ConvertJson2Weapon(player["RightWeapon"]));

    effect=player["Inventory"].GetArray();

    array<InventorySlot,100> arr;
    for(int i=0;i<effect.Size();i++){
       arr[i]=ConvertJson2InventorySlot(effect[i]);
    }
    ret.setInventory(arr);

    ret.setFreeSlots(player["FreeSlots"].GetInt());
    ret.setInventorySize(player["InventorySize"].GetInt());
    ret.setMoney(player["Money"].GetInt());
    ret.setLevelUp(player["LevelUp"].GetInt());
    ret.setCurrentWeight(player["CurrentWeight"].GetInt());
    ret.setMaxWeight(player["MaxWeight"].GetInt());
    ret.setOverWeighted(player["OverWeighted"].GetInt());

    ret.setCreaturesKilled(player["CreaturesKilled"].GetInt());
    ret.setItemsRecieved(player["ItemsRecieved"].GetInt());
    ret.setGoldCollected(player["GoldCollected"].GetInt());
    ret.setGoldSpent(player["GoldSpent"].GetInt());
    ret.setRoomsBeenToo(player["RoomsBeenToo"].GetInt());
    ret.setDamageRecieved(player["DamageRecieved"].GetInt());
    ret.setDamageDealt(player["DamageDealt"].GetInt());
    ret.setMaxDamageDealt(player["MaxGoldHeld"].GetInt());
    ret.setMaxDamageDealt(player["MaxDamageDealt"].GetInt());
    ret.setPotionDranked(player["PotionsDranked"].GetInt());
    return ret;
}