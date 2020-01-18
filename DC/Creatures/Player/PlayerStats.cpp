#include "Player.h"


//displays all the players stats
void Player::DisplayStats(){
    cout<<"----------STATS----------"<<endl;
    cout<<"Max Health: "<<this->getMaxHealth()<<endl;
    cout<<"Speed: "<<this->getSpeed()<<endl;
    cout<<"Defense: "<<this->getDefense()<<endl;
    cout<<"Damage: "<<this->getDamage()<<endl;
    cout<<"Strength: "<<this->getStrength()<<endl;
    cout<<"Stamina: "<<this->getStamina()<<endl;
    cout<<endl<<"Creatures Killed: "<<this->getCreaturesKilled()<<endl;
    cout<<"Items Recieved: "<<this->getItemsRecieved()<<endl;
    cout<<"Total Gold Collected: "<<this->getGoldCollected()<<endl;
    cout<<"Total Gold Spent: "<<this->getGoldSpent()<<endl;
    cout<<"Rooms Been Too: "<<this->getRoomsBeenToo()<<endl;
    cout<<"Total Damage Dealt: "<<this->getDamageDealt()<<endl;
    cout<<"Total Damage Recieved: "<<this->getDamageRecieved()<<endl;
    cout<<"Potions Taken: "<<this->getPotionsDranked()<<endl;
    cout<<"Most Gold Held: "<<this->getMaxGoldHeld()<<endl;
    cout<<"Most Damage Dealt: "<<this->getMaxDamageDealt()<<endl;

}

//returns the amount of creatures player has killed
int Player::getCreaturesKilled(){
    return this->CreaturesKilled;
}

//increases CreaturesKilled by 1
void Player::IncrementCreaturesKilled(){
    this->CreaturesKilled+=1;
    RewardCheckCreaturesKilled();
}
//checks to see if the amount meets a reward requirment
int Player::RewardCheckCreaturesKilled(){

    //this is vaugue model for rewards
   
    Item* RewardItem;
    int ArmourChance=-1;
    if(this->getCreaturesKilled()>1000000){
        cout<<"what are you doing with your life"<<endl;
    }
    else if(this->getCreaturesKilled()==420){
        
        RewardItem=spawner.CreateTheMarly(this->getLevel());

        cout<<this->getName()<<"has killed 420 Opponents and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 420;
    }   
    //rewarded every 200 kills
    else if(this->getCreaturesKilled()%200==0&& this->getCreaturesKilled()!=0){
        
        RewardItem=spawner.CreateRandomExtinctionistItem(this->getLevel());

        cout<<this->getName()<<"has killed "<<this->getCreaturesKilled()<<" Opponents and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return this->getCreaturesKilled();
    }
    else if(this->getCreaturesKilled()==125){
        
        RewardItem=spawner.CreateRandomExtinctionistItem(this->getLevel());

        cout<<this->getName()<<"has killed 125 Opponents and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 125;
    }
    else if(this->getCreaturesKilled()==75){
        
        RewardItem=spawner.CreateRandomExtinctionistItem(this->getLevel());

        cout<<this->getName()<<"has killed 75 Opponents and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 75;
    }
    else if(this->getCreaturesKilled()==69){
        
        RewardItem=spawner.CreateNICE(this->getLevel());

        cout<<this->getName()<<"has killed 69 Opponents and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 69;
    }
    else if(this->getCreaturesKilled()==25){
        
        RewardItem=spawner.CreateRandomExtinctionistItem(this->getLevel());

        cout<<this->getName()<<"has killed 25 Opponents and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 25;
    }
    else if(this->getCreaturesKilled()==10){
        
        if(rand()%2 ==0){
            RewardItem=spawner.CreateDagger(this->getLevel());
        }else{
            RewardItem=spawner.CreateChest(this->getLevel(),Light_ArmorClass);
        }
        cout<<this->getName()<<"has killed 10 Opponents and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
       return 10;
    }
    return -1;
}

//returns the total amount of items recieved;
int Player::getItemsRecieved(){
    return this->ItemsRecieved;
}

//increments the ItemsRecieved by 1
void Player::IncrementItemsRecieved(){
    this->ItemsRecieved+=1;
    this->RewardCheckItemsRecieved();
}

//checks to see if the ItemsRecieved meets reward requirments
int Player::RewardCheckItemsRecieved(){

      Item* RewardItem;
    int ArmourChance=-1;
    if(this->getCreaturesKilled()>1000000){
        cout<<"what are you doing with your life"<<endl;
    }
    else if(this->getCreaturesKilled()==420){
        
        RewardItem=spawner.CreateTheMarly(this->getLevel());

        cout<<this->getName()<<"has killed 420 Opponents and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 420;
    }   
    //rewarded every 200 kills
    else if(this->getItemsRecieved()%300==0&&getItemsRecieved()!=0){
        
        RewardItem=spawner.CreateRandomCollectorItem(this->getLevel());

        cout<<this->getName()<<"has collected "<<this->getItemsRecieved()<<" items and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return this->getItemsRecieved();
    }
    
   else if(this->getItemsRecieved()==150){
        
        RewardItem=spawner.CreateRandomCollectorItem(this->getLevel());

        cout<<this->getName()<<"has collected 150 Items and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 150;
    }
     else if(this->getItemsRecieved()==100){
        
        RewardItem=spawner.CreateRandomCollectorItem(this->getLevel());

        cout<<this->getName()<<"has collected 100 Items and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 100;
    }
    else if(this->getCreaturesKilled()==69){
        
        RewardItem=spawner.CreateNICE(this->getLevel());

        cout<<this->getName()<<"has killed 69 Opponents and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 69;
    }
    else if(this->getItemsRecieved()==50){
        
        RewardItem=spawner.CreateRandomCollectorItem(this->getLevel());

        cout<<this->getName()<<"has collected 50 Items and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
     
       
       return 50;
    }
    else if(this->getItemsRecieved()==25){
        
        if(rand()%2 ==0){
            RewardItem=spawner.CreateDagger(this->getLevel());
        }else{
            RewardItem=spawner.CreateChest(this->getLevel(),Light_ArmorClass);
        }
        cout<<this->getName()<<"has collected 25 Items and is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
       return 25;
    }
    return -1;
}

