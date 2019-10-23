#include "DamageTypes.h"


    DamageTypes::DamageTypes(int damage,int probability,DamageTypes_enum type,bool isdot, int dot_damage, int dot_time){
        this->setDamage(damage);
        this->setProbability(probability);
        this->setType(type);
        this->setIsDamageOverTime(isdot);
        this->setDamageOverTime_damage(dot_damage);
        this->setDamageOverTime_time(dot_time);
    }

    bool DamageTypes::getIsDamageOverTime(){
        return this->isDamageOverTime;
    }
    void DamageTypes::setIsDamageOverTime(bool dot){
        if(dot==true){
            if(this->getDamageOverTime_damage()<=0){
                this->setDamageOverTime_damage(1);
            }
            if(this->getDamageOverTime_time()<=0){
                this->setDamageOverTime_time(1);
            }
        }
        this->isDamageOverTime=dot;
    }
    int DamageTypes::getDamageOverTime_damage(){
        return this->DamageOverTime_damage;
    }
    void DamageTypes::setDamageOverTime_damage(int damage){
        if(damage<0){
            damage=0;
        }
        this->DamageOverTime_damage=damage;
    }
    int DamageTypes::getDamageOverTime_time(){
        return this->DamageOverTime_time;
    }
    void DamageTypes::setDamageOverTime_time(int time){
        if(time<0){
            time=0;
        }
        this->DamageOverTime_time=time;
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
       // case NULL_DamageType: return "NULL"; break;
        case Normal_DamageType: return "Normal"; 
        case Fire_DamageType: return "Fire"; 
        case Stabbing_DamageType: return "Stabbing";
        case Blunt_DamageType: return "Blunt Damage"; 
        case Critical_DamageType: return "Critical Damage"; 
        
        
        default: return "NULL";
        }


    }