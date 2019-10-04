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


    public:

    //sets Type to Normal, Probability to 100 and Damage 0;
    DamageTypes();
    
    //sets Type to Normal, Probability to 100 and Damage to damage;
    DamageTypes(int damage);

    //sets Type to type, Probability to probability and Damage to damage;
    DamageTypes(DamageTypes_enum type, int probability, int damage);

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