//returns total amount of gold Collected
int Player::getGoldCollected(){
    return this->GoldCollected;
}

//increases GoldCollected by amount
void Player::IncrementGoldCollected(int amount){
    this->GoldCollected+=amount;

}

//checks if the GoldCollected meets RewardRequirements
int Player::RewardCheckGoldCollected(int amount){
    Item *RewardItem;
    if(amount>1000000000){
        cout<<"why are you still playing"<<endl;
    }
    else if(this->GoldCollected>=690&&this->GoldCollected-amount<690){
       
        RewardItem=spawner.CreateNICE(this->getLevel());
        cout<<this->getName()<<"has collected a total of 690 Gold is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
       return 690;
    }
    //rewards on multiples of 500
    else if(this->GoldCollected%500>0&&this->GoldCollected%500-amount<0){
        //this should round to nearest 500        
        int rounder=(this->GoldCollected/500)*500;
        RewardItem=spawner.CreateRandomGoldMongerItem(this->getLevel());
        cout<<this->getName()<<"has collected a total of "<<rounder<<" Gold is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
       return rounder;
    }
    else if(this->GoldCollected>=420&&this->GoldCollected-amount<420){
       
        RewardItem=spawner.CreateTheMarly(this->getLevel());
        cout<<this->getName()<<"has collected a total of 420 Gold is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
       return 420;
    }
    else if(this->GoldCollected>=300&&this->GoldCollected-amount<300){
       
        RewardItem=spawner.CreateRandomGoldMongerItem(this->getLevel());
        cout<<this->getName()<<"has collected a total of 300 Gold is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
       return 300;
    }
    else if(this->GoldCollected>=150&&this->GoldCollected-amount<150){
       
        RewardItem=spawner.CreateRandomGoldMongerItem(this->getLevel());
        cout<<this->getName()<<"has collected a total of 150 Gold is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
       return 150;
    }    
    else if(this->GoldCollected>=50&&this->GoldCollected-amount<50){
        if(rand()%2 ==0){
            RewardItem=spawner.CreateDagger(this->getLevel());
        }else{
            RewardItem=spawner.CreateChest(this->getLevel(),Light_ArmorClass);
        }
        cout<<this->getName()<<"has collected a total of 50 Gold is rewarded "<<RewardItem->getName()<<endl;
        this->addToInventory(RewardItem);
       return 50;
    }

    return -1;
}

//returns the total amount of Gold Spent
int Player::getGoldSpent(){
    return this->GoldSpent;
}

//increases GoldSpent by amount
void Player::IncrementGoldSpent(int amount){
    this->GoldSpent+=amount;
}

//checks if the GoldSpent meets reward Requirements
int Player::RewardCheckGoldSpent(){
    return -1;
}

//returns total amount of floors player has been too
int Player::getRoomsBeenToo(){
    return this->RoomsBeenToo;
}

//increases RoomsBeenToo by 1
void Player::IncrementRoomsBeenToo(){
    this->RoomsBeenToo+=1;
}

//checks if the RoomsBeenToo meets reward requirements
int Player::RewardCheckRoomsBeenToo(){
    return -1;
}

//returns total amount of damage recieved
int Player::getDamageRecieved(){
    return this->DamageRecieved;
}

//increase DamageRecieved by amount;
void Player::IncrementDamageRecieved(int amount){
    this->DamageRecieved+=amount;
}

//checks if the DamageRecieved meetsReward requirements
int Player::RewardCheckDamageRecieved(){
    return -1;
}

//returns total amount of Damage Dealt
int Player::getDamageDealt(){
    return this->DamageDealt;
}

//increases DamageDealt by amount
void Player::IncrementDamageDealt(int amount){
    this->DamageDealt+=amount;
}

// checks if DamageDealt meets reward requirements
int Player::RewardCheckDamageDealt(){
    return -1;
}

//returns largest amount of Money the player has had
int Player::getMaxGoldHeld(){
    return this->MaxGoldHeld;
}

//checks to see if MaxGold meets reqard requirements
int Player::RewardCheckMaxGoldHeld(){
    if(this->getMoney()>this->MaxGoldHeld){
        this->MaxGoldHeld=this->Money;
    }

    return -1;
}

//returns the maxDamage Dealt
int Player::getMaxDamageDealt(){
    return this->MaxDamageDealt;

}

//checks if MaxDamageDealt meets Reward Requirements
int Player::RewardCheckMaxDamageDealt(int damage){
    if(damage>this->MaxDamageDealt){
        this->MaxDamageDealt=damage;
    }
    return -1;
}

//returns total amount of potions the player has drunk
int Player::getPotionsDranked(){
    return this->PotionsDranked;
}

//increases Potion Dranked by 1
void Player::IncrementPotionDranked(){
    this->PotionsDranked+=1;
}

//checks if the PotionsDranked meets reward requirements
int Player::RewardCheckPotionDranked(){
    return -1;
}