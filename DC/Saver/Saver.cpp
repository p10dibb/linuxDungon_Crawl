#include "Saver.h"

//converts an active effect to json
string convertActiveEffect2Json(ActiveEffects effect){

    string effectStr="{";

    //adds Effect
    effectStr+="\"Effect\":"+to_string(effect.getEffect())+",";
    effectStr+="\"EffectType\":"+to_string(effect.getEffectType())+",";
    effectStr+="\"RoundsActive\":"+to_string(effect.getRound())+",";
    effectStr+="\"Modifier\":"+to_string(effect.getModifier())+"}";

    return effectStr;

}



//converts damage Type to json
string converDamageType2Json(DamageTypes damage){

    string damageStr="{";

    damageStr+="\"Type\":"+to_string(damage.getType())+",";
    damageStr+="\"Probability\":"+to_string(damage.getProbability())+",";
    damageStr+="\"Damage\":"+to_string(damage.getDamage())+",";
    damageStr+="\"isDamageOverTime\":"+to_string(damage.getIsDamageOverTime())+",";
    damageStr+="\"DamageOverTime_damage\":"+to_string(damage.getDamageOverTime_damage())+",";
    damageStr+="\"DamageOverTime_time\":"+to_string(damage.getDamageOverTime_time())+"}";
    
    return damageStr;
}

//conver Item type to json
string converItem2Json(Item i){
    string itemStr="{";
    itemStr+="\"ItemType\":\"item\",";
    itemStr+="\"Name\":\""+i.getName()+"\",";
    itemStr+="\"Value\":"+to_string(i.getValue())+",";
    itemStr+="\"Weight\":"+to_string(i.getWeight())+",";
    itemStr+="\"StackSize\":"+to_string(i.getStackSize())+",";
    itemStr+="\"Description\":\""+i.getDescription()+"\"}";

    return itemStr;
}


//converts potion to json
string convertPotion2Json(Potion p){
    string itemStr="{";
    itemStr+="\"ItemType\":\"potion\",";
    itemStr+="\"Name\":\""+p.getName()+"\",";
    itemStr+="\"Value\":"+to_string(p.getValue())+",";
    itemStr+="\"Weight\":"+to_string(p.getWeight())+",";
    itemStr+="\"StackSize\":"+to_string(p.getStackSize())+",";
    itemStr+="\"Description\":\""+p.getDescription()+"\",";
    itemStr+="\"Type\":"+to_string(p.getType())+",";
    itemStr+="\"Tier\":"+to_string(p.getTier())+",";
    itemStr+="\"BaseBooster\":"+to_string(p.getBaseBooster())+"}";
    return itemStr;


}