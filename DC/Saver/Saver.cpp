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
string converDamageType2Json(DamageTypes damage)
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
        itemStr += converDamageType2Json(damage[i]);
        if (i < damage.size() - 1)
        {
            itemStr += ",";
        }
        else
        {
            itemStr += "],";
        }
    }
    itemStr += "\"Defense\":" + convertActiveEffect2Json(w.getDefense()) + ",";
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

    itemStr += "\"amount\":" + to_string(i.amount) + ",";
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
    else{
        itemStr+=convertItem2Json(*i.item);
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
    cout << "effect1" << endl;
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
    cout << "effect2" << endl;

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
    cout << "effect3" << endl;

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
    cout << "effect4" << endl;

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
    cout << "effect5" << endl;

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
        cout<<"Armor"<<endl;
        itemStr += "\"Head\":" + convertArmor2Json(*p.getHead()) + ",";
        itemStr += "\"Torso\":" + convertArmor2Json(*p.getTorso()) + ",";
        itemStr += "\"Hands\":" + convertArmor2Json(*p.getHands()) + ",";
        itemStr += "\"Legs\":" + convertArmor2Json(*p.getLegs()) + ",";
        itemStr += "\"Feet\":" + convertArmor2Json(*p.getFeet()) + ",";
        cout<<"Weapon"<<endl;

        itemStr += "\"LeftWeapon\":" + convertWeapon2Json(*p.getLeft()) + ",";
        itemStr += "\"RightWeapon\":" + convertWeapon2Json(*p.getRight()) + ",";
        itemStr += "\"Inventory\":[";
        cout<<"Inventory"<<endl;

        array<InventorySlot, 100> arr = p.getInventory();
        for (int i = 0; i < 100; i++)
        {
            if(arr[i].item==0x0){
                break;
            }
            itemStr += convertInventorySlot2Json(arr[i]);
       
            if (i < 99)
            {
                itemStr += ",";
            }
        }
        itemStr += "],";
        cout<<"more inventory"<<endl;
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

    