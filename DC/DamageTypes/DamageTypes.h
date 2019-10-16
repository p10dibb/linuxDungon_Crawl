#pragma once
#include <string>
#include <iostream>
using namespace::std;

enum DamageTypes_enum{NULL_DamageType,Normal_DamageType,Fire_DamageType,Stabbing_DamageType,Blunt_DamageType,Critical_DamageType};

class DamageTypes{
    private:
    DamageTypes_enum Type;

    //odds of Effect occuring
    int Probability;

    //amount of Damage delt
    int Damage;

    //is this a damage type that adds a Damage over time effect
    bool isDamageOverTime;
    //the amount of damage taken for Damoage over time
    int DamageOverTime_damage;
    //the amount of rounds it is DOT effect is active for
    int DamageOverTime_time;


    public:

    // //sets Type to Normal, Probability to 100 and Damage 0;
    // DamageTypes();
    
    // //sets Type to Normal, Probability to 100 and Damage to damage;
    // DamageTypes(int damage);

    // //sets Type to type, Probability to probability and Damage to damage;
    // DamageTypes(DamageTypes_enum type, int probability, int damage);

    DamageTypes(int damage=0,int probability=100,DamageTypes_enum type=Normal_DamageType,bool isdot=false, int dot_damage=0, int dot_time=0);

    bool getIsDamageOverTime();
    void setIsDamageOverTime(bool dot);
    int getDamageOverTime_damage();
    void setDamageOverTime_damage(int damage);
    int getDamageOverTime_time();
    void setDamageOverTime_time(int time);
    


    DamageTypes_enum getType();
    void setType(DamageTypes_enum type);

    int getProbability();
    void setProbability(int probability);

    int getDamage();
    void setDamage(int damage);

    //Displays all relevent info
    void DisplayDetails();

    //returns the name of effect derived from the Type
    string getName();

};