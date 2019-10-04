#include "DamageTypes.h"


 //sets Type to Normal, Probability to 100 and Damage 0;
    DamageTypes::DamageTypes(){
        this->Type=Normal_DamageType;
        this->Probability=100;
        this->Damage=0;
    }
    
    //sets Type to Normal, Probability to 100 and Damage to damage;
    DamageTypes::DamageTypes(int damage){
        this->Type=Normal_DamageType;
        this->Probability=100;
        this->setDamage(damage);
    }

    //sets Type to type, Probability to probability and Damage to damage;
    DamageTypes::DamageTypes(DamageTypes_enum type, int probability, int damage){
        this->Type=type;
        this->setProbability(probability);
        this->setDamage(damage);
    }

    DamageTypes_enum DamageTypes::getType(){
        return this->Type;
    }

    void DamageTypes::setType(DamageTypes_enum type){
        this->Type=type;
    }

    int DamageTypes::getProbability(){
        return this->Probability;
    }

    void DamageTypes::setProbability(int probability){
        if (probability<0){
            probability =0;
        }else if(probability>100){
            probability=100;
        }
        this->Probability=probability;
    }

    int DamageTypes::getDamage(){
        return this->Damage;
    }
    void DamageTypes::setDamage(int damage){
        if(damage<0){
            damage=0;
        }
        this->Damage=damage;
    }

       //Displays all relevent info
    void DamageTypes::DisplayDetails(){
        cout<<"Damage Type: "<<this->getName()<<endl;
        cout<<"Probability: "<<this->getProbability()<<endl;
        cout<<"Damage: " <<this->getDamage()<<endl;
    }

    //returns the name of effect derived from the Type
    string DamageTypes::getName(){

        switch (this->Type)
        {
        case NULL_DamageType: return "NULL"; break;
        case Normal_DamageType: return "Normal"; break;
        case Fire_DamageType: return "Fire"; break;
        case Stabbing_DamageType: return "Stabbing"; break;
        case Blunt_DamageType: return "Blunt Damage"; break;
        case Critical_DamageType: return "Critical Damage"; break;
        
        
        default:
        return "";
            break;
        }


    